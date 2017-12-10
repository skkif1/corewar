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
	char *cycle;

	cycle = ft_itoa(g_env->cycle + 1);
		notification = ft_strdup("\nA process shows that player ");
		notification = ft_append(notification, process->name, ft_strlen(notification), ft_strlen(process->name));
		notification = ft_append(notification, ft_itoa(process->id), ft_strlen(notification), ft_strlen(ft_itoa(process->id)));
		notification = ft_append(notification, " is alive on cycle --> ", ft_strlen(notification), 23);
		notification = ft_append(notification, cycle, ft_strlen(notification), ft_strlen(cycle));
		add_notification(notification, process);
}

void live(t_process *process)
{
    t_player *player;
    unsigned int arg = get_arg(process);

	player = find_player(arg);

	if(player != NULL && player->player_number == process->player_num)
	{
		process->live++;
		player->last_live = (g_env->cycle + 1);
		player->live_in_period++;
        anounce_live(process);
	}
    g_env->num_live++;
    process->say_live++;
    process->counter += 5;
}
