#pragma once

#include "stdafx.h"

class Role
{
public:
	string account;
	string password;
	int role;
	Role();
	~Role();

	void Register(string username, string password);//ע��
	Status Login(string username, string password);//��¼
	void Display();//��ʾ�˺ż�������
	void AfterLogin();
};

