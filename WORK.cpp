#include "TXLib.h"

void fox_draw (double x, double y, double size, double dHandL, double dHandR ,double dEarL, double dEarR, double dNose, int mirror);
void bird_draw (double x, double y, double size, double dLegL, double dLegR, int mirror);
void tree (double x, double y, double size);
void tree_draw();
void cheese (double x, double y, double size);

int main()
    {
    //окно
    txCreateWindow(1600, 900);
    txRectangle(0, 0, 1600, 900);
    double x = 300;
    double y = 300;
    int z = 0;
    tree_draw();

    //анимация
/*     while (y < 750)
        {
        x = 1100;
        y = y + 30;
        txSetFillColor(TX_WHITE);
        txClear();

        tree(x, y, 1);

        txSleep(150);

        }
*/
    while ( y < 700)
     {
        x = 500;
        y = y + 25;
        txSetFillColor(TX_WHITE);
        txClear();
        cheese(x,y,1);
        bird_draw(300,775,0.5,0,0,-1);
        txSleep(150);


     }
   double size = 0.5;
   while (x < 1100)
        {

        if (z % 4 == 4)   {x = x + 40;}
        else              {x = x + 15; }
        z++;
        y = y - 10;
        size = size - 0.002;


        txSetFillColor(TX_WHITE);
        txClear();
        tree_draw();
        bird_draw (x, y, size, 0, 0, -1);
        cheese(x + 150,y - 70, 1);
        txSleep(150);
        }
    x = 100;
    y = 100;

   double FSize = 0.1;

   while (x < 650)
        {
        if (z % -5 == -4) {x = x + 40;}
        else              {x = x + 15; }
        z++;
        y = y + 15;
        FSize = FSize + 0.02;
        txSetFillColor(TX_WHITE);
        txClear();
        tree_draw();
        bird_draw(1125, 225, 0.4, 0,0,-1);
        cheese(1275, 160,1);

        fox_draw (x, y, FSize, z%2 * 10, 0, 0, 0, 0, 1);

        txSleep(150);

        }
    x = 650;
    while ( x < 1250)
        {
        x = x + 15;
        txSetFillColor(TX_WHITE);
        txClear();
        tree_draw();
        bird_draw(1125, 225, 0.4, 0,0,-1);
        cheese(1275, 160,1);
        fox_draw(x, 650, 0.8, 0, 0, 0, 0, 0, 1);
        txSleep(150);
        }
    y = 160;
    while (y < 725)
        {
        y = y + 15;
        txSetFillColor(TX_WHITE);
        txClear();
        tree_draw();
        bird_draw(1125, 225, 0.4, 0,0,-1);

        fox_draw (1275, 650, 0.8, 0, 0, 0, 0, 0, -1);

        cheese(1275, y, 1);
        txSleep(50);


        }
        x = 1275;
    while (x > -100)
        {
        x = x - 30;
        txSetFillColor(TX_WHITE);
        txClear();
        tree_draw();
        bird_draw(1125, 225, 0.4, 0,0,-1);
        fox_draw (x, 650, 0.8, 0, 0, 0, 0, 0, -1);
        cheese(x - 50, 725, 1);
        txSleep(50);



        }
        }

/*
while (y < 775)
    {
    x = 300;
    y = y + 10;
    txSetFillColor(TX_WHITE);
    txClear();
    tree_draw();
    bird_draw (x, y, 0.5, 0, 0, -1);
    txSleep(50);
    }


    while ( y < 775)
     {
        x = 300;
        y = y + 25;
        txSetFillColor(TX_WHITE);
        txClear();
        cheese(x,y,1);
        bird_draw(x,y,0.5,0,0);
        txSleep(150);


     }

   double size = 0.5;
   while (x < 1100)
        {

        if (z % 4 == 4)   {x = x + 40;}
        else              {x = x + 15; }
        z++;
        y = y - 10;
        size = size - 0.002;


        txSetFillColor(TX_WHITE);
        txClear();
        tree_draw();
        bird_draw (x, y, size, -10, 10, -1);
        cheese(x + 150,y - 70, 1);
        txSleep(150);
        }
    }
*/

//-----------------------------------------------------------------------------
void bird_draw (double x, double y, double size, double dLegL, double dLegR, int mirror)
    {
    txSetFillColor(TX_TRANSPARENT);
    txSetColor(TX_BLACK, 7*size);

    //Body
    txSetFillColor(RGB(48, 48, 46));
    POINT BodyBird[6] = {{ROUND(x),            ROUND(y)},
                         {ROUND(x + 150*size*mirror), ROUND(y -  50*size)},
                         {ROUND(x),            ROUND(y + 100*size)},
                         {ROUND(x - 100*size*mirror), ROUND(y + 100*size)},
                         {ROUND(x - 200*size*mirror), ROUND(y -  50*size)},
                         {ROUND(x-  100*size*mirror), ROUND(y - 100*size)}};

    txPolygon(BodyBird, 6);

    //Legs
    txLine(x -  50*size*mirror, y + 100*size, x - 150*size        *mirror,   y + 200*size);
    txLine(x - 150*size*mirror, y + 200*size, x - 150*size*mirror + dLegL,   y + 225*size);
    txLine(x - 150*size*mirror, y + 200*size, x - 125*size*mirror + dLegL,   y + 225*size);
    txLine(x - 150*size*mirror, y + 200*size, x - 175*size*mirror + dLegL,   y + 225*size);
    txLine(x -  25*size*mirror, y + 100*size, x -  50*size*mirror,           y + 200*size);
    txLine(x -  50*size*mirror, y + 200*size, x -  50*size*mirror + dLegR,   y + 225*size);
    txLine(x -  50*size*mirror, y + 200*size, x -  25*size*mirror + dLegR,   y + 225*size);
    txLine(x -  50*size*mirror, y + 200*size, x -  75*size*mirror + dLegR,   y + 225*size);

    //Head
    txSetFillColor(RGB(89, 88, 83));
    txCircle(x - 175*size*mirror, y - 125*size, 75*size);

    //Wings
    txSetFillColor(RGB(89, 88, 83));
    POINT WingFirst[3] = {{ROUND(x),            ROUND(y)},
                          {ROUND(x - 100*size*mirror), ROUND(y +  50*size)},
                          {ROUND(x - 100*size*mirror), ROUND(y - 100*size)}};


    POINT WingSecond[3] = {{ROUND(x),            ROUND(y)},
                           {ROUND(x - 100*size*mirror), ROUND(y + 150*size)},
                           {ROUND(x - 100*size*mirror), ROUND(y - 100*size)}};
    txPolygon(WingFirst, 3);

    txSetFillColor(RGB(56, 55, 53));
    txPolygon(WingSecond, 3);

    //Beak
    txSetFillColor(RGB(89, 88, 83));
    POINT Beak[5] = {{ROUND(x - 200*size*mirror), ROUND(y - 150*size)},
                     {ROUND(x - 300*size*mirror), ROUND(y - 150*size)},
                     {ROUND(x - 200*size*mirror), ROUND(y - 100*size)},
                     {ROUND(x - 300*size*mirror), ROUND(y -  50*size)},
                     {ROUND(x - 200*size*mirror), ROUND(y -  75*size)}};
    txPolygon(Beak, 5);

    //Eye
    txSetColor(TX_RED, 7*size);
    txSetFillColor(TX_RED);
    txCircle(x - 150*size*mirror, y - 150*size, 5*size);

}

//-----------------------------------------------------------------------------
void fox_draw (double x, double y, double size, double dHandL, double dHandR, double dEarL, double dEarR, double dNose, int mirror)
    {
    //Fox Body
    txSetFillColor(TX_ORANGE);
    txSetColor(TX_BLACK, 7*size);
    POINT Body[3] =  {{ ROUND(x),                    ROUND(y)},
                     { ROUND(x - 50*size*mirror),   ROUND(y + 200*size)},
                     { ROUND(x + 50*size*mirror),   ROUND(y + 200*size)}};
    txPolygon(Body , 3);

    //Legs
    txSetFillColor(TX_ORANGE);
    txRectangle(x - 45*size*mirror, y + 200*size, x + 5*size*mirror, y + 225*size);
    txCircle(x - 20*size*mirror, y + 200*size, 25*size);


    //hand
    txSetFillColor(TX_ORANGE);
    POINT HandL[3] = {{ROUND(x +  10*size*mirror), ROUND(y +  75*size       )},
                      {ROUND(x + 150*size*mirror), ROUND(y +  75*size+dHandL)},
                      {ROUND(x +  25*size*mirror), ROUND(y + 115*size       )}};
    txPolygon(HandL, 3);

    POINT HandR[3] = {{ROUND(x +  30*size*mirror), ROUND(y +  125*size       )},
                      {ROUND(x + 150*size*mirror), ROUND(y +  150*size+dHandR)},
                      {ROUND(x +  35*size*mirror), ROUND(y +  150*size       )}};
    txPolygon(HandR, 3);

    //tail
    POINT tail[4] =  {{ROUND(x -  50*size*mirror), ROUND(y + 200*size)},
                      {ROUND(x -  50*size*mirror), ROUND(y + 100*size)},
                      {ROUND(x - 100*size*mirror), ROUND(y +  50*size)},
                      {ROUND(x - 125*size*mirror), ROUND(y + 125*size)}};
    txPolygon(tail, 4);

    //head
    POINT head[5] =  {{ROUND(x -  50*size*mirror), ROUND(y - 100*size)},
                      {ROUND(x),                   ROUND(y - 100*size)},
                      {ROUND(x + 150*size*mirror), ROUND(y - 50*size + dNose)},
                      {ROUND(x),                   ROUND(y)},
                      {ROUND(x -  50*size*mirror), ROUND(y)}};
    txPolygon(head, 5);
    txSetColor(TX_BLACK, 10*size);
    txCircle(x + 150*size*mirror, y - 50*size + dNose, 4*size);

    //Eye
    txCircle(x, y - 75*size, 5*size);

    //ears
    POINT earL[3] =  {{ROUND(x - 50*size*mirror),            ROUND(y - 100*size)},
                     {ROUND(x - (37 + dEarL)*size*mirror),  ROUND(y - 150*size)},
                     {ROUND(x - 25*size*mirror),            ROUND(y - 100*size)}};
    txPolygon(earL, 3);

    POINT earR[3] =  {{ROUND(x - 25*size*mirror),            ROUND(y - 100*size)},
                     {ROUND(x - (12 + dEarR)*size*mirror),   ROUND(y - 150*size)},
                     {ROUND(x),                              ROUND(y - 100*size)}};
    txPolygon(earR, 3);

    }

//------------------------------------------------------------------
void tree (double x, double y, double size)
    {
    txSetFillColor(RGB(30, 69, 11));
    POINT tree[3] =    {{ROUND (x      *size),ROUND    (y      *size)},
                        {ROUND (x - 125*size),ROUND    (y + 150*size)},
                        {ROUND (x + 125*size),ROUND    (y + 150*size)}};
    txPolygon(tree,3);
    }
void tree_draw ()
    {
    txSetColor(TX_BLACK, 7);
    tree (1100, 200, 1);
    tree (1100, 350, 1);
    tree (1100, 500, 1);
    txSetFillColor(TX_BROWN);
    txRectangle(1075, 650, 1125,  750);
    }

void cheese (double x, double y, double size)
        {
        txSetColor(TX_TRANSPARENT);
        POINT Cheese[3] =    {{ROUND (x      *size),ROUND      (y      *size)},
                              {ROUND (x + 35 *size),ROUND      (y + 30*size) },
                              {ROUND (x - 65 *size),ROUND      (y + 30*size)}};
        txSetFillColor(RGB(255, 235, 54));
        txPolygon(Cheese, 3);
        }




