/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:40:04 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/02/02 16:30:54 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		init_stack_a(t_stack **stack_a, char **argv, int flag);
void	append_child(t_stack **stack_a, int val);
int		free_stack(t_stack **stack);
int		error_exit(t_stack **stack);
int		*init_tab(t_stack *head, int size);
int		*bubble_sort(int *tab, int size);
void	init_index(t_stack **head, int *tab, int size);
int		get_size(char **splited);
t_stack	*get_last_element(t_stack *head);

// instructions de back
void	swap(t_stack **stack);
void	push(t_stack **to_take, t_stack **to_put);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

// instructions de front
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	radix_sort(t_stack **a, t_stack **b, int size);
void	easy_sort(t_stack **a, int size);
int		get_size_stack(t_stack *stack);
int		is_stack_sorted(t_stack *a);

#endif
