//
// Created by yongpu on 2019/12/28 15:55.
//

#include "P0236_LowestCommonAncestorOfA_BinaryTree.h"

/**
 * 题目：二叉树的最近公共祖先
 * 描述：给定一个二叉树, 找到该树中两个指定节点的最近公共祖先.
 * 思路：方法1.计算p和q的路径，然后找最后一个重合的节点；方法2.记录p和q的所有祖先，然后将p的父节点放入set中，再反向计算q.
 * 备注：掌握方法1和方法2
 */

// 方法1.计算pq路径，并对比
void FindPath(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> path, vector<TreeNode *> &p_path,
              vector<TreeNode *> &q_path) {
    if (root == nullptr) {
        return;
    }

    path.push_back(root);

    if (root == p) {
        p_path = path;
    }
    if (root == q) {
        q_path = path;
    }
    if (!q_path.empty() && !p_path.empty()) {
        return;
    }

    FindPath(root->left, p, q, path, p_path, q_path);
    FindPath(root->right, p, q, path, p_path, q_path);
}

TreeNode *P0236_LowestCommonAncestorOfA_BinaryTree::lowestCommonAncestor_1(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> path;
    vector<TreeNode *> p_path;
    vector<TreeNode *> q_path;

    FindPath(root, p, q, path, p_path, q_path);

    if (p_path.empty() || q_path.empty()) {
        return nullptr;
    }

    int i = 0;
    while (1) {
        if (p_path[i] != q_path[i]) {
            break;
        }
        i++;
        if (i < p_path.size() && i < q_path.size()) {
            continue;
        } else {
            break;
        }
    }


    return p_path[i - 1];
}

// 方法2.记录父节点

TreeNode *P0236_LowestCommonAncestorOfA_BinaryTree::lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }

    // 1.记录所有父节点
    map<TreeNode *, TreeNode *> parentMap;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *node = nullptr;
    parentMap[root] = nullptr;
    while (!st.empty()) {
        node = st.top();
        st.pop();
        if (parentMap.find(p) != parentMap.end() && parentMap.find(q) != parentMap.end()) {
            break;
        }
        if (node->right) {
            parentMap[node->right] = node;
            st.push(node->right);
        }

        if (node->left) {
            parentMap[node->left] = node;
            st.push(node->left);
        }
    }

    // 2.将p的父节点存入到 parentSet 中
    set<TreeNode *> parentSet;
    parentSet.insert(p);
    TreeNode *temp = nullptr;
    temp = p;
    // 找到temp的父节点
    while (parentMap.find(temp) != parentMap.end()) {
        parentSet.insert(parentMap[temp]);
        temp = parentMap[temp];
    }


    // 3.反向找q的父节点，直到在 parentSet 中出现
    temp = q;
    // 找到temp的父节点
    while (parentMap.find(temp) != parentMap.end()) {
        if (parentSet.find(temp) != parentSet.end()) {
            return temp;
        }
        temp = parentMap[temp];
    }
    return root;
}

int P0236_LowestCommonAncestorOfA_BinaryTree::test() {
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(5);
    TreeNode *p3 = new TreeNode(1);
    TreeNode *p4 = new TreeNode(6);
    TreeNode *p5 = new TreeNode(2);
    TreeNode *p6 = new TreeNode(0);
    TreeNode *p7 = new TreeNode(8);
    TreeNode *p8 = new TreeNode(7);
    TreeNode *p9 = new TreeNode(4);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    p5->left = p8;
    p5->right = p9;

    TreeNode *node = lowestCommonAncestor_2(p1, p2, p9);
    if (node) {
        cout << node->val << endl;
    }
    return 0;
}
