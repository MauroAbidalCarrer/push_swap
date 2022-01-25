/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:00:17 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/25 19:11:55 by maabidal         ###   ########.fr       */
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

void	push(t_stack *src, t_stack *dst, char *operation)
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

	write(1, operation, 3);

//printf("\n");
}

void	swap(t_stack *s, char *operation)
{
	int	tmp;

	if (s->s < 2)
			return ;
	tmp = s->v[0];
	s->v[0] = s->v[1];
	s->v[1] = tmp;
	if (operation)
		write(1, operation, 3);
}

void	rotate(t_stack *s, char *operation)
{
	shift(*s, 1);
	if (operation)
		write(1, operation, 3);
}

void	rev_rotate(t_stack *s, char *operation)
{
	shift(*s, -1);
	if (operation)
		write(1, operation, 3);
}
