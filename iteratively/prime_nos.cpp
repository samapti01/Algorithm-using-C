// Find all prime numbers upto n

#include<stdio.h>
#include<stdlib.h>

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
	int *arr= (int*)malloc(n*sizeof(int));
	arr[0]=2;
	int i,j=0,count=1;
	for(i=3;i<=n;i+=2)
	{
		for(j=0;j<count;j++)
		{
			if(i%arr[j]==0)
				break;
		}
		if(j>=count)
			arr[count++]=i;
	}
		print(arr,count);
}

void print(int *arr, int n)
{
	int i=0;
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}

