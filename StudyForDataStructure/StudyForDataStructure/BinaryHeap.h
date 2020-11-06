/*
	�ѣ����ȶ��У���ʵ��ͷ�ļ���ʹ����ȫ��������ʾ��ʹ������ʵ��
	�������Ѻ���С��
*/

#pragma once
#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include<iostream>
#include<vector>
// ��С��ʵ�ִ���
template<class elemType>
class BinaryHeap
{
private:
	vector<elemType> _array;
	int _currentSize;
	/**
	* Establish heap order property from an arbitrary
	* arrangement of items. Runs in linear time.
	*/
	void buildHeap()
	{
		/*
		// �Ӻ���ǰ��һ��һ���ѽ���ѭ������
		������˵����ѭ���������һ��Ԫ�أ�Ҷ�ڵ㣩�ĸ��������ɵĶѣ���6��Ԫ�ص����飬���һ��Ԫ�صĸ���Ϊ6/2=3
		�����������Ǹ��ѣ���ʱi-- ��3-- =2��2������3Ϊ�ֵܵ��Ǹ��ѣ����д���
		����ѭ�������Ƚϸ��ڵ㣬����ɶѵ����򻯴������
		*/
		for (int i = _currentSize / 2; i > 0; i--)
			percolateDown(i);
	}
	/**
	* Internal method to percolate down in the heap.
	* hole is the index at which the percolate begins.
	*/
	void percolateDown(int hole)
	{
		int child;
		elemType tmp = _array[hole];
		for (; hole * 2 <= _currentSize; hole = child)
		{
			child = hole * 2;
			if (child != _currentSize && _array[child + 1] < _array[child])
				child++;
			if (_array[child] < tmp)
				_array[hole] = _array[child];
			else
				break;
		}
		_array[hole] = tmp;
	}
public:
	BinaryHeap(int capacity = 100)
		:_array(capacity + 1), _currentSize(0){}
	BinaryHeap(const vector<elemType> & items)
		:_array(items.size() + 10), _currentSize(items.size())
	{
		for (int i = 0; i < items.size(); i++) {
			_array[i + 1] = items[i];//����ʵ�ֶѵ�����
		}
		/*
		// ������������һ�����������
		// ��ʱ���ִ������ȫ��������Ȼ�������������
		*/
		buildHeap();
	}

	bool isempty()
	{
		if (_currentSize == 0)
			return true;
		else
			return false;
	}
	const elemType & findMin() const
	{
		if (isempty())
			//throw
			cout << "error!" << endl;
		else
			return _array[1];
	}
	void insert(const elemType &x)
	{
		if (isempty()) {
			cout << "��Ϊ�գ�" << endl;
			return;
		}
		if (_currentSize == _array.size() - 1) {
			_array.resize(_array.size() * 2);
		}
		
		int hole = ++_currentSize;//�������ĩβ��Ҳ����ȫ��������Ҷ���
		/* hole>1 Ҳ��ʹ���ڱ�����������0��λ�ã���ֵ��һ����������С���������ֵ
			��ʱ���ж������Ͳ���Ҫ�� hole>1,��Ч�ʻ����
		*/
		for (; hole > 1 && _array[hole / 2] > x; hole= hole / 2) {//������ڵ���ڲ����ֵ����ѭ��
			_array[hole] = _array[hole / 2];// �����ڵ�ֵ��ֵ��Ҫ�����λ�ã���ȫ��������Ҷ�ڵ㣩
		}
		_array[hole] = x;	
	}
	void deleteMin()
	{
		if(isempty()) {
			cout << "��Ϊ�գ�" << endl;
			return;
		}
		//elemType minValue = _array[1];
		elemType temp = _array[_currentSize--];
		int child, parent;
		for (parent = 1; parent * 2 <= _currentSize; parent = child) {
			child = 2 * parent;//�����
			if (child != _currentSize&&_array[child] > _array[child + 1]) {
				// �����ǰ�ڵ㻹��������뵱ǰ�ڵ�����Ӵ����Ҷ���ͬʱ����
				child++;//��Ϊ�Ҷ���С����childΪ�Ҷ���
			}
			if (temp < _array[parent]) {
				break;
				// ���Ҷ�ڵ�ȵ�ǰparent�ڵ�ֵС��ֱ��break ��Ҷ�ڵ㸳����ǰparent�ڵ�
			}
			else {
				_array[parent] = _array[child];
				//���Ҷ�ڵ�ȵ�ǰparent�ڵ�ֵ����ѵ�ǰ���Ҷ�����С�ĸ�ֵ����ǰparent�ڵ�
			}
		}
		_array[parent] = temp;
	}
};
#endif