/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:30:31 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/09 20:30:35 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count;
	char		*str;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = c;
		count++;
	}
	return (str);
}
