/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:09:19 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/26 23:40:14 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

#include <stdio.h>


void	print_stack(t_stack s)
{
	printf("stack '%c', size = %d\n", s.name, s.s);
	for (int i = 0; i < s.s; i++)
		printf("%c.v[%d] = %d\n", s.name, i, s.v[i]);
	printf("\n");
}

void	classify(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	while (i < a->s)
	{
		j = 0;
		b->v[i] = 0;
		while (j < a->s)
		{
			if (a->v[j] < a->v[i])
				(b->v[i])++;
			j++;
		}
		i++;
	}
	b->s = 0;
	temp = a->v;
	a->v = b->v;
	b->v = temp;
}

int	is_sorted(t_stack s)
{
	int	i;

	if (s.name =='a')
	{
		i = -1;
		while (++i < s.s - 1)
		{
			if (s.v[i] > s.v[i + 1])
				return (0);
		}
		return (1);
	}
	else
	{
		i = s.s;
		while (--i > 0)
		{
			if (s.v[i] > s.v[i - 1])
				return (0);
		}
		return (1);
		//return (s.s != 0);
	}
}

void	sam_eye_sort(t_stack *a, t_stack *b)
{
	int	to_send;
	int	max;

	max = a->s - 1;
	to_send = 0;
	while (!is_sorted(*a))
	{
		if (a->v[0] > a->v[1] && a->v[0] != max && a->v[1] != max)
			swap(a, 1);
		else if (a->v[0] == to_send)
		{
			to_send++;
			push(a, b);
		}
		else
			rotate(a, 1);
	}
//printf("is_sorted(a) = %d, before push all\n", is_sorted(*a));
//print_stack(*a, 'a');
//printf("is_sorted(b) = %d, before push all\n", is_sorted(*b));
	push_all(b, a);
	/*
printf("done sotring\n");
printf("name = %c\n", a->name);
printf("is_sorted(a) = %d\n", is_sorted(*a));
print_stack(*a);
*/
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bitshift;
	int	passes;

	bitshift = 0;
//print_stack(*a);
//printf("starting sort\n");
	while (!is_sorted(*a))
	{
		passes = a->s;
//printf("bitshift = %d\n", bitshift);
		while (passes-- > 0)
		{
			if ((a->v[0] >> bitshift) & 1)
				rotate(a, 1);
			else
				push(a, b);
			if (is_sorted(*a) && is_sorted(*b))
				break ;
			//printf("second\n");
		}
		push_all(b, a);
//		print_stack(*a);
//		print_stack(*b);

			//printf("first\n");
		bitshift++;
		if (bitshift >= 31)
		{
			//printf("ERROR\n");
			break;
		}
	}
	
}
