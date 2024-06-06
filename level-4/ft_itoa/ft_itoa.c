#include <stdlib.h>

int count_number(int n)
{
    int c = 0;
    if (n == 0)
        return 1;
    if (n < 0)
    {
        c++;
        n *= -1;
    }
    while (n != 0)
    {
        n /=10;
        c++;
    }
    return c;
}
char    *ft_itoa(int nbr)
{
    int len = count_number(nbr);
    int i = 0;
    char *s;
    if (nbr < 0)
    {
        i = 1;
        nbr *= -1;
    }
    s = malloc(len + 1);
    s[len--] = 0;
    while (len >= 0)
    {
        s[len] = (nbr % 10) + '0';

        nbr /= 10;
        if (len == 0 && i == 1)
        {
            s[len] = '-';
            break;
        }
        len--;
    }
     
    return s;
}