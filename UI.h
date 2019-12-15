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
#include"Setting.h"
using namespace std;

const int WIDTH = 200;
const int HIGH = 50;

void show_bgimg()
{
	IMAGE bgimg;
	loadimage(&bgimg, _T("bg.jpg"), 800, 600);
	putimage(0, 0, &bgimg);
}

void init()
{
	initgraph(800, 600);
	show_bgimg();
}

void show_menu()
{
	LOGFONT f;
	gettextstyle(&f);								// 获取当前字体设置
	f.lfHeight = 40;								// 设置字体高度为 40
	_tcscpy(f.lfFaceName, _T("华文行楷"));			// 设置字体为“华文行楷”
	f.lfQuality = ANTIALIASED_QUALITY;				// 设置输出效果为抗锯齿  
	settextstyle(&f);								// 设置字体样式
	setbkmode(TRANSPARENT);							// 设置字体背景透明
	settextcolor(DARKGRAY);							// 设置字体颜色
	outtextxy(300, 130, _T("单项选择题考试系统"));
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = FW_BLACK;
	_tcscpy(f.lfFaceName, _T("华文楷体"));
	settextstyle(&f);
	int x = 350;
	outtextxy(x, 200, _T("试卷设置"));
	outtextxy(x, 250, _T("添加题库"));
	outtextxy(x, 300, _T("开始考试"));
	outtextxy(x, 350, _T("退出  "));

}

void show_Question(Question& q, int index,int amount)
{
	LOGFONT f;
	gettextstyle(&f);								// 获取当前字体设置
	f.lfHeight = 20;								// 设置字体高度为 40
	_tcscpy(f.lfFaceName, _T("宋体"));			// 设置字体为“宋体”
	//f.lfQuality = ANTIALIASED_QUALITY;				// 设置输出效果为抗锯齿  
	settextstyle(&f);								// 设置字体样式
	int x = 50, y = 50;
	string ind = to_string(index);
	settextcolor(BLACK);							// 设置字体颜色
	setbkmode(TRANSPARENT);							// 设置字体背景透明
	outtextxy(x, y, CA2T(ind.c_str()));
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(x + 30, y, CA2T(q.description.c_str()));
	for (int i = 1; i <= 4; i++)
	{
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		outtextxy(x, y + i * HIGH, _T('A ' + i - 1));
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		outtextxy(x + 30, y + i * HIGH, CA2T(q.choice[i - 1].c_str()));
	}
	string s = "共" + to_string(amount) + "题,按T可跳转题目,做完后按回车交卷";
	outtextxy(400, 500, CA2T(s.c_str()));
}

void draw_rec(int choice)
{
	setlinecolor(RED);
	rectangle(45, 45 + HIGH * choice, 70, 50 + HIGH * choice + 20);
}

void draw_time(int seconds)
{

	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillrectangle(550, 0, 800, 30);
	string t = "倒计时:" + to_string(seconds)+" s";
	//setbkcolor(WHITE);
	//setbkmode(OPAQUE);
	settextcolor(RED);
	outtextxy(550, 0, CA2T(t.c_str()));
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
}

void draw_score(double score)
{
	show_bgimg();
	LOGFONT f;
	gettextstyle(&f);								// 获取当前字体设置
	f.lfHeight = 40;								// 设置字体高度为 40
	_tcscpy(f.lfFaceName, _T("华文行楷"));			// 设置字体为“华文行楷”
	f.lfQuality = ANTIALIASED_QUALITY;				// 设置输出效果为抗锯齿  
	settextstyle(&f);								// 设置字体样式
	setbkmode(TRANSPARENT);							// 设置字体背景透明
	settextcolor(BLUE);							// 设置字体颜色
	score = (double)round(score * 100) / 100;
	string s = "分数:" + to_string(score);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			s[i + 3] = '\0';
			break;
		}
	}
	outtextxy(200, 200, CA2T(s.c_str()));
	_getch();
}