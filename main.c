/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:19:58 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 18:52:51 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			push(a, b, 1);
		}
		else
			rotate(a, 1);
	}
	push_all(b, a);
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
	i = 0;
	while (i < medianne)
	{
		if (a->v[0] < medianne)
		{
			push(a, b, 1);
			i++;
		}
		else
			rotate(a, 1);
	}
	while (a->s != 1)
	{
		if (a->v[0] != max)
			push(a, b, 1);
		else
			rotate(a, 1);
	}
	while (b->s)
	{
		find_vals_to_sort(a, b, max, indices);
		bring_up(a, b, indices, 1);
		push(b, a, 1);
	}
	if (a->v[0] > a->s / 2)
		f = &rotate;
	else
		f = &rev_rotate;
	while (a->v[0])
		(*f)(a, 1);
}

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (init(ac, av, &a, &b))
		return (1);
	classify(&a, &b);
	if (!is_sorted(a))
	{
		if (ac < LIMIT)
			sam_eye_sort(&a, &b);
		else
			hugo_sort(&a, &b);
	}
	free(a.v);
	free(b.v);
}
