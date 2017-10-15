#include "op.h"


int lst_size(t_list *list)
{
    t_list *temp;
    int i;

    i = 0;
    temp = list;

    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return i;
}


void screen_cycle_status()
{
    t_list* temp = g_env->players;
    printf("we have %d players in game \n", lst_size(temp));
    t_player *player;

    while (temp)
    {
        player = temp->content;
        printf("%s number is %u \n", (char *) player->player_name, player->player_number);
        printf("his last live was on %d cycle\n", player->last_live);
        printf("his color %d \n", player->color);
        printf("------------------------------------------\n");
        temp = temp->next;
    }

    printf("allready passed cycles is %d \n", g_env->cycle);
    printf("in game there are %d processes\n", lst_size(g_env->processes));

    temp = g_env->processes;
    t_process *process;

    while (temp)
    {
        process = temp->content;
        printf("process %u: \n", process->registers[0]);
        printf("process PC is on %u \n", process->counter);
        printf("process say live %d times in current period \n", process->live);
        printf("process current operation is %s\n", process->current_op);
        printf("cycles to execute current op is %d \n", process->cycle_to_execute);
        printf("|||||||||||||||||||||||||||||||||||||||\n\n");


        temp = temp->next;
    }
//    exit(0);
}