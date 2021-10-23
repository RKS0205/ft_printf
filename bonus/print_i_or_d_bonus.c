/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_or_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:28:01 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:28:01 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*conditions_1(t_flags *info, char *str, char *temp, int i)
{
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
	if (i >= 0 && info->space == 1 && info->plus == 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
	return (str);
}

static void	conditions_2(t_flags *info, char *str, int i)
{
	if (info->plus == 1 && i >= 0)
		write (1, "+", 1);
	if (i < 0)
		write (1, "-", 1);
	if (i < 0 || info->plus != 0)
	{
		info->width--;
		info->size++;
	}
	ft_putstr_fd(str, 1);
	info->width -= ft_strlen(str);
	info->size += ft_strlen(str);
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
}

static void	conditions_3(t_flags *info, char *str, int i)
{
	info->width -= ft_strlen(str);
	if (i < 0 || info->plus != 0)
	{
		info->width--;
		info->size++;
	}
	while ((info->width > 0 && info->zero == 0)
		|| (info->width > 0 && info->zero == 1 && info->precision != 0))
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
	if (info->plus == 1 && i >= 0)
		write (1, "+", 1);
	if (i < 0)
		write (1, "-", 1);
	while (info->width > 0 && info->zero == 1)
	{
		write (1, "0", 1);
		info->width--;
		info->size++;
	}
	ft_putstr_fd(str, 1);
	info->size += ft_strlen(str);
}

static void	conditions_4(t_flags *info, char *str, int i)
{
	if (info->plus == 1 && i >= 0)
	{
		write (1, "+", 1);
		info->size++;
	}
	if (i < 0)
	{
		write (1, "-", 1);
		info->size++;
	}
	ft_putstr_fd(str, 1);
	info->size += ft_strlen(str);
}

int	print_i_or_d(t_flags *info)
{
	int		i;
	char	*str;
	char	*temp;

	i = va_arg (info->arg, int);
	temp = ft_itoa(i);
	str = ft_strtrim(temp, "-+");
	free (temp);
	if (info->precision == 0 && info->point != 0 && i == 0)
	{
		info->size = info->width;
		while (info->width-- > 0)
			write (1, " ", 1);
		free (str);
		return (info->size);
	}
	str = conditions_1(info, str, temp, i);
	if (info->width != 0 && info->minus == 1)
		conditions_2(info, str, i);
	else if (info->width != 0 && info->minus == 0)
		conditions_3(info, str, i);
	else
		conditions_4(info, str, i);
	free (str);
	return (info->size);
}
