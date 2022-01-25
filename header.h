/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:35:27 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/25 17:38:00 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef LIMIT
#  define LIMIT 24
# endif
# include<unistd.h>
# include<stdlib.h>
typedef struct stack
{
	int	*v;
	int	s;
}	t_stack;

void	swap_all(t_stack *a, t_stack *b);
void	rotate_all(t_stack *a, t_stack *b);
void	rev_all(t_stack *a,t_stack *b);
void	push(t_stack *src, t_stack *dst, char *name);
void	push_all(t_stack *src, t_stack *dst, char *name);
void	swap(t_stack *stack, char *name);
void	swap_all(t_stack *a, t_stack *b);
void	rotate(t_stack *s, char *name);
void	rev_rotate(t_stack *s, char *name);
void	sam_eye_sort(t_stack *a, t_stack *b);
void	classify(t_stack *a, t_stack *b);
void	sam_eye_sort(t_stack *a, t_stack *b);
int	is_sorted(t_stack s);

void	print_stack(t_stack s, char name);
#endif
