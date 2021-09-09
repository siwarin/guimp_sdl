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

void    main_loop(t_sdl *sdl)
{
	int i;

	i = 0;

	while (1)
	{
		sdl->f.last = sdl->f.current;
		sdl->f.current = SDL_GetTicks();
		sdl->f.delta = sdl->f.current - sdl->f.last;
		sdl->f.count += sdl->f.delta;
		while(SDL_PollEvent(&sdl->e))
		{
			switch(sdl->e.type)
			{
				case SDL_KEYDOWN:
					switch(sdl->e.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							hook_keydown(sdl);
							break;
					}

				case SDL_MOUSEMOTION:
					sdl->k.mx = sdl->e.motion.x;
					sdl->k.my = sdl->e.motion.y;
					sdl->k.mxr = sdl->e.motion.xrel;
					sdl->k.myr = sdl->e.motion.yrel;
					break;
				case SDL_MOUSEBUTTONDOWN:
					sdl->x = sdl->k.mx;
					sdl->y = sdl->k.my;
					i = mousemotioncalcul(sdl); //ca doit renvoyer un int
					break;
				case SDL_MOUSEBUTTONUP:
					midPointCircleDrawR(sdl, sdl->k.mx, sdl->k.my, 200); // changer le 200 par le mouvement de la souris
					SDL_UpdateWindowSurface(sdl->win);
				   	break;	
			}

		}
	}
	SDL_UpdateWindowSurface(sdl->win); // Mise à jour de l'écran 
	sdl->f.count -= sdl->f.step;
}

int		main(int argc, char **argv)
{
	t_sdl	sdl;

	ft_init(&sdl);
	main_loop(&sdl);
	return (0);
}
