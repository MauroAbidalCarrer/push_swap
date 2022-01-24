/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:19:58 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/24 19:49:09 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

int	mini_atoi(char *str)
{
	long	nb;
	long	sign;

	nb = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	str += (*str == '-');
	while (*str)
		nb = nb * 10 + *(str++) - '0';
	return (nb * sign);
}

int	av_is_valid(char **av)
{
	int	i;
	int	j;
	int	nb;

	//check valid
	i = 0;
	while (av[i])
	{
		if (!is_num(av[i]))
			return (0);
		nb = mini_atoi(av[i]);
		j = i;
		while (av[i][++j])
		{
			if (mini_atoi(av[i][j]) == nb)
				return (0);
		}	
		i++;
	}
	return (1);
}

t_stack	*mk_stack(int ac, char **av)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));	
	if (s == NULL)
		return (NULL);
	s->v = malloc(ac * sizeof(int));
	if (s->v == NULL)
	{
		free(s);
		return (NULL);
	}
	s->s = ac;
	while (ac-- > 0)
		s->v[ac] = mini_atoi(av[ac]);
	return (s);
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1 || !av_is_valid(av))
		return (0);
	a = mk_stack(ac -1, av + 1);
	if (a == NULL)
		return(0);
	b = mk_stack(0, NULL);
	if (b == NULL)
	{
		free(a);
		return (1);
	}
	if (!is_sorted(a))
	{
		if (ac < LIMIT )
			swap_sort(a, b);
		else
			radix_sort(a, b);
	}
	free(a);
	free(b);
}
