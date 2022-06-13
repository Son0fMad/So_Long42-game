
SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
			ft_isascii.c	ft_isprint.c	ft_strlen.c\
			ft_memset.c		ft_bzero.c		ft_memcpy.c\
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
			ft_toupper.c	ft_tolower.c	ft_strchr.c\
			ft_strrchr.c	ft_strncmp.c	ft_strcmp.c\
			ft_memchr.c		ft_memcmp.c		ft_strnstr.c\
			ft_atoi_ps.c	ft_calloc.c		ft_strdup.c\
			ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_substr.c\
			ft_strjoin.c	ft_strtrim.c	ft_strmapi.c\
			ft_itoa.c		ft_split.c\
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	get_next_line.c		ft_strcpy.c\

OBJ		=	${SRCS:.c=.o}
NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HEADER	=	libft.h
LIBC	=	ar rc
RM		=	rm -f

.c.o:		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

$(NAME)	:	${HEADER} ${OBJ}
			${LIBC} ${NAME} ${OBJ}

all		:	${NAME}

clean	:
			${RM} ${OBJ}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	.c.o all clean fclean re
