#include "op.h"

t_env g_env;

int main()
{

    init_screen();

    init_env();
    add_new_player();
    start_cycle();

    getch();
    dell_window();
}
