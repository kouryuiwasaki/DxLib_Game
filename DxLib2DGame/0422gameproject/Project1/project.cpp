#include "DxLib.h"

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);

    DxLib_Init();

    SetDrawScreen(DX_SCREEN_BACK);

    SetGraphMode(800, 600, 32);
    

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    int circleX = 150;
    int circleY = 200;
    int stringX = 10;
    int stringY = 15;
    int stringX1 = 10;
    int stringY1 = 50;
    int mouseX = 0;
    int mouseY = 0;
    int circleColor = GetColor(0, 0, 255);
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(225, 0, 0);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        DrawCircle(circleX, circleY, 30, circleColor, TRUE);

        GetMousePoint(&mouseX, &mouseY);
        
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit", StringColor2);
        }
        if (CheckHitKey(KEY_INPUT_UP))
        {
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            if (circleX <= 40)
            {
                circleX += 3;

            }
            else
            {
                circleX -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 740)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }
        }

        // circleX += 2;
        // circleY += 1;
        SetFontSize(32);

        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%dY:%d", mouseX, mouseY);

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}