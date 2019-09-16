#include <stdlib.h>

#include "BinaryTree.h"

/**
 * TreeNode 생성 함수
 * 
 * return BinaryTreeNode * 생성된 노드의 주소
 * 
 * 노드를 생성합니다.
 */ 
BinaryTreeNode * MakeBinaryTreeNode() {
    BinaryTreeNode * node = (BinaryTreeNode *) malloc (sizeof(BinaryTreeNode));
    node->data = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * TreeNode 데이터 반환 함수
 * 
 * @param node BinaryTree * 노드의 주소
 * 
 * return BTData 노드의 데이터
 * 
 * 해당 노드가 저장하는 데이터를 반환합니다.
 */ 
BTData GetData(BinaryTreeNode * node) {
    return node->data;
}

/**
 * TreeNode 데이터 변경 함수
 * 
 * @param node BinaryTree * 노드의 주소
 * @param data BTData       저장할 데이터
 * 
 * 파라미터로 받은 data를 node에 저장합니다.
 */ 
void SetData(BinaryTreeNode * node, BTData data) {
    node->data = data;
}

/**
 * TreeNode 왼쪽 자식 트리 반환 함수
 * 
 * @param node BinaryTree * 노드의 주소
 * 
 * return BinaryTree * 왼쪽 자식 트리의 주소
 * 
 * 자신의 왼쪽 트리(를 표현하고 있는 노드)의 주소를 반환합니다.
 */ 
BinaryTreeNode * GetLeftSubTree(BinaryTreeNode * node) {
    return node->left;
}

/**
 * TreeNode 오른쪽 자식 트리 반환 함수
 * 
 * @param node BinaryTree * 노드의 주소
 * 
 * return BinaryTree * 오른쪽 자식 트리의 주소
 * 
 * 자신의 오른쪽 트리(를 표현하고 있는 노드)의 주소를 반환합니다.
 */ 
BinaryTreeNode * GetRightSubTree(BinaryTreeNode * node) {
    return node->right;
}

/**
 * 왼쪽 서브 트리 지정 함수
 * 
 * @param parent BinaryTree * 부모의 노드 주소
 * @param child BinaryTree *  왼쪽 자식이 될 노드(트리)의 주소
 * 
 * 노드는 단일 노드를 표현하기도 하지만, 트리 자체를 표현하기도 합니다. 
 * "parent 노드의 왼쪽 자식을 child로 한다."는 즉, child가 표현하고 있는 트리를 자신의 왼쪽 자식으로 지정한다는 뜻입니다.
 */ 
void MakeLeftSubTree(BinaryTreeNode * parent, BinaryTreeNode * child) {
    if (parent->left != NULL) {
        RemoveTreeNode(parent->left);
    }

    parent->left = child;
}


/**
 * 오른쪽 서브 트리 지정 함수
 * 
 * @param parent BinaryTree * 부모의 노드 주소
 * @param child BinaryTree *  오른쪽 자식이 될 노드(트리)의 주소
 * 
 * 노드는 단일 노드를 표현하기도 하지만, 트리 자체를 표현하기도 합니다. 
 * "parent 노드의 오른쪽 자식을 child로 한다."는 즉, child가 표현하고 있는 트리를 자신의 오른쪽 자식으로 지정한다는 뜻입니다.
 */ 
void MakeRightSubTree(BinaryTreeNode * parent, BinaryTreeNode * child) {
    if (parent->right != NULL) {
        RemoveTreeNode(parent->right);
    }

    parent->right = child;
}

/**
 * 트리(를 표현하고 있는 노드) 삭제 함수
 * 
 * @param node BinaryTree * 삭제할 노드 주소
 * 
 * 해당 노드를 삭제합니다. 만약 왼쪽 혹은 오른쪽 자식들이 있다면, 먼저 재귀적으로 삭제합니다.
 * 즉, 후위 순회 방식으로 트리(노드)를 삭제합니다.
 */ 
void RemoveTreeNode(BinaryTreeNode * node) {
    if (node == NULL) {
        return;
    }

    RemoveTreeNode(node->left);
    RemoveTreeNode(node->right);
    free(node);
    node = NULL;
}

/** 
 * 전위 순회 함수
 * 
 * @param node BinaryTree * 순회할 노드 주소
 * @param action TraversalFuctionPtr 실행 함수의 포인터
 * 
 * 트리를 전위 방식으로 순회합니다. 전위 순회란, 자기 자신에 대해서 실행 함수를 실행하고, 왼쪽 자식, 오른쪽 자식 순으로 순회하는 것입니다.
 */ 
void PreOrderTraverse(BinaryTreeNode * node, TraversalFuctionPtr action) {
    if (node == NULL) {
        return;
    }

    action(node->data);
    PreOrderTraverse(node->left, action);
    PreOrderTraverse(node->right, action);
}

/** 
 * 중위 순회 함수
 * 
 * @param node BinaryTree * 순회할 노드 주소
 * @param action TraversalFuctionPtr 실행 함수의 포인터
 * 
 * 트리를 중위 방식으로 순회합니다. 중위 순회란, 왼쪽 자식을 순회 후, 자기 자신에 대해서 실행함수를 실행한 후, 오른쪽 자식을 순회하는 것입니다. 
 */
void InOrderTraverse(BinaryTreeNode * node, TraversalFuctionPtr action) {
    if (node == NULL) {
        return;
    }

    InOrderTraverse(node->left, action);
    action(node->data);
    InOrderTraverse(node->right, action);
}

/** 
 * 후위 순회 함수
 * 
 * @param node BinaryTree * 순회할 노드 주소
 * @param action TraversalFuctionPtr 실행 함수의 포인터
 * 
 * 트리를 후위 방식으로 순회합니다. 후위 순회란, 왼쪽 자식, 오른쪽 자식들을 순회 후, 자기 자신에 대해서 실행함수를 실행하는 것입니다. 
 */
void PostOrderTraverse(BinaryTreeNode * node, TraversalFuctionPtr action) {
    if (node == NULL) {
        return;
    }

    PostOrderTraverse(node->left, action);
    PostOrderTraverse(node->right, action);
    action(node->data);
}

BinaryTreeNode * RemoveLeftSubTree(BinaryTreeNode * bt) {
    if (bt == NULL) {
        return NULL;
    }

    return bt->left;
}

BinaryTreeNode * RemoveRightSubTree(BinaryTreeNode * bt) {
    if (bt == NULL) {
        return NULL;
    }

    return bt->right;
}

void ChangeLeftSubTree(BinaryTreeNode * main, BinaryTreeNode * sub) {
    main->left = sub;
}

void ChangeRightSubTree(BinaryTreeNode * main, BinaryTreeNode * sub) {
    main->right = sub;
}