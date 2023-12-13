/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:11:19 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/11 17:56:19 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flagger_left(t_flags *flags, int width)
{
	(*flags).left_justified += width;
}

void	ft_flagger_right(t_flags *flags, int width)
{
	(*flags).right_justified += width;
}

void	ft_flagger_zero(t_flags *flags, int width)
{
	(*flags).zero_padding += width;
}
