/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s </var/mail/rkenji-s>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:30:06 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/09/09 20:30:09 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_count(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	my_loop(char *str, int n, int count)
{
	if (n >= 10 || n <= -10)
		my_loop(str, n / 10, count - 1);
	if (n <= 0)
		str[count] = ((n % 10) * -1) + 48;
	else
		str[count] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = my_count(n);
	str = (char *) malloc (sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	count--;
	my_loop(str, n, count);
	str[count + 1] = '\0';
	return (str);
}
