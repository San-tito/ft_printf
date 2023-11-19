/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:49:27 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/19 19:03:07 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(int n, ...)
{
	va_list	args;
	void	**ptr;

	va_start(args, n);
	while (n--)
	{
		ptr = va_arg(args, void **);
		if (ptr && *ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
	}
	va_end(args);
}

void	ft_append_char(char **str, int c, int *count)
{
	char	*new_str;

	new_str = ft_calloc(*count + 1, sizeof(char));
	if (!new_str)
		return (ft_free(1, (void **)str));
	ft_memcpy(new_str, *str, *count);
	*(new_str + *count) = c;
	(*count)++;
	ft_free(1, (void **)str);
	*str = new_str;
}

void	ft_append_str(char **str, const char *suffix, int *count)
{
	size_t	suffix_len;
	char	*new_str;

	suffix_len = ft_strlen(suffix);
	new_str = ft_calloc(*count + suffix_len, sizeof(char));
	if (!new_str)
		return (ft_free(1, (void **)str));
	ft_memcpy(new_str, *str, *count);
	ft_memcpy(new_str + *count, suffix, suffix_len);
	*count += suffix_len;
	ft_free(1, (void **)str);
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


