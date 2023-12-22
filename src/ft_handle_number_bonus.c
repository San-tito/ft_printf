/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/22 18:33:48 by sguzman          ###   ########.fr       */
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

	decimal = va_arg(arg, int);
	if (decimal < 0)
		string = ft_utoa(-decimal, "0123456789");
	else
		string = ft_utoa(decimal, "0123456789");
	if (flags.has_precision && !decimal && !flags.precision)
		ft_reduce(&string, flags.precision);
	str_len = ft_strlen(string);
	if (flags.precision && flags.zero_padding)
	{
		flags.right_justified = flags.zero_padding;
		flags.zero_padding = 0;
	}
	while (flags.precision-- > str_len)
		ft_attach_str(&string, ft_strdup("0"));
	if (decimal < 0 || flags.space_before || flags.show_sign)
		str_len++;
	while (flags.zero_padding-- > str_len)
		ft_attach_str(&string, ft_strdup("0"));
	if (decimal < 0)
		ft_attach_str(&string, ft_strdup("-"));
	else if (flags.space_before)
		ft_attach_str(&string, ft_strdup(" "));
	else if (flags.show_sign)
		ft_attach_str(&string, ft_strdup("+"));
	str_len = ft_strlen(string);
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
	if (flags.has_precision && !udecimal && !flags.precision)
		ft_reduce(&string, flags.precision);
	str_len = ft_strlen(string);
	if (flags.precision && flags.zero_padding)
	{
		flags.right_justified = flags.zero_padding;
		flags.zero_padding = 0;
	}
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
