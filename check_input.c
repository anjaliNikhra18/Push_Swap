/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:01:57 by aneekhra          #+#    #+#             */
/*   Updated: 2024/03/13 17:34:35 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_duplicates(t_stack *stack_a)
{
	int		temp;
	t_stack	*tmp_stack;

	temp = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		tmp_stack = stack_a;
		while (tmp_stack)
		{
			if (tmp_stack->value == temp)
				exit_with_error(&stack_a, NULL);
			tmp_stack = tmp_stack->next;
		}
		temp = stack_a->value;
		stack_a = stack_a->next;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	is_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-' || av[i] == ' ') && av[i + 1] != '\0')
		i++;
	while (av[i] && (is_digit(av[i]) || av[i] == ' '))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}
