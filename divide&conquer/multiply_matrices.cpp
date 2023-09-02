//multiply matrix
#include <stdio.h>
#include<stdlib.h>
 
 
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
            printf(" ");
            printf("%d",F[i][j]);
        }
        printf("\n");
    }
}
void mat_mul(int **a, int **b, int **c,int ars,int are, int acs, int ace, int brs, int bre, int bcs, int bce)
{
    if(are-ars==1)
    {
        c[ars][bcs]+=a[ars][acs]*b[acs][bcs];
    }
    else{
        mat_mul(a,b,c,ars,(ars+are)/2,acs,(acs+ace)/2,brs,(brs+bre)/2,bcs,(bcs+bce)/2);
        mat_mul(a,b,c,ars,(ars+are)/2,(acs+ace)/2,ace,(brs+bre)/2,bre,bcs,(bcs+bce)/2);
        mat_mul(a,b,c,ars,(ars+are)/2,acs,(acs+ace)/2,brs,(brs+bre)/2,(bcs+bce)/2,bce);
        mat_mul(a,b,c,ars,(ars+are)/2,(acs+ace)/2,ace,(brs+bre)/2,bre,(bcs+bce)/2,bce); 
        mat_mul(a,b,c,(ars+are)/2,are,acs,(acs+ace)/2,brs,(brs+bre)/2,bcs,(bcs+bce)/2);
        mat_mul(a,b,c,(ars+are)/2,are,(acs+ace)/2,ace,(brs+bre)/2,bre,bcs,(bcs+bce)/2);
        mat_mul(a,b,c,(ars+are)/2,are,acs,(acs+ace)/2,brs,(brs+bre)/2,(bcs+bce)/2,bce); 
        mat_mul(a,b,c,(ars+are)/2,are,(acs+ace)/2,ace,(brs+bre)/2,bre,(bcs+bce)/2,bce);
    }
}

int main()
{
    int r1,c1,r2,c2,**A,**B,**C,n;
    printf("Enter the order of square matrix of first matrix A and of second matrix B.\n");
           scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
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
          mat_mul(A,B,C,0,r1,0,c1,0,r2,0,c2);
          printf("\n resultant matrix\n");
           display_matrix(r1,c2,C);
}

 

 
