/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_conditionals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:03:52 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/14 16:03:52 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i_or_d(va_list arg)
{
	int		i;
	char	*str;
	int		size;

	i = va_arg(arg, int);
	str = ft_itoa(i);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free (str);
	return (size);
}

int	print_p(va_list arg)
{
	unsigned long	p;
	char			*str;
	int				size;

	p = va_arg(arg, unsigned long);
	str = convert_hex3(p);
	write (1, "0x", 2);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str) + 2;
	free (str);
	return (size);
}

int	print_u(va_list arg)
{
	unsigned int	u;
	char			*str;
	int				size;

	u = va_arg(arg, unsigned int);
	str = ft_utoa(u);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}

int	print_x(va_list arg)
{
	unsigned int	x;
	char			*str;
	int				size;

	x = va_arg(arg, unsigned int);
	str = convert_hex(x);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}

int	print_x2(va_list arg)
{
	unsigned int	x2;
	char			*str;
	int				size;

	x2 = va_arg(arg, unsigned int);
	str = convert_hex2(x2);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}
