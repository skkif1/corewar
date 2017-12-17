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
	process->name = strdup((const char *) player->player_name);
    process->current_op = 0;
	process->say_live = 0;
    process->cycle_to_execute = 0;
	process->id = g_id++;
    process->player_num = player->player_number;
    process->is_child = 0;
    ft_lstadd(&g_env->processes, ft_lstnew(process, sizeof(t_process)));
	g_env->process_number++;
	free(process);
};


void reset_process(t_process* process)
{
	t_player *player;


	process->live = 0;
	//process->carry = 0;
	process->say_live = 0;
	player = find_player(process->registers[1]);
    if(player != NULL)
        player->live_in_period = 0;
}

//void delete_node(t_list **head_ref, unsigned int key)
//{
//
//	t_list *temp;
//	t_list *prev;
//	temp = *head_ref;
//
//	if(!temp)
//		return;
//	if(((t_process*)temp->content)->id == key)
//	{
//		*head_ref = temp->next;
//	} else
//	{
//		prev = temp;
//		temp = temp->next;
//		while(temp)
//		{
//			if(((t_process*)temp->content)->id == key)
//			{
//				prev->next = temp->next;
//				g_env->process_number--;
//				return;
//			}
//			temp = temp->next;
//		}
//	}
//}


void delete_node(t_list **lst, unsigned int id)
{
	// When node to be deleted is head node

	t_list *head = *lst;
	t_list *temp;

		if (((t_process *) head->content)->id == id) {
			if (head->next == NULL) {
				*lst = NULL;
				g_env->process_number--;
				return;
			}

			/* Copy the data of next node to head */
			head->content = head->next->content;

			// store address of next node
			temp = head->next;

			// Remove the link of next node
			head->next = head->next->next;

			// free memory
			free(temp);

			return;
		}


		// When not first node, follow the normal deletion process

		// find the previous node
		temp = head;
		while (temp->next != NULL && ((t_process *) temp->next->content)->id != id) {
			temp = temp->next;
		}

		// Check if node really exists in Linked List
		if (temp->next == NULL) {
			return;
		}

		// Remove node from Linked List
		temp->next = temp->next->next;
		g_env->process_number--;
}