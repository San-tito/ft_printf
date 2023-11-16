/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/16 13:37:31 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(char **str, va_list arg)
{
	ft_append_char(str, va_arg(arg, int));
}

void	ft_handle_string(char **str, va_list arg)
{
	char	*string;

	string = va_arg(arg, char *);
	if (string)
		ft_append_str(str, string);
	else
		ft_append_str(str, "(null)");
}

void	*ft_initialize_handlers(void)
{
	void	(**conversions)(char **, va_list);

	conversions = ft_calloc(2, sizeof(void (*)(char **, va_list)));
	if (!conversions)
		return (NULL);
	*conversions = &ft_handle_char;
	*(conversions + 1) = &ft_handle_string;
	return ((void *)conversions);
}

void	ft_handle_conversions(char *format, va_list arg, char **str)
{
	int		specifier;
	void	(**conversions)(char **, va_list);

	conversions = ft_initialize_handlers();
	if (!conversions)
		return (ft_free(str));
	while (*format)
	{
		if (*format == '%')
		{
			specifier = ft_find_index("cspdiuxX%", *++format);
			if (specifier != -1)
				conversions[specifier](str, arg);
		}
		else
			ft_append_char(str, *format);
		if (!str)
			return ;
		format++;
	}
	free(conversions);
}
