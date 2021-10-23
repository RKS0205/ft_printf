/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:28:14 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:28:14 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list arg)
{
	int	c;

	c = va_arg(arg, int);
	write (1, &c, 1);
	return (1);
}

int	print_s(va_list arg)
{
	char	*s;
	int		size;

	s = va_arg(arg, char *);
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	size = ft_strlen(s);
	return (size);
}

int	get_the_letter(char letter, va_list arg)
{
	int	size;

	size = 1;
	if (letter == '%')
		write (1, "%%", 1);
	if (letter == 'c')
		size = print_c(arg);
	if (letter == 's')
		size = print_s(arg);
	if (letter == 'p')
		size = print_p(arg);
	if (letter == 'i' || letter == 'd')
		size = print_i_or_d(arg);
	if (letter == 'u')
		size = print_u(arg);
	if (letter == 'x')
		size = print_x(arg);
	if (letter == 'X')
		size = print_x2(arg);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		size;
	va_list	arg;

	count = 0;
	size = 0;
	va_start (arg, (char *)str);
	while (str[count] != '\0')
	{
		if (str[count] == '%')
		{
			size += get_the_letter(str[count + 1], arg);
			count += 1;
		}
		else
			size += write (1, &str[count], 1);
		count++;
	}
	va_end(arg);
	return (size);
}
