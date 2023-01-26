# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 21:43:09 by aamhamdi          #+#    #+#              #
#    Updated: 2023/01/26 22:32:22 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# paths
SRCSF  = src/
OBJSF  = build/
B_SRCP = bonus/

# names
CLIENT = client
SERVER = server

# srcs
C_SRC  = client.c
S_SRC  = server.c
U_SRC  = mini_talk_utils.c
C_SRCS = $(addprefix $(SRCSF), $(C_SRC))
U_SRCS = $(addprefix $(SRCSF), $(U_SRC))
S_SRCS = $(addprefix $(SRCSF), $(S_SRC))

# objs
C_OBJ  = $(C_SRC:.c=.o)
S_OBJ  = $(S_SRC:.c=.o)
U_OBJ  = $(U_SRC:.c=.o)
C_OBJS = $(addprefix $(OBJSF), $(C_OBJ))
U_OBJS = $(addprefix $(OBJSF), $(U_OBJ))
S_OBJS = $(addprefix $(OBJSF), $(S_OBJ))


all:$(SERVER) $(CLIENT)

$(OBJSF):
	mkdir -p $(OBJSF)

$(OBJSF)%.o:$(SRCSF)%.c $(OBJSF)
	cc -Wall -Wextra -Werror -c $< -o $@

$(CLIENT): $(C_OBJS) $(U_OBJS) 
	cc $(C_OBJS) $(U_OBJS) -o $@

$(SERVER): $(S_OBJS) $(U_OBJS)
	cc $(S_OBJS) $(U_OBJS) -o $@

clean :
	rm -rf $(OBJSF)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re : fclean all