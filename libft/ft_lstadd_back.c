#include "libft.h"

void	ft_lstadd_back(t_liste **alst, t_liste *new)
{
	t_liste	*last_elem;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last_elem = ft_lstlast(*alst);
	last_elem->next = new;
}
