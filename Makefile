NAME=		libftprintf.a

CC=		cc

FLAGS=		-Wall -Wextra -Werror

LIBFT_DIR=	./libft
LIBFT=		$(LIBFT_DIR)/libft.a
LIBFT_SRCS=	$(LIBFT_DIR)/ft_atoi.c \
			$(LIBFT_DIR)/ft_putchar.c \
			$(LIBFT_DIR)/ft_nbrsize.c \
			$(LIBFT_DIR)/ft_putstr.c \
			$(LIBFT_DIR)/ft_power.c

LIBFT_INC=	$(LIBFT_DIR)/libft.h

SRCS_DIR=	./srcs
SRCS=		$(SRCS_DIR)/ft_printf.c \
			$(SRCS_DIR)/ft_printf_utils.c \
			$(SRCS_DIR)/ft_convert_p.c \
			$(SRCS_DIR)/ft_convert_x.c \
			$(SRCS_DIR)/ft_convert_u.c \
			$(SRCS_DIR)/ft_convert_d_i.c \
			$(SRCS_DIR)/ft_convert_c.c \
			$(SRCS_DIR)/ft_convert_s.c \

PRINTF_INC=	./includes/

OBJS=		$(SRCS:.c=.o)
LIBFT_OBJS=	$(LIBFT_SRCS:.c=.o)
INCS=		-I$(LIBFT_DIR) -I$(PRINTF_INC)

HEADER=		ft_printf.h

%.o: %.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

all: $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	ar -rcs $(LIBFT) $(LIBFT_OBJS)
	cp $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

bonus: all

.PHONY: all clean fclean re
