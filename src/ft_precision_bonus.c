/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:14:59 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/05 17:21:30 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagger_precision(t_flags *flags, int precision)
{
	(*flags).has_precision += precision;
}

void	ft_flagger_form(t_flags *flags, int precision)
{
	(*flags).alternative_form += precision;
}
