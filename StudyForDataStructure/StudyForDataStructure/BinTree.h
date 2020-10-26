#pragma once
// 数据结构-树的代码头文件
/*
	树的主要实现可由 数组 和链表 实现
	数组的实现 最好是在树为完全树时，对于一般的树来讲，可能有大量空间浪费
	链表的实现 对于一般的表示很难用链表表示，但可采用儿子-兄弟法（child-sibling），即二叉树
	树中最重要的操作是遍历，遍历又分为前序 中序 后序
*/
#ifndef BINTREE_H_
#define BINTREE_H_
//#include "stdafx.h"
#include <iostream>
using namespace std;
// 二叉树结构体
template <class elemType>
struct TreeNode
{
	elemType _data;
	TreeNode *_left;
	TreeNode *_right;
};
template <class elemType>
class BinTree 
{
private:
	TreeNode<elemType> *_head;//头结点
public:

};
#endif