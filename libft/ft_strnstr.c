/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:31:46 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/09 20:31:47 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	while (a < len && str[a] != '\0')
	{
		b = 0;
		while (str[a + b] == to_find[b] && a + b < len)
		{
			if (to_find[b + 1] == '\0')
				return ((char *) str + a);
			b++;
		}
		a++;
	}
	return (NULL);
}
