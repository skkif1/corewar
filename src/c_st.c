#include "../includes/op.h"

int validate_st(int *mass, t_process *process) {
	int i;

	i = 0;

	if (mass[0] == T_REG && (mass[1] == T_IND || mass[1] == T_REG))
		i = 1;
	type_to_size(mass, 4);
	if (!i)
    		invalid_coding_byte(mass, process, 2);
	return i;
}



void st(t_process *process) {
	int coding_byte;
	unsigned int value;
	int registry;
    int address;
    int arg_type[3];


    coding_byte = get_register(process->counter, 1);
	get_arg_types(arg_type, coding_byte);
    if (validate_st(arg_type, process))
    {
        registry = get_register(process->counter, T_REG + 1);
        if(validate_reqistry(registry))
        {
            value = big_to_little(process->registers[registry]);

            if (arg_type[1] == IND_SIZE) {
                address = bytes_to_int(process->counter + T_REG + 2, arg_type[1]);

                if(address > 32767)
                {
                    address = ((process->counter + (short)address % IDX_MOD));
                    if(address < 0)
                    {
                        address = MEM_SIZE + address;
                    }
                } else
                {
                    address = ((process->counter + address % IDX_MOD));
                }

                bytes_to_memory(address % MEM_SIZE, &value, DIR_SIZE, process->color);
            } else {
                address = get_register(process->counter, T_REG + 2);

                    process->registers[address] = value;
            }
        }
        process->counter += 2 + T_REG + arg_type[1];
    }
}