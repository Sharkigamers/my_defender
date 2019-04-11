/*
** EPITECH PROJECT, 2019
** defender
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h"))
        write(1, "It's a Trap!\n", 13);
    defender();
    return (0);
}
