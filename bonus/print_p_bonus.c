/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:27:56 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:27:56 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	conditions_1(t_flags *info)
{
	info->width -= 3;
	info->size += 3;
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
	write (1, "0x0", 3);
}

static void	conditions_2(t_flags *info, char *str)
{
	write (1, "0x", 2);
	ft_putstr_fd(str, 1);
	info->width -= (2 + ft_strlen(str));
	info->size += (ft_strlen(str));
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width -= 1;
		info->size++;
	}
}

static void	conditions_3(t_flags *info, char *str)
{
	info->width -= (2 + ft_strlen(str));
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width -= 1;
		info->size++;
	}
	write (1, "0x", 2);
	ft_putstr_fd(str, 1);
	info->size += (ft_strlen(str));
}

static void	conditions_4(t_flags *info, char *str)
{
	write (1, "0x", 2);
	ft_putstr_fd(str, 1);
	info->size += (ft_strlen(str));
}

int	print_p(t_flags *info)
{
	unsigned long	p;
	char			*str;

	p = va_arg (info->arg, unsigned long);
	if (p == 0)
	{
		conditions_1(info);
		return (info->size);
	}
	str = convert_hex3(p);
	if (info->width != 0 && info->minus == 1)
		conditions_2(info, str);
	else if (info->width != 0 && info->minus == 0)
		conditions_3(info, str);
	else
		conditions_4(info, str);
	free (str);
	return (info->size + 2);
}
