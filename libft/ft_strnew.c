/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:27:41 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/28 19:41:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*p;

	str = (char*)malloc(size + sizeof(char));
	if (str == NULL)
		return (NULL);
	p = str;
	while (size--)
		*p++ = '\0';
	*p = '\0';
	return (str);
}
