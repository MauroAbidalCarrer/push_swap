/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:19:58 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/26 23:16:08 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


#include<stdio.h>

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

//printf("mini atoi called, str = \"%s\"\n", str);
	nb = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	str += (*str == '-');
	while (*str)
		nb = nb * 10 + *(str++) - '0';
//printf("nb = %ld\n\n", nb * sign);
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
		while (av[++j])
		{
			if (mini_atoi(av[j]) == nb)
				return (0);
		}	
		i++;
	}
	return (1);
}

t_stack	*mk_stack(int ac, char **av, char name)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));	
	if (s == NULL)
		return (NULL);
	s->name = name;
	s->v = malloc(ac * sizeof(int));
	if (s->v == NULL)
	{
		free(s);
		return (NULL);
	}
	s->s = ac;
	while (av && ac-- > 0)
	{
//printf("s->[%d] = %d\n", ac, mini_atoi(av[ac]));
		s->v[ac] = mini_atoi(av[ac]);
	}
//printf("s->s = %d\n", s->s);
	return (s);
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1 || !av_is_valid(av + 1))
		return (0);
	a = mk_stack(ac - 1, av + 1, 'a');
//printf("issorted = %d\n", is_sorted(*a));
//print_stack(*a);
//return (0);
	if (a == NULL)
		return(0);
	b = mk_stack(ac - 1, NULL, 'b');
	if (b == NULL)
	{
		free(a);
		return (1);
	}
//for (int i = 0; i < a->s; i++)
//{printf("a->v[%d] = %d\n", i, a->v[i]);}
	classify(a, b);
//printf("done\n");
	if (!is_sorted(*a))
	{
		if (ac < LIMIT)
			sam_eye_sort(a, b);
		else
			radix_sort(a, b);
	}
	free(a);
	free(b);
}
