/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:43:58 by sguzman           #+#    #+#             */
/*   Updated: 2024/06/19 20:59:23 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define CONVERSIONS "cspdiuxX"

# define DIGITS "0123456789"
# define DIGITS_UPPER "0123456789ABCDEF"
# define DIGITS_LOWER "0123456789abcdef"

/* ************************************************************************** */
/*                                Main Function                               */
/* ************************************************************************** */
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);

/* ************************************************************************** */
/*                          Format handling functions                         */
/* ************************************************************************** */
void	ft_handle_format(char *format, va_list arg, char **str, int *count);
void	*ft_init_conversion_handlers(void);

/* ************************************************************************** */
/*                             Output functions                               */
/* ************************************************************************** */
int		ft_putstr(int fd, char *str, int count);

/* ************************************************************************** */
/*                          String manipulation functions                     */
/* ************************************************************************** */
void	ft_append_char(char **str, int c, int *count);
void	ft_append_str(char **str, const char *suffix, int *count);
void	ft_attach_str(char **str, const char *suffix);

/* ************************************************************************** */
/*                        Conversion specifier handling functions             */
/* ************************************************************************** */
void	ft_handle_char(char **str, va_list arg, int *count);
void	ft_handle_str(char **str, va_list arg, int *count);
void	ft_handle_ptr(char **str, va_list arg, int *count);
void	ft_handle_dec(char **str, va_list arg, int *count);
void	ft_handle_unsigned_dec(char **str, va_list arg, int *count);
void	ft_handle_upper_hex(char **str, va_list arg, int *count);
void	ft_handle_lower_hex(char **str, va_list arg, int *count);

/* ************************************************************************** */
/*                           Utility functions                                */
/* ************************************************************************** */
int		ft_find_index(const char *find, char c);
void	ft_free(int n, ...);
char	*ft_utoa(size_t value, const char *digits);

#endif
