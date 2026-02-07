/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:00:35 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/02/03 09:16:17 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max;
	int	max_bits;

	if (size < 2)
		return (0);
	max = size - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	get_size_stack(t_stack *stack)
{
	int	i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	max_bits;
	t_stack	*head;

	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		size = get_size_stack(*a);
		j = 0;
		while (j < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (get_size_stack(*b) > 0)
			pa(a, b);
		i++;
	}
}
