/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:49:27 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/28 16:30:19 by sguzman          ###   ########.fr       */
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

	if (!*str)
		return ;
	new_str = ft_calloc(*count + 1, sizeof(char));
	if (!new_str)
		return (ft_free(1, str));
	ft_memcpy(new_str, *str, *count);
	*(new_str + (*count)++) = c;
	ft_free(1, str);
	*str = new_str;
}

void	ft_append_str(char **str, const char *suffix, int *count)
{
	size_t	suffix_len;
	char	*new_str;

	if (!*str || !suffix)
		return (ft_free(2, str, &suffix));
	suffix_len = ft_strlen(suffix);
	new_str = ft_calloc(*count + suffix_len, sizeof(char));
	if (!new_str)
		return (ft_free(2, str, &suffix));
	ft_memcpy(new_str, *str, *count);
	ft_memcpy(new_str + *count, suffix, suffix_len);
	*count += suffix_len;
	ft_free(2, str, &suffix);
	*str = new_str;
}

void	ft_attach_str(char **str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;
	char	*new_str;

	if (!*str || !suffix)
		return (ft_free(2, str, &suffix));
	suffix_len = ft_strlen(suffix);
	str_len = ft_strlen(*str);
	new_str = ft_calloc(str_len + suffix_len + 1, sizeof(char));
	if (!new_str)
		return (ft_free(2, str, &suffix));
	ft_strlcpy(new_str, suffix, suffix_len + 1);
	ft_strlcat(new_str, *str, suffix_len + str_len + 1);
	ft_free(2, str, &suffix);
	*str = new_str;
}

int	ft_find_index(const char *find, char c)
{
	char	*found;

	found = ft_strchr(find, c);
	if (found && c)
		return (found - find);
	else
		return (-1);
}
