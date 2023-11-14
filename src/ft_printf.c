/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:35 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/14 17:41:38 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		if (ft_putchar(*(str + i++)) < 0)
			return (-1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	char	*str;

	str = ft_calloc(1, sizeof(char *));
	if (!str)
		return (-1);
	va_start(arg, format);
	ft_handle_conversions((char *)format, arg, &str);
	if (!str)
		return (-1);
	va_end(arg);
	return (ft_putstr(str));
}
