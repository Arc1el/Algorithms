#include<stdio.h> 
#include<stdlib.h> 
#define MAX(a, b) (a)

typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

int get_height(AVLNode *node)
{
  int height = 0;

	if (node != NULL)
		height = 1 + __max(get_height(node->left),
			get_height(node->right));

	return height;
}

int get_balance(AVLNode* node)
{
	if (node == NULL) return 0;

	return get_height(node->left)
		- get_height(node->right);
}

AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// 오른쪽 회전
AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

// 왼쪽회전
AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}
 
AVLNode* insert(AVLNode* node, int key)
{
	if (node == NULL)
		return(create_node(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else	
		return node;

	// 균형인수 재계산
	int balance = get_balance(node);

	// LL
	if (balance > 1 && key < node->left->key)
		return rotate_right(node);

	// RR
	if (balance < -1 && key > node->right->key)
		return rotate_left(node);

	// LR
	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_right(node->left);
		return rotate_right(node);
	}

	// RL
	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

// 전위 순회 함수
void preorder(AVLNode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(void)
{
	AVLNode *root = NULL;

	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 8);
	root = insert(root, 9);

	printf("전위 순회 결과 \n");
	preorder(root);

	return 0;
}
