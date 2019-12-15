#pragma once

#include"Question.h"
#include"QuestionList.h"
#include<string>
#include<iostream>
#include<ctime>
#include <thread>
#include <windows.h>
#include<conio.h>
#include"UI.h"
using namespace std;

class Paper {
private:
	QuestionList bank;//题库
	
	
	int amount;
	double sum;
	int *keys;
	double score;
	QuestionList exam;//试卷题目
	int seconds;
	static int time_left;
	static int dead;
public:
	
	Paper(QuestionList& bank,QuestionList& exam,int amount,int seconds):bank(bank),amount(amount),exam(exam),sum(0),seconds(seconds),score(0)
	{
		Paper::score = 0;
		srand((int)time(0));
		exam.list.clear();
		int random;
		bool* flag = new bool[bank.list.size()];
		fill(flag, flag + bank.list.size(), false);
		int i = 0;
		while (i < amount)
		{
			random = rand() % bank.list.size();
			if (!flag[random])
			{
				exam.add(bank.list[random]);
				flag[random] = true;
				i++;
			}
		}
		this->exam = exam;
		keys = new int[amount];
		fill(keys, keys + amount, -1);
		delete[] flag;
		time_left = seconds;
		dead = 0;
	}
	~Paper()
	{
		delete[] keys;
	}

	Question getQuestion(int index)
	{
		return exam.list[index];
	}

	static void cnt(int& seconds)
	{
		while (1)
		{
			Sleep(1000);
			seconds--;
			time_left = seconds;
			if (seconds == -1||dead == 1)
			{
				break;
			}
		}
	}

	static void draw_timer()
	{
		while (1)
		{
			Sleep(300);
			draw_time(time_left);
			if (time_left <= 0||dead==1)
				break;
		}
	}

	void start()
	{
		int current = 0;
		thread timer(cnt, std::ref(seconds));
		thread draw_timer(draw_timer);
		timer.detach();
		draw_timer.detach();
		for (current = 0; current < amount; current++)
		{
			show_bgimg();
			
			show_Question(exam.list[current], current + 1,amount);
			while (1) 
			{
			
				if (keys[current] != -1)
				{
					draw_rec(keys[current] + 1);
					Sleep(500);
					break;
				}
				//draw_time(seconds);
				char key = _getch();	
				if (time_left <= 0)
				{
					current = amount - 1;
					break;
				}
				//rewind(stdin);
				if (key == 'a' || key == 'A')
				{
					keys[current] = 0;
				}
				else if (key == 'b' || key == 'B')
				{
					keys[current] = 1;
				}
				else if (key == 'c' || key == 'C')
				{
					keys[current] = 2;
				}
				else if (key == 'd' || key == 'D')
				{
					keys[current] = 3;
				}
				else if (key == 't' || key == 'T')
				{
					TCHAR s[10];
					InputBox(s, 10, _T("请输入题号"));
					// 将用户输入转换为数字
					char ss[10];
					WideCharToMultiByte(CP_ACP, 0, s, -1, ss, 256, NULL, NULL);
					int r;
					sscanf(ss, "%d", &r);
				
					 current = r-1;
					 keys[current] = -1; 
					 current--;
					 break;
					/* show_bgimg();
					 show_Question(exam.list[current], current + 1);*/
////					TCHAR s[10];
//					InputBox(s, 10, _T("请输入答案"));
//					// 将用户输入转换为数字
////					char ss[10];
//					WideCharToMultiByte(CP_ACP, 0, s, -1, ss, 256, NULL, NULL);
//			//		int r;
//					if (ss[0] >= 'a' && ss[0] <= 'z')
//						r = ss[0] - 'a';
//					else if (ss[0] >= 'A' && ss[0] <= 'Z')
//						r = ss[0] - 'A';
//					keys[c] = r;
				}
			}
			if (current == amount - 1)
			{
				while (1) {
					if (time_left <= 0)
					{
						dead = 1;
						get_score();
						draw_score(score);
						break;
	    			}
					char key = _getch();
					rewind(stdin);
					if (key == '\r')
					{
						dead = 1;
						get_score();
						draw_score(score);
						break;
					}
					else if (key == 't' || key == 'T')
					{
						TCHAR s[10];
						InputBox(s, 10, _T("请输入题号"));
						// 将用户输入转换为数字
						char ss[10];
						WideCharToMultiByte(CP_ACP, 0, s, -1, ss, 256, NULL, NULL);
						int r;
						sscanf(ss, "%d", &r);

						current = r - 1;
						keys[current] = -1;
						current--;
						break;
						/*show_bgimg();
						show_Question(exam.list[current], current + 1);*/
	//					//					TCHAR s[10];
	//					InputBox(s, 10, _T("请输入答案"));
	//					// 将用户输入转换为数字
	////					char ss[10];
	//					WideCharToMultiByte(CP_ACP, 0, s, -1, ss, 256, NULL, NULL);
	//					//		int r;
	//					if (ss[0] >= 'a' && ss[0] <= 'z')
	//						r = ss[0] - 'a';
	//					else if (ss[0] >= 'A' && ss[0] <= 'Z')
	//						r = ss[0] - 'A';
	//					keys[c] = r;
					}
				}
			}
		}
	}

	void get_score()
	{
		double sum = 100;
		double each = sum / amount;
		int cnt = 0;
		for (int i = 0; i < amount; i++)
		{
			if(keys[i]==exam.list[i].answer)
				cnt += 1;
		}
		if (cnt == amount)
			score = 100;
		else
			score = cnt * each;
	}

};