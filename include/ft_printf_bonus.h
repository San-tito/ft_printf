/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:37:49 by sguzman           #+#    #+#             */
/*   Updated: 2024/06/19 21:01:47 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define CONVERSIONS "cspdiuxX"

# define DIGITS "0123456789"
# define DIGITS_UPPER "0123456789ABCDEF"
# define DIGITS_LOWER "0123456789abcdef"

# define FLAGS "-0.# +"

typedef struct s_flags
{
	int left_justify : 1;
	int zero_padding : 1;
	int alternative_form : 1;
	int space_before : 1;
	int show_sign : 1;
	int has_precision : 1;
	int		precision;
	int		field_width;
}			t_flags;

typedef struct s_context
{
	void	(**handlers)(char **, va_list, int *, t_flags);
	void	(**flaggers)(t_flags *, int);

}			t_context;

/* ************************************************************************** */
/*                                Main Function                               */
/* ************************************************************************** */
int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);

/* ************************************************************************** */
/*                          Format handling functions                         */
/* ************************************************************************** */
void		ft_handle_format(char *format, va_list arg, char **str, int *count);
void		*ft_init_conversion_handlers(void);
void		*ft_init_modification_flaggers(void);
t_context	ft_init_context(void);
void		ft_extract_flags(char **format, t_flags *flags,
				void (**flaggers)(t_flags *, int));
void		ft_extract_precision(char **format, t_flags *flags,
				void (**flaggers)(t_flags *, int));

/* ************************************************************************** */
/*                             Output functions                               */
/* ************************************************************************** */
int			ft_putstr(int fd, char *str, int count);

/* ************************************************************************** */
/*                          String manipulation functions                     */
/* ************************************************************************** */
void		ft_append_char(char **str, int c, int *count);
void		ft_append_str(char **str, const char *suffix, int *count);
void		ft_attach_str(char **str, const char *suffix);
void		ft_reduce(char **str, int reductor);

/* ************************************************************************** */
/*                        Conversion specifier handling functions             */
/* ************************************************************************** */
void		ft_handle_perc(char **str, char c, int *count, t_flags flags);
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
void		ft_flagger_left(t_flags *flags, int active);
void		ft_flagger_zero(t_flags *flags, int active);
void		ft_flagger_precision(t_flags *flags, int precision);
void		ft_flagger_form(t_flags *flags, int active);
void		ft_flagger_space(t_flags *flags, int active);
void		ft_flagger_sign(t_flags *flags, int active);
void		ft_flagger_field(t_flags *flags, int width);

/* ************************************************************************** */
/*                           Flags utility functions                          */
/* ************************************************************************** */
void		ft_adjust_field_width(char **str, char *string, int *count,
				t_flags flags);
void		ft_set_field_width(char **str, char c, int *count, t_flags flags);
void		ft_complete_zero(char **string, t_flags flags);

/* ************************************************************************** */
/*                           Utility functions                                */
/* ************************************************************************** */
int			ft_find_index(const char *find, char c);
void		ft_free(int n, ...);
char		*ft_utoa(size_t value, const char *digits);
int			is_flag(int flag);

#endif
