#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Question.h"
#include"QuestionList.h"
#include"Paper.h"
#include<graphics.h>
#include<conio.h>
#include"UI.h"

using namespace std;

void loadSetting(string &b,string&t,int&num,int&sec)
{
	ifstream fin("setting", ios::in|ios::app);
	fin >> b >> t >> num >> sec;
	fin.close();
}
void Main();

void setSetting()
{
	closegraph();
	string b, t;
	int num,  sec;
	cout << "����Ҫ���������ļ���:" << endl;
	cin >> b;
	QuestionList ql(b);
	ql.load();
	cout << "�������" << ql.list.size() << "��" << endl;
	cout << "�����Ծ��ļ���:" << endl;
	cin >> t;
	cout << "������Ŀ����: (<=�����Ŀ����" <<endl;
	cin >> num;
	cout << "��������ʱ�䣨s)" << endl;
	cin >> sec;
	ofstream fout("setting", ios::out);
	fout << b << " " << t << " " << num << " " << sec << " ";
	fout.close();
	Main();
}

void setBank()
{
	closegraph();
	string b;
	cout << "������Ҫ�����Ŀ�����:" << endl;
	cin >> b;
	QuestionList bank(b);
	bank.load();
	cout <<"�������"<< bank.list.size() <<"��"<< endl;
	while (1)
	{
		Question q;
		bank.add(q);
		cout << "����q�˳�,����b����¼����Ŀ" << endl;
		char c;
		
		while(1)
		{
			cin >> c;
			if (c == 'q' || c == 'b' || c == 'Q' || c == 'B')
				break;
		}
		if (c == 'q' || c == 'Q')
		{
			Main();
			break;
		}
	}
}