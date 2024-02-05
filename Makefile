NAME 		:= cub3d

SRC_FILES	:= main.c\
			\
			debug.c\
			\
			assets.c\
			error.c\
			game.c\
			object.c\
			player.c\
			player_method.c\
			player_step.c\
			player_turn.c\
			texture.c\
			hook/hooks_init.c\
			hook/hook_controls.c\
			hook/hook_close.c\
			hook/hook_render.c\
			map/map.c\
			map/map_check.c\
			map/map_method.c\
			minimap/minimap.c\
			minimap/minimap_method.c\
			minimap/minimap_render_entities.c\
			minimap/minimap_render_objects.c\
			minimap/minimap_update_viewport.c\
			parse/check.c\
			parse/map_raw.c\
			parse/parse_assets.c\
			parse/parse_utils.c\
			parse/parse_map.c\
			parse/parse_object.c\
			parse/parse_value.c\
			rc/rc.c\
			rc/rc_cast.c\
			screen/screen.c\
			screen/view.c\
			screen/view_render.c\
			utils/mlx_utils.c
OBJ_FILES	:= $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES	:= cbd.h\
			\
			debug.h\
			\
			cbd_assets.h\
			cbd_error.h\
			cbd_game.h\
			cbd_hook.h\
			cbd_map.h\
			cbd_object.h\
			cbd_parse.h\
			cbd_player.h\
			cbd_screen.h\
			cbd_view.h\
			point.h\
			types.h
LIB_FILES	:= lib/libft/libft.a\
			lib/libmlx42_build/libmlx42.a

SRC_DIR		:= ./source/
SRC_SUBDIRS	:= hook map minimap parse rc screen utils
OBJ_DIR		:= ./object/
OBJ_SUBDIRS := $(SRC_SUBDIRS)
HDR_DIR		:= ./include/

CC			:= cc
CFLAGS		+= -Wall -Wextra -Werror -I$(HDR_DIR) -Ilib/libft/include/ -Ilib/libmlx42/include/MLX42/ -g -fsanitize=address

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
	@cmake --build $(dir $@)
	
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
