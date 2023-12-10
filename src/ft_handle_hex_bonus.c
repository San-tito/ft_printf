/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:31 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/10 16:05:57 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_ptr_flags(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	value;
	char	*string;
	size_t	str_len;

	value = (size_t)va_arg(arg, void *);
	string = ft_utoa(value, DIGITS_LOWER);
	if (!string)
		return (ft_free(1, str));
	str_len = ft_strlen(string) + 2;
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	ft_append_str(str, ft_strdup("0x"), count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}

void	ft_handle_upper_hex_flags(char **str, va_list arg, int *count,
		t_flags flags)
{
	size_t	hexa;
	char	*string;
	size_t	str_len;

	str_len = 0;
	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_UPPER);
	if (!string)
		return (ft_free(1, str));
	str_len = ft_strlen(string);
	if (flags.alternative_form)
		str_len += 2;
	while (flags.zero_padding-- > str_len)
		ft_append_char(str, '0', count);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	if (flags.alternative_form)
		ft_append_str(str, ft_strdup("0X"), count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}

void	ft_handle_lower_hex_flags(char **str, va_list arg, int *count,
		t_flags flags)
{
	size_t	hexa;
	char	*string;
	size_t	str_len;

	str_len = 0;
	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_LOWER);
	if (!string)
		return (ft_free(1, str));
	str_len = ft_strlen(string);
	if (flags.alternative_form)
		str_len += 2;
	while (flags.zero_padding-- > str_len)
		ft_append_char(str, '0', count);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	if (flags.alternative_form)
		ft_append_str(str, ft_strdup("0x"), count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}
