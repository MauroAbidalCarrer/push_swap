/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:18:50 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 18:52:04 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

	i = 0;
	while (av[i])
	{
		if (!is_num(av[i]))
			return (0);
		nb = mini_atoi(av[i]);
		j = i;
		while (av[++j])
		{
			if (mini_atoi(av[j]) == nb)
				return (0);
		}	
		i++;
	}
	return (1);
}

void	init_stack(t_stack *s, int ac, char **av, char name)
{
	s->name = name;
	s->v = malloc(ac * sizeof(int));
	if (s->v)
	{
		s->s = ac * (av != NULL);
		while (av && ac-- > 0)
			s->v[ac] = mini_atoi(av[ac]);
	}
}

int	init(int ac, char **av, t_stack *a, t_stack *b)
{
	if (ac == 1)
		return (1);
	if (!av_is_valid(av + 1))
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	init_stack(a, ac - 1, av + 1, 'a');
	if (a->v == NULL)
		return(0);
	init_stack(b, ac - 1, NULL, 'b');
	if (b->v == NULL)
	{
		free(a->v);
		return (1);
	}
	return (0);
}
