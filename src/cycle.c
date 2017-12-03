#include "../includes/op.h"

t_env *g_env;

void do_operation(t_process *process)
{
    int operation = get_operation(process);

    if (operation != -1) {
        init_operation(operation, process);
    }
    if (process->counter >= MEM_SIZE)
        process->counter = process->counter % MEM_SIZE;
    place_cursor(process);
}

int check_processes()
{

    t_list *processes;
    int nbr_flag;
    char *notification;

    nbr_flag = 0;
    processes = g_env->processes;

    while (processes)
    {
        if (((t_process*)processes->content)->say_live == 0)
        {
			notification = ft_strdup("\nprocess of player ");
            notification = ft_append(notification, ((t_process*)processes->content)->name, ft_strlen(notification), ft_strlen(((t_process*)processes->content)->name));
            notification = ft_append(notification, " was killed!!", ft_strlen(notification), 13);
            add_notification(notification, processes->content);

            delete_node(&g_env->processes, ((t_process*)processes->content)->id);
            if(lst_size(g_env->processes) == 0)
                return 1;
        }
        else
        {
            if (((t_process*)processes->content)->say_live >= NBR_LIVE)
                    nbr_flag++;
                reset_process(processes->content);
        }
            processes = processes->next;
    }
    if (nbr_flag != 0)
        g_env->cycle_to_die -= CYCLE_DELTA;
    return 0;
}



void dump_memory() {


	int i = 1;
	while (i <= MEM_SIZE)
	{

		ft_printf("%.2x ", g_env->global_field[i - 1]);
		if(i % 64 == 0)
		{
			ft_printf("\n");
		}
		i++;
	}
}


void start_cycle()
{
    t_list *temp;
    int i;
    i = 0;


     while (1)
    {
        if(!manage_ui())
			continue;
        temp = g_env->processes;
        while (temp)
        {
            do_operation(temp->content);
            temp = temp->next;
        }
        if(g_env->cycle == g_env->dump)
            dump_memory();
        if (i++ == g_env->cycle_to_die)
        {
            i = 0;
                if (check_processes())
                {
                    rewrite_memory(g_env->global_field);
                    rewrite_stat();
                    break;
                }
        }
		g_env->cycle++;
		rewrite_memory(g_env->global_field);
		rewrite_stat();
//        g_env->vis_delay = 500;
//        if(g_env->cycle < 3072) // 930
        {
            g_env->vis_delay = 1;
        }
//		screen_cycle_status();
	}
}

