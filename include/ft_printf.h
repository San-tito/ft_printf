/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:43:58 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/27 16:19:56 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define CONVERSIONS "cspdiuxX%"

# define DIGITS_UPPER "0123456789ABCDEF"
# define DIGITS_LOWER "0123456789abcdef"

// Main printf function
int		ft_printf(const char *fmt, ...);

// Format handling functions
void	ft_handle_format(char *format, va_list arg, char **str, int *count);
void	*ft_init_conversion_handlers(void);

// Output functions
int		ft_putstr(char *str, int count);

// Index finding functions
int		ft_find_index(const char *find, char c);

// String manipulation functions
void	ft_append_char(char **str, int c, int *count);
void	ft_append_str(char **str, const char *suffix, int *count);

// Memory management functions
void	ft_free(int n, ...);

// Conversion specifier handling functions
void	ft_handle_char(char **str, va_list arg, int *count);
void	ft_handle_string(char **str, va_list arg, int *count);
void	ft_handle_pointer(char **str, va_list arg, int *count);
void	ft_handle_decimal(char **str, va_list arg, int *count);
void	ft_handle_unsigned_decimal(char **str, va_list arg, int *count);
void	ft_handle_upper_hex(char **str, va_list arg, int *count);
void	ft_handle_lower_hex(char **str, va_list arg, int *count);

// Utility function to convert an unsigned integer to a string
char	*ft_utoa(size_t value, const char *digits);

#endif
