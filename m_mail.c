#include "allfunc.h"
#include "m_mail.h"

void m_mail(int *func)
{
	int f[10]={0};
	mouse_off(&mouse);
	draw_m_mail();
    mouse_on(mouse);
	while (1)
	{
		mouse_show(&mouse);
		//移至返回
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				*func=33;
				break;
			}else if(f[0]==0)
				{
					Light_m_mail(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				mouse_off(&mouse);
				Dark_m_mail(0);
				f[0]=0;
			}
		}
		//移至预约取消
		if(mouse.x>250&&mouse.x<1024-250&&mouse.y>250&&mouse.y<250+150)
		{
			if (mouse_press(250,250,1024-250,250+150)==1)
			{
				mail_can();
			}else if(f[1]==0)
				{
					Light_m_mail(1);
					f[1]=1;
					continue;
				}
		} else 
		{
			if (f[1]==1)
			{
				Dark_m_mail(1);
				f[1]=0;
			}
		}
		//移至进校通知
		if(mouse.x>250&&mouse.x<1024-250&&mouse.y>250+150+50&&mouse.y<250+150*2+50)
		{
			if (mouse_press(250,250+150+50,1024-250,250+150*2+50)==1)
			{
				mail_not();
			}else if(f[2]==0)
				{
					Light_m_mail(2);
					f[2]=1;
					continue;
				}
		} else 
		{
			if (f[2]==1)
			{
				Dark_m_mail(2);
				f[2]=0;
			}
		}
	}
}

void draw_m_mail(void )
{
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
	prt_hz16_size(512-16*5*4/2,60,5,5,"今日邮件",0x000000,"HZK\\HZK16s");
	
	Cirbar(250,250,1024-250,250+150,0x00FF);
	prt_hz16_size(512-16*4*4/2,250+75-16*4/2,4,4,"预约取消",0xFFFFFF,"HZK\\HZK16s");
	Cirbar(250,250+150+50,1024-250,250+150*2+50,0x00FF);
	prt_hz16_size(512-16*4*4/2,250+150+50+75-16*4/2,4,4,"进校通知",0xFFFFFF,"HZK\\HZK16s");
}

void Dark_m_mail(int tag )
{
	mouse_off(&mouse);
	switch (tag)
	{
		case 0:
		{
			bar1(15+1,10+1,120+48*2-1,90-1,0x87CEFA);
			JianTou(15,50,60,10,115,30,0x000000);
			prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
			break;
		}
		case 1:
		{
			Cirbar(250,250,1024-250,250+150,0x00FF);
			prt_hz16_size(512-16*4*4/2,250+75-16*4/2,4,4,"预约取消",0xFFFFFF,"HZK\\HZK16s");
			break;
		}
		case 2:
		{
			Cirbar(250,250+150+50,1024-250,250+150*2+50,0x00FF);
			prt_hz16_size(512-16*4*4/2,250+150+50+75-16*4/2,4,4,"进校通知",0xFFFFFF,"HZK\\HZK16s");
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void Light_m_mail(int tag)
{
	mouse_off(&mouse);
	switch(tag)
	{
		case 0:
		{
			bar1(15+1,10+1,120+48*2-1,90-1,0xB3B5B6);
			JianTou(15,50,60,10,115,30,0xDC2DF1);
			prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		case 1:
		{
			Cirbar(250,250,1024-250,250+150,0xB3B5B6);
			prt_hz16_size(512-16*4*4/2,250+75-16*4/2,4,4,"预约取消",0xDC2DF1,"HZK\\HZK16s");
			break;
		}
		case 2:
		{
			Cirbar(250,250+150+50,1024-250,250+150*2+50,0xB3B5B6);
			prt_hz16_size(512-16*4*4/2,250+150+50+75-16*4/2,4,4,"进校通知",0xDC2DF1,"HZK\\HZK16s");
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void mail_can()				//用户取消预约
{
	int t=0;
	int f[10];
	DATE a[5];
	int x=100,y=100;
	int yr=40;
	int i=0,j=0;
	VisitorList VL;
	Visitor *p;
	
	get_time(a);
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	mouse_off(&mouse);
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
	for (i=0;i<VL.length;i++)
	{
		p = &VL.elem[i];
		if (p->condition==-2&&atoi(p->cancel_day)-atoi(a[0].day)==0)
		{
			put_asc16_size( x,y+yr*t,2,2, p->dengji_name, 0x000000);
			prt_hz16_size(x+5*50,y+yr*t,2,2,"用户取消了",0x000000,"HZK\\HZK16s");
			put_asc16_size(x+5*50+48*5+30,y+yr*t,2,2,p->dengji_date,0x000000 );
			prt_hz16_size(x+5*50+48*7+30,y+yr*t,2,2,"日的预约",0x000000,"HZK\\HZK16s");
			Line_Thick(x,y+yr*t+32,1024-x,y+yr*t+32,2,0x000000);
			t++;
		}
	}
	mouse_on(mouse);
	
	while (1)
	{
		mouse_show(&mouse);
		//移至返回
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				break;
			}else if(f[0]==0)
				{
					Light_m_mail(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				mouse_off(&mouse);
				Dark_m_mail(0);
				f[0]=0;
			}
		}
	}
	
	DestroyVisitorList(&VL);
}

void mail_not()			//用户已经进校
{
	int hour,min;
	int f[10];
	DATE a[5];
	VisitorList VL;
	Visitor *p;
	int x=100,y=100;
	int yr=40;
	int i=0,j=0,k=0;
	int n=0;			//n表示总数
	int g,h;
	int t[100];			//按顺序记录下今日进校的用户
	int u[100];			//算出60*hour+min
	
	get_time(a);
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	mouse_off(&mouse);
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	//选出符合要求的用户并计算u
	for (i=0;i<VL.length;i++)
	{
		p = &VL.elem[i];
		hour=atoi(p->jin_hour);
		min=atoi(p->jin_min);
		if (strcmp(p->jin_day,a[0].day)==0&&p->jin_xiao==1)
		{
			u[k]=60*hour+min;
			t[k++]=i;
			n++;
		}
	}
	
	//给用户按时间进行排序，由大到小
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (u[i]<u[j])
			{
				k=u[i];
				u[i]=u[j];
				u[j]=k;
				
				k=t[i];
				t[i]=t[j];
				t[j]=k;
			}
		}
	}
	
	//打印邮件
	for (i=0,j=0;i<n;i++)
	{
		p = &VL.elem[t[j++]];			//按顺序找出用户
		put_asc16_size( x,y+yr*i,2,2, p->dengji_name, 0x000000);
		prt_hz16_size(x+5*50,y+yr*i,2,2,"用户于今日",0x000000,"HZK\\HZK16s");
		put_asc16_size(x+5*50+48*5+30,y+yr*i,2,2,p->jin_hour,0x000000 );
		put_asc16_size(x+5*50+48*5+30+100,y+yr*i,2,2,p->jin_min,0x000000 );
		prt_hz16_size(x+5*50+48*5+30+100+100,y+yr*i,2,2,"进校",0x000000,"HZK\\HZK16s");
		Line_Thick(x,y+yr*i+32,1024-x,y+yr*i+32,2,0x000000);
	}
	mouse_on(mouse);
	
	while (1)
	{
		mouse_show(&mouse);
		//移至返回
		if(mouse.x>15&&mouse.x<120+48*2&&mouse.y>10&&mouse.y<90)
		{
			if (mouse_press(15,10,120+48*2,90)==1)
			{
				break;
			}else if(f[0]==0)
				{
					Light_m_mail(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				mouse_off(&mouse);
				Dark_m_mail(0);
				f[0]=0;
			}
		}
	}
	DestroyVisitorList(&VL);
}