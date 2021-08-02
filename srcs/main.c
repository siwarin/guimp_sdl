#include "../include/guimp.h"

int             hook_keydown(t_sdl *sdl)
{
        int             y;

        y = 0;
        SDL_FreeSurface(sdl->ren);
        SDL_DestroyWindow(sdl->win);
        SDL_Quit();
        exit(EXIT_SUCCESS);
        return (0);
}

void    ft_init(t_sdl *sdl)
{
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
        {
                ft_putstr(SDL_GetError());
                ft_putstr("\n\n");
        }
        sdl->win = SDL_CreateWindow("Doom-Nukem", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGTH, 0);
        if (!sdl->win)
        {
                ft_putstr(SDL_GetError());
                ft_putstr("\n\n");
        }
        if ((sdl->ren = SDL_GetWindowSurface(sdl->win)) == NULL)
        {
                ft_putstr(SDL_GetError());
                ft_putstr("Surface error.\n");
        }
        sdl->f.step = 0.0;
        sdl->f.current = 0.0;
        sdl->f.delta = 0.0;
        sdl->f.last = 0.0;
        sdl->f.count = 0.0;
	sdl->color = WHITE;
}

void	fill(t_sdl *sdl, int rad)
{
	int	ox;
	int	oy;
	int	d;
	int	status;

	ox = 0;
	oy = rad;
	d = rad - 1;
	status = 0;

	while (oy >= ox)
	{
		pixelm(sdl, sdl->x - oy, sdl->y + ox);
		pixelm(sdl, sdl->x + oy, sdl->y + ox);
		pixelm(sdl, sdl->x - ox, sdl->y + oy);
		pixelm(sdl, sdl->x + ox, sdl->y + oy);
		pixelm(sdl, sdl->x - ox, sdl->y - oy);
		pixelm(sdl, sdl->x + ox, sdl->y - oy);
		pixelm(sdl, sdl->x - oy, sdl->y - ox);
		pixelm(sdl, sdl->x + oy, sdl->y - ox);

		if (d >= 2 * ox)
		{
			d -= 2 * ox + 1;
			ox += 1;
		}
		else if (d < 2 * (rad - oy))
		{
			d += 2 * oy - 1;
			oy -= 1;
		}
		else
		{
			d += 2 * (oy - ox - 1);
			oy -= 1;
			ox += 1;
		}
	}
}

void	cercle(t_sdl *sdl, int rad)
{
	int	dia;
	int	x;
	int	y;
	int	tx;
	int	ty;
	int	error;

	dia = (rad * 2);
	x = (rad - 1);
	y = 0;
	tx = 1;
	ty = 1;
	error = (tx - dia);

	while (x >= y)
	{
		pixelm(sdl, sdl->x + x, sdl->y - y);
		pixelm(sdl, sdl->x + x, sdl->y + y);
		pixelm(sdl, sdl->x - x, sdl->y - y);
		pixelm(sdl, sdl->x - x, sdl->y + y);
		pixelm(sdl, sdl->x + y, sdl->y - x);
		pixelm(sdl, sdl->x + y, sdl->y + x);
		pixelm(sdl, sdl->x - y, sdl->y - x);
		pixelm(sdl, sdl->x - y, sdl->y + x);
		
		if (error <= 0)
      		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - dia);
		}
	}
	fill(sdl, rad);
}

void    main_loop(t_sdl *sdl)
{
        while (1)
        {
                sdl->f.last = sdl->f.current;
                sdl->f.current = SDL_GetTicks();
                sdl->f.delta = sdl->f.current - sdl->f.last;
                sdl->f.count += sdl->f.delta;
                while(SDL_PollEvent(&sdl->e))
                {
                        // changer cette boucle pour les clics souris
                        if (sdl->e.type == SDL_KEYDOWN)
                                hook_keydown(sdl);
			/*if (sdl->e.type == SDL_KEYDOWN)
				keyboard(sdl);
			if (sdl->e.type == SDL_KEYUP)
				keyrelease(sdl);*/
			/*if (sdl->e.type == SDL_MOUSEMOTION && sdl->e.type == SDL_MOUSEBUTTONDOWN)
			{
				sdl->x = sdl->e.motion.x;
				sdl->y = sdl->e.motion.y;
				//pixel(sdl);
			}*/
			if (sdl->e.type == SDL_MOUSEBUTTONDOWN)
			{
				sdl->x = sdl->e.motion.x;
				sdl->y = sdl->e.motion.y;
				fill(sdl, 50);	
			}
				
                }
		/*sdl->x = sdl->e.motion.x;
		sdl->y = sdl->e.motion.y;	
               	pixel(sdl); // Fonction des calculs de dessin à l'écran
                sdl->x += 1;
		pixel(sdl);
		sdl->y += 1;
		pixel(sdl);
		sdl->x -= 1;
		pixel(sdl);*/

		SDL_UpdateWindowSurface(sdl->win); // Mise à jour de l'écran 
                sdl->f.count -= sdl->f.step;
        }
}

int		main(int argc, char **argv)
{
	t_sdl	sdl;

	ft_init(&sdl);
	main_loop(&sdl);
	return (0);
}
