#include "computer.h"

char		*ft_skip(char *str)
{
	int		i;
	int		k;
	char	*s_nospace;

	i = 0;
	k = 0;
	s_nospace = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
			i++;
		else
		{
			s_nospace[k] = str[i];
			i++;
			k++;
		}
	}
	s_nospace[k] = '\0';
	return (s_nospace);
}

char		**ft_parse(char *s)
{
	int 	i;
	double 	*coef;
	char	**str;
	char	*tmp;

	i = 0;
	str = ft_strsplit(s, '=');
	coef = (double *)malloc(sizeof(int));

	if (check_equ(ft_skip(str[1])))
	{
		coef[i] = get_coefficient(ft_skip(str[0]), '0') + check_string(ft_skip(str[0]));
			i++;
		coef[i] = get_coefficient(ft_skip(str[0]), '1');
			i++;
		coef[i] = get_coefficient(ft_skip(str[0]), '2');
		printf("Reduce form: %s %s %s = 0\n", get_p0(coef), get_p1(coef), get_p2(coef));
	}
	else
	{
		tmp = ft_skip(get_ae(str[1], str[0]));
		coef[i] = get_coefficient(tmp, '0') + check_string(tmp);
			i++;
		coef[i] = get_coefficient(ft_skip(get_ae(str[1], str[0])), '1');
			i++;
		coef[i] = get_coefficient(ft_skip(get_ae(str[1], str[0])), '2');
		printf("Reduce form: %s %s %s = 0\n", get_p0(coef), get_p1(coef), get_p2(coef));
		free(tmp);
	}
	free(coef);
	return (str);
}

char		*get_ae(char *str, char *str1)
{
	int 	i;
	int 	k;
	int 	j;
	char	**tmp;
	char	*final_str;

	i = 0;
	k = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * 100);
	tmp[j] = (char *)malloc(sizeof(char));
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			tmp[j][k] = '\0';
			j++;
			k = 0;
			tmp[j] = (char *)malloc(sizeof(char));
		}
		tmp[j][k] = str[i];
		k++;
		i++;
	}
	if (j == 0)
	{
		j++;
		tmp[j] = NULL;
	}
	final_str = transform_string(switch_string(tmp), str1);
	return (final_str);
}

char		*transform_string(char **tab, char *str)
{
	int 	i;
	char	*final_str;

	i = 0;
	final_str = str;
	while (tab[i])
	{
		final_str = ft_strjoin(final_str, tab[i]);
		i++;
	}
	return (final_str);
}

char		**switch_string(char **s)
{
	int 	i;
	int 	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i][k] == '-')
			s[i][k] = '+';
		else if (s[i][k])
			s[i][k] = '-';
		i++;
	}
	return (s);
}

double		get_coefficient(char *s, char degree)
{
	int 	i;
	int 	u;
	char	**tmp;

	u = 0;
	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	while (s[i])
		i++;
	i = i - 1;
	while (s[i])
	{
		if (s[i] == 'X' && s[i + 2] == degree)
		{
			i--;
			if (s[i] == '+' || s[i] == '-' || i == -1)
			{
				tmp[u] = (char *)malloc(sizeof(char *));
				tmp[u] = (s[i] == '-') ? "- 1": "1";
				u++;
			}
			else
			{
				i--;
				tmp[u] = get_coefficient_number(s, i);
				u++;
			}
		}
		i--;
	}
	tmp[u] = NULL;
	return (get_number(tmp));
}

char 		*get_coefficient_number(char *s, int position)
{
	int 	i;
	int 	k;
	char 	*tmp;

	k = 0;
	i = position;
	while (s[i] && ft_cmp_digit(s[i]))
	{
		if (s[i - 1] == '.')
		{
			i--;
			k++;
		}
		k++;
		i--;
	}
	if (s[i] == '-' || s[i] == '+')
		k++;
	if (i < 0)
		i++;
	tmp = ft_strsub(s, i, k);
	return (tmp);
}
