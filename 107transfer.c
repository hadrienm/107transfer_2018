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

void calcul(int **tab, int **taille, double **resultat, int ac)
{
    for (int i = 0; i != ac; ++i)resultat[i][0] = 1;
    int place = ac - 2;
    int k = 0;
    int save = 0;
    for (float i = 0.000; i != 1; i += 0.001) {
        save = taille[place][0];
        for (k = 0; k != taille[place][0]; k++) {
            resultat[place][0] *= i;
            resultat[place][0] += (double)(tab[place][save]);
            save--;
        }
        printf("%g %0.5f\n", i, resultat[place]);
        place--;
    }
}

int main(int ac, char **av)
{
    int save_ac = ac;
    int k = 0;
    int place = 0;
    int i = 0;
    int **tab = malloc(sizeof(int *) * (ac + 1));
    int **taille = malloc(sizeof(int *) * (ac + 1));
    double **resultat = malloc(sizeof(double) * (ac + 1));
    if (ac == 2 && verify_h(av) == 1)return 0;
    for (int i = 1; i != ac; i++)for (int j = 0; av[i][j] != '\0'; j++)if (av[i][j] > 57 || av[i][j] < '*')return 84;
    for (i = 1; i != ac; i++) {
        place = 0;
        for (k = 0; av[i][k] != '\0'; k++);
        tab[i - 1] = malloc(sizeof(int) * (k + 1));
        taille[i - 1] = malloc(sizeof(int) * (2));
        resultat[i - 1] = malloc(sizeof(double) * (2));
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] <= 57 && av[i][j] >= 48) {
                tab[i - 1][place] = (av[i][j] - 48);
                taille[i - 1][0] = (place + 1);
                place++;
            }
        }
    }
    tab[i - 1] = NULL;
    taille[i - 1] = NULL;
    ac--;
    calcul(tab, taille, resultat, ac);
}