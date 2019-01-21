/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 17:35:31 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static int	ft_enorm(long double *num, int power)
{
	if (ABS(*num) < 1)
	{
		*num = *num * 10.0;
		power--;
	}
	else if (ABS(*num) > 10.0)
	{
		*num = *num * 0.1;
		power++;
	}
	else
	{
		return (power);
	}
	return (ft_enorm(num, power));
}

static char	*ft_ee(long double num, int acc)
{
	int		power;
	char	*res;
	char	*buf;
	char	*exp;

	power = ft_enorm(&num, 0);
	if (power < 0)
		buf = ft_strjoin("e", "-");
	else
		buf = ft_strjoin("e", "+");
	if (ABS(power) < 10)
	{
		exp = ft_strjoin(buf, "0");
	}
	else
	{
		exp = ft_strdup(buf);
	}
	free(buf);
	buf = ft_strjoin(exp, ft_itoa_base(ABS(power), 10));
	res = ft_strjoin(ft_dtoa(num, acc), buf);
	free(buf);
	return (res);
}

char		*ft_efloattostr(va_list *ap, t_spec *spec)
{
	char	*res;

	spec->accuracy = spec->accuracy == -1 ? 6 : spec->accuracy;
	if (spec->size == SIZE_L)
		res = ft_ee(va_arg(*ap, long double), spec->accuracy);
	else
		res = ft_ee(va_arg(*ap, double), spec->accuracy);
	return (res);
}

int			print_efloat(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_efloattostr(ap, spec)) == NULL)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width, side);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
	{
		str = res;
		res = ft_strjoin(" ", res);
		free(str);
		tmp++;
	}
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}

int			print_efloat_upper(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_efloattostr(ap, spec)) == NULL)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width, side);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
	{
		str = res;
		res = ft_strjoin(" ", res);
		free(str);
		tmp++;
	}
	ft_strupper(res);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}
