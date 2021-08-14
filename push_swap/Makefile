NAME   :=	push_swap
CHKR   :=	checker
SRCS   :=	push_swap.c argv_parser.c \
			check_argv.c manipulate_stack.c \
			sort_stack.c sort_stack_utils.c \
			utils.c shift_stack.c selection.c
OBJS   :=	$(SRCS:.c=.o)
SRCS_  :=	checker.c argv_parser.c check_argv.c utils.c \
			get_next_line.c get_next_line_utils.c \
			manipulate_stack.c
OBJS_  :=	$(SRCS_:.c=.o)
HDR    :=	push_swap.h
CC     :=	gcc
CFLAGS :=	-Wall -Wextra -Werror -MMD 
VPATH  :=	src include
all:		$(NAME)

$(NAME):	$(OBJS) $(HDR)
			$(MAKE) -C libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

bonus:		$(CHKR)

$(CHKR):	$(OBJS_) $(HDR)
			$(MAKE) -C libft
			$(CC) $(CFLAGS) -o $@ $(OBJS_)  -Llibft -lft	
%.o: %.c
			$(CC) $(CFLAGS) -c $< $(addprefix -I,include libft)

include		$(wildcard *.d)

clean:
			rm -rf *.o *.d
			$(MAKE) clean -C libft

fclean:		clean
			rm -rf $(NAME) $(CHKR)
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus
