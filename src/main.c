/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:46:03 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/25 16:57:54 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 2 3
// 5) 1 3 2 sa -> 3 1 2 ra
// 1) 2 1 3 sa 
// 4) 2 3 1 rra
// 2) 3 2 1 sa -> 2 3 1 rra
// 3) 3 1 2 ra
void	ft_sort_three_a(t_node **deque_a)
{
	if ((*deque_a)->val > (*deque_a)->next->val)
	{
		if ((*deque_a)->val < (*deque_a)->next->next->val)
			ft_do_instruction(deque_a, NULL, "sa", 0);
		else if ((*deque_a)->next->val > (*deque_a)->next->next->val)
		{
			ft_do_instruction(deque_a, NULL, "sa", 0);
			ft_do_instruction(deque_a, NULL, "rra", 0);
		}
		else
			ft_do_instruction(deque_a, NULL, "ra", 0);
	}
	else if ((*deque_a)->val < (*deque_a)->next->val)
	{
		if ((*deque_a)->val > (*deque_a)->next->next->val)
			ft_do_instruction(deque_a, NULL, "rra", 0);
		else if ((*deque_a)->next->val > (*deque_a)->next->next->val)
		{
			ft_do_instruction(deque_a, NULL, "sa", 0);
			ft_do_instruction(deque_a, NULL, "ra", 0);
		}
	}
}

// 1 2 3
// 1) 1 3 2 rb -> 3 2 1 pa pa pa
// 3) 2 1 3 rrb -> 3 2 1 pa pa pa 
// 2) 2 3 1 sb -> 3 2 1 pa pa pa
// 5) 3 2 1 pa pa pa
// 4) 3 1 2 pa sb pa
void	ft_sort_three_b2(t_node **deque_a, t_node **deque_b)
{
	if ((*deque_b)->val < (*deque_b)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "rrb", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 3);
	}
	else if ((*deque_b)->next->val < (*deque_b)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "pa", 0);
		ft_do_instruction(deque_a, deque_b, "sb", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
	}
	else
		ft_do_multi_instruction(deque_a, deque_b, "pa", 3);
}

void	ft_sort_three_b(t_node **deque_a, t_node **deque_b)
{
	if ((*deque_b)->val < (*deque_b)->next->val)
	{
		if ((*deque_b)->val < (*deque_b)->next->next->val)
		{
			ft_do_instruction(deque_a, deque_b, "rb", 0);
			ft_do_multi_instruction(deque_a, deque_b, "pa", 3);
		}
		else if ((*deque_b)->val > (*deque_b)->next->next->val)
		{
			ft_do_instruction(deque_a, deque_b, "sb", 0);
			ft_do_multi_instruction(deque_a, deque_b, "pa", 3);
		}
	}
	else
	{
		ft_sort_three_b2(deque_a, deque_b);
	}
}

void	push_swap(t_node *deque_a, t_node *deque_b, int len)
{
	if (ft_lst_is_sorted(deque_a, 0))
		return ;
	if (len == 2)
		ft_do_instruction(&deque_a, &deque_b, "sa", 0);
	else if (len == 3)
		ft_sort_three_a(&deque_a);
	else
		if (ft_quicksort_a(&deque_a, &deque_b, len) == 0)
			exit(EXIT_FAILURE);
	ft_lst_clear(deque_a);
	ft_lst_clear(deque_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*deque_a;
	t_node	*deque_b;

	i = 0;
	deque_a = NULL;
	deque_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (ft_argu_check(deque_a, argv[i]) == 0)
				ft_free_stop(deque_a, ERROR_MSG_INPUT);
			deque_a = ft_lst_add_top_front(deque_a, ft_atoi(argv[i]));
		}
		push_swap(deque_a, deque_b, ft_lst_size(deque_a));
	}
	return (0);
}
