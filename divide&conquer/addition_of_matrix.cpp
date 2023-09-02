//addition of matrices
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int **Mem_Alloc(int r,int c);
void input_matrix(int r,int c,int **E);
void display_matrix(int r,int c,int **F);
void add_mat(int **a,int **b, int **c ,int rs, int re, int cs, int ce);
int main()
{
    int r1,c1,r2,c2,**A,**B,**C,n;
    printf("Enter the order of square matrix of first matrix A and of second matrix B.\n");
           scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
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
           add_mat(A,B,C,0,r1,0,c1);
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
    printf("\n resultant matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" ");
            printf("%d",F[i][j]);
        }
        printf("\n");
    }
}
void add_mat(int **a,int **b, int **c ,int rs, int re, int cs, int ce)
{
	if(re-rs==1)
		c[rs][cs]=a[rs][cs]+b[rs][cs];
	else
	{
		add_mat(a,b,c,rs,(rs+re)/2,cs,(cs+ce)/2);
		add_mat(a,b,c,rs,(rs+re)/2,(cs+ce)/2,ce);
	    add_mat(a,b,c,(rs+re)/2,re,cs,(cs+ce)/2);
		add_mat(a,b,c,(rs+re)/2,re,(cs+ce)/2,ce);
	}
		
}
