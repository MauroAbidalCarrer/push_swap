/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:58:35 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/25 17:08:20 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


#include <stdio.h>

void	swap_all(t_stack *a, t_stack *b)
{
	swap(a, NULL);
	swap(b, NULL);
	write(1, "ss\n", 3);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(1, "rr\n", 3);
}

void	rev_all(t_stack *a, t_stack *b)
{
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	write(1, "rrr\n", 3);
}

void	push_all(t_stack *src, t_stack *dst, char* name)
{
//write(1, "push all-----------\n", 20);
	while (src->s > 0)
	{
//printf("src->s = %d\n", src->s);
		push(src, dst, name);
	}
}
