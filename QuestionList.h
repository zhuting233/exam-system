#pragma once
#include"Question.h"
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

class QuestionList {
private:
	
	string filename;
public:
	vector<Question> list;

	void load() 
	{
		ifstream fin(filename, ios::in | ios::app);
		if (!fin) {
			cout << "文件打开失败" << endl;
			return;
		}
		list.clear();
		string description, choice[4];
		int answer;
		while (getline(fin, description)) {
			for (int i = 0; i < 4; i++)
			{
				getline(fin, choice[i]);
			}
			fin >> answer;
			string temp;
			getline(fin, temp);
			list.push_back(Question(description, choice, answer));
		}
		fin.close();
	}

	void clear()
	{
		list.clear();
		ofstream fout(filename,ios::out);
		fout.close();
	}

	QuestionList(string filename)
	{
		this->filename = filename;
	}

	void save()
	{
		ofstream fout(filename, ios::out);
		if (!fout)
		{
			cout << "文件写入失败" << endl;
			return;
		}
		for (int i = 0; i < list.size(); i++)
		{
			fout << list[i];
		}
		fout.close();
	}

	void add(const Question& q)
	{
		list.push_back(q);
		ofstream fout(filename, ios::app);
		fout << q;
		fout.close();
	}

	void showAll()
	{
		for (int i = 0; i < list.size(); i++)
		{
			list[i].show();
			cout << endl;
		}
	}
};