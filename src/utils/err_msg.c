#include "utils.h"

int err_msg_code(char *str, int n)
{
    if (str)
        ft_putstr_fd(str, 1);
    return (n);
}