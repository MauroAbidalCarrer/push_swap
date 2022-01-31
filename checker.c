/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:06:42 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/31 17:11:14 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_next_line(int fd);

t_stack	*get(char c, t_stack *a, t_stack *b)
{
	if (c == 'a')
		return (a);
	if (c == 'b')
		return (b);
	return (NULL);
}

int	exec(char *l, t_stack *a, t_stack *b)
{
	if (*l == 'p')
	{
		if ((l[1] == 'a' || l[1] == 'b') && !l[2])
			push(get(l[1], a, b), 0);
		else
			return (0);
	}
	else if (*l == 'r')
	{
		if ((l[1] == 'a' || l[1] == 'b') && !l[2])
			rotate(get(l[1], a, b), 0);
		else if(l[1] == 'r')
		{
			if ((l[2] == 'a' || l[2] == 'b') && !l[3])
				rev_rotate(get(l[2], a, b);
			else if (l[2] == 'r' && !l[3])
				rev_all(a, b, 0);
			else if (!l[2])
				rotate_all(get(a, b), 0);
			else
				return (0);
		}
			return (0);
	}
	else if (*l == 's')
	{
		if ((l[1] == 'a' || l[1] == 'b') && !l[2])
			swap(get(l[1], a, b), 0);
		else if (l[1] == 's' && !l[1])
			swap_all(a, b, 0);
		else
			return (0):
	}
	else
		return (0);
	return (1);	
}

int	listen(t_stack a, t_stack b)
{
	char	*line;
	int success;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (exec(line, &a, &b))
		{
			free(line);
			write(1, "ERROR\n", 6);
			return (1);
		}
		free(line);
	}
	success = is_sorted(a) && b.s == 0;
	if (success)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (!success);
}

int	main(int ac, char **av)
{
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
	return (listen(a, b));
}
