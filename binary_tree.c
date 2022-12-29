#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* Left;
    struct Node* Right;
};

void init_node(struct Node* node_)
{
    node_->data = 0;
    node_->Left = NULL;
    node_->Right = NULL;
}

int main( int argc, char** argv )
{
    struct Node left_child;
    init_node(&left_child);
    left_child.data = 30;

    struct Node rightL_child;
    init_node(&rightL_child);
    rightL_child.data = 5;

    struct Node right_child;
    init_node(&right_child);
    right_child.data = 60;
    right_child.Left = &rightL_child;

    struct Node root;
    init_node(&root);
    root.data = 50;

    root.Left = &left_child;
    root.Right = &right_child;

    return 0;
}