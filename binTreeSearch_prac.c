#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode
{
	struct TNode *leftChild;
	struct TNode *rightChild;
	int data;
}TreeNode;

TreeNode *insert_data(TreeNode *btnode, int data)
{
		

	if(btnode == NULL)
	{
		TreeNode *node = NULL;
		node = malloc(sizeof(TreeNode));
		node->leftChild = NULL;
		node->rightChild = NULL;
		node->data = data;
		printf("Inserted data %d\n", data);
		return node;
	}
	
	if(data > (btnode->data))
	{       
	        printf("%d is greater than %d\n", data, btnode->data);	
		btnode->rightChild = insert_data(btnode->rightChild, data);
	
	}
	else if(data < (btnode->data))
	{       
		printf("%d is smaller than %d\n",data, btnode->data );
		btnode->leftChild = insert_data(btnode->leftChild, data);
	}

	return btnode;
}

TreeNode *binary_Search(TreeNode *btnode, int data)
{       
	TreeNode *node = NULL;

	if (btnode == NULL)
		return NULL;
	
	if (data > (btnode->data))
		node = binary_Search(btnode->rightChild, data);
	else if (data < (btnode->data))
		node = binary_Search(btnode->leftChild, data);
        else
		return btnode;
	return node;
}

int find_depth(TreeNode *btnode)
{
	if(btnode == NULL)
		return 0;
	else
	{
		int lDepth = find_depth(btnode->leftChild);
		int rDepth = find_depth(btnode->rightChild);
		if(lDepth > rDepth)
			return (lDepth+1);
		else
			return (rDepth+1);
	}
}
int main()
{
	TreeNode *node = NULL;
	TreeNode *found = NULL;

        node = insert_data(node, 7);
	node = insert_data(node, 1);
	node = insert_data(node, 11);
	node = insert_data(node, 9);
	node = insert_data(node, 2);
	node = insert_data(node, 3);
	node = insert_data(node, 6);
	node = insert_data(node, 27);
	node = insert_data(node, 99);

        found = binary_Search(node, 18);

	if (found)
		printf("The value exists\n");
	else
		printf("Not found\n");

	int depth = find_depth(node);
	printf("Binary Tree Depth is %d\n", depth);


}

