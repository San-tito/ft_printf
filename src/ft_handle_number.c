/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/23 01:50:57 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int value, const char *digits)
{
	unsigned int	base;
	int				len;
	unsigned int	temp;
	char			*str;

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

void	ft_handle_decimal(char **str, va_list arg, int *count)
{
	long	decimal;
	char	*string;

	decimal = va_arg(arg, int);
	string = ft_itoa(decimal);
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, string, count);
}

void	ft_handle_udecimal(char **str, va_list arg, int *count)
{
	unsigned int	udecimal;
	char			*string;

	udecimal = va_arg(arg, unsigned int);
	string = ft_utoa(udecimal, "0123456789");
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, string, count);
}
