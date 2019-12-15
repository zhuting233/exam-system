#pragma once
#include<string>
#include<iostream>
#include<graphics.h>
#include <atlstr.h>
using namespace std;
extern const int HIGH;


class Question {
private:
	string description;//��Ŀ����
	string choice[4];//ѡ��
	int answer;//��׼��
public:
	Question()
	{
		getchar();
		cout << "������Ŀ����" << endl;
		getline(cin, description);
		cout << "�����ĸ�ѡ�������" << endl;
		for (int i = 0; i < 4; i++)
		{
			getline(cin, choice[i]);
		}
		cout << "�����(1-4)" << endl;
		cin >> answer;
		answer--;
	}
	Question(string desc, string choice[], int ans) : description(desc), answer(ans)
	{
		for (int i = 0; i < 4; i++)
		{
			this->choice[i] = choice[i];
		}
	}

	friend ostream& operator<<(ostream& os, const Question& q)
	{
		os << q.description << endl;
		for (int i = 0; i < 4; i++)
			os << q.choice[i] << endl;
		os << q.answer << endl;
		return os;
	}

	void show()
	{
		cout << description << endl;
		cout << "A. " << choice[0] << endl;
		cout << "B. " << choice[1] << endl;
		cout << "C. " << choice[2] << endl;
		cout << "D. " << choice[3] << endl;
	}

	friend void show_Question(Question& q,int index,int amount);
	friend class Paper;
};

