/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:52:07 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/01/28 15:14:33 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		i++;
	return (i);
}

int	*bubble_sort(int *tab, int size)
{
	int	i;
	int	flag;
	int	temp;

	i = 0;
	flag = 0;
	while (i < size)
	{
		if (i == size - 1 && flag == 1)
		{
			i = 0;
			flag = 0;
		}
		if (i == size - 1)
			break ;
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			flag = 1;
		}
		i++;
	}
	return (tab);
}

void	init_index(t_stack **head, int *tab, int size)
{
	t_stack	*current;
	int		i;

	if (!head || !*head)
		return ;
	current = *head;
	while (current != NULL)
	{
		i = 0;
		while (i < size && current->value != tab[i])
			i++;
		if (i < size)
			current->index = i;
		current = current->next;
	}
}
