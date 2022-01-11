#include "../include/guimp.h"

struct		s_list //structure pour floodfill
{
	int q; // compteur
	int	x; // coordonnées graphique du noeud en question
	int y;
	struct s_list *next;
}					*l;

struct s_list  *lstnew(int i, int j) 
{
	struct s_list	*li;
	if (!(li = (struct s_list*)malloc(sizeof(struct s_list))))
		return (NULL);
    li->x = i;
    li->y = j;
	return (li);
}

void	lstadd(int x, int y)
{
	struct s_list *new;
	if (!l)
	{
		l = new;
		return ;
	}
	new = lstnew(x, y);
	new->q = l->q + 1;
	new->next = l;
	l = new;
}

void	lstdelfirst()
{
	struct s_list  *del = l;
    l = l->next;
	l->q = del->q - 1;
	free(del);
}

void	lstdel()
{
	struct s_list *last;	
	while (l != NULL)
	{
		last = l;
		l = l->next;
		free(last);
	}
}

int		verif(int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return (-1);
	return (0);
}

void	floodfill(t_sdl *sdl, int x, int y) // outil pot de peinture (a finir)
{ // faire une fonction pour dessiner rectangle, floodfill plante topscreen et sors des cercles  
	int i;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	if (getpixel(sdl, x, y) == sdl->color)
		return ;
	if (!(l = (struct s_list*)malloc(sizeof(struct s_list))))
		return ;
	l->next = NULL;
	l->q = 0;
	i = 0 ;
	lstadd(x, y);
	pixelm(sdl, x, y);
	SDL_UpdateWindowSurface(sdl->win);
	//chain list
	while (l->q) // le compteur
	{
		if (l->q == 0 && getpixel(sdl, x, y - 1) == sdl->color && getpixel(sdl, x - 1, y) == sdl->color && getpixel(sdl, x, y + 1) == sdl->color && getpixel(sdl, x + 1, y) == sdl->color)
			break ;
		printf("maillon q pré-boucle = %d, x = %d, y = %d\n", l->q, l->x, l->y);
		while (y >= 0 && verif(x, y - 1) == 0) //verif nord
		{
			printf("a maillon q = %d, x = %d, y = %d\n", l->q, x, y);
			if (y <= 0)
			{
				y++;
				break ;
			}
			if (getpixel(sdl, x, y - 1) != sdl->color) //verif couleur pixel actuel
			{
				printf("a maillon print\n");
				y--;
				pixelm(sdl, x, y);
				SDL_UpdateWindowSurface(sdl->win);
				lstadd(x, y);
			}
			if (getpixel(sdl, x, y - 1) == sdl->color || verif(x, y - 1) == -1)
			{
				printf("a break fin\n");
				break ;
			}
		}
		while (x >= 0 && verif(x - 1, y) == 0) // verif ouest
		{
			printf("b maillon q = %d, x = %d, y = %d\n", l->q, l->x, l->y);
			/*if (x <= 0)
			{
				x++;
				break ;
			}*/
			if (getpixel(sdl, x - 1, y) != sdl->color)
			{
				printf("b maillon print\n");
				x--;
				pixelm(sdl, x, y);
				SDL_UpdateWindowSurface(sdl->win);
				lstadd(x, y);
			}
			if (getpixel(sdl, x - 1, y) == sdl->color || verif(x - 1, y) == -1)
			{
				printf("b break fin\n");
				break ;
			}
		}
		while (y <= HEIGTH && verif(x, y + 1) == 0) // verif sud
		{
			printf("c maillon q = %d, x = %d, y = %d\n", l->q, l->x, l->y);
			/*if (y >= HEIGTH)
			{
				y--;
				break ;
			}*/
			if (getpixel(sdl, x, y + 1) != sdl->color)
			{
				printf("c maillon print\n");
				y++;
				pixelm(sdl, x, y);
				SDL_UpdateWindowSurface(sdl->win);
				lstadd(x, y);
			}
			if (getpixel(sdl, x, y + 1) == sdl->color || verif(x, y + 1) == -1)
			{
				printf("c break fin\n");
				break ;
			}
		}
		while (x <= WIDTH && verif(x + 1, y) == 0) // verif est
		{
			printf("d maillon q = %d, x = %d, y = %d\n", l->q, l->x, l->y);
			/*if (x <= WIDTH)
			{
				x--;
				break ;
			}*/
			if (getpixel(sdl, x + 1, y) != sdl->color)
			{
				printf("d maillon print\n");
				x++;
				pixelm(sdl, x, y);
				SDL_UpdateWindowSurface(sdl->win);
				lstadd(x, y);
			}
			if (getpixel(sdl, x + 1, y) == sdl->color || verif(x + 1, y) == -1)
			{
				printf("d break fin\n");
				break ;
			}
		}
		printf("début de free\n");
		while (l != NULL)
		{
			if (l->q == 0 || getpixel(sdl, x, y - 1) != sdl->color || getpixel(sdl, x - 1, y) != sdl->color || getpixel(sdl, l->x, l->y + 1) != sdl->color || getpixel(sdl, l->x + 1, l->y) != sdl->color)
			{
				if (verif(x, y) == -1)
				{
					printf("verif passée\n");
					lstdelfirst();
					x = l->x;
					y = l->y;
				}
				printf("break début free\n");
				break ;
			}
			printf("--e maillon q = %d, x = %d, y = %d--\n", l->q, x, y);
			lstdelfirst();
			x = l->x;
			y = l->y;
			printf("--f maillon q = %d, x = %d, y = %d--\n", l->q, x, y);
			if (l->q == 0 || getpixel(sdl, x, y - 1) != sdl->color || getpixel(sdl, x - 1, y) != sdl->color || getpixel(sdl, x, y + 1) != sdl->color || getpixel(sdl, x + 1, y) != sdl->color)
			{
				printf("break fin de free\n");
				break ;
			}
		}
	}
	if (l != NULL)
	{
		lstdel();
	}
}