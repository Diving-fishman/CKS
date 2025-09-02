#include"allfunc.h"
//#include"lgfunc.h"
#include "u_main.h"
#include"email_u.h"
#include"ufunc.h"

void user_main(int *func,int *unum)
{
	int f[10]={0};
	DATE a[5];

	get_time(a);
	mouse_off(&mouse);
	draw_user_main(a);
    mouse_on(mouse);
	//bianxie(*unum);
	while (1)
	{
		mouse_show(&mouse);
		//移至退出
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				*func=0;
				break;
			}else if(f[0]==0)
				{
					Light_user_main(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				Dark_user_main(0);
				f[0]=0;
			}
		}
		//移至登记信息
		if(mouse.x>170&&mouse.x<640&&mouse.y>150&&mouse.y<150+140)
		{
			if (mouse_press(170,150,640,150+140)==1)
			{
				*func=51;
				break;
			}else if(f[1]==0)
				{
					Light_user_main(1);
					f[1]=1;
					continue;
				}
		} else 
		{
			if (f[1]==1)
			{
				Dark_user_main(1);
				f[1]=0;
			}
		}
		
		//移至取消登记
		if(mouse.x>170&&mouse.x<640&&mouse.y>150+140+45&&mouse.y<150+140+45+140)
		{
			if (mouse_press(170,150+140+45,640,150+140+45+140)==1)
			{
				can_dengji(func,31,unum);
				break;
			}else if(f[2]==0)
				{
					Light_user_main(2);
					f[2]=1;
					continue;
				}
		} else 
		{
			if (f[2]==1)
			{
				Dark_user_main(2);
				f[2]=0;
			}
		}
		
		
		//移至历史登记
		if(mouse.x>170&&mouse.x<640&&mouse.y>150+140*2+45*2&&mouse.y<150+140*3+45*2)
		{
			if (mouse_press(170,150+140*2+45*2,640,150+140*3+45*2)==1)
			{
				story_user(func,31,unum);
				break;
			}else if(f[3]==0)
				{
					Light_user_main(3);
					f[3]=1;
					continue;
				}
		} else 
		{
			if (f[3]==1)
			{
				Dark_user_main(3);
				f[3]=0;
			}
		}
		
		//模拟进校操作
		if(mouse_press(400,20,400+100,20+50)==1)
		{
		    user_enter(func,unum,func);
			break;
		}
		//进入邮件系统
		if(mouse_press(800,660,980,740)==1)
		{
		    email_user(func,unum,func);
			break;
		}
	}
}

void draw_user_main(DATE *p)
{
	bar1(0,0,1023,767,0x87CEFA);//背景色;
//	bar1(0,0,210,100,0x00FF);//返回

	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "退出", 0x000000, "HZK\\HZK16s");

	bar1(170,150,640,150+140,0x00FF);//登记界面
	bar1(170,150+140+45,640,150+140+45+140,0x00FF);//取消登记
	bar1(170,150+140*2+45*2,640,150+140*3+45*2,0x00FF);//历史登记记录
	bar1(700,0,1023,650,0x90EE90);//今日概况
	
	bar1(800,660,980,740,0x553D33);//邮箱
	Line_Thick(800,660,890,710, 2,0xFFFFFF);
	Line_Thick(890,710,980,660, 2,0xFFFFFF);
	bar1(888,700,892,704,0xFFFFFFF);
	
	bar1(400,20,400+100,20+50,0x00FF);
	prt_hz16_size(410,30,2,2,"进校",0x000000,"HZK\\HZK16s");
	
//	prt_hz16_size( 50,30,3,3, "返回", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size( 405-48*2,220-48/2,3,3, "登记信息", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size( 405-48*2,220-48/2+140+45,3,3, "取消登记", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size( 405-48*2,220-48/2+140*2+45*2,3,3, "历史登记", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size( 780,30,2,2, "欢迎参观", 0x000000, "HZK\\HZK16s");
    prt_hz16_size( 780,100,2,2, "华中科技大学", 0x000000, "HZK\\HZK16s");
    prt_hz16_size( 780,200,2,2, "祝您拥有", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( 780,270,2,2, "愉快的一天", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( 780,400,2,2, "务必登记进校！", 0x000000, "HZK\\HZK16s");
	
	//绘制时间
	prt_hz16_size(760,550,2,2,"今天是",0x000000,"HZK\\HZK16s");
	put_asc16_size( 760+16*2*3+10,550,2,2,p[0].year,0xFFFFFF);
	put_asc16_size( 760+16*2*3+10+80,550,2,2,p[0].month,0xFFFFFF);
	put_asc16_size( 760+16*2*3+10+110,550,2,2,p[0].day,0xFFFFFF);
	bar2(750,525,750+16*2*3+110+60,600,0x00FF);
	
}

void Light_user_main(int tag)
{
	mouse_off(&mouse);
	switch(tag)
	{
		case 0:
		{
			bar1(15+1,10+1,120+48*2-1,90-1,0xB3B5B6);
			JianTou(15,50,60,10,115,30,0xDC2DF1);
			prt_hz16_size( 120,50-16*3/2, 3, 3, "退出", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		case 1:
		{
			bar1(170+1,150+1,640-1,150+140-1,0xB3B5B6);//历史记录
			prt_hz16_size( 405-48*2,220-48/2,3,3, "登记信息", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		case 2:
		{
			bar1(170+1,150+140+45+1,640-1,150+140+45+140-1,0xB3B5B6);//审核申请
			prt_hz16_size( 405-48*2,220-48/2+140+45,3,3, "取消登记", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		case 3:
		{
			bar1(170+1,150+140*2+45*2+1,640-1,150+140*3+45*2-1,0xB3B5B6);//数据分析
			prt_hz16_size( 405-48*2,220-48/2+140*2+45*2,3,3, "历史登记", 0xDC2DF1F, "HZK\\HZK16s");
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void Dark_user_main(int tag)
{
	mouse_off(&mouse);
	switch (tag)
	{
		case 0:
		{
			bar1(15+1,10+1,120+48*2-1,90-1,0x87CEFA);
			JianTou(15,50,60,10,115,30,0x000000);
			prt_hz16_size( 120,50-16*3/2, 3, 3, "退出", 0x000000, "HZK\\HZK16s");
			break;
		}
		case 1:
		{
			bar1(170,150,640,150+140,0x00FF);//历史记录
			prt_hz16_size( 405-48*2,220-48/2,3,3, "登记信息", 0xFFFFFF, "HZK\\HZK16s");
			break;
		}
		case 2:
		{
			bar1(170,150+140+45,640,150+140+45+140,0x00FF);//审核申请
			prt_hz16_size( 405-48*2,220-48/2+140+45,3,3, "取消登记", 0xFFFFFF, "HZK\\HZK16s");
			break;
		}
		case 3:
		{
			bar1(170,150+140*2+45*2,640,150+140*3+45*2,0x00FF);//数据分析
			prt_hz16_size( 405-48*2,220-48/2+140*2+45*2,3,3, "历史登记", 0xFFFFFF, "HZK\\HZK16s");
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}