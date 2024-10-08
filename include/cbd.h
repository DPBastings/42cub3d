/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:58 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/30 14:30:31 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_H
# define CBD_H

# define TITLE			"Void" // I'm taking suggestions for this.
# define FILE_EXT		".cub"
# define FILE_EXT_LEN	4

# define CBD_SCREEN_W_DFL	960
# define CBD_SCREEN_H_DFL	540
# define CBD_RC_RES			CBD_SCREEN_W_DFL
# define CBD_HALF_HEIGHT 	270
# define CBD_VIEW_Z_MARGIN	250
# define CBD_BOX_H_DFL		520
# define FOG_R	138
# define FOG_G	54
# define FOG_B	85
//#8714DF

typedef struct s_game		t_game;
typedef struct s_assets		t_assets;
typedef struct s_screen		t_screen;
typedef struct s_minimap	t_minimap;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_object		t_object;
typedef struct s_rc			t_rc;
typedef struct s_hrc		t_hrc;
typedef struct s_hrc_data	t_hrc_data;
typedef struct s_view		t_view;

typedef enum e_z
{
	CBD_Z_VIEW_BG = 0,
	CBD_Z_VIEW_SCENE,
	CBD_Z_MINIMAP,
	CBD_Z_SCREEN_OVERLAY,
	CBD_Z_SCREEN_OVERLAY_ICON
}	t_z;

#endif // CBD_H
