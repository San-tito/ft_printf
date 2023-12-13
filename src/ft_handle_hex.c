/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:31 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/12 15:44:58 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_ptr(char **str, va_list arg, int *count)
{
	size_t	value;
	char	*string;

	value = (size_t)va_arg(arg, void *);
	string = ft_utoa(value, DIGITS_LOWER);
	if (!string)
		return (ft_free(1, str));
	ft_attach_str(&string, ft_strdup("0x"));
	ft_append_str(str, string, count);
}

void	ft_handle_upper_hex(char **str, va_list arg, int *count)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_UPPER);
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, string, count);
}

void	ft_handle_lower_hex(char **str, va_list arg, int *count)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_LOWER);
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, string, count);
}
