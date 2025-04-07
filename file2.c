#include "server.h"

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

void	remove_user(char *ip, char *pid)
{
	char	*line;
	char	*buffer;
	int		len;
	int		fd1;
	int		fd2;
	int		counter;
	char	built_line[50];

	if (!ip || !pid)
		return (exit(1));
	built_line[0] = '\0';
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
		if (strncmp(line, built_line, strlen(ip)) == 0)
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

int main()
{
	remove_user("127.0.0.1", "512433");
	return 0;
}