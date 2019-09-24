SRCS	= srcs/affichage.c\
	  srcs/check_sol.c\
	  srcs/interface.c\
	  srcs/main.c\

OBJS	= ${SRCS:.c=.o}

NAME 	= morpion

CFLAGS	= -Wall -Werror -Wextra -Iincludes/

RM	= rm -f

CC	= gcc

all:		${NAME}

${NAME}:	${OBJS}
		gcc ${CFLAGS} ${OBJS} -o ${NAME}
		@echo -e "\n\nHERE IS YOUR NEWLY CREATED, \e[36mBEAUTIFUL\e[0m, IMMERSIVE AND COMPLEX \e[95mGAMING EXPERIENCE"

clean:
		${RM} ${OBJS}

fclean: 	clean
		${RM} ${NAME}

re:		fclean all

gud:		all clean


.PHONY:		all fclean clean re gud
