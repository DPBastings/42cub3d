NAME 		:= cub3d

SRC_FILES	:= main.c\
			error.c\
			texture.c\
			cbd/load.c\
			cbd/load_assets.c\
			cbd/load_map.c\
			parse/parse_asset.c\
			parse/parse_map.c\
			parse/parse_utils.c\
			parse/parse_value.c
OBJ_FILES	:= $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES	:= cbd.h\
			cbd_assets.h\
			cbd_error.h\
			cbd_game.h\
			cbd_map.h\
			cbd_parse.h\
			raycaster.h\
			types.h
LIB_FILES	:= lib/libft/libft.a\
			lib/libmlx42_build/libmlx42.a

SRC_DIR		:= ./source/
SRC_SUBDIRS	:= cbd parse
OBJ_DIR		:= ./object/
OBJ_SUBDIRS := $(SRC_SUBDIRS)
HDR_DIR		:= ./include/

CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror -I$(HDR_DIR) -Ilib/libft/include/ -Ilib/libmlx42/include/MLX42/
LIBFLAGS	:= -lglfw -L/usr/lib -ldl -pthread -lm
DEPFLAGS	:= -MMD $(@.o=.d) -MP
DEP_FILES	:= $(patsubst %.o,%.d,$(addprefix $(OBJ_DIR), $(OBJ_FILES)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES)) $(LIB_FILES)
	@$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c # $(addprefix $(HDR_DIR),$(HDR_FILES))
	@mkdir -p $(addprefix $(OBJ_DIR),$(OBJ_SUBDIRS))
	@$(CC) $(CFLAGS) $(DEPFLAGS) -I$(SRC_DIR) $< -c -o $@

lib/libft/libft.a:
	@git submodule init
	@git submodule update
	@$(MAKE) --directory=$(dir $@)

lib/libmlx42_build/libmlx42.a:
	@git submodule init
	@git submodule update
	@cmake -S ./lib/libmlx42/ -B $(dir $@)
	@cmake  --build $(dir $@)
	
clean:
	$(MAKE) --directory=./lib/libft/ clean
	cmake --build ./lib/libmlx42_build/ --target clean
	@rm -f $(addprefix $(OBJ_DIR),$(OBJ_FILES))\
		$(addprefix $(OBJ_DIR),$(patsubst %.o,%.d,$(OBJ_FILES)))

fclean: clean
	$(MAKE) --directory=./lib/libft/ fclean
	@rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
