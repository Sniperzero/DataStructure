/*
	二叉树
	采用递归实现前序，中序，后序
*/
#pragma once
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template<class elemType>
class BinaryTree 
{
public:
	BinaryTree() :root(NULL) {};
	BinaryTree(const BinaryTree &rhs) : root(NULL) {// 调用这种东西
		*this = rhs;//谁调用这种东西就返回谁
	}
	BinaryTree & operator=(const BinaryTree &rhs);
	//~BinaryTree();//带指针 一定要有big three

	void insert(const elemType & x)
	{
		insert(x, root);
		
	}
private:
	struct BinTreeNode // 把struct 放在类内
	{
		elemType _data;
		BinTreeNode * _left;
		BinTreeNode * _right;
		BinTreeNode(const elemType & _Data, BinTreeNode *lt, BinTreeNode *rt)
			: _data(_Data), _left(lt), _right(rt) { }//构造函数
	};
	BinTreeNode *root;//根节点

	void insert(const elemType &x, BinTreeNode * & t)
	{
		if (t == NULL)
			t = new BinTreeNode(x, NULL, NULL);
		else if (x < t->_data)
			insert(x, t->_left);
		else if (x > t->_data)
			insert(x, t->_right);
		else
			;
	}
};
#endif