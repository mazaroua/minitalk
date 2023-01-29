NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

src_server =  server.c 
src_client = client.c

src_server_bonus = server_bonus.c
src_client_bonus = client_bonus.c

obj_server = $(src_server:.c=.o)
obj_client = $(src_client:.c=.o)

obj_server_bonus = $(src_server_bonus:.c=.o)
obj_client_bonus = $(src_client_bonus:.c=.o)

all: $(NAME)

$(NAME): $(obj_client) $(obj_server)
	make -C Libft
	$(CC) $(CFLAGS)  $(obj_server) Libft/libft.a -o server
	$(CC) $(CFLAGS) $(obj_client) Libft/libft.a -o client

bonus: $(obj_client_bonus) $(obj_server_bonus)
	make -C Libft
	$(CC) $(CFLAGS)  $(obj_server_bonus) Libft/libft.a -o server_bonus
	$(CC) $(CFLAGS) $(obj_client_bonus) Libft/libft.a -o client_bonus

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	make fclean -C libft

fclean: clean
	rm -rf server
	rm -rf client
	rm -rf server_bonus
	rm -rf client_bonus

re: fclean all

.PHONY: all clean fclean re bonus