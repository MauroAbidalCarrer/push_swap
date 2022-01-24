/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:34:56 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/24 19:14:54 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack s)
{
	while (s.s-- >= 2)
	{
		if (s.v[s.s] > s.v[s.s - 1])
			return (0);
	}
	return (1);
}

void	swap_sort(t_stack *a, t_stack *b, int max)
{
	int	last_sent;

	last_sent = 0;
	while (!is_sorted(a))
	{
		if (a->v[0] > a->v[1] && a->v[0] != max && a->av[1] != max)
			swap(a, 'a');
		else if (a->v[0] == last_sent + 1)
		{
			sent = a->v[0];
			push(a, b, 'b');
		}
		else
			rotate(a, 'a');
	}
	push_all(b, a, 'a');
}
