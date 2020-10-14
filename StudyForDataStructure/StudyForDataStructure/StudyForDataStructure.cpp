// StudyForDataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include "SeqList.cpp"
#include "SeqList.h"
#include "LinkList.h"

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
	cout << "��ֵ��ѯ��������λ�� " << list.findByValue(1) << endl;
	list.insert(10, 2);
	list.showData();
	list.deleteByIndex(list.findByValue(3));
	list.showData();
	cout << "~~~~~~~~show link list~~~~~~~~~~~~" << endl;
	LinkList<int> nollist;//�޲ι���õ������Ա�
	int aa[] = { 9, 7, 6, 5 };
	LinkList<int> llist(aa, 4);
	cout << "output link list length : " << llist.length() << endl;
	llist.showLinkList();
	cout << "�����0,����ֵ������ֵ " << llist.findByKth(0) << endl;
	cout << "�����1,����ֵ������ֵ " << llist.findByKth(1) << endl;
	cout << "�����2,����ֵ������ֵ " << llist.findByKth(2) << endl;
	cout << "�����3,����ֵ������ֵ " << llist.findByKth(3) << endl;
	cout << endl;
	cout << "��ֵ9,������ţ�������� " << llist.findByValue(9) << endl;
	cout << "��ֵ7,������ţ�������� " << llist.findByValue(7) << endl;
	cout << "��ֵ6,������ţ�������� " << llist.findByValue(6) << endl;
	cout << "��ֵ5,������ţ�������� "<< llist.findByValue(5)<<endl;
	llist.insert(0, 0);//��0����ź����ֵ100
	cout << "��0����ź����ֵ0" << endl;
	llist.showLinkList();
	llist.insert(1, 1);//��2����ź����ֵ100
	cout << "��1����ź����ֵ1" << endl;
	llist.showLinkList();

	llist.insert(2, 2);//��2����ź����ֵ100
	cout << "��2����ź����ֵ2" << endl;
	llist.showLinkList();

	llist.insert(3, 3);//��3����ź����ֵ100
	cout << "��3����ź����ֵ3" << endl;
	llist.showLinkList();
	double da[] = { 9.1, 7.2, 6.3, 5.4 };
	LinkList<double> dllist(da, 4);
	cout << "9.1, 7.2, 6.3, 5.4 " << endl;
	cout << "remove 1 " << dllist.remove(1)<< endl;
	dllist.showLinkList();

	system("pause");
	return 0;
}

