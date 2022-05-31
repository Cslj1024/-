#pragma once
#include "Role.h"
#include "List.h"
class Student : public Role
{
public:
	string ID;//ѧ��
	List *M;
	Student();
	~Student();

	 void Register(string username, string password);//ע��
	 Status Login(string username, string password);//��¼
	 void Display();//��ʾ�˺ż�������
	 void AfterLogin(Student *S,List *L);

	 void QuerryMatch(List *L);
	 Status JoinMatch(Student *S,List *L);
	 Status ExitMatch(Student *S, List *L);
	 void ShowMatch();

	 void Load();
	 void Save();
};

