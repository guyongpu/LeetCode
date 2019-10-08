//
// Created by yongpu on 2019/10/8.
//

#include "P0148_SortList.h"

/**
 * 题目：排序链表
 * 描述：在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 思路：对链表进行快速排序或归并排序进行实现均可，和普通的数组排序有所不同，要注意区分。
 * 备注：该题比较重要，要注意复习
 *
 * 做法：
 * 我们设置两个指针 i，j，其中 i 初始时指向数组的第一个元素，j 初始化为 i+1。
 * 然后，我们设定 i 指向的元素为基准数字。我们要做的事情，就是在一趟排序中，把那些比基准数字小的数，移动到前面。
 * 具体的算法如下：
 * (1)如果 j 指向的值大于等于基准数字（如果比基准大，直接跳过）
 *      j ++
 * (2)如果 j 指向的值小于基准数字，（如果比基准小，交换 i 和 j 位置的值）
 *      i ++
 *      swap(i， j)
 *      j ++
 *
 * 备注：在交换的时候，为什么要让i先向后移动呢？
 * 这是因为，在整个排序的过程中，i 前面指向的都是小于4的数字，i 后面指向的都是大于4的数字，
 * i 是左右两边的分界线。我们交换的目的是把小于4的交换到前面，把大于4的交换到后面，
 * 所以 i 要先向后移动1位，找到后面第一个大于4的数，然后把这个大于4的数，和后面小于4的数交换。
 *
 * 链接：https://blog.csdn.net/u010429424/article/details/77776731
 *
 * 提交结果：
 * 执行用时: 432 ms, 在所有 C++ 提交中击败了18.70%的用户
 * 内存消耗: 12.1 MB, 在所有 C++ 提交中击败了66.98%的用户
 */

ListNode *P0148_SortList::sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    QuickSortList(head, nullptr);
    return head;
}

//对链表进行快速排序
void P0148_SortList::QuickSortList(ListNode *pFirst, ListNode *pLast) {
    if (pFirst != pLast) {
        ListNode *pPos = Partition(pFirst, pLast);
        QuickSortList(pFirst, pPos);
        QuickSortList(pPos->next, pLast);
    }
}

//一趟快速排序的实现
ListNode *P0148_SortList::Partition(ListNode *pFirst, ListNode *pLast) {
    int temp = pFirst->val;
    ListNode *pStart = pFirst;
    ListNode *pCur = pFirst->next;

    while (pCur != nullptr && pCur != pLast) {
        if (pCur->val < temp) {
            pStart = pStart->next;
            swap(pStart, pCur);
            pCur = pCur->next;
        } else {
            pCur = pCur->next;
        }
    }
    //最后交换 pFirst 和 pStart 的值
    swap(pFirst, pStart);
    return pStart;
}

//交换 pNode1 和 pNode2 的值
void P0148_SortList::swap(ListNode *pNode1, ListNode *pNode2) {
    int temp = pNode1->val;
    pNode1->val = pNode2->val;
    pNode2->val = temp;
}
/***********************************************************************/
//归并排序实现
ListNode *P0148_SortList::mergesort(ListNode *node) {
    if (node == nullptr || node->next == nullptr)   //链表为空或者只有一个节点
        return node;

    ListNode *fast = node;  //快指针走两步
    ListNode *slow = node;  //慢指针走一步
    ListNode *brek = node;  //断点
    while (fast && fast->next) {
        fast = fast->next->next;
        brek = slow;
        slow = slow->next;
    }
    brek->next = nullptr;

    ListNode *l1 = mergesort(node);
    ListNode *l2 = mergesort(slow);
    return merge(l1, l2);
}

ListNode *P0148_SortList::merge(ListNode *l1, ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l2->next, l1);
        return l2;
    }
}

/***********************************************************************/
int P0148_SortList::test() {
    ListNode *p1 = new ListNode(3);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(1);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    ListNode *head = p1;
    sortList(head);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;
    return 0;
}
