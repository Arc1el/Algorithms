#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct TreeNode
{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(int item)
{
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if(node==NULL)
		return new_node(key);

	if(key<node->key)
		node->left=insert_node(node->left, key);

	if(key>node->key)
		node->right=insert_node(node->right, key);

	return node;
}

void inorder(TreeNode* root)
{
	if(root)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

void preorder(TreeNode* root)
{
	if(root)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->key);
	}
}

int get_height(TreeNode* root)
{
	int height = 0;

	if (root != NULL)
	{
		height = 1 + __max(get_height(root->left), get_height(root->right));
	}
	return height;
}

int main(void)
{
	TreeNode *root = NULL;
	TreeNode *tmp = NULL;

	root = insert_node(root, 1);
	root = insert_node(root, 4);
	root = insert_node(root, 2);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 3);
	
	printf("중위순회(left-root-right) \n");
	inorder(root);
	printf("\n트리의 높이 : %d",get_height(root));
	printf("\n왼쪽 서브트리의 높이 : %d",get_height(root->left));
	printf("\n오른쪽 서브트리의 높이 : %d",get_height(root->right));
	printf("\n\n전위순회(root-left-right)\n");
	preorder(root);
	printf("\n\n후위순회(left-right-root)\n");
	postorder(root);
	printf("\n\n");
	return 0;
}
