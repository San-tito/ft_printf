/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:35 by sguzman           #+#    #+#             */
/*   Updated: 2024/06/19 20:57:46 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(int fd, char *str, int count)
{
	int	bytes_written;

	bytes_written = write(fd, str, count);
	ft_free(1, &str);
	return (bytes_written);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_calloc(1, sizeof(char *));
	if (!str)
		return (-1);
	ft_handle_format((char *)format, ap, &str, &count);
	if (!str)
		return (-1);
	return (ft_putstr(fd, str, count));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vdprintf(fd, format, arg);
	va_end(arg);
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vdprintf(STDOUT, format, arg);
	va_end(arg);
	return (done);
}
