/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:28:03 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:28:03 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	conditionals_1(t_flags *info, char c)
{
	write (1, &c, 1);
	info->width--;
	info->size++;
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
}

static void	conditionals_2(t_flags *info, char c)
{
	info->width--;
	while (info->width != 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
	write (1, &c, 1);
	info->size++;
}

int	print_c(t_flags *info)
{
	char	c;

	c = va_arg(info->arg, int);
	if (info->width != 0 && info->minus == 1)
		conditionals_1(info, c);
	else if (info->width != 0 && info->minus == 0)
		conditionals_2(info, c);
	else
	{
		write (1, &c, 1);
		info->size++;
	}
	return (info->size);
}
