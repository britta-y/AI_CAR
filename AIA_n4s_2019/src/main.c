/*
** EPITECH PROJECT, 2020
** N4S
** File description:
** main
*/

#include "ai.h"

double turn_car(char **tab)
{
    double i = 0.0;
    double lol = atof(tab[19]);

    if (lol <= 3100 && lol > 2000)
        i = 0.0;
    if (lol <= 2000 && lol > 1500)
        i = 0.005;
    if (lol <= 1500 && lol > 1000)
        i = 0.055;
    if (lol <= 1000 && lol > 600)
        i = 0.13;
    if (lol <= 600 && lol > 200)
        i = 0.3;
    if (lol <= 200)
        i = 0.55;
    return i;
}

void speed(char **tab)
{
    char *str = NULL;
    size_t size = 0;
    double lol = atof(tab[19]);
    double i = 0.0;
    
    dprintf(1, "CAR_FORWARD:");
    if (lol > 2000)
        i = 1.0;
    if (lol > 1500 && lol <= 2000)
        i = 0.8;
    if (lol > 1000 && lol <= 1500)
        i = 0.7;
    if (lol > 800 && lol <= 1000)
        i = 0.6;
    if (lol > 500 && lol <= 800)
        i = 0.3;
    if (lol <= 500 && lol > 300)
        i = 0.3;
    if (lol <= 300)
        i = 0.2;
    dprintf(1, "%f\n", i);
    getline(&str, &size, stdin);
}

void turn_wheels(char **tab)
{
    char *str = NULL;
    size_t size = 0;
    double rotate = turn_car(tab);
    double ok = atof(tab[3]) - atof(tab[34]);
    
    dprintf(1, "WHEELS_DIR:");
    if (ok < 0)
        rotate = rotate * -1;
    dprintf(1, "%f\n", rotate);
    getline(&str, &size, stdin);
}

int get_info()
{
    char *str = NULL;
    size_t len = 0;
    int i = 0;
    char **tab = NULL;

    dprintf(1,"GET_INFO_LIDAR\n");
    if (getline(&str, &len, stdin) == -1)
        return (0);
    tab = str_to_word_array(str);
    for (; tab[i] != NULL; i++);
    if (i > 18) {
        speed(tab);
        turn_wheels(tab);
    }
    if (end_track(tab, i-2) == 0)
        return (0);
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    return (1);
}

int main(void)
{
    dprintf(1,"START_SIMULATION\n");
    dprintf(1,"CAR_FORWARD:0.8\n");
    while (1) {
        if (get_info() == 0)
            break;
    }
    printf("STOP_SIMULATION\n");
    return 0;
}
