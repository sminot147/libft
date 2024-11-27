# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 14:53:08 by sminot            #+#    #+#              #
#    Updated: 2024/11/27 11:54:33 by sminot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHAR_DIR = src/char/

CHAR = ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\

INT_DIR = src/int/

INT = ft_atoi.c\
	ft_itoa.c\

LST_DIR = src/lst/

LST = ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

MEM_DIR = src/mem/

MEM = ft_bzero.c\
	ft_calloc.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\

PUT_DIR = src/put/

PUT = putchar_fd.c\
	putstr_fd.c\
	putnbr_fd.c\
	putendl_fd.c\

STR_DIR = src/str/

STR = ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\

FILE = $(addprefix $(CHAR_DIR), $(CHAR))\
	$(addprefix $(INT_DIR), $(INT))\
	$(addprefix $(MEM_DIR), $(MEM))\
	$(addprefix $(PUT_DIR), $(PUT))\
	$(addprefix $(STR_DIR), $(STR))\

FILEB = $(addprefix $(LST_DIR), $(LST))

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(FILE:.c=.o))
OBJB = $(addprefix $(OBJ_DIR)/, $(FILEB:.c=.o))

DEPS= $(OBJ:.o=.d) $(OBJB:.o=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -MMD
INCLUDE = include

AR = ar -rsc

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(OBJ) $(OBJB)
	$(AR) $(NAME) $(OBJ) $(OBJB)

-include $(DEPS)

.PHONY : all, clean, fclean, re, bonus

#OBJ = $(subst $(SRC_DIR),$(SRC_OBJ),$(FILE:.c=.o))
#Mettre un pip | pour regarder si la regle existe.