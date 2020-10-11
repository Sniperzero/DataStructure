#pragma once
#ifndef SEQLIST_H_
#define SEQLIST_H_

#include <iostream>
using namespace std;

//typedef class LNode* List;
typedef int Position;// using Position = int;
const int MAXSIZE = 100;
template <class elemType>
class SeqList
{
public:
	//��ʼ��
	SeqList() { Last = 0; };//�޲ι��캯��
	SeqList(elemType array[], int n);//�вι��캯��
	~SeqList() {};//��������
	Position findByValue(elemType x);//���������У�����ĳ��Ԫ�أ�����������λ��

	void showLength() { cout << "length = " << Last << endl; }
private:

	elemType Data[MAXSIZE];
	int Last;
};
#endif