#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <stdio.h>

typedef struct	s_env
{
	int			i;
	int			j;
	int			k;
	int			u;
	int			*tab_position;
	char		**tab_number;

}				t_env;


void			display_pol(int *coef);
void			get_space_sign(int *tab);
char			*get_ae(char *str, char *str1);
char			*transform_string(char **tab, char *str);
char			**switch_string(char **s);
char	 		**ft_parse(char *s);
char			*ft_skip(char *str);
char			*delete_power(char *s, t_env *e);
char			*get_p0(double *coef);
char			*get_p1(double *coef);
char			*get_p2(double *coef);
int				check_equ(char *s);
int 			ft_cmp_digit(char c);
int				check_list(char *s, int count);
int				check_degree(char *str);
void			resolve_first_degree(double a, double b);
void			ft_error(char *s);
float			ft_atof(const char *str);
double			get_coefficient(char *s, char degree);
double			check_string(char *s);
double			get_number(char **tab_int);
double			check_power(char *s, t_env *e);
char			**get_tab_number(char *str);
char 			*get_coefficient_number(char *s, int position);
int				check_first_number(char *s);

#endif
