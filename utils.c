/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:09:19 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 15:50:27 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

#include <stdio.h>


void	print_stack(t_stack s)
{
	printf("stack '%c', size = %d\n", s.name, s.s);
	for (int i = 0; i < s.s; i++)
		printf("%c.v[%d] = %d\n", s.name, i, s.v[i]);
	printf("\n");
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

	if (s.name =='a')
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

void	sam_eye_sort(t_stack *a, t_stack *b)
{
	int	to_send;
	int	max;

	max = a->s - 1;
	to_send = 0;
	while (!is_sorted(*a))
	{
		if (a->v[0] > a->v[1] && a->v[0] != max && a->v[1] != max)
			swap(a, 1);
		else if (a->v[0] == to_send)
		{
			to_send++;
			push(a, b);
		}
		else
			rotate(a, 1);
	}
	push_all(b, a);
}

int	f_sup(t_stack a, int val, int tmp)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (++i < a.s)
	{
		if (a.v[i] > val && tmp >= a.v[i])
		{
			tmp = a.v[i];
			index = i;
		}
	}
	return (index);
}

int	should_swap(int tmp, int *tmp_indices, int smallest_ops, int *indices)
{
	int	diff;
	int	tmp_diff;

	if (tmp < smallest_ops)
		return (1);
	if (tmp > smallest_ops)
		return (0);
	diff = indices[0] - indices[1];
	tmp_diff = tmp_indices[0] - tmp_indices[1];
	return (tmp_diff < diff);
}

void	find_vals_to_sort(t_stack *a, t_stack *b, int max, int *indices)
{
	int	i;
	int	smallest_ops;
	int	tmp;
	int	tmp_indices[2];

	i = 0;
	indices[0] = f_sup(*a, b->v[i], max);
	indices[1] = 0;
	smallest_ops = bring_up(a, b, indices, 0);
	while (++i < b->s)
	{
		tmp_indices[0] = f_sup(*a, b->v[i], max);
		tmp_indices[1] = i;
		tmp = bring_up(a, b, tmp_indices, 0);
		if (should_swap(tmp, tmp_indices, smallest_ops, indices))
		{
			smallest_ops = tmp;
			indices[0] = tmp_indices[0];
			indices[1] = tmp_indices[1];
		}
	}
}

void	hugo_sort(t_stack *a, t_stack *b)
{
	int	max;
	int	indices[2];
	void	(*f)(t_stack *s, int show);
	int	medianne;
	int	i;

	max = a->s - 1;
	medianne = max / 2;
	//vider a
	i = 0;
	while (i < medianne)
	{
		if (a->v[0] < medianne)
		{
//printf("pushing %d, medianne = %d\n", a->v[0], medianne);
			push(a, b);
i++;
}
		else
			rotate(a, 1);
	}
	while (a->s != 1)
	{
		if (a->v[0] != max)
			push(a, b);
		else
			rotate(a, 1);
	}
	while (b->s)
	{
		find_vals_to_sort(a, b, max, indices);
		bring_up(a, b, indices, 1);
		push(b, a);
	}
	if (a->v[0] > a->s / 2)
		f = &rotate;
	else
		f = &rev_rotate;
	while (a->v[0])
		(*f)(a, 1);
}
