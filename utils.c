/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:09:19 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/25 19:21:07 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

#include <stdio.h>


void	print_stack(t_stack s, char name)
{
	printf("stack '%c', size = %d\n", name, s.s);
	for (int i = 0; i < s.s; i++)
		printf("%c.v[%d] = %d\n", name, i, s.v[i]);
}

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

	i = -1;
	while (++i < s.s - 1)
	{
		if (s.v[i] > s.v[i + 1])
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
//printf("is_sorted(a) = %d, before push all\n", is_sorted(*a));
//print_stack(*a, 'a');
//printf("is_sorted(b) = %d, before push all\n", is_sorted(*b));
	push_all(b, a, "pa\n");
//printf("done sotring\n");
//printf("is_sorted(a) = %d\n", is_sorted(*a));
//print_stack(*a, 'a');
}
