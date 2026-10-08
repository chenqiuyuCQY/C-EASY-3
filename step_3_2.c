#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct Stack {    // 栈
    TreeNode **arr;  // 用来存放TreeNode* 的数组，即存放二叉树每个节点地址的数组
    int top;     //  定义栈顶
    int capacity;  //  定义栈的容量
} Stack;  
Stack *createStack(int capacity) {    // 创建一个栈
    Stack *stack = malloc(sizeof(Stack));  // 给栈申请一块空间
    stack->arr = malloc(sizeof(TreeNode *) * capacity);  // 给上面创建的存放地址的数组申请一块空间
    stack->top = -1;    // 栈刚创建时为空
    stack->capacity = capacity;  // 保存栈的最大容量
    return stack;   // 返回已创建的栈的地址
}
int isEmpty(Stack *stack) {
    return stack->top == -1;  // 判断栈是否为空，若top==-1，则展为空
}
void push(Stack *stack, TreeNode *node) {  // 入栈
    if (stack->top == stack->capacity - 1) {  //判断栈是否已满
        return;
    }
    stack->arr[++stack->top] = node;  // 没满则top+1，将stack->arr[top+1]放入node中
}
TreeNode *pop(Stack *stack) {  // 出栈
    if (isEmpty(stack)) {
        return NULL;   // 判断栈是否为空
    }
    return stack->arr[stack->top--];  // 不为空则取出栈顶，top-1，栈顶向下移动
}

void preorderTraversal(TreeNode *root) // 补全这个函数
{
    if (root == NULL)
    {
        return;
    }
    Stack* stack = createStack(100);  // 创建的栈的容量
    push(stack,root);  // 将根节点放入栈中
    while (!isEmpty(stack)) {
        TreeNode *node = pop(stack);
        printf("%d ", node->data);
        if (node->right != NULL) {
            push(stack, node->right);  // 如果有右孩子,就把右孩子放入栈中
        }
        if (node->left != NULL) {
            push(stack, node->left);   // 如果有左孩子,就把左孩子放入栈中
        }
        
    }
        free(stack->arr);  // 释放栈的内存
        free(stack);   // 再释放Stack结构体本身占用的内存
}

TreeNode* create_node(int value)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}  // 创建节点函数

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
    preorderTraversal(node1);
    return 0;
}