#include "server.h"

int client_fds[MAX_CLIENTS];
int client_counter = 0;

void	sigchld_handler(int sig)
{
	(void)sig;
	while (waitpid(-1, NULL, WNOHANG) > 0); // это нужно чтобы избежать блокировки родительского процесса
}

void	connect_tcp(int *client_fd, int *server_fd)
{
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

	*server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*server_fd == -1)
	{
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Настройка адреса и порта сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(*server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
        perror("bind failed");
        close(*server_fd);
        exit(EXIT_FAILURE);
    }
    if (listen(*server_fd, 10) == -1)
	{
        perror("listen failed");
        close(*server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d\n", PORT);
}

int add_info(char *str, char *filename)
{
	int fd;

	if (!filename)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		perror("open");
		return -1;
	}
	if (write(fd, str, strlen(str)) == -1)
	{
		perror("write");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

void	register_user(int code, char *ip, int pid)
{
	char	*buffer;
	char	*ch_pid;
	char	*ch_code;
	int		i;
	int		j;

	ch_code = ft_itoa(code);
	if (!ch_code)
		return ;
	ch_pid = ft_itoa(pid);
	if (!ch_pid)
		return free(ch_code);
	buffer = malloc(strlen(ch_code) + strlen(ip) + strlen(ch_pid) + 4);
	if (!buffer)
		return free(ch_pid), free(ch_code);
	i = 0;
	while (ch_code[i])
	{
		buffer[i] = ch_code[i];
		i++;
	}
	buffer[i] = '\t';
	i++;
	j = 0;
	while (ip[j])
	{
		buffer[i] = ip[j];
		j++;
		i++;
	}
	buffer[i] = ':';
	i++;
	j = 0;
	while (ch_pid[j])
	{
		buffer[i] = ch_pid[j];
		i++;
		j++;
	}
	buffer[i] = '\n';
	i++;
	buffer[i] = '\0';
	add_info(buffer, POOL);
	free(buffer);
	free(ch_pid);
	free(ch_code);
}

int get_len_file(char *namefile)
{
	char *line;
	int counter;
	int fd;

	if (!namefile)
		return -1;
	fd = open(namefile, O_RDONLY);
	if (fd < 0)
		return (-1);
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		counter += strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

void	remove_user(char *code, char *ip, char *pid)
{
	char	*line;
	char	*buffer;
	int		len;
	int		fd1;
	int		fd2;
	int		counter;
	char	built_line[100];

	if (!ip || !pid || !code)
		return (exit(1));
	built_line[0] = '\0';
	strcat(built_line, code);
	strcat(built_line, "\t");
	strcat(built_line, ip);
	strcat(built_line, ":");
	strcat(built_line, pid);
	strcat(built_line, "\n");
	printf("built_line: %s\n", built_line);
	len = get_len_file(POOL);
	fd1 = open(POOL, O_RDONLY);
	if (fd1 == -1 || len <= 0)
	{
		perror("open");
		return (exit(1));
	}
	buffer = malloc(len + 1);
	buffer[0] = '\0';
	line = get_next_line(fd1);
	counter = 0;
	while (line)
	{
		if (strcmp(line, built_line) == 0)
		{
			free(line);
			line = get_next_line(fd1);
			continue ;
		}
		strcat(buffer, line);
		counter += strlen(line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	fd2 = open(POOL, O_WRONLY | O_TRUNC);
	if (write(fd2, buffer, strlen(buffer)) == -1)
	{
		perror("write");
		return (exit(1));
	}
}

void	remember_data(char *str, char *code)
{
	char buffer[50] = "/tmp/";
	
	if (!code || !str)
		return ;
	strcat(buffer, code);
	add_info(str, buffer);
}

void	send_to_all_clients(char *msg)
{
	if (!msg)
		return ;
	int i = 0;
	while (i < client_counter)
	{
		printf("client_fd[i]: %d\n", client_fds[i]);
		if (send(client_fds[i], msg, strlen(msg), 0) == -1)
		{
			perror("send");
		}
		else
			printf("Message was sent to client %d\n", i + 1);
		i++;
	}
}

void get_client_data(int *client_fd, char *filename, char *ip, int pid)
{
	char *str;
	int i = 0;
	int code = -1;
	int connected = -1;
	char *t2 = ft_itoa(pid);
	char *another_client_data;

	str = get_next_line(*client_fd);
	while (str)
	{
		if (i == 0)
		{
			code = atoi(str);
			register_user(code, ip, pid);
		}
		remember_data(str, ft_itoa(code));
		// if (i == 1) // подключение пользователя
		// {
		// }
		send_to_all_clients(str);
		// if (connected)
			// redirect_data(str, code);
		printf("code: %d\n", code);
		printf("str: %s\n", str);
		free(str);
		str = get_next_line(*client_fd);
		i++;
	}
	remove_user(ft_itoa(code), ip, t2);
	free(t2);
	printf("Client logged out\n");
}

int main()
{
    int client_fd;
	int server_fd;
	struct sockaddr_in client_addr;
	socklen_t addr_len = sizeof(client_addr);
	// struct pollfd fds[MAX_CLIENTS + 1];
	pid_t child_pid;

	signal(SIGCHLD, sigchld_handler);
	connect_tcp(&client_fd, &server_fd);
	while (1)
	{
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
		if (client_fd == -1) // если не получилось принять подключение пробуем снова
		{
			perror("accept");
			continue;
			// return 1;
		}
		if (client_counter < MAX_CLIENTS)
		{
			printf("[main] client_fd: %d\n", client_fd);
			client_fds[client_counter] = client_fd;
			client_counter++;
			printf("Client №%d connected\n", client_counter);
		}
		else
		{
			printf("Max clients reached. Rejecting client\n");
			close(client_fd);
		}
		printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		child_pid = fork();
		if (child_pid == -1) // если не получилось создать процесс пробуем снова
		{
			perror("fork");
			close(client_fd);
			continue;
			// return 1;
		}
		if (child_pid == 0) // дочерний процесс
		{
			get_client_data(&client_fd, "journal_server.txt", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
			close(client_fd);
			exit(0);
		}
		else
		{
			close(client_fd);
		}
	}
	close(server_fd);
}

// sudo netstat -tulnp | grep :8080				проверка занятости порта на котором этот сервер
// watch cat /tmp/client_file.txt -n 1			просмотр файла в тек времени (обновление по дефолту каждые 2 сек. Можно изменить с помощью -n )

// сделать так, чтобы я мог включать свои библиотеки и не писать сообщение о компиляции (чтобы нужно было только название вводеить типо -lft и все) 
// cc server.c ~/42_learning/get_next_line/* -Llibft -lft -o server
