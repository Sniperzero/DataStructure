/*
	二叉树
	采用递归实现前序，中序，后序
	除了递归 可采用堆栈实现遍历
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
	BinaryTree(const BinaryTree &rhs) : root(NULL) {// 调用这种东西
		*this = rhs;//谁调用这种东西就返回谁
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
	~BinaryTree() { makeEmpty(); }//析构函数
	//带指针 一定要有big three

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
		cout << "使用递归 前序遍历： " << endl;
		PreOrderShowBinTree(root);
	}
	void InOrderShowBinTree()
	{
		cout << "使用递归 中序遍历： " << endl;
		InOrderShowBinTree(root);
	}
	void PostOrderShowBinTree()
	{
		cout << "使用递归 后序遍历： " << endl;
		PostOrderShowBinTree(root);
	}
	void InOrderShowBinTreeByStack()
	{
		cout << "使用栈 中序遍历： " << endl;
		InOrderShowBinTreeByStack(root);
	}
	void PreOrderShowBinTreeByStack()
	{
		cout << "使用栈 前序遍历： " << endl;
		PreOrderShowBinTreeByStack(root);
	}
	void PostOrderShowBinTreeByStack()
	{
		cout << "使用栈 后序遍历： " << endl;
		PostOrderShowBinTreeByStack(root);
	}
	void LevelOrderShowBinTreeByqueue()
	{
		cout << "使用队列 层序遍历： " << endl;
		LevelOrderShowBinTreeByqueue(root);
	}
	void DepthOrderShowBinTreeByStack()
	{
		cout << "使用栈 深度优先 层序遍历： " << endl;
		DepthOrderShowBinTreeByStack(root);
	}
	
	void PreOrderPrintLeaves()// 输出叶子结点
	{
		cout << "输出叶子结点： " << endl;
		PreOrderPrintLeaves(root);
	}
	int PostOrderGerHeight()
	{
		cout << "输出树的高度： " << endl;
		int height = PostOrderGerHeight(root);
		cout << "高度= " << height << endl;
		return height;
	}
private:
	struct BinTreeNode // 把struct 放在类内
	{
		elemType _data;
		BinTreeNode * _left;
		BinTreeNode * _right;
		BinTreeNode(const elemType & _Data, BinTreeNode *lt, BinTreeNode *rt)
			: _data(_Data), _left(lt), _right(rt) { }//构造函数
		BinTreeNode() :_left(NULL), _right(NULL) {};
	};
	BinTreeNode *root;//根节点
	/*将每个结点置空，采用递归*/
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
	/*插入构建二叉树，此二叉树的插入时按大小*/
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
	/*前序创建二叉树
	  input： 插入元素，可为一个字符数组或vector；pos为位置迭代变量
	*/
	BinTreeNode *PreCreateBinTree(elemType &s, int &pos)
	{
		++pos;
		BinTreeNode *t;
		if ((unsigned)pos >= s.size())
			return NULL;
		else {
			if (s[pos] == '#')// #为结束符
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
		stack<BinTreeNode *> st;//创建一个栈
		// 自己创建栈的方法无法使用，因为缺失一个实现t = st.top();的方法
		/*
		cout << t->_data << endl;
		t = t->_left;
		cout << t->_data << endl;
		*/
		//BinTreeNode tt = t;
		while (t || !st.empty())
		{
			while (t) {/*一直向左，沿途结点压入栈*/
				st.push(t);
				t = t->_left;//向左更新t
			}
			//st.showData();
			if (!st.empty()) {
				t = st.top();//将栈顶元素赋值给t
				st.pop();/*节点弹出栈*/
				cout << t->_data << endl;/*打印结点*/
				t = t->_right;/*转向右子树*/
			}
		}
	}

	void PreOrderShowBinTreeByStack(BinTreeNode * t)
	{
		stack<BinTreeNode *> st;//创建一个栈
		while (t != NULL || !st.empty())
		{
			while (t != NULL) {/*一直向左，沿途结点压入栈*/
				cout << t->_data << endl;/*打印结点*/
				st.push(t);
				t = t->_left;//向左更新t
			}
			//st.showData();
			if (!st.empty()) {
				t = st.top();//将栈顶元素赋值给t
				st.pop();/*节点弹出栈*/
				t = t->_right;/*转向右子树*/
			}
		}
	}
	void PostOrderShowBinTreeByStack(BinTreeNode * t)
	{
		stack<BinTreeNode *> st;//创建一个栈
		BinTreeNode *r = NULL;//标记指针，标记该结点是否被访问过
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
					// 有右儿子，且未被访问
					t = t->_right;
				}
				else {
					// 若无右儿子，则出栈，并访问该栈顶元素
					st.pop();//出栈
					cout << t->_data << endl;//访问该栈顶元素
					r = t;//若该元素被访问，则标记该元素
					t = NULL;//节点访问完，重置节点
					// 若无上面语句，则当树遍历到最左端，会陷入死循环
					/*原因是因为当不置于NULL时。t依然指向该栈顶结点，即最开始遍历到最左端的那个结点
					此时，该结点又会进入两个循环语句，在内循环中跳入该else 语句，最后不断进行重复
					不断输出 该栈顶结点，随陷入死循环。*/
				}
			}
		}
			
	}

	void LevelOrderShowBinTreeByqueue(BinTreeNode * t)
	{
		if (t == NULL) { return; }
		queue<BinTreeNode *> qt;//创建一个队列
		qt.push(t);//根节点入队
		while (!qt.empty())
		{
			t = qt.front();//s使t指向队列首元素
			qt.pop();//首元素出队
			cout << t->_data << endl;
			if (t->_left){qt.push(t->_left);}//如果左儿子非空，则左儿子入队
			if (t->_right){qt.push(t->_right);}//如果右儿子非空，则右儿子入队
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