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
#include"Setting.h"


using namespace std;






//int main()
//{
//	string d = "3*2 = £¿";
//	string a[4] = { "2","6","7","9999" };
//	Question q(d, a, 1);
//	Question q1(d, a, 2);
//	QuestionList ql("data");
//	ql.load();
//	ql.add(q);
//	ql.add(q1);
//	ql.save();
//	ql.showAll();
//	ql.add(q1);
//	system("cls");
//	ql.showAll();
//
//	//cout << q;
//}


void start()
{
	string b, t;
	int num, sec;
	loadSetting(b, t, num, sec);
	QuestionList bank(b);
	QuestionList test(t);
	bank.load();
	test.clear();
	Paper p(bank, test, num, sec);
	initgraph(800, 600);
	p.start();
}







int Paper::time_left = 0;
int Paper::dead = 0;
const int x = 350;


void Main()
{
FLAG:	init();
	show_menu();
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= x && m.y >= 200 && m.x <= x + WIDTH && m.y <= 200 + HIGH && m.mkLButton)
			//rectangle(x, 200, x + WIDTH, 200 + HIGH);
			setSetting();
		else if (m.x >= x && m.y >= 250 && m.x <= x + WIDTH && m.y <= 250 + HIGH && m.mkLButton)
		{
			setBank();
		}
		else if (m.x >= x && m.y >= 300 && m.x <= x + WIDTH && m.y <= 300 + HIGH && m.mkLButton)
			//rectangle(x, 250, x + WIDTH, 250 + HIGH);
		{
			start();
			FlushMouseMsgBuffer();
			goto FLAG;
		}
		else if (m.x >= x && m.y >= 350 && m.x <= x + WIDTH && m.y <= 350 + HIGH && m.mkLButton)
			exit(0);
	}
}

int main()
{
	

	Main();
	_getch();


	//init();
	//string d = "ÄãÊÇË­";
	//string a[4] = { "Éµ¹·","shabbyRome","zz","sbrong" };
	//Question q(d, a, 1);

	//show_Question(q,99);

	system("pause");

}