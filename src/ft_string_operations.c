/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:49:27 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/16 13:37:30 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_append_char(char **str, int c)
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

int	ft_find_index(const char *find, char c)
{
	char	*found;

	found = ft_strchr(find, c);
	if (found)
		return (found - find);
	else
		return (-1);
}
