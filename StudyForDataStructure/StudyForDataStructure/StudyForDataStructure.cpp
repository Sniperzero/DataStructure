// StudyForDataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SeqList.h"

int main()
{
	SeqList<int> nonelist;//无参构造得到的线性表
	nonelist.showLength();
	cout << "~~~~~~~~~~~~~~" << endl;
	int a[] = { 1, 2, 3 };
	//cout << sizeof(a)/4 << endl;
	SeqList<int> list(a,3);
	list.showLength();
	list.showData();
	system("pause");
	return 0;
}

