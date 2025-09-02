#include"allfunc.h"
#include"m_func.h"

void history (int *func)
{
	int i=0;
	int j=0;
	int n=0;
	int t=0;
	int a[100]={0};			//a的值用来记录VL.elem对应的i（condition不为-1），从a【0】开始
	int page=1;
	int page_max=0;
	Visitor *p;
	int f[10]={0};
	int x=70,y=130;//x，y都表示主框的左上角坐标
	int xr=(1024-2*x)/4,yr=60;		//xr为框的间隔
	VisitorList VL;
	
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//给已审批的visitor按时间顺序编号，编号从0开始，并统计总数n
	for (j = 0; j <VL.length; j++)
	{
		p = &VL.elem[j];
		if (p->condition==0||p->condition==1||p->condition==-2)
		{
			n++;
			a[i++]=j;
		}
	}
	//计算page的总数page_max
	if (n%8==0)
	{
		page_max=n/8;
	}else{
		page_max=n/8+1;
	}
	
	mouse_off(&mouse);
	draw_history(x,y,xr,yr);
	i=0,j=0;
	
	for (i=0;i<VL.length;i++)				//j判定第一页的visitor数量
	{
		p = &VL.elem[i];
		if (i==a[j])
		{
			draw_info(x,y,xr,yr,p,j);
			j++;
		}
		if (j==8)
			break;
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
				*func=33;
				break;
			}else if(f[0]==0)
				{
					Light_manager_func(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				Dark_manager_func(0);
				f[0]=0;
			}
		}
		//移至上一页
		if(mouse.x>10&&mouse.x<100+5+16*3*3&&mouse.y>680&&mouse.y<720*2-680)
		{
			if (mouse_press(10,680,100+5+16*3*3,720*2-680)==1)
			{
				page--;
				if (page==0)
				{
					page=1;
				}else{
					draw_history(x,y,xr,yr);
					for (i=0,j=0;i<8;i++)
					{
						t=a[page*8-8+i];
						p=&VL.elem[t];
						draw_info(x,y,xr,yr,p,j++);
					}
					mouse_on(mouse);
					mouse_show(&mouse);
				}
			}else if(f[1]==0)
				{
					Light_manager_func(1);
					f[1]=1;
					continue;
				}
		}else
		{
			if (f[1]==1)
			{
				Dark_manager_func(1);
				f[1]=0;
			}
		}
			
		//移至下一页
		if(mouse.x>1023-(100+5)-16*3*3&&mouse.x<1023-10&&mouse.y>680&&mouse.y<720*2-680)
		{
			if (mouse_press(1023-(100+5)-16*3*3,680,1023-10,720*2-680)==1)
			{
				page++;
				if (page==page_max+1)
				{
					page=page_max;
				}else{
					draw_history(x,y,xr,yr);
					if (page!=page_max)
					{
						for (i=0,j=0;i<8;i++)
						{
							t=a[page*8-8+i];
							p=&VL.elem[t];
							draw_info(x,y,xr,yr,p,j++);
						}
					}
					if (page==page_max)
					{
						for (i=0,j=0;i<n%8;i++)
						{
							t=a[page*8-8+i];
							p=&VL.elem[t];
							draw_info(x,y,xr,yr,p,j++);
						}
					}
					mouse_on(mouse);
					mouse_show(&mouse);
				}
			}else if(f[2]==0)
				{
					Light_manager_func(2);
					f[2]=1;
					continue;
				}
		}else
		{
			if (f[2]==1)
			{
				Dark_manager_func(2);
				f[2]=0;
			}
		}
		
		//移至详情
		if (page!=page_max)			//非最后一页
		{
			if (mouse_press(x+xr*3,y+yr,x+xr*4,y+yr*2)==1)
			{
				t=a[page*8-8];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*2,x+xr*4,y+yr*3)==1)
			{
				t=a[page*8-8+1];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*3,x+xr*4,y+yr*4)==1)
			{
				t=a[page*8-8+2];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*4,x+xr*4,y+yr*5)==1)
			{
				t=a[page*8-8+3];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*5,x+xr*4,y+yr*6)==1)
			{
				t=a[page*8-8+4];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*6,x+xr*4,y+yr*7)==1)
			{
				t=a[page*8-8+5];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*7,x+xr*4,y+yr*8)==1)
			{
				t=a[page*8-8+6];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*8,x+xr*4,y+yr*9)==1)
			{
				t=a[page*8-8+7];
				p=&VL.elem[t];
				detail_user(p,4);
			}
		}
		if (page==page_max)						//是最后一页
		{
			if (mouse_press(x+xr*3,y+yr,x+xr*4,y+yr*2)==1&&n%8>0)
			{
				t=a[page*8-8];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*2,x+xr*4,y+yr*3)==1&&n%8>1)
			{
				t=a[page*8-8+1];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*3,x+xr*4,y+yr*4)==1&&n%8>2)
			{
				t=a[page*8-8+2];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*4,x+xr*4,y+yr*5)==1&&n%8>3)
			{
				t=a[page*8-8+3];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*5,x+xr*4,y+yr*6)==1&&n%8>4)
			{
				t=a[page*8-8+4];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*6,x+xr*4,y+yr*7)==1&&n%8>5)
			{
				t=a[page*8-8+5];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*7,x+xr*4,y+yr*8)==1&&n%8>6)
			{
				t=a[page*8-8+6];
				p=&VL.elem[t];
				detail_user(p,4);
			}
			if (mouse_press(x+xr*3,y+yr*8,x+xr*4,y+yr*9)==1&&n%8>7)
			{
				t=a[page*8-8+7];
				p=&VL.elem[t];
				detail_user(p,4);
			}
		}			
		
	}
	DestroyVisitorList(&VL);
}

void audit(int *func)
{
	FILE *fp=NULL;
	int i=0;
	int j=0;				//i，j可作为循环变量
	int page=1;				//page为界面的编号
	int page_max;			//page的最大值
	int t=0;				
	int k=0;				//k的终值可以判断n的奇偶
	int n=0;				//n为目前需要处理的总数
	int f[10]={0};			//f为点亮的判断
	int a[20]={0};			//a储存本轮visitor的编号，从a[0]开始
	Visitor *p;
	
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	mouse_off(&mouse);
	draw_audit();
	
	if((fp=fopen("visitorinfo.dat","rb+"))==NULL)
	{
		prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	//给visitor按时间顺序编号，编号从0开始，并统计总数n
	for (j = 0; j < VL.length; j++)
	{
		p = &VL.elem[j];
		if (p->condition==-1)
		{
			n++;
			a[t++]=j;
		}
	}
	k=n%2;
	
/*	p = &VL.elem[0];
	draw_bg(p,0);
	p = &VL.elem[1];
	draw_bg(p,1);*/
	//打印第一个界面
	
	if (k==0)				//计算page_max的最大值
	{
		page_max=n/2;
	}else
	{
		page_max=(n+1)/2;
	}
	
	if (page_max>0)				//打印第一个界面
	{
		t=a[0];
		p = &VL.elem[t];
		draw_bg(p,0);
		if (n>1)
		{
			t=a[1];
			p = &VL.elem[t];
			draw_bg(p,1);
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
				SaveAllVisitors(&VL);
				*func=33;
				break;
			}else if(f[0]==0)
				{
					Light_manager_func(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				Dark_manager_func(0);
				f[0]=0;
			}
		}
		//移至上一页
		if(mouse.x>10&&mouse.x<100+5+16*3*3&&mouse.y>680&&mouse.y<720*2-680)
		{
			if (mouse_press(10,680,100+5+16*3*3,720*2-680)==1)
			{
				page--;
				if (page==0)
				{
					page=1;
				}else{
					bar1(0,92,1023,678,0x87CEFA);
					t=a[page*2-2];
					p=&VL.elem[t];
					draw_bg(p,0);
					if(p->condition==0)
						draw_tg(1);
					if (p->condition==1)
						draw_tg(2);
					
					t=a[page*2-1];
					p=&VL.elem[t];
					draw_bg(p,1);
					mouse_on(mouse);
					mouse_show(&mouse);
					if(p->condition==0)
						draw_tg(3);
					if (p->condition==1)
						draw_tg(4);
				}
			}else if(f[1]==0)
				{
					Light_manager_func(1);
					f[1]=1;
					continue;
				}
		}else
		{
			if (f[1]==1)
			{
				Dark_manager_func(1);
				f[1]=0;
			}
		}
			
		//移至下一页
		if(mouse.x>1023-(100+5)-16*3*3&&mouse.x<1023-10&&mouse.y>680&&mouse.y<720*2-680)
		{
			if (mouse_press(1023-(100+5)-16*3*3,680,1023-10,720*2-680)==1)
			{
				page++;
				if (page==page_max+1)
				{
					page=page_max;
				}else{
					bar1(0,92,1023,678,0x87CEFA);
					
					t=a[page*2-2];
					p=&VL.elem[t];
					draw_bg(p,0);
					if(p->condition==0)
						draw_tg(1);
					if (p->condition==1)
						draw_tg(2);
					if (page!=page_max||(page_max==page&&k==0))		//不是最后一页或者是最后一页但是总人数为偶数
					{
						t=a[page*2-1];
						p=&VL.elem[t];
						draw_bg(p,1);
						if(p->condition==0)
							draw_tg(3);
						if (p->condition==1)
							draw_tg(4);
					}
					mouse_on(mouse);
					mouse_show(&mouse);
				}
			}else if(f[2]==0)
				{
					Light_manager_func(2);
					f[2]=1;
					continue;
				}
		}else
		{
			if (f[2]==1)
			{
				Dark_manager_func(2);
				f[2]=0;
			}
		}
		
		
		
		if(k==1&&page==page_max)			//预约人数n为奇数且为最后一页单独考虑
		{
			t=a[page*2-2];
			p=&VL.elem[t];
			
			if (mouse_press(50+10,100+60*8+10,200,100+60*8+70)==1)		//点击不通过
			{
				p->condition=0;
				mouse_off(&mouse);
				draw_tg(1);
				mouse_on(mouse);
				mouse_show(&mouse);
			
			}
			
			if (mouse_press(512-200,100+60*8+10,512-50-10,100+60*8+70)==1)	//点击通过
			{
				p->condition=1;
				mouse_off(&mouse);
				draw_tg(2);
				mouse_on(mouse);
				mouse_show(&mouse);
				
			
			}
		}else{															//其他情况
		
			if (mouse_press(50+10,100+60*8+10,200,100+60*8+70)==1)		//点击左边不通过
			{
				t=a[page*2-2];
				p=&VL.elem[t];
				p->condition=0;
				mouse_off(&mouse);
				draw_tg(1);
				mouse_on(mouse);
				mouse_show(&mouse);
				
				
			}
			if (mouse_press(512-200,100+60*8+10,512-50-10,100+60*8+70)==1)	//点击左边通过
			{
				t=a[page*2-2];
				p=&VL.elem[t];
				p->condition=1;
				mouse_off(&mouse);
				draw_tg(2);
				mouse_on(mouse);
				mouse_show(&mouse);
				
				
			}
			if (mouse_press(50+512+10,100+60*8+10,512+200,100+60*8+70)==1)		//点击右边不通过
			{
				t=a[page*2-1];
				p=&VL.elem[t];
				p->condition=0;
				mouse_off(&mouse);
				draw_tg(3);
				mouse_on(mouse);
				mouse_show(&mouse);
				
				
				
			}
			if (mouse_press(1024-200,100+60*8+10,1024+512-50-512-10,100+60*8+70)==1)	//点击右边通过
			{
				t=a[page*2-1];
				p=&VL.elem[t];
				p->condition=1;
				mouse_off(&mouse);
				draw_tg(4);
				mouse_on(mouse);
				mouse_show(&mouse);
				
				
			}
			//UpdataVisitor(*p);
		}
		
	}
	DestroyVisitorList(&VL);
	fclose(fp);
}

void analyse(int *func)
{
	int n=0;
	int f[10]={0};
	mouse_off(&mouse);
	draw_analyse(n);
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
					Light_manager_func(0);
					f[0]=1;
					continue;
				}
		} else 
		{
			if (f[0]==1)
			{
				Dark_manager_func(0);
				f[0]=0;
			}
		}	
		if (mouse_press(50,390,50+100,440)==1)			//点击当日
		{
			n=0;
			mouse_off(&mouse);
			draw_analyse(n);
			mouse_on(mouse);
			mouse_show(&mouse);
		}
		if (mouse_press(50+100,390,50+200,440)==1)		//点击近三天
		{
			n=2;
			mouse_off(&mouse);
			draw_analyse(n);
			mouse_on(mouse);
			mouse_show(&mouse);
		}
		if (mouse_press(50+200,390,50+300,440)==1)		//点击近七天
		{
			n=6;
			mouse_off(&mouse);
			draw_analyse(n);
			mouse_on(mouse);
			mouse_show(&mouse);
		}
	}
}

void draw_history(int x,int y, int xr,int yr)
{
	int i=0;
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	
	Line_Thick(x,y,1024-x,y,2,0x000000);
	Line_Thick(x,y+yr,1024-x,y+yr,2,0x000000);
	Line_Thick(x,y+yr*9,1024-x,y+yr*9,2,0x000000);
	for (i=0;i<5;i++)
		Line_Thick(x+i*xr,y,x+i*xr,y+yr*9,2,0x000000);
	
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
//	bar1(1023-(100+5)-16*3*3,680,1023-10,720*2-680,0xFFFFFF);	//两个框的坐标
	JianTou(10,720,55,680,100,700,0x000000);
	prt_hz16_size(100+5,720-16*3/2,3,3,"上一页",0x000000,"HZK\\HZK16s");
	JianTou(1023-10,720,1023-55,680,1023-100,700,0x000000);
	prt_hz16_size(1023-(100+5)-16*3*3,720-16*3/2,3,3,"下一页",0x000000,"HZK\\HZK16s");
	
	prt_hz16_size(512-16*3*2,30,3,3,"历史记录",0x000000,"HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*1,y+6,3,3, "姓名", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*1+xr,y+6,3,3, "日期", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6,3,3, "审批状态", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*2+xr*3,y+6,3,3, "详细情况", 0x000000, "HZK\\HZK16s");
	
//	prt_hz16_size(80-48*3/2,720-24,3,3, "上一页", 0x000000, "HZK\\HZK16s");
//	prt_hz16_size(1023-80-48*3/2,720-24,3,3, "下一页", 0x000000, "HZK\\HZK16s");
//	prt_hz16_size(512-32*4,710,2,2, "第页共页", 0x000000, "HZK\\HZK16s");
}

void draw_info(int x,int y, int xr,int yr,Visitor *p,int flag)
{
	y+=yr;
	put_asc16_size( x+xr/2-16*5*1,y+6+yr*flag,3,3, p->dengji_name, 0x000000);
	put_asc16_size( x+xr/2-16*3*1+xr,y+6+yr*flag,3,3, p->dengji_month, 0x000000);
	put_asc16_size( x+xr/2+xr,y+6+yr*flag,3,3, p->dengji_date, 0x000000);
	if (p->condition==0)
	{
		prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6+yr*flag,3,3, "不通过", 0x000000, "HZK\\HZK16s");
	}
	if (p->condition==1)
	{
		prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6+yr*flag,3,3, "通过", 0x000000, "HZK\\HZK16s");
	}
	if (p->condition==-2)
	{
		prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6+yr*flag,3,3, "用户取消", 0x000000, "HZK\\HZK16s");
	}
	if(p->condition==-1)
	{
		prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6+yr*flag,3,3, "未审批", 0x000000, "HZK\\HZK16s");
	}
	//prt_hz16_size( x+xr/2-16*3*2+xr*2,y+6,3,3, "审批状态", 0x000000, "HZK\\HZK16s");
	prt_hz16_size( x+xr/2-16*3*2+xr*3,y+6+yr*flag,3,3, "点击查看", 0x000000, "HZK\\HZK16s");
	Line_Thick(x,y+yr*(flag+1),1024-x,y+yr*(flag+1),2,0x000000);
}

void draw_audit(void)		//审批
{
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	
	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	
	JianTou(10,720,55,680,100,700,0x000000);
	prt_hz16_size(100+5,720-16*3/2,3,3,"上一页",0x000000,"HZK\\HZK16s");
	JianTou(1023-10,720,1023-55,680,1023-100,700,0x000000);
	prt_hz16_size(1023-(100+5)-16*3*3,720-16*3/2,3,3,"下一页",0x000000,"HZK\\HZK16s");
	
	
}
void draw_analyse(int n)		//数据分析
{
	DATE a[5];
	int i,j;
	int x=50,y=120;
	int xr=150,yr=60;
	bar1(0,0,1023,767,0x87CEFA);//背景色;
	JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(512-16*3*2,30,3,3,"数据分析",0x000000,"HZK\\HZK16s");
	
	get_time(a);
	draw_jintime( n,a);
	draw_reason(n,a);
	//打印到校率的表格
	for (i=0;i<7;i++)
	{
		
		Line_Thick(x+xr*i,y,x+xr*i,y+yr*4,2,0x000000);
		
		if (i==0)
		{
			prt_hz16_size(x+xr+5,y+yr*i+14,2,2,"预约人次",0x000000,"HZK\\HZK16s");
			prt_hz16_size(x+xr*2+5,y+yr*i+14,2,2,"到校人次",0x000000,"HZK\\HZK16s");
			prt_hz16_size(x+xr*3+5,y+yr*i+14,2,2,"到校率",0x000000,"HZK\\HZK16s");
			prt_hz16_size(x+xr*4+5,y+yr*i+14,2,2,"车辆数",0x000000,"HZK\\HZK16s");
			prt_hz16_size(x+xr*5+5,y+yr*i+14,2,2,"开车比例",0x000000,"HZK\\HZK16s");
		}
		if(i==1)
		{
			prt_hz16_size(x+10,y+yr*i+6,3,3,"今日",0x000000,"HZK\\HZK16s");
			put_asc16_number_size(x+10+xr,y+yr*i+6,3,3,reserve_num(0,a),0x000000);
			put_asc16_number_size(x+10+xr*2,y+yr*i+6,3,3,arrive_num(0,a),0x000000);
			if(reserve_num(0,a)!=0)
				put_asc16_number_size(x+10+xr*3,y+yr*i+6,3,3,100*arrive_num(0,a)/reserve_num(0,a),0x000000);
			else
				put_asc16_number_size(x+10+xr*3,y+yr*i+6,3,3,0,0x000000);
			put_asc16_size(x+10+xr*3+100,y+yr*i+6,3,3,"%",0x000000);
			put_asc16_number_size(x+10+xr*4,y+yr*i+6,3,3,car_num(0,a),0x000000);
			if(reserve_num(0,a)!=0)
				put_asc16_number_size(x+10+xr*5,y+yr*i+6,3,3,100*car_num(0,a)/reserve_num(0,a),0x000000);
			else
			    put_asc16_number_size(x+10+xr*5,y+yr*i+6,3,3,0,0x000000);
			put_asc16_size(x+10+xr*5+100,y+yr*i+6,3,3,"%",0x000000);
		}
		if(i==2)
		{
			prt_hz16_size(x+10,y+yr*i+6,3,3,"近三天",0x000000,"HZK\\HZK16s");
			put_asc16_number_size(x+10+xr,y+yr*i+6,3,3,reserve_num(2,a),0x000000);
			put_asc16_number_size(x+10+xr*2,y+yr*i+6,3,3,arrive_num(2,a),0x000000);
			if(reserve_num(2,a)!=0)
				put_asc16_number_size(x+10+xr*3,y+yr*i+6,3,3,100*arrive_num(2,a)/reserve_num(2,a),0x000000);
			else
				put_asc16_number_size(x+10+xr*3,y+yr*i+6,3,3,0,0x000000);
			put_asc16_size(x+10+xr*3+100,y+yr*i+6,3,3,"%",0x000000);
			put_asc16_number_size(x+10+xr*4,y+yr*i+6,3,3,car_num(2,a),0x000000);
			if(reserve_num(2,a)!=0)
				put_asc16_number_size(x+10+xr*5,y+yr*i+6,3,3,100*car_num(2,a)/reserve_num(2,a),0x000000);
			else
				put_asc16_number_size(x+10+xr*5,y+yr*i+6,3,3,0,0x000000);
			put_asc16_size(x+10+xr*5+100,y+yr*i+6,3,3,"%",0x000000);
		}
		if(i==3)
		{
			prt_hz16_size(x+10,y+yr*i+6,3,3,"近七天",0x000000,"HZK\\HZK16s");
			put_asc16_number_size(x+10+xr,y+yr*i+6,3,3,reserve_num(6,a),0x000000);
			put_asc16_number_size(x+10+xr*2,y+yr*i+6,3,3,arrive_num(6,a),0x000000);
			if(reserve_num(6,a)!=0)
				put_asc16_number_size(x+10+xr*3,y+yr*i+6,3,3,100*arrive_num(6,a)/reserve_num(6,a),0x000000);
			else
				put_asc16_number_size(x+10+xr*3,y+yr*i+6,3,3,0,0x000000);
			put_asc16_size(x+10+xr*3+100,y+yr*i+6,3,3,"%",0x000000);
			put_asc16_number_size(x+10+xr*4,y+yr*i+6,3,3,car_num(6,a),0x000000);
			if(reserve_num(6,a)!=0)
				put_asc16_number_size(x+10+xr*5,y+yr*i+6,3,3,100*car_num(6,a)/reserve_num(6,a),0x000000);
			else
				put_asc16_number_size(x+10+xr*5,y+yr*i+6,3,3,0,0x000000);
			put_asc16_size(x+10+xr*5+100,y+yr*i+6,3,3,"%",0x000000);
		}
		
	}
	
	for(i=0;i<5;i++)
	{
		Line_Thick(x,y+yr*i,x+xr*6,y+yr*i,2,0x000000);
	}
	
	bar1(x,390,x+100,440,0xFFFFFF);
	prt_hz16_size(x+16,390+10,2,2,"今日",0x000000,"HZK\\HZK16s");
	bar1(x+100,390,x+200,440,0xFFFFFF);
	prt_hz16_size(x+100,390+10,2,2,"近三天",0x000000,"HZK\\HZK16s");
	bar1(x+200,390,x+300,440,0xFFFFFF);
	prt_hz16_size(x+200,390+10,2,2,"近七天",0x000000,"HZK\\HZK16s");
	
	if(n==0)
	{
		bar1(x,390,x+100,440,0x00FF);
		prt_hz16_size(x+16,390+10,2,2,"今日",0x000000,"HZK\\HZK16s");
	}
	if(n==2)
	{
		bar1(x+100,390,x+200,440,0x00FF);
		prt_hz16_size(x+100,390+10,2,2,"近三天",0x000000,"HZK\\HZK16s");
	}
	if(n==6)
	{
		bar1(x+200,390,x+300,440,0xFF);
		prt_hz16_size(x+200,390+10,2,2,"近七天",0x000000,"HZK\\HZK16s");
	}
	
	//Line_Thick(x-5,450-5,530+5,750+5,0x000000);
	Line_Thick(x-5,450-5,530+5,450-5,2,0x000000);
	Line_Thick(x-5,750+5,530+5,750+5,2,0x000000);
	Line_Thick(x-5,450-5,x-5,750+5,2,0x000000);
	Line_Thick(530+5,450-5,530+5,750+5,2,0x000000);
	
	prt_hz16_size(x,450,2,2,"用户取消预约率",0x000000,"HZK\\HZK16s");
	put_asc16_number_size(430,450,2,2,can_rate(n,a),0x000000);
	Put_Asc16_Size(530-50,450,2,2,'%',0x000000);
	Line_Thick(430,450+40,530,450+40,2,0x000000);
	
	prt_hz16_size(x,500,2,2,"审批通过率",0x000000,"HZK\\HZK16s");
	put_asc16_number_size(430,500,2,2,pass_rate(n,a),0x000000);
	Put_Asc16_Size(530-50,500,2,2,'%',0x000000);
	Line_Thick(430,500+40,530,500+40,2,0x000000);
	
	prt_hz16_size(x,550,2,2,"校外人员预约占比",0x000000,"HZK\\HZK16s");
	put_asc16_number_size(430,550,2,2,xiaowai_rate(n,a),0x000000);
	Put_Asc16_Size(530-50,550,2,2,'%',0x000000);
	Line_Thick(430,550+40,530,550+40,2,0x000000);
	
	prt_hz16_size(x,600,2,2,"主校区预约占比",0x000000,"HZK\\HZK16s");
	put_asc16_number_size(430,600,2,2,zhuxq_rate(n,a),0x000000);
	Put_Asc16_Size(530-50,600,2,2,'%',0x000000);
	Line_Thick(430,600+40,530,600+40,2,0x000000);
	
}
//7:00--20:00,7-9,10-12,13-15,16-19
void draw_jintime(int n,DATE *a)
{
	int i;
	int s=0;
	int b[4]={0};
	int angle[3]={0};
	Visitor *p;
	VisitorList VL;
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	InitVisitorList(&VL);
	
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i=0;i<VL.length;i++)
	{
		p = &VL.elem[i];
		month=atoi(p->jin_month);
		day=atoi(p->jin_day);
		day2=month*30+day;
		if (all_day-day2<=n)			//n分别可取0,2,6,1000
		{
			if(atoi(p->jin_hour)>=7&&atoi(p->jin_hour)<=9)
				b[0]++;
			if(atoi(p->jin_hour)>=10&&atoi(p->jin_hour)<=12)
				b[1]++;
			if(atoi(p->jin_hour)>=13&&atoi(p->jin_hour)<=15)
				b[2]++;
			if(atoi(p->jin_hour)>=17&&atoi(p->jin_hour)<=19)
				b[3]++;
		}
	}
	for (i=0;i<4;i++)
		s+=b[i];
	if(s!=0)
	{
		prt_hz16_size(550,580,2,2,"进",0x000000,"HZK\\HZK16s");
		prt_hz16_size(550,580+40,2,2,"校",0x000000,"HZK\\HZK16s");
		prt_hz16_size(550,580+40*2,2,2,"时",0x000000,"HZK\\HZK16s");
		prt_hz16_size(550,580+40*3,2,2,"间",0x000000,"HZK\\HZK16s");
		
		angle[0]=b[0]*360/s;
		angle[1]=b[1]*360/s+angle[0];
		angle[2]=b[2]*360/s+angle[1];

		DrawSector(680,650,90,0,angle[0],0x59497A);
		DrawSector(680,650,90,angle[0],angle[1],0x557E9C);
		DrawSector(680,650,90,angle[1],angle[2],0x5B7569);
		DrawSector(680,650,90,angle[2],360,0xB7B647);
		
		
		bar1(800,570,800+32,570+32,0x59497A);
		put_asc16_size(840,570,2,2,"7-9",0x000000);
		bar1(800,620,800+32,620+32,0x557E9C);
		put_asc16_size(840,620,2,2,"10-12",0x000000);
		bar1(800,670,800+32,670+32,0x5B7569);
		put_asc16_size(840,670,2,2,"13-15",0x000000);
		bar1(800,720,800+32,720+32,0xB7B647);
		put_asc16_size(840,720,2,2,"16-19",0x000000);
		
		put_asc16_number_size(930,570,2,2,100*b[0]/s,0x000000);
		put_asc16_number_size(930,620,2,2,100*b[1]/s,0x000000);
		put_asc16_number_size(930,670,2,2,100*b[2]/s,0x000000);
		put_asc16_number_size(930,720,2,2,100*b[3]/s,0x000000);
		
		put_asc16_size(990,570,2,2,"%",0x000000);
		put_asc16_size(990,620,2,2,"%",0x000000);
		put_asc16_size(990,670,2,2,"%",0x000000);
		put_asc16_size(990,720,2,2,"%",0x000000);
	}
	if(s==0)
		prt_hz16_size(600,550,3,3,"暂无进校记录",0x000000,"HZK\\HZK16s");
	
	DestroyVisitorList(&VL);
}

void draw_reason(int n,DATE *a)
{
	int i;
	int s=0;
	int b[3]={0};
	int angle[2]={0};
	Visitor *p;
	VisitorList VL;
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	InitVisitorList(&VL);
	
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i=0;i<VL.length;i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		if (all_day-day2<=n)			//n分别可取0,2,6,1000
		{
			if(p->reason==1)
				b[0]++;
			if(p->reason==2)
				b[1]++;
			if(p->reason==3)
				b[2]++;
		}
	}
	s=b[0]+b[1]+b[2];
	if(s!=0)
	{
		angle[0]=b[0]*360/s;
		angle[1]=b[1]*360/s+angle[0];
		
		prt_hz16_size(550,380,2,2,"进",0x000000,"HZK\\HZK16s");
		prt_hz16_size(550,380+40,2,2,"校",0x000000,"HZK\\HZK16s");
		prt_hz16_size(550,380+40*2,2,2,"原",0x000000,"HZK\\HZK16s");
		prt_hz16_size(550,380+40*3,2,2,"因",0x000000,"HZK\\HZK16s");
		
		DrawSector(680,460,90,0,angle[0],0x3EC84D);
		DrawSector(680,460,90,angle[0],angle[1],0xE9DD24);
		DrawSector(680,460,90,angle[1],360,0xA8593F);
		
		
		bar1(800,410,800+32,410+32,0x3EC84D);
		prt_hz16_size(840,410,2,2,"参观",0x000000,"HZK\\HZK16s");
		bar1(800,460,800+32,460+32,0xE9DD24);
		prt_hz16_size(840,460,2,2,"探亲",0x000000,"HZK\\HZK16s");
		bar1(800,510,800+32,510+32,0xA8593F);
		prt_hz16_size(840,510,2,2,"其他",0x000000,"HZK\\HZK16s");
		
		put_asc16_number_size(930,410,2,2,100*b[0]/s,0x000000);
		put_asc16_number_size(930,460,2,2,100*b[1]/s,0x000000);
		put_asc16_number_size(930,510,2,2,100*b[2]/s,0x000000);
		
		put_asc16_size(990,410,2,2,"%",0x000000);
		put_asc16_size(990,460,2,2,"%",0x000000);
		put_asc16_size(990,510,2,2,"%",0x000000);
	}
	if(s==0)
		prt_hz16_size(600,400,3,3,"暂无预约记录",0x000000,"HZK\\HZK16s");
	
	DestroyVisitorList(&VL);
}

void Light_manager_func(int tag)
{
	mouse_off(&mouse);
	switch (tag)
	{
		//返回键
		case 0:
		{
			bar1(15+1,10+1,120+48*2-1,90-1,0xB3B5B6);
			Line_Thick(15,50,60,10,2,0xDC2DF1);
			Line_Thick(60,10,60,30,2,0xDC2DF1);
			Line_Thick(60,30,115,30,2,0xDC2DF1);
			Line_Thick(15,50,60,90,2,0xDC2DF1);
			Line_Thick(60,90,60,70,2,0xDC2DF1);
			Line_Thick(60,70,115,70,2,0xDC2DF1);
			Line_Thick(115,30,115,70,2,0xDC2DF1);
			prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0xDC2DF1, "HZK\\HZK16s");
			break;
		}
		//上一页
		case 1:
		{
			bar1(10,680,100+5+16*3*3,720*2-680,0xB3B5B6);
			JianTou(10,720,55,680,100,700,0xDC2DF1);
			prt_hz16_size(100+5,720-16*3/2,3,3,"上一页",0xDC2DF1,"HZK\\HZK16s");
			break;
		}
		//下一页
		case 2:
		{
			bar1(1023-(100+5)-16*3*3,680,1023-10,720*2-680,0xB3B5B6);
			JianTou(1023-10,720,1023-55,680,1023-100,700,0xDC2DF1);
			prt_hz16_size(1023-(100+5)-16*3*3,720-16*3/2,3,3,"下一页",0xDC2DF1,"HZK\\HZK16s");
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void Dark_manager_func(int tag)
{
	mouse_off(&mouse);
	switch (tag)
	{
		case 0:
		{
			bar1(15,10,120+48*2,90,0x87CEFA);
			Line_Thick(15,50,60,10,2,0x000000);
			Line_Thick(60,10,60,30,2,0x000000);
			Line_Thick(60,30,115,30,2,0x000000);
			Line_Thick(15,50,60,90,2,0x000000);
			Line_Thick(60,90,60,70,2,0x000000);
			Line_Thick(60,70,115,70,2,0x000000);
			Line_Thick(115,30,115,70,2,0x000000);
			prt_hz16_size( 120,50-16*3/2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");
			break;
		}
		case 1:
		{
			bar1(10,680,100+5+16*3*3,720*2-680,0x87CEFA);
			JianTou(10,720,55,680,100,700,0x000000);
			prt_hz16_size(100+5,720-16*3/2,3,3,"上一页",0x000000,"HZK\\HZK16s");
			break;
		}
		case 2:
		{
			bar1(1023-(100+5)-16*3*3,680,1023-10,720*2-680,0x87CEFA);
			JianTou(1023-10,720,1023-55,680,1023-100,700,0x000000);
			prt_hz16_size(1023-(100+5)-16*3*3,720-16*3/2,3,3,"下一页",0x000000,"HZK\\HZK16s");
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void  draw_bg(Visitor *p,int flag)
{
	int i=0,j=0;
	int x=50,y=100;
	int xr=120,yr=60;
	
	if (flag==0)//填充左边的表格
	{
		Line_Thick(x,y,x,y+yr*8,2,0x000000);
		Line_Thick(512-x,y,512-x,y+yr*8,2,0x000000);
		Line_Thick(x+xr,y,x+xr,y+yr*8,2,0x000000);
		bar1(x+10,y+yr*8+10,200,y+yr*8+70,0x00FF);
		bar1(512-200,y+yr*8+10,512-x-10,y+yr*8+70,0x00FF);
		for (i=0;i<9;i++)
		{
			Line_Thick(x,y+yr*i,512-x,y+yr*i,2,0x000000);
			if(i==0)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"日期",0x000000,"HZK\\HZK16s");
			if(i==1)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"电话",0x000000,"HZK\\HZK16s");
			if(i==2)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"姓名",0x000000,"HZK\\HZK16s");
			if(i==3)
				prt_hz16_size(x+10,y+yr*i+6,2,3,"身份证",0x000000,"HZK\\HZK16s");
			if(i==4)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"校区",0x000000,"HZK\\HZK16s");
			if(i==5)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"方式",0x000000,"HZK\\HZK16s");
			if(i==6)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"身份",0x000000,"HZK\\HZK16s");
			if(i==7)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"原因",0x000000,"HZK\\HZK16s");
		}
		prt_hz16_size(x+30,y+yr*8+10+11,2,3,"不通过",0xFFFFFF,"HZK\\HZK16s");
		prt_hz16_size(512-200+25,y+yr*8+10+11,3,3,"通过",0xFFFFFF,"HZK\\HZK16s");
	}
	
	if(flag==1)//填充右边的表格
	{
		x+=512;
		Line_Thick(x,y,x,y+yr*8,2,0x000000);
		Line_Thick(1024+512-x,y,1024+512-x,y+yr*8,2,0x000000);
		Line_Thick(x+xr,y,x+xr,y+yr*8,2,0x000000);
		bar1(x+10,y+yr*8+10,512+200,y+yr*8+70,0x00FF);
		bar1(1024-200,y+yr*8+10,1024+512-x-10,y+yr*8+70,0x00FF);
		for (i=0;i<9;i++)
		{
			Line_Thick(x,y+yr*i,1024+512-x,y+yr*i,2,0x000000);
			if(i==0)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"日期",0x000000,"HZK\\HZK16s");
			if(i==1)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"电话",0x000000,"HZK\\HZK16s");
			if(i==2)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"姓名",0x000000,"HZK\\HZK16s");
			if(i==3)
				prt_hz16_size(x+10,y+yr*i+6,2,3,"身份证",0x000000,"HZK\\HZK16s");
			if(i==4)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"校区",0x000000,"HZK\\HZK16s");
			if(i==5)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"方式",0x000000,"HZK\\HZK16s");
			if(i==6)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"身份",0x000000,"HZK\\HZK16s");
			if(i==7)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"原因",0x000000,"HZK\\HZK16s");
		}
		prt_hz16_size(x+30,y+yr*8+10+11,2,3,"不通过",0xFFFFFF,"HZK\\HZK16s");
		prt_hz16_size(1024-200+25,y+yr*8+10+11,3,3,"通过",0xFFFFFF,"HZK\\HZK16s");
	}
	
	x+=130;
	 
	for (i=0;i<8;i++)
	{
		if(i==0)
		{
			put_asc16_size(x+10,y+yr*i+6,3,3,p->dengji_month,0x000000);
			put_asc16_size(x+10+50,y+yr*i+6,3,3,p->dengji_date,0x000000);
		}
		if(i==1)
			put_asc16_size(x+10,y+yr*i+6,3,3,p->tele,0x000000);
		if(i==2)
			put_asc16_size(x+10,y+yr*i+6,3,3,p->dengji_name,0x000000);
		if(i==3)
			put_asc16_size(x+10,y+yr*i+6,3,3,p->dengji_id,0x000000);
		if(i==4)
		{
			if (p->state_xiaoqu==1)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"同济校区",0x000000,"HZK\\HZK16s");
			if (p->state_xiaoqu==2)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"主校区",0x000000,"HZK\\HZK16s");
		}
		if(i==5)
		{
			if (p->state_way==2)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"步行",0x000000,"HZK\\HZK16s");
			else {
				put_asc16_size(x+10,y+yr*i+6,3,3,p->car_number,0x000000);
			}
		}
			
		if(i==6)
		{
			if(p->user_stu==0)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"校外人员",0x000000,"HZK\\HZK16s");
			if(p->user_stu==1)
				prt_hz16_size(x+10,y+yr*i+6,3,3,"学生",0x000000,"HZK\\HZK16s");
		}
		if(i==7)
		{
		    if(p->reason==1)
			    prt_hz16_size(x+10,y+yr*i+6,3,3,"参观校园",0x000000,"HZK\\HZK16s");
			else if(p->reason==2)
			    prt_hz16_size(x+10,y+yr*i+6,3,3,"探亲",0x000000,"HZK\\HZK16s");
			else if(p->reason==3)
			    prt_hz16_size(x+10,y+yr*i+6,3,3,"其他",0x000000,"HZK\\HZK16s");
		}
	}
			
}

void draw_tg(int tag)
{
	int x=50,y=100;
	int xr=120,yr=60;
	
	switch(tag)
	{
		case 1://左不通
		{
			bar1(x+10,y+yr*8+10,200,y+yr*8+70,0x000000);
			bar1(512-200,y+yr*8+10,512-x-10,y+yr*8+70,0x00FF);
			prt_hz16_size(x+30,y+yr*8+10+11,2,3,"不通过",0xFFFFFF,"HZK\\HZK16s");
			prt_hz16_size(512-200+25,y+yr*8+10+11,3,3,"通过",0xFFFFFF,"HZK\\HZK16s");
			break;
		}
		case 2://左通
		{
			bar1(x+10,y+yr*8+10,200,y+yr*8+70,0x00FF);
			bar1(512-200,y+yr*8+10,512-x-10,y+yr*8+70,0x000000);
			prt_hz16_size(x+30,y+yr*8+10+11,2,3,"不通过",0xFFFFFF,"HZK\\HZK16s");
			prt_hz16_size(512-200+25,y+yr*8+10+11,3,3,"通过",0xFFFFFF,"HZK\\HZK16s");
			break;
		}
		case 3://右不通
		{
			x+=512;
			bar1(x+10,y+yr*8+10,512+200,y+yr*8+70,0x000000);
			bar1(1024-200,y+yr*8+10,1024+512-x-10,y+yr*8+70,0x00FF);
			prt_hz16_size(x+30,y+yr*8+10+11,2,3,"不通过",0xFFFFFF,"HZK\\HZK16s");
			prt_hz16_size(1024-200+25,y+yr*8+10+11,3,3,"通过",0xFFFFFF,"HZK\\HZK16s");
			break;
		}
		case 4://右通
		{
			x+=512;
			bar1(x+10,y+yr*8+10,512+200,y+yr*8+70,0x00FF);
			bar1(1024-200,y+yr*8+10,1024+512-x-10,y+yr*8+70,0x000000);
			prt_hz16_size(x+30,y+yr*8+10+11,2,3,"不通过",0xFFFFFF,"HZK\\HZK16s");
			prt_hz16_size(1024-200+25,y+yr*8+10+11,3,3,"通过",0xFFFFFF,"HZK\\HZK16s");
			break;
		}
	}
}

int reserve_num (int n,DATE *a)
{
	int i;
	int num=0;					//num为返回的总人次
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		
		if (all_day-day2<=n)			//n分别可取0,2,6
		{
			num++;
		}
	}
	DestroyVisitorList(&VL);
	return num;
}

int arrive_num(int n,DATE *a)
{
	int i;
	int num=0;					//num为返回的总人次
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		
		if (all_day-day2<=n&&p->jin_xiao==1)			//n分别可取0,2,6
		{
			num++;
		}
	}
	DestroyVisitorList(&VL);
	return num;
}

int  can_rate(int n,DATE *a)
{
	int i;
	float rate;						//用于返回的取消比例
	int quxiao=0;
	int t=0;
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		if (all_day-day2<=n)			//n分别可取0,2,6
		{
			t++;
			if(p->condition==-2)
				quxiao++;
		}
	}
	if(t!=0)
		rate=100*quxiao/t;
	DestroyVisitorList(&VL);
	return rate;
}

int pass_rate(int n,DATE *a)
{
	int i;
	float rate;						//用于通过的比例
	int pass=0;
	int no_pass=0;
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		if (day2==0)
		bar1(100,100,150,150,0xFFFFFF);
		if (all_day-day2<=n&&p->condition==1)			//通过的人数
		{
			pass++;
		}
		if (all_day-day2<=n&&p->condition==0)			//不通过的人数
		{
			no_pass++;
		}
	}
	if (pass+no_pass==0)
	{
		DestroyVisitorList(&VL);
		return 0;
	}
		
	else{
		rate=100*pass/(pass+no_pass);		//不计算未审批和用户主动取消的
		DestroyVisitorList(&VL);
		return rate;
	}
}

int xiaowai_rate(int n,DATE *a)
{
	int i;
	float rate;						//用于通过的比例
	int user=0;
	int t=0;
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		if (all_day-day2<=n)			//计算校外人员
		{
			t++;
			if(p->user_stu==0)
				user++;
		}
	}
	if(t!=0)
		rate=100*user/t;	
	DestroyVisitorList(&VL);
	return rate;
}

int car_num (int n,DATE *a)
{
	int i;
	int num=0;					//num为返回的总车辆数
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		
		if (all_day-day2<=n&&p->state_way==1)			//n分别可取0,2,6
		{
			num++;
		}
	}
	DestroyVisitorList(&VL);
	return num;
}

int zhuxq_rate(int n,DATE *a)
{
	int i;
	float rate;						//用于主校区的比例
	int zhuxq=0;	
	int t=0;
	int month,day,all_day;		//all_day表示现在的天数
	int day2;					//用于计算用户的预约的天数来比较all_day	//主校区的总数
	Visitor *p;
	VisitorList VL;
	InitVisitorList(&VL);
	// 读取文件中的访客信息
    ReadAllVisitors(&VL);
	
	//计算总天数
	month=atoi(a[0].month);
	day=atoi(a[0].day);
	all_day=month*30+day;
	
	for (i = 0; i < VL.length; i++)
	{
		p = &VL.elem[i];
		month=atoi(p->dengji_month);
		day=atoi(p->dengji_date);
		day2=month*30+day;
		if (all_day-day2<=n)			
		{
			t++;
			if(p->state_xiaoqu==2)
				zhuxq++;
		}
	}
	if (t!=0)
		rate=100*zhuxq/t;		//不计算未审批和用户主动取消的
	DestroyVisitorList(&VL);
	return rate;
}
