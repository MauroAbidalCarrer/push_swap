/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:06:42 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/01 01:18:37 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd);

int	check_for_rotation(char *l, t_stack **ss)
{
	if ((l[1] == 'a' || l[1] == 'b') && l[2] == '\n' && !l[3])
		rotate(ss[l[1] == 'b'], 0);
	else if (l[1] == 'r')
	{
		if ((l[2] == 'a' || l[2] == 'b') && l[3] == '\n' && !l[4])
			rev_rotate(ss[l[2] == 'b'], 0);
		else if (l[2] == 'r' && l[3] == '\n' && !l[4])
			rev_all(*ss, ss[1], 0);
		else if (l[2] == '\n' && !l[3])
			rotate_all(*ss, ss[1], 0);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

int	exec(char *l, t_stack **ss)
{
	if (*l == 'p')
	{
		if ((l[1] == 'a' || l[1] == 'b') && l[2] == '\n' && !l[3])
			push(ss[l[1] == 'a'], ss[l[1] == 'b'], 0);
		else
			return (1);
	}
	else if (*l == 'r')
		return (check_for_rotation(l, ss));
	else if (*l == 's')
	{
		if ((l[1] == 'a' || l[1] == 'b') && l[2] && !l[3])
			swap(ss[l[1] == 'b'], 0);
		else if (l[1] == 's' && l[2] == '\n' && !l[3])
			swap_all(*ss, ss[1], 0);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

int	listen(t_stack *a, t_stack *b)
{
	char	*line;
	t_stack	*stacks[2];

	*stacks = a;
	stacks[1] = b;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (exec(line, stacks))
		{
			write(2, "Error\n", 6);
			free(line);
			return (2);
		}
		free(line);
	}
	return (is_sorted(*a) && b->s == 0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		res;

	if (init(ac, av, &a, &b) == 1)
		return (1);
	res = listen(&a, &b);
	if (res == 1)
		write(1, "OK\n", 3);
	else if (res == 0)
		write(1, "KO\n", 3);
	free(a.v);
	free(b.v);
	return (res);
}
