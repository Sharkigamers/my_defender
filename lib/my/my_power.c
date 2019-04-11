/*
** EPITECH PROJECT, 2018
** my_power
** File description:
** power
*/

int my_power(int a, int c)
{
    int b = a;

    if (c == 1) {
        a = a;
    }
    if (c == 0) {
        a = 1;
    }
    while (c > 1) {
        a = a * b;
        c = c - 1;
    }
    if (c < 0) {
        a = 0;
    }
    return a;
}
