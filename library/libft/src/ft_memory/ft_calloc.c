/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:26:10 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/14 13:12:08 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// size * count still doesn't make sense
void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(size * count);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size * count);
	return ((void *)tmp);
}
