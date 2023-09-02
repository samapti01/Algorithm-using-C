/*************************
NAME : SAMAPTI CHAR
PROGRAM :MAX HEAP
**************************/
#include <stdio.h>
#include<stdlib.h>
 void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
  }
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
 
// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
    printf("Array representation of Heap is:\n");
 
    for (int i = 0; i < n; ++i)
         printf( "%d ",arr[i]);
    printf( "\n");
}
 
// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    //             1
    //           /    \
    //         3        5
    //       /  \     /  \
    //     4      6  13  10
    //    / \    / \
    //   9   8  15 17
   int *arr,n,i;
   printf("Enter total element in the tree");
   scanf("%d",&n);
   arr=(int*)calloc(n,sizeof(int));
   printf("Enter the numbers");
   for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
   buildHeap(arr,n);
 
    printHeap(arr,n);
    // Final Heap:
    //              17
    //            /    \
    //          15      13
    //         /  \     / \
    //        9     6  5   10
    //       / \   / \
    //      4   8 3   1
 
    return 0;
}
