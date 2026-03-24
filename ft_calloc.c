/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:22:28 by rmarin-n          #+#    #+#             */
/*   Updated: 2026/03/24 10:32:20 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		len;
	void	*buf;

	len = num * size;
	buf = malloc(len);
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, num * size);
	return (buf);
}
