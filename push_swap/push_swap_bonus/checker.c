/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:47:14 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/26 16:59:38 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tmp(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
}

void	free_memory(t_list *stack_a, t_list *stack_b)
{
	free (stack_b);
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
}

void	parssing(char **av, t_list *stack_a)
{
	char	**split;

	split = split_stack(av);
	creat_stack(stack_a, split);
	free(split);
	check_same_number(stack_a);
}

void	modulation_stack(t_list **stack_a, t_list **stack_b, char *input)
{
	if (!ft_strcmp(input, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(input, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(input, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(input, "pb\n"))
		pb(stack_b, stack_a);
	else if (!ft_strcmp(input, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(input, "sb\n"))
		sb(stack_b);
	else
	{
		ft_putstr_fd("error\n", 1);
		free(input);
		free_memory(*stack_a, *stack_b);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*input;

	if (ac > 1)
	{
		stack_a = ft_lstnew(42);
		stack_b = ft_lstnew(1337);
		parssing(av, stack_a);
		free_tmp(&stack_a);
		input = get_next_line(0);
		while (ft_strcmp(input, "ok\n"))
		{
			modulation_stack(&stack_a, &stack_b, input);
			free(input);
			input = get_next_line(0);
		}
		free(input);
		check_sort(stack_a);
		free_memory(stack_a, stack_b);
	}
	else
		exit(0);
}
