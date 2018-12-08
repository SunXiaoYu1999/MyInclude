#include "MyButton.h"

Button::Button(int X, int Y, int Higth, LPCTSTR bname, COLORREF textcolor, COLORREF bkcolor, COLORREF clickcolor)
	: x(X), y(Y), higth(Higth), bName(bname), textColor(textcolor), bkColor(bkcolor), clickColor(clickcolor)
{

	int lenth = 0;
	width = 0;
	for (; bname[lenth] != '\0'; lenth++)
	{
		if (bname[lenth] >= 128)
			width += higth;
		if (bname[lenth] < 128 && bname[lenth] >= 0)
			width += higth / 2;
	}
	textSize = higth * 2 / 3;
	textOffsetY = (higth - textSize) / 2;
	textOffsetX = (int)((double)(width - textSize * ((double)width / higth)) / 2.0);

	Show();
}

bool Button::Click()
{
	if (msg.uMsg == WM_LBUTTONDOWN)
		if (msg.x > x && msg.x < x + width && msg.y > y && msg.y < y + higth)
			return true;
	return false;
}

void Button::Show()
{
	int flag = 0;
	setlinecolor(WHITE);
	setfillcolor(bkColor);
	fillrectangle(x, y, x + width, y + higth);
	if (msg.x > x && msg.x < x + width && msg.y > y && msg.y < y + higth)
	{
		flag = 1;
		setfillcolor(clickColor);
		floodfill(msg.x, msg.y, WHITE);
		settextstyle((textSize * 1.3) > higth ? higth : (textSize * 1.3), 0, L"楷体");
		textOffsetY = (higth - textSize * 1.3) / 2;
		textOffsetX = (int)((double)(width - textSize * 1.3 * ((double)width / higth)) / 2.0);
	}
	setbkmode(TRANSPARENT);
	if (flag == 0)
	{
		settextstyle(textSize, 0, TEXT("宋体"));
		textOffsetY = (higth - textSize) / 2;
		textOffsetX = (int)((double)(width - textSize * ((double)width / higth)) / 2.0);
	}
	settextcolor(textColor);
	outtextxy(x + textOffsetX, y + textOffsetY, bName);
}
// 设置文字大小，按钮高度的 size%,size取值范围[20,100]；
void Button::SetTextSize(int size)
{
	if (size < 20 || size > 100)
		return;
	textSize = size * higth / 100;
	textOffsetY = (higth - textSize) / 2;
	textOffsetX = (int)((double)(width - textSize * ((double)width / higth)) / 2.0);
}

void Button::GetMsg()
{
	msg = GetMouseMsg();
}

MOUSEMSG Button::msg;