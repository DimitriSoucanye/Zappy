##
## Makefile for dqs in /home/galpin_a/PSU_2016_zappy
##
## Made by Antoine Galpin
## Login   <galpin_a@epitech.net>
##
## Started on  Tue Jun 27 20:15:03 2017 Antoine Galpin
## Last update Thu Jun 29 19:01:59 2017 Daniel Dessaux
##

SERVER =	zappy_server

AI =		zappy_ai

CLIENT =	zappy_client

SRCSSERV +=	srcs/server/main.c \
		srcs/server/args_map.c \
		srcs/server/args_others.c \
		srcs/server/check_and_free_functions.c \
		srcs/server/choose_arg.c \
		srcs/server/dump_infos.c \
		srcs/server/my_getline.c \
		srcs/server/my_str_to_wordtab.c \
		srcs/server/xfunctions.c \
		srcs/server/init.c \
		srcs/server/choose_cmds.c \
		srcs/server/choose_cmds2.c \
		srcs/server/add_list.c \
		srcs/server/player.c \
		srcs/server/update_map.c \
		srcs/server/choose_cmds3.c \
		srcs/server/take_obj_cmd.c \
		srcs/server/choose_cmds4.c \
		srcs/server/broadcast.c \
		srcs/server/direction.c \
		srcs/server/look_cmd.c \
		srcs/server/generator.c \
		srcs/server/pose_obj_cmd.c \
		srcs/server/set_look_view.c \
		srcs/server/incantation.c \
		srcs/server/incantation_list.c \
		srcs/server/incantation_ressources.c \
		srcs/server/server.c

SRCSAI +=	srcs/AI/main.cpp \
		srcs/AI/NewAI.cpp \
		srcs/client/Socket.cpp \
		srcs/client/my_getline.cpp \
		srcs/client/Map.cpp \
		srcs/AI/lookParser.cpp \
		srcs/AI/mainloop.cpp \
		srcs/AI/command.cpp \
		srcs/AI/case.cpp \
		srcs/AI/checkValue.cpp \
		srcs/AI/checkLvl.cpp

SRCSCLIENT +=	srcs/client/client.cpp \
		srcs/client/Socket.cpp \
		srcs/client/my_getline.cpp \
		srcs/client/Map.cpp \
		srcs/client/main.cpp

OBJSERV +=	$(SRCSSERV:.c=.o)
OBJAI +=	$(SRCSAI:.cpp=.o)
OBJCLIENT +=	$(SRCSCLIENT:.cpp=.o)

CFLAGS +=	-g3 -W -Wall -Wextra -Iinclude/ -I/usr/local/include/
CXXFLAGS +=	 -std=c++14 -W -Wall -Wextra -Iinclude/ -I/usr/local/include/

SFMLFLAGS +=	-L/usr/local/lib/ \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lsfml-network

all:		zappy_servers zappy_ais zappy_clients

zappy_clients:	$(CLIENT)

zappy_servers:	$(SERVER)

zappy_ais:	$(AI)

$(SERVER):	$(OBJSERV)
		gcc $(OBJSERV) -o $(SERVER)

$(AI):		$(OBJAI)
		g++ -lpthread $(OBJAI) -o $ $(AI)

$(CLIENT):	$(OBJCLIENT)
		g++ -lpthread -o $(CLIENT) $(OBJCLIENT) $(SFMLFLAGS)

clean:
		rm -rf $(OBJSERV)
		rm -rf $(OBJAI)
		rm -rf $(OBJCLIENT)

fclean:		clean
		rm -rf $(SERVER)
		rm -rf $(AI)
		rm -rf $(CLIENT)

re:		fclean all

.PHONY:		all zappy_servers zappy_ais clean fclean re
