# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:00:03 by adgarcia          #+#    #+#              #
#    Updated: 2020/03/06 22:43:49 by adgarcia         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 			= 	libftprintf.a

HEADER			=	ft_printf.h

LIBFT_SRCS		=	ft_atoi.c				\
					ft_bzero.c				\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isdigit.c			\
					ft_isprint.c			\
					ft_memcpy.c				\
					ft_memset.c				\
					ft_strchr.c				\
					ft_strrchr.c			\
					ft_strlen.c				\
					ft_strncmp.c			\
					ft_strnstr.c			\
					ft_tolower.c			\
					ft_toupper.c			\
					ft_memccpy.c			\
					ft_memmove.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_strdup.c				\
					ft_strjoin.c			\
					ft_substr.c				\
					ft_strtrim.c			\
					ft_split.c				\
					ft_itoa.c				\
					ft_calloc.c				\
					ft_strmapi.c			\
					ft_putchar_fd.c			\
					ft_putstr_fd.c			\
					ft_putendl_fd.c			\
					ft_putnbr_fd.c			\
					ft_strlcat.c			\
					ft_strlcpy.c			\
					ft_lstnew_bonus.c		\
					ft_lstadd_front_bonus.c	\
					ft_lstsize_bonus.c		\
					ft_lstlast_bonus.c		\
					ft_lstadd_back_bonus.c	\
					ft_lstdelone_bonus.c	\
					ft_lstclear_bonus.c		\
					ft_putnbr_base.c		\
					ft_numlen_base.c		\
					ft_print_repeated_char.c\

LIBFT_INC		=	libft/libft.h

LIB				=	libft/libft.a

SRCS			=	ft_signed.c				\
					ft_printf.c				\
					ft_unsigned.c 			\
					ft_pars.c				\
					ft_str.c				\
					ft_char.c				\
					ft_ptr.c				\
					
OBJS			= 	$(SRCS:.c=.o) $(addprefix libft/, $(LIBFT_SRCS:.c=.o))
	
all				: 	$(NAME)

$(NAME)			:	$(OBJS)
				make -C libft
				cp libft/libft.a $(NAME)
				ar -rcs $(NAME) $(LIB) $(OBJS)

bonus			:	$(NAME)

%.o:%.c				$(HEADER) $(LIBFT_INC)
				gcc -Wall -Wextra -Werror -o $@ -c $< -I $(HEADER) -I $(LIBFT_INC)

clean			:
				make clean -C libft
				/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean			:	clean
				make fclean -C libft
				/bin/rm -f $(NAME)

re				: 	fclean all
