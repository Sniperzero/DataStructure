// StudyForDataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "SeqList.cpp"
#include "SeqList.h"
#include "LinkList.h"

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
	cout << "~~~~~~~~show link list~~~~~~~~~~~~" << endl;
	LinkList<int> nollist;//无参构造得到的线性表
	int aa[] = { 9, 7, 6, 5 };
	LinkList<int> llist(aa, 4);
	cout << "output link list length : " << llist.length() << endl;
	llist.showLinkList();
	cout << "按序号0,查找值，返回值 " << llist.findByKth(0) << endl;
	cout << "按序号1,查找值，返回值 " << llist.findByKth(1) << endl;
	cout << "按序号2,查找值，返回值 " << llist.findByKth(2) << endl;
	cout << "按序号3,查找值，返回值 " << llist.findByKth(3) << endl;
	cout << endl;
	cout << "按值9,查找序号，返回序号 " << llist.findByValue(9) << endl;
	cout << "按值7,查找序号，返回序号 " << llist.findByValue(7) << endl;
	cout << "按值6,查找序号，返回序号 " << llist.findByValue(6) << endl;
	cout << "按值5,查找序号，返回序号 "<< llist.findByValue(5)<<endl;
	llist.insert(0, 0);//第0个序号后插入值100
	cout << "第0个序号后插入值0" << endl;
	llist.showLinkList();
	llist.insert(1, 1);//第2个序号后插入值100
	cout << "第1个序号后插入值1" << endl;
	llist.showLinkList();

	llist.insert(2, 2);//第2个序号后插入值100
	cout << "第2个序号后插入值2" << endl;
	llist.showLinkList();

	llist.insert(3, 3);//第3个序号后插入值100
	cout << "第3个序号后插入值3" << endl;
	llist.showLinkList();
	double da[] = { 9.1, 7.2, 6.3, 5.4 };
	LinkList<double> dllist(da, 4);
	cout << "9.1, 7.2, 6.3, 5.4 " << endl;
	cout << "remove 1 " << dllist.remove(1)<< endl;
	dllist.showLinkList();

	system("pause");
	return 0;
}

