#include <allfunc.h>
#include "xuanze.h"
//#include"login.h"

void xuanze(int *func)
{
	mouse_off(&mouse);
	draw_xuanze();
    mouse_on(mouse);
	
	while (1)
	{
		mouse_show(&mouse);
		if(mouse_press(280,190,1024-280,190+100)==1)					//用户
		{
			*func=2;
			break;
		}
		if(mouse_press(280,190+100+60,1024-280,190+100+60+100)==1)		//学生
		{
			*func=21;
			break;
		}
		if(mouse_press(280,190+200+120,1024-280,190+200+180)==1)		//管理员
		{
			*func=22;
			break;
		}
		if(mouse_press(15,10,120+48*2,90)==1)				//返回
		{
			*func=0;
			break;
		}
	}
}

void draw_xuanze(void)
{
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	Cirbar(280,190,1024-280,190+100,0x00FF);//蓝色框
	Cirbar(280,190+100+60,1024-280,190+100+60+100,0x00FF);
	Cirbar(280,190+200+120,1024-280,190+300+120,0x00FF);
//	bar1(15,10,120+48*2,90,0xFFFFFF);
	
	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");

	
	prt_hz16_size( 512-16*5*7/2,50, 5, 5, "请选择您的身份", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(512-16*4*2,190+50-16*2 , 4, 4, "用户登录", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size(512-16*4*2,190+100+60+50-16*2 , 4, 4, "学生登录", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size(512-16*5*2,190+200+120+50-16*2 , 4, 4, "管理员登录", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
}

