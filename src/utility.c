#include "../includes/op.h"

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

void type_to_size(int *mass)
{
	int i;

	i = 0;
	while(i < 3)
	{
		if (mass[i] == T_IND || mass[i] == T_DIR)
			mass[i] = (mass[i] == T_IND) ? IND_SIZE : DIR_SIZE;
		i++;
	}
}