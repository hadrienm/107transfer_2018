/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(tests, isneg_test, .init = redirect_all_stdout)
{
    cr_assert_eq(comparateur("coucou", "coucou"), 0);
    cr_assert_eq(comparateur("coaucou", "coucou"), 1);
    cr_assert_eq(verify_h("-h"), 1);
    cr_assert_eq(verify_h("-jetebaise"), 0);
}
