/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/14 21:03:06 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_append_char(char **dest, char c)
{
	size_t	len;

	len = ft_strlen(*dest);
	*dest = realloc(*dest, len + 2);
	(*dest)[len] = c;
	(*dest)[len + 1] = '\0';
}

void	ft_append_str(char **dest, const char *str)
{
	size_t	len;

	len = ft_strlen(*dest) + ft_strlen(str);
	*dest = realloc(*dest, len + 1);
	ft_strlcat(*dest, str, len);
}

void	ft_handle_conversions(char *format, va_list arg, char **str)
{
	while (*format)
	{
		ft_append_char(str, *format);
		format++;
	}
}
