/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:35:27 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/24 19:17:12 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
typedef struct stack
{
	int	*v;
	int	s;
}	t_stack;

void	swap_all(t_stack *a, t_stack *b);
void	rotate_all(_stack *a, t_stack *b);
void	rev_all(t_stack *a,t_stack *b);
void	push(t_stack *src, t_stack *dst, char *name);
void	swap(t_stack *stack, char *name);
void	swap_all(t_stack *a, t_stack *b);
void	rotate(t_stack *s, char *name);
void	rev_rotate(t_stack *s, char *name);
void	swap_sort(t_stack *a, t_stack *b, int max);
#endif
