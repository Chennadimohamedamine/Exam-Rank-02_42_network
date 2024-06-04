#include <unistd.h>

void rev_wstr(char *s)
{
    int i = 0;
    int start;
    int end;
    int f;
    while(s[i])
        i++;
    i--;
    while(i >= 0)
    {
        while(s[i] == '\t' || s[i] == ' ')
            i--;
        end = i;
        while (s[i] != '\t' && s[i] != ' ' && s[i] != '\0')
            i--;
        start = i + 1;
        f = start;
        while (start <= end)
            write(1,&s[start++],1);        
        if(f != 0)
            write(1," ",1);
    }
}
int main(int ac ,char **av)
{
    if (ac == 2)
        rev_str(av[1]);
    write(1,"\n",1);
    return 0;
}