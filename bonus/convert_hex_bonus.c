/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:28:18 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:28:18 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	hex_loop(char *str, unsigned int x, int size, int type)
{
	char	*hex;
	char	*hex2;

	hex = ft_strdup("0123456789abcdef");
	hex2 = ft_strdup("0123456789ABCDEF");
	if (x >= 16)
		hex_loop(str, x / 16, size - 1, type);
	if (type == 1)
		str[size] = hex[x % 16];
	else
		str[size] = hex2[x % 16];
	free (hex);
	free (hex2);
}

static void	hex_loop2(char *str, unsigned long p, int size)
{
	char	*hex;

	hex = ft_strdup("0123456789abcdef");
	if (p >= 16)
		hex_loop2(str, p / 16, size - 1);
	str[size] = hex[p % 16];
	free (hex);
}

char	*convert_hex(unsigned int x)
{
	int					size;
	char				*str;
	unsigned int		temp;

	size = 0;
	temp = x;
	while (temp >= 16)
	{
		temp /= 16;
		size++;
	}
	str = (char *) malloc ((sizeof(char) * size) + 2);
	hex_loop(str, x, size, 1);
	str[size + 1] = '\0';
	return (str);
}

char	*convert_hex2(unsigned int x2)
{
	int					size;
	char				*str;
	unsigned int		temp;

	size = 0;
	temp = x2;
	while (temp >= 16)
	{
		temp /= 16;
		size++;
	}
	str = (char *) malloc ((sizeof(char) * size) + 2);
	hex_loop(str, x2, size, 2);
	str[size + 1] = '\0';
	return (str);
}

char	*convert_hex3(unsigned long p)
{
	int					size;
	char				*str;
	unsigned long		temp;

	size = 0;
	temp = p;
	while (temp >= 16)
	{
		temp /= 16;
		size++;
	}
	str = (char *) malloc ((sizeof(char) * size) + 2);
	hex_loop2(str, p, size);
	str[size + 1] = '\0';
	return (str);
}
