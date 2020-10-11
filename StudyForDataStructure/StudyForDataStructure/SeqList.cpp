#include "stdafx.h"
#include "SeqList.h"

template <class elemType>
SeqList::SeqList(const elemType array[], const int &n)//�вι��캯��
// SeqList<elemType>::SeqList(const elemType array[], const int &n)
// ����д�����link2019 �Ĵ���ԭ�������������ò�ƥ�䣿
{
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