#include "../includes/op.h"

unsigned  int get_arg(t_process *process)
{
    unsigned int arg;
    arg = bytes_to_int(process->counter + 1, 4);
    return arg;
}

void anounce_live(t_process *process)
{
	char *notification;

//	if(g_env->vis)
//	{
		notification = ft_strdup("A process shows that player ");
		notification = ft_append(notification, process->name, ft_strlen(notification), ft_strlen(process->name));
		notification = ft_append(notification, " is alive\n", ft_strlen(notification), 10);
		add_notification(notification, process);
//	}
//	else
//	{
//		ft_printf("A process shows that player %s is alive\n", process->name);
//	}

}

void live(t_process *process)
{
    t_player *player;
    unsigned int arg = get_arg(process);


	player = find_player(arg);
	if(player != NULL)
	{
		process->live++;
		player->last_live = (g_env->cycle + 1);
		player->live_in_period++;
	}
    process->counter += 5;
	anounce_live(process);
}
