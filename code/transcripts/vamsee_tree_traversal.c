/****************************************************
 The tree used to print is as follows

                                8
                               / \
                             /     \
                            4        9
                           / \      /
                         /     \   /
                        2       6  10
                       / \     / \   \
                      1   3   5   7   11

 The output is 8 4 9 10 6 2 1 3 5 7 11
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

/* Single array used for implementing 2 stacks
 * first stack grows from left to right and
 * second stack grows from right to left */
void *stack_array[MAX_SIZE] = {0};

int top_st1 = -1;
int top_st2 = MAX_SIZE;

void push(void *data, int which_stack);
void *pop(int which_stack);

void push(void *data, int which_stack)
{
	if(which_stack == 1)
	{
		if(top_st1!=top_st2) {
			stack_array[++top_st1] = data;
		}
	}
	else if(which_stack == 2)
	{
		if(top_st2!=top_st1) {
			stack_array[--top_st2] = data;
		}
	}
	return;
}

int isEmpty(int which_stack)
{
	if(which_stack == 1)
		return (top_st1 == -1);
	else
		return (top_st2 == MAX_SIZE);
}

void *pop(int which_stack)
{
	void *vp;
	if(isEmpty(which_stack))
		return NULL;

	if(which_stack == 1)
	{
		vp = stack_array[top_st1];
		stack_array[top_st1]=NULL;
		top_st1--;
	}
	else if(which_stack == 2)
	{
		vp = stack_array[top_st2];
		stack_array[top_st2]=NULL;
		top_st2++;
	}
	return vp;
}

struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
};

typedef struct treenode TreeNode;

TreeNode *insert(TreeNode *node, int data) {
	if (node == NULL) {
		node = (TreeNode *)malloc(sizeof(TreeNode));
		node->data = data;
		node->left = node->right = NULL;
	}
	else {
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
	}
	return node;
}


void traverseTree(TreeNode *root)
{
	int level = 1;
	TreeNode *node;

	if(root == NULL) return;

	push(root, 1);

	while (!isEmpty(1) || !isEmpty(2)) {
		if(level%2 != 0) { /* level is odd stack right node first */
		   while((node = (TreeNode *)pop(1))!=NULL) {
			printf("%d ",node->data);
		   	if(node->right != NULL)
		   	{
		   		push(node->right, 2);
			}

			if(node->left != NULL)
			{
		   		push(node->left, 2);
			}
		   }
		}
		else {		/* level is even stack left node first */
		   while((node = (TreeNode *)pop(2))!=NULL) {
			printf("%d ",node->data);
		   	if(node->left != NULL)
		   	{
		   		push(node->left, 1);
			}

			if(node->right != NULL)
			{
		   		push(node->right, 1);
			}
		   }
		}
		level++;
	}
	return;
}

int main()
{
	int a[] = {8,4,2,6,1,3,5,7,9,10,11};

	int i;
	TreeNode *root = NULL;

	for(i=0;i<11;i++)
		root = insert(root,a[i]);

	printf("\n");
	traverseTree(root);
	printf("\n");
	return 0;
}
