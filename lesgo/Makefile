NAME = pipex
HEADER = pipex/pipex.h

MANDATORY = utils/checks.c utils/errors.c utils/find_cmd.c utils/find_string.c\
			utils/free_all.c utils/free_dbl_pntr.c utils/ft_putstr_fd.c\
			utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlcpy.c\
			utils/ft_strlen.c utils/size_pntr_array.c utils/utils.c mandatory/pipex.c


MANOBJ = $(MANDATORY:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

REMOVE = rm -f

all: $(NAME)

$(NAME): $(MANOBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	$(REMOVE) $(MANOBJ)

fclean: clean
	$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
