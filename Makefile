# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:31:23 by sguzman           #+#    #+#              #
#    Updated: 2023/11/23 01:59:33 by santito          ###   ########.fr        #
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

SRCS		= ft_handle_format.c ft_handle_hexa.c   ft_handle_number.c ft_handle_string.c ft_printf.c        ft_utils.c

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
	@echo -e "$(PURPLE)"
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
	@echo -e "$(RESET)"


$(NAME):	$(OBJS) $(LIBFT)
			@${AR} $@ ${OBJS} 
			@echo -e "$(BLUE)Building library:\t\t\t\t\t\t\t\t$(CYAN)$@\t$(GREEN)[✓]$(RESET)"

$(LIBFT):	
			@cd $(LIBFT_PATH) && make &> /dev/null
			@mv $(LIBFT) $(NAME)
			@echo -e "$(BLUE)Building Libft library:\t\t\t\t\t\t\t\t$(CYAN)$@\t$(GREEN)[✓]$(RESET)"
			
objs/%.o: 	$(SRCS_PATH)/%.c $(HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
			@echo -e "$(BLUE)Compiling:\t\t\t\t\t\t\t\t$(CYAN)$<\t$(GREEN)[✓]$(RESET)"

clean:		banner
			@cd $(LIBFT_PATH) && make clean &> /dev/null
			@rm -rf objs 
			@echo -e "$(BLUE)$@:\t\t\t\t\t\t\t\t$(CYAN)$<\t$(GREEN)[✓]$(RESET)"

fclean:		banner clean
			@cd $(LIBFT_PATH) && make fclean &> /dev/null
			@rm -rf $(NAME)
			@echo -e "$(BLUE)$@:\t\t\t\t\t\t\t\t$(CYAN)$<\t$(GREEN)[✓]$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re banner
