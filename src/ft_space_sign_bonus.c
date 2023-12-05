/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_sign_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:17:20 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/05 17:21:06 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagger_space(t_flags *flags, int width)
{
	(*flags).space_before += width;
}

void	ft_flagger_sign(t_flags *flags, int width)
{
	(*flags).show_sign += width;
}
