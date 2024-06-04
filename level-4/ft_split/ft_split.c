#include <stdlib.h>
#include <stdio.h>

int cw(char *s)
{
    int i = 0;
    int c = 0;
    int c1 = 0;
    while (s[i])
    {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
            c = 0;
        else if (c == 0)
        {
            c1++;
            c = 1;
        }
        i++;
    }
    return c1;
}
char *get_word(char *s,int *p)
{
    char *s1;
    int len = 0;
    int i = 0;
    int j = 0;

    while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
            i++;
    while (s[i + len] != ' ' && s[i + len] != '\t' && s[i + len] != '\n' && s[i + len] != 0)
            len++;
    s1 = malloc(len + 1);
    if (!s1)
        return NULL;
    len += i;
    while (i != len)
    {
        s1[j++] = s[i++];
    }
    s1[j] = 0;
    *p = i;
    return s1;
}
char    **ft_split(char *str)
{
    int i = 0;
    int len = cw(str);
    int p = 0;
    char **s;

    s = malloc(sizeof(char *) * len + 1);
    if (!s)
        return NULL;
    while (i < len)
    {
        s[i] = get_word(str,&p);
        str += p;
        i++;
    }
    s[i] = 0;
    return s;
}
// int main(int ac ,char **av)
// {
//     ac = cw(av[1]);
//     printf("count word ==> %d\n",ac);
//     char **s1= ft_split(av[1]);
//     for(int i = 0;i < ac;i++)
//     {
//         printf("word == > %s\n",s1[i]);
//     }
// } 