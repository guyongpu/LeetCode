//
// Created by yongpu on 2019/11/21 16:00.
//

#include "P0106_ConstructBinaryTreeFromInorderAndPostorderTraversal.h"

/**
 * 题目：从中序与后序遍历序列构造二叉树
 * 描述：根据一棵树的中序遍历与后序遍历构造二叉树.
 * 思路：与105题相似，当前节点为 postorder的最后一个节点，然后构造left_inorder,left_postorder和right_inorder,right_postorder,递归构造左右子树.
 * 备注：注意复习掌握
 */


TreeNode *
P0106_ConstructBinaryTreeFromInorderAndPostorderTraversal::buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0 || postorder.size() == 0) {
        return nullptr;
    }

    int num = postorder[postorder.size() - 1];
    TreeNode *Node = new TreeNode(num);
    int pos = find(inorder.begin(), inorder.end(), num) - inorder.begin();

    vector<int> left_inorder;
    vector<int> left_postorder;

    left_inorder.assign(inorder.begin(), inorder.begin() + pos);
    left_postorder.assign(postorder.begin(), postorder.begin() + pos);

    vector<int> right_inorder;
    vector<int> right_postorder;
    right_inorder.assign(inorder.begin() + 1 + pos, inorder.end());
    right_postorder.assign(postorder.begin() + pos, postorder.end() - 1);

    // 左子树
    if (left_inorder.size()) {
        Node->left = buildTree(left_inorder, left_postorder);
    }

    // 右子树
    if (right_inorder.size()) {
        Node->right = buildTree(right_inorder, right_postorder);
    }

    return Node;
}

int P0106_ConstructBinaryTreeFromInorderAndPostorderTraversal::test() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode *root = nullptr;
    root = buildTree(inorder, postorder);

    return 0;
}
