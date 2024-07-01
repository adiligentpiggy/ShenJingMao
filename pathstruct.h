#ifndef PATHSTRUCT_H
#define PATHSTRUCT_H

#include <QVector>
#include <QHash>
#include <QDebug>
const int nullInit = 999;

struct TreeNode {
    int val;
    int depth;
    QVector<TreeNode*> childList;

    TreeNode(int v = nullInit, int d = nullInit) :
    val(v), depth(d){}

    ~TreeNode()
    {
        TreeNode* n;
        foreach(n, childList)
            delete n;
    }
};

struct PathStruct {
    // 我们使用一个多叉树的结构来存储神经猫的路径，为了保证节点不会反向跳到自己的祖辈造成无限循环，
    // 这里按层次遍历方式建树，并用 QHash 存储祖辈及其所在层数。
    QHash<int, int> m_Hash;
    TreeNode *m_Node;

    PathStruct() { m_Node = NULL; }
    ~PathStruct() { delete m_Node; }
};

#endif // PATHSTRUCT_H
