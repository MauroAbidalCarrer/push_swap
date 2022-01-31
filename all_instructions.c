/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:58:35 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 17:23:49 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


#include <stdio.h>

void	swap_all(t_stack *a, t_stack *b, int show)
{
	swap(a, 0);
	swap(b, 0);
	if (show)
		write(1, "ss\n", 3);
}

void	rotate_all(t_stack *a, t_stack *b, int show)
{
	rotate(a, 0);
	rotate(b, 0);
	if (show)
		write(1, "rr\n", 3);
}

void	rev_all(t_stack *a, t_stack *b, int show)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	if (show)
		write(1, "rrr\n", 4);
}

void	push_all(t_stack *src, t_stack *dst)
{
	while (src->s > 0)
		push(src, dst, 1);
}
