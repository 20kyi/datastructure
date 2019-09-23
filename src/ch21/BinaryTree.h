#ifndef  __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef void * BTData;

/**
 * Tree이자, Tree의 노드를 표현하는 자료구조체.
 * 
 * @field data BTData            노드가 저장하는 데이터
 * @field left BinaryTreeNode *  왼쪽의 자식 노드를 가리키는 포인터
 * @field right BinaryTreeNode * 오른쪽의 자식 노드를 가리키는 포인터
 */ 
typedef struct _binary_tree_node {
    BTData data;                       //data
    struct _binary_tree_node * left;   //left child
    struct _binary_tree_node * right;  //right child
} BinaryTreeNode;

/** 
 * 순회 함수에 쓰일 함수 포인터, 이런 형식의 원형을 갖는 함수를 받는다.
 * void func(BTData data);
 */ 
typedef void TraversalFuctionPtr(BTData data);

BinaryTreeNode * MakeBinaryTreeNode();

BTData GetData(BinaryTreeNode * node);
void SetData(BinaryTreeNode * node, BTData data);

BinaryTreeNode * GetLeftSubTree(BinaryTreeNode * node);
BinaryTreeNode * GetRightSubTree(BinaryTreeNode * node);

void MakeLeftSubTree(BinaryTreeNode * parent, BinaryTreeNode * child);
void MakeRightSubTree(BinaryTreeNode * parent, BinaryTreeNode * child);

void RemoveTreeNode(BinaryTreeNode * root);

void PreOrderTraverse(BinaryTreeNode * root, TraversalFuctionPtr action);
void InOrderTraverse(BinaryTreeNode * root, TraversalFuctionPtr action);
void PostOrderTraverse(BinaryTreeNode * root, TraversalFuctionPtr action);

BinaryTreeNode * RemoveLeftSubTree(BinaryTreeNode * bt);
BinaryTreeNode * RemoveRightSubTree(BinaryTreeNode * bt);

void ChangeLeftSubTree(BinaryTreeNode * main, BinaryTreeNode * sub);
void ChangeRightSubTree(BinaryTreeNode * main, BinaryTreeNode * sub);

#endif // !__BINARY_TREE_H__

