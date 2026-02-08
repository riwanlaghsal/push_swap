/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:31:59 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/02/07 15:47:59 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	return (1);
}

int	free_split(char **splited)
{
	int	i;

	if (!splited)
		return (1);
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (1);
}

int	init_splited(t_stack **stack_a, char **argv)
{
	char	**splited;

	if (argv[1][0] == '\0')
		return (1);
	splited = ft_split(argv[1], ' ');
	if (init_stack_a(stack_a, splited, 0))
		return (1);
	free_split(splited);
	return (0);
}

void	easy_sort(t_stack **a, int size)
{
	t_stack	*head;
	int		first;
	int		second;
	int		third;

	if (size == 2)
		return (rra(a));
	head = *a;
	first = head->value;
	second = head->next->value;
	third = head->next->next->value;
	if (first > second && first > third)
		ra(a);
	if (second > first && second > third)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tab;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (init_splited(&stack_a, argv))
			return (1);
	}
	else if (init_stack_a(&stack_a, argv, 1))
		return (1);
	if (is_stack_sorted(stack_a))
		return (0);
	tab = init_tab(stack_a, get_size_stack(stack_a));
	init_index(&stack_a, tab, get_size_stack(stack_a));
	if (get_size_stack(stack_a) == 2 || get_size_stack(stack_a) == 3)
		easy_sort(&stack_a, get_size_stack(stack_a));
	else
		radix_sort(&stack_a, &stack_b, get_size_stack(stack_a));
	free_stack(&stack_a);
	free(tab);
}
