#pragma once
#include "common.h"
#include "widget.h"
class Button :public Widget
{
public:
	Button(string text="", int x = 0, int y = 0, int width = 100, int height = 25,
		COLORREF color=RED);
	void SetBkColor(COLORREF color);
	void SetTextColor(COLORREF color);
	void SetText();
	void Show();
	bool MouseInButton(ExMessage& msg);
	bool ClickButton(ExMessage& msg);

protected:
	//按钮的坐标
	int x;
	int y;
	//按钮文字
	string text;
	//按钮颜色
	COLORREF curColor;		//当前按钮颜色
	COLORREF inColor;		//鼠标在按钮中
	COLORREF outColor;		//鼠标不在按钮中的颜色
	COLORREF textColor;
	/*
		int width;
		int height;
		IMAGE *img;
		string imgURL;
	*/
};