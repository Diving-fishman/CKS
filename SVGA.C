#include "SVGA.h"
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
//#include <ghz.h>
#include "mouse.h"


/**********************************************************
Function：		SetSVGA64k

Description：	SVGA显示模式设置函数，设为0x117

Calls：			int86
				delay
				printf
				exit

Called By：		AutoSimulate
				HandOperate
				
Input：			None

Output：		错误信息

Return：		None				
Others：		None
**********************************************************/
void SetSVGA64k(void)
{
	/*REGS联合体见上*/
	union REGS graph_regs;
	
	/*设置VESA VBE模式的功能号*/
	graph_regs.x.ax = 0x4f02;
	graph_regs.x.bx = 0x117;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*ax != 0x004f意味着初始化失败，输出错误信息见上,下同*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
}


/**********************************************************
Function：		Putpixel256

Description：	画点函数，其他画图函数的基础，仅适用于0x105模式！

Calls：			Selectpage

Called By：		Putbmp256
				Line
				Circle
				
Input：			int x					像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					像素纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned char color		颜色数，共有256种

Output：		在屏幕上画指定颜色的点

Return：		None
Others：		None
**********************************************************/
void Putpixel256(int x, int y, unsigned char color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;	/*64k个点一换页，除以64k的替代算法*/
	Selectpage(new_page);
	
	/*向显存写入颜色，对应点画出*/
	video_buffer[page] = color;	
}

/**********************************************************
Function：		Putpixel64k

Description：	画点函数，其他画图函数的基础，仅适用于0x117模式！

Calls：			Selectpage

Called By：		Putbmp64k
				MousePutBk
				MouseDraw
				
Input：			int x					像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					像素纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned int color		颜色数，共有64k种

Output：		在屏幕上画指定颜色的点

Return：		None
Others：		None
**********************************************************/
void Putpixel64k(int x, int y, unsigned int color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;	/*32k个点一换页，除以32k的替代算法*/
	Selectpage(new_page);
	
	/*向显存写入颜色，对应点画出*/
	video_buffer[page] = color;	
}



/**********************************************************
Function：		Xorpixel

Description：	按位异或画点函数

Calls：			Selectpage

Called By：		XorCarBmp
				
Input：			int x					像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					像素纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned char color		颜色数，共有256种

Output：		在屏幕上画异或点

Return：		None
Others：		None
**********************************************************/
void Xorpixel(int x, int y, unsigned char color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;
	Selectpage(new_page);
	
	/*按位异或方式向显存写入颜色，对应点画出*/
	video_buffer[page] ^= color;	
}

/***8位显示模式下划线***/ 
void Line(int x1, int y1, int x2, int y2, unsigned char color)
{
	int i;
	if(x1==x2)                   //竖直直线
	{
		for(i=y1;i<=y2;i++)
			Putpixel256(x1,i,color);
	}
	if(y1==y1)                   //水平直线
	{
		for(i=x1;i<=x2;i++)
			Putpixel256(i,y1,color);
	}
}
/***24位显示模式下划线***/
void Line1(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i;
	if(x1==x2)                   //竖直直线
	{
		for(i=y1;i<=y2;i++)
			Putpixel64k(x1,i,color);
	}
	if(y1==y1)                   //水平直线
	{
		for(i=x1;i<=x2;i++)
			Putpixel64k(i,y1,color);
	}
}

void Line2(int x1, int y1, int x2, int y2, unsigned int color)
{
	int	dx, dy;			/*直线x、y坐标差值*/
	int dx2, dy2;		/*加快运算速度的中间值*/
	int xinc, yinc;		/*判断想、y增加方向的符号值*/
	int d, dxy;			/*决策变量*/
	/*计算坐标差值和中间变量*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*判断直线x坐标增加方向*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*如果是竖直线*/
	else if (x2 == x1)
	{
		/*y坐标排序*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*画竖直线*/
		for (dx = y1; dx <= y2; dx++)
		{
			Putpixel64k(x1, dx, color);
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*判断直线y坐标增加方向*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*如果是水平线*/
	else if (y2 == y1)
	{
		Line1(x1, y1, x2, y1, color);		
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	以下运用Bresenham算法生成直线。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	*******************************/
	Putpixel64k(x1, y1, color);
	
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Putpixel64k(x1, y1, color);
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Putpixel64k(x1, y1, color);
		}
	}
}

/***24位显示模式下划粗直线***/
void Line3(int x1, int y1, int x2, int y2, int radius,unsigned int color)
{
	int i;
	int dx,dy;
	if(x1>x2)    //解决x,y大小顺序问题
	{
		dx=x1;
		x1=x2;
		x2=dx;
	}
	if(y1>y2)
	{
		dy=y1;
		y1=y2;
		y2=dy;
	}
	if(x1==x2)                   //竖直直线
	{
		for(i=y1;i<=y2;i++)
			Circlefill(x1, i, radius, color);
	}
	if(y1==y1)                   //水平直线
	{
		for(i=x1;i<=x2;i++)
			Circlefill(i, y1, radius, color);
	}
}

void Line_Thick(int x1, int y1, int x2, int y2, int radius,unsigned int color)
{
	int	dx, dy;			/*直线x、y坐标差值*/
	int dx2, dy2;		/*加快运算速度的中间值*/
	int xinc, yinc;		/*判断x、y增加方向的符号值*/
	int d, dxy;			/*决策变量*/
	
	/*计算坐标差值和中间变量*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*判断直线x坐标增加方向*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*如果是竖直线*/
	else if (x2 == x1)
	{
		/*y坐标排序*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*画竖直线*/
		for (dx = y1; dx <= y2; dx++)
		{
			Circlefill(x1, dx, radius, color);
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*判断直线y坐标增加方向*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*如果是水平线*/
	else if (y2 == y1)
	{
		Line3(x1, y1, x2, y1,radius, color);		
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	以下运用Bresenham算法生成直线。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	*******************************/
	Circlefill(x1, y1, radius, color);
	
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Circlefill(x1, y1, radius, color);
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Circlefill(x1, y1, radius, color);
		}
	}
}

/***8位显示模式下画矩形***/
void Bar(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i,j;
	for(j=y1;j<=y2;j++)
	{
		Line(x1,j,x2,j,color);
	}
}
/***24位显示模式下画矩形***/
void bar1(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i,j;
	for(j=y1;j<=y2;j++)
	{
		Line1(x1,j,x2,j,color);
	}
}


/***24位显示模式下画矩形(不填色)***/
void bar2(int x1,int y1,int x2,int y2,unsigned int color)
{
	Line1(x1,y1,x2,y1,color);
    Line1(x2,y1,x2,y2,color);
	Line1(x1,y1,x1,y2,color);
	Line1(x1,y2,x2,y2,color);
}

void Circle(int xc, int yc, int radius, unsigned int color)
{
	/*画圆圈的定位变量和决策变量*/
	int x, y, d;
	
	/*半径必须为正，否则退出*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	以下运用Bresenham算法生成圆圈。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	************************************/
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(xc + x, yc + y, color);
		Putpixel64k(xc + x, yc - y, color);
		Putpixel64k(xc - x, yc - y, color);
		Putpixel64k(xc - x, yc + y, color);
		Putpixel64k(xc + y, yc + x, color);
		Putpixel64k(xc + y, yc - x, color);
		Putpixel64k(xc - y, yc - x, color);
		Putpixel64k(xc - y, yc + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}

void Circlefill(int xc, int yc, int radius, unsigned int color)
{
	/*画圆圈的定位变量和决策变量*/
	int x = 0,
		y = radius,
		dx = 3,
		dy = 2 - radius - radius,
		d = 1 - radius;
	
	/*半径必须为正，否则退出*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	以下运用Bresenham算法生成实心圆。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	************************************/
	while (x <= y)
	{
		Line1(xc - x, yc - y, xc + x, yc-y, color);
        Line1(xc - y, yc - x, xc + y, yc-x, color);
        Line1(xc - y, yc + x, xc + y, yc+x, color);
        Line1(xc - x, yc + y, xc + x, yc+y, color);
        
        if (d < 0)
        {
            d += dx;
            dx += 2;
        }
        
        else
        {
            d += (dx + dy);
            dx += 2;
            dy += 2;
            y--;
		}

        x++;
	}
}

void CloseSVGA(void)        
{
    union REGS regs;
    regs.h.ah=0;
    regs.h.al=0x03;
    int86(0x10,&regs,&regs);     
}



/*******************
功能说明：读取矩形区域图像信息到缓存区
参数说明：读入矩形区域左上和右下顶点坐标，缓存区指针
*******************/
void Get_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{
	int i=0;                                   /*循环变量*/
	int j=0;
	int wide=x1-x0;
    int high=y1-y0;
	for(i=0;i<high;i++)
	{
		for(j=0;j<wide;j++)
		{
			save[i*wide+j]=Getpixel64k(x0+j, y0+i);
		}
	}
}

/*******************
功能说明：从缓存区读出图像信息到矩形区域
参数说明：读入矩形区域左上和右下顶点坐标，缓存区指针
*******************/
void Put_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{

	int i=0;                                   /*循环变量*/
	int j=0;
	int wide=x1-x0;
	int high=y1-y0;
	unsigned   int far *VideoBuffer=(unsigned int far *)0xa0000000L ;
	long int newpage=0;
	long int  oldpage=0;
	unsigned long pos;
	for(i=0;i<high;i++)
	{
		if((i+y0)>768)
		{
			continue;
		}
		Selectpage(newpage);
		for(j=0;j<x1-x0;j++)
		{   
            if((j+x0)>1024)
			{
				continue;
			}  
			pos=((unsigned long)(y0+i)<<10)+x0+j;
			newpage=pos>>15 ;                         /*除以32k的替代算法*/
			if (newpage != oldpage)            //调用换页函数
			{
				Selectpage(newpage);
				oldpage = newpage;
			}
			VideoBuffer[pos]=save[i*wide+j];
		}
	}
}

/***画按钮***/
void Cirbar(int x1, int y1, int x2, int y2, unsigned int color)
{
	int y3=(y1+y2)/2;
	int r=(y2-y1)/2;
	Circlefill(x1,y3,r,color);
	Circlefill(x2,y3,r,color);
	bar1(x1,y1,x2,y2,color); 
}

void Selectpage(register char page)
{
	/*REGS含义同上*/
	union REGS graph_regs;
	
	/*上一次的页面号,用于减少切换次数,是使用次数很多的重要变量*/
	static unsigned char old_page = 0;
	
	/*标志数，用于判断是否是第一次换页*/
	static int flag = 0;
	
	/*窗口页面控制功能号*/
	graph_regs.x.ax = 0x4f05;
	graph_regs.x.bx = 0;
	
	/*如果是第一次换页*/
	if (flag == 0)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
		flag++;
	}
	
	/*如果和上次页面号不同，则进行换页*/
	else if (page != old_page)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
	}
}
