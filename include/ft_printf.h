/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:43:58 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/19 18:09:46 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define CONVERSIONS "cspdiuxX%"

int		ft_printf(const char *format, ...);
void	ft_handle_conversions(char *format, va_list arg, char **str,
			int *count);
int		find_conversion_index(const char *find, char c);
void	ft_handle_char(char **str, va_list arg, int *count);
void	ft_handle_string(char **str, va_list arg, int *count);
int		ft_find_index(const char *find, char c);
void	*ft_initialize_handlers(void);
void	ft_append_char(char **str, int c, int *count);
void	ft_append_str(char **str, const char *suffix, int *count);
void	ft_free(int n, ...);

#endif
