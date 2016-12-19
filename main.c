#include <stdio.h>
#include <stdlib.h>

int a;

void ordenar (int N, float *x);

float
modulo (float x, int b)
{
  x = x / b;
  x = x - (int) x;

  return x;
}

float
promediar_columnas_pares (int N, float mat[N][N])
{

  int i;
  int j;
  int b = 0;
  float r = 0;

  for (i = 0; i < N; i = i + 1)
    {
      if (modulo (i, 2) == 0)
	{
	  for (j = 0; j < N; j = j + 1)
	    {
	      r = r + mat[i][j];
	      b = b + 1;

	    }
	}
    }

  r = r / b;

  return r;
}

float
promediar_diagonales (int N, float mat[N][N])
{

  int i;
  int j;
  int b = 0;
  float r = 0;

  for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
	{
	  if (i == j)
	    {
	      r = r + mat[i][j];
	      b = b + 1;
	    }
	}
    }

  r = r / b;

  return r;
}

void
llenar_mat (int N, float mat[5][5], float *datos)
{

  int i = 0;
  int j = 0;
  int b = N * N * a;

  for (i = 0; i < N; i = i + 1)
    {
      for (j = 0; j < N; j = j + 1)
	{
	  mat[i][j] = *(datos + b);
	}
    }
}

void
extra (float *datos, int N)
{
  int i;
  a = 0;
  float *x = 0;
  float mat[N][N];

  for (i = 0; i < 8; i = i + 1)
    {
      *(datos + i) = i;
    }

  for (i = 0; i < N; i = i + 1)
    {
      llenar_mat (N, mat, datos);
      *(x + i) =
	promediar_columnas_pares (N, mat) - promediar_diagonales (N, mat);
      a = a + 1;
    }

  ordenar (N, x);

  for (i = 0; i < N; i = i + 1)
    {
      printf ("%f", *(x + i));
    }
}

void
ordenar (int N, float *x)
{

  int i;
  int j;
  float aux;

  for (i = 0; i < N; i = i + 1)
    {
      for (j = 0; j < N; j = j + 1)
	{
	  if (*(x + i) < *(x + j))
	    {
	      aux = *(x + j);
	      *(x + j) = *(x + i);
	      *(x + i) = aux;
	    }
	}
    }
}

int
main ()
{
  int N = 2;
  float *datos = (float *) malloc (N * N * N * sizeof (float));
  extra (datos, N);
  free (datos);
}
