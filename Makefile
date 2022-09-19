# --------------------------------------------------------------------VARS ---------------------------------------------------------------------------------------------

NAME			= libftprintf.a

CC				= gcc -g

FLAGS			= -Wall -Wextra -Werror

RM				= rm -f 

LIBC 			= ar rcs

# -----------------------------------------------------------------SOURCE FILES ----------------------------------------------------------------------------------------

SRCS			= 	ft_print_nbr.c \
					ft_print_str.c \
					ft_printf.c \
					ft_print_hex.c \
					ft_itoa.c \
					ft_print_ptr.c \

OBJS	   		 = $(addprefix srcs/, $(SRCS:.c=.o))

HEADER			 = -Iincludes -I/includes/ft_printf.h

# -------------------------------------------------------------------- RULES -------------------------------------------------------------------------------------------

.c.o:		
			$(CC) $(FLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all:	    $(NAME)
		
$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS) 

clean:
			$(RM) $(OBJS)
														         
fclean: clean
			$(RM) $(NAME)	

re: fclean all
										

# ----------------------------------------------------------------------PHONY --------------------------------------------------------------------------------------------

.PHONY: all clean fclean re