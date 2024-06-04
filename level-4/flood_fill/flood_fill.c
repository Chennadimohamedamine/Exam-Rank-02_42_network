 typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
void exet(char **ar,t_point size,t_point c,char f)
{
    if (c.x < 0 || c.y < 0 ||  c.x >= size.x || c.y >= size.y || ar[c.y][c.x] != f)
        return ;
    ar[c.y][c.x] = 'F';
    exet(ar,size,(t_point){c.x + 1,c.y},f); 
    exet(ar,size,(t_point){c.x - 1,c.y},f); 
    exet(ar,size,(t_point){c.x,c.y + 1},f); 
    exet(ar,size,(t_point){c.x,c.y - 1},f); 
}
void	flood_fill(char **tab, t_point size, t_point begin)
{
	exet(tab,size,begin,tab[begin.y][begin.x]);
}  