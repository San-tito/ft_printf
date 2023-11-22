/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:34:49 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/22 19:43:08 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(char **str, va_list arg, int *count)
{
	char	c;

	c = va_arg(arg, int);
	ft_append_char(str, c, count);
}

void	ft_handle_string(char **str, va_list arg, int *count)
{
	char	*string;

	string = va_arg(arg, char *);
	if (string)
		ft_append_str(str, string, count);
	else
		ft_append_str(str, "(null)", count);
}
