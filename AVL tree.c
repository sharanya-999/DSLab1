// C program to implement AVL tree
#include<stdio.h>
#include<stdlib.h>

// Structure for an AVL Tree node
struct node {
	int key;
	struct node* left;
	struct node* right;
	int height;
};

// Function to get the height of a node
int getheight(struct node* n)
{
	if(n==NULL){
		return 0;
	}
	return n->height;	
}

// Function to create a new AVL tree node
struct node* createnode(int key)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}

// Function to get the maximum of two integers
int max(int a,int b) {
	return (a>b)?a:b;
}

// Function to get the balance factor of a node
int balancefactor(struct node* n)
{
	if(n==NULL){
		return 0;
	}
	return getheight(n->left)-getheight(n->right);
}

// Function to perform a right rotation
struct node* rightrotate(struct node* y)
{
	struct node* x=y->left;
	struct node* t2=x->right;
	
	//rotation
	x->right=y;
	y->left=t2;
	
	//updating heights
	y->height=max(getheight(y->left),getheight(y->right))+1;
	x->height=max(getheight(x->left),getheight(x->right))+1;
	
	//return new root
	return x;
}

// Function to perform a left rotation
struct node* leftrotate(struct node* x)
{
	struct node* y=x->right;
	struct node* t2=y->left;
	
	//rotate
	y->left=x;
	x->right=t2;
	
	//update heights
	x->height=max(getheight(x->left),getheight(x->right))+1;
	y->height=max(getheight(y->left),getheight(y->right))+1;
	
	//return new node
	return y;
}

// Function to insert a key into the AVL tree
struct node* insert(struct node* node,int key)
{
	if(node==NULL){
		return createnode(key);
	}
	if(key<node->key){
	node->left=insert(node->left,key);
	}
	else if(key>node->key){
	node->right=insert(node->right,key);
	}
	else{
	return node;
	} //duplicate keys not allowed
	
	//update height of root node
	node->height=1 + max(getheight(node->left), getheight(node->right));
	
	//check balance factor
	int balance=balancefactor(node);
	
	//perform rotations
	
	//lL case
	if(balance>1 && key<node->left->key)
	return rightrotate(node);
	
	//RR case
	if(balance<-1 && key>node->right->key)
	return leftrotate(node);
	
	//LR case
	if(balance>1 && key>node->left->key){
	node->left=leftrotate(node->left);
	return rightrotate(node);
	}
	
	//RL case
	if(balance<-1 && key<node->right->key){
	node->right=rightrotate(node->right);
	return leftrotate(node);
	}
	
	return node;
}

// Function for inorder traversal (Left, Root, Right)
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}

// Main function to test AVL Tree operations
int main()
{
struct node* root = NULL;
// Insert nodes into the AVL tree
root = insert(root, 1);
root = insert(root, 2);
root = insert(root, 4);
root = insert(root, 5);
root = insert(root, 6);
root = insert(root, 3);
// Display the inorder traversal
printf("Inorder traversal of AVL tree: ");
inorder(root);
return 0;
}
