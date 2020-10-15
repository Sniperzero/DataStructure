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
			-_ddata[_Top2++];
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