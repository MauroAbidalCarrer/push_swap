/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:09:19 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 18:29:32 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	classify(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	while (i < a->s)
	{
		j = 0;
		b->v[i] = 0;
		while (j < a->s)
		{
			if (a->v[j] < a->v[i])
				(b->v[i])++;
			j++;
		}
		i++;
	}
	b->s = 0;
	temp = a->v;
	a->v = b->v;
	b->v = temp;
}

int	is_sorted(t_stack s)
{
	int	i;

	if (s.name == 'a')
	{
		i = -1;
		while (++i < s.s - 1)
		{
			if (s.v[i] > s.v[i + 1])
				return (0);
		}
		return (1);
	}
	else
	{
		i = s.s;
		while (--i > 0)
		{
			if (s.v[i] > s.v[i - 1])
				return (0);
		}
		return (1);
	}
}
