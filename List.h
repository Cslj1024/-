#pragma once

#include "stdafx.h"
#include "MatchInfo.h"
class List
{
public:
	MatchInfo data;
	List *next;


	List();
	~List();

	void InitList(List *L);//��ʼ��
	void DestroyList(List *L);//����8 
	void ClearList(List *L);//���
	Status ListEmpty(List *L);//�п�
	int ListLength(List *L);//��
	Status GetMatch(List *L,int i,MatchInfo &m);
	int LocateMatch(List *L, MatchInfo m, Status(*Compare)(List *L,MatchInfo m));
	void ListInsert(List *L, int n);//β��
	Status ListDelete(List *L, MatchInfo &m);
	void ListTraverse(List *L);//����
	Status UpdateList(List *L, MatchInfo &m);
	Status Equal(List *L, MatchInfo m);
};

