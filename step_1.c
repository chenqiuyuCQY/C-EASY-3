#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;

void init_tree(SeqBiTree* tree)
{
    tree->size = MAX_TREE_SIZE;
    for (int i = 0; i < MAX_TREE_SIZE; i++) 
    {
        tree->nodes[i].used = false;
    }
}   // 初始化二叉树

bool set_root(SeqBiTree *tree, int value)
{
    tree->nodes[1].data = value;
    tree->nodes[1].used = true;
    return true;
} //创建根节点，在数组1处设置节点，并传入数据data

bool set_left_child(SeqBiTree *tree, int parent_node, int value)
{
    int left = parent_node * 2;

    if (!tree->nodes[parent_node].used) {
        return false;
    }
    if (tree->nodes[left].used) {
        return false;
    }
    tree->nodes[left].data = value;
    tree->nodes[left].used = true;
    return true;
} //创建左孩子

bool set_right_child(SeqBiTree *tree, int parent_node, int value)
{
    int right = parent_node * 2 + 1;
    if (!tree->nodes[parent_node].used) {
        return false;
    }
    if (tree->nodes[right].used) {
        return false;
    }
    tree->nodes[right].data = value;
    tree->nodes[right].used = true;
    return true;
}  // 创建右孩子

void level_order(SeqBiTree *tree)
{
    int level_start = 1;
    int level_end = 1;

    while (level_start < tree->size) {

        for (int i = level_start; i <= level_end; i++) {

            if (tree->nodes[i].used) {
                printf("%d ", tree->nodes[i].data);
            } else {
                printf("-1 ");
            }
        }

        printf("\n");

        level_start = level_end + 1;
        level_end = level_end * 2 + 1;
    }
}  // 遍历二叉树，按层序打印

int main()
{
    SeqBiTree tree;
    init_tree(&tree);
    set_root(&tree, 1);
    set_left_child(&tree, 1, 2);
    set_right_child(&tree, 1, 3);
    set_left_child(&tree, 2,4);
    set_right_child(&tree, 2, 5);
    set_left_child(&tree, 3, 6);
    set_right_child(&tree,3,7);
    level_order(&tree);
    return 0;
}