/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:21:46 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/25 18:53:10 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mshell.h"

t_mdata	*get_mdata()
{
	static t_mdata	mdata;
	return (&mdata);
}

void	parser(char **tokens)
{
	int		i;
	int		j;
	t_mdata *mdata;

	j = 0;
	mdata = get_mdata();
	while (tokens[j])
	{
		i = 0;
		while (tokens[j][i])
		{
			if 
		}
		
	}
	
}