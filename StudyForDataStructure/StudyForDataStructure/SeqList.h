#pragma once

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
		for (int i = 0; i < n; i++) {
			Data[i] = array[i];
		}
		Last = n;
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

