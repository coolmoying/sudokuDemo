#include "widget.h"
Widget::Widget(int width, int height, string url)
{
	this->width = width;
	this->height = height;
	this->imgURL = url;			//´°¿Ú±³¾°µÄÍ¼Æ¬Â·¾¶
	if (url.size() != 0) 
	{
		this->img = new IMAGE;
		loadimage(this->img, url.c_str(), this->width, this->height);
	}
}
void Widget::Show(int flag)
{
	initgraph(this->width, this->height, flag);
	if (this->imgURL.size() != 0) 
	{
		putimage(0, 0, this->img);
	}
}
void Widget::Refresh()
{
	if (imgURL.size() != 0)
		putimage(0, 0, img);
	else
		cleardevice();
}
bool Widget::exec()
{
	while (_getch() != '\r');
	return 0;
}
Widget::~Widget()
{
	if (imgURL.size() != 0)
	{
		delete img;
	}
}
