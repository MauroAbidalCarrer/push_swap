/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:11:21 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 10:57:47 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include<stdio.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	up_alone(t_stack *s, int index, int show)
{
	int	i;
	int	tmp;

	i = index;
	if (show)
	{
//printf("bringing alone index %d in stack'%c'\n", index, s->name);
		tmp = (index > s->s / 2);
		tmp -= (index <= s->s / 2);
		while (i)
		{
//printf("i = %d, tmp = %d\n", i, tmp);
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

int	bring_along(t_stack **stacks, int *indices, void (*f)(t_stack *a, t_stack *b), int show)
{
	int	clos;//closest
	int	fur;//further
	int	ops;
	int	indexs[2];

	indexs[0] = indices[0];
	indexs[1] = indices[1];
	clos = ((stacks[0]->s - indexs[0]) > (stacks[1]->s - indexs[1]));
	if (f == &rotate_all)
		clos = indexs[0] > indexs[1];
	fur = 1 - clos;
	ops = stacks[clos]->s - indexs[clos];
	if (f == &rotate_all)
		ops = indexs[clos];
	for (int i = 0; i < ops && show; i++)
		(*f)(stacks[0], stacks[1]);
	if (f == &rotate_all)
		indexs[fur] -= indexs[clos];
	else
		indexs[fur] = (indexs[fur] + ops) % stacks[fur]->s;
/*
	if (f == &rotate_all)
		printf("along rotate, ");
	else
		printf("along rev, ");
*/
int	oui = up_alone(stacks[fur], indexs[fur], show);
//printf("ops = %d, indexs[fur] = %d, upalone(fur) = %d\n", ops, indexs[fur], oui);
	return (ops + oui);
}

int	bring_up(t_stack *a, t_stack *b, int *indices, int show)
{
	t_stack *stacks[2];
	int	res[3];//0 = both rotate, 1 = both rev_rotate, 2 = seperate way
	
	stacks[0] = a;
	stacks[1] = b;
//printf("measurnig min nb ops for %d and %d\n", indices[0], indices[1]);
	res[0] = bring_along(stacks, indices, &rotate_all, 0);
	res[1] = bring_along(stacks, indices, &rev_all, 0);
	res[2] = up_alone(a, indices[0], 0) + up_alone(b, indices[1], 0);
//printf("along rotate = %d, along rev = %d, alone = %d\n", res[0], res[1], res[2]);
	if (res[0] < res[1] && res[0] < res[2])
	{
//printf("choosing along rotate\n\n");
		return (bring_along(stacks, indices, &rotate_all, show));
	}
	if (res[1] < res[0] && res[1] < res[2])
{
//printf("choosing along rev\n\n");
		return (bring_along(stacks, indices, &rev_all, show));
}
//printf("choosing up alone\n\n");
	return (up_alone(a, indices[0], show) + up_alone(b, indices[1], show));
}
