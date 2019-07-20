/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:44:25 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/22 16:54:18 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;
	size_t	b;

	if (s && f)
	{
		i = -1;
		b = ft_strlen(s);
		if (!(new = ft_strnew(b)))
			return (NULL);
		while (s[++i])
			new[i] = f(s[i]);
		return (new);
	}
	return (NULL);
}
