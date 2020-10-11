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
	//初始化
	SeqList() { Last = 0; };//无参构造函数
	SeqList(elemType array[], int n);//有参构造函数
	~SeqList() {};//析构函数
	Position findByValue(elemType x);//根据有序列，查找某个元素，并返回他的位置

	void showLength() { cout << "length = " << Last << endl; }
private:

	elemType Data[MAXSIZE];
	int Last;
};
#endif