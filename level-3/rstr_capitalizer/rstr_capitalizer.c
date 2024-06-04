#include <unistd.h>
#include <stdio.h>

void to_lower(char *s)
{
    int i;
    i = 0;
    while(s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] +=32;
        i++;
    }
}
void rstr(char *s)
{
    int i = 0;
    int c = 0;
    int j;
    while(s[i])
    {
        if (s[i] == ' ' || s[i] == '\t')
            c = 0;
        else if (c == 0)
        {
            j = 0;
            while((s[i + j] >= 'a' && s[i + j] <= 'z'))
                j++;
            if (j > 0  && (s[i + j] == ' ' || s[i + j] == '\t' || s[i + j] == 0))
            {
                j--;
                s[i + j] -= 32;
            }
            c = 1;
        }
        write(1,&s[i],1);
        i++;
    }
    
}
int main(int ac, char **av)
{
    int i = 1;
    if (ac > 1)
    {
        while(i < ac)
        {
            to_lower(av[i]);
            rstr(av[i]);
            if (i + 1 != ac)
                write(1,"\n",1);
            i++;
        }
    }
    write(1,"\n",1);
    return 0;
}