#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void	sigchld_handler(int sig)
{
	(void)sig;
	while (waitpid(-1, NULL, WNOHANG) > 0);
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
    // Принятие подключения клиента
    *client_fd = accept(*server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if (*client_fd == -1) {
        perror("accept failed");
        close(*server_fd);
        exit(EXIT_FAILURE);
    }
    close(*server_fd);
    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
}

int compare_code(char *str, char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (exit(1), 1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (strncmp(str, line, 6) == 0)
			return (close(fd), atoi(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (-1);
}

int isnummeric(char *str)
{
	int i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int redirect_user_data(int code, char *str) // создает новый файл, но она работает, только если есть в списке код юзера
{
	char str1[50] = "/tmp/";
	char *str2 = ft_itoa(code);
	int fd;

	strcat(str1, str2);
	if (atoi(str) == code)
		return 0;
	fd = open(str1, O_RDWR | O_APPEND | O_CREAT, 0777);
	if (fd < 0)
		return -1;
	if (write(fd, str, strlen(str)) == -1)
		return 1;
	close(fd);
	return (0);
}

int add_new_code(char *str, char *filename) // просто создать новый файл для юзера и записать его код в journal_server.txt
{
	int fd;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return -1;
	if (write(fd, str, strlen(str)) == -1)
	{
		perror("write");
		exit(1);
	}
	close(fd);
}

void get_client_data(int *client_fd, char *filename)
{
	char *str;
	int i = 0;
	int code = -1;
	int new_code;

	str = get_next_line(*client_fd);
	while (str)
	{
		if (i == 0) // передача специального кода, показывающая, какой юзер пишет
		{
			if (strlen(str) != 7)
				break ;
			if (isnummeric(str))
				code = compare_code(str, filename);
		}
		if (code != -1)// файл с записями клиента существует
		{
			if (redirect_user_data(code, str) == -1)
			{
				perror("redirect_user_data");
				free(str);
				return ;
			}
		}
		else
		{
			if (isnummeric(str))
			{
				if (add_new_code(str, filename) == -1)
				{
					perror("create_new_user_file");
					free(str);
					return ;
				}
				code = atoi(str);
			}
		}
		printf("code: %d\n", code);
		printf("str: %s\n", str);
		free(str);
		str = get_next_line(*client_fd);
		i++;
	}
	free(str);
}

int main()
{
    int client_fd;
	int server_fd;
    ssize_t bytes_read;
	int send_message;

	connect_tcp(&client_fd, &server_fd);
	get_client_data(&client_fd, "journal_server.txt");
    close(client_fd);

    return 0;
}

// int main()
// {
//     int client_fd;
// 	int server_fd;
// 	// struct sockaddr_in client_addr;
// 	// socklen_t addr_len = sizeof(client_addr);
// 	// pid_t child_pid;

// 	// signal(SIGCHLD, sigchld_handler);
// 	connect_tcp(&client_fd, &server_fd);

// 	while (1)
// 	{
// 		child_pid = fork();
// 		if (child_pid == -1)
// 		{
// 			perror("fork");
// 			close(client_fd);
// 			continue;
// 		}
// 		if (child_pid == 0) // дочерний процесс
// 		{
// 			// close()
// 			get_client_data(&client_fd, "journal_server.txt");
// 			close(client_fd);
// 			exit(0);
// 		}
// 		else
// 		{
// 			waitpid(child_pid, NULL, 0);
// 			close(client_fd);
// 		}
// 	}
// }
// sudo netstat -tulnp | grep :8080				проверка занятости порта на котором этот сервер
// watch cat /tmp/client_file.txt -n 1			просмотр файла в тек времени (обновление по дефолту каждые 2 сек. Можно изменить с помощью -n )

// сделать так, чтобы я мог включать свои библиотеки и не писать сообщение о компиляции (чтобы нужно было только название вводеить типо -lft и все) 
// cc server.c ~/42_learning/get_next_line/* -Llibft -lft -o server