#include "euclides.h"
#include <stdio.h>

long int euclides(long int a, long int b)
{
  __int128_t d1 = b*b, t1 = 1, s1 = 0, d2 = a, t2 = 0, s2 = 1, temp = 0;

  while (d1 != 0 && d2 != 0)
  {
    temp = d2 / d1;
    d2 -= temp * d1;
    t2 -= temp * t1;    
    s2 -= temp * s1;

    if (d1 != 0 && d2 != 0)
    {
      temp = d1 / d2;
      d1 -= temp * d2;
      t1 -= temp * t2;
      s1 -= temp * s2;
    }
  }

  // Verifica se o inverso multiplicativo é negativo.
  if (d1 == 0)
  {
    if (t2 < 0)
      t2 += a;
    return t2;
  }
  else
  {
    if (t1 < 0)
      t1 += a;
    return t1;
  }
}
