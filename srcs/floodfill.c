#include "../include/guimp.h"

Uint32	getpixel(t_sdl *sdl, int x, int y)
{
	Uint8 *p = (Uint8 *)sdl->ren->pixels + y * sdl->ren->pitch + x * 4;
	return *(Uint32 *)p;
}

void	floodfill(t_sdl *sdl, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	if (getpixel(sdl, x, y) == sdl->color)
		return ;
	if (getpixel(sdl, x, y) == sdl->colortemp)
	{
		pixelm(sdl, x, y);
		floodfill(sdl, x + 1, y);
		floodfill(sdl, x, y + 1);
		floodfill(sdl, x - 1, y);
		floodfill(sdl, x, y - 1);
	}
}

void	floodfills(t_sdl *sdl, int x1, int x2, int y) // recursive scanline
{
	int xl, xr;
	if ((y < 0 || y >= HEIGTH) || (getpixel(sdl, x2, y) == sdl->color))
		return ;
	xl = x1;
	ft_putchar('a');
	while (xl >= 0)
	{
	ft_putchar('b');
		if (getpixel(sdl, xl, y) != sdl->colortemp)
			break;
	ft_putchar('c');
		pixelm(sdl, xl, y);
		xl--;
	}
	if (xl < x1)
	{
	ft_putchar('d');
		floodfills(sdl, xl, x1, y - 1);
	ft_putchar('e');
		floodfills(sdl, xl, x1, y + 1);
	ft_putchar('f');
		x1++;
	}
	xr = x2;
	ft_putchar('g');
	while (xr <= WIDTH)
	{
	ft_putchar('h');
		if (getpixel(sdl, xr, y) != sdl->colortemp)
			break;
	ft_putchar('i');
		pixelm(sdl, xr, y);
		xr++;
	}
	ft_putchar('j');
	if (xr > x2)
	{
	ft_putchar('k');
		floodfills(sdl, x2, xr, y - 1);
	ft_putchar('l');
		floodfills(sdl, x2, xr, y + 1);
	ft_putchar('m');
		x2--;
	}
	ft_putchar('n');
	xr = x1;
	while (xr <= x2 && xr <= WIDTH)
	{
	ft_putchar('o');
		if (getpixel(sdl, xr, y) == sdl->colortemp)
		{
	ft_putchar('p');
			pixelm(sdl, xr, y);
		}
		else if (x1 < xr)
		{
	ft_putchar('q');
			floodfills(sdl, x1, xr - 1, y - 1);
	ft_putchar('r');
			floodfills(sdl, x1, xr - 1, y + 1);
	ft_putchar('s');
			x1 = xr;
	ft_putchar('t');
			while (xr <= x2 && xr <= WIDTH)
			{
				ft_putchar('u');
				if (getpixel(sdl, xr, y) == sdl->colortemp)
				{
					ft_putchar('v');
					x1 = xr--;
					break;
				}
				xr++;
			}
		}
		xr++;
	}
}
