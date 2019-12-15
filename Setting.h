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
	cout << "输入要导入的题库文件名:" << endl;
	cin >> b;
	QuestionList ql(b);
	ql.load();
	cout << "该题库有" << ql.list.size() << "题" << endl;
	cout << "设置试卷文件名:" << endl;
	cin >> t;
	cout << "输入题目数量: (<=题库题目数）" <<endl;
	cin >> num;
	cout << "输入限制时间（s)" << endl;
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
	cout << "请输入要添加题目的题库:" << endl;
	cin >> b;
	QuestionList bank(b);
	bank.load();
	cout <<"该题库有"<< bank.list.size() <<"题"<< endl;
	while (1)
	{
		Question q;
		bank.add(q);
		cout << "输入q退出,输入b继续录入题目" << endl;
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