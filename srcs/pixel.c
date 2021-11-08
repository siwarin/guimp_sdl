#include "../include/guimp.h"

void    pixel(t_sdl *sdl) //print pixel en fonction des datas de la struc SDL
{
        if (sdl->x < 0 || sdl->x >= WIDTH || sdl->y < 0 || sdl->y >= HEIGTH)
                return ;
        *((int *)sdl->ren->pixels + (sdl->y * WIDTH + sdl->x)) = sdl->color;
}

void	pixelm(t_sdl *sdl, int x, int y) // print pixel avec des coordonnées données 
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	*((int *)sdl->ren->pixels + (y * WIDTH + x)) = sdl->color;
}

Uint32	getpixel(t_sdl *sdl, int x, int y) //récupération de la couleur du pixel actuel
{
	Uint8 *p = (Uint8 *)sdl->ren->pixels + y * sdl->ren->pitch + x * 4;
	return *(Uint32 *)p;
}