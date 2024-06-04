#include <unistd.h>

int to_int(char *s)
{
    int r = 0;
    int i = 0;
    while(s[i])
    {
        r = r * 10;
        r += (s[i] - '0');
        i++;
    }
    return (r);
}
void printstr(int i)
{
    if (i > 9)
        printstr(i / 10);
    write(1,&"0123456789"[i % 10],1);
}

void printall(int i,int n)
{
    printstr(i);
    write(1," x ",3);
    printstr(n);
    write(1," = ",3);
    printstr(i * n);
}
void tab_mult(int n)
{
    int i = 1;
    while (i <= 9)
    {
        printall(i,n);
        if (i != 9)
            write(1,"\n",1);
        i++;
    }
}
int main(int ac ,char **av)
{
    if (ac == 2)
        tab_mult(to_int(av[1]));
    write(1,"\n",1);
    return 0;
}