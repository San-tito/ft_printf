# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:31:23 by sguzman           #+#    #+#              #
#    Updated: 2023/12/28 19:23:51 by sguzman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #    

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		= libftprintf.a
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MMD -MF $(@:.o=.d)
AR		= ar -rcs

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_PATH	= ./src

INCLUDE_PATH	= ./include

LIBFT_PATH 	= ./libft

LIBFT 		= $(LIBFT_PATH)/libft.a

HEADER	= $(INCLUDE_PATH)/ft_printf.h

HEADER_BONUS	= $(INCLUDE_PATH)/ft_printf_bonus.h

SRCS =	ft_handle_format.c \
	ft_handle_hex.c \
	ft_handle_number.c \
	ft_handle_string.c \
	ft_printf.c \
	ft_utils.c

SRCS_BONUS =	ft_alignment_bonus.c \
				ft_handle_format_bonus.c \
				ft_handle_hex_bonus.c \
				ft_handle_number_bonus.c \
				ft_handle_string_bonus.c \
				ft_precision_bonus.c \
				ft_printf_bonus.c \
				ft_space_sign_bonus.c \
				ft_utils_bonus.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

OBJS		= $(addprefix objs/, ${SRCS:.c=.o})

OBJS_BONUS		= $(addprefix objs/, ${SRCS_BONUS:.c=.o})

DEPS		= $(addprefix objs/, ${SRCS:.c=.d})

DEPS_BONUS		= $(addprefix objs/, ${SRCS_BONUS:.c=.d})

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

-include $(DEPS) $(DEPS_BONUS)
ifndef BONUS
$(NAME):	$(OBJS) $(LIBFT)
			@cp $(LIBFT) $@
			@$(AR) $@ $(OBJS) 
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building library:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"
else	
$(NAME):	$(OBJS_BONUS) $(LIBFT)
			@cp $(LIBFT) $@
			@$(AR) $@ $(OBJS_BONUS)
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building Bonus library:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"
endif

$(LIBFT):	
			@make bonus -C $(LIBFT_PATH) > /dev/null
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building Libft library:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"
			
objs/%.o: 	$(SRCS_PATH)/%.c $(HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Compiling:" "$(CYAN)" $< "$(GREEN)" "[✓]" "$(RESET)"

objs/%_bonus.o: 	$(SRCS_PATH)/%_bonus.c $(HEADER_BONUS) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
			@printf "%b%-42s%-42b%-30s%b%s%b\n" "$(BLUE)" "Compiling:" "$(CYAN)" $< "$(GREEN)" "[✓]" "$(RESET)"

bonus: 
			@make BONUS=1 --no-print-directory

clean:		banner
			@make clean -C $(LIBFT_PATH) > /dev/null
			@rm -rf objs 
			@printf "%b%-42s%-42b%b%s%b\n" "$(BLUE)" "$@:" "$(CYAN)" "$(GREEN)" "[✓]" "$(RESET)"

fclean:		banner clean
			@make fclean -C $(LIBFT_PATH) > /dev/null
			@rm -rf $(NAME)
			@printf "%b%-42s%-42b%b%s%b\n" "$(BLUE)" "$@:" "$(CYAN)" "$(GREEN)" "[✓]" "$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re banner bonus


