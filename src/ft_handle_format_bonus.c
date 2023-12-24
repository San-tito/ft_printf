/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/24 12:55:38 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_extract_precision(char **format, t_flags *flags,
		void (**flaggers)(t_flags *, int))
{
	int	precision;

	if (**format == '.')
	{
		(*format)++;
		precision = 0;
		if (ft_isdigit(**format))
		{
			precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		(*(flaggers + 2))(flags, precision);
	}
}

void	ft_extract_flags(char **format, t_flags *flags,
		void (**flaggers)(t_flags *, int))
{
	int	flag;
	int	width;

	*flags = (t_flags){};
	flag = ft_find_index(FLAGS, *++(*format));
	while (**format && is_flag(flag))
	{
		(*(flaggers + flag))(flags, 1);
		flag = ft_find_index(FLAGS, *++(*format));
	}
	width = 0;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	(*(flaggers + 6))(flags, width);
	ft_extract_precision(format, flags, flaggers);
}

void	*ft_init_modification_flaggers(void)
{
	void	(**flaggers)(t_flags *, int);

	flaggers = ft_calloc(7, sizeof(void (*)(t_flags *, int)));
	if (!flaggers)
		return (NULL);
	*flaggers = &ft_flagger_left;
	*(flaggers + 1) = &ft_flagger_zero;
	*(flaggers + 2) = &ft_flagger_precision;
	*(flaggers + 3) = &ft_flagger_form;
	*(flaggers + 4) = &ft_flagger_space;
	*(flaggers + 5) = &ft_flagger_sign;
	*(flaggers + 6) = &ft_flagger_field;
	return ((void *)flaggers);
}

void	*ft_init_conversion_handlers(void)
{
	void	(**handlers)(char **, va_list, int *, t_flags);

	handlers = ft_calloc(8, sizeof(void (*)(char **, va_list, int *, t_flags)));
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
	void	(**handlers)(char **, va_list, int *, t_flags);
	void	(**flaggers)(t_flags *, int);
	t_flags	flags;

	handlers = ft_init_conversion_handlers();
	flaggers = ft_init_modification_flaggers();
	if (!handlers || !flaggers)
		return (ft_free(3, str, &handlers, &flaggers));
	while (*format && str)
	{
		if (*format == '%')
		{
			ft_extract_flags(&format, &flags, flaggers);
			specifier = ft_find_index(CONVERSIONS, *format);
			if (specifier != -1)
				(*(handlers + specifier))(str, arg, count, flags);
			else
				ft_handle_perc(str, *format, count, flags);
		}
		else
			ft_append_char(str, *format, count);
		format++;
	}
	ft_free(2, &handlers, &flaggers);
}
