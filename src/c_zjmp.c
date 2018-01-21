/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:16:31 by omotyliu          #+#    #+#             */
/*   Updated: 2018/01/21 18:16:47 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	zjmp(t_process *process)
{
	int	address;

	address = bytes_to_int(process->counter + 1, IND_SIZE);
	if (process->carry == 1)
		process->counter += (address);
	else
		process->counter += IND_SIZE + 1;
}
