/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:03:25 by aneekhra          #+#    #+#             */
/*   Updated: 2024/03/19 16:56:13 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*stack_new(int value)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(*new_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->pos = -1;
	new_stack->target_pos = -1;
	new_stack->cost_a = -1;
	new_stack->cost_b = -1;
	new_stack->next = NULL;
	return (new_stack);
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack **stack_a, t_stack *new_stack)
{
	t_stack	*tail;

	if (!new_stack)
		return ;
	if (!*stack_a)
	{
		*stack_a = new_stack;
		return ;
	}
	tail = get_stack_bottom(*stack_a);
	tail->next = new_stack;
}
