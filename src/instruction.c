/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:13:04 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/25 17:05:10 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_node **deque)
{
	t_node	*tmp;

	if (deque == NULL || *deque == NULL || (*deque)->next == NULL)
		return (-1);
	tmp = (*deque)->next;
	(*deque)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *deque;
	tmp->next = *deque;
	tmp->prev = NULL;
	(*deque)->prev = tmp;
	*deque = tmp;
	return (0);
}

int	ft_push(t_node **deque_from, t_node **deque_to)
{
	t_node	*tmp;

	if (deque_from == NULL || *deque_from == NULL)
		return (-1);
	tmp = (*deque_from)->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	(*deque_from)->next = *deque_to;
	if (*deque_to != NULL)
		(*deque_to)->prev = *deque_from;
	*deque_to = *deque_from;
	*deque_from = tmp;
	return (0);
}

// down = 0, up =  1
int	ft_rotate(t_node **deque, int reverse)
{
	t_node	*tmp;

	if (deque == NULL || *deque == NULL || (*deque)->next == NULL)
		return (-1);
	tmp = *deque;
	if (reverse == 0)
	{
		*deque = (*deque)->next;
		(*deque)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = ft_last_node(*deque);
		ft_last_node(*deque)->next = tmp;
	}
	else
	{
		*deque = ft_last_node(*deque);
		(*deque)->prev->next = NULL;
		(*deque)->prev = NULL;
		(*deque)->next = tmp;
		tmp->prev = *deque;
	}
	return (0);
}

int	ft_do_instruction(t_node **deque_a, t_node **deque_b,
	char *intstruction, int is_print)
{
	if (!is_print)
		ft_printf("%s\n", intstruction);
	if (strcmp(intstruction, "sa") == 0)
		return (ft_swap(deque_a));
	else if (strcmp(intstruction, "sb") == 0)
		return (ft_swap(deque_b));
	else if (strcmp(intstruction, "ss") == 0)
		return (ft_swap(deque_a) && ft_swap(deque_b));
	else if (strcmp(intstruction, "pa") == 0)
		return (ft_push(deque_b, deque_a));
	else if (strcmp(intstruction, "pb") == 0)
		return (ft_push(deque_a, deque_b));
	else if (strcmp(intstruction, "ra") == 0)
		return (ft_rotate(deque_a, 0));
	else if (strcmp(intstruction, "rb") == 0)
		return (ft_rotate(deque_b, 0));
	else if (strcmp(intstruction, "rr") == 0)
		return (ft_rotate(deque_a, 0) && ft_rotate(deque_b, 0));
	else if (strcmp(intstruction, "rra") == 0)
		return (ft_rotate(deque_a, 1));
	else if (strcmp(intstruction, "rrb") == 0)
		return (ft_rotate(deque_b, 1));
	else if (strcmp(intstruction, "rrr") == 0)
		return (ft_rotate(deque_a, 1) && ft_rotate(deque_b, 1));
	return (-1);
}

int	ft_do_multi_instruction(t_node **deque_a, t_node **deque_b,
	char *intstruction, int num)
{
	while (num--)
	{
		if (ft_do_instruction(deque_a, deque_b, intstruction, 0) == -1)
			return (-1);
	}
	return (0);
}
