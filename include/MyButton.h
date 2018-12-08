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
	int x;				// ��ť����x����
	int y;				// ��ť����y����
	int width;			// ��ť���
	int higth;			// ��ť�߶�
	int textSize;		// ���ִ�С
	int textOffsetX;	// ����Xƫ����
	int textOffsetY;	// ����Yƫ����
	LPCTSTR bName;		// ��ť����
	COLORREF textColor;	// ������ɫ
	COLORREF bkColor;	// ��ť������ɫ
	COLORREF clickColor;// ��ťѡ��ʱ��ɫ
};
#endif // !MYBUTTON_H


