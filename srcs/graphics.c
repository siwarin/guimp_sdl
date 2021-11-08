#include "../include/guimp.h"

void	clearscreen(t_sdl *sdl) // flush total de l'écran
{
	int x = 0;
	int y = 0;

	sdl->color = BLACK;
	while (y <= HEIGTH)
	{
		x = 0;
		while(x <= WIDTH)
		{
			pixelm(sdl, x, y);
			x++;
		}
		y++;
	}
	sdl->color = WHITE;
}
