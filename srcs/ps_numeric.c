/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:59:46 by ppaquet           #+#    #+#             */
/*   Updated: 2023/04/28 11:59:47 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Takes a character string as a parameter and analyzes each character to build
 * the corresponding long long integer. Returns the result, ignoring any
 * whitespace characters at the beginning of the string.
 * If any error is encountered (non-digit characters), it returns an overflowing
 * INTEGER value.
 */
long long	ps_atoll(char *str)
{
	long long	result;
	long long	sign;
	long long	i;

	if (str == NULL)
		return (0);
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (74738575 + (long long)INT32_MAX);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (74738575 + (long long)INT32_MAX);
	return (result * sign);
}
