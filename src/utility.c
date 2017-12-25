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

void type_to_size(int *mass, int dir_size)
{
	int i;

	i = 0;
	while(i < 3)
	{
		if(mass[i] == T_IND)
			mass[i] = IND_SIZE;
		else
		{
			if(mass[i] == T_DIR)
			{
				mass[i] = dir_size;
			}
		}
//
//		if (mass[i] == T_IND || mass[i] == dir_size)
//			mass[i] = (mass[i] == T_IND) ? IND_SIZE : dir_size;
//		if(mass[i] == T_DIR)
//			mass[i] = dir_size;
		i++;
	}
}

void invalid_coding_byte(const int *arg_type, t_process *process, int param_count)
{
    if(param_count == 2)
    {
        if(arg_type[0] == 0 && arg_type[1] == 0)
        {
            process->counter += 2;
        } else
        {
            process->counter += arg_type[0] + arg_type[1] + 2;
        }
    }
    else if(arg_type[0] == 0 && arg_type[1] == 0 && arg_type[2] == 0 )
    {
        process->counter += 2;

    } else
    {
        process->counter += arg_type[0] + arg_type[1] + arg_type[2] + 2;
    }

}

int validate_reqistry(int value)
{
	if(value > 0 && value <= 16)
		return 1;
	return 0;
}