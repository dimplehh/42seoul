#include <stdio.h>

int main (void)
{
    int N = 0;
    int i = 0;
    int k = 0;
    int l = 0;
    int len = 0;
    int res = 0;
    int a = 1;
    char s[100];
    scanf("%d", &N);
    while (i < N && N <= 100)
    {
        s[0] = '\0';
        len = 0;
        scanf("%s", s);
        while (s[len] != '\0')
        {
            if (!('a' <= s[len] && s[len] <= 'z'))
                return (0);
            len++;
        }
        k = 0;
        a = 1;
        while (k < len)
        {
            l = k + 1;
            while (l < len)
            {
                if ((s[k] == s[l]) && l != k + 1)
                {
                    while (k < l)
                    {
                        if (s[k] != s[l])
                            a = 0;
                        k++;
                    }
                }
                l++;
            }
            k++;
        }
        res += a;
        i++;
    }
    printf("%d\n",res);
    return (0);
}