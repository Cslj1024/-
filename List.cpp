#include "stdafx.h"
#include "List.h"


List::List()
{
}


List::~List()
{
}

void List::InitList(List *L)
{
	L->next = NULL;
}

void List::DestroyList(List * L)
{
	List *p;
	while (L) {
		p = L->next;
		free(L);
		L = p;
	}
}

void List::ClearList(List * L)
{
	List *p, *q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

Status List::ListEmpty(List * L)
{
	if (L->next)
		return TRUE;
	else
		return FALSE;
}

int List::ListLength(List * L)
{
	int i = 0;
	List *p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;

}

Status List::GetMatch(List * L, int i, MatchInfo & m)
{
	cout << "��ǰ�Ǳ�����Ϣ���ҽ���: " << endl << endl;
	int j = 1;
	List *p = L->next;
	while (p&&j < i) {
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	m = p->data;
	return OK;
	return Status();
}

int List::LocateMatch(List * L, MatchInfo m, Status(*Compare)(List *L, MatchInfo m))
{
	int i = 0;
	List *p = L->next;
	while (p) {
		i++;
		if (Compare(p, m))
			return i;
		p = p->next;
	}
	return 0;
}

void List::ListInsert(List * L, int n)
{
	cout << "��ǰ�Ǳ�����Ϣ��ӽ���: " << endl << endl;
	List *p = NULL, *q = L;
	cout << "��������Ϣ�������� "; cin >> n;
	cout << endl;
	cout << "���\t\t" << "��Ŀ\t\t\t\t" << "ʱ��\t\t" << "�ص�\t" << "����\t" << "������\t\t" << endl << endl;

	while (q->next)
		q = q->next;

	for (int i = 0; i < n; i++) {
		p = new List();
		cin >> p->data.matchID
			>> p->data.matchTitle
			>> p->data.matchTime
			>> p->data.matchAddress
			>> p->data.matchContent
			>> p->data.matchPrincipal;
		q->next = p;
		q = q->next;
	}
	p->next = NULL;
	cout << endl;
}

Status List::ListDelete(List *L, MatchInfo & m)
{
	int find = 0;
	string id;
	cout << "��ǰ�Ǳ�����Ϣɾ������: " << endl << endl;
	cout << "����������:";
	cin >> id;

	List *p = L;
	List *q = p->next;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			find = 1;
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}

	if (find == 0)
		cout << "�������" << id << "������" << endl << endl;

	return Status();
}

void List::ListTraverse(List * L)
{
	List *p = L->next;
	while (p) {
		cout << p->data.matchID << "\t"
			<< p->data.matchTitle << "\t"
			<< p->data.matchTime << "\t"
			<< p->data.matchAddress << "\t"
			<< p->data.matchContent << "\t"
			<< p->data.matchPrincipal << endl << endl;
		p = p->next;
	}
}

Status List::UpdateList(List * L, MatchInfo & m)
{
	int find = 0;
	string id;
	cout << "��ǰ�Ǳ�����Ϣ�޸Ľ���: " << endl << endl;
	cout << "����������:";
	cin >> id;
	List *p = L;
	List *q = p->next;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			find = 1;
			cout << "����������:";
			cin >> q->data.matchID;
			cout << "�����������:";
			cin >> q->data.matchTitle;
			cout << "�������ʱ��:";
			cin >> q->data.matchTime;
			cout << "��������ص�:";
			cin >> q->data.matchAddress;
			cout << "�����������:";
			cin >> q->data.matchContent;
			cout << "�������������:";
			cin >> q->data.matchPrincipal;
			break;
		}

		q = q->next;
	}

	if (find == 0)
		cout << "�������" << id << "������" << endl << endl;

	return Status();
}

Status List::Equal(List * L, MatchInfo m)
{
	int find = 0;
	string id;
	cout << "��ǰ�Ǳ�����Ϣ���ҽ���: " << endl << endl;
	cout << "����������:";
	cin >> id;
	List *p = L;
	List *q = p->next;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			find = 1;
			cout << "���\t\t" << "��Ŀ\t\t\t\t" << "ʱ��\t\t" << "�ص�\t" << "����\t" << "������\t\t" << endl << endl;
			cout << q->data.matchID	<< "\t";
			cout << q->data.matchTitle << "\t";
			cout << q->data.matchTime << "\t";
			cout << q->data.matchAddress << "\t";
			cout << q->data.matchContent << "\t";
			cout << q->data.matchPrincipal << endl << endl;
			break;
		}

		q = q->next;
	}

	if (find == 0)
		cout << "�������" << id << "������" << endl << endl;

	return Status();
}

