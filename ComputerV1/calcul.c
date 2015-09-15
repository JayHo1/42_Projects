#include "computer.h"

float		ft_atof(const char *str)
{
	float	n;
	int		i;
	int		k;
	int		signe;

	i = 0;
	n = 0;
	k = 0;
	signe = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	signe = (str[i] == '-') ? -signe : signe;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i++] - 48);
		if (str[i] == '.')
			k = i++;
	}
	while (k != 0 && str[++k])
		signe = signe * 10;
	return (n / signe);
}

double		get_number(char **tab_int)
{
	double 	a;
	int 	i;

	a = 0;
	i = 0;
	// printf("Waiting for process... \n");
	// sleep(4);
	while (tab_int[i])
	{
		a = a + ft_atof(tab_int[i]);
		i++;
	}
	return (a);
}

void		resolve_first_degree(double a, double b)
{
	if (a != 0 && b == 0)
		printf("The solution is : 0\n");
	if (a == 0 && b != 0)
		printf("Impossible equation !\n");
	if (a != 0 && b != 0)
		printf("The solution is : %g\n", (-b / a));
}

void		resolve_second_degree(double a, double b, double c)
{
	double 	delta;

	delta = b * b - 4 * a * c;
}