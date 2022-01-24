/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:32:03 by maabidal          #+#    #+#             */
/*   Updated: 2022/01/21 16:54:05 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
#include <stdio.h>
#include <unistd.h>
int	get_next_line(int fd);
void	put_rest(int longest);
void	put_str(char *str, int precision);
typedef struct stack
{
	char	**vals;
	int	len;
} t_stack;
#endif
