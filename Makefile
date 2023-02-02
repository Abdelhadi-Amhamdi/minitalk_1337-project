# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 21:43:09 by aamhamdi          #+#    #+#              #
#    Updated: 2023/02/02 09:34:42 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSF  = src/
B_SRCP = bonus/

S_HEADER=mini_talk.h
B_HEADER=mini_talk_bonus.h

CLIENT = client
SERVER = server

CLIENT_B = client_bonus
SERVER_B = server_bonus

FLAGS = -Wall -Wextra -Werror

C_SRC  = client.c
S_SRC  = server.c
U_SRC  = mini_talk_utils.c mini_talk_utils2.c

C_SRC_B  = client_bonus.c
S_SRC_B  = server_bonus.c
U_SRC_B  = mini_talk_utils_bonus.c mini_talk_utils_bonus2.c

C_SRCS = $(addprefix $(SRCSF), $(C_SRC))
U_SRCS = $(addprefix $(SRCSF), $(U_SRC))
S_SRCS = $(addprefix $(SRCSF), $(S_SRC))

C_SRCS_B = $(addprefix $(B_SRCP), $(C_SRC_B))
U_SRCS_B = $(addprefix $(B_SRCP), $(U_SRC_B))
S_SRCS_B = $(addprefix $(B_SRCP), $(S_SRC_B))

C_OBJS  = $(C_SRCS:.c=.o)
S_OBJS  = $(S_SRCS:.c=.o)
U_OBJS  = $(U_SRCS:.c=.o)

C_OBJS_B  = $(C_SRCS_B:.c=.o)
S_OBJS_B  = $(S_SRCS_B:.c=.o)
U_OBJS_B  = $(U_SRCS_B:.c=.o)

all:$(SERVER) $(CLIENT)

$(B_SRCP)%.o:$(B_SRCP)%.c $(B_SRCP)$(B_HEADER)
	cc $(FLAGS) -c $< -o $@

$(SRCSF)%.o:$(SRCSF)%.c $(SRCSF)$(S_HEADER)
	cc $(FLAGS) -c $< -o $@

$(CLIENT): $(C_OBJS) $(U_OBJS)
	cc $(C_OBJS) $(U_OBJS) -o $@

$(SERVER): $(S_OBJS) $(U_OBJS)
	cc $(S_OBJS) $(U_OBJS) -o $@

bonus: $(SERVER_B) $(CLIENT_B)

$(CLIENT_B): $(C_OBJS_B) $(U_OBJS_B)
	cc $(FLAGS)  $(C_OBJS_B) $(U_OBJS_B) -o $@

$(SERVER_B): $(S_OBJS_B) $(U_OBJS_B)
	cc $(FLAGS) $(S_OBJS_B) $(U_OBJS_B) -o $@
	
clean :
	rm -f $(C_OBJS) $(S_OBJS) $(U_OBJS) $(C_OBJS_B) $(S_OBJS_B) $(U_OBJS_B)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(SERVER_B) $(CLIENT_B)

re : fclean all