#include "my.h"

int main(int ac, char **av)
{
    int save_ac = ac;
    int k = 0;
    int place = 0;
    int i = 0;
    int **tab = malloc(sizeof(int *) * (ac + 1));
    int **taille = malloc(sizeof(int *) * (ac + 1));
    double **resultat = malloc(sizeof(double) * (ac + 1));
    if (ac == 2 && verify_h(av[1]) == 1)return 0;
    if (ac < 3)return 84;
    if (ac % 2 == 0)return 84;
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