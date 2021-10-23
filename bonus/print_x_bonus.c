/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:27:48 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:27:48 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	conditionals_1(t_flags *info, char *str)
{
	info->size = info->width;
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
	}
	free (str);
}

static char	*conditionals_2(t_flags *info, char *str, int x)
{
	char	*temp;

	if (info->hashtag == 1 && x != 0)
	{
		write (1, "0x", 2);
		info->width -= 2;
		info->size += 2;
	}
	if (info->precision != 0)
	{
		while (info->precision > (int)ft_strlen(str))
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strjoin ("0", temp);
			free (temp);
		}
	}
	return (str);
}

static void	conditionals_3(t_flags *info, char *str)
{
	ft_putstr_fd(str, 1);
	info->width -= ft_strlen(str);
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
}

static void	conditionals_4(t_flags *info, char *str)
{
	info->width -= ft_strlen(str);
	while ((info->width > 0 && info->zero == 0)
		|| (info->width > 0 && info->zero == 1 && info->point != 0))
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
	while (info->width > 0 && info->zero == 1 && info->point == 0)
	{
		write (1, "0", 1);
		info->width--;
		info->size++;
	}
	ft_putstr_fd(str, 1);
}

int	print_x(t_flags *info)
{
	unsigned int	x;
	char			*str;

	x = va_arg (info->arg, unsigned int);
	str = convert_hex(x);
	if (info->precision == 0 && info->point != 0 && x == 0)
	{
		conditionals_1(info, str);
		return (info->size);
	}
	str = conditionals_2(info, str, x);
	if (info->width != 0 && info->minus == 1)
		conditionals_3(info, str);
	else if (info->width != 0 && info->minus == 0)
		conditionals_4(info, str);
	else
		ft_putstr_fd(str, 1);
	info->size += ft_strlen(str);
	free (str);
	return (info->size);
}
