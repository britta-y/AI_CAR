/*
** EPITECH PROJECT, 2020
** end track
** File description:
** end of the track detection
*/

#include "ai.h"

int end_track(char **tab, int nb)
{
    if (strcmp(tab[nb], "Track Cleared") == 0) {
        dprintf(1, "CAR_FORWARD:0\n");
        dprintf(2, "%s\n", tab[nb]);
        while (1) {
            dprintf(1, "CAR_FORWARD:0\n");
            dprintf(1, "STOP_SIMULATION\n");
        }
        return (0);
    }
    return (1);
}
