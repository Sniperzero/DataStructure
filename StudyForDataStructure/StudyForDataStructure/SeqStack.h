#pragma once
/*	˳��ջʵ�֣�
	ջ��˳��ģ��Һ����ȳ������ݽṹ���ɽ�������Ϊһ������
	˳��ջ��������ʵ�ֵġ�
	��Ҫ���� ��push ��ջ ��pop ɾջ
	ʹ��һ�������ʵ������ջ����һ����ͷ���м䣬һ����β�͵��м�
*/
#ifndef SEQSTACK_H_
#define SEQSTACK_H_
//#include "stdafx.h"
#include <iostream>
using namespace std;
const int StackMAXSIZE = 100;

template <class elemType>
class SeqStack
{
public:
	SeqStack(){//�޲ι��캯��
		_Top = -1;//��ջ
	}
	SeqStack(elemType array[], int n) {		
		for (int i = 0; i < n; i++) {
			_data[i] = array[i];
		}
		_Top = n;
	}
	//~SeqStack();
	bool IsFull() {
		if (_Top == (StackMAXSIZE - 1)) {
			cout << "the stack is full! " << endl;
			return true;
		}
		return false;
	}
	bool IsEmpty() {
		if (_Top == -1) {
			cout << "the stack is empty! " << endl;
			return true;
		}
		return false;
	}
	void Push(elemType x) {
		if (!IsFull()) {
			_data[++_Top] = x;
			return;
		}
	}
	void Pop() {// pop ֻ�ܴ����һ��Ԫ�ؿ�ʼ�������β�
		if (!IsEmpty()) {
			_data[--_Top];
		}
		return;
	}
	void showData() {
		for (int i = 0; i <= _Top; i++) {
			cout << _data[i] << endl;
		}
		cout << "TOP: " << _Top << endl;
	}
private:
	elemType _data[StackMAXSIZE];
	int _Top;
};
// ˫˳��ջʵ��
const int DStackMAXSIZE = 4;
template <class elemType>
class DoubleSeqStack
{
private:
	elemType _ddata[DStackMAXSIZE];
	int _Top1;
	int _Top2;
public:
	DoubleSeqStack() { _Top1 = -1; _Top2 = DStackMAXSIZE; }
	// �вι��캯�� ���������Ǹ��ࡣ��ͬ����������ѭ����һ����ͷ���м䣬һ����β���м�
	void Push(elemType x, int tag) {
		if (_Top2 - _Top1 == 1) { cout << "the double stach is full! " << endl; return; }
		if (tag == 1) { _ddata[++_Top1] = x; }//tag Ϊ����ջ�ı�ʶ��
		else { _ddata[--_Top2] = x; }
	}
	void Pop(int tag) {
		if (tag == 1) {
			if (_Top1 == -1) { cout << "the left stack is empty;" << endl; return;}
			_ddata[_Top1--];
		}
		else {
			if (_Top2 == DStackMAXSIZE) { cout << "the right stach isempty! " << endl; return;}
			_ddata[_Top2++];
		}
	}
	void show() {
		cout << "the left Top1: " << _Top1 << endl;
		for (int i = 0; i <= _Top1; i++) { cout << _ddata[i] << endl; }
		cout << endl;

		cout << "the right Top2: " << _Top2 << endl;
		for (int j = DStackMAXSIZE-1; j >= _Top2;j--) { cout << _ddata[j] << endl; }
		
	}
};
//��ʽ ջ ʵ��
template <class elemType>
struct Node
{
	elemType _data;//����
	Node<elemType> *_next;//��ָ�루�洢��һ���ڵ�ĵ�ַ��
};

template <class elemType>
class LinkStack
{
private:
	Node<elemType> *_head;//ͷ���
public:
	LinkStack() { _head = new Node<elemType>; _head->_next = NULL; }//�޲ι��캯��
	~LinkStack() {
		while (_head != NULL)
		{
			Node<elemType>* q = _head;
			_head = _head->_next;
			delete q;
		}
	}
	void Push(elemType x) {
		//Node <elemType>*p = _head->_next;
		Node <elemType>*s = new Node<elemType>;
		cout << x << " push " << endl;
		s->_data = x;
		s->_next = _head;
		_head = s;
	}
	void Pop() {
		Node <elemType>*FirstCell = new Node<elemType>;
		cout << _head->_data << " pop " << endl;
		elemType Top;
		//Node <elemType>*p = _head->_next;
		if (_head->_next == NULL) { cout << "the stack is empty! " << endl; return; }
		FirstCell = _head;
		_head = FirstCell->_next;
		Top = FirstCell->_data;
		delete(FirstCell);
	}
	void Show() {
		Node<elemType>*p = _head->_next;
		while (p != NULL) {
			cout << "show data: " << p->_data << endl;
			cout << "show pointer address: " << p->_next << endl;
			cout << endl;
			p = p->_next;
		}
	}
};


#endif

/*
template <class elemType>
bool SeqStack<elemType>::IsFull() {
	if (_Top = (StackMAXSIZE - 1)) {
		cout << "the stack is full! " << endl;
		return true;
	}
	return false;
}
template <class elemType>
bool SeqStack<elemType>::IsEmpty() {
	if (_Top == -1) {
		cout << "the stack is empty! " << endl;
		return true;
	}
	return false;
}
template <class elemType>
void SeqStack<elemType>::showData() {
	for (int i = 0; i < _Top; i++) {
		cout << _data[i] << endl;
	}
}
*/