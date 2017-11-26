#include "../includes/op.h"


static int g_colors[MEM_SIZE];
static WINDOW *memory;
static WINDOW *stat;
t_list *notifications;

WINDOW *create_memory_window() {

    WINDOW *wraper = newwin(COL_LEN + 2, ROW_LEN + 2, MARGIN, MARGIN);
    WINDOW *memory = newwin(COL_LEN, ROW_LEN, MARGIN + 1, MARGIN + 1);
    wrefresh(wraper);
    wrefresh(memory);
    return memory;
}

WINDOW *create_stat_window() {

    WINDOW *wrapper = newwin(COL_LEN + 2, 60, MARGIN, ROW_LEN + 10);
    WINDOW *stat = newwin(COL_LEN - 2, 60 - 2, MARGIN + 1, ROW_LEN + 11);
    wrefresh(wrapper);
    wrefresh(stat);
    return stat;
}


void register_color_changes(int start, int len, int color) {
    int i = 0;

    while (i < len) {
        g_colors[start + i] = color;
        i++;
    };
}

void rewrite_notification()
{
    t_list *temp;
    t_notification *not;
    temp = notifications;

    wmove(stat, 20, 0);
    while(temp)
    {
        not = temp->content;
        wattron(stat, COLOR_PAIR(not->color));
        wprintw(stat, "%s\n", not->notification);
        wattroff(stat, COLOR_PAIR(not->color));
        temp = temp->next;
    }
}

void rewrite_stat()
{
	t_list *temp;
	t_player *player;

	if (!g_env->vis)
		return;

	wmove(stat, 0, 0);
	wprintw(stat,"\n");
	wprintw(stat,"CYCLE PER SECOND: %d \n", 1000 / g_env->vis_delay);
	wprintw(stat,"CYCLE TO DIE: %d \n", CYCLE_TO_DIE);
	wprintw(stat,"CYCLE DELTA: %d \n", CYCLE_DELTA);
	wprintw(stat,"NBR LIVE: %d \n\n", NBR_LIVE);
	wprintw(stat,"PROCESSES: %d \n\n", lst_size(g_env->processes));
	wprintw(stat,"CYCLE: %u\n\n", g_env->cycle);
    wprintw(stat,"PLAYERS:\n");
    temp = g_env->players;
	while (temp)
	{
		player = temp->content;
		wattron(stat, COLOR_PAIR(player->color));
		wprintw(stat, "name: %s\n", player->player_name);
		wattroff(stat, COLOR_PAIR(player->color));
		wprintw(stat, "     last live: %d\n", player->last_live);
		wprintw(stat, "     lives in curent period: %d\n", player->live_in_period);
		temp = temp->next;
	}
    wprintw(stat, "\nLEGEND:\n   w - start/stop\n   s - increase speed\n   a - decrease speed\n");
    rewrite_notification();
	wrefresh(stat);
}



void add_notification(char *info, t_process *process)
{
    t_notification *notification;

    notification = malloc(sizeof(t_notification));
    notification->color = process->color;
    notification->notification = info;
    ft_lstadd(&notifications, ft_lstnew(notification, sizeof(t_notification)));
}

void rewrite_memory(unsigned char *buff) {

    if (!g_env->vis)
        return;
    wmove(memory, 0, 0);
    int i = 0;
    while (i < MEM_SIZE) {
        if (g_colors[i] > 1000) {
            wattron(memory, COLOR_PAIR(g_colors[i] / 1000 + 1));
            wprintw(memory, "%.2X", buff[i]);
            wattroff(memory, COLOR_PAIR(g_colors[i] / 1000 + 1));
            wprintw(memory, " ");
            g_colors[i] = g_colors[i] % 1000;
        } else {
            wattron(memory, COLOR_PAIR(g_colors[i]));
            wprintw(memory, "%.2X", buff[i]);
            wattroff(memory, COLOR_PAIR(g_colors[i]));
            wprintw(memory, " ");
        }
        i++;
    }
    wrefresh(memory);
}

void init_def_color() {
    int i = 0;

    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK); // frame color
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // initial field color
    init_pair(3, COLOR_GREEN, COLOR_BLACK); // player 1 color
    init_pair(4, COLOR_BLACK, COLOR_GREEN); // player 1 cursor color
    init_pair(5, COLOR_RED, COLOR_BLACK); // player 2 color
    init_pair(6, COLOR_BLACK, COLOR_RED); // player 2 cursor color
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK); // player 3 color
    init_pair(8, COLOR_BLACK, COLOR_MAGENTA); // player 3 cursor color
    init_pair(9, COLOR_YELLOW, COLOR_BLACK); // player 4 color
    init_pair(10, COLOR_BLACK, COLOR_YELLOW); // player 4 cursor color
    init_pair(11, COLOR_BLUE, COLOR_BLACK); // player 5 color
    init_pair(12, COLOR_BLACK, COLOR_BLUE); // player 5 cursor color
    init_pair(13, COLOR_CYAN, COLOR_BLACK); // player 6 color
    init_pair(14, COLOR_BLACK, COLOR_CYAN); // player 6 cursor color

    while (i < MEM_SIZE)
        g_colors[i++] = 2;
}

void init_screen() {
    initscr();
    signal(SIGWINCH, NULL);
    init_def_color();
    chtype background = '.' | COLOR_PAIR(1);
    bkgd(background);
    curs_set(0);
    refresh();
    memory = create_memory_window();
    stat = create_stat_window();
}

void place_cursor(t_process *process)
{
    g_colors[process->counter] = process->color * 1000 + g_colors[process->counter];
}


void dell_window() {
    delwin(memory);
    delwin(stat);
    endwin();
}


void pause_war()
{
    int button;

    while(1)
    {
        button = getch();
        if (button == 119)
        {
            g_env->vis_run = 1;
            return;
        }
        move(0,0);
    }
}

int manage_ui()
{
    int button;
    static int per_second;

    if (!g_env->vis)
        return 1;

    if (!g_env->vis_run)
        pause_war();

    move(0,0);
    timeout(g_env->vis_delay);
    button = getch();
    attron(COLOR_PAIR(1));
    printw("...........");
    attroff(COLOR_PAIR(1));

    if (button == 119)
	{
		g_env->vis_run = 0;
		return 0;
	}
    if (button == 115)
    {
		per_second = (per_second == 100) ? 100 : ++per_second;
        g_env->vis_delay = 1000 / per_second;
    } else
    if (button == 97)
    {
        per_second = (per_second == 1) ? 1 : --per_second;
        g_env->vis_delay = 1000 / per_second;
    } else if (button == 27 && getch() != 91)
	{
            dell_window();
            printf("%d\n" , button);
            exit(0);
	}
	return 1;
}


void hold_ui()
{
	while (1)
	{
		manage_ui();
	}
}

