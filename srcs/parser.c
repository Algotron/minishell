/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:21:46 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/27 15:33:12 by tkleynts         ###   ########.fr       */
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
	int		j;
	t_mdata *mdata;

	j = 0;
	mdata = get_mdata();
	while (tokens[j])
	{
		if (*tokens[j] == ';')
		{
			if ((j - 1 >= 0 && *tokens[j - 1] == ';') || (*tokens[j + 1] == ';'))
				return (-1); //plus de 1 ; d'affilee
		}

		
	}
 	
}