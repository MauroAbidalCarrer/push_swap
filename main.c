/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:19:58 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 17:19:08 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1 || )
		return (0);
	if (!av_is_valid(av + 1))
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	a.v = init_stack(ac - 1, av + 1, 'a');
	if (a.v == NULL)
		return(0);
	b.v = init_stack(ac - 1, NULL, 'b');
	if (b.v == NULL)
	{
		free(a.v);
		return (1);
	}
	classify(&a, &b);
	if (!is_sorted(a))
	{
		if (ac < LIMIT)
			sam_eye_sort(&a, &b);
		else
			hugo_sort(&a, &b);
	}
	free(a->v);
	free(b->v);
}
