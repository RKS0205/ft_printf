/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:30:41 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/09 20:30:43 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*a;
	int		b;
	int		count;

	count = 0;
	while (s[count] != '\0')
		count++;
	a = (char *) malloc((count + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	b = 0;
	while (s[b] != '\0')
	{
		a[b] = s[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}
