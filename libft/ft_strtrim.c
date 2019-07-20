/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:37:16 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/20 14:37:22 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	char	*t;

	if (!(s))
		return (NULL);
	j = ft_strlen(s);
	while (ft_isspace(s[j - 1]) == 1)
		j--;
	i = -1;
	while (ft_isspace(s[++i]) == 1)
		j--;
	if (j < 0)
		j = 0;
	if (!(t = ft_strnew(j)))
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		t[i] = *s++;
	t[i] = '\0';
	return (t);
}
