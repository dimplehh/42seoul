#include "header.h"
#include <ctype.h>

int isNumber(int argc, char** argv)
{
    int i = 1;
    int j;
    while (i < argc)
    {
        j = 0;
        while (j < strlen(argv[i]))
        {
            if (isdigit(argv[i][j++]) == 0)
                return 0;
        }
        i++;
    }
    return 1;
}

int isInt(int argc, char** argv)
{
    int i = 1;
    while (i < argc)
    {
        if (atol(argv[i]) != atoi(argv[i]))
            return 0;
        i++;
    }
    return 1;
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

int check(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (!isNumber(argc, argv) || !isInt(argc, argv))
    {
        printf("Error: is not int\n");
        return (0);
    }
    else if (isDuple(argc, argv))
    {
        printf("Error: number is duplicated\n");
        return (0);
    }
    if (isSort(argc, argv))
    {
        printf("OK\n");
        return (0);
    }
    return (1);
}