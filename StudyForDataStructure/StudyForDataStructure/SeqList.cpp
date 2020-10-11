#include "stdafx.h"
#include "SeqList.h"

template <class elemType>
SeqList<elemType>::SeqList(elemType array[], int n)//有参构造函数
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