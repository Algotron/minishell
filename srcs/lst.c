/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:26:55 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/27 13:11:31 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mshell.h"

int		new_elem(t_cmd **cmd_lst)
{
	t_cmd *tmp;

	if (!(tmp = (t_cmd*)malloc(sizeof(t_cmd))))
		return (ALLOC_ERROR);
	lstadd_back(cmd_lst, tmp);
}

t_cmd	*lstlast(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_cmd **alst, t_cmd *new)
{
	if (!new || !alst)
		return ;
	if (!lstlast(*alst))
		*alst = new;
	else
	{
		new->next = NULL;
		lstlast(*alst)->next = new;
	}
}