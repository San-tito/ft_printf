# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:31:23 by sguzman           #+#    #+#              #
#    Updated: 2023/11/14 12:39:49 by sguzman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #    

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		= libftprintf.a
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_PATH	= ./src

INCLUDE_PATH	= ./include

LIBFT_PATH 	= ./libft

LIBFT 		= $(LIBFT_PATH)/libft.a

HEADER	= $(INCLUDE_PATH)/ft_printf.h

SRCS		= ft_printf.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

OBJS		= $(addprefix objs/, ${SRCS:.c=.o})

################################################################################
#                                 Makefile logic                               #
################################################################################

RED         	= \033[0;31m
GREEN       	= \033[0;32m
YELLOW      	= \033[0;33m
BLUE        	= \033[0;34m
PURPLE      	= \033[0;35m
CYAN        	= \033[0;36m
RESET       	= \033[m

################################################################################
#                                 Makefile rules                             #
################################################################################

all: banner $(NAME) 

banner:
	@printf "%b" "$(PURPLE)"
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
	@printf "%b" "$(RESET)"


$(NAME):	$(OBJS) $(LIBFT)
			@${AR} $@ ${OBJS} 
			@printf "%-84b%b%b" "$(BLUE)Building library:" "$(CYAN)$@\t" "$(GREEN)[✓]$(RESET)\n"

$(LIBFT):	
			@cd $(LIBFT_PATH) && make > /dev/null
			@mv $(LIBFT) $(NAME)
			@printf "%-84b%b%b" "$(BLUE)Building Libft library:" "$(CYAN)$@\t" "$(GREEN)[✓]$(RESET)\n"
			
objs/%.o: 	$(SRCS_PATH)/%.c $(HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
			@printf "%-84b%b%b" "$(BLUE)Compiling:" "$(CYAN)$<\t" "$(GREEN)[✓]$(RESET)\n"

clean:		banner
			@cd $(LIBFT_PATH) && make clean > /dev/null
			@rm -rf objs 
			@printf "%-84b%b" "$(BLUE)clean:" "$(GREEN)[✓]$(RESET)\n"

fclean:		banner clean
			@cd $(LIBFT_PATH) && make fclean > /dev/null
			@rm -rf $(NAME)
			@printf "%-84b%b" "$(BLUE)fclean:" "$(GREEN)[✓]$(RESET)\n"

re:			fclean all

.PHONY:		all clean fclean re banner
