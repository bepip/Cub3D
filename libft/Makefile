NAME	=	libft.a
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR	=	ar rcs

CFILES	=	ft_tolower.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_strrchr.c \
			ft_split.c \
			ft_striteri.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_isalpha.c \
			ft_memmove.c \
			ft_strncmp.c \
			ft_isprint.c \
			ft_atoi.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_memcmp.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strtok.c \
			ft_calloc.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_memset.c \
			ft_toupper.c \
			ft_itoa.c \
			ft_putstr_fd.c \
			ft_memcpy.c  \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstiter.c \
			ft_dupsplit.c \
			ft_isnumber.c

OBJECTS	=	$(CFILES:.c=.o)

CGNL = 		gnl/get_next_line.c
OGNL = 		$(CGNL:.c=.o)

PRINTF_PATH =	printf/
CPRINTF = 	ft_printdecimal.c \
			ft_printf.c \
			ft_fprintf.c \
			ft_printhexa.c \
			ft_printchar.c \
			ft_printpercent.c \
			ft_printptr.c \
			ft_printstr.c \
			ft_printunint.c

SRC_PRINTF = $(addprefix $(PRINTF_PATH), $(CPRINTF))
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ_PRINTF) $(OBJECTS) $(OGNL)
	$(AR) $(NAME) $(OBJECTS) $(OGNL) $(OBJ_PRINTF)

gnl/%.o:gnl/%.c
	$(CC) $(CFLAGS) -c $< -o $@

printf%.o:printf%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(OGNL) $(OBJ_PRINTF)

fclean:	clean
	rm -f $(NAME)

re: fclean all
