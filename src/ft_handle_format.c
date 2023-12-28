/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/28 16:33:56 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_init_conversion_handlers(void)
{
	void	(**handlers)(char **, va_list, int *);

	handlers = ft_calloc(8, sizeof(void (*)(char **, va_list, int *)));
	if (!handlers)
		return (NULL);
	*handlers = &ft_handle_char;
	*(handlers + 1) = &ft_handle_str;
	*(handlers + 2) = &ft_handle_ptr;
	*(handlers + 3) = &ft_handle_dec;
	*(handlers + 4) = &ft_handle_dec;
	*(handlers + 5) = &ft_handle_unsigned_dec;
	*(handlers + 6) = &ft_handle_lower_hex;
	*(handlers + 7) = &ft_handle_upper_hex;
	return ((void *)handlers);
}

void	ft_handle_format(char *format, va_list arg, char **str, int *count)
{
	int		specifier;
	void	(**handlers)(char **, va_list, int *);

	handlers = ft_init_conversion_handlers();
	if (!handlers)
		return (ft_free(1, str));
	while (*format && str)
	{
		if (*format == '%')
		{
			specifier = ft_find_index(CONVERSIONS, *++format);
			if (!*format)
				break ;
			if (specifier != -1)
				(*(handlers + specifier))(str, arg, count);
			else
				ft_append_char(str, *format, count);
		}
		else
			ft_append_char(str, *format, count);
		format++;
	}
	ft_free(1, &handlers);
}
