/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:38:51 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/12 17:07:42 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = 0;
	while (s1[len])
		++len;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		while (len >= 0)
		{
			str[len] = s1[len];
			len--;
		}
	else
		return (NULL);
	return (str);
}
