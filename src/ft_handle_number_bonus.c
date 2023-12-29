/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/29 16:41:20 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_put_preffix(char **string, t_flags flags, int decimal)
{
	if (decimal < 0)
		ft_attach_str(string, ft_strdup("-"));
	else if (flags.show_sign)
		ft_attach_str(string, ft_strdup("+"));
	else if (flags.space_before)
		ft_attach_str(string, ft_strdup(" "));
}

static void	ft_zero_pad(char **string, t_flags flags, int decimal)
{
	int		field_width;
	size_t	len;

	if (!*string)
		return ;
	len = ft_strlen(*string);
	if (decimal < 0 || flags.space_before || flags.show_sign)
		len++;
	field_width = flags.field_width - len;
	if (flags.zero_padding)
		while (field_width-- > 0)
			ft_attach_str(string, ft_strdup("0"));
}

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

	decimal = va_arg(arg, int);
	if (decimal < 0)
		string = ft_utoa(-decimal, DIGITS);
	else
		string = ft_utoa(decimal, DIGITS);
	if (flags.has_precision && !decimal && !flags.precision)
		ft_reduce(&string, flags.precision);
	ft_complete_zero(&string, flags);
	ft_zero_pad(&string, flags, decimal);
	ft_put_preffix(&string, flags, decimal);
	ft_adjust_field_width(str, string, count, flags);
}

void	ft_handle_unsigned_dec(char **str, va_list arg, int *count,
		t_flags flags)
{
	size_t	udecimal;
	char	*string;

	udecimal = va_arg(arg, unsigned int);
	string = ft_utoa(udecimal, DIGITS);
	if (flags.has_precision && !udecimal && !flags.precision)
		ft_reduce(&string, flags.precision);
	ft_complete_zero(&string, flags);
	ft_zero_pad(&string, flags, 1);
	ft_adjust_field_width(str, string, count, flags);
}
