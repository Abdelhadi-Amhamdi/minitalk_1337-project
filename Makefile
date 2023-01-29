# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 21:43:09 by aamhamdi          #+#    #+#              #
#    Updated: 2023/01/29 13:13:56 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# paths
SRCSF  = src/
OBJSF  = build/
B_SRCP = bonus/

# headers
S_HEADER=mini_talk.h
B_HEADER=mini_talk_bonus.h

# names
CLIENT = client
SERVER = server

CLIENT_B = client_bonus
SERVER_B = server_bonus

# srcs
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

# objs
C_OBJ  = $(C_SRC:.c=.o)
S_OBJ  = $(S_SRC:.c=.o)
U_OBJ  = $(U_SRC:.c=.o)

C_OBJ_B  = $(C_SRC_B:.c=.o)
S_OBJ_B  = $(S_SRC_B:.c=.o)
U_OBJ_B  = $(U_SRC_B:.c=.o)

C_OBJS_B = $(addprefix $(OBJSF), $(C_OBJ_B))
U_OBJS_B = $(addprefix $(OBJSF), $(U_OBJ_B))
S_OBJS_B = $(addprefix $(OBJSF), $(S_OBJ_B))

C_OBJS = $(addprefix $(OBJSF), $(C_OBJ))
U_OBJS = $(addprefix $(OBJSF), $(U_OBJ))
S_OBJS = $(addprefix $(OBJSF), $(S_OBJ))


all:$(SERVER) $(CLIENT)

$(OBJSF):
	mkdir -p $(OBJSF)

$(OBJSF)%.o:$(B_SRCP)%.c $(OBJSF) $(B_SRCP)$(B_HEADER)
	cc -Wall -Wextra -Werror -c $< -o $@

$(OBJSF)%.o:$(SRCSF)%.c $(OBJSF) $(SRCSF)$(S_HEADER)
	cc -Wall -Wextra -Werror -c $< -o $@

$(CLIENT): $(C_OBJS) $(U_OBJS) 
	cc $(C_OBJS) $(U_OBJS) -o $@

$(SERVER): $(S_OBJS) $(U_OBJS)
	cc $(S_OBJS) $(U_OBJS) -o $@

bonus: $(SERVER_B) $(CLIENT_B)


$(CLIENT_B): $(C_OBJS_B) $(U_OBJS_B)
	cc  $(C_OBJS_B) $(U_OBJS_B) -o $@

$(SERVER_B): $(S_OBJS_B) $(U_OBJS_B)
	cc  $(S_OBJS_B) $(U_OBJS_B) -o $@
	
clean :
	rm -rf $(OBJSF)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(SERVER_B) $(CLIENT_B)

re : fclean all