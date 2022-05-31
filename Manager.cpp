#include "stdafx.h"
#include "Manager.h"


Status Manager::Login(string account, string password)
{
	
	cout << "��ǰ�ǹ���Ա��¼ҳ�� : " << endl << endl;
	cout << "�������¼�˺� : "; cin >> account;
	cout << endl;
	cout << "�������¼���� : "; cin >> password;
	cout << endl;
	
	if (account.compare(this->account) == 0 && password.compare(this->password) == 0)
		return TRUE;
	else
		return FALSE;	
}
	
	



void Manager::AfterLogin(List * L)
{
	int flag = 0;
	int n = 0, i = 0;
	int operation;
	MatchInfo m;
	

	while (true) {
		cout << "1.��ӱ�����Ϣ\t2.ɾ��������Ϣ\t3.�޸ı�����Ϣ\t4.���ұ�����Ϣ\t5.�˳���½����" << endl << endl;
		cout << "��ѡ����ز��������� "; cin >> operation;
		cout << endl;
		switch (operation) {
		case 1:
			system("cls");
			L->ListInsert(L,n);
			system("pause");
			system("cls");
			SaveMatch(L);
			break;
		case 2:
			system("cls");
			L->ListDelete(L, m);
			system("pause");
			system("cls");
			SaveMatch(L);
			break;
		case 3:
			system("cls");
			L->UpdateList(L, m);
			system("pause");
			system("cls");
			SaveMatch(L);
			break;
		case 4:
			system("cls");
			L->Equal(L, m);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "�Ƿ��˳���ǰ���� [1:�� 0:��]\t"; cin >> flag;
			cout << endl;
			if (flag) {
				cout << "�ɹ��˳���ǰ����!" << endl << endl;
				system("pause");
				return;
			}
			continue;
		default:
			cout << "��������,�밴�涨����������!" << endl << endl;
			break;
		}
	}
}

void Manager::QuerryMatch()
{
	fstream file;
	string line;
	file.open("MatchInfo.txt", ios::in);

	cout << "���\t\t" << "��Ŀ\t\t\t\t" << "ʱ��\t\t" << "�ص�\t" << "����\t" << "������\t\t" << endl << endl;

	int index = 1;
	while (file.peek() != EOF) {
		getline(file, line);
		cout << line << "\t";
		if (index++ % 6 == 0) {
			cout << endl << endl;
		}
	}
	file.close();
	cout << endl;
}

void Manager::SaveMatch(List *L)
{
	fstream file;
	file.open("MatchInfo.txt", ios::out);

	List *q = L->next;
	while (q)
	{
		file << q->data.matchID			<< endl
			<< q->data.matchTitle		<< endl
			<< q->data.matchTime		<< endl
			<< q->data.matchAddress		<< endl
			<< q->data.matchContent		<< endl
			<< q->data.matchPrincipal   << endl;
		q = q->next;
	}
	file.close();
}

void Manager::Display()
{
	cout << "����Ա�˺� : " << this->account << endl << endl;
	cout << "����Ա���� : " << this->password << endl << endl;
}

Manager::Manager()
{
}


Manager::~Manager()
{
}


