/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/include/fita.h
 * Path: /home/rudreais/prog/fed-in-the-abyss/include
 * Created Date: Tuesday, July 10th 2018, 1:34:37 pm
 * Author: rudreais
 *
 * Copyright (c) 2018 rudreais
 */

#pragma once

#include <ncurses.h>
#include "cursor.h"
#include "files.h"

#define N_COLS (COLS - 40) // the width
#define N_LINES (LINES - 10) // the height

/******************/
/* lib/readline.c */
/******************/
/**
 * @param file descriptor
 * @return a complete line
 * @purpose read a line until a \n or EOF is encoutered
 */
char *read_line(int fd);

/**********************/
/* src/core/gen_map.c */
/**********************/
/**
 * @param the current level of the game
 * @return nothing
 * @purpose execute the rust map generator
 */
void gen_map(int level);

/****************/
/* src/prints.c */
/****************/
/**
 * @param the current WINDOW, the char to print
 * @return nothing
 * @purpose print pretty characters using attributes from ncurses
 */
void print_charac(WINDOW *win, cursor_t *pos);

/**
 * @param the current WINDOW, the camera position, the map to print
 * @return nothing
 * @purpose print the map and refresh the screen
 */
void centered_map(WINDOW *win, cursor_t *cam, files_t *maps);

/**************/
/* src/attr.c */
/**************/
/**
 * @param nothing
 * @return nothing
 * @purpose get a good width for the main WINDOW
 */
int get_width(void);

/**
 * @param nothing
 * @return nothing
 * @purpose get a good height for the main WINDOW
 */
int get_height(void);


char **cpy_state(file_t *map);
void assign_player(char **map, char **old_state, cursor_t *charac, cursor_t *cam);

void move_charac(int key, cursor_t *pos, cursor_t *cam, char **map);

