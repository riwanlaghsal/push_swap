/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaghsal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:41:55 by rlaghsal          #+#    #+#             */
/*   Updated: 2026/01/28 15:15:53 by rlaghsal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_element(int val)
{
	t_stack *new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->value = val;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

t_stack	*get_last_element(t_stack *head)
{
	t_stack	*current;

	if (!head)
		return (NULL);
	current = head;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	append_child(t_stack **head, int val)
{
	t_stack *last_element;
	t_stack *new_element;

	new_element = create_element(val);
	if (*head == NULL)
		*head = new_element;
	else
	{
		last_element = get_last_element(*head);
		new_element->prev = last_element;
		new_element->next = NULL;
		last_element->next = new_element;
	}
}

int	*init_tab(t_stack *head, int size)
{
	int	i;
	int	*tab;
	t_stack	*current;

	if (!head)
		return (NULL);
	current = head;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (current)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	tab = bubble_sort(tab, get_size_stack(head));
	return (tab);
}
