#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree;
void create_tree(struct node *);
struct node *insertelement(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
struct node *smallestelement(struct node *);
struct node *largestelement(struct node *);
struct node *deleteelement(struct node *,int);
int totalnodes(struct node *);
int totalinternalnodes(struct node *);
int totalexternalnodes(struct node *);
int height(struct node *);
struct node *deletetree(struct node *);

int main(){
	int option,val;
	struct node *ptr;
	create_tree(tree);
	do{
		printf("\n ******MAIN MENU******* \n");
		printf("\n 1. Insert Element");
		printf("\n 2. Preorder Traversal");
		printf("\n 3. Inorder Traversal");
		printf("\n 4. Postorder Traversal");
		printf("\n 5. Find the smallest element");
		printf("\n 6. Find the largest element");
		printf("\n 7. Delete an element");
		printf("\n 8. Count the total number of nodes");
		printf("\n 9. Count the total number of external nodes");
		printf("\n 10. Count the total number of internal nodes");
		printf("\n 11. Determine the height of the tree");
		printf("\n 12. Delete the tree");
		printf("\n 13. Exit");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value of new node: ");
				scanf("%d",&val);
				tree = insertelement(tree , val);
				break;
				
			case 2:
				printf("\n The elements of the tree are: \n");
				preorder(tree);
				break;
				
			case 3:
				printf("\n The elements of the tree are: \n");
				inorder(tree);
				break;
				
			case 4:
				printf("\n The elements of the tree are: \n");
				postorder(tree);
				break;
				
			case 5:
				ptr=smallestelement(tree);
				printf("\n Smallest element is :%d",ptr->data);
				break;
				
			case 6:
				ptr=largestelement(tree);
				printf("\n largest element is :%d",ptr->data);
				break;
				
			case 7:
				printf("\n Enter the element to be deleted : ");
				scanf("%d",&val);
				tree=deleteelement(tree, val);
				break;
				
			case 8:
				printf("\n Total no. of nodes = %d", totalnodes(tree));
				break;
				
			case 9:
				printf("\n Total no. of external nodes = %d",totalexternalnodes(tree));
				break;
				
			case 10:
				printf("\n Total no. of internal nodes = %d",totalinternalnodes(tree));
				break;
				
			case 11:
				printf("\n The height of the tree = %d",height(tree));
				break;
				
			case 12:
				tree = deletetree(tree);
				break;
		}
	}while(option!=13);
	return 0;
}

void create_tree(struct node *tree)
{
	tree=NULL;
}

struct node *insertelement(struct node *tree,int val)
{
	struct node *ptr,*nodeptr,*parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL){
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else {
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL){
			parentptr=nodeptr;
			if(val<nodeptr->data){
				nodeptr=nodeptr->left;
			}
			else {
				nodeptr=nodeptr->right;
			}
		}
		if(val<parentptr->data){
			parentptr->left = ptr;
		}
		else{
			parentptr->right = ptr;
		}
	}
	return tree;
}
void preorder(struct node *tree)
{
	if(tree != NULL)
	{
		printf("%d\t", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(struct node *tree)
{
	if(tree != NULL)
	{
		inorder(tree->left);
		printf("%d\t", tree->data);
		inorder(tree->right);
	}
}

void postorder(struct node *tree)
{
	if(tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\t", tree->data);
	}
}

struct node *smallestelement(struct node *tree)
{
	if((tree == NULL) || (tree->left == NULL))
	return tree;
	else
	return smallestelement(tree->left);
}

struct node *largestelement(struct node *tree)
{
	if((tree == NULL) || (tree->right == NULL))
	return tree;
	else
	return largestelement(tree->right);
}

int totalnodes(struct node *tree)
{
	if(tree==NULL)
	return 0;
	else
	return(totalnodes(tree->left) + totalnodes(tree->right) + 1);
}

int totalexternalnodes(struct node *tree)
{
	if(tree==NULL)
	return 0;
	else if((tree->left==NULL) && (tree->right==NULL))
	return 1;
	else
	return (totalexternalnodes(tree->left) +totalexternalnodes(tree->right));
}

int totalinternalnodes(struct node *tree)
{
	if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
	return 0;
	else
	return (totalinternalnodes(tree->left)+ totalinternalnodes(tree->right) + 1);
}

int height(struct node *tree)
{
	int leftheight, rightheight;
	if(tree==NULL)
	return 0;
	else {
		leftheight = height(tree->left);
		rightheight = height(tree->right);
		if(leftheight > rightheight)
		return (leftheight + 1);
		else
		return (rightheight + 1);
	}
}

struct node *deletetree(struct node *tree)
{
	if(tree!=NULL)
	{
		deletetree(tree->left);
		deletetree(tree->right);
		free(tree);
	}
}

struct node *deleteelement(struct node *tree, int val)
{
	struct node *cur, *parent, *suc, *psuc, *ptr;
	if(tree->left==NULL){
		printf("\n The tree is empty: ");
		return tree;
	}
	while(cur!=NULL && val!= cur->data)
	{
		parent = cur;
		cur = (val<cur->data)? cur->left:cur->right;
	}
	if(cur == NULL)
	{
		printf("\n The value to be deleted is not present in the tree");
		return(tree);
	}
	if(cur->left == NULL)
	ptr = cur->right;
	else if(cur->right == NULL)
	ptr = cur->left;
	else 
	{
		// Find the in–order successor and its parent
		psuc = cur;
		cur = cur->left;
		while(suc->left!=NULL)
		{
			psuc = suc;
			suc = suc->left;
		}
		if(cur==psuc)
		{
			// Situation 1
			suc->left = cur->right;
		}
		else
		{
			// Situation 2
			suc->left = cur->left;
			psuc->left = suc->right;
			suc->right = cur->right;
		}
		ptr = suc;
	}
	// Attach ptr to the parent node
	if(parent->left == cur)
	parent->left=ptr;
	else
	parent->right=ptr;
	free(cur);
	return tree;
}



