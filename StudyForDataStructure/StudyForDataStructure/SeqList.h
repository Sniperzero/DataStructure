#pragma once
/*顺序线性表实现：*/
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
	//初始化
	SeqList() { Last = 0; };//无参构造函数
	SeqList(const elemType array[], const int &n)//有参构造函数
	{
		if (n > MAXSIZE) { cout << "The array is so large!" << endl; }
		else {
			for (int i = 0; i < n; i++) {
				Data[i] = array[i];
			}
			Last = n;
		}
	}
	~SeqList() {};//析构函数
	
	Position findByValue(elemType x)//根据有序列，查找某个元素出现的第一个位置，并返回他的位置
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
		if (Last == MAXSIZE - 1) { cout << "the array is full！" << endl; return; }
		if (index < 0 || index>(Last + 2)) { cout << "the array index is fault!" << endl; return; }
		for (int end = Last; end >= index - 1; end--) {
			Data[end + 1] = Data[end];//倒着循环，把最后一个值赋给他的下一个
		}
		Data[index - 1] = x;//index-1 是因为从0 开始
		Last++;//更新长度
		return;
	}
	void deleteByIndex(Position index) {
		if (Last == MAXSIZE - 1) { cout << "the array is full！" << endl; return; }
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
SeqList<elemType>::SeqList(const elemType array[], const int &n)//有参构造函数
{// SeqList<elemType>::SeqList(const elemType array[], const int &n)
 // 这样写会出现link2019 的错误，原因是声明和引用不匹配？
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

