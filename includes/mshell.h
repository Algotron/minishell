/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:15:26 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/25 17:25:13 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELL_H
# define MSHELL_H

# include "../libft/libft.h"

typedef struct s_cmd
{
	char			**argv;
	int				pipe;
	int				redir;
	struct s_cmd	*nxt;
}	t_cmd;


#endif