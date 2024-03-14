NAME = so_long

LIBMLX = lib/libmlx42.a
LIBAMOA = lib/libamoa/libamoa.a


CC = cc

CFLAGS += -Wall -Wextra -Werror -g -Iinclude

LFLAGS = -Llib \
			-lmlx42 -ldl -lglfw -lXext -lX11 -lm

FILES = init_image interaction load_map main map_test \
map_test_bis move parsing print_and_error utils load_text

OBJ_DIR = obj/
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

.PHONY: all clean fclean re bonus deps

all: deps $(NAME)

bonus: all

clean:
	@echo "\033[32m✔ Suppression des fichiers sources...\033[37m"
	rm -rf $(OBJ_DIR)
	@echo "\033[32m✔ Suppression effectuer...\033[37m"

fclean: clean
	@echo "\033[32m✔ Suppression de l'éxécutable...\033[37m"
	rm -rf $(NAME)
	@echo "\033[32m✔ Suppression effectuer...\033[37m"

re: fclean all

deps:
	$(MAKE) -C lib/libamoa
	$(MAKE) clean -C lib/libamoa

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBMLX) $(LIBAMOA)
	@echo "\033[32m✔ Compilation des fichiers sources...\033[37m"
	$(CC) -o $@ $(OBJS) $(LIBAMOA) $(LFLAGS)
	@echo "\033[32m✔ executable crée...\033[37m"

$(OBJ_DIR):
	@echo "\033[32m✔ création du repertoire src...\033[37m"
	mkdir $@
	@echo "\033[32m✔ repertoire src crée...\033[37m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@