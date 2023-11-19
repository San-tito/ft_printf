/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:35 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/19 18:15:57 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int count)
{
	int	bytes_written;

	bytes_written = write(STDOUT, str, count);
	ft_free(1, (void **)&str);
	return (bytes_written);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	char	*str;
	int		count;

	count = 0;
	str = ft_calloc(1, sizeof(char *));
	if (!str)
		return (-1);
	va_start(arg, fmt);
	ft_handle_format((char *)fmt, arg, &str, &count);
	va_end(arg);
	return (ft_putstr(str, count));
}
