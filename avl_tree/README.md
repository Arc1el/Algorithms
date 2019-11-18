# AVL트리의 생성, 입력, 삭제, 출력프로그램

![Image Of Result](https://github.com/Arc1el/Algorithms/blob/master/avl_tree/result.png)

AVL노드 구조체
```c++
typedef struct AVLNode
{
	int key;
	int height;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;
```
트리의 높이구하기
```c++
int get_height(AVLNode *node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + __max(get_height(node->left),
			get_height(node->right));

	return height;
}
```
균형인수 구하기
```c++
int get_balance(AVLNode* node)
{
	if (node == NULL) return 0;

	return get_height(node->left) - get_height(node->right);
}
```
노드생성
```c++
AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
```
오른쪽 회전연산
```c++
AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}
```
왼쪽 회전연산
```c++
AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}
```
삽입
```c++
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
```
단말노드 찾기
```c++
AVLNode* minValueNode(AVLNode* node) 
{ 
    AVLNode* current = node; 

    while (current->left != NULL) //단말노드 찾기
        current = current->left; 
  
    return current; 
} 
```
삭제
```c++
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
```
전위순회
```c++
void preorder(AVLNode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
```
중위순회
```c++
void inorder(AVLNode* root)
{
	if(root)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}
```
후위순회
```c++
void postorder(AVLNode* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->key);
	}
}
```
