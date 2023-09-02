/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Create a binary search tree and search in preorder,postorder and inorder traversal
Program no: 11
**************************/
#include<stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *left,*right;
};
struct node *create(struct node* root,int value)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->info=value;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(value>root->info)
	root->right=create(root->right,value);
	else
	root->left=create(root->left,value);
	return root;
}
void preorder(struct node *ro)
{
	if(ro==NULL)
	return;
	printf("%d ",ro->info);
	preorder(ro->left);
	preorder(ro->right);
}
void inorder(struct node *ro)
{
	if(ro==NULL)
	return;
	inorder(ro->left);
	printf("%d ",ro->info);
	inorder(ro->right);
}
void postorder(struct node *ro)
{
	if(ro==NULL)
	return;
	postorder(ro->left);
	postorder(ro->right);
    printf("%d ",ro->info);
}
int main()
{
	int n;
	char ch;
	struct node *root=NULL;
	do{
		printf("Enter value");
		scanf("%d",&n);
		root=create(root,n);
	
	fflush(stdin);
    printf("wanna enter more!y or n\n");
    scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
	printf("preorder traversal \n");
    preorder(root);
    printf("inorder traversal \n");
    inorder(root);
    printf("postorder traversal /n");
    postorder(root);
}
