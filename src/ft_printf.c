/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:35 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/16 12:11:48 by sguzman          ###   ########.fr       */
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

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	char	*str;
	int		count;

	str = ft_calloc(1, sizeof(char *));
	if (!str)
		return (-1);
	va_start(arg, fmt);
	ft_handle_conversions((char *)fmt, arg, &str);
	va_end(arg);
	count = ft_putstr(str);
	free(str);
	return (count);
}
