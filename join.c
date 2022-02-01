/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:11:21 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 17:50:38 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (tmp < smallest_ops)
		{
			smallest_ops = tmp;
			indices[0] = tmp_indices[0];
			indices[1] = tmp_indices[1];
		}
	}
}

int	up_alone(t_stack *s, int index, int show)
{
	int	i;
	int	tmp;

	i = index;
	if (show)
	{
		tmp = (index > s->s / 2);
		tmp -= (index <= s->s / 2);
		while (i)
		{
			i = (i + tmp) % s->s;
			if (tmp == -1)
				rotate(s, 1);
			else
				rev_rotate(s, 1);
		}
	}
	if (index <= s->s / 2)
		return (index);
	return (s->s - index);
}

int	bring_along(t_stack **stacks, int *indices, t_rotation_all f, int show)
{
	int	clos;
	int	fur;
	int	ops;
	int	indexs[2];
	int	i;

	indexs[0] = indices[0];
	indexs[1] = indices[1];
	clos = ((stacks[0]->s - indexs[0]) > (stacks[1]->s - indexs[1]));
	if (f == &rotate_all)
		clos = indexs[0] > indexs[1];
	fur = 1 - clos;
	ops = stacks[clos]->s - indexs[clos];
	if (f == &rotate_all)
		ops = indexs[clos];
	i = -1;
	while (++i < ops && show)
		(*f)(stacks[0], stacks[1], 1);
	if (f == &rotate_all)
		indexs[fur] -= indexs[clos];
	else
		indexs[fur] = (indexs[fur] + ops) % stacks[fur]->s;
	return (ops + up_alone(stacks[fur], indexs[fur], show));
}

int	bring_up(t_stack *a, t_stack *b, int *indices, int show)
{
	t_stack	*stacks[2];
	int		res[3];

	stacks[0] = a;
	stacks[1] = b;
	res[0] = bring_along(stacks, indices, &rotate_all, 0);
	res[1] = bring_along(stacks, indices, &rev_all, 0);
	res[2] = up_alone(a, indices[0], 0) + up_alone(b, indices[1], 0);
	if (res[0] < res[1] && res[0] < res[2])
		return (bring_along(stacks, indices, &rotate_all, show));
	if (res[1] < res[0] && res[1] < res[2])
		return (bring_along(stacks, indices, &rev_all, show));
	return (up_alone(a, indices[0], show) + up_alone(b, indices[1], show));
}
