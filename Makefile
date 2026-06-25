NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rcs
RM			= rm -f

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= ft_printf.c \
			  ft_putnbr_base.c

OBJS		= $(SRCS:.c=.o)

HEADER		= ft_printf.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re