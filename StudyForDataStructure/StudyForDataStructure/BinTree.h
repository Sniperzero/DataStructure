#pragma once
// ���ݽṹ-���Ĵ���ͷ�ļ�
/*
	������Ҫʵ�ֿ��� ���� ������ ʵ��
	�����ʵ�� ���������Ϊ��ȫ��ʱ������һ����������������д����ռ��˷�
	�����ʵ�� ����һ��ı�ʾ�����������ʾ�����ɲ��ö���-�ֵܷ���child-sibling������������
	��������Ҫ�Ĳ����Ǳ����������ַ�Ϊǰ�� ���� ����
*/
#ifndef BINTREE_H_
#define BINTREE_H_
//#include "stdafx.h"
#include <iostream>
using namespace std;
// �������ṹ��
template <class elemType>
struct TreeNode
{
	elemType _data;
	TreeNode *_left;
	TreeNode *_right;
};
template <class elemType>
class BinTree 
{
private:
	TreeNode<elemType> *_head;//ͷ���
public:

};
#endif