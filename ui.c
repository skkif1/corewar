#include "op.h"


int g_mem_row_len = 64 * 3;
int g_mem_col_len = MEM_SIZE / 64;

static int colors[MEM_SIZE];
static WINDOW *memory;
static WINDOW *stat;

WINDOW *create_memory_window() {

    WINDOW *wraper = newwin(g_mem_col_len + 2, g_mem_row_len + 2, MARGIN, MARGIN);
    WINDOW *memory = newwin(g_mem_col_len, g_mem_row_len, MARGIN + 1, MARGIN + 1);
    wrefresh(wraper);
    wrefresh(memory);
    return memory;
}

WINDOW *create_stat_window() {

    WINDOW *wrapper = newwin(g_mem_col_len + 2, 60, MARGIN, g_mem_row_len + 10);
    WINDOW *stat = newwin(g_mem_col_len - 2, 60 - 2, MARGIN + 1, g_mem_row_len + 11);
    wrefresh(wrapper);
    wrefresh(stat);
    return stat;
}


void register_color_changes(int start, int len, int color) {
    int i = 0;

    while (i < len) {
        colors[start + i] = color;
        i++;
    };
}


void rewrite_memory(unsigned char *buff) {

    if (!g_env->vis)
        return;
    wmove(memory, 0, 0);
    int i = 0;
    while (i < MEM_SIZE) {
        if (colors[i] > 1000) {
            wattron(memory, COLOR_PAIR(colors[i] / 1000 + 1));
            wprintw(memory, "%.2X", buff[i]);
            wattroff(memory, COLOR_PAIR(colors[i] / 1000 + 1));
            wprintw(memory, " ");
            colors[i] = colors[i] % 1000;
        } else {
            wattron(memory, COLOR_PAIR(colors[i]));
            wprintw(memory, "%.2X", buff[i]);
            wattroff(memory, COLOR_PAIR(colors[i]));
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
        colors[i++] = 2;
}

void init_screen() {
    initscr();
    signal(SIGWINCH, NULL);
    init_def_color();
    chtype background = '.' | COLOR_PAIR(1);
    bkgd(background);
    refresh();
    memory = create_memory_window();
    stat = create_stat_window();
}

void place_cursor(t_process *process) {

    colors[process->counter] = process->color * 1000 + colors[process->counter];
}

void dell_window() {
    delwin(memory);
    delwin(stat);
    endwin();
}



