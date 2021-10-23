/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:28:07 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:28:07 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	my_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	my_loop(char *str, unsigned int n, unsigned int count)
{
	if (n >= 10)
		my_loop(str, n / 10, count - 1);
	str[count] = (n % 10) + 48;
}

char	*ft_utoa(unsigned int n)
{
	char				*str;
	unsigned int		count;

	count = my_count(n);
	str = (char *) malloc (sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	count--;
	my_loop(str, n, count);
	str[count + 1] = '\0';
	return (str);
}
