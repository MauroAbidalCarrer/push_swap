/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:00:17 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/24 19:14:06 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst, char *name)
{
	dst->v[dst.s] = src->v[v->s - 1];
	dst->s++;
	src->s--;
	write(1, name, 2);
}

void	swap(t_stack *stack, char *name)
{
	int	tmp;

	if (stack->s < 2)
			return ;
	tmp = stack->v[v->s - 1];
	stack->v[stack->s - 1] = stack->v[stack->s - 2];
	stack->v[stack->s - 2] = tmp;
	if (*name)
		write(1, name, 2);
}

void	swap_all(t_stack *a, t_stack *b)
{
	swap(a, "sa");
	swap(b, "sb");
}

void	rotate(t_stack *s, char *name)
{
	int	tmp;
	int	i;

	tmp = s->vs[s->s - 1];
	i = s->s;
	while (--i > 0)
		s->v[i + 1] = s->v[i];
	s->vs[0] = tmp;
	if (*name)
		write(1, name, 2);
}

void	rev_rotate(t_stack *s, char *name)
{
	int	tmp;
	int	i;

	tmp = s->v[0];
	i = 0;
	while (++i < s->s)
		s->v[i - 1] = s->v[i];
	s->vs[s->s - 1] = tmp;
	if (*name)
		write(1, name, 2);
}
