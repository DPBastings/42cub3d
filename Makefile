NAME 		:= cub3D

SRC_FILES	:= main.c\
			assets.c\
			error.c\
			game.c\
			game_status.c\
			object.c\
			texture.c\
			hook/hooks_init.c\
			hook/hook_close.c\
			hook/hook_controls.c\
			hook/hook_cursor.c\
			hook/hook_key.c\
			hook/hook_move.c\
			hook/hook_render.c\
			hook/hook_scroll.c\
			hook/hook_view.c\
			hook/hook_fps.c \
			math/dvector.c\
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
			player/player.c\
			player/player_method.c\
			player/player_step.c\
			player/player_turn.c\
			rc/camera.c\
			rc/dda.c\
			rc/ray.c\
			rc/rc.c\
			rc/rc_cast.c\
			screen/screen.c\
			screen/screen_overlay.c\
			screen/screen_overlay_method.c\
			screen/view.c\
			screen/view_render.c\
			screen/view_render_scene.c\
			screen/view_utils.c \
			MLX42_ext/mlx_utils.c\
			MLX42_ext/mlx_put_line.c\
			hrc/hrc.c \
			hrc/hrc_utils.c \

OBJ_FILES	:= $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES	:= cbd.h\
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
			types.h\
			MLX42_ext.h\

LIB_FILES	:= lib/libft/libft.a\
			lib/libmlx42_build/libmlx42.a

SRC_DIR		:= ./source/
SRC_SUBDIRS	:= hook math map minimap parse player rc screen MLX42_ext hrc
OBJ_DIR		:= ./object/
OBJ_SUBDIRS := $(SRC_SUBDIRS)
HDR_DIR		:= ./include/

CC			:= cc
CFLAGS		+= -Wall -Wextra -Wextra -Ofast -I$(HDR_DIR) -Ilib/libft/include/ -Ilib/libmlx42/include/MLX42/

LIBFLAGS	:= -lglfw -L/usr/lib -ldl -pthread -lm
DEPFLAGS	:= -MMD $(@.o=.d) -MP
DEP_FILES	:= $(patsubst %.o,%.d,$(addprefix $(OBJ_DIR), $(OBJ_FILES)))

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
BLUE 		= 	\033[34;01m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)[+] SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)[?] INFO$(RESET)]
_ID			=	[$(BLUE)$(NAME)$(RESET)]
_ID_MLX		=	[$(BLUE)MLX$(RESET)]
_ID_LFT		=	[$(BLUE)LIBFT$(RESET)]
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES)) $(LIB_FILES)
	@$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o $@
	@printf "$(_SUCCESS) Project compiled ->$(_ID)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@git submodule init
	@git submodule update
	@mkdir -p $(addprefix $(OBJ_DIR),$(OBJ_SUBDIRS))
	@$(CC) $(CFLAGS) $(DEPFLAGS) -I$(SRC_DIR) $< -c -o $@

lib/libft/libft.a:
	@git submodule init
	@git submodule update
	@$(MAKE) --directory=$(dir $@) --silent
	@printf "$(_INFO) Archive created ->$(_ID_LFT)\n"

lib/libmlx42_build/libmlx42.a:
	@git submodule init
	@git submodule update
	@cmake -S ./lib/libmlx42/ -B $(dir $@)
	@cmake --build $(dir $@)
	@printf "$(_INFO) Archive created ->$(_ID_MLX)\n"

bonus: all

clean:
	@$(MAKE) -C ./lib/libft/ clean --silent
	@cmake --build ./lib/libmlx42_build/ --target clean
	@rm -f $(addprefix $(OBJ_DIR),$(OBJ_FILES))\
		$(addprefix $(OBJ_DIR),$(patsubst %.o,%.d,$(OBJ_FILES)))
	@printf "$(_INFO) Object files deleted ->$(_ID)\n"

fclean: clean
	@$(MAKE) -C ./lib/libft/ fclean --silent
	@rm -f $(NAME)
	@printf "$(_INFO) Executable removed ->$(_ID)\n"

re: fclean all

-include $(DEP_FILES)
