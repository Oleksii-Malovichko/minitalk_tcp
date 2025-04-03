



#ifndef SERVER_H
# define SERVER_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
// # include "/home/alex/42_learning/libft"

# define PORT 8080
# define BUFFER_SIZE 1024

typedef struct t_user
{
	int port;

}	s_user;


#endif	