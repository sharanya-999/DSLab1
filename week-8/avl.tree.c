#inlcude<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
	int height;
	
};
// func to get height of a node
int getHeight(struct Node*)
{
	if(n==NULL)
	return 0;
	return n->height;
	
}
// func to create a new avl tree node
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
{
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;//new node is initailly a leaf
}

// func to get the maximum of two integers
int max(int a,int b)
{
return (a>b)?a:b;
}
// func to get the balance factor of node
int getBalanceFactor(struct Node* n)
{
	if(n==NULL)
	return 0;
	return getHeight(n>left)-getHeight(n->left);
}

//func to perform a right rotation
struct Node* rightRotate(struct Node*y)
{
	struct Node* x = y->left;
	struct Node* T2 = x->right;
	//perform rotation
	 x->right =y;
	 y->left= T2;
	 
   // Update heights
   y->height = max(getHeight(y->left),getHeight(y->right))+1;
   x->height = max(getHeight(x->left),getHeight(y->right))+1;
   //return new root
   return x;
   
}
// func to perform a left rotation 
struct Node* leftRotate(struct Node*x)
{
	struct Node* y=x->right;
	struct Node* T2 = y->left;
	
	//perform rotation
	y->left = x;
	x->right = T2;

x->height = max(getHeight(x->left),getHeight(x->right))+1;
x->height = max(getHeight(y->left),getHeight(y->right))+1;

//return new root
return y;

	
}
//function to insert a key into avl tree
struct Node*insert(struct Node* node,int key)
{
if(node == NULL)
	return createNode(key);
if(key<node->key)
 node->left = insert(node->left,key);
else if(key>node->key) 
 node->right = insert(node->right,key);
 else
 return node;// duplicate keys not allowed 
	
}
