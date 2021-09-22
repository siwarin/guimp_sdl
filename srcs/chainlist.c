#include "../include/guimp.h"

t_list  *lstnew(t_sdl *sdl)
{
	t_list	*elt;

	if (!(elt = (t_list*)malloc(sizeof(*elt))))
		error ("malloc maillon graphique échec");
	elt.n = 0;
    elt.w = 0;
    elt.s = 0;
    elt.e = 0;
    elt.q = sdl->l.q + 1
    elt.x = sdl->x; // probablement pas les coordonnées stockées dans sdl
    elt.y = sdl->y; // elles sont modifiées ici en fonction du noeud
	elt.next = NULL;
	return (elt);
}

void	lstadd(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	lstdelone(t_sdl *sdl, t_list **alst)
{
	if (alst)
	{
        t_list  del = *alst->next;
        *alst->next = sdl->l.next.next;
		free(del);
	}
}

void	ft_lstdel(t_sdl *sdl, t_list **alst)
{
	t_list *last;
	
	while (*alst)
	{
		last = (*alst)->next;
		ft_lstdelone(sdl, alst);
		*alst = last;
	}
}