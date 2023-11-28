/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:29:43 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/25 17:18:58 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 2 3
// 5) 1 3 2 pb -> sa -> pa
// 1) 2 1 3 sa 
// 4) 2 3 1 ra ra -> 1 xx 3 2 | pb -> rra rra
// 2) 3 2 1 ra -> 2 1 xxx 3  |  sa -> 1 2 xxx 3 
// 3) 3 1 2 ra -> 1 2 xxx 3  |
int	ft_less_three_a(t_node **deque_a, t_node **deque_b, int len)
{
	if (len == 2)
	{
		if ((*deque_a)->val > (*deque_a)->next->val)
			ft_do_instruction(deque_a, deque_b, "sa", 0);
	}
	else if (len == 3)
	{
		if ((*deque_a)->val > (*deque_a)->next->val)
			ft_helper_a(deque_a, deque_b);
		else if ((*deque_a)->val < (*deque_a)->next->val)
			ft_helper_a2(deque_a, deque_b);
	}
	return (1);
}

// 1 2 3
// 1) 1 3 2 rb -> 3 2 1 pa pa rrb pa
// 3) 2 1 3 xxx rb rb -> 3 xxx 1 2 -> pa -> rrb rrb -> pa pa 
// 2) 2 3 1 sb -> 3 2 1 pa pa pa
// 5) 3 2 1 pa pa pa
// 4) 3 1 2 pa sb pa
int	ft_less_three_b(t_node **deque_a, t_node **deque_b, int len)
{
	if (len == 2)
	{
		if ((*deque_b)->val < (*deque_b)->next->val)
		{
			ft_do_instruction(deque_a, deque_b, "sb", 0);
			ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
		}
		else
			ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
	}
	else if (len == 3)
	{
		if ((*deque_b)->val < (*deque_b)->next->val)
			ft_helper_b(deque_a, deque_b);
		else
			ft_helper_b2(deque_a, deque_b);
	}
	return (1);
}

int	ft_quicksort_a(t_node **deque_a, t_node **deque_b, int len)
{
	int	pivot;
	int	num;
	int	pushed_under;

	if (ft_lst_is_sorted(*deque_a, INCREASING))
		return (1);
	num = len;
	if (len <= 3)
		return (ft_less_three_a(deque_a, deque_b, len));
	pushed_under = 0;
	if (!get_pivot(&pivot, *deque_a, len))
		return (0);
	while (len != num / 2 + num % 2)
	{
		if ((*deque_a)->val < pivot && (len--))
			ft_do_instruction(deque_a, deque_b, "pb", 0);
		else if ((++pushed_under))
			ft_do_instruction(deque_a, deque_b, "ra", 0);
	}
	while (!ft_lst_is_sorted(*deque_a, INCREASING) && pushed_under--)
		ft_do_instruction(deque_a, deque_b, "rra", 0);
	return (ft_quicksort_a(deque_a, deque_b, num / 2 + num % 2)
		&& ft_quicksort_b(deque_a, deque_b, num / 2));
}

int	ft_quicksort_b(t_node **deque_a, t_node **deque_b, int len)
{
	int	pivot;
	int	num;
	int	pushed_under;

	pushed_under = 0;
	if (ft_lst_is_sorted(*deque_b, DESCENDING))
		while (len--)
			ft_do_instruction(deque_a, deque_b, "pa", 0);
	if (len <= 3)
		return (ft_less_three_b(deque_a, deque_b, len));
	num = len;
	if (!get_pivot(&pivot, *deque_b, len))
		return (0);
	while (len != num / 2)
	{
		if ((*deque_b)->val >= pivot && len--)
			ft_do_instruction(deque_a, deque_b, "pa", 0);
		else if (++pushed_under)
			ft_do_instruction(deque_a, deque_b, "rb", 0);
	}
	while (!ft_lst_is_sorted(*deque_b, DESCENDING) && pushed_under--)
		ft_do_instruction(deque_a, deque_b, "rrb", 0);
	return (ft_quicksort_a(deque_a, deque_b, num / 2 + num % 2)
		&& ft_quicksort_b(deque_a, deque_b, num / 2));
}

int	get_pivot(int *pivot, t_node *deque, int len)
{
	int		*cache;
	int		*buf;
	int		i;
	t_node	*tmp;

	tmp = deque;
	cache = (int *)malloc(sizeof(int) * len);
	if (!cache)
		return (0);
	buf = (int *)calloc(len, sizeof(int));
	if (!buf)
		return (0);
	i = -1;
	while (++i < len)
	{
		cache[i] = tmp->val;
		tmp = tmp->next;
	}
	ft_mergesort(0, len - 1, cache, buf);
	*pivot = cache[len / 2];
	free(cache);
	free(buf);
	return (1);
}
