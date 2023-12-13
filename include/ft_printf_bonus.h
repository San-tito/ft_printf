/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:37:49 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/11 15:43:38 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define CONVERSIONS "cspdiuxX%"

# define DIGITS_UPPER "0123456789ABCDEF"
# define DIGITS_LOWER "0123456789abcdef"

# define FLAGS "-0.# +"

typedef struct s_flags
{
	size_t	left_justified;
	size_t	right_justified;
	size_t	zero_padding;
	size_t	alternative_form;
	size_t	has_precision;
	size_t	space_before;
	size_t	show_sign;
}			t_flags;

/* ************************************************************************** */
/*                                Main Function                               */
/* ************************************************************************** */
int			ft_printf(const char *fmt, ...);

/* ************************************************************************** */
/*                          Format handling functions                         */
/* ************************************************************************** */
void		ft_handle_format(char *format, va_list arg, char **str, int *count);
void		*ft_init_conversion_handlers(void);
void		*ft_init_modification_flaggers(void);
void		ft_extract_flags(char **format, t_flags *flags,
				void (**flaggers)(t_flags *, int));

/* ************************************************************************** */
/*                             Output functions                               */
/* ************************************************************************** */
int			ft_putstr(char *str, int count);

/* ************************************************************************** */
/*                          String manipulation functions                     */
/* ************************************************************************** */
void		ft_append_char(char **str, int c, int *count);
void		ft_append_str(char **str, const char *suffix, int *count);
void		ft_attach_str(char **str, const char *suffix);

/* ************************************************************************** */
/*                        Conversion specifier handling functions             */
/* ************************************************************************** */
void		ft_handle_perc(char **str, int *count, t_flags flags);
void		ft_handle_char(char **str, va_list arg, int *count, t_flags flags);
void		ft_handle_str(char **str, va_list arg, int *count, t_flags flags);
void		ft_handle_ptr(char **str, va_list arg, int *count, t_flags flags);
void		ft_handle_dec(char **str, va_list arg, int *count, t_flags flags);
void		ft_handle_unsigned_dec(char **str, va_list arg, int *count,
				t_flags flags);
void		ft_handle_upper_hex(char **str, va_list arg, int *count,
				t_flags flags);
void		ft_handle_lower_hex(char **str, va_list arg, int *count,
				t_flags flags);

/* ************************************************************************** */
/*                        Conversion modifier handling functions              */
/* ************************************************************************** */
void		ft_flagger_left(t_flags *flags, int width);
void		ft_flagger_zero(t_flags *flags, int width);
void		ft_flagger_precision(t_flags *flags, int precision);
void		ft_flagger_form(t_flags *flags, int precision);
void		ft_flagger_space(t_flags *flags, int width);
void		ft_flagger_sign(t_flags *flags, int width);
void		ft_flagger_right(t_flags *flags, int width);

/* ************************************************************************** */
/*                           Utility functions                                */
/* ************************************************************************** */
int			ft_find_index(const char *find, char c);
void		ft_free(int n, ...);
char		*ft_utoa(size_t value, const char *digits);

#endif