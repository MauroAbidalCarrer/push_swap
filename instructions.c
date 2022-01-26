/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:00:17 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/26 22:13:29 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	shift(t_stack s, int offset)
{
	int	tmp;
	int	i;

//printf("shift(%d) called\n", offset);
//print_stack(s, 0);
	if (s.s < 2)
		return ;
	i = 0;
	if (offset == -1)
		i = s.s - 1;
	tmp = s.v[i];
//printf("tmp = %d\n", tmp);
	while (i + offset >= 0 && i + offset < s.s)
	{
		s.v[i] = s.v[i + offset];
		i += offset;
	}
	s.v[i] = tmp;
//printf("shift(%d) done\n", offset);
//print_stack(s, 0);
}

void	push(t_stack *src, t_stack *dst)
{
//printf("push(%c%c) called\nsrc = \n", *operation, operation[1]);
//print_stack(*src, 0);
//printf("dst = \n");
//print_stack(*dst, operation[1]);

		dst->s++;
		shift(*dst, -1);
		dst->v[0] = src->v[0];
		shift(*src, 1);
		src->s--;

//printf("push done\nsrc = \n");
//print_stack(*src, 0);
//printf("dst = \n");
//print_stack(*dst, operation[1]);

	write(1, "p", 1);
	write(1, &(dst->name), 1);
	write(1, "\n", 1);

//printf("\n");
}

void	swap(t_stack *s, int print_op)
{
	int	tmp;

	if (s->s < 2)
			return ;
	tmp = s->v[0];
	s->v[0] = s->v[1];
	s->v[1] = tmp;
	if (!print_op)
		return ;
	write(1, "s", 1);
	write(1, &(s->name), 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *s, int	print_op)
{
	shift(*s, 1);
	if (!print_op)
		return ;
	write(1, "r", 1);
	write(1, &(s->name), 1);
	write(1, "\n", 1);
}

void	rev_rotate(t_stack *s, int	print_op)
{
	shift(*s, -1);
	if (!print_op)
		return ;
	write(1, "rr", 2);
	write(1, &(s->name), 1);
	write(1, "\n", 1);
}
