NAME = libftprintf.a
CC = cc
LIB1 = libft/libft.a
FLAGS = -Wall -Wextra -Werror
VAR = ar rcs
SRCS = ft_printf.c ft_itoa_void.c ft_putnbr_hexa.c ft_putstr.c ft_putchar.c
OBJS = ${SRCS:.c=.o}
	
all : ${NAME}
${NAME} : subMake ${OBJS}
	${VAR}  ${NAME}  ${OBJS} ${LIB1}
%.o : %.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@
subMake :
	make -C libft
clean :
	rm -f ${OBJS}
fclean : clean
	rm -f ${NAME}
re : fclean all
.PHONY: all clean fclean re subMake
