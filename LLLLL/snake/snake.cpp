#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
typedef struct body {
    /***********�������1***********/
	
	
}SnakeBody;

typedef struct snake{        //�����Ա�洢�ߵ�����
    /***********�������2***********/
	
} Snake;

void initbeginmap(int width,int height);
void putApple(int x,int y);
Snake *createSanke()  ;
void initSnake(Snake *s, int x,int y, int len);
void  moveSnake(Snake *s);


void main()
{

    Snake *snake=NULL;
    char c =' ';

    initgraph(640, 480);
	srand((int)time(0));
	
    initbeginmap(64,48);     //���ñ���
	setwritemode(R2_XORPEN); //���� XOR ��ͼģʽ
    	
	
    getch();
    closegraph();
}
void initbeginmap(int width,int height)   //��������
{
    int i,j;
	setbkcolor(BLACK);
	cleardevice();
	setcolor(LIGHTGREEN);
	for(i=0;i<480;i=i+20)
		line(0,i,639,i);
	line(639,0,639,479);
	for(i=0;i<640;i=i+20)
		line(i,0,i,479);
	line(0,479,639,479);
}



