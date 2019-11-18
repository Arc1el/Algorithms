#include<stdio.h> 
#include<stdlib.h> 
#define MAX(a, b) (a)

typedef struct AVLNode
{
	int key;
	int height;
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

	return get_height(node->left) - get_height(node->right);
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

AVLNode* minValueNode(AVLNode* node) 
{ 
    AVLNode* current = node; 

    while (current->left != NULL) //단말노드 찾기
        current = current->left; 
  
    return current; 
} 

AVLNode* delete_node(AVLNode* root, int key) 
{   
    if (root == NULL) 
	{
        return root; 
	}
 
    if (key < root->key) 
	{
        root->left = delete_node(root->left, key); 
	}
 
    else if(key > root->key) 
	{
        root->right = delete_node(root->right, key); 
	}
  
    else
    { 
        if((root->left == NULL) || (root->right == NULL)) //자식이 1명만 있거나 없거나
        { 
            AVLNode *temp = root->left ? root->left : root->right;   
            if (temp == NULL) //자식없음
            { 
                temp = root; 
                root = NULL; 
            } 
            else //자식 1명
			{
				 *root = *temp;
			}
			free(temp); 
        } 
        else
        { 
            AVLNode* temp = minValueNode(root->right); 
            root->key = temp->key; 
            root->right = delete_node(root->right, temp->key); 
        } 
    } 

    if (root == NULL) 
	{
		return root;
	}
  
    root->height = 1 + __max(get_height(root->left), get_height(root->right)); 
  
    int balance = get_balance(root); 
  
    // LL
    if (balance > 1 && get_balance(root->left) >= 0) 
	{
        return rotate_right(root); 
	}
  
    // LR
    if (balance > 1 && get_balance(root->left) < 0) 
    { 
        root->left =  rotate_left(root->left); 
        return rotate_right(root); 
    } 
  
    // RR
    if (balance < -1 && get_balance(root->right) <= 0) 
	{
        return rotate_left(root); 
	}
  
    // RL
    if (balance < -1 && get_balance(root->right) > 0) 
    { 
        root->right = rotate_right(root->right); 
        return rotate_left(root); 
    } 
  
    return root; 
} 

// 전위순회
void preorder(AVLNode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
//중위순회
void inorder(AVLNode* root)
{
	if(root)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}
//후위순회
void postorder(AVLNode* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->key);
	}
}

int main(void)
{
	AVLNode *root = NULL;

	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 3);

	printf("삭제연산 전 전위순회 결과\n");
	preorder(root);
	printf("\n");

	root = delete_node(root, 6);
	root = delete_node(root, 5);

	printf("\n삭제연산 후 전위 순회 결과 \n");
	preorder(root);

	return 0;
}
