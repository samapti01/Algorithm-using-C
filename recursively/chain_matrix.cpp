/***************
NAME-SAMAPTI CHAR
PROG-CHAIN MATRIX
****************/
#include <stdlib.h>
#include<limits.h>
#include <stdio.h>
 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
#include <limits.h>
#include <stdio.h>
int MatrixChainOrder(int p[], int n)
{
 
    /* For simplicity of the program,
       one extra row and one
       extra column are allocated in m[][]. 
       0th row and 0th
       column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
   for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}
// Driver code
int main()
{
    int *arr,n,i;
    printf("enter total no of matrix");
    scanf("%d",&n);
   arr=(int*)calloc(n,sizeof(int));
    printf("Enter values of rows in every matrix");
    	for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
  printf("Minimum number of multiplications is %d ",MatrixChainOrder(arr, n));
    return 0;
}
