#include "../includes/op.h"

t_env *g_env;
static unsigned int g_id;

void add_new_process(int position, t_player *player)
{

    t_process *process = NULL;

    int i;
    i = 0;

    process = (t_process*)malloc(sizeof(t_process));
    while(i < REG_NUMBER + 1)
    {
        process->registers[i] = 0;
        i++;
    }
    process->registers[1] = player->player_number;
    process->color = player->color;
    process->counter = (unsigned int) position;
    process->live = 0;
    process->current_op = 0;
    process->cycle_to_execute = 0;
	process->id = g_id++;
    ft_lstadd(&g_env->processes, ft_lstnew(process, sizeof(t_process)));
};


void reset_process(t_process* process)
{
	t_player *player;

	process->live = 0;
	process->carry = 0;
	player = find_player(process->registers[1]);
	player->live_in_period = 0;
}

void delete_node(t_list **head_ref, unsigned int key)
{

	t_list *temp;
	t_list *prev;
	temp = *head_ref;

	if(!temp)
		return;
	if(((t_process*)temp->content)->id == key)
	{
		*head_ref = temp->next;
	} else
	{
		prev = temp;
		while(temp)
		{
			if(((t_process*)temp->content)->id == key)
			{
				prev->next = temp->next;
				printf("%d\n", ((t_process*)temp->content)->id);
				return;
			}
			temp = temp->next;
		}
	}
}


