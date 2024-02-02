NAME = so_long

LIBMLX = lib/libmlx42.a
LIBAMOA = lib/libamoa.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Iinclude

LFLAGS = -Llib \
			-lmlx42 -lamoa -ldl -lglfw -lXext -lX11 -lm

FILES = main parsing map_test ft_init

OBJ_DIR = obj/
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBMLX) $(LIBAMOA)
	$(CC) -o $@ $(OBJS) $(LFLAGS) 

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
