/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:43:58 by sguzman           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/15 20:00:41 by sguzman          ###   ########.fr       */
=======
/*   Updated: 2023/11/15 19:47:46 by sguzman          ###   ########.fr       */
>>>>>>> bab74c636893c5fbf90d68db6873d3c2a628affe
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
void	ft_handle_conversions(char *format, va_list arg, char **str);
void	ft_append_char(char **str, char c);
void	ft_append_str(char **str, const char *suffix);

#endif
