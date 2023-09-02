/*************************
NAME : SAMAPTI CHAR
PROGRAM :determinant matrices.
**************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int **Mem_Alloc(int n);
void input_matrix(int n,int **E);
void display_matrix(int n,int **F);
float determinent(int **A, int size);

int main()
{
    int n,**A,**B,**C;
	printf("Enter the size n*n of the matrix ");
    scanf("%d",&n);
           A=Mem_Alloc(n);
           printf("Enter the elements of matrix\n");
           input_matrix(n,A);
           printf("Print the matrix\n");
           display_matrix(n,A);
           float result = determinent(A,n);
    printf("The determinent of the matrix is %f",result);
}
int **Mem_Alloc(int n)
{
    int**D,i;
    D=(int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
        D[i]=(int*)calloc(n,sizeof(int));
    return D;
}
void input_matrix(int n,int **E)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter a[%d][%d]=",i,j);
            scanf("%d",&E[i][j]);
        }
    }
}
void display_matrix(int n,int **F)
{
    int i,j;
    printf("\n resultant matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" ");
            printf("%d",F[i][j]);
        }
        printf("\n");
    }
}
float determinent(int **A, int size)
{
    int c, **B;
    B=Mem_Alloc(size);
    float det=0,s=1;
    int i,j,m,n;
    if(size == 1)
    {
        return (A[0][0]);
    }
    else{
        det=0;
        for(c=0; c<size; c++)
        { m=0, n=0;
            for(i=0; i<size; i++)
        {
		  for(j=0; j<size; j++)
          {
		         B[i][j] = 0;
				if(i!=0 && j!=c)
                {
				  B[m][n] = A[i][j];
                   if(n<(size-2))
                        {
                            n++;
                        }
                        else
                        {
                      	   n=0;
					       m++;
                        }
                    }
            }
            }
			            det = det + s*(A[0][c]*determinent(B,size-1));
            s = -1*s;

        }
	
    }

    return (det);
}