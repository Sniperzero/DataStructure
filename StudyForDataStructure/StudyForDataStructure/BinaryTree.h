/*
	������
	���õݹ�ʵ��ǰ�����򣬺���
*/
#pragma once
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template<class elemType>
class BinaryTree 
{
public:
	BinaryTree() :root(NULL) {};
	BinaryTree(const BinaryTree &rhs) : root(NULL) {// �������ֶ���
		*this = rhs;//˭�������ֶ����ͷ���˭
	}
	BinaryTree & operator=(const BinaryTree &rhs);
	//~BinaryTree();//��ָ�� һ��Ҫ��big three

	void insert(const elemType & x)
	{
		insert(x, root);
		
	}
private:
	struct BinTreeNode // ��struct ��������
	{
		elemType _data;
		BinTreeNode * _left;
		BinTreeNode * _right;
		BinTreeNode(const elemType & _Data, BinTreeNode *lt, BinTreeNode *rt)
			: _data(_Data), _left(lt), _right(rt) { }//���캯��
	};
	BinTreeNode *root;//���ڵ�

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