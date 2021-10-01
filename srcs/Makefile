###################### MANDATORY #######################
NAME		=	libftprintf.a
SRCS		=	ft_printf.c\
			calc_hex.c\
			ft_write_char.c\
			ft_write_string.c\
			ft_write_sp_zero.c\
			ft_write_digit.c\
			ft_write_unsigned.c\
			ft_write_small_hex.c\
			ft_write_large_hex.c\
			ft_write_sp_zero.c\
			ft_write_pointer.c\
			ft_utoa.c\
			ft_utils.c\
			format_deal.c

###################### LIBRARY #######################
LIBFT_DIR	=	libft
LIBFT		=	${LIBFT_DIR}/libft.a
INCLUDE		=	-I./ -I./${LIBFT_DIR}
LIBS		=	-L${LIBFT_DIR} -lft
OBJS		=	${SRCS:.c=.o}

###################### GCC RULES #######################
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror

###################### COMPILE RULES #######################
.c.o:;			${CC} ${CFLAGS} ${INCLUDE} -o $@ -c $<
all:			$(NAME)
${LIBFT}:		${LIBFT_DIR}/*.c
			${MAKE} -C ${LIBFT_DIR}
$(NAME): $(OBJS);	$(MAKE) -C ./libft
			cp ${LIBFT} $(NAME)
			ar rcs $(NAME) $(OBJS)

clean:;			$(RM) *.o
			${MAKE} -C ${LIBFT_DIR} clean
fclean:clean;		$(RM) $(NAME)
			${MAKE} -C ${LIBFT_DIR} fclean
re:			fclean $(NAME)
.PHONY:			re clean fclean all