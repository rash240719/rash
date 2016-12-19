#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a;

void
print_row (int M, int j, int matriz[M][M])
{
  int i = 0;

  for (i = 0; i < M; i++)
    {
      printf ("%d ", matriz[i][j]);
    }
}

void
print_mat (int M, int matriz[M][M])
{

  int j = 0;

  printf ("\n");

  for (j = 0; j < M; j++)
    {
      print_row (M, j, matriz);
      printf ("\n");
    }
}

int
calc_det2x2 (int matrix[2][2])
{

  int r = 0;

  r = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

  return r;
}


int
calc_det3x3 (int matrix[3][3])
{

  int i = 0;
  int r = 0;
  int matrix2[2][2];

  for (; i < 3; i++)
    {
      matrix2[0][0] = matrix[1][1];
      matrix2[1][0] = matrix[1][2];
      matrix2[0][1] = matrix[1][1];

      r += pow(-1, i % 2) * matrix[0][i] * calc_det2x2 (matrix2);
      /*
      printf("\nr += pow(-1, %d mod 2) * matrix[0][%d] * calc_det2x2(matrix2)", i, i);
      printf("\nr += %d * %d * %d", (int) pow(-1, i % 2), matrix[0][i], calc_det2x2(matrix2));
      printf("\nr = %d", r);
      */
    }
}

void
reduce_mat (int M, int mat[M][M], int mat3[3][3])
{

  mat3[0][0] = mat[0][M - 2];
  mat3[1][0] = mat[1][M - 2];
  mat3[2][0] = mat[2][M - 2];

  mat3[0][1] = mat[0][M - 1];
  mat3[1][1] = mat[1][M - 1];
  mat3[2][1] = mat[2][M - 1];

  mat3[0][2] = mat[0][M];
  mat3[1][2] = mat[1][M];
  mat3[2][2] = mat[2][M];
}

void
fill_mat (int M, int mat[M][M], int *datos)
{

  int i = 0;
  int j = 0;

  for (j = 0; j < M; j++)
    {
      for (i = 0; i < M; i++)
    	{
    	  mat[i][j] = *(datos + a);
    	  a++;
    	}
    }

  print_mat (M, mat);
}

void
operate (int N, int M, int det[N], int *datos)
{

  int matrix[M][M];
  int mat3[3][3];
  int i = 0;
  
  for (i = 0; i < N; i++)
    {
      fill_mat(M, matrix, datos);
      reduce_mat (M, matrix, mat3);
      det[i] = calc_det3x3 (mat3);
      printf("%d\n", det[i]);
    }
}

void
order(int N, int det[N]) {
  int a = 0;
  int i = 0;
  int j = 0;

  for (; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      if (det[i] < det[j]) {
        a = det[i];
        det[i] = det[j];
        det[j] = a;
      }
    }
  }
}

void
examen (int N, int M, int *datos)
{

  int i = 0;

  if (M >= 3)
    {
      int det[N];

      operate(N, M, det, datos);
      order(N, det);

      for (; i < N; i++)
      {
        printf("\n%d", det[i]);
      }
      printf("\n");
    }
}

int
main ()
{
  a = 0;
  int N = 3;
  int M = 4;
  int i = M * M * N;
  int det[M];
  int *datos = (int *) malloc (i * sizeof (int));

  for (i = 0; i < 48; i++)
    {
      *(datos + i) = -i;
    }
  
  examen(N, M, datos);
  free (datos);
  //print_mat(matrix, 3);
}
