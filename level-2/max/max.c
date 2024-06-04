int             max(int* tab, unsigned int len){
    int i;
    int m;

    if (len == 0)
        return (0);
    i = 0;
    m = tab[i];
    while(i < len)
    {
        if ( m < tab[i])
            m = tab[i];
        i++;
    }
    return m;
}