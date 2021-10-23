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

#include "ft_printf_bonus.h"

void	initialize_flags(t_flags *info)
{
	info->letter = '\0';
	info->minus = 0;
	info->plus = 0;
	info->point = 0;
	info->precision = 0;
	info->width = 0;
	info->space = 0;
	info->hashtag = 0;
	info->zero = 0;
	info->size = 0;
}

int	get_flags2(const char *str, t_flags *info, int count)
{
	if (str[count] >= '1' && str[count] <= '9')
	{
		info->width = ft_atoi(str + count);
		while (str[count] >= '0' && str[count] <= '9')
			count++;
	}
	if (str[count] == '.')
	{
		count++;
		info->point = 1;
		info->precision = ft_atoi(str + count);
		while (str[count] >= '0' && str[count] <= '9')
			count++;
	}
	return (count);
}

int	get_flags(const char *str, t_flags *info)
{
	int	count;

	count = 0;
	while (str[count] == '-' || str[count] == '+'
		|| str[count] == '0' || str[count] == '#' || str[count] == ' ')
	{
		if (str[count] == '-')
			info->minus = 1;
		if (str[count] == '+')
			info->plus = 1;
		if (str[count] == '0')
			info->zero = 1;
		if (str[count] == '#')
			info->hashtag = 1;
		if (str[count] == ' ')
			info->space = 1;
		count++;
	}
	count = get_flags2(str, info, count);
	info->letter = str[count];
	return (count + 1);
}

int	use_flags(t_flags *info)
{
	int	size;

	size = 1;
	if (info->letter == '%')
		write (1, "%%", 1);
	if (info->letter == 'c')
		size = print_c(info);
	if (info->letter == 's')
		size = print_s(info);
	if (info->letter == 'p')
		size = print_p(info);
	if (info->letter == 'd')
		size = print_i_or_d(info);
	if (info->letter == 'i')
		size = print_i_or_d(info);
	if (info->letter == 'u')
		size = print_u(info);
	if (info->letter == 'x')
		size = print_x(info);
	if (info->letter == 'X')
		size = print_x2(info);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	t_flags	*info;
	int		size;

	count = 0;
	size = 0;
	info = (t_flags *) malloc (sizeof(t_flags));
	if (!info)
		return (-1);
	va_start (info->arg, (char *)str);
	while (str[count] != '\0')
	{
		initialize_flags(info);
		if (str[count] == '%')
		{
			count += get_flags(&str[count + 1], info);
			size += use_flags(info);
		}
		else
			size += write (1, &str[count], 1);
		count++;
	}
	va_end(info->arg);
	free (info);
	return (size);
}
