/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <bminner@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:56:59 by bminner           #+#    #+#             */
/*   Updated: 2020/12/02 13:56:35 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char		*take_token(char *s, int i, int cas, int *j)
{
	char *dest;

	if (cas == 2)
	{
		*j += 3;
		if (!(dest = (char*)malloc(sizeof(char) * 3)))
			return (0);
		dest = ">>";
		dest[2] = '\0';
		return (dest);
	}
	else if (cas == 1)
	{
		*j += 2;
		if (!(dest = (char*)malloc(sizeof(char) * 2)))
			return (0);
		dest[0] = s[i];
		dest[1] = '\0';
		return (dest);
	}
	return (0);
}

int			iscase(char *string, int i)
{
	if (string[i] == ';')
		return (1);
	if (string[i] == '|')
		return (1);
	if (string[i] == '<')
		return (1);
	if (string[i] == '>' && string[i + 1] != '>')
		return (1);
	if (string[i] == '>' && string[i + 1] == '>')
		return (2);
	return (0);
}

char		*ft_rempli(char *s, int *i)
{
	int		j;
	char	*dest;
	int		n;
	int		cas;

	n = 0;
	j = *i;
	if (iscase(s, j) > 0)
		return(take_token(s, j, iscase(s, j), i));
	while (!iscase(s, j) && s[j])
		j++;
	if (s[j] && iscase(s, j) > 0)
	{
		cas = 1;
		j--;
	}
	if (!(dest = (char*)malloc(sizeof(char) * (j - *i))))
		return (0);
	while (*i < j)
	{
		dest[n++] = s[*i];
		(*i)++;
	}
	if (cas == 1)
		(*i)++;
	return (dest);
}

int			count(char *string)
{
	int n;
	int i;

	n = 0;
	i = -1;
	while (string[++i] != '\0')
	{
		if (string[i] == ';')
			n++;
		if (string[i] == '|')
			n++;
		if (string[i] == '<')
			n++;
		if (string[i + 1] && string[i] == '>' && string[i + 1] != '>')
			n++;
		if (string[i + 1] && string[i] == '>' && string[i + 1] == '>')
		{
			i++;
			n++;
		}
	}
	if (n == 0)
		return (1);
	else
		return (n);	
}

char		**ft_lexer(char *string)
{
	char	**ret;
	int 	i;
	int		n;

	if (!string)
		return (0);
	if (!(ret = (char**)malloc(sizeof(char*) * ((count(string) * 2) + 2))))
		return (0);
	i = 0;
	n = 0;
	while (string[i] && i <= ft_strlen(string))
	{
		if (!(ret[n] = ft_rempli(string, &i)))
			return (0);
		n++;
	}
	ret[n] = NULL;
	return (ret);
}

int			main(int argc, char **argv)
{
	int		i;
	char	**dest;

	i = 0;
	if (!(dest = ft_lexer(argv[1])))
	{
		printf("ntm\n");
		return (0);
	}
	(void)argc;
	while (dest[i])
	{
		printf("%s\n", dest[i]);
		i++;
	}
	return (0);
}