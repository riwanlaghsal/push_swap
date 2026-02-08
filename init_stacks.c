/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:24:16 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/02/03 09:16:32 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	if (!stack || !*stack)
		return (-1);
	current = *stack;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	*stack = NULL;
	return (0);
}

int	error_doublon(t_stack *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	error_syntax(char *nb)
{
	int	i;

	if (ft_strlen(nb) == 0)
		return (1);
	i = 0;
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

long	ft_atol(char *nptr)
{
	long	sign;
	long	i;
	long	n;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\r'
			|| nptr[i] == ' ' || nptr[i] == '\v' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	n *= sign;
	return (n);
}

int	init_stack_a(t_stack **stack_a, char **argv, int flag)
{
	long	n;
	int		i;

	i = flag;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			return (error_exit(stack_a));
		n = ft_atol(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			return (error_exit(stack_a));
		if (error_doublon(*stack_a, n))
			return (error_exit(stack_a));
		append_child(stack_a, n);
		i++;
	}
	return (0);
}
