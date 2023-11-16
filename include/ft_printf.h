/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:43:58 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/16 13:40:20 by sguzman          ###   ########.fr       */
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
int		find_conversion_index(const char *find, char c);
void	ft_handle_char(char **str, va_list arg);
void	ft_handle_string(char **str, va_list arg);
int		ft_find_index(const char *find, char c);
void	*ft_initialize_handlers(void);
void	ft_append_char(char **str, int c);
void	ft_append_str(char **str, const char *suffix);
void	ft_free(char **str);

#endif
