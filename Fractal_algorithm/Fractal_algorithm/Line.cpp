#include<graphics.h>
#include<math.h>
class Line
{
public:
	float first_x;
	float first_y;
	float second_x;
	float second_y;
	Line();
	Line(float n1, float n2, float n3, float n4)
	{
		first_x = n1;
		first_y = n2;
		second_x = n3;
		second_y = n4;
	}
	float line_long()
	{
		return sqrt((first_x - second_x) * (first_x - second_x) + (first_y - second_y) * (first_y - second_y));
	}
	float angle()
	{
		return (atan2(second_x - first_x, second_y - first_y) * 180 / 3.1415926)-90;
	}
	void draw()
	{
		line(first_x, first_y, second_x, second_y);
	}
};

