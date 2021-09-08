#ifndef GUIMP_H
# define GUIMP_H

# include "../libft/libft.h"
# include "../SDL2/SDL.h"
# define WIDTH	1300
# define HEIGTH	850

typedef struct		s_keyboard
{
	const Uint8	 *key;
	int	mx;
	int my;
	int mxr;
	int myr;
	char mb[8];
}			t_keyboard;

typedef struct		s_fps
{
	double	step;
	double	current;
	double	delta;
	double	last;
	double	count;
}			t_fps;

typedef struct		s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*ren;
	SDL_Event	e;
	t_keyboard	k;
	t_fps		f;
	int		x;
	int		y;
	int		color;
}			t_sdl;


void	midPointCircleDraw(t_sdl *sdl, int x_center, int y_center, int r);
void	midPointCircleDrawR(t_sdl *sdl, int x_center, int y_center, int r);
int		hook_keydown(t_sdl *sdl);
void	draw(t_sdl *sdl);
//void	drawrect(t_sdl *sdl, int x, int y, int v, int w);
void	pixel(t_sdl *sdl);
void	pixelm(t_sdl *sdl, int x, int y);

/*
** macro des fenetres et boutons
*/
# define MAIN_WND_X 500
# define MAIN_WND_Y 100
# define MAIN_WND_W 1200
# define MAIN_WND_H 700

# define TOOLS_WND_X 125
# define TOOLS_WND_Y 100
# define TOOLS_WND_W 300
# define TOOLS_WND_H 700

# define QUIT_BTN_X 0
# define QUIT_BTN_Y 0
# define QUIT_BTN_H 100
# define QUIT_BTN_W 25

# define SAVE_BTN_X 200
# define SAVE_BTN_Y 0
# define SAVE_BTN_H 100
# define SAVE_BTN_W 25

# define POLICE_BTN_X 0
# define POLICE_BTN_Y 60
# define POLICE_BTN_H 100
# define POLICE_BTN_W 25

# define LESS_BTN_X 105
# define LESS_BTN_Y 60
# define LESS_BTN_H 25
# define LESS_BTN_W 25

# define MORE_BTN_X 165
# define MORE_BTN_Y 60
# define MORE_BTN_H 25
# define MORE_BTN_W 25

# define SIZE_BTN_X 135
# define SIZE_BTN_Y 60
# define SIZE_BTN_H 25
# define SIZE_BTN_W 25

# define WRITE_BTN_X 195
# define WRITE_BTN_Y 60
# define WRITE_BTN_H 100
# define WRITE_BTN_W 25

/*
** colors
*/

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define ORANGE 0xFFA500
# define LIME 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define MAROON 0x800000
# define OLIVE 0x808000
# define GREEN 0x008000
# define PURPLE 0x800080
# define TEAL 0x008080
# define NAVY 0x000080

/*
** More awesome colors!
*/

# define CRIMSON 0xDC143C
# define CORAL 0xFF7F50
# define INDIAN_RED 0xCD5C5C
# define SALMON 0xFA8072
# define ORANGE_RED 0xFF4500

# define GOLD 0xFFD700
# define GOLDEN_ROD 0xDAA520
# define DARK_GOLDEN_ROD 0xB8860B
# define SADDLEBROWN 0x8B4513

# define LAWN_GREEN 0x7CFC00
# define DARK_GREEN 0x006400
# define FOREST_GREEN 0x228B22
# define PALE_GREEN 0x98FB98
# define SPRING_GREEN 0x00FF7F
# define SEA_GREEN 0x2E8B57
# define LIGHT_SEA_GREEN 0x20B2AA

# define DARK_SLATE_GRAY 0x2F4F4F
# define POWDER_BLUE 0xB0E0E6

# define AQUA_MARINE 0x7FFFD4
# define STEEL_BLUE 0x4682B4
# define SKY_BLUE 0x87CEEB
# define MIDNIGHT_BLUE 0x191970

# define INDIGO 0x4B0082
# define DARK_MAGENTA 0x8B008B
# define DEEP_PINK 0xFF1493
# define HOT_PINK 0xFF69B4
# define ORCHID 0xFF83FA

# define BEIGE 0xF5F5DC
# define ANTIQUE_WHITE 0xFAEBD7
# define WHEAT 0xF5DEB3
# define CORN_SILK 0xFFF8DC

# define LAVENDER 0xE6E6FA
# define FLORAL_WHITE 0xFFFAF0
# define ALICE_BLUE 0xF0F8FF
# define GHOST_WHITE 0xF8F8FF
# define HONEYDEW 0xF0FFF0
# define IVORY 0xFFFFF0
# define AZURE 0xF0FFFF
# define SNOW 0xFFFAFA
# define MISTY_ROSE 0xFFE4E1

# define DARK_GRAY 0x696969
# define GAINSBORO 0xDCDCDC
# define WHITE_SMOKE 0xF5F5F5

#endif
