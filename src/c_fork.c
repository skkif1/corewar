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

static unsigned int g_id;

void c_fork(t_process *process)
{
    int param;
    t_process *child_process;
    int i;

    i = 0;
    param = ((short)bytes_to_int(process->counter + 1, 2)) % IDX_MOD + process->counter;
    child_process = (t_process*)malloc(sizeof(t_process));
    while(i < REG_NUMBER + 1)
    {
        child_process->registers[i] = process->registers[i];
        i++;
    }
    child_process->registers[1] = process->registers[1];
    child_process->color = process->color;
    child_process->name = ft_strdup(process->name);
    child_process->live = process->live;
    child_process->counter = param;
    child_process->carry = process->carry;
    child_process->say_live = process->say_live;
    child_process->current_op = 0;
    child_process->is_child = 1;
    child_process->id = g_id++;
    child_process->player_num = process->player_num;
    ft_lstadd(&g_env->processes, ft_lstnew(child_process, sizeof(t_process)));
    g_env->process_number++;
    process->counter += 3;
    if (child_process->counter >= MEM_SIZE)
        child_process->counter = child_process->counter % MEM_SIZE;
    free(child_process);
}
