// StudyForDataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SeqList.h"

int main()
{
	SeqList<int> nonelist;//�޲ι���õ������Ա�
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

