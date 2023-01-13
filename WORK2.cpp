#include "TXLib.h"

void fox_draw (double x, double y, double dHandL, double dHandR);
void bird_draw (double x, double y);

int main()
    {
    //окно
    txTextCursor (false);
    txCreateWindow(1600, 900);
    txRectangle(0, 0, 1600, 900);
    double x = 300;
    double y = 300;
    fox_draw (x, y, -20, -20);
    x = 800;
    fox_draw (x, y, 0, 0);
    x = 1300;
    fox_draw (x, y, 20, 20);

    }


//-----------------------------------------------------------------------------
void fox_draw (double x, double y, double dHandL, double dHandR)
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
    POINT HandL[3] = {{ROUND(x +  10), ROUND(y +  75)},
                      {ROUND(x + 150), ROUND(y +  75+dHandL)},
                      {ROUND(x +  25), ROUND(y + 115)}};
    txPolygon(HandL, 3);

    POINT HandR[3] = {{ROUND(x +  30), ROUND(y +  125)},
                      {ROUND(x + 150), ROUND(y +  150+dHandR)},
                      {ROUND(x +  35), ROUND(y +  150)}};
    txPolygon(HandR, 3);

    //tail
    POINT tail[4] =  {{ROUND(x -  50), ROUND(y + 200)},
                      {ROUND(x -  50), ROUND(y + 100)},
                      {ROUND(x - 100), ROUND(y +  50)},
                      {ROUND(x - 125), ROUND(y + 125)}};
    txPolygon(tail, 4);

    //head
    POINT head[5] =  {{ROUND(x -  50), ROUND(y - 100)},
                      {ROUND(x),       ROUND(y - 100)},
                      {ROUND(x + 150), ROUND(y - 50)},
                      {ROUND(x),       ROUND(y)},
                      {ROUND(x -  50), ROUND(y)}};
    txPolygon(head, 5);
    txSetColor(TX_BLACK, 10);
    txCircle(x + 150, y - 50, 4);

    //Eye
    txCircle(x, y - 75, 5);

    //ears
    POINT earL[5] = {{ROUND(x - 50),          ROUND(y - 100)},
                     {ROUND(x - 37 ),         ROUND(y - 150)},
                     {ROUND(x - 25),          ROUND(y - 100)}};
    txPolygon(earL, 3);

    POINT earR[5] = {{ROUND(x - 25),          ROUND(y - 100)},
                     {ROUND(x - 12),          ROUND(y - 150)},
                     {ROUND(x),               ROUND(y - 100)}};
    txPolygon(earR, 3);
    }
//-----------------------------------------------------------------------------

