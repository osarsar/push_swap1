/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:44:51 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/26 11:46:03 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_stack(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	check_sort(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	size_stack(stack_a);
	head = stack_a;
	while (head->next)
	{
		if (head->content < head->next->content)
			i++;
		head = head->next;
	}
	if (i == size_stack(stack_a) - 1)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 2);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t		i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
