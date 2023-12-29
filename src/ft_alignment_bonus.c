/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:11:19 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/29 16:44:58 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flagger_left(t_flags *flags, int active)
{
	(*flags).left_justify = active;
}

void	ft_flagger_zero(t_flags *flags, int active)
{
	(*flags).zero_padding = active;
}

void	ft_flagger_field(t_flags *flags, int width)
{
	(*flags).field_width += width;
}

void	ft_set_field_width(char **str, char c, int *count, t_flags flags)
{
	if (!*str)
		return ;
	if (!flags.left_justify)
		while (flags.field_width-- > 1)
			ft_append_char(str, ' ', count);
	ft_append_char(str, c, count);
	if (flags.left_justify)
		while (flags.field_width-- > 1)
			ft_append_char(str, ' ', count);
}

void	ft_adjust_field_width(char **str, char *string, int *count,
		t_flags flags)
{
	int	field_width;

	if (!*str || !string)
		return (ft_free(2, str, &string));
	field_width = flags.field_width - ft_strlen(string);
	if (!flags.left_justify)
		while (field_width-- > 0)
			ft_append_char(str, ' ', count);
	ft_append_str(str, string, count);
	if (flags.left_justify)
		while (field_width-- > 0)
			ft_append_char(str, ' ', count);
}
