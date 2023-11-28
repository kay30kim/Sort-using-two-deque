/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:12 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/25 17:18:26 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <string.h>

# define ERROR_MSG_ARG "[ERROR] You need one argument\n"
# define ERROR_MSG_FILENO "[ERROR] Invalid file\n"
# define ERROR_MSG_EXTENSION "[ERROR] It is not .ber file\n"
# define ERROR_MSG_NOFILE "[ERROR] There is no file name\n"
# define ERROR_MSG_OPEN "[ERROR] Can't open the map\n"
# define ERROR_MSG_INIT "[ERROR] Initialization is failed\n"
# define ERROR_MSG_PATH "[ERROR] THis is not a valid path\n"
# define ERROR_MSG_INPUT "[ERROR] Your input format is wrong\n"
# define INCREASING 0
# define DESCENDING 1

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// Instructions
int		ft_swap(t_node **deque);
int		ft_push(t_node **deque_from, t_node **deque_to);
int		ft_rotate(t_node **deque, int reverse);
int		ft_do_instruction(t_node **deque_a, t_node **deque_b,
			char *intstruction, int is_print);
int		ft_do_multi_instruction(t_node **deque_a, t_node **deque_b,
			char *intstruction, int num);

// list functions
int		ft_lst_is_sorted(t_node *deque, int reverse);
void	ft_lst_clear(t_node *node);
int		ft_lst_size(t_node *node);
t_node	*ft_lst_new(int val);
t_node	*ft_lst_add_top_front(t_node *node, int val);
t_node	*ft_last_node(t_node *node);

// Sort functions
void	ft_sort_three_a(t_node **deque_a);
void	ft_sort_three_b(t_node **deque_a, t_node **deque_b);
void	ft_sort(t_node *deque_a, t_node *deque_b);
void	push_swap(t_node *deque_a, t_node *deque_b, int len);
int		ft_quicksort_a(t_node **deque_a, t_node **deque_b, int len);
int		ft_quicksort_b(t_node **deque_a, t_node **deque_b, int len);
int		get_pivot(int *pivot, t_node *deque_a, int len);
void	ft_mergesort(int start, int finish, int *cache, int *buf);
void	ft_helper_a(t_node **deque_a, t_node **deque_b);
void	ft_helper_a2(t_node **deque_a, t_node **deque_b);
void	ft_helper_b(t_node **deque_a, t_node **deque_b);
void	ft_helper_b2(t_node **deque_a, t_node **deque_b);

// Generic Utilities
void	ft_free_stop(t_node *deque_a, char *msg);
int		ft_atoi_exhandler(char *str, t_node *deque_a);
int		ft_argu_check(t_node *deque_a, char *str);
void	print_every(t_node *deque_a, t_node *deque_b, int len, char cha);

#endif
