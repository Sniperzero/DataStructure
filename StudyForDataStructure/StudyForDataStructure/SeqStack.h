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