/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:58:35 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/24 19:14:24 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_all(t_stack *a, t_stack *b)
{
	swap(a, "");
	swap(b, "");
}

void	rotate_all(_stack *a, t_stack *b)
{
	rotate(a, "");
	rotate(b, "");
}

void	rev_all(t_stack *a,t_stack *b)
{
	rev_rotate(a, "");
	rev_rotate(b, "");
}
