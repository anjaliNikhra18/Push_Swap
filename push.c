/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:58:15 by aneekhra          #+#    #+#             */
/*   Updated: 2024/03/20 20:46:54 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **stack_a, int wc, char **str, int f)
{
	int			j;
	long int	nb;

	j = 0;
	while (j < wc)
	{
		nb = ft_atoi(str[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_with_error(&(*stack_a), NULL);
		if (is_number(str[j]) == 0)
			exit_with_error(&(*stack_a), NULL);
		if (f == 0)
		{
			*stack_a = stack_new((int)nb);
			f = 1;
		}
		else
			stack_add_bottom(&(*stack_a), stack_new((int)nb));
		j++;
	}
}

void	push(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}
