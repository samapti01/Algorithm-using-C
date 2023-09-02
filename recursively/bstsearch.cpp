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
struct node *insert(struct node *ptr, int ikey )
{
        if(ptr==NULL)
        {
                ptr = (struct node *) malloc(sizeof(struct node));
                ptr->info = ikey;
                ptr->left= NULL;
                ptr->right = NULL;
        }
        else if(ikey < ptr->info) /*Insertion in left subtree*/
                ptr->left = insert(ptr->left, ikey);
        else if(ikey > ptr->info) /*Insertion in right subtree */
                ptr->right = insert(ptr->right, ikey);
        else
                printf("\nDuplicate key\n");
        return ptr;
}/*End of insert( )*/
struct node *search(struct node *ptr, int skey)
{
        if(ptr==NULL)
        {
                printf("key not found\n");
                return NULL;
        }
        else if(skey < ptr->info)/*search in left subtree*/
                return search(ptr->left, skey);
        else if(skey > ptr->info)/*search in right subtree*/
                return search(ptr->right, skey);
        else /*skey found*/
                return ptr;
}/*End of search()*/
struct node *del(struct node *ptr, int dkey)
{
        struct node *tmp, *succ;

        if( ptr == NULL)
        {
                printf("\nDkey not found\n");
                return(ptr);
        }
        if( dkey < ptr->info )/*delete from left subtree*/
                ptr->left = del(ptr->left, dkey);
        else if( dkey > ptr->info )/*delete from right subtree*/
                ptr->right = del(ptr->right, dkey);
        else
        {
                /*key to be deleted is found*/
                if( ptr->left!=NULL  &&  ptr->right!=NULL )  /*2 children*/
                {
                        succ=ptr->right;
                        while(succ->left)
                                succ=succ->left;
                        ptr->info=succ->info;
                        ptr->right = del(ptr->right, succ->info);
                }
                else
                {
                        tmp = ptr;
                        if( ptr->left != NULL ) /*only left child*/
                                ptr = ptr->left;
                        else if( ptr->right != NULL) /*only right child*/
                                ptr = ptr->right;
                        else    /* no child */
                                ptr = NULL;
                        free(tmp);
                }
        }
        return ptr;
}/*End of del( )*/
void inorder(struct node *ro)
{
	if(ro==NULL)
	return;
	inorder(ro->left);
	printf("%d ",ro->info);
	inorder(ro->right);
}

int main()
{
	int n,choice;
	char ch,k;
	struct node *root=NULL,*ptr;
	do{
		printf("Enter value");
		scanf("%d",&n);
		root=create(root,n);
	
	fflush(stdin);
    printf("wanna enter more!y or n\n");
    scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
    while(1)
        {
                printf("\n");
                printf("1.Search\n");
                printf("2.Insert\n");
                printf("3.Delete\n");
                 printf("4.Display\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
         switch(choice)
                {

                case 1:
                        printf("\nEnter the key to be searched : ");
                        scanf("%d",&k);
                        ptr = search(root, k);
                        if(ptr!=NULL)
                                printf("\n\n");
                        break;

                case 2:
                        printf("\nEnter the key to be inserted : ");
                        scanf("%d",&k);
                        root = insert(root, k);
                        break;

                case 3:
                        printf("\nEnter the key to be deleted : ");
                        scanf("%d",&k);
                        root = del(root,k);
                        break;
                        case 4:
            printf("\n");
            inorder(root);
            printf("\n");
            break;

                 case 5:
                        exit(1);

                 default:
                        printf("\nWrong choice\n");
                }/*End of switch */
        }
    }




