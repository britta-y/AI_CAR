##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

NAME	= 	ai

CC	=	gcc

RM	=	rm -f

SRCS	=	src/main.c		\
		src/end_track.c		\
		src/str_to_word_array.c

OBJS	= 	$(SRCS:.c=.o)

CPPFLAGS	=	-Iinclude

CFLAGS 	+=	-Wall -Wextra

all:		$(NAME)

$(NAME): 	$(OBJS)
	 		$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
