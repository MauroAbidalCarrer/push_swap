/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:35:27 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 22:45:45 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef LIMIT
#  define LIMIT 14
# endif
# include<unistd.h>
# include<stdlib.h>
typedef struct stack
{
	int	*v;
	int	s;
	char	name;
	int	init_size;
}	t_stack;
typedef void (* t_rotation_all)(t_stack *a, t_stack *b, int show);

void	swap_all(t_stack *a, t_stack *b, int show);
void	rotate_all(t_stack *a, t_stack *b, int show);
void	rev_all(t_stack *a, t_stack *b, int show);
void	push_all(t_stack *src, t_stack *dst);

void	push(t_stack *src, t_stack *dst, int show);
void	swap(t_stack *s, int show);
void	rotate(t_stack *s, int	show);
void	rev_rotate(t_stack *s, int show);

int	is_sorted(t_stack s);
void	classify(t_stack *a, t_stack *b);
void	sam_eye_sort(t_stack *a, t_stack *b);

void	find_vals_to_sort(t_stack *a, t_stack *b, int max, int *indices);
int	bring_up(t_stack *a, t_stack *b, int *indices, int show);
void	hugo_sort(t_stack *a, t_stack *b);

void	print_stack(t_stack s);

int	av_is_valid(char **av);
void	init_stack(t_stack *s, int ac, char **av, char name);
int	init(int ac, char **av, t_stack *a, t_stack *b);
#endif
