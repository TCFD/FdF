# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 09:08:15 by rciaze            #+#    #+#              #
#    Updated: 2023/03/16 11:27:56 by rciaze           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
MLX_FLAGS 	= -lm -Lmlx -lXext -lX11 -O2
CFLAGS		= -Wall -Wextra -Werror
COMP 		= cc 
CLEANF 		= @(rm -f *.o)
OBJ 		= ${SRCS:.c=.o}

# SRCS

SRCS 		= main.c \
parsing.c \
utils.c \
print_to_image.c 

# Couleurs
BOLD		="\033[1m"
RESET		="\033[0m"
LIGHT_GREEN	="\033[92m"
LIGHT_CYAN	="\033[96m"

all : $(NAME)

$(NAME) : $(OBJ)
	@echo $(BOLD)$(LIGHT_GREEN)On compile les librairies$(RESET)

	@make -s -C librairies/libft
	@echo $(LIGHT_GREEN)	Libft done.$(RESET)
	@make -s -C librairies/minilibx-linux
	@echo $(LIGHT_GREEN)	Mlx done.$(RESET)

	@echo $(BOLD)$(LIGHT_CYAN)On move les librairies$(RESET)
	@mv librairies/libft/libft.a .
	@echo $(LIGHT_CYAN)	Libft done.$(RESET)
	@mv librairies/minilibx-linux/libmlx.a .
	@echo $(LIGHT_CYAN)	Mlx done.$(RESET)

	@$(COMP) $(CFLAGS) $(OBJ) libft.a libmlx.a $(MLX_FLAGS) -o $(NAME)
	@echo $(BOLD)$(LIGHT_GREEN)Tout est prêt !$(RESET)

clean :
	@make -s clean -C librairies/libft
	@echo $(LIGHT_GREEN)	Libft done.$(RESET)
	@make -s clean -C librairies/minilibx-linux
	@echo $(LIGHT_GREEN)	Mlx done.$(RESET)

	@$(CLEANF)
	@echo $(BOLD)$(LIGHT_GREEN).o deleted.$(RESET)

fclean : clean
	
	@echo $(BOLD)$(LIGHT_GREEN)On fclean les librairies$(RESET)
	@make -s fclean -C librairies/libft
	@echo $(LIGHT_GREEN)	Libft done.$(RESET)
	@make -s clean -C librairies/minilibx-linux
	@echo $(LIGHT_GREEN)	Mlx done.$(RESET)

	@rm -f $(NAME)
	@rm -f libft.a
	@rm -f libmlx.a
	@echo $(BOLD)$(LIGHT_GREEN).a deleted.$(RESET)
	@$(CLEANF)
	@echo $(BOLD)$(LIGHT_GREEN).o deleted.$(RESET)
	@echo $(BOLD)$(LIGHT_GREEN)Tout est prêt !$(RESET)

re : fclean all


.PHONY : all re clean fclean 