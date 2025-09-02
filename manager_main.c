#include"allfunc.h"
#include "m_main.h"
#include "m_func.h"

void manager_main(int *func)
{
	int f[10]={0};
	DATE a[5];
	get_time(a);
	mouse_off(&mouse);
	draw_manager_main(a);
    mouse_on(mouse);
	
	while (1)
	{
		mouse_show(&mouse);
		//移至退出
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				*func=12;
				break;
			}else if(f[0]==0)
				{
					Light_manager_main(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				Dark_manager_main(0);
				f[0]=0;
			}
		}
		//移至历史记录
		if(mouse.x>170&&mouse.x<640&&mouse.y>150&&mouse.y<150+140)
		{
			if (mouse_press(170,150,640,150+140)==1)
			{
				*func=4;
				break;
			}else if(f[1]==0)
				{
					Light_manager_main(1);
					f[1]=1;
					continue;
				}
		} else 
		{
			if (f[1]==1)
			{
				Dark_manager_main(1);
				f[1]=0;
			}
		}
		
		//移至审核申请
		if(mouse.x>170&&mouse.x<640&&mouse.y>150+140+45&&mouse.y<150+140+45+140)
		{
			if (mouse_press(170,150+140+45,640,150+140+45+140)==1)
			{
				*func=41;
				break;
			}else if(f[2]==0)
				{
					Light_manager_main(2);
					f[2]=1;
					continue;
				}
		} else 
		{
			if (f[2]==1)
			{
				Dark_manager_main(2);
				f[2]=0;
			}
		}
		
		
		//移至数据分析
		if(mouse.x>170&&mouse.x<640&&mouse.y>150+140*2+45*2&&mouse.y<150+140*3+45*2)
		{
			if (mouse_press(170,150+140*2+45*2,640,150+140*3+45*2)==1)
			{
				*func=42;
				break;
			}else if(f[3]==0)
				{
					Light_manager_main(3);
					f[3]=1;
					continue;
				}
		} else 
		{
			if (f[3]==1)
			{
				Dark_manager_main(3);
				f[3]=0;
			}
		}
		//移至邮箱
		if(mouse.x>800&&mouse.x<980&&mouse.y>660&&mouse.y<740)
		{
			if (mouse_press(800,660,980,740)==1)
			{
				*func=43;
				break;
			}else if(f[4]==0)
				{
					Light_manager_main(4);
					f[4]=1;
					continue;
				}
		} else 
		{
			if (f[4]==1)
			{
				Dark_manager_main(4);
				f[4]=0;
			}
		}
	}
}

void draw_manager_main(DATE *p)
{
    bar1(0,0,1023,767,0x87CEFA);//背景色;
//    bar1(0,0,1023,767,0xFFFFFF);//背景色;
//    bar1(0,0,210,100,0x00FF);//返回

    JianTou(15,50,60,10,115,30,0x000000);
    prt_hz16_size( 120,50-16*3/2, 3, 3, "退出", 0x000000, "HZK\\HZK16s");

    bar1(170,150,640,150+140,0x00FF);//历史记录
    bar1(170,150+140+45,640,150+140+45+140,0x00FF);//审核申请
    bar1(170,150+140*2+45*2,640,150+140*3+45*2,0x00FF);//数据分析
    bar1(750,0,1023,650,0x90EE90);//今日概况
    
    bar1(800,660,980,740,0x553D33);//邮箱
    Line_Thick(800,660,890,710, 2,0xFFFFFF);
    Line_Thick(890,710,980,660, 2,0xFFFFFF);
    bar1(888,700,892,704,0xFFFFFFF);
    
//    prt_hz16_size( 50,30,3,3, "返回", 0xFFFFFF, "HZK\\HZK16s");
    prt_hz16_size( 405-48*2,220-48/2,3,3, "历史记录", 0xFFFFFF, "HZK\\HZK16s");
    prt_hz16_size( 405-48*2,220-48/2+140+45,3,3, "审批申请", 0xFFFFFF, "HZK\\HZK16s");
    prt_hz16_size( 405-48*2,220-48/2+140*2+45*2,3,3, "数据分析", 0xFFFFFF, "HZK\\HZK16s");
    prt_hz16_size( 780,30,3,3, "今日概况", 0x000000, "HZK\\HZK16s");

    prt_hz16_size(760,100,2,2,"今天是",0x000000,"HZK\\HZK16s");
    put_asc16_size( 760+16*2*3+10,100,2,2,p[0].year,0xFFFFFF);
    put_asc16_size( 760+16*2*3+10+80,100,2,2,p[0].month,0xFFFFFF);
    put_asc16_size( 760+16*2*3+10+110,100,2,2,p[0].day,0xFFFFFF);
    
    prt_hz16_size(760,100+70,2,2,"预约人数",0x000000,"HZK\\HZK16s");
    put_asc16_number_size(760+150,100+70,2,2,reserve_num (0,p),0x000000);
    prt_hz16_size(760,100+70+50,2,2,"进校人数",0x000000,"HZK\\HZK16s");
    put_asc16_number_size(760+150,100+70+50,2,2,arrive_num(0,p),0x000000);
    prt_hz16_size(760,100+70+50*2,2,2,"车辆数",0x000000,"HZK\\HZK16s");
    put_asc16_number_size(760+150,100+70+50*2,2,2,car_num(0,p),0x000000);
    prt_hz16_size(760,100+70+50*3,2,2,"校外占比",0x000000,"HZK\\HZK16s");
    put_asc16_number_size(760+150,100+70+50*3,2,2,xiaowai_rate(0,p),0x000000);
    Put_Asc16_Size(980,100+70+50*3,2,2,'%',0x000000);
    prt_hz16_size(760,100+70+50*4,2,2,"主校区占比",0x000000,"HZK\\HZK16s");
    put_asc16_number_size(760+150,100+70+50*4,2,2,zhuxq_rate(0,p),0x000000);
    Put_Asc16_Size(980,100+70+50*4,2,2,'%',0x000000);
}
void Light_manager_main(int tag)
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
			prt_hz16_size( 405-48*2,220-48/2,3,3, "历史记录", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		case 2:
		{
			bar1(170+1,150+140+45+1,640-1,150+140+45+140-1,0xB3B5B6);//审核申请
			prt_hz16_size( 405-48*2,220-48/2+140+45,3,3, "审批申请", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		case 3:
		{
			bar1(170+1,150+140*2+45*2+1,640-1,150+140*3+45*2-1,0xB3B5B6);//数据分析
			prt_hz16_size( 405-48*2,220-48/2+140*2+45*2,3,3, "数据分析", 0xDC2DF1F, "HZK\\HZK16s");
			break;
		}
		case 4:
		{
			bar1(800+1,660+1,980-1,740-1,0xB3B5B6);//邮箱
			Line_Thick(800,660,890,710, 2,0xFFFFFF);
			Line_Thick(890,710,980,660, 2,0xFFFFFF);
			bar1(888,700,892,704,0xFFFFFF);
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void Dark_manager_main(int tag)
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
			prt_hz16_size( 405-48*2,220-48/2,3,3, "历史记录", 0xFFFFFF, "HZK\\HZK16s");
			break;
		}
		case 2:
		{
			bar1(170,150+140+45,640,150+140+45+140,0x00FF);//审核申请
			prt_hz16_size( 405-48*2,220-48/2+140+45,3,3, "审批申请", 0xFFFFFF, "HZK\\HZK16s");
			break;
		}
		case 3:
		{
			bar1(170,150+140*2+45*2,640,150+140*3+45*2,0x00FF);//数据分析
			prt_hz16_size( 405-48*2,220-48/2+140*2+45*2,3,3, "数据分析", 0xFFFFFF, "HZK\\HZK16s");
			break;
		}
		case 4:
		{
			bar1(800,660,980,740,0x553D33);//邮箱
			Line_Thick(800,660,890,710, 2,0xFFFFFF);
			Line_Thick(890,710,980,660, 2,0xFFFFFF);
			bar1(888,700,892,704,0xFFFFFFF);
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

