#include "TXLib.h"

void fox_draw (double x, double y);
//void bird_draw (double x, double y, double size);

int main()
    {
    //окно
    txCreateWindow(1600, 900);
    txRectangle(0, 0, 1600, 900);
    double x = 300;
    double y = 300;
    int z = 0;
    txTextCursor(false);
    while (x < 1600)
        {
        x = x + 5;
        z ++;
        txSetFillColor(TX_WHITE);
        txClear();
        fox_draw (x, y + z%2*25);

        txSleep(150);
        }




    }


//-----------------------------------------------------------------------------
/*void bird_draw (double x, double y, double size)
    {
    txSetFillColor(TX_TRANSPARENT);
    txSetColor(TX_BLACK, 7);

    //Body
    txSetFillColor(RGB(48, 48, 46));
    POINT BodyBird[6] = {{ROUND(x),            ROUND(y)},
                         {ROUND(x + 150), ROUND(y -  50)},
                         {ROUND(x),            ROUND(y + 100)},
                         {ROUND(x - 100), ROUND(y + 100)},
                         {ROUND(x - 200), ROUND(y -  50)},
                         {ROUND(x-  100), ROUND(y - 100)}};
    txPolygon(BodyBird, 6);

    //Legs
    txLine(x -  50, y + 100, x - 150,  y + 200);
    txLine(x - 150, y + 200, x - 150,  y + 225);
    txLine(x - 150, y + 200, x - 125,  y + 225);
    txLine(x - 150, y + 200, x - 175,  y + 225);
    txLine(x -  25, y + 100, x -  50,  y + 200);
    txLine(x -  50, y + 200, x -  50 , y + 225);
    txLine(x -  50, y + 200, x -  25,  y + 225);
    txLine(x -  50, y + 200, x -  75,  y + 225);

    //Head
    txSetFillColor(RGB(89, 88, 83));
    txCircle(x - 175, y - 125, 75);

    //Wings
    txSetFillColor(RGB(89, 88, 83));
    POINT WingFirst[3] = {{ROUND(x),            ROUND(y)},
                          {ROUND(x - 100), ROUND(y +  50)},
                          {ROUND(x - 100), ROUND(y - 100)}};

    POINT WingSecond[3] = {{ROUND(x),            ROUND(y)},
                           {ROUND(x - 100), ROUND(y + 150)},
                           {ROUND(x - 100), ROUND(y - 100)}};
    txPolygon(WingFirst, 3);

    txSetFillColor(RGB(56, 55, 53));
    txPolygon(WingSecond, 3);

    //Beak
    txSetFillColor(RGB(89, 88, 83));
    POINT Beak[5] = {{ROUND(x - 200), ROUND(y - 150)},
                     {ROUND(x - 300), ROUND(y - 150)},
                     {ROUND(x - 200), ROUND(y - 100)},
                     {ROUND(x - 300), ROUND(y -  50)},
                     {ROUND(x - 200), ROUND(y -  75)}};
    txPolygon(Beak, 5);

    //Eye
    txSetColor(TX_RED, 7);
    txSetFillColor(TX_RED);
    txCircle(x - 150, y - 150, 5);
    }
*/
//-----------------------------------------------------------------------------
void fox_draw (double x, double y)
    {
    //Fox Body
    txSetFillColor(TX_ORANGE);
    txSetColor(TX_BLACK, 7);
    POINT Body[3] = {{ ROUND(x),             ROUND(y)},
                     { ROUND(x - 50),   ROUND(y + 200)},
                     { ROUND(x + 50),   ROUND(y + 200)}};
    txPolygon(Body , 3);

    //Legs
    txSetFillColor(TX_ORANGE);
    txRectangle(x - 45, y + 200, x + 5, y + 225);
    txCircle(x - 20, y + 200, 25);


    //hand
    txSetFillColor(TX_ORANGE);
    POINT HandL[3] = {{ROUND(x +  25), ROUND(y +  75)},
                      {ROUND(x + 150), ROUND(y +  75)},
                      {ROUND(x +  35), ROUND(y + 125)}};
    txPolygon(HandL, 3);

    POINT HandR[3] = {{ROUND(x +  33), ROUND(y +  125)},
                      {ROUND(x + 150), ROUND(y +  150)},
                      {ROUND(x +  40), ROUND(y +  150)}};
    txPolygon(HandR, 3);

    //tail
    POINT tail[4] =  {{ROUND(x -  50), ROUND(y + 200)},
                      {ROUND(x -  50), ROUND(y + 100)},
                      {ROUND(x - 100), ROUND(y +  50)},
                      {ROUND(x - 125), ROUND(y + 125)}};
    txPolygon(tail, 4);

    //head
    POINT head[5] =  {{ROUND(x -  50), ROUND(y - 100)},
                      {ROUND(x),            ROUND(y - 100)},
                      {ROUND(x + 150), ROUND(y - 50)},
                      {ROUND(x),            ROUND(y)},
                      {ROUND(x -  50), ROUND(y)}};
    txPolygon(head, 5);
    txSetColor(TX_BLACK, 10);
    txCircle(x + 150, y - 50, 4);

    //Eye
    txCircle(x, y - 75, 5);

    //ears
    POINT earL[5] = {{ROUND(x - 50),  ROUND(y - 100)},
                     {ROUND(x - 37),  ROUND(y - 150)},
                     {ROUND(x - 25),  ROUND(y - 100)}};
    txPolygon(earL, 3);

    POINT earR[5] = {{ROUND(x - 25),  ROUND(y - 100)},
                     {ROUND(x - 12),  ROUND(y - 150)},
                     {ROUND(x),            ROUND(y - 100)}};
    txPolygon(earR, 3);
    }
//-----------------------------------------------------------------------------

