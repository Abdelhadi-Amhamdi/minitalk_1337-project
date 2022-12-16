SRC= client.c server.c
name=minitalk.a
EXC= client server

all:$(EXC)

%.:%.c
	cc -Wall -Wextra -Werror $< 

clean :
	rm -f $(EXC)

fclean: clean

re : clean all