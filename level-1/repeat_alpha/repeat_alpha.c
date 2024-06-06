#include <unistd.h>
int reapt(char c)
{
    int i = 0;
    char *s = "abcdefghijklmnopqrstuvwxyz";
    char *s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (s[i] && s1[i])
    {
        if (s[i] == c || s1[i] == c)
            break;
        i++;
    }
    return i;
}
int main(int ac, char **av)
{
    int i = 0;
    int c = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if ((av[1][i] >= 'a' && av[1][i] <= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
            {
                c = reapt(av[1][i]);
                while (c >= 0)
                {
                    write(1, &av[1][i], 1);
                    c--;
                }
            }
            else
                    write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
