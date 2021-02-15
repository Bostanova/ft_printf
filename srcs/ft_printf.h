/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:40:03 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:33:02 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct	s_flags
{
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
}				t_flags;

int				ft_printf(const char *input, ...);
int				istype(int c);
int				isflags(int c);
int				ft_conversions(int c, t_flags flags, va_list ap);
int				print_width(int width, int eliminate, int zero_exist);
int				print_str(char *str, int len);
int				char_handling(char c, t_flags flags);
int				string_handling(char *str, t_flags flags);
int				int_handling(int i, t_flags flags);
int				percent_handling(t_flags flags);
int				hexa_handling(unsigned int num, int height, t_flags flags);
int				uint_handling(unsigned int num, t_flags flags);
int				flag_dot(const char *format, int i, t_flags *flags, va_list ap);
int				ft_putchar(int c);
int				pointer_handling(unsigned long long ptr, t_flags flags);
char			*num_to_hex(unsigned long long value, int count);
char			*ft_unsigned_itoa(unsigned int n);
char			*ft_str_tolower(char *str);
t_flags			flag_minus(t_flags flags);
t_flags			flag_width(va_list ap, t_flags flags);
t_flags			flag_digit(char c, t_flags flags);

#endif
