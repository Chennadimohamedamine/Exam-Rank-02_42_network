#include <unistd.h>
void alpha(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'a')
        i++;
    }
}
int main(int ac, char **av)
{
    if (ac == 2)
        alpha(av[1]);
    write(1, "\n", 1);
    return 0;
}