##
## makefile fed in the abyss
## rudreais
##
##

CC		=	gcc

CFLAGS		+=	-I $(DIRINC)	\
			-Wall -Wextra -W	\
			-g

LDFLAGS		+=	-lncurses

DIRLIB		+=	lib/

DIRSRC		+=	src/

DIRINC		+=	include/

SRC		+=	$(DIRLIB)paths.c		\
			$(DIRLIB)readline.c		\
			$(DIRLIB)objects/string.c	\
			$(DIRLIB)objects/o_strings.c	\
			$(DIRSRC)main.c			\
			$(DIRSRC)init_level.c		\
			$(DIRSRC)destroy_level.c	\
			$(DIRSRC)game_loop.c		\
			$(DIRSRC)border_cam.c		\
			$(DIRSRC)move_charac.c		\
			$(DIRSRC)attack.c		\
			$(DIRSRC)core/files.c		\
			$(DIRSRC)core/gen_map.c		\
			$(DIRSRC)screens/logs.c		\
			$(DIRSRC)screens/player_info.c	\
			$(DIRSRC)prints.c		\
			$(DIRSRC)player.c		\
			$(DIRSRC)enemy.c

OBJ		=	$(SRC:.c=.o)

EXEC		=	fita

all:		$(EXEC)

$(EXEC):	$(OBJ)
		$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(EXEC)

re:		fclean all

.PHONY:		all clean fclean re
