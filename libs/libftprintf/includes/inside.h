/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 16:29:05 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSIDE_H
# define FT_INSIDE_H

# include <stdarg.h>
# include "libft.h"

# define IS_FLAG(f)	(spec->flags & f)

# define FLAG_MINUS		1
# define FLAG_PLUS		2
# define FLAG_SPACE		4
# define FLAG_OCTOP		8
# define FLAG_ZERO		16

typedef enum	e_sp_size
{
	SIZE_NONE,
	SIZE_hh,
	SIZE_h,
	SIZE_l,
	SIZE_ll,
	SIZE_j,
	SIZE_z,
	SIZE_L
}				t_sp_size;

typedef struct	s_value_types {
	void		*p_value;
	long long	l_value;
	double		d_value;
	long double ld_value;
	ssize_t		z_value;
}				t_value_types;

typedef struct	s_spec {
	char	flags;
	int		width;
	int		accuracy;
	char	size;
}				t_spec;

typedef struct	s_formater {
	char		type_specifier;
	int			(*func)(va_list*, t_spec*, int*);
}				t_formatter;

int				find_specifier(const char ch);
void			parse_spec_body(char *body, va_list *ap, t_spec *spec);
int				is_spec_body_char(char ch);
int				get_flags(char ch, char *flags);
int				get_accuracy(char *body, va_list *ap, int *accuracy);
char			get_size(char *body, char *size);
int				get_width(char *body, va_list *ap, t_spec *spec);

int				write_len(va_list *ap, t_spec *spec, int *len);
int				print_percent(va_list *ap, t_spec *spec, int *len);
int				print_number(va_list *ap, t_spec *spec, int *len);
int				print_long_number(va_list *ap, t_spec *spec, int *len);
int				print_octal(va_list *ap, t_spec *spec, int *len);
int				print_long_octal(va_list *ap, t_spec *spec, int *len);
int				print_unsigned(va_list *ap, t_spec *spec, int *len);
int				print_long_unsigned(va_list *ap, t_spec *spec, int *len);
int				print_hex(va_list *ap, t_spec *spec, int *len);
int				print_hex_upper(va_list *ap, t_spec *spec, int *len);

int				print_float(va_list *ap, t_spec *spec, int *len);
int				print_efloat(va_list *ap, t_spec *spec, int *len);
int				print_efloat_upper(va_list *ap, t_spec *spec, int *len);
int				print_afloat(va_list *ap, t_spec *spec, int *len);
int				print_afloat_upper(va_list *ap, t_spec *spec, int *len);
char			*ft_numtohex(long double num, int acc);
char			*ft_floattostr(va_list *ap, t_spec *spec);
char			*ft_efloattostr(va_list *ap, t_spec *spec);
int				print_gfloat(va_list *ap, t_spec *spec, int *len);
int				print_gfloat_upper(va_list *ap, t_spec *spec, int *len);

int				print_unicode_char(wchar_t ch, t_spec *spec, int *len);
int				print_byte_char(char ch, t_spec *spec, int *len);
int				print_char(va_list *ap, t_spec *spec, int *len);
int				print_long_char(va_list *ap, t_spec *spec, int *len);
int				print_byte_string(char *value, t_spec *spec, int *len);
int				print_string(va_list *ap, t_spec *spec, int *len);
int				print_long_string(va_list *ap, t_spec *spec, int *len);
int				print_pointer(va_list *ap, t_spec *spec, int *len);
int				print_binary(va_list *ap, t_spec *spec, int *len);

char			*pf_uitoa_base(unsigned long long num, int base, int len);
char			*ft_extend_itoa(long long n, int discharges, int need_sign);
int				get_number_width(int number);

size_t			ft_wcsbytes(const wchar_t *s);
wchar_t			*ft_wcscut(wchar_t const *s, size_t len);
int				ft_wcsfixlen(wchar_t **str, wchar_t ch, int width, int side);
void			ft_putwstr(wchar_t const *s);
int				ft_wcs_char_len(wchar_t ch);

#endif
