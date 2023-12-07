/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:31 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/07 15:59:18 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_ptr_flags(char **str, va_list arg, int *count, t_flags flags)
{
	size_t	value;
	char	*string;

	value = (size_t)va_arg(arg, void *);
	string = ft_utoa(value, DIGITS_LOWER);
	if (!string)
		return (ft_free(1, str));
	while (flags.right_justified-- > ft_strlen(string) + 2)
		ft_append_char(str, ' ', count);
	ft_append_str(str, ft_strdup("0x"), count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > ft_strlen(string) + 2)
		ft_append_char(str, ' ', count);
}

void	ft_handle_upper_hex_flags(char **str, va_list arg, int *count,
		t_flags flags)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_UPPER);
	if (!string)
		return (ft_free(1, str));
	while (flags.right_justified-- > ft_strlen(string))
		ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > ft_strlen(string))
		ft_append_char(str, ' ', count);
}

void	ft_handle_lower_hex_flags(char **str, va_list arg, int *count,
		t_flags flags)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, DIGITS_LOWER);
	if (!string)
		return (ft_free(1, str));
	while (flags.right_justified-- > ft_strlen(string))
		ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > ft_strlen(string))
		ft_append_char(str, ' ', count);
}
