#include"allfunc.h"
#include"ufunc.h"
#include"can_de.h"
#include"m_func.h"

void can_dengji(int *func,int unum,int* num)
{
	VisitorList VL;
	DATE a[5];
	int f[10]={0};
	int count[10]={0};
	int x=70,y=130;
	int xr=(1024-2*x)/4,yr=60;
    int i=0,j=0,y_pos;	
	
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	get_time(a);//读取信息
	
	mouse_off(&mouse);
	draw_can_user(x,y,xr,yr);
	PrintV_can(&VL,*func,num);
	mouse_on(mouse);
	
	for(i=0;i<VL.length;i++)
	{
	    if(VL.elem[i].condition!=-2&&VL.elem[i].dengji_user==*num)
		    count[j++]=i;
	}
	
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
		}else 
			{
				if (f[0]==1)
				{
					Dark_manager_func(0);
					f[0]=0;
				}
			}
		
		for (i = 0; i < VL.length; i++) 
		{
            y_pos = y +( i + 1 ) * yr;
            if (mouse_press(x +  xr *3 , y_pos, x + xr * 4, y_pos + yr) == 1) 
			{
                cancel(&VL,count[i],a,num);  // 调用取消函数
				mouse_off(&mouse);
				draw_can_user(x,y,xr,yr);
				PrintV_can(&VL,*func,num);
				mouse_on(mouse);
				break;
            }
        }
	}
	DestroyVisitorList(&VL);
}

void draw_can_user(int x, int y, int xr, int yr) 
{
    int i=0;
    bar1(0, 0, 1023, 767, 0x87CEFA);  // 清空屏幕
	JianTou(15,50,60,10,115,30,0x000000);

    // 绘制表格
    Line_Thick(x, y, 1024 - x, y, 2, 0x000000);
    Line_Thick(x, y + yr, 1024 - x, y + yr, 2, 0x000000);
    Line_Thick(x, y + yr * 8, 1024 - x, y + yr * 8, 2, 0x000000);
    for (i = 0; i < 5; i++) 
	{
        Line_Thick(x + i * xr, y, x + i * xr, y + yr * 8, 2, 0x000000);
    }

    // 绘制表头
    prt_hz16_size(120, 50 - 16 * 3 / 2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(512 - 16 * 3 * 2, 30, 3, 3, "请选择取消", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(x + xr / 2 - 16 * 3 * 1, y + 6, 3, 3, "姓名", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr, y + 6, 3, 3, "日期", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(x + xr / 2 - 16 * 3 * 2 + xr * 2, y + 6, 3, 3, "审批状态", 0x000000, "HZK\\HZK16s");
    prt_hz16_size(x + xr / 2 - 16 * 3 * 2 + xr * 3, y + 6, 3, 3, "取消", 0x000000, "HZK\\HZK16s");
}

void PrintV_can(VisitorList *VL,int judge,int* num) 
{
    int x = 70, y = 130;  // 起始坐标
    int xr = (1024 - 2 * x) / 4, yr = 60;  // 每列的宽度和每行的高度
	int i=0;

    // 打印访客信息
	if(judge==31)//用户登录
	{
		y += yr;  // 跳过表头
		for (i = 0; i < VL->length; i++) 
		{
				Visitor *visitor = &VL->elem[i];
				if(visitor->condition!=-2&&visitor->user_stu==0&&visitor->dengji_user==*num/*&&visitor->jin_xiao==0&&atoi(visitor->dengji_date)>=25*/)//未取消且为游客信息则打印
				{

				// 姓名
				put_asc16_size(x + xr / 2 - 16 * 3 * 1, y, 2, 2, visitor->dengji_name, 0x000000);

				// 日期
				// 年
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr-50, y, 2, 2, visitor->dengji_year, 0x000000);
				// 月
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 30, y, 2, 2, visitor->dengji_month, 0x000000);
				// 日
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 60, y, 2, 2, visitor->dengji_date, 0x000000);

				//显示审批状态
				if(VL->elem[i].condition==-1)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未审批", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==0)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未通过", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==1)
					prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "已通过", 0x000000, "HZK\\HZK16s");
				// 取消按钮
				prt_hz16_size(x + xr / 2 - 16 * 3 * 2 + xr * 3, y, 2, 2, "取消", 0x000000,"HZK\\HZK16s");

				Line_Thick(x,y+40,1024-x,y+40,2,0x000000);

					y += yr;  // 下一行
			}
		}
	}
	//学生取消信息打印
	else if(judge==32)//学生登录
	{
	    y += yr;  // 跳过表头
		for (i = 0; i < VL->length; i++) 
		{
				Visitor *visitor = &VL->elem[i];
				if(visitor->condition!=-2&&visitor->user_stu==1&&visitor->dengji_user==*num)//如果未取消且为学生信息则打印
				{

				// 姓名
				put_asc16_size(x + xr / 2 - 16 * 3 * 1, y, 2, 2, visitor->dengji_name, 0x000000);

				// 日期
				// 年
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr-50, y, 2, 2, visitor->dengji_year, 0x000000);
				// 月
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 30, y, 2, 2, visitor->dengji_month, 0x000000);
				// 日
				put_asc16_size(x + xr / 2 - 16 * 3 * 1 + xr + 60, y, 2, 2, visitor->dengji_date, 0x000000);

				//显示审批状态
				if(VL->elem[i].condition==-1)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未审批", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==0)
				   prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "未通过", 0x000000, "HZK\\HZK16s");
				else if(VL->elem[i].condition==1)
					prt_hz16_size(x + xr / 2 - 16 * 3 * 1 + xr * 2, y, 2, 2, "已通过", 0x000000, "HZK\\HZK16s");
				// 取消按钮
				prt_hz16_size(x + xr / 2 - 16 * 3 * 2 + xr * 3, y, 2, 2, "取消", 0x000000,"HZK\\HZK16s");

				Line_Thick(x,y+40,1024-x,y+40,2,0x000000);

				y += yr;  // 下一行
			}
		}
	}
}

void cancel(VisitorList *VL,int n,DATE* a,int* num)
{
    VL->elem[n].condition=-2;//记录取消状态
	
	//记录取消时间
	strcpy(VL->elem[n].cancel_year,a[0].year);
	strcpy(VL->elem[n].cancel_month,a[0].month);
	strcpy(VL->elem[n].cancel_day,a[0].day);
	
	SaveAllVisitors(VL);
}