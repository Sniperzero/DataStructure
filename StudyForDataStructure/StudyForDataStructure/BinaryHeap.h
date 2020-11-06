/*
	堆（优先队列）的实现头文件，使用完全二叉树表示，使用数组实现
	可有最大堆和最小堆
*/

#pragma once
#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include<iostream>
#include<vector>
// 最小堆实现代码
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
		// 从后向前，一个一个堆进行循环处理
		具体来说：先循环数组最后一个元素（叶节点）的父亲所构成的堆，入6个元素的数组，最后一个元素的父亲为6/2=3
		处理完上面那个堆，此时i-- 即3-- =2，2就是与3为兄弟的那个堆，进行处理，
		不断循环，最后比较根节点，即完成堆的有序化处理过程
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
			_array[i + 1] = items[i];//构造实现堆的数组
		}
		/*
		// 当输入数组是一个无序的数组
		// 此时可现处理成完全二叉树，然后进行有序化排序
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
			cout << "堆为空！" << endl;
			return;
		}
		if (_currentSize == _array.size() - 1) {
			_array.resize(_array.size() * 2);
		}
		
		int hole = ++_currentSize;//到数组的末尾，也是完全二叉树的叶结点
		/* hole>1 也可使用哨兵，即在数组0的位置，赋值给一个绝不能在小于这个数的值
			此时，判断条件就不需要用 hole>1,且效率会提高
		*/
		for (; hole > 1 && _array[hole / 2] > x; hole= hole / 2) {//如果父节点大于插入的值进行循环
			_array[hole] = _array[hole / 2];// 将父节点值赋值给要插入的位置（完全二叉树的叶节点）
		}
		_array[hole] = x;	
	}
	void deleteMin()
	{
		if(isempty()) {
			cout << "堆为空！" << endl;
			return;
		}
		//elemType minValue = _array[1];
		elemType temp = _array[_currentSize--];
		int child, parent;
		for (parent = 1; parent * 2 <= _currentSize; parent = child) {
			child = 2 * parent;//左儿子
			if (child != _currentSize&&_array[child] > _array[child + 1]) {
				// 如果当前节点还有左儿子与当前节点左儿子大于右儿子同时成立
				child++;//因为右儿子小，故child为右儿子
			}
			if (temp < _array[parent]) {
				break;
				// 如果叶节点比当前parent节点值小，直接break 将叶节点赋给当前parent节点
			}
			else {
				_array[parent] = _array[child];
				//如果叶节点比当前parent节点值大，则把当前左右儿子中小的赋值给当前parent节点
			}
		}
		_array[parent] = temp;
	}
};
#endif