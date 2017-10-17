#include "../includes/op.h"

unsigned int bytes_to_int(const unsigned char *bytes)
{
    unsigned int l = 0;
    l += bytes[0] & 0xFF;
    l <<= 8;
    l += bytes[1] & 0xFF;
    l <<= 8;
    l += bytes[2] & 0xFF;
    l <<= 8;
    l += bytes[3] & 0xFF;
    return l;
}

t_player *find_player(unsigned int number)
{
    t_list *temp = g_env->players;

    while (temp)
    {
        if (((t_player*)temp->content)->player_number == number)
            return (t_player*)temp->content;
        temp = temp->next;
    }
    return 0;
}

unsigned  int get_arg(t_process *process)
{
    unsigned int arg;
    arg = bytes_to_int(&g_env->global_field[process->counter + 1]);
    return arg;
}

void live(t_process *process)
{
    t_player *player;
    unsigned int arg = get_arg(process);

    if (arg == process->registers[0])
    {
        process->live++;
        player = find_player(process->registers[0]);
        player->last_live = (g_env->cycle + 1);
    }
    process->counter += 5;
}



