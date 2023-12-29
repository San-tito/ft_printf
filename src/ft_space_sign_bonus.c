/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_sign_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:17:20 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/29 16:40:02 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flagger_space(t_flags *flags, int active)
{
	(*flags).space_before = active;
}

void	ft_flagger_sign(t_flags *flags, int active)
{
	(*flags).show_sign = active;
}

int	is_flag(int flag)
{
	return (flag == 0 || flag == 1 || (flag >= 3 && flag <= 5));
}

void	ft_complete_zero(char **string, t_flags flags)
{
	int	field_width;

	if (!*string)
		return ;
	field_width = flags.precision - ft_strlen(*string);
	if (flags.has_precision)
		while (field_width-- > 0)
			ft_attach_str(string, ft_strdup("0"));
}
