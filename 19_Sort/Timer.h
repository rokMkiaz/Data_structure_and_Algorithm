#pragma once
#include <Windows.h>

class Timer
{
public:
	Timer()
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&tick);//시간비율을 구함.
	}

	void Start()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&start);//시작지점
	}

	float End()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&end);//끝지점

		return (float)((double)(end - start) / tick * 1000.0f);//비율을 구해 리턴
	}

private:
	__int64 tick;
	__int64 start, end;
};