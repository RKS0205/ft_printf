/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:47:56 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:53:55 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*conditions_1(t_flags *info, char *s, int free_check)
{
	char	*temp;

	if (free_check == 1)
	{
		temp = s;
		s = ft_substr(s, 0, info->precision);
		free (temp);
	}
	else
		s = ft_substr(s, 0, info->precision);
	return (s);
}

static void	conditions_2(t_flags *info, char *s)
{
	ft_putstr_fd(s, 1);
	info->width -= ft_strlen(s);
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
}

static void	conditions_3(t_flags *info, char *s)
{
	info->width -= ft_strlen(s);
	while (info->width > 0)
	{
		write (1, " ", 1);
		info->width--;
		info->size++;
	}
	ft_putstr_fd(s, 1);
}

int	print_s(t_flags *info)
{
	char	*s;
	int		free_check;

	free_check = 0;
	s = va_arg (info->arg, char *);
	if (!s)
	{
		s = ft_strdup("(null)");
		free_check = 1;
	}
	if (info->point != 0)
		s = conditions_1(info, s, free_check);
	if (info->width != 0 && info->minus == 1)
		conditions_2(info, s);
	else if (info->width != 0 && info->minus == 0)
		conditions_3(info, s);
	else
		ft_putstr_fd(s, 1);
	info->size += ft_strlen(s);
	if (info->point != 0 || free_check == 1)
		free (s);
	return (info->size);
}
