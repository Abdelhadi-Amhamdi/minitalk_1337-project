SRC= client.c server.c
name=minitalk
EXC= client server

all:$(name) 

%:%.c
	cc -Wall -Wextra -Weroor $< -o 

$(name): $(EXC)
	ar -rc $(EXC)
