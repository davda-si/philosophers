# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 19:49:44 by david             #+#    #+#              #
#    Updated: 2024/02/29 18:45:50 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/pars.c $(SRC_DIR)/utils.c $(SRC_DIR)/create_mt.c $(SRC_DIR)/life.c $(SRC_DIR)/grim_reap.c

CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread


#LIBFT_PATH = ./libs/libft
#LIBFT = $(LIBFT_PATH)/libft.a

OBJ_DIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	@echo "*-----------------*"
	@echo "|Compilation done!|"
	@echo "*-----------------*"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

#$(LIBFT):
#	@make -s -C $(LIBFT_PATH)

clean:
	@echo "*--------------*"
	@echo "|Cleaning done!|"
	@echo "*--------------*"
	@rm -rf $(OBJS) $(NAME)
#	@make -s -C $(LIBFT_PATH) clean
	
fclean: clean
	@rm -f $(NAME)
#	@rm -f $(LIBFT)

re: fclean all

.PHONY:         all clean fclean re
