/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_sign_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:17:20 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/23 10:56:07 by santito          ###   ########.fr       */
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

int	is_activation_flag(int flag)
{
	return (flag == 0 || flag == 1 || (flag >= 3 && flag <= 5));
}
