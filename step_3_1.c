#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;

TreeNode* create_node(int value)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}  //创建节点的函数

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
} //前序遍历函数

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}  //中序遍历函数

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}  //后序遍历函数

int depth(TreeNode *root, int current_depth, int max_depth)
{
    if (root == NULL) {
        return max_depth;
    }  // 如果当前节点为空，直接返回最大深度

    if (current_depth > max_depth) {
        max_depth = current_depth;
    }  // 如果当前深度比之前记录的最大深度更大

    max_depth = depth(root->left, current_depth + 1, max_depth);  // 遍历左子树
    max_depth = depth(root->right, current_depth + 1, max_depth);  // 遍历右子树
    return max_depth;
}

int main(){
    TreeNode *node1 = create_node(1);
    TreeNode *node2 = create_node(2);
    TreeNode *node3 = create_node(3);
    TreeNode *node4 = create_node(4);
    TreeNode *node5 = create_node(5);
    TreeNode *node6 = create_node(6);
    TreeNode *node7 = create_node(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    preorder(node1);
    printf("\n");
    inorder(node1);
    printf("\n");
    postorder(node1);
    printf("\n");
    return 0;
}