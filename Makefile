CC=cc
C_FLAGS = -Llibft -lft ~/42_learning/get_next_line/*

NAME1=server
NAME2=client

SRCS1 = server.c
SRCS2 = client.c

all: $(NAME1) $(NAME2)

$(NAME1):
	$(CC) $(SRCS1) $(C_FLAGS) -o $(NAME1)

$(NAME2):
	$(CC) $(SRCS2) $(C_FLAGS) -o $(NAME2)


re: fclean all

fclean: clean

clean:
	rm -rf $(NAME1)
	rm -rf $(NAME2)

.PHONY: all re clean fclean