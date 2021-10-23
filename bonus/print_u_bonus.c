/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:27:41 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:27:41 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	conditions_1(t_flags *info)
{
	info->size = info->width;
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
	}
}

static char	*conditions_2(t_flags *info, char *str)
{
	char	*temp;

	while (info->precision > (int)ft_strlen(str))
	{
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin ("0", temp);
		free (temp);
	}
	return (str);
}

static void	conditions_3(t_flags *info, char *str)
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

static void	conditions_4(t_flags *info, char *str)
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

int	print_u(t_flags *info)
{
	unsigned int		u;
	char				*str;

	u = va_arg (info->arg, unsigned int);
	str = ft_utoa(u);
	if (info->precision == 0 && info->point != 0 && u == 0)
	{
		conditions_1(info);
		free (str);
		return (info->size);
	}
	if (info->precision != 0)
		str = conditions_2(info, str);
	if (info->width != 0 && info->minus == 1)
		conditions_3(info, str);
	else if (info->width != 0 && info->minus == 0)
		conditions_4(info, str);
	else
		ft_putstr_fd(str, 1);
	info->size += ft_strlen(str);
	free (str);
	return (info->size);
}
