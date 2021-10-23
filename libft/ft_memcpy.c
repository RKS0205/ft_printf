/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:23:50 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/09 20:23:53 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*a;
	char	*b;

	if (dest == NULL && src == NULL)
		return (NULL);
	a = (char *)dest;
	b = (char *)src;
	count = 0;
	while (count < n)
	{
		a[count] = b[count];
		count++;
	}
	return (dest);
}
