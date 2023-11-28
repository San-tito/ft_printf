/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/27 19:10:15 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagger_minus(t_flags *flags, int width)
{
	(*flags).left_justified += width;
}

void	*ft_init_flaggers(void)
{
	void	(**flaggers)(t_flags *, int);

	flaggers = ft_calloc(8, sizeof(void (*)(char **, va_list, int *)));
	if (!flaggers)
		return (NULL);
	*flaggers = &ft_flagger_minus;
	return ((void *)flaggers);
}

void	*ft_init_conversion_handlers(void)
{
	void	(**handlers)(char **, va_list, int *);

	handlers = ft_calloc(8, sizeof(void (*)(char **, va_list, int *)));
	if (!handlers)
		return (NULL);
	*handlers = &ft_handle_char;
	*(handlers + 1) = &ft_handle_string;
	*(handlers + 2) = &ft_handle_pointer;
	*(handlers + 3) = &ft_handle_decimal;
	*(handlers + 4) = &ft_handle_decimal;
	*(handlers + 5) = &ft_handle_unsigned_decimal;
	*(handlers + 6) = &ft_handle_lower_hex;
	*(handlers + 7) = &ft_handle_upper_hex;
	return ((void *)handlers);
}

void	ft_handle_format(char *format, va_list arg, char **str, int *count)
{
	int		specifier;
	int		flag;
	void	(**handlers)(char **, va_list, int *);
	void	(**flaggers)(t_flags *, int);
	t_flags	flags;

	handlers = ft_init_conversion_handlers();
	flaggers = ft_init_flaggers();
	if (!handlers || !flaggers)
		return (ft_free(3, str, handlers, flaggers));
	while (*format)
	{
		if (*format == '%')
		{
			flag = ft_find_index(FLAGS, *++format);
			if (flag != -1)
				(*(flaggers + flag))(&flags, ft_atoi(format));
			specifier = ft_find_index(CONVERSIONS, *format);
			if (specifier == 8)
				ft_append_char(str, *format, count);
			else if (specifier != -1)
				(*(handlers + specifier))(str, arg, count);
		}
		else
			ft_append_char(str, *format, count);
		if (!str)
			return (ft_free(2, &handlers, &flaggers));
		format++;
	}
	ft_free(2, &handlers, &flaggers);
}