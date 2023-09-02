/*********************
Name:-Samapti Char
prog:-bubble sort
**********************/
#include <stdio.h>
#include<stdlib.h>
void recurbublSort(int arr[], int len){
   int temp;

   if (len == 1){
      return;
   }
   for (int i=0; i<len-1; i++){
      if (arr[i] > arr[i+1]){
         temp=arr[i];
         arr[i]=arr[i+1];
         arr[i+1]=temp;
      }
   }
   len=len-1;
   recurbublSort(arr, len);
}
int main(){
   int *Arr,n;
   printf("Enter total no. in the list");
   scanf("%d",&n);
   Arr=(int*)calloc(n,sizeof(int));
   printf("Enter the numbers");
   for(int i=0;i<n;i++)
   scanf("%d",&Arr[i]);
   recurbublSort(Arr,n);
   printf("Sorted array : ");
   for(int i=0;i<n;i++)
   {
      printf("%d ",Arr[i]);
   }

   return 0;
}
