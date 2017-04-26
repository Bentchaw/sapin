#include <stdio.h>
#include <stdlib.h>

#define BASE 3

void	sapin(int);
void	trunk(int, int);
int	last(int , int, int);
void	triangle(int , int, int);

int	my_putchar(char c)
{
  write(1, &c, 1);
}

void	sapin(int size)
{
  int	i;
  int	start;
  int	basenew;
  int	ajout;
  int	decale;
  int	lastline;
  
  i = 1;
  start = 0;
  ajout = 2;
  lastline = last(i,size,start);
  while (i <= size)
    {
      basenew = BASE + i + start;
      decale = basenew - lastline;
      triangle(basenew, start, decale);
      start = start + ajout;
      i++;   
      if (i % 2 == 0)
	ajout++;
    }
  trunk(size, lastline);  
}

void	trunk(int size, int lastline)
{
  int	nb;
  int	start;
  int	sizetemp;
  int	space;

  sizetemp = size;
  nb = 0;
  start = 0;
  space = 1;
  if (size % 2 == 0)  // pair
    size++;
  while (start < sizetemp)
    {
      while (nb < size)
	{
	  while (space < lastline-(size/2))
	    {
	      my_putchar(' ');
	      space++;
	    }
	  my_putchar('|');
	  nb++;
	}
      my_putchar('\n');
      start++;
      space = 1;
      nb = 0;
    }
}

int	last(int i, int size, int start)
{
  int	basenew;
  int	ajout;
  int	decale;
  
  i = 1;
  start = 0;
  ajout = 2;
  while (i <= size)
    {
      basenew = BASE + i + start;
      start = start + ajout;
      i++;   
      if (i % 2 == 0)
	ajout++;
    }
  return (basenew);
}

void	triangle(int size, int start, int decale)
{
  int	i;
  int	j;
  int	k;
  
  i = start; // premier tour 
  j = 0;
  k = 0;
  while (i < size) // saut de ligne
    {
      while (j < size - k + i - decale) // etoile
	{
	  while (k < size - 1 - i - decale) // vide
	    {
	      my_putchar(' ');	      
	      k++;
	    }
	  my_putchar('*');
	  j++;
	}
      my_putchar('\n');
      i++;
      j = 0;
      k = 0;
    } 
}
/*
int	main(int argc, char **argv)
{
  sapin(atoi(argv[1]));
}
*/
