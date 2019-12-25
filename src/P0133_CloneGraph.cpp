//
// Created by yongpu on 2019/12/4 20:09.
//

#include "P0133_CloneGraph.h"

/**
 * 题目：克隆图
 * 描述：给定无向连通图中一个节点的引用，返回该图的深拷贝(克隆).图中的每个节点都包含它的值 val(int)和其邻居的列表(list[Node]).
 * 思路：1.根据原来节点的节点数，和节点值创建新的节点；2.根据原来节点的对应关系，连接新的对应节点
 * 备注：理解大概思路即可
 */

/**
 * 为了实现克隆图的深度拷贝，首先需要创建与原图节点个数相等的新节点，然后再依照原图中边的连接规则，把新图中对应节点进行连接操作。
 * 简单来说克隆图分为两步：
 * 根据原来节点的节点数，和节点值创建新的节点，
 * 根据原来节点的对应关系，连接新的对应节点。
 * 1.根据原来节点的节点数，和节点值创建新的节点：
 *   首先通过广度优先遍历，遍历所有节点（BFS），每遍历到一个节点(Node)创建一个与之对应的新节点（Node_1），并利用map数据结构保存该节点(Node_1)与原节点(Node)的映射关系。
 * 2.根据原来节点的对应关系，连接新的对应节点：
 *   根据第一步，完成了所有节点的创建和新旧节点对应关系的保存；
 *   接下来只需按照原图的对应关系，将新创建的图进行连接；
 *   我们已将所有节点对应关系保存到map中，只需要遍历map中的所有原来节点,找到他的邻接节点数组，遍历该数组。然后按照该规则将新图的对应节点相连即可
 */

/**
 * {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},
 * {"$id":"3","neighbors":[{"$ref":"2"},
 * {"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
 *
 */

P0133_Node *P0133_CloneGraph::cloneGraph(P0133_Node *node) {
    P0133_Node *head = nullptr;
    if ( !node )  return NULL;

    queue<P0133_Node *> m_queue;	//利用队列实现图的广度优先遍历
    map<P0133_Node *,P0133_Node *> m_map;
    P0133_Node *temp;
    P0133_Node *p;

    m_queue.push(node);	 //第一个结点入队

    //首先BFS所有节点，创建新节点，并保存新节点与原节点的映射关系
    while(!m_queue.empty()){
        //出队元素
        temp = m_queue.front(); // 队首
        m_queue.pop();          // 队首出队
        //新节点创建
        p = new P0133_Node(temp->val,{});
        m_map.insert({temp,p});
        //入队元素
        for( P0133_Node *neighborsNode : temp->neighbors ) {
            if( m_map.find(neighborsNode) == m_map.end() ) {  //如果该节点已经有了映射关系，则不入队
                m_queue.push(neighborsNode);
            }
        }
    }

    //遍历所有节点 完成边的链接
    map<P0133_Node *,P0133_Node *>::iterator iter;
    for( iter = m_map.begin(); iter != m_map.end(); ++iter ){
        for( P0133_Node *neighborsNode : iter->first->neighbors ) {     // 遍历旧节点
            iter->second->neighbors.push_back(m_map.find(neighborsNode)->second);   // 找到对应的新节点建立与新节点的对应关系
        }
    }

    return m_map.find(node)->second;
}

int P0133_CloneGraph::test() {

    return 0;
}
