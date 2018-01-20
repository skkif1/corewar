#include "../includes/op.h"

unsigned  int get_arg(t_process *process)
{
    unsigned int arg;
    arg = bytes_to_int(process->counter + 1, 4);
    return arg;
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
    }
    g_env->num_live++;
    process->say_live++;
    process->counter += 5;
}
