/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:31 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/22 13:40:19 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_ptr(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	value;
	char	*string;
	size_t	str_len;

	value = (size_t)va_arg(arg, void *);
	string = ft_utoa(value, DIGITS_LOWER);
	ft_attach_str(&string, ft_strdup("0x"));
	str_len = ft_strlen(string);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}

void	ft_handle_upper_hex(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	hexa;
	char	*string;
	size_t	str_len;

	str_len = 0;
	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_UPPER);
	if (flags.alternative_form && hexa)
		ft_attach_str(&string, ft_strdup("0X"));
	if (flags.has_precision && !hexa && !flags.precision)
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

void	ft_handle_lower_hex(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	hexa;
	char	*string;
	size_t	str_len;

	str_len = 0;
	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_LOWER);
	if (flags.alternative_form && hexa)
		ft_attach_str(&string, ft_strdup("0x"));
	if (flags.has_precision && !hexa && !flags.precision)
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
