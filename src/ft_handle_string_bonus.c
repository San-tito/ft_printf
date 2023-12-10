/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:34:49 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/10 16:00:24 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_perc_flags(char **str, int *count, t_flags flags)
{
	char	c;

	c = '%';
	while (flags.right_justified-- > 1)
		ft_append_char(str, ' ', count);
	ft_append_char(str, c, count);
	while (flags.left_justified-- > 1)
		ft_append_char(str, ' ', count);
}

void	ft_handle_char_flags(char **str, va_list arg, int *count, t_flags flags)
{
	char	c;

	c = va_arg(arg, int);
	while (flags.right_justified-- > 1)
		ft_append_char(str, ' ', count);
	ft_append_char(str, c, count);
	while (flags.left_justified-- > 1)
		ft_append_char(str, ' ', count);
}

void	ft_handle_str_flags(char **str, va_list arg, int *count, t_flags flags)
{
	char	*string;
	size_t	str_len;

	string = va_arg(arg, char *);
	if (!string)
		string = "(null)";
	str_len = ft_strlen(string);
	while (flags.right_justified-- > str_len)
		ft_append_char(str, ' ', count);
	ft_append_str(str, ft_strdup(string), count);
	while (flags.left_justified-- > str_len)
		ft_append_char(str, ' ', count);
}
