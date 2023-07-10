#include<graphics.h>
#include<iostream>
#include "Map.h"
const double PI = 3.1415926;
using namespace std;

Map::Map(int num)
{

	Line l(200, 300, 800, 300);
	int x = get_point(200, 300,l.line_long()).first;
	int y = get_point(200, 300, l.line_long()).second;
	Line l2(800, 300,x,y);
	Line l3(x, y, 200, 300);
	draw(l,3);
	draw(l2, 3);
	draw(l3, 3);
}

pair<float, float> Map::get_point(float x,float y,float l)
{
	float height = sqrt(l * l - l / 2 * l / 2);
	int X = x + l / 2;
	int Y = y + height;
	pair<float, float> p;
	p.first = X;
	p.second = Y;
	return p;
}

void Map::draw(Line l,int num)
{
	auto four_line = [&](vector<Line> lines)
	{

	};
	if (num == 0)
	{
		//三等分长度
		int d = l.line_long() / 3;
		//等分点
		float x1 = l.first_x + (d * (l.second_x - l.first_x) / l.line_long());
		float y1 = l.first_y + (d * (l.second_y - l.first_y) / l.line_long());

		float x2 = l.first_x + (d * 2 * (l.second_x - l.first_x) / l.line_long());
		float y2 = l.first_y + (d * 2 * (l.second_y - l.first_y) / l.line_long());

		Line a(l.first_x, l.first_y, x1, y1);
		Line b(x2, y2, l.second_x, l.second_y);


		//斜向线
		int Angle1 = -60 - l.angle();

		float radians1 = (Angle1)*PI / 180;
		float x3 = x1 + d * cos(radians1);
		float y3 = y1 + d * sin(radians1);
		Line l1(x1, y1, x3, y3);


		float radians2 = (-120 - l.angle()) * PI / 180;
		float x4 = x2 + d * cos(radians2);
		float y4 = y2 + d * sin(radians2);
		Line l2(x4, y4, x2, y2);
		a.draw();
		b.draw();
		l1.draw();
		l2.draw();
	}
	else
	{
		//三等分长度
		int D = l.line_long() / 3;
		//等分点
		float x1 = l.first_x + (D * (l.second_x - l.first_x) / l.line_long());
		float y1 = l.first_y + (D * (l.second_y - l.first_y) / l.line_long());

		float x2 = l.first_x + (D * 2 * (l.second_x - l.first_x) / l.line_long());
		float y2 = l.first_y + (D * 2 * (l.second_y - l.first_y) / l.line_long());

		Line a(l.first_x, l.first_y, x1, y1);
		Line b(x2, y2, l.second_x, l.second_y);

		//斜向线
		int Angle1 = -60 - l.angle();

		float radians1 = (Angle1)*PI / 180;
		float x3 = x1 + D * cos(radians1);
		float y3 = y1 + D * sin(radians1);
		Line c(x1, y1, x3, y3);


		float radians2 = (-120 - l.angle()) * PI / 180;
		float x4 = x2 + D * cos(radians2);
		float y4 = y2 + D * sin(radians2);
		Line d(x4, y4, x2, y2);

		draw(a, num - 1);
		draw(b, num - 1);
		draw(c, num - 1);
		draw(d, num - 1);
	}

}

