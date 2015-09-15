#include "computer.h"

char		*get_p0(double *coef)
{
	char	*str_0;

	if (coef[0] < 0)
		str_0 = ft_strjoin(ft_itoa(coef[0]), " * X^0");
	else
		str_0 = ft_strjoin(ft_itoa(coef[0]), " * X^0");
	return (str_0);
}

char		*get_p1(double *coef)
{
	char	*str_1;

	if (coef[1] < 0)
	{
		coef[1] = -coef[1];
		str_1 = ft_strjoin(ft_strjoin("- ", ft_itoa(coef[1])), " * X^1");
	}
	else
		str_1 = ft_strjoin(ft_strjoin("+ ", ft_itoa(coef[1])), " * X^1");
	return (str_1);
}

char		*get_p2(double *coef)
{
	char	*str_2;

	if (coef[2] < 0)
	{
		coef[2] = -coef[2];
		str_2 = ft_strjoin(ft_strjoin("- ", ft_itoa(coef[2])), " * X^2");
	}
	else
		str_2 = ft_strjoin(ft_strjoin("+ ", ft_itoa(coef[2])), " * X^2");
	return (str_2);
}
