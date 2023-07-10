#pragma once
#include<vector>
#include "LINE.cpp"
using namespace std;
class Map
{
public:
	Map(int num);
private:
	int count;
	vector<Line> lines;
	void draw(Line l,int num);
	pair<float, float> get_point(float x,float y,float l);
};
