#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
typedef struct body {
    /***********补充代码1***********/
	int x;
	int y;
	int flag;  //1:head  0:body
	struct body *next,*pre;
}SnakeBody;

typedef struct snake{        //用线性表存储蛇的资料
    /***********补充代码2***********/
	
	SnakeBody *snakehead,*snaketail;
	int n;	
	int der;
} Snake;

void initbeginmap(int width,int height);
void putApple(int x,int y);
void eatapple(int x,int y);
Snake *createSanke()  ;
void initSnake(Snake *s, int x,int y, int len);
void  Snakemove(Snake *s);
SnakeBody *  delsnaketail(Snake *s);
void insertsnake(Snake *s,SnakeBody *q,int x,int y);

void paintsnakebody(int x,int y);

void main()
{

    Snake *snake=NULL;
    char c =' ';
	int app_x=5,app_y=6;
    initgraph(640, 480);
	srand((int)time(0));
	//setlinestyle(PS_SOLID,2);

    initbeginmap(32,24);     //设置背景
	setwritemode(R2_XORPEN); //设置 XOR 绘图模式
    
	snake=createSanke();
	initSnake(snake,20,10,3);
	putApple(app_x,app_x);

	while(1)
	{
		if(kbhit())
		{
			c=getch();
			if(snake->der !=4 && (c=='A' || c=='a' ))
					snake->der =2;
			else if(c=='c' || c=='C')
				break;
				//方向问题
			
		}
		//Sleep(1000);
		Snakemove(snake);
		Sleep(1000);

	}
    pas

	
    getch();
    closegraph();
}
void initbeginmap(int width,int height)   //创建背景
{
    int i,j;
	setbkcolor(BLACK);
	cleardevice();
	setcolor(LIGHTGREEN);
	for(i=0;i<height*20;i=i+20)
		line(0,i,width*20-1,i);
	line(width*20-1,0,width*20-1,height*20-1);
	for(i=0;i<width*20;i=i+20)
		line(i,0,i,height*20-1);
	line(0,height*20-1,width*20-1,height*20-1);
}


Snake *createSanke()
{
	Snake *sn=NULL;
	sn=(Snake *)malloc(sizeof(Snake));
	
	sn->n=0;
	sn->snakehead=NULL;
	sn->snaketail=NULL;
	return sn;
}

void initSnake(Snake *s, int x,int y, int len)
{
	int i;
	SnakeBody *p;
	for(i=1;i<=len;i++)
	{

		p=(SnakeBody *)malloc(sizeof(SnakeBody));
		p->x=x;
		p->y =y;
		p->next=NULL;
		if(i==1)
			p->flag =1;
		else 
			p->flag =0;

		if(s->snakehead==NULL)
		{
			s->snakehead=p;
			p->pre=NULL;
			s->snaketail=p;
		}
		else
		{
			s->snaketail->next=p;
			p->pre=s->snaketail;
			s->snaketail=p;
		}
		s->n++;
		s->der=1;
		// 图形实现
		paintsnakebody(x,y);
		y++;

	}
}

void putApple(int x,int y)
{
	setcolor(RED);
	setfillcolor(LIGHTGREEN);
	fillcircle((x-1)*20+10,(y-1)*20+10,9);
	
}

void  Snakemove(Snake *s)
{
	SnakeBody *p;
	int x,y;
	p=delsnaketail(s);
	paintsnakebody(p->x ,p->y ); //擦除
    //Sleep(1000);
	x=s->snakehead->x ;
	y=s->snakehead->y ;

	if(s->der ==1)
		y--;
	else if(s->der ==2)
		x--;
	else if(s->der ==3)
		y++;
	else if(s->der ==4)
		x++;

	insertsnake(s,p,x,y);
	paintsnakebody(x ,y);  //画新的蛇头
	//Sleep(1000);
}

SnakeBody *  delsnaketail(Snake *s)
{
	SnakeBody *p;
	p=s->snaketail;
	s->snaketail=p->pre;
	s->snaketail->next =NULL;
	return p;
}

void insertsnake(Snake *s,SnakeBody *q,int x,int y)
{
	q->next =s->snakehead ;
	s->snakehead->pre =q;
	s->snakehead =q;
	q->flag =0;
	q->x =x;
	q->y =y;
}

void paintsnakebody(int x,int y)
{
		setcolor(RED);
		setfillcolor(YELLOW);
		fillroundrect((x-1)*20+1,(y-1)*20+1,(x)*20-1,(y)*20-1,10,10);
		//floodfill((x-1)*20+3,(y-1)*20+3,RED);
}