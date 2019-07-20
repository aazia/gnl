/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:07:06 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/13 18:18:47 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_string;

	if (!(new_string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new_string, size + 1);
	return (new_string);
}
