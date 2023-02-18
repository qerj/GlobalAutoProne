#include <iostream>
#include <Windows.h>

//got from some source off UC thx :)
void SendKeys(char key) {
    INPUT input; //https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-input
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(key)), 0);
    SendInput(1, &input, sizeof(INPUT));
    Sleep(1);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main()
{
    bool status = false;

    while (true)
    {
        if (GetAsyncKeyState(VK_XBUTTON2) & 1) //bind key for it being on and off
        {
            status = !status;
        }
        if (GetAsyncKeyState(0x5A)) //z key, for debugging you can delete.
        {
            std::cout << "Z was pressed" << std::endl;
        }

        if (status && GetAsyncKeyState(MK_LBUTTON) & 1)//finally if status is on from our bind key and we shoot with left click then prone.
        {
            SendKeys(0x5A);//send input
        }
        Sleep(1);
    }
}
