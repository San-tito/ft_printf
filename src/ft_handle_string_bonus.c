/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:34:49 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/28 19:22:15 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_perc(char **str, char c, int *count, t_flags flags)
{
	ft_set_field_width(str, c, count, flags);
}

void	ft_handle_char(char **str, va_list arg, int *count, t_flags flags)
{
	char	c;

	c = va_arg(arg, int);
	ft_set_field_width(str, c, count, flags);
}

void	ft_handle_str(char **str, va_list arg, int *count, t_flags flags)
{
	char	*string;

	string = va_arg(arg, char *);
	if (!string)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(string);
	if (flags.has_precision)
		ft_reduce(&string, flags.precision);
	ft_adjust_field_width(str, string, count, flags);
}
