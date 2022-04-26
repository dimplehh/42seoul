#include "header.h"
#include <ctype.h>

int isNumber(int argc, char* argv)
{
    int j;

    j = 0;
    while (j < strlen(argv))
    {
        if (!isdigit(argv[j]))
            if (!(argv[0] == '+' || argv[0] == '-'))
                return (0);
        j++;
    }
    return (1);
}

int isInt(int argc, char* argv)
{
    if (atol(argv) != atoi(argv))
        return (0);
    return (1);
}

int isDuple(int argc, char** argv)
{
    int i = 1;
    int j = 2;
    while (i < argc)
    {
        j = i+1;
        while (j < argc)
        {
            if(atoi(argv[i]) == atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int isSort(int argc, char **argv)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
            return (0);
        i++;
    }
    return (1);
}

int check(int argc, char **argv, t_Deque *a)
{
    int i;
    int j;
    char **split;

    i = 1;
    j = 0;
    if (argc == 1)
        return (0);
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        if (split != NULL)
        {
            while (j < ft_col(argv[i] ,' '))
            {
                if (!isNumber(argc, split[j]) || !isInt(argc, split[j]))
                    return (0);
                DQAddLast(a, atoi(split[j]));
                j++;
            }
            j = 0;
        }
        i++;
    }
    return (1);
}