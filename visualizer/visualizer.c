/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:12:28 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/21 17:39:53 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	ruturn (i);
}

void	put_str(char *str, int precision)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	if (len < precision)
		write(1, "            ", precision - len);
}

void	put_stack(int longest, t_stack a, t_stack b)
{
	int	max = a.len > b.len ? a : b;
	for (int i = max - 1; i >= 0; i--)
	{
		if (i < a.len)
			put_str(a.vals[i], longest);
		write(1, " ", );
		if (i < b.len)
			put_str(bvals[i], longest);
		write(1, "\n", 1);
	}
	put_str("a", longest);
	write(1,  " b\n\n", 4);
}

int	main(int ac, char **av)
{
	int	longest;
	int	c_len;
	t_stack	a, b;

	longest = 0;
	for (int i = 1; i < ac; i++)
	{
		c_len = ft_strlen(av[i]);
		if (c_len > longest)
			longest = c_len;
	}
	a.vals = malloc(sizeof(char *) * (ac - 1));
	a.len = ac - 1;
	b.vals = malloc(sizeof(char *) * (ac - 1));
	b.len = 0;
	for (int i = 1; i < ac; i++)
	{
		a.vals[i - 1] = av[i];
		put_str(av[i], longest);
	}
	put_stack(longest);
	put_rest(longest);
}
