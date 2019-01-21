/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 17:03:28 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static int	ft_anorm(long double *num, int power)
{
	if (ABS(*num) < 1.0)
	{
		*num = *num * 2.0;
		power--;
	}
	else if (ABS(*num) >= 2.0)
	{
		*num = *num / 2.0;
		power++;
	}
	else
	{
		return (power);
	}
	return (ft_anorm(num, power));
}

static char	*ft_aa(long double num, int acc)
{
	int		power;
	char	*res;
	char	*buf;
	char	*exp;

	power = ft_anorm(&num, 0);
	res = ft_numtohex(num, acc);
	if (power < 0)
		buf = ft_strjoin("p", "-");
	else
		buf = ft_strjoin("p", "+");
	exp = ft_strjoin(buf, ft_itoa_base(ABS(power), 10));
	free(buf);
	res = ft_strjoin(res, exp);
	free(exp);
	return (res);
}

static char	*ft_afloattostr(va_list *ap, t_spec *spec)
{
	char	*res;

	if (spec->size == SIZE_L)
		res = ft_aa(va_arg(*ap, long double), spec->accuracy);
	else
		res = ft_aa(va_arg(*ap, double), spec->accuracy);
	return (res);
}

int			print_afloat(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		side;
	int		tmp;

	side = 0;
	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_afloattostr(ap, spec)) == NULL)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width - 2, side) + 2;
	str = ft_strjoin("0x", res);
	free(res);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
	{
		ft_putchar(' ');
		write(1, str, tmp++);
	}
	else
		write(1, str, tmp);
	free(str);
	*len += tmp;
	return (1);
}

int			print_afloat_upper(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		side;
	int		tmp;

	side = 0;
	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_afloattostr(ap, spec)) == NULL)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width - 2, side) + 2;
	str = ft_strjoin("0x", res);
	free(res);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
	{
		ft_putchar(' ');
		write(1, ft_strupper(str), tmp++);
	}
	else
		write(1, ft_strupper(str), tmp);
	free(str);
	*len += tmp;
	return (1);
}
