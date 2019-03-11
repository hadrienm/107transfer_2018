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
    int place = ac - 1;
    double save = 0;
    int height = 0;
    double res = 0;
    for (int i = 0; i != ac; ++i)resultat[i][0] = 1;
    for (double i = 0.000; i <= 1; i += 0.001) {
        for (; place != -1; place--) {
            height = taille[place][0] - 1;
            for (int k = 0; k != height + 1; height--) {
                resultat[place][0] = (double)(tab[place][height] * i);
                save = resultat[place][0];
                res += save;
                save = 0;
            }
            printf("%g %f\n", i, res);
            res = 0;
        }
        if (place <= -1)place = ac -1;
        res = 0;
        save = 0;
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
        resultat[i - 1] = malloc(sizeof(double) * (3));
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] <= 57 && av[i][j] >= 48) {
                tab[i - 1][place] = (av[i][j] - 48);
                place++;
            }
        }
        taille[i - 1][0] = place;
    }
    tab[i - 1] = NULL;
    taille[i - 1] = NULL;
    resultat[i - 1] = NULL;
    ac--;
    calcul(tab, taille, resultat, ac);
}