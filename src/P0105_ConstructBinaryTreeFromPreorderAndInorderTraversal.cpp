//
// Created by yongpu on 2019/11/21 9:44.
//

#include "P0105_ConstructBinaryTreeFromPreorderAndInorderTraversal.h"

/**
 * 题目：从前序与中序遍历序列构造二叉树
 * 描述：根据一棵树的前序遍历与中序遍历构造二叉树.
 * 思路：每次将preorder的首元素构造树节点，然后提取left_inorder,left_preorder和right_inorder,right_preorder，进行进一步构造.
 * 备注：掌握方法
 */

TreeNode *
P0105_ConstructBinaryTreeFromPreorderAndInorderTraversal::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) {
        return nullptr;
    }
    int num = preorder[0];
    int pos = find(inorder.begin(), inorder.end(), num) - inorder.begin();


    TreeNode *Node = new TreeNode(num);

    vector<int> left_inorder;
    vector<int> left_preorder;
    left_inorder.assign(inorder.begin(), inorder.begin() + pos);
    int left_size = left_inorder.size();
    left_preorder.assign(preorder.begin() + 1, preorder.begin() + 1 + left_size);

    vector<int> right_inorder;
    vector<int> right_preorder;
    right_inorder.assign(inorder.begin() + pos + 1, inorder.end());
    right_preorder.assign(preorder.begin() + 1 + left_size, preorder.end());

    if (left_preorder.size() > 0) {
        Node->left = buildTree(left_preorder, left_inorder);
    }
    if (right_preorder.size() > 0) {
        Node->right = buildTree(right_preorder, right_inorder);
    }
    return Node;
}

int P0105_ConstructBinaryTreeFromPreorderAndInorderTraversal::test() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = nullptr;
    root = buildTree(preorder, inorder);


    return 0;
}
