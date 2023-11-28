/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:57:30 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/25 17:02:03 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stop(t_node *deque_a, char *msg)
{
	ft_lst_clear(deque_a);
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	ft_atoi_exhandler(char *str, t_node *deque_a)
{
	long long	res;
	long long	sign;

	res = 0;
	sign = 1;
	while (*str && ((9 <= *str && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_free_stop(deque_a, ERROR_MSG_INPUT);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_free_stop(deque_a, ERROR_MSG_INPUT);
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * sign;
	if ((res) > INT_MAX || (res) < INT_MIN)
		ft_free_stop(deque_a, ERROR_MSG_INPUT);
	return (res);
}

int	ft_argu_check(t_node *deque_a, char *str)
{
	t_node	*tmp;
	int		nbr;

	tmp = deque_a;
	nbr = ft_atoi_exhandler(str, deque_a);
	while (tmp)
	{
		if (tmp->val == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_lst_is_sorted(t_node *deque, int reverse)
{
	t_node	*tmp;

	tmp = deque;
	if (ft_lst_size(deque) == 0 || !deque)
		return (0);
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val && reverse == 0)
			return (0);
		if (tmp->val < tmp->next->val && reverse == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
