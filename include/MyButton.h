#pragma once
#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <Windows.h>
#include <graphics.h>

class Button
{
public:
	Button(int X, int Y, int Higth, LPCTSTR bname, COLORREF textcolor = WHITE, COLORREF bkcolor = BLACK, COLORREF clickcolor = BLUE);
	bool Click();
	void Show();
	void SetTextSize(int size);

	static MOUSEMSG msg;
	static void GetMsg();

private:
	int x;				// 按钮左上x坐标
	int y;				// 按钮左上y坐标
	int width;			// 按钮宽度
	int higth;			// 按钮高度
	int textSize;		// 文字大小
	int textOffsetX;	// 文字X偏移量
	int textOffsetY;	// 文字Y偏移量
	LPCTSTR bName;		// 按钮文字
	COLORREF textColor;	// 文字颜色
	COLORREF bkColor;	// 按钮背景颜色
	COLORREF clickColor;// 按钮选中时颜色
};
#endif // !MYBUTTON_H


