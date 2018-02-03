/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discharges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:48:53 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 12:49:00 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_discharge(long long int width)
{
	int i;

	i = 0;
	if (width >= -9 && width <= 9)
		return (1);
	while (width)
	{
		i++;
		width /= 10;
	}
	return (i);
}
