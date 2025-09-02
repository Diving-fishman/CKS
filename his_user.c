#include"allfunc.h"
#include"ufunc.h"
#include"his_u.h"

void story_user(int *func,int unum,int* num)
{
	VisitorList VL;
	int f[10]={0};
	int count[10];
	int i=0,y_pos=0,j=0;
	int a=0,b=0,c=0;
	int x=70,y=130;
	int xr=(1024-2*x)/4,yr=60;		
	
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	mouse_off(&mouse);
	draw_his_user(x,y,xr,yr);
	PrintVisitors(&VL,*func,num);
	mouse_on(mouse);
	
	for(i=0;i<VL.length;i++)
	{
	    if(VL.elem[i].dengji_user==*num)
		    count[j++]=i;
	}
	
	j=0;
	
	while (1)
	{
		mouse_show(&mouse);
		
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				*func=unum;
				break;
			}
			else if(f[0]==0)
				{
					Light_manager_func(0);
					f[0]=1;
					continue;
				}
		} 
		else 
		{
			if (f[0]==1)
			{
				Dark_manager_func(0);
				f[0]=0;
			}
		}
		
		for (i = 0; i < VL.length; i++) 
		{
            y_pos = y + (i + 1) * yr;
            if (mouse_press(x+xr*3, y_pos, x + xr * 4, y_pos + yr) == 1) 
			{
                detail_user(&(VL.elem[count[i]]),func);  // 调用查看详情的函数
				j=1;
				if(VL.elem[i].user_stu==0)
			    {
				    bar1(800,600,900,650,0x00ff);
					prt_hz16_size(800+10,600+10, 1, 1, "查看同伴", 0x000000, "HZK\\HZK16s");
				}
            }
        }
		if(j==1)
		   break;
		
	}
    DestroyVisitorList(&VL);
}

void draw_his_user(int x,int y, int xr,int yr)
{
	int i=0;
	bar1(0,0,1023,767,0x87CEFA);
	
	Line_Thick(x,y,1024-x,y,2,0x000000);
	Line_Thick(x,y+yr,1024-x,y+yr,2,0x000000);
	Line_Thick(x,y+yr*8,1024-x,y+yr*8,2,0x000000);
	for (i=0;i<5;i++)
		Line_Thick(x+i*xr,y,x+i*xr,y+yr*8,2,0x000000);
	
//	bar1(15,10,120+48*2,90,0xFFFFFF);
	Line_Thick(15,50,60,10,2,0x000000);
	Line_Thick(60,10,60,30,2,0x000000);
	Line_Thick(60,30,115,30,2,0x000000);
	Line_Thick(15,50,60,90,2,0x000000);
	Line_Thick(60,90,60,70,2,0x000000);
	Line_Thick(60,70,115,70,2,0x000000);
	Line_Thick(115,30,115,70,2,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
//	bar1(10,680,100+5+16*3*3,720*2-680,0xFFFFFF);
//	bar1(1023-(100+5)-16*3*3,680,1023-10,720*2-680,0xFFFFFF);	
	
	prt_hz16_size(512-16*3*2,30,3,3,"历史记录",0x000000,"HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*1,y+6,3,3, "姓名", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*1+xr,y+6,3,3, "日期", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6,3,3, "审批状态", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*2+xr*3,y+6,3,3, "详细情况", 0x000000, "HZK\\HZK16s");
	
	
}

void PrintVisitors(VisitorList *VL,int judge,int* num) 
{
	int i=0;
    int x = 70, y = 130;  // 起始坐标
    int xr = (1024 - 2 * x) / 4, yr = 60;  // 每列的宽度和每行的高度


    // 打印访客信息
	if(judge==31)//游客登录
	{
		y += yr;  // 跳过表头
		for ( i = 0; i < VL->length; i++) 
		{
			Visitor *visitor = &VL->elem[i];
			if(visitor->user_stu==0&&visitor->dengji_user==*num)
			{
				
				// 姓名
				put_asc16_size(x + xr / 2 - 16 * 3 * 1, y, 2, 2, visitor->dengji_name, 0x000000);

				// 日期
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr-40, y, 2, 2, visitor->dengji_year, 0x0000000);
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 30, y, 2, 2,visitor->dengji_month, 0x000000);
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 60, y, 2, 2,visitor->dengji_date, 0x000000);
					
				//显示审批状态
				if(VL->elem[i].condition==-2)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "已取消", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==-1)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未审批", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==0)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未通过", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==1)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "已通过", 0x000000, "HZK\\HZK16s");

				// 详细情况
				prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 3, y, 2, 2, "点击查看", 0x000000, "HZK\\HZK16s");
				
				Line_Thick(x,y+40,1024-x,y+40,2,0x000000);

				y += yr;  // 下一行
			}
		}
	}
	else if(judge==32)//学生登录
	{
	    y += yr;  // 跳过表头
		for ( i = 0; i < VL->length; i++) 
		{
			Visitor *visitor = &VL->elem[i];
			if(visitor->user_stu==1&&visitor->dengji_user==*num)
			{
				
				// 姓名
				put_asc16_size(x + xr / 2 - 16 * 3 * 1, y, 2, 2, visitor->dengji_name, 0x000000);

				// 日期
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr-40, y, 2, 2, visitor->dengji_year, 0x0000000);
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 30, y, 2, 2,visitor->dengji_month, 0x000000);
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 60, y, 2, 2,visitor->dengji_date, 0x000000);
					
				//显示审批状态
				if(VL->elem[i].condition==-2)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "已取消", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==-1)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未审批", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==0)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未通过", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==1)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "已通过", 0x000000, "HZK\\HZK16s");

				// 详细情况
				prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 3, y, 2, 2, "点击查看", 0x000000, "HZK\\HZK16s");
				
				Line_Thick(x,y+40,1024-x,y+40,2,0x000000);

				y += yr;  // 下一行
			}
		}
	}
}

void detail_user(Visitor* visitor,int* func)
{
	DATE a[5];
	
	get_time(a);
    mouse_off(&mouse);
	draw_de_user(a);
	print_de_user(visitor);
	mouse_on(mouse);
	
	while(1)
	{
		mouse_show(&mouse);
		
		//查看同伴
		if(mouse_press(800,600,900,650)==1)
	    {
		   cp_de(visitor,func);
		   break;
	    }
		if (mouse_press(15,10,120+48*2,90)==1)
		{
			if(*func==31)
			    *func=31;
			else if(*func==32)
			     *func=32;
			break;
		}
	}
}

void draw_de_user(DATE *p)
{
     bar1(0, 0, 1023, 767, 0x87CEFA);  // 清空屏幕
	 
	 // 绘制表格
    Line_Thick(200,150,800,150, 2, 0x000000);
    Line_Thick(200,150,200,150+5+65*8, 2, 0x000000);
    Line_Thick(200,150+5+65*8,800,150+5+65*8,2, 0x000000);
	Line_Thick(800,150,800,150+5+65*8,2,0x000000);

    prt_hz16_size(120, 50 - 16 * 3 / 2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
	prt_hz16_size(400,70, 3, 3, "详细信息", 0x000000, "HZK\\HZK16s");
	
	prt_hz16_size(200+5,150+5,2,2, "姓名", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65,2,2, "身份证号", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65*2,2,2, "进校方式", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65*3,2,2, "访问校区", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65*4,2,2, "来访电话", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65*5,2,2, "来访时间", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65*6,2,2, "来访缘由", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200+5,150+5+65*7,2,2, "来访车牌号", 0x000000, "HZK\\HZK16s");
	
	//绘制时间
	prt_hz16_size(760,70,2,2,"今天是",0x000000,"HZK\\HZK16s");
	put_asc16_size( 760+16*2*3+10,70,2,2,p[0].year,0xFFFFFF);
	put_asc16_size( 760+16*2*3+10+80,70,2,2,p[0].month,0xFFFFFF);
	put_asc16_size( 760+16*2*3+10+110,70,2,2,p[0].day,0xFFFFFF);
	bar2(750,70,750+16*2*3+110+60,150,0x00FF);
	
	//绘制同伴信息按钮
	bar1(800,600,900,650,0x00ff);
	prt_hz16_size(800+10,600+10,1,1, "同伴信息", 0x000000, "HZK\\HZK16s");
}

void print_de_user(Visitor *visitor)
{
	put_asc16_size(400,150+5,2,2, visitor->dengji_name, 0x000000);
	put_asc16_size(400,150+5+65,2,2, visitor->dengji_id, 0x000000);
	
	if(visitor->state_way==1)
	    prt_hz16_size(400,150+5+65*2,2,2,"驾车", 0x000000, "HZK\\HZK16s");
	else if(visitor->state_way==2)
		prt_hz16_size(400,150+5+65*2,2,2,"步行", 0x000000, "HZK\\HZK16s");
	
	if(visitor->state_xiaoqu==1)
		prt_hz16_size(400,150+5+65*3,2,2,"同济校区", 0x000000, "HZK\\HZK16s");
	else if(visitor->state_xiaoqu==2)
		prt_hz16_size(400,150+5+65*3,2,2,"主校区", 0x000000, "HZK\\HZK16s");
	
	put_asc16_size(400,150+5+65*4,2,2, visitor->tele, 0x000000);
	
	put_asc16_size(400,150+5+65*5,2,2, visitor->dengji_year, 0x000000);
	put_asc16_size(400+100,150+5+65*5,2,2, visitor->dengji_month, 0x000000);
	put_asc16_size(400+150,150+5+65*5,2,2, visitor->dengji_date, 0x000000);
	
	if(visitor->reason==1)
	    prt_hz16_size(400,150+5+65*6,2,2,"参观校园", 0x000000,"HZK\\HZK16s");
	else if(visitor->reason==2)
	    prt_hz16_size(400,150+5+65*6,2,2,"探亲", 0x000000,"HZK\\HZK16s");
	else if(visitor->reason==3)
	    prt_hz16_size(400,150+5+65*6,2,2,"其他", 0x000000,"HZK\\HZK16s");
	
	if(strcmp(visitor->car_number,"\0")==0)
		prt_hz16_size(400,150+5+65*7,2,2,"无", 0x000000,"HZK\\HZK16s");
	else
		put_asc16_size(400,150+5+65*7,2,2, visitor->car_number, 0x000000);
}

void cp_de(Visitor* visitor,int* func)
{
    int f[10]={0};
	
	mouse_off(&mouse);
	draw_cp_de(visitor);
	mouse_on(mouse);
	
	while (1)
	{
		mouse_show(&mouse);
		
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				detail_user(visitor,func);
				break;
			}
			else if(f[0]==0)
			{
				Light_manager_func(0);
				f[0]=1;
				continue;
			}
		} 
		else 
		{
			if (f[0]==1)
			{
				Dark_manager_func(0);
				f[0]=0;
			}
		}
	}
}

void draw_cp_de(Visitor* visitor)
{
    int i=0;
	int x=70,y=130;//x，y都表示主框的左上角坐标
	int xr=(1024-2*x)/4,yr=60;		//xr为框的间隔
	
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	
	for(i=0;i<4;i++)
	    Line_Thick(x,y+i*yr,x+xr*2,y+i*yr,2,0x000000);
	for (i=0;i<3;i++)
		Line_Thick(x+i*xr,y,x+i*xr,y+yr*3,2,0x000000);

//	bar1(15,10,120+48*2,90,0xFFFFFF);
	Line_Thick(15,50,60,10,2,0x000000);
	Line_Thick(60,10,60,30,2,0x000000);
	Line_Thick(60,30,115,30,2,0x000000);
	Line_Thick(15,50,60,90,2,0x000000);
	Line_Thick(60,90,60,70,2,0x000000);
	Line_Thick(60,70,115,70,2,0x000000);
	Line_Thick(115,30,115,70,2,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
	prt_hz16_size( 600,y+yr*2,3,3, "同伴信息", 0x000000, "HZK\\HZK16s");
	
	prt_hz16_size( x+xr/2-16*3*1,y+6,3,3, "姓名", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*1+xr-40,y+6,3,3, "身份证号", 0x000000, "HZK\\HZK16s");
	if(strcmp(visitor->cpname[0],"\0")==0)
	    prt_hz16_size( x+xr/2-16*3*1+10,y+6+yr,3,3, "无", 0x000000, "HZK\\HZK16s");
	else
		put_asc16_size( x+xr/2-16*3*1+10,y+6+yr,3,3, visitor->cpname[0], 0x000000);
	if(strcmp(visitor->cpid[0],"\0")==0)
		prt_hz16_size( x+xr/2-16*3*1+10+xr,y+6+yr,3,3, "无", 0x000000, "HZK\\HZK16s");
	else
		put_asc16_size( x+xr/2-16*3*1+10+xr,y+6+yr,3,3, visitor->cpid[0], 0x000000);
	if(strcmp(visitor->cpname[1],"\0")==0)
		prt_hz16_size( x+xr/2-16*3*1+10,y+6+yr*2,3,3, "无", 0x000000, "HZK\\HZK16s");
	else
		put_asc16_size( x+xr/2-16*3*1+10,y+6+yr*2,3,3, visitor->cpname[1], 0x000000);
	if(strcmp(visitor->cpid[1],"\0")==0)
		prt_hz16_size( x+xr/2-16*3*1+10+xr,y+6+yr*2,3,3, "无", 0x000000, "HZK\\HZK16s");
	else
		put_asc16_size( x+xr/2-16*3*1+10+xr,y+6+yr*2,3,3, visitor->cpid[1], 0x000000);
}