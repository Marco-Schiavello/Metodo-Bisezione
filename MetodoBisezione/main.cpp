#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

float toDeg(float x){return (M_PI*x)/180;}

float f(float x)
{
  /*return pow(x,3) + (-17*pow(x,2)) + (14*x) + 32;*/
  return sin(toDeg(x)) - (2*cos(toDeg(x)));
}

float absFloat(float num)
{
  if(num < 0)
    return num*=-1;
  else
    return num;
}

int main()
{
  float max,min,medio,tol;
  printf("metti limite minimo : ");
  scanf("%f",&min);
  printf("metti limite massimo : ");
  scanf("%f",&max);
  printf("metti tolleranza : ");
  scanf("%f",&tol);
  if(min>max)
    printf("valore minimo maggiore del massimo errore!");
  else if((f(min)>0 && f(max)>0) ||  (f(min)<0 && f(max)<0))
  {
    printf("non ci possono essere x valide ");
  }
  else
  {
    int nIte = 0;
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| Passo |  x_sinistro  |  f(x_sinistro)  |   x_destro   |  f(x_destro)  |   x_medio   |  f(x_medio)  |  intervallo  | \n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    medio = (min+max)/2;
    printf("| %5d | %12.6f | %15.6f | %12.6f | %13.6f | %11.6f | %12.6f | %12.6f | \n",
    ++nIte,min,f(min),max,f(max),medio,f(medio),absFloat(max-min));
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    do
    {
      if(f(medio) > 0)
        max = medio;
      else
      {
        if(f(medio) == 0)
          break;
        else
          min = medio;
      }
      medio = (min+max)/2;

      printf("| %5d | %12.6f | %15.6f | %12.6f | %13.6f | %11.6f | %12.6f | %12.6f | \n",
      ++nIte,min,f(min),max,f(max),medio,f(medio),absFloat(max-min));
      printf("---------------------------------------------------------------------------------------------------------------------\n");
    }
    while(absFloat(max-min) > tol);
  }
}
