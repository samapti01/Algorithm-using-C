/*************************
NAME : SAMAPTI CHAR
PROGRAM :add two matrices iterative.
Program no : 03
Date :  2021.02.17
**************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int **Mem_Alloc(int r,int c);
void input_matrix(int r,int c,int **E);
void display_matrix(int r,int c,int **F);
void Add_matrix(int **A,int **B,int **C,int r,int c);

int main()
{
    int r1,c1,r2,c2,**A,**B,**C, i=0,j=0;
    step1: printf("Enter the order of first matrix A and the order of second matrix B.\n");
           scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
           if(r1!=r2||c1!=c2)goto step1;
           A=Mem_Alloc(r1,c1);
           B=Mem_Alloc(r2,c2);
           C=Mem_Alloc(r1,c1);
           printf("Enter the elements of first matrix\n");
           input_matrix(r1,c1,A);
           printf("Enter the elements of second matrix\n");
           input_matrix(r2,c2,B);
           printf("Print the first matrix\n");
           display_matrix(r1,c1,A);
           printf("Print the second matrix\n");
           display_matrix(r2,c2,B);
           Add_matrix(A,B,C,r1,c1);
           display_matrix(r1,c1,C);
           return 0;
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
void Add_matrix(int **A,int **B,int **C,int r,int c)
{
	int i,j;
	for (i= 0; i < r; i++)  
    {  
        for (j = 0; j < c; j++)  
        {  
            C[i][j] = A[i][j] + B[i][j];  
        }  
        printf("\n");  
    }  
    printf("Resultant matrix\n");
	}

