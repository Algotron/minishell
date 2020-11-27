/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:15:26 by tkleynts          #+#    #+#             */
/*   Updated: 2020/11/27 13:07:48 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELL_H
# define MSHELL_H

# include "../libft/libft.h"

# define ALLOC_ERROR -1
# define OPEN_ERROR -2
# define READ_ERROR -3
# define WRITE_ERROR -4

typedef struct s_cmd
{
	char			**argv;
	int				pipe;
	int				redir;
	struct s_cmd	*next;
}	t_cmd;

typedef struct
{
	struct s_cmd	*cmd_list;
}	t_mdata;


void	lstadd_back(t_cmd **alst, t_cmd *new);

#endif