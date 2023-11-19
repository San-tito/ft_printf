/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/19 19:14:32 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(char **str, va_list arg, int *count)
{
	ft_append_char(str, va_arg(arg, int), count);
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

void	*ft_init_conversion_handlers(void)
{
	void	(**handlers)(char **, va_list, int *);

	handlers = ft_calloc(2, sizeof(void (*)(char **, va_list, int *)));
	if (!handlers)
		return (NULL);
	*handlers = &ft_handle_char;
	*(handlers + 1) = &ft_handle_string;
	return ((void *)handlers);
}

void	ft_handle_format(char *format, va_list arg, char **str, int *count)
{
	int		specifier;
	void	(**handlers)(char **, va_list, int *);

	handlers = ft_init_conversion_handlers();
	if (!handlers)
		return (ft_free(1, (void **)str));
	while (*format)
	{
		if (*format == '%')
		{
			specifier = ft_find_index(CONVERSIONS, *++format);
			if (specifier != -1)
				(*(handlers + specifier))(str, arg, count);
		}
		else
			ft_append_char(str, *format, count);
		if (!str)
			return (ft_free(1, (void **)handlers));
		format++;
	}
	ft_free(1, &handlers);
}
