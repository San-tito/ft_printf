/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/14 19:53:10 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_utoa(size_t value, const char *digits)
{
	size_t	base;
	int		len;
	size_t	temp;
	char	*str;

	base = ft_strlen(digits);
	len = 1;
	temp = value;
	while (temp >= base)
	{
		temp /= base;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len)
	{
		*(str + --len) = *(digits + (value % base));
		value /= base;
	}
	return (str);
}

void	ft_handle_dec(char **str, va_list arg, int *count, t_flags flags)
{
	long	decimal;
	char	*string;
	size_t	str_len;
	size_t	precision;

	str_len = 0;
	decimal = va_arg(arg, int);
	if (decimal < 0)
	{
		decimal = -decimal;
		ft_append_char(str, '-', count);
		str_len++;
	}
	else if (flags.space_before)
		ft_append_char(str, ' ', count);
	else if (flags.show_sign)
		ft_append_char(str, '+', count);
	string = ft_utoa(decimal, "0123456789");
	precision = ft_strlen(string);
	str_len += precision;
	while (flags.precision-- > precision)
		ft_attach_str(&string, ft_strdup("0"));
	while (flags.zero_padding-- > str_len)
		ft_append_char(str, '0', count);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}

void	ft_handle_unsigned_dec(char **str, va_list arg, int *count,
		t_flags flags)
{
	size_t	udecimal;
	char	*string;
	size_t	str_len;

	udecimal = va_arg(arg, unsigned int);
	string = ft_utoa(udecimal, "0123456789");
	str_len = ft_strlen(string);
	while (flags.precision-- > str_len)
		ft_attach_str(&string, ft_strdup("0"));
	str_len = ft_strlen(string);
	while (flags.zero_padding-- > str_len)
		ft_append_char(str, '0', count);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}
