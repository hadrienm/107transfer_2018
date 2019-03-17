/*
** EPITECH PROJECT, 2019
** 107transfer
** File description:
** 107transfer
*/

#include "my.h"

int verify_h(char *av)
{
    if (strlen(av) == 2 && av[0] == '-' && av[1] == 'h') {
        printf("USAGE\n    ./107transfer [num den]*\n\nDESCRIPTION\n    num     polynomial numerator defined by its coefficients\n    den     polynomial denominator defined by its coefficients\n");
        return 1;
    }
    return 0;
}

char *lol(char *str, char *res, double resu, int sig)
{
    char print[50];
    if (res[sig] >= 53) {
        resu += 0.00001;
        sprintf(print, "%0.10f", resu);
    }
    else return str;
    double resul = 0;
    int i = 0;
    int save = 1000;
    for (;  i != save && res[i] != '\0'; i++) {
        if (res[i] == '.')save = (i + 6);
    }
    str = malloc(sizeof(char) *(i + 1));
    i = 0;
    for (;  i != save && res[i] != '\0'; i++) {
        str[i] = res[i];
    }
    resul = atof(res);
    sprintf(print, "%0.5f", resul);
    for (i = 0;  i != save && print[i] != '\0'; i++)
        str[i] = print[i];
    return str;
}

char *print_until_comma(char *str, char *res, double resu)
{
    double resul = 0;
    char print[50];
    int i = 0;
    int save = 1000;
    for (;  i != save && res[i] != '\0'; i++) {
        if (res[i] == '.')save = (i + 6);
    }
    str = malloc(sizeof(char) *(i + 1));
    i = 0;
    for (;  i != save && res[i] != '\0'; i++) {
        str[i] = res[i];
    }
    resul = atof(res);
    sprintf(print, "%0.5f", resul);
    for (i = 0;  i != save && print[i] != '\0'; i++)
        str[i] = print[i];
    str = lol(str, res, resu, i);
    return str;
}

int comparateur(char *str, char *str2)
{
    if (strlen(str) != strlen(str2))return 1;
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] != str2[i])return 1;
    return 0;
}

void calcul(int **tab, int **taille, double **resultat, int ac)
{
    char *str = NULL;
    char print[50];
    int place = ac - 1;
    double divideur = 1;
    double save = 0;
    int height = 0;
    double res = 0;
    double resu = 0;
    for (int i = 0; i != ac; ++i)resultat[i][0] = 1;
    for (double i = 0.000; i <= 1.001; i += 0.001) {
        divideur = 1;
        for (; place != -1; place--) {
            height = taille[place][0] - 1;
            for (int k = 0; k != height + 1; height--) {
                if (divideur != 0) {
                    resultat[place][0] = (double)((tab[place][height] / divideur));
                    save = resultat[place][0];
                    res *= i;
                    res += save;
                    save = 0;
                }
            }
            divideur = res;
            resu = res;
            res = 0;
        }
        sprintf(print, "%0.10f", resu);
        str = print_until_comma(str, print, resu);
        if (comparateur(str, "-0.00000") == 0)printf("%0.3f -> %0.5f\n",i, 0.000000);
        else if (divideur != 0)printf("%0.3f -> %s\n", i, str);
        else printf("%0.3f -> %0.5f\n",i, 0.000000);
        if (place <= -1)place = ac -1;
        res = 0;
        save = 0;
    }
}
