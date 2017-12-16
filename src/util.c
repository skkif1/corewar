#include "../includes/op.h"


int lst_size(t_list *list)
{
    t_list *temp;
    int i;

    i = 0;
    temp = list;
	if(temp == NULL)
		return 0;
    while (temp)
    {

        if(((t_process*)temp->content)->id != 2000000000)
        {
            i++;
        }
        temp = temp->next;
    }
    return i;
}

int get_opcode_by_name(char *name)
{
    int i;

    i = 0;

    while (i < 16)
    {
        if (!strcmp(name, g_tab[i].name))
            return i;
        i++;
    }
    ft_printf("no such command");
    exit(1);
}




void screen_cycle_status()
{
    if (g_env->vis)
        return;
    t_list* temp = g_env->players;
    ft_printf("we have %d players in game \n", lst_size(temp));
    t_player *player;

    while (temp)
    {
        player = temp->content;
        ft_printf("%s number is %u \n", (char *) player->player_name, player->player_number);
        ft_printf("his last live was on %d cycle\n", player->last_live);
        ft_printf("his color %d \n", player->color);
        ft_printf("------------------------------------------\n");
        temp = temp->next;
    }

    ft_printf("allready passed cycles is %d \n", g_env->cycle);
    ft_printf("in game there are %d processes\n", lst_size(g_env->processes));

    temp = g_env->processes;
    t_process *process;

    while (temp)
    {
        process = temp->content;
        ft_printf("process %u: \n", process->registers[0]);
        ft_printf("process PC is on %u \n", process->counter);
        ft_printf("process say live %d times in current period \n", process->live);
        ft_printf("process current operation is %s\n", process->current_op);
        ft_printf("cycles to execute current op is %d \n", process->cycle_to_execute);
        ft_printf("|||||||||||||||||||||||||||||||||||||||\n\n");

        temp = temp->next;
    }
//    exit(0);
}

unsigned int big_to_little(unsigned int value)
{
	value = ((value>>24)&0xff) | // move byte 3 to byte 0
			((value<<8)&0xff0000) | // move byte 1 to byte 2
			((value>>8)&0xff00) | // move byte 2 to byte 1
			((value<<24)&0xff000000);
	return value;
}