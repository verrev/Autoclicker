#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	cout << "Move the cursor to the location where you want to click, then press F7.\n";
	int x = 0, y = 0;
	while (1){
		if (GetAsyncKeyState(VK_F7)){
			POINT p;
			GetCursorPos(&p);
			x = p.x;
			y = p.y;
			break;
		}
		Sleep(80);
	}
	cout << "Press ESC to close the program.\n";
	while (1){
		if (GetAsyncKeyState(VK_ESCAPE)) break;
		SetCursorPos(x, y);
		input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &input, sizeof(INPUT));
		Sleep(40);
		input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &input, sizeof(INPUT));
		Sleep(150);
	}
}