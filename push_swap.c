/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:31:59 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/02/03 11:47:03 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	char	**splited;
	int		*tab;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		splited = ft_split(argv[1], ' ');
		if (init_stack_a(&stack_a, splited, 0))
			return (1);
		free(splited);
	}
	else
	{
		if (init_stack_a(&stack_a, argv, 1))
			return (1);
	}
	tab = init_tab(stack_a, get_size_stack(stack_a));
	tab = bubble_sort(tab, get_size_stack(stack_a));
	init_index(&stack_a, tab, get_size_stack(stack_a));
	radix_sort(&stack_a, &stack_b, get_size_stack(stack_a));
	free_stack(&stack_a);
	free(tab);
}
