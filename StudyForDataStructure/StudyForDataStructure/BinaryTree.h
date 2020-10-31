/*
	������
	���õݹ�ʵ��ǰ�����򣬺���
	���˵ݹ� �ɲ��ö�ջʵ�ֱ���
*/
#pragma once
#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "SeqStack.h"
#include<stack>
#include<queue>

#include<string>

template<class elemType>
class BinaryTree 
{
public:
	BinaryTree() :root(NULL) {};
	BinaryTree(const BinaryTree &rhs) : root(NULL) {// �������ֶ���
		*this = rhs;//˭�������ֶ����ͷ���˭
	}
	BinaryTree & operator=(const BinaryTree &rhs)
	{
		if (this != &rhs)
		{
			makeEmpty();
			root = clone(rhs.root);
		}
		return *this;
	}
	~BinaryTree() { makeEmpty(); }//��������
	//��ָ�� һ��Ҫ��big three

	void makeEmpty()
	{
		makeEmpty(root);
	}

	void insert(const elemType & x)
	{
		insert(x, root);
		
	}
	void PreCreatBinTree(elemType x)
	{
		int pos = -1;
		root =PreCreateBinTree(x,pos);
		
	}
	void PreOrderShowBinTree()
	{
		cout << "ʹ�õݹ� ǰ������� " << endl;
		PreOrderShowBinTree(root);
	}
	void InOrderShowBinTree()
	{
		cout << "ʹ�õݹ� ��������� " << endl;
		InOrderShowBinTree(root);
	}
	void PostOrderShowBinTree()
	{
		cout << "ʹ�õݹ� ��������� " << endl;
		PostOrderShowBinTree(root);
	}
	void InOrderShowBinTreeByStack()
	{
		cout << "ʹ��ջ ��������� " << endl;
		InOrderShowBinTreeByStack(root);
	}
	void PreOrderShowBinTreeByStack()
	{
		cout << "ʹ��ջ ǰ������� " << endl;
		PreOrderShowBinTreeByStack(root);
	}
	void PostOrderShowBinTreeByStack()
	{
		cout << "ʹ��ջ ��������� " << endl;
		PostOrderShowBinTreeByStack(root);
	}
	void LevelOrderShowBinTreeByqueue()
	{
		cout << "ʹ�ö��� ��������� " << endl;
		LevelOrderShowBinTreeByqueue(root);
	}
	void DepthOrderShowBinTreeByStack()
	{
		cout << "ʹ��ջ ������� ��������� " << endl;
		DepthOrderShowBinTreeByStack(root);
	}
	
	void PreOrderPrintLeaves()// ���Ҷ�ӽ��
	{
		cout << "���Ҷ�ӽ�㣺 " << endl;
		PreOrderPrintLeaves(root);
	}
	int PostOrderGerHeight()
	{
		cout << "������ĸ߶ȣ� " << endl;
		int height = PostOrderGerHeight(root);
		cout << "�߶�= " << height << endl;
		return height;
	}
private:
	struct BinTreeNode // ��struct ��������
	{
		elemType _data;
		BinTreeNode * _left;
		BinTreeNode * _right;
		BinTreeNode(const elemType & _Data, BinTreeNode *lt, BinTreeNode *rt)
			: _data(_Data), _left(lt), _right(rt) { }//���캯��
		BinTreeNode() :_left(NULL), _right(NULL) {};
	};
	BinTreeNode *root;//���ڵ�
	/*��ÿ������ÿգ����õݹ�*/
	void makeEmpty(BinTreeNode * & t)
	{
		if (t != NULL)
		{
			makeEmpty(t->_left);
			makeEmpty(t->_right);
			delete t;
		}
		t = NULL;
	}
	/*���빹�����������˶������Ĳ���ʱ����С*/
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
	BinTreeNode *clone(BinTreeNode *t)const
	{
		if (t == NULL)
			return NULL;
		else
			return new BinTreeNode(t->_data, clone(t->_left), clone(t->_right));
	}
	/*ǰ�򴴽�������
	  input�� ����Ԫ�أ���Ϊһ���ַ������vector��posΪλ�õ�������
	*/
	BinTreeNode *PreCreateBinTree(elemType &s, int &pos)
	{
		++pos;
		BinTreeNode *t;
		if ((unsigned)pos >= s.size())
			return NULL;
		else {
			if (s[pos] == '#')// #Ϊ������
				t = NULL;
			else {
				t = new BinTreeNode;
				t->_data = s[pos];
				t->_left = PreCreateBinTree(s, pos);
				t->_right = PreCreateBinTree(s, pos);
			}
			//cout << t->_data;
			return t;
		}
	}
	
	void PreOrderShowBinTree(BinTreeNode * t)
	{
		if (t != NULL) {
			cout << t->_data << endl;
			PreOrderShowBinTree(t->_left);
			PreOrderShowBinTree(t->_right);
		}

	}

	void InOrderShowBinTree(BinTreeNode * t)
	{
		if (t != NULL) {
			InOrderShowBinTree(t->_left);
			cout << t->_data << endl;
			InOrderShowBinTree(t->_right);
		}

	}
	void PostOrderShowBinTree(BinTreeNode * t)
	{
		if (t != NULL) {
			PostOrderShowBinTree(t->_left);
			PostOrderShowBinTree(t->_right);
			cout << t->_data << endl;
		}
	}
	void InOrderShowBinTreeByStack(BinTreeNode * t)
	{
		stack<BinTreeNode *> st;//����һ��ջ
		// �Լ�����ջ�ķ����޷�ʹ�ã���Ϊȱʧһ��ʵ��t = st.top();�ķ���
		/*
		cout << t->_data << endl;
		t = t->_left;
		cout << t->_data << endl;
		*/
		//BinTreeNode tt = t;
		while (t || !st.empty())
		{
			while (t) {/*һֱ������;���ѹ��ջ*/
				st.push(t);
				t = t->_left;//�������t
			}
			//st.showData();
			if (!st.empty()) {
				t = st.top();//��ջ��Ԫ�ظ�ֵ��t
				st.pop();/*�ڵ㵯��ջ*/
				cout << t->_data << endl;/*��ӡ���*/
				t = t->_right;/*ת��������*/
			}
		}
	}

	void PreOrderShowBinTreeByStack(BinTreeNode * t)
	{
		stack<BinTreeNode *> st;//����һ��ջ
		while (t != NULL || !st.empty())
		{
			while (t != NULL) {/*һֱ������;���ѹ��ջ*/
				cout << t->_data << endl;/*��ӡ���*/
				st.push(t);
				t = t->_left;//�������t
			}
			//st.showData();
			if (!st.empty()) {
				t = st.top();//��ջ��Ԫ�ظ�ֵ��t
				st.pop();/*�ڵ㵯��ջ*/
				t = t->_right;/*ת��������*/
			}
		}
	}
	void PostOrderShowBinTreeByStack(BinTreeNode * t)
	{
		stack<BinTreeNode *> st;//����һ��ջ
		BinTreeNode *r = NULL;//���ָ�룬��Ǹý���Ƿ񱻷��ʹ�
		while (t!=NULL || !st.empty())
		{
			while (t!=NULL)
			{
				st.push(t);
				t = t->_left;
			}
			if (!st.empty())
			{
				t = st.top();
				if (t->_right != NULL && t->_right != r) {
					// ���Ҷ��ӣ���δ������
					t = t->_right;
				}
				else {
					// �����Ҷ��ӣ����ջ�������ʸ�ջ��Ԫ��
					st.pop();//��ջ
					cout << t->_data << endl;//���ʸ�ջ��Ԫ��
					r = t;//����Ԫ�ر����ʣ����Ǹ�Ԫ��
					t = NULL;//�ڵ�����꣬���ýڵ�
					// ����������䣬��������������ˣ���������ѭ��
					/*ԭ������Ϊ��������NULLʱ��t��Ȼָ���ջ����㣬���ʼ����������˵��Ǹ����
					��ʱ���ý���ֻ��������ѭ����䣬����ѭ���������else ��䣬��󲻶Ͻ����ظ�
					������� ��ջ����㣬��������ѭ����*/
				}
			}
		}
			
	}

	void LevelOrderShowBinTreeByqueue(BinTreeNode * t)
	{
		if (t == NULL) { return; }
		queue<BinTreeNode *> qt;//����һ������
		qt.push(t);//���ڵ����
		while (!qt.empty())
		{
			t = qt.front();//sʹtָ�������Ԫ��
			qt.pop();//��Ԫ�س���
			cout << t->_data << endl;
			if (t->_left){qt.push(t->_left);}//�������ӷǿգ�����������
			if (t->_right){qt.push(t->_right);}//����Ҷ��ӷǿգ����Ҷ������
		}
	}
	void DepthOrderShowBinTreeByStack(BinTreeNode * t)
	{
		
	}
	void PreOrderPrintLeaves(BinTreeNode * t)
	{
		if (t == NULL) {return;}
		if (t->_left == NULL && t->_right == NULL) {
			cout << t->_data << endl;
		}
			PreOrderPrintLeaves(t->_left);
			PreOrderPrintLeaves(t->_right);
	}
	int PostOrderGerHeight(BinTreeNode * t)
	{
		int HL, HR, MaxH;
		if (t != NULL)
		{
			HL = PostOrderGerHeight(t->_left);
			HR = PostOrderGerHeight(t->_right);
			MaxH = (HL > HR) ? HL : HR;
			return (MaxH + 1);
		}
		else
			return 0;
	}
};
#endif