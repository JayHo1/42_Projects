#include "computer.h"

// int			check_equ(char *s)
// {
// 	int 	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '0' || s[i] == '-' || s[i] == '+')
// 		{
// 			if (s[i] == '0' && s[i + 1])
// 				return (0);
// 			if ((s[i] == '-' || s[i] == '+') && s[i + 1] != '0')
// 				return (0);
// 			if ((s[i] == '-' || s[i] == '+') && s[i + 1] == '0')
// 			{
// 				if (s[i + 2])
// 					return (0);
// 				else
// 					return (1);
// 			}
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int 	ft_cmp_digit(char c)
{
	if ((c - '0') >= 0 && (c - '9') <= 9)
		return (1);
	return (0);
}

int		check_equ(char *s)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

double		check_string(char *s)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '^')
		{
			if (s[i + 1] != '0' && s[i + 1] != '1' && s[i + 1] != '2')
				ft_error("Warning: Exposant bigger than 2 !");
		}
		i++;
	}
	return (get_number(get_tab_number(s)));
}

// double		check_power(char *s, t_env *e)
// {
// 	int		i;
// 	int		k;
// 	char	**tab_number;
// 	char	*str;

// 	i = 0;
// 	k = 0;
// 	e->tab_position = (int *)malloc(sizeof(int));
// 	while (s[i])
// 	{
// 		if (s[i] == '^')
// 		{
// 			i++;
// 			if (s[i] == '0')
// 			{
// 				e->tab_position[k] = i;
// 				k++;
// 			}
// 		}
// 		i++;
// 	}
// 	e->tab_position[k] = '\0';
// 	// str = delete_power(s, e);
// 	// tab_number = reduce_form(str);

// 	return (get_number(tab_number));
// }

char		**get_tab_number(char *str)
{
	int 	i;
	int		v;
	int		k;
	int 	u;
	char	**tmp;

	i = 0;
	v = 0;
	u = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (check_first_number(str) && i == 0)
		{
			tmp[u] = ft_strsub(str, 0, check_first_number(str));
			u++;
		}
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			k = i;
			while (ft_cmp_digit(str[i]))
			{
				if (str[i + 1] == '.')
					i++;
				i++;
			}
			if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
			{
				v = 1;
				i--;
			}
		}
		if (v == 1)
		{
			tmp[u] = ft_strsub(str, k - 1, i - k + 2);
			u++;
			v = 0;
		}
		i++;
	}
	tmp[u] = NULL;
	return (tmp);
}

int			check_first_number(char *s)
{
	int 	i;

	i = 0;
	while (ft_cmp_digit(s[i]))
	{
		if (s[i + 1] == '.')
			i++;
		i++;
	}
	if (s[i] == '-' || s[i] == '+' || s[i] == '\0')
		return (i);
	return (0);
}

char		*delete_power(char *s, t_env *e)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	i = 0;
	k = 0;
	j = 0;
	str = (char *)malloc(sizeof(char));

	while (e->tab_position[j])
	{
		while (i <= e->tab_position[j])
		{
			if (i <= (e->tab_position[j] - 4))
			{
				str[k] = s[i];
				k++;
			}
			i++;
		}
		j++;
	}
	while (s[i])
	{
		str[k] = s[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

// int			check_degree(char *str, char c)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '^' && (str[i + 1] == c || str[i + 1] == c))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char		*get_p1_string(int *coef)
// {
// 	char	*str_1;

// 	if (coef[1] != 0)
// 	{
// 		if (coef[1] < 0)
// 		{
// 			coef[1] = -coef[1];
// 			if (coef[1] == 1)
// 				str_1 = ft_strjoin("- ", "X^1");
// 			else
// 				str_1 = ft_strjoin(ft_strjoin("+ ", ft_itoa(coef[1])), " * X^1");
// 			printf("%s\n", str_1);
// 		}
// 		else
// 		{
// 			if (coef[1] == 1)
// 				str_1 = ft_strjoin("+ ", "X^1");
// 			else
// 				str_1 = ft_strjoin(ft_strjoin("+ ", ft_itoa(coef[1])), " * X^1");
// 			printf("%s\n", str_1);
// 		}
// 		return (str_1);
// 	}
// 	else
// 		return (NULL);
