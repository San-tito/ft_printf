# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:31:23 by sguzman           #+#    #+#              #
#    Updated: 2023/11/13 17:33:03 by sguzman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #    

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= libftprintf.a
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_PATH		= ./src

INCLUDE_PATH	= ./include

LIBFT_PATH 		= ./libft

LIBFT 			= $(LIBFT_PATH)/libft.a

SRCS			= ft_printf.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

OBJS				= $(addprefix objs/, ${SRCS:.c=.o})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

################################################################################
#                                 Makefile rules                             #
################################################################################

all: banner $(NAME)

banner:
	@printf "%b" "$(OK_COLOR)"
	@echo
	@echo "# **************************************************************************** #"
	@echo "#                                                                              #"
	@echo "#                                                         :::      ::::::::    #"
	@echo "#    ft_printf                                          :+:      :+:    :+:    #"
	@echo "#                                                     +:+ +:+         +:+      #"
	@echo "#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #"
	@echo "#                                                 +#+#+#+#+#+   +#+            #"
	@echo "#                                                      #+#    #+#              #"
	@echo "#                                                     ###   ########.fr        #"
	@echo "#                                                                              #"
	@echo "# **************************************************************************** #"
	@echo 
	@printf "%b" "$(NO_COLOR)"


$(NAME):	${OBJS} $(LIBFT) 
			@printf "%-84b%b%b" "$(COM_COLOR)build library:" "$(OBJ_COLOR)$@\t" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
			@${AR} ${NAME} ${OBJS}
			
objs/%.o: 	$(SRCS_PATH)/%.c
			@printf "%-84b%b%b" "$(COM_COLOR)compiling:" "$(OBJ_COLOR)$<\t" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)

$(LIBFT):
			@printf "%-84b%b%b" "$(COM_COLOR)build libft library:" "$(OBJ_COLOR)$@\t" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
			@cd $(LIBFT_PATH) && make > /dev/null
			@cp $(LIBFT) $(NAME)

clean:		banner
			@cd $(LIBFT_PATH) && make clean > /dev/null
			@rm -rf objs 
			@printf "%-84b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		banner clean
			@cd $(LIBFT_PATH) && make fclean > /dev/null
			@rm -rf $(NAME)
			@printf "%-84b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re banner
