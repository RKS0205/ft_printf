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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
char	*convert_hex(unsigned int x);
char	*convert_hex2(unsigned int x2);
char	*convert_hex3(unsigned long p);
char	*ft_utoa(unsigned int n);
int		print_s(va_list arg);
int		print_c(va_list arg);
int		print_i_or_d(va_list arg);
int		print_p(va_list arg);
int		print_u(va_list arg);
int		print_x(va_list arg);
int		print_x2(va_list arg);

#endif