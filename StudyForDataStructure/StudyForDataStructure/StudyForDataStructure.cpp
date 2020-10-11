// StudyForDataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "SeqList.cpp"
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
	cout << "按值查询，返回其位置 " << list.findByValue(1) << endl;

	list.insert(10, 2);
	list.showData();
	list.deleteByIndex(list.findByValue(3));
	list.showData();
	system("pause");
	return 0;
}

