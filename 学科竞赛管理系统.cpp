// ѧ�ƾ�������ϵͳ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "List.h"
#include "Role.h"
#include "Student.h"
#include "Manager.h"
#include "MatchInfo.h"



int operation, n;
string account, password;
Status i;


void Menu() {
	cout << "--------------------ѧ�ƾ�������ϵͳ--------------------" << endl << endl;
	cout << " 1��ѧ��ע�� " << endl << endl;
	cout << " 2��ѧ����¼ " << endl << endl;
	cout << " 3������Ա��¼ " << endl << endl;
	cout << " 4���˳� " << endl << endl;
	cout << "------------------------------------------------------" << endl << endl;
}

void LoadMatch(List **L)
{
	fstream file;
	file.open("MatchInfo.txt", ios::in);
	List *p = *L;

	while (file.peek() != EOF) {
		List *n = new List;
		getline(file, n->data.matchID);
		getline(file, n->data.matchTitle);
		getline(file, n->data.matchTime);
		getline(file, n->data.matchAddress);
		getline(file, n->data.matchContent);
		getline(file, n->data.matchPrincipal);
		n->next = NULL;
		p->next = n;
		p = p->next;
	}
	file.close();
}

int main()
{
	
	Student *S = new Student();
	Manager *m = new Manager();
	List *L = new List();
	L->InitList(L);
	LoadMatch(&L);
	//m->Display();
	//L->ListInsert(L, n);
	//L->ListTraverse(L);
	while (true) {
		Menu();
		cout << "��ѡ����Ӧ���������� "; cin >> operation;
		switch (operation) {
		case 1:
			system("cls");
			S->Register(account, password);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			i=S->Login(account, password);
			//i = 1;
			if (i) {
				cout << "��½�ɹ�!" << endl << endl;
				S->AfterLogin(S,L);
			}else
				cout << "��¼ʧ��!" << endl << endl;
			system("pause");
			system("cls");
			break;
		/*case 3:
			system("cls");
			S->JoinMatch(S, L);
			system("pause");
			system("cls");
			break;*/
		case 3:
			system("cls");
			i=m->Login(account, password);
			//i = 1;
			if (i) {
				cout << "�ɹ���½!" << endl << endl;
				m->QuerryMatch();
				m->AfterLogin(L);
				system("cls");
			}
			else {
				cout << "��½ʧ��!" << endl << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			cout << endl;
			cout << "�ɹ��˳�ѧ�ƾ�������ϵͳ!" << endl << endl;
			exit(0);
		default:
			cout << endl << "��ǰ��������,�밴�涨ָ������!" << endl << endl;
			system("pause");
			system("cls");

		}
}
    return 0;
}


