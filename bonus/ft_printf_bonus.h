/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:28:10 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/10/10 04:28:10 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	va_list	arg;
	char	letter;
	int		minus;
	int		plus;
	int		point;
	int		precision;
	int		width;
	int		space;
	int		hashtag;
	int		zero;
	int		size;

}	t_flags;

int		ft_printf(const char *str, ...);
int		get_flags(const char *str, t_flags *info);
int		use_flags(t_flags *info);
void	initialize_flags(t_flags *info);
int		print_c(t_flags *info);
int		print_i_or_d(t_flags *info);
int		print_s(t_flags *info);
int		print_u(t_flags *info);
int		print_x(t_flags *info);
int		print_x2(t_flags *info);
int		print_p(t_flags *info);
char	*convert_hex(unsigned int x);
char	*convert_hex2(unsigned int x2);
char	*convert_hex3(unsigned long p);
char	*ft_utoa(unsigned int n);

#endif