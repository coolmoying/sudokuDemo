#include "button.h"
Button::Button(string text, int x, int y, int width, int height, COLORREF color):Widget(width,height)
{
	this->curColor = color;
	this->outColor = color;
	this->inColor = LIGHTBLUE;
	this->textColor = BLACK;
	this->text = text;
	this->x = x;
	this->y = y;
}
void Button::SetBkColor(COLORREF color)
{
	this->curColor = color;
	this->outColor = color;
	this->inColor = LIGHTBLUE;			//鼠标在按钮中显示淡蓝色
}
void Button::SetTextColor(COLORREF color)
{
	this->textColor = textColor;
}
void Button::SetText()
{
	stringstream temp(text);
	int num = 0;
	temp >> num;
	num++;
	if (num > 9)
		num = 0;
	this->text = to_string(num);
}
void Button::Show()
{
	//按钮绘制出来的
	setlinecolor(BLACK);
	setfillcolor(this->curColor);
	fillrectangle(this->x, this->y, this->x + this->width, this->y + this->height);
	//文字显示
	//文字居中
	setbkmode(TRANSPARENT);		//去掉文字的背景
	settextcolor(this->textColor);
	settextstyle(this->height*2/3, 0, "楷体");
	int x = this->x+(this->width - textwidth(text.c_str()))/2;
	int y = this->y + (this->height - textheight(text.c_str())) / 2;
	outtextxy(x, y, text.c_str());
}
bool Button::MouseInButton(ExMessage& msg)
{
	if (msg.x >= this->x && msg.y >= this->y &&
		msg.x <= this->x + this->width &&
		msg.y <= this->y + this->height) 
	{
		this->curColor = this->inColor;
		//cout << this->inColor << endl;
		return true;   //需要返回
	}
	this->curColor = this->outColor;
	//cout << this->inColor << endl;
	return false;
}
bool Button::ClickButton(ExMessage& msg)
{
	if (MouseInButton(msg)&&msg.message == WM_LBUTTONDOWN) 
	{
		return true;
	}
	return false;
}
