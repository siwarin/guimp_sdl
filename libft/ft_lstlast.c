#include "libft.h"

t_liste	*ft_lstlast(t_liste *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
