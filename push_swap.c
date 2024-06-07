/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:48:27 by aneekhra          #+#    #+#             */
/*   Updated: 2024/03/19 18:57:44 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*fill_stack_values(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		wc;
	char	**str;
	int		f;

	stack_a = NULL;
	i = 1;
	f = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (NULL);
		str = ft_split(argv[i], ' ');
		if (!str)
			return (NULL);
		wc = count_words(argv[i], ' ');
		push_stack(&stack_a, wc, str, f);
		f = 1;
		i++;
		if (str)
			ft_free_strmem(str);
	}
	return (stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		positional_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = fill_stack_values(argc, argv);
	if (!stack_a)
		return (0);
	stack_size = get_stack_size(stack_a);
	ft_check_duplicates(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
