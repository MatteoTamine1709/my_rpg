/*
** EPITECH PROJECT, 2020
** test_menu
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str) {
        if (str[i] >= '0' && str[i] <= '9') {
            result *= 10;
            result += str[i] - 48;
        } else {
            return (result);
        }
        i++;
    }
    return (result);
}