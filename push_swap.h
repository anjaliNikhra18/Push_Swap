/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:48:34 by aneekhra          #+#    #+#             */
/*   Updated: 2024/03/19 12:55:59 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* PUSH_SWAP */
t_stack				*fill_stack_values(int argc, char **argv);
void				push_swap(t_stack **stack_a, t_stack **stack_b,
						int stack_size);
void				exit_with_error(t_stack **stack_a, t_stack **stack_b);

/* PUSH */
void				push_stack(t_stack **stack_a, int wc, char **str, int f);
void				push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void				push(t_stack **stack_a, t_stack **stack_b);
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);

/* SWAP */
void				swap(t_stack *stack);
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b, int i);

/* ROTATE */
void				rotate(t_stack **stack);
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **a, t_stack **b, int i);
void				do_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);

/* REV_ROTATE */
void				rev_rotate(t_stack **stack);
void				do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b, int i);

/* SORTING ALGO */
void				tiny_sort(t_stack **stack_a);
void				positional_sort(t_stack **stack_a, t_stack **stack_b);
void				do_rotate_a(t_stack **a, int *cost);
void				do_rotate_b(t_stack **b, int *cost);

/* INDEX */
void				assign_index(t_stack *stack_a, int stack_size);
int					find_highest_index(t_stack *stack_a);
int					get_lowest_index_position(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);
int					get_target(t_stack **a, int b_idx, int target_idx,
						int target_pos);

/* STACK */
int					get_stack_size(t_stack *stack);
t_stack				*stack_new(int value);
t_stack				*get_stack_bottom(t_stack *stack_a);
t_stack				*get_stack_before_bottom(t_stack *stack);
void				stack_add_bottom(t_stack **stack_a, t_stack *new_stack);

/* STACK UTILS*/
void				get_position(t_stack **stack);
void				get_cost(t_stack **stack_a, t_stack **stack_b);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				shift_stack(t_stack **stack_a);

/* CHECK_INPUT */
void				ft_check_duplicates(t_stack *stack_a);
int					is_sorted(t_stack *stack);
int					ft_abs(int num);
int					is_digit(char c);
int					is_number(char *av);

/* FREE */
void				*ft_free_strmem(char **str);
void				free_stack(t_stack **stack);

/* UTILS */
long int			ft_atoi(char *av);
char				**ft_split(char *argv, char c);
char				**ft_get_str(char **str, int index, char *argv, char c);
int					count_words(const char *argv, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);

/* STRING UTILS*/
size_t				ft_strlen(char *s);
void				ft_putstr(char *str);
#endif
