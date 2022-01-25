/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:00:17 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/25 17:03:09 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push(t_stack *src, t_stack *dst, char *operation)
{
	dst->v[dst->s] = src->v[src->s - 1];
	dst->s++;
	src->s--;
	write(1, operation, 3);
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
	int	tmp;
	int	i;

	tmp = s->v[s->s - 1];
	i = s->s;
	while (--i > 0)
		s->v[i + 1] = s->v[i];
	s->v[0] = tmp;
	if (operation)
		write(1, operation, 3);
}

void	rev_rotate(t_stack *s, char *operation)
{
	int	tmp;
	int	i;

	tmp = s->v[0];
	i = 0;
	while (++i < s->s)
		s->v[i - 1] = s->v[i];
	s->v[s->s - 1] = tmp;
	if (operation)
		write(1, operation, 3);
}
