#include "../include/guimp.h"

void    pixel(t_sdl *sdl)
{
        if (sdl->x < 0 || sdl->x >= WIDTH || sdl->y < 0 || sdl->y >= HEIGTH)
                return ;
        *((int *)sdl->ren->pixels + (sdl->y * WIDTH + sdl->x)) = sdl->color;
}

void	pixelm(t_sdl *sdl, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	*((int *)sdl->ren->pixels + (y * WIDTH + x)) = sdl->color;
}
