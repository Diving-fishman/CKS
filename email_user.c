#include"allfunc.h"
#include"ufunc.h"
#include"email_u.h"

void email_user(int *func,int *unum,int* num)
{
    VisitorList VL;
    DATE a[5];
	
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	get_time(a);//获取时间
	
    mouse_off(&mouse);
	draw_email_user(a);
	putmail(&VL,unum);
	mouse_on(mouse);
	
	while(1)
	{
	    mouse_show(&mouse);
	
	    if(mouse_press(15,10,120+48*2,90)==1)
        {
            *func=*num;
            break;
        }
	}
	DestroyVisitorList(&VL);
}

void draw_email_user(DATE *p)
{
    int i=0;
	bar1(0,0,1023,767,0x87CEFA);
	
    // 绘制表格
    Line_Thick(200,150,800,150, 2, 0x000000);
    Line_Thick(200,150,200,150+5+65*8, 2, 0x000000);
    Line_Thick(200,150+5+65*8,800,150+5+65*8,2, 0x000000);
	Line_Thick(800,150,800,150+5+65*8,2,0x000000);

    prt_hz16_size(120, 50 - 16 * 3 / 2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
	prt_hz16_size(400,70, 3, 3, "今日邮件", 0x000000, "HZK\\HZK16s");
	
	//绘制时间
	prt_hz16_size(760,70,2,2,"今天是",0x000000,"HZK\\HZK16s");
	put_asc16_size( 760+16*2*3+10,70,2,2,p[0].year,0xFFFFFF);
	put_asc16_size( 760+16*2*3+10+80,70,2,2,p[0].month,0xFFFFFF);
	put_asc16_size( 760+16*2*3+10+110,70,2,2,p[0].day,0xFFFFFF);
	bar2(750,70,750+16*2*3+110+60,150,0x00FF);
	
}

void putmail(VisitorList *VL,int *unum)
{
    int i=0;
    int  y =  150 ;  // 起始坐标
    int  yr = 60;  // 每行的高度

    // 打印访客信息
    y += yr;  // 跳过表头 
    for ( i = 0; i < VL->length; i++) 
	{
        if(VL->elem[i].condition==1&&VL->elem[i].dengji_user==*unum)
		{
			prt_hz16_size(200+5,y+5,2,2,"您可以于",0x000000,"HZK\\HZK16s");
			put_asc16_size(200+5+130,y+5,2,2,VL->elem[i].dengji_year,0xFFFFFF);
			put_asc16_size(200+5+250,y+5,2,2,VL->elem[i].dengji_month,0xFFFFFF);
			put_asc16_size(200+5+280,y+5,2,2,VL->elem[i].dengji_date,0xFFFFFF);
			prt_hz16_size(200+5+350,y+5,2,2,"进入校园",0x000000,"HZK\\HZK16s");
			
			Line_Thick(200,y+40,800,y+40,2,0x000000);

			y += yr;  // 下一行
		}
		else if(VL->elem[i].condition==0&&VL->elem[i].dengji_user==*unum)
		{
			prt_hz16_size(200+5,y+5,2,2,"您于",0x000000,"HZK\\HZK16s");
			put_asc16_size(200+5+130,y+5,2,2,VL->elem[i].dengji_year,0xFFFFFF);
			put_asc16_size(200+5+250,y+5,2,2,VL->elem[i].dengji_month,0xFFFFFF);
			put_asc16_size(200+5+280,y+5,2,2,VL->elem[i].dengji_date,0xFFFFFF);
			prt_hz16_size(200+5+350,y+5,2,2,"的登记未通过",0x000000,"HZK\\HZK16s");
			
			Line_Thick(200,y+40,800,y+40,2,0x000000);

			y += yr;  // 下一行
		}
    }
}