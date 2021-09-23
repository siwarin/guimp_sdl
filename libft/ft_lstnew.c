/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:35:31 by cduverge          #+#    #+#             */
/*   Updated: 2018/11/30 14:54:10 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_liste *ft_lstnew(void *content)
{
	t_liste	*elt;

	if (!(elt = (t_list*)malloc(sizeof(*elt))))
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
