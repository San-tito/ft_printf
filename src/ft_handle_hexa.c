/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:31 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/23 02:02:48 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_pointer(char **str, va_list arg, int *count)
{
	size_t	value;
	char	*string;

	value = *(size_t *)va_arg(arg, void *);
	string = ft_utoa(value, "0123456789abcdef");
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, "0x", count);
	if (!str)
		return ;
	ft_append_str(str, string, count);
}

void	ft_handle_uhexa(char **str, va_list arg, int *count)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, "0123456789ABCDEF");
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, string, count);
}

void	ft_handle_lhexa(char **str, va_list arg, int *count)
{
	size_t	hexa;
	char	*string;

	hexa = va_arg(arg, unsigned int);
	string = ft_utoa(hexa, "0123456789abcdef");
	if (!string)
		return (ft_free(1, str));
	ft_append_str(str, string, count);
}
