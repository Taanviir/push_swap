# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanas <tanas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 20:23:05 by tanas             #+#    #+#              #
#    Updated: 2023/05/18 17:00:10 by tanas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
C_FLAGS = -Wall -Wextra -Werror -g3
LIBFT = libft/libft.a
INCLUDES = -Iincludes/ -Ilibft/includes/

SRCS_DIR = sources/
SRCS_LIST = main.c \
			error.c \
			error2.c \
			stack.c \
			stack_utils.c \
			sort.c \
			operations.c \
			operations2.c \
			sort2.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objects/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:c=o))

HEADERS = includes/push_swap.h

# colours
GREEN 			= "\033[1;32m"
RED 			= "\033[1;3;31m"
BLUE 			= "\033[3;34m"
YELLOW 			= "\033[0;33m"
COLOUR_RESET 	= "\033[0m"

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@echo $(YELLOW)"\nCreating push_swap executable."$(COLOUR_RESET)
	@cc $(C_FLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $@
	@echo $(GREEN)"push_swap is ready. ✅\n"$(COLOUR_RESET)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	@cc $(C_FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BLUE)"Compiling $<."$(COLOUR_RESET)

$(LIBFT) :
	@echo $(YELLOW)"Creating $(LIBFT)"$(COLOUR_RESET)
	@make -sC libft
	@echo $(GREEN)"\nLibft is ready. ✅\n"$(COLOUR_RESET)

clean :
	@make clean -sC libft
	@rm -rf $(OBJS_DIR)
	@echo $(RED)"\nRemoving object directory and files."$(COLOUR_RESET)

fclean : clean
	@make fclean -sC libft
	@rm -rf $(NAME)
	@echo $(RED)"Removing executable files.\n"$(COLOUR_RESET)

re : fclean all

.PHONY : all clean fclean re