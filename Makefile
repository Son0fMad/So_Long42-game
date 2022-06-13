NAME		=	so_long

SRCS		=	${shell find ./src -name "*.c"}

OBJS		=	$(SRCS:.c=.o)

LIB_DIR		=	libft
MLX_DIR		=	miniLibx
INCLUDE		=	-I./include -I./libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
MLX_FLAGS	=	-L miniLibx -lmlx -framework OpenGL -framework AppKit

all			:	$(NAME)

%.o			:	%.c include
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME)		:	$(OBJS)
				@make -C ${LIB_DIR}
				@make -C ${MLX_DIR}
				@$(CC) ${CFLAGS} ${MLX_FLAGS} $(INCLUDE) ${LIB_DIR}/libft.a ${OBJS} -o $(NAME)
				@clear

clean		:
				@make clean -C ${LIB_DIR}
				@make clean -C ${MLX_DIR}
				${RM} $(OBJS)

fclean		:	clean
				@make fclean -C ${LIB_DIR}
				@make clean -C ${MLX_DIR}
				${RM} $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re

