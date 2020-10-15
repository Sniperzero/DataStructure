#pragma once
/*单链式线性表实现：*/
#ifndef LINKLIST_H_
#define LINKLIST_H_
//#include "stdafx.h"
#include <iostream>
using namespace std;

template <class elemType>
struct LinkNode
{
	elemType _data;//数据
	LinkNode<elemType> *_next;//链指针（存储下一个节点的地址）
};

template <class elemType>
class LinkList
{
public:
	LinkList() { _head = new LinkNode<elemType>;_head->_next = NULL; }//无参构造函数
	LinkList(const elemType array[], const int &n) {
		_head = new LinkNode<elemType>;
		_head->_next = NULL;
		for (int i = 0; i < n; i++) {
			LinkNode<elemType> *p = new LinkNode<elemType>;
			p->_data = array[i];
			p->_next = _head->_next;
			_head->_next = p;//update
		}
	}
	~LinkList() {
		while (_head != NULL)
		{
			LinkNode<elemType>* q = _head;
			_head = _head->_next;
			delete q;
		}
	}
	int length() {
		// 从首节点开始 到最后一个结点 统计次数
		LinkNode<elemType>*p = _head->_next;
		int count = 0;
		while (p != NULL) {
			p = p->_next;
			count++;
		}
		return count;
	}
	elemType findByKth(int index) {
		LinkNode<elemType>*p = _head->_next;
		int count = 0;
		while (p != NULL&&count < index) {
			p = p->_next;
			count++;
		}
		if (count == index) { return p->_data; }// 找到返回指针p 即地址
	}

	int findByValue(elemType x) {
		LinkNode<elemType>*p = _head->_next;
		int count = 0;
		while (p != NULL && p->_data != x) {
			p = p->_next;
			count++;
		}
		return count;
	}
	void insert(int index, elemType x) {
		LinkNode<elemType>*p = _head->_next;
		LinkNode<elemType>*s = new LinkNode<elemType>;
		//if (index<1) { cout << "the index is fault!" << endl; }
		/*
		if (index == 0) {
			s->_data = x;
			s->_next = _head->_next;
			//_head->_next = s;//加上此句，会将第一个数据替换
		}
		*/
		int count = 1;// 必须是1	
		while (p != NULL ) {
			if (index == count - 1) { break; }
			p = p->_next;//此时 指针p 也就是指向struct LinkNode的指针，是指向第i-1个结点
			count++;
		}
		// 下面是关键
		s->_data = x;
		//p->_next = s;
		s->_next = p->_next;//把指向i-1 的下一个节点 赋给s
		// 本来p._next 是指向原来的下一个节点，现把他赋值给s._next
		p->_next = s;// 与上一行顺序不得互换 放到前面会出现死循环
	}
	elemType remove(int index) {
		LinkNode<elemType>*p = _head;
		cout << "p->_data:" << p->_data << endl;
		cout << "~~~" << endl;
		LinkNode<elemType> *q = new LinkNode<elemType>;
		int count = 1;// 必须是1	
		while (p != NULL ) {
			if (index == count - 1) { break; }
			p = p->_next;//找到第i-1个结点的 p
			cout << "p->_data:" << p->_data << endl;
			count++;
		}
		if (p == NULL || p->_next == NULL) throw "Location";
		else {
			cout << "~~~" << endl;
			cout << "p->_data:" << p->_data << endl;
			q = p->_next;// 临时保存被删除结点的地址，以备释放
			cout << "q->_data:" << q->_data << endl;
			elemType x = q->_data;// 保存要删除的结点值
			p->_next = q->_next;//令p->_next 指向index 的后继结点
			cout << "~~~" << endl;
			cout << "p->_data:" << p->_data << endl;
			delete(q);
			return x;
		}
	}
	void showLinkList() {
		LinkNode<elemType>*p = _head->_next;
		while (p != NULL) {
			cout <<"show data: " << p->_data << endl;
			cout << "show pointer address: " << p->_next << endl;
			cout << endl;
			p = p->_next;
		}
	}
private:
	LinkNode<elemType> *_head;//头结点
};
#endif
