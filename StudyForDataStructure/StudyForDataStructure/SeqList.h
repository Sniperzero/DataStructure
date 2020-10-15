#pragma once
/*˳�����Ա�ʵ�֣�*/
#ifndef SEQLIST_H_
#define SEQLIST_H_
//#include "stdafx.h"
#include <iostream>
using namespace std;

//typedef class LNode* List;
typedef int Position;// using Position = int;
const int MAXSIZE = 100;
//#define int ERROR = -1;
template <class elemType>
class SeqList
{
public:
	//��ʼ��
	SeqList() { Last = 0; };//�޲ι��캯��
	SeqList(const elemType array[], const int &n)//�вι��캯��
	{
		if (n > MAXSIZE) { cout << "The array is so large!" << endl; }
		else {
			for (int i = 0; i < n; i++) {
				Data[i] = array[i];
			}
			Last = n;
		}
	}
	~SeqList() {};//��������
	
	Position findByValue(elemType x)//���������У�����ĳ��Ԫ�س��ֵĵ�һ��λ�ã�����������λ��
	{
		{
			Position i = 0;
			while (i <= Last && Data[i] != x)
				i++;
			if (i > Last) return -1;
			else return i;
		}
	}
	void insert(elemType x, Position index) {
		if (Last == MAXSIZE - 1) { cout << "the array is full��" << endl; return; }
		if (index < 0 || index>(Last + 2)) { cout << "the array index is fault!" << endl; return; }
		for (int end = Last; end >= index - 1; end--) {
			Data[end + 1] = Data[end];//����ѭ���������һ��ֵ����������һ��
		}
		Data[index - 1] = x;//index-1 ����Ϊ��0 ��ʼ
		Last++;//���³���
		return;
	}
	void deleteByIndex(Position index) {
		if (Last == MAXSIZE - 1) { cout << "the array is full��" << endl; return; }
		if (index < 0 || index>(Last + 2)) { cout << "the array index is fault!" << endl; return; }
		for (; index < Last; index++) {
			Data[index - 1] = Data[index];
		}
		Last--;
		return;
	}
	void showLength() { cout << "length = " << Last << endl; }
	void showData() {
		cout << "show data: " << endl;
		for (Position i = 0; i < Last;i++) {
			cout << Data[i] << endl;
		}
	}
private:
	elemType Data[MAXSIZE];
	int Last;
};
#endif
/*
template <class elemType>
SeqList<elemType>::SeqList(const elemType array[], const int &n)//�вι��캯��
{// SeqList<elemType>::SeqList(const elemType array[], const int &n)
 // ����д�����link2019 �Ĵ���ԭ�������������ò�ƥ�䣿
	for (int i = 0; i < n; i++) {
		Data[i] = array[i];
	}
	Last = n;
}


#define int ERROR = -1;
template <class elemType>
Position SeqList<elemType>::findByValue(elemType x)
{
	Position i = 0;
	while (i <= Last && Data[i] != x)
		i++;
	if (i > Last) return ERROR;
	else return i;
}
*/


//#include "SeqList.cpp"

