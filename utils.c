/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:09:19 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/25 17:03:23 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

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
	while (s.s-- >= 2)
	{
		if (s.v[s.s] > s.v[s.s - 1])
			return (0);
	}
	return (1);
}

void	sam_eye_sort(t_stack *a, t_stack *b)
{
	int	to_send;
	int	max;

	max = a->s - 1;
	to_send = 0;
	while (!is_sorted(*a))
	{
//printf("av->[0] = %d, av->[1] = %d, max = %d\n", a->v[0], a->v[1], max);
		if (a->v[0] > a->v[1] && a->v[0] != max && a->v[1] != max)
			swap(a, "sa\n");
		else if (a->v[0] == to_send)
		{
			to_send++;
			push(a, b, "pb\n");
		}
		else
			rotate(a, "ra\n");
	}
	push_all(b, a, "pa\n");
}
