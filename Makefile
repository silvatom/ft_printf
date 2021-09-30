NAME=	libftprintf.a

CC=		clang

FLAGS=	-Wall -Wextra -Werror

SRCS=	ft_printf.c \
		ft_printf_utils.c \
		ft_convert_p.c \
		ft_convert_x.c \
		ft_convert_u.c \
		ft_convert_d_i.c \
		ft_convert_c.c \
		ft_convert_s.c \

OBJS=	$(SRCS:.c=.o)

HEADER=	ft_printf.h

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re
