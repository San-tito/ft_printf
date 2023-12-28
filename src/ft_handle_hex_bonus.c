/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:31 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/28 19:23:02 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_zero_pad(char **string, t_flags flags, size_t hex)
{
	int		field_width;
	size_t	len;

	if (!*string)
		return ;
	len = ft_strlen(*string);
	if (flags.alternative_form && hex)
		len += 2;
	field_width = flags.field_width - len;
	if (flags.zero_padding)
		while (field_width-- > 0)
			ft_attach_str(string, ft_strdup("0"));
}

void	ft_handle_ptr(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	value;
	char	*string;

	value = (size_t)va_arg(arg, void *);
	string = ft_utoa(value, DIGITS_LOWER);
	ft_attach_str(&string, ft_strdup("0x"));
	ft_adjust_field_width(str, string, count, flags);
}

void	ft_handle_upper_hex(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_UPPER);
	if (!hexa && !flags.precision && flags.has_precision)
		ft_reduce(&string, flags.precision);
	ft_complete_zero(&string, flags);
	ft_zero_pad(&string, flags, hexa);
	if (flags.alternative_form && hexa)
		ft_attach_str(&string, ft_strdup("0X"));
	ft_adjust_field_width(str, string, count, flags);
}

void	ft_handle_lower_hex(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_LOWER);
	if (!hexa && !flags.precision && flags.has_precision)
		ft_reduce(&string, flags.precision);
	ft_complete_zero(&string, flags);
	ft_zero_pad(&string, flags, hexa);
	if (flags.alternative_form && hexa)
		ft_attach_str(&string, ft_strdup("0x"));
	ft_adjust_field_width(str, string, count, flags);
}
