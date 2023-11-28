/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:53 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/14 13:12:51 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pass(const char *str, int *i, int *sign)
{
	while (str[*i] && ((9 <= str[*i] && str[*i] <= 13) || str[*i] == 32))
	{
		*i = *i + 1;
	}
	if (str[*i] != '\0' && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!str)
		return (0);
	ft_pass(str, &i, &sign);
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * (int)num);
}
