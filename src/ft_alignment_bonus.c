/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:11:19 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/23 10:56:28 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flagger_left(t_flags *flags, int active)
{
	(*flags).left_justified = active;
}

void	ft_flagger_zero(t_flags *flags, int active)
{
	(*flags).zero_padding = active;
}

void	ft_flagger_field(t_flags *flags, int width)
{
	(*flags).field_width += width;
}
