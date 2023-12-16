/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:34:49 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/16 18:35:19 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_perc(char **str, int *count, t_flags flags)
{
	char	c;

	c = '%';
	while (flags.right_justified-- > 1)
		ft_append_char(str, ' ', count);
	ft_append_char(str, c, count);
	while (flags.left_justified-- > 1)
		ft_append_char(str, ' ', count);
}

void	ft_handle_char(char **str, va_list arg, int *count, t_flags flags)
{
	char	c;

	c = va_arg(arg, int);
	while (flags.right_justified-- > 1)
		ft_append_char(str, ' ', count);
	ft_append_char(str, c, count);
	while (flags.left_justified-- > 1)
		ft_append_char(str, ' ', count);
}

void	ft_handle_str(char **str, va_list arg, int *count, t_flags flags)
{
	char	*string;
	size_t	str_len;

	string = va_arg(arg, char *);
	if (!string)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(string);
	if (flags.has_precision)
		ft_reduce(&string, flags.precision);
	str_len = ft_strlen(string);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}
