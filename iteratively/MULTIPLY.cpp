#include<stdio.h>
/*************************
NAME : SAMAPTI CHAR
PROGRAM :Multiply two matrices iterative.
Program no : 03
Date :  2021.02.17
**************************/
#include<string.h>
#include<stdlib.h>

int **Mem_Alloc(int r,int c);
void input_matrix(int r,int c,int **E);
void display_matrix(int r,int c,int **F);
void mul_matrix(int r1,int c1,int c2,int **A,int **B,int **C);

int main()
{
    int r1,c1,r2,c2,**A,**B,**C;
    step1: printf("Enter the order of first matrix A and the order of second matrix B.\n");
           scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
           if(c1!=r2)goto step1;
           A=Mem_Alloc(r1,c1);
           B=Mem_Alloc(r2,c2);
           C=Mem_Alloc(r1,c2);
           printf("Enter the elements of first matrix\n");
           input_matrix(r1,c1,A);
           printf("Enter the elements of second matrix\n");
           input_matrix(r2,c2,B);
           printf("Print the first matrix\n");
           display_matrix(r1,c1,A);
           printf("Print the second matrix\n");
           display_matrix(r2,c2,B);
           mul_matrix(r1,c1,r2,A,B,C);
           display_matrix(r1,c2,C);
}
int **Mem_Alloc(int r,int c)
{
    int**D,i;
    D=(int**)calloc(r,sizeof(int*));
    for(i=0;i<r;i++)
        D[i]=(int*)calloc(c,sizeof(int));
    return D;
}
void input_matrix(int r,int c,int **E)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter a[%d][%d]=",i,j);
            scanf("%d",&E[i][j]);
        }
    }
}
void display_matrix(int r,int c,int **F)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",F[i][j]);
        }
        printf("\n");
    }
}
void mul_matrix(int r1,int c2,int r2,int **A,int **B,int **C)
{
   for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
 
            for (int k = 0; k < r2; k++) {
                C[i][j] += A[i][k] * B[k][j];

              }
          }
}
  printf("Resultant matrix\n");
}
