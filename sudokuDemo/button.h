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
	//��ť������
	int x;
	int y;
	//��ť����
	string text;
	//��ť��ɫ
	COLORREF curColor;		//��ǰ��ť��ɫ
	COLORREF inColor;		//����ڰ�ť��
	COLORREF outColor;		//��겻�ڰ�ť�е���ɫ
	COLORREF textColor;
	/*
		int width;
		int height;
		IMAGE *img;
		string imgURL;
	*/
};