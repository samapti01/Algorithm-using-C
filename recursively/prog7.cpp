/*************************
NAME : SAMAPTI CHAR
PROGRAM : robust to check prime no.
Program no : 07
Date :  2021.02.17
**************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void prime_upto_n(int n);
void print(int *arr, int n);


int main()
{
	int n;
	printf("Enter the limit :\t");
	scanf("%d",&n);
	prime_upto_n(n);
}

void prime_upto_n(int n)
{
	int *arr=(int*)malloc(n*sizeof(int));
	arr[0]=2;
	arr[1]=3;
	int i,j,count=1;
	for(i=5;i<=n;i+=2)
	{
		j=1;
		while(j<=sizeof(arr)/sizeof(arr[0]))
		{	
		
			if(i%arr[j]==0)
				break;
			else
				j++;
		}
		if(j==sizeof(arr)/sizeof(arr[0])+1)
			arr[++count]=i;
	}
	print(arr,count);
}

void print(int *arr, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}

