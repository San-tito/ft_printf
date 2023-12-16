/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:14:59 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/16 18:28:03 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flagger_precision(t_flags *flags, int precision)
{
	(*flags).has_precision = 1;
	(*flags).precision += precision;
}

void	ft_flagger_form(t_flags *flags, int precision)
{
	(*flags).alternative_form += precision;
}

void	ft_reduce(char **str, int precision)
{
	char	*new_str;

	if (!*str)
		return ;
	new_str = ft_calloc(precision + 1, sizeof(char));
	if (!new_str)
		return (ft_free(1, str));
	ft_strlcpy(new_str, *str, precision + 1);
	ft_free(1, str);
	*str = new_str;
}
