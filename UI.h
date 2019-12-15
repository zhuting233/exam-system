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
	gettextstyle(&f);								// ��ȡ��ǰ��������
	f.lfHeight = 40;								// ��������߶�Ϊ 40
	_tcscpy(f.lfFaceName, _T("�����п�"));			// ��������Ϊ�������п���
	f.lfQuality = ANTIALIASED_QUALITY;				// �������Ч��Ϊ�����  
	settextstyle(&f);								// ����������ʽ
	setbkmode(TRANSPARENT);							// �������屳��͸��
	settextcolor(DARKGRAY);							// ����������ɫ
	outtextxy(300, 130, _T("����ѡ���⿼��ϵͳ"));
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = FW_BLACK;
	_tcscpy(f.lfFaceName, _T("���Ŀ���"));
	settextstyle(&f);
	int x = 350;
	outtextxy(x, 200, _T("�Ծ�����"));
	outtextxy(x, 250, _T("������"));
	outtextxy(x, 300, _T("��ʼ����"));
	outtextxy(x, 350, _T("�˳�  "));

}

void show_Question(Question& q, int index,int amount)
{
	LOGFONT f;
	gettextstyle(&f);								// ��ȡ��ǰ��������
	f.lfHeight = 20;								// ��������߶�Ϊ 40
	_tcscpy(f.lfFaceName, _T("����"));			// ��������Ϊ�����塱
	//f.lfQuality = ANTIALIASED_QUALITY;				// �������Ч��Ϊ�����  
	settextstyle(&f);								// ����������ʽ
	int x = 50, y = 50;
	string ind = to_string(index);
	settextcolor(BLACK);							// ����������ɫ
	setbkmode(TRANSPARENT);							// �������屳��͸��
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
	string s = "��" + to_string(amount) + "��,��T����ת��Ŀ,����󰴻س�����";
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
	string t = "����ʱ:" + to_string(seconds)+" s";
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
	gettextstyle(&f);								// ��ȡ��ǰ��������
	f.lfHeight = 40;								// ��������߶�Ϊ 40
	_tcscpy(f.lfFaceName, _T("�����п�"));			// ��������Ϊ�������п���
	f.lfQuality = ANTIALIASED_QUALITY;				// �������Ч��Ϊ�����  
	settextstyle(&f);								// ����������ʽ
	setbkmode(TRANSPARENT);							// �������屳��͸��
	settextcolor(BLUE);							// ����������ɫ
	score = (double)round(score * 100) / 100;
	string s = "����:" + to_string(score);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			s[i + 3] = '\0';
			break;
		}
	}
	outtextxy(200, 200, CA2T(s.c_str()));
	_getch();
}