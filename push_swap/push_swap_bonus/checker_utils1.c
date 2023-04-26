/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:43:09 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/26 17:00:16 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_stack(char **av)
{
	int		i;
	char	*string;
	char	**split;

	string = ft_strdup("");
	i = 1;
	while (av[i])
	{
		string = ft_strjoin1(string, av[i]);
		string = ft_strjoin1(string, " ");
		i++;
	}
	i = 0;
	split = ft_split(string, ' ');
	free(string);
	while (split[i])
	{
		check_valid_stack(split[i]);
		i++;
	}
	return (split);
}

int	creat_stack(t_list	*stack_a, char **split)
{
	t_list	*tab;
	int		i;

	i = 0;
	while (split[i])
	{
		tab = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(&stack_a, tab);
		free(split[i]);
		i++;
	}
	return (i);
}

void	check_same_number(t_list	*stack_a)
{
	t_list	*head;
	t_list	*head_1;

	head = stack_a;
	head_1 = stack_a->next;
	while (head->next)
	{
		head_1 = head->next;
		while (head_1)
		{
			if (head->content == head_1->content)
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
			head_1 = head_1->next;
		}
		head = head->next;
	}
}

int	check_valid_stack(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (str[i] <= '0' || str[i] >= '9')
				message_error();
		}
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != '\0' && str[i] != ' ')
			message_error();
		i++;
	}
	return (1);
}
