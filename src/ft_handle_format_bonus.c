/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/10 16:12:32 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_extract_flags(char **format, t_flags *flags,
		void (**flaggers)(t_flags *, int))
{
	int	flag;
	int	width;

	*flags = (t_flags){};
	flag = ft_find_index(FLAGS, *++(*format));
	while (**format && (flag != -1 || ft_isdigit(**format)))
	{
		if (flag != -1)
			(*format)++;
		else
			flag = 6;
		width = 1;
		if (ft_isdigit(**format))
		{
			width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		(*(flaggers + flag))(flags, width);
		flag = ft_find_index(FLAGS, **format);
	}
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
	*(flaggers + 6) = &ft_flagger_right;
	return ((void *)flaggers);
}

void	*ft_init_conversion_handlers(void)
{
	void	(**handlers)(char **, va_list, int *, t_flags);

	handlers = ft_calloc(8, sizeof(void (*)(char **, va_list, int *, t_flags)));
	if (!handlers)
		return (NULL);
	*handlers = &ft_handle_char_flags;
	*(handlers + 1) = &ft_handle_str_flags;
	*(handlers + 2) = &ft_handle_ptr_flags;
	*(handlers + 3) = &ft_handle_dec_flags;
	*(handlers + 4) = &ft_handle_dec_flags;
	*(handlers + 5) = &ft_handle_unsigned_dec_flags;
	*(handlers + 6) = &ft_handle_lower_hex_flags;
	*(handlers + 7) = &ft_handle_upper_hex_flags;
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
			if (specifier == 8)
				ft_handle_perc_flags(str, count, flags);
			else if (specifier != -1)
				(*(handlers + specifier))(str, arg, count, flags);
		}
		else
			ft_append_char(str, *format, count);
		format++;
	}
	ft_free(2, &handlers, &flaggers);
}
