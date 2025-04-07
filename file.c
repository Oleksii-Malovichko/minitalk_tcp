#include "server.h"
#define JRNL_IP "journal_ip.txt"

int get_len_file(char *info)
{
	int fd;
	int counter;
	char *line;

	if (!info)
		return (-1);
	fd = open(JRNL_IP, O_RDWR | O_CREAT, 0666);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (strncmp(info, line, strlen(info)) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		counter += strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

int add_line(char *info)
{
	int fd;

	fd = open(JRNL_IP, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd < 0)
		return (-1);
	if (write(fd, info, strlen(info)) == -1)
		return (close(fd), -1);
}

char *copy_file_except(char *info, int len)
{
	char *tempfile;
	int fd;
	char *line;
	int i;

	tempfile = malloc(len + 1);
	tempfile[0] = '\0';
	if (!tempfile)
	{
		perror("malloc");
		return (NULL);
	}
	fd = open(JRNL_IP, O_RDONLY | O_CREAT, 0666);
	if (fd < 0)
	{
		perror("open");
		return (NULL);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (strncmp(info, line, strlen(info)) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		i += strlen(line);
		// printf("%s\n", line);
		strcat(tempfile, line);
		free(line);
		line = get_next_line(fd);
	}
	tempfile[i] = '\0';
	// printf("i: %d; len: %d; tempfile:\n%s\n", i, len, tempfile);
	close(fd);
	return (tempfile);
}

int remove_lines(char *info)
{
	int		fd;
	char	*tempfile;
	int		len_tempfile = 0;
	
	if (!info)
		return (-1);
	len_tempfile = get_len_file(info);
	if (len_tempfile == -1)
		return (-1);
	tempfile = copy_file_except(info, len_tempfile);
	if (!tempfile)
		return (-1);
	// if (tempfile)
		// printf("%s\n", tempfile);
	fd = open(JRNL_IP, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("open");
		close(fd);
		free(tempfile);
		return -1;
	}
	if (write(fd, tempfile, strlen(tempfile)) == -1)
		return (free(tempfile), close(fd), -1);
	free(tempfile);
	close(fd);
	return (0);
}

char *make_ip_line(char *ip, int pid)
{
	char *info;
	char *ch_pid;

	ch_pid = ft_itoa(pid);
	if (!ch_pid)
		return (NULL);
	info = malloc(strlen(ip) + strlen(ch_pid) + 2);
	if (!info)
		return (free(ch_pid), NULL);
	info[0] = '\0';
	strcat(info, ip);
	strcat(info,":");
	strcat(info, ch_pid);
	return (free(ch_pid), info);
}

int table_ip(char *ip, int pid)
{
	int fd;
	char *info;

	info = make_ip_line(ip, pid);
	if (!info)
		return (-1);
	printf("info: %s\n", info);
	if (remove_lines(info) == -1) // из файла должны удалится все заходы этого ip, включая смс о выходе
		return (free(info), -1);
	if (add_line(info) == -1)
		return (free(info), -1);
	free(info);
	return (0);
}

int main()
{
	table_ip("127.0.0.1", 51234);
}
