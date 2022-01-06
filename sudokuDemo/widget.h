#pragma once
#include "common.h"
class Widget 
{
public:
	enum SHOW_STYLE
	{
		NO_CON,
		YEW_CON
	};
public:
	Widget(int width, int height, string url = "");
	void Show(int flag = 0);
	void Refresh();
	bool exec();

	~Widget();
protected:
	int width;
	int height;
	IMAGE* img;
	string imgURL;
};
