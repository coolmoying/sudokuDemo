#pragma once
//定义和声明都在.h中，这个文件改为.hpp
#include <time.h>
class MyTimer 
{
public:
	static bool Timer(time_t num, int id) 
	{
		static time_t time[10] = { 0 };
		MyTimer object(id);
		if (object.end - time[id] > num) 
		{
			time[id] = object.end;
			return true;
		}
		return false;
	}
private:
	MyTimer(int id):id(id)
	{
		end = clock();
	}
	time_t end;				//结束时间
	int id;					//定时器id
};