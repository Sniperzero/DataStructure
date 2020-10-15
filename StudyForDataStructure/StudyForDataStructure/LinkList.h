#pragma once
/*����ʽ���Ա�ʵ�֣�*/
#ifndef LINKLIST_H_
#define LINKLIST_H_
//#include "stdafx.h"
#include <iostream>
using namespace std;

template <class elemType>
struct LinkNode
{
	elemType _data;//����
	LinkNode<elemType> *_next;//��ָ�루�洢��һ���ڵ�ĵ�ַ��
};

template <class elemType>
class LinkList
{
public:
	LinkList() { _head = new LinkNode<elemType>;_head->_next = NULL; }//�޲ι��캯��
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
		// ���׽ڵ㿪ʼ �����һ����� ͳ�ƴ���
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
		if (count == index) { return p->_data; }// �ҵ�����ָ��p ����ַ
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
			//_head->_next = s;//���ϴ˾䣬�Ὣ��һ�������滻
		}
		*/
		int count = 1;// ������1	
		while (p != NULL ) {
			if (index == count - 1) { break; }
			p = p->_next;//��ʱ ָ��p Ҳ����ָ��struct LinkNode��ָ�룬��ָ���i-1�����
			count++;
		}
		// �����ǹؼ�
		s->_data = x;
		//p->_next = s;
		s->_next = p->_next;//��ָ��i-1 ����һ���ڵ� ����s
		// ����p._next ��ָ��ԭ������һ���ڵ㣬�ְ�����ֵ��s._next
		p->_next = s;// ����һ��˳�򲻵û��� �ŵ�ǰ��������ѭ��
	}
	elemType remove(int index) {
		LinkNode<elemType>*p = _head;
		cout << "p->_data:" << p->_data << endl;
		cout << "~~~" << endl;
		LinkNode<elemType> *q = new LinkNode<elemType>;
		int count = 1;// ������1	
		while (p != NULL ) {
			if (index == count - 1) { break; }
			p = p->_next;//�ҵ���i-1������ p
			cout << "p->_data:" << p->_data << endl;
			count++;
		}
		if (p == NULL || p->_next == NULL) throw "Location";
		else {
			cout << "~~~" << endl;
			cout << "p->_data:" << p->_data << endl;
			q = p->_next;// ��ʱ���汻ɾ�����ĵ�ַ���Ա��ͷ�
			cout << "q->_data:" << q->_data << endl;
			elemType x = q->_data;// ����Ҫɾ���Ľ��ֵ
			p->_next = q->_next;//��p->_next ָ��index �ĺ�̽��
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
	LinkNode<elemType> *_head;//ͷ���
};
#endif
