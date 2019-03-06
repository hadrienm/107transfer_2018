/*
** EPITECH PROJECT, 2019
** 107transfer
** File description:
** 107transfer
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int verify_h(char **av)
{
    if (strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n    ./107transfer [num den]*\n\nDESCRIPTION\n    num     polynomial numerator defined by its coefficients\n    den     polynomial denominator defined by its coefficients\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int k = 0;
    int place = 0;
    int i = 0;
    int **tab = malloc(sizeof(int *) * (ac + 1));
    if (ac == 2 && verify_h(av) == 1)return 0;
    for (int i = 1; i != ac; i++)for (int j = 0; av[i][j] != '\0'; j++)if (av[i][j] > 57 || av[i][j] < '*')return 84;
    for (i = 1; i != ac; i++) {
        place = 0;
        for (k = 0; av[i][k] != '\0'; k++);
        tab[i - 1] = malloc(sizeof(int) * (k + 1)); 
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] <= 57 && av[i][j] >= 48) {
                tab[i - 1][place] = (av[i][j] - 48);
                place++;
            }
        }
    }
    tab[i - 1] = NULL;
}