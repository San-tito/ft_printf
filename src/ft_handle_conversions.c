/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:12 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/15 20:01:07 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_append_char(char **str, char c)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(*str);
	new_str = ft_calloc(len + 2, sizeof(char));
	if (!new_str)
		return (ft_free(str));
	ft_strlcpy(new_str, *str, len + 1);
	*(new_str + len) = c;
	*(new_str + len + 1) = '\0';
	ft_free(str);
	*str = new_str;
}

void	ft_append_str(char **str, const char *suffix)
{
	size_t	len;
	size_t	suffix_len;
	char	*new_str;

	len = ft_strlen(*str);
	suffix_len = ft_strlen(suffix);
	new_str = ft_calloc(len + suffix_len + 1, sizeof(char));
	if (!new_str)
		return (ft_free(str));
	ft_strlcpy(new_str, *str, len + 1);
	ft_strlcat(new_str, suffix, len + suffix_len + 1);
	ft_free(str);
	*str = new_str;
}

void	ft_handle_conversions(char *format, va_list arg, char **str)
{
	while (*format)
	{
		ft_append_char(str, *format);
		if (!str)
			return ;
		format++;
	}
}
