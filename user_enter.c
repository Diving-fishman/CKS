#include"allfunc.h"
#include"ufunc.h"
#include"u_enter.h"

void user_enter(int *func,int *unum,int* num)                         //模拟进校操作
{
     VisitorList VL;
	 int i=0,j=0;
    DATE a[5];
    //时间存储
    char temp[20]={0};
	
	InitVisitorList(&VL);
	
    //读入所有已录入的游客信息便于检索
    ReadAllVisitors(&VL);

	get_time(a);                        //记录当前时间
    mouse_off(&mouse);
	draw_user_enter(a);            //描绘当前页面
	mouse_on(mouse);
	
	while(1)
	{
	    mouse_show(&mouse);
		
		if(mouse_press(15,10,120+48*2,90)==1)//点击返回
        {
            *func=*num;
            break;
        }
		if(mouse_press(300,375,800,400)==1)//输入进校身份证号
		{
		    mouse_off(&mouse);
			strcpy(temp,"\0");
			bar1(300,350,800,420,0x87CEFA);
			Getinfo(300,375,temp,18,300,375,800,400);
			Line_Thick(300,430,800,430,1, 0xBD32 );
			mouse_on(mouse);
		}
		
		if(mouse_press(400,650,400+240,650+55)==1)//当要进校时
		{
		    for ( i = 0; i < VL.length; i++)                      //遍历所有的登记信息来检索
			{
				Visitor *visitor = &VL.elem[i];
                
				if(strcmp(visitor->dengji_id,temp)==0&&visitor->condition==-1)//若身份证号正确但未审批
				{
				    prt_hz16_size(400,710,2,2,"未审批！", 0x000000, "HZK\\HZK16s");
					j=2;
					delay(2000);
					bar1(400,710,700,800, 0x87CEFA);
				}
				else if(strcmp(visitor->dengji_id,temp)==0&&visitor->condition==0)//若身份证号正确但审批未通过
				{
				    prt_hz16_size(400,710,2,2,"审批未通过！", 0x000000, "HZK\\HZK16s");
					j=2;
					delay(2000);
					bar1(400,710,700,800, 0x87CEFA);
				}
				else if(strcmp(visitor->dengji_id,temp)==0&&(atoi(a[0].hour)<8||atoi(a[0].hour)>20))//若身份证号正确但错误时间进校
				{
				    prt_hz16_size(400,710,2,2,"未在规定时间内入校！", 0x000000, "HZK\\HZK16s");
					j=2;
					delay(2000);
					bar1(400,710,700,800, 0x87CEFA);
				}
				
				else if(strcmp(visitor->dengji_id,temp)==0&&(atoi(a[0].hour)>8&&atoi(a[0].hour)<20))//若身份证号正确且正确时间进校
				{
				    save_id(&VL,a,i);
					j=1;
					//打印成功信息并退出
					prt_hz16_size(400,710,2,2,"进校成功！", 0x000000, "HZK\\HZK16s");
					delay(3000);
					*func=31;
					break;
				}
			}
			
			if(j==0)//如果没有找到对应信息
			{
				prt_hz16_size(400,710,2,2,"未找到联系人！", 0x000000, "HZK\\HZK16s");
				delay(2000);
				bar1(400,710,700,800, 0x87CEFA);
			}
	   }
	   if(j==1)
	        break;
	}
	DestroyVisitorList(&VL);
}

void draw_user_enter(DATE *p)
{
    bar1(0,0,1023,767,0x87CEFA);//背景色;
	bar1(0,0,1023,767,0x87CEFA);//背景色;
//	bar1(0,0,210,100,0x00FF);//返回

    JianTou(15,50,60,10,115,30,0x000000);
	prt_hz16_size(120,50-16*3/2,3,3,"返回",0x000000,"HZK\\HZK16s");//返回按钮
	
	prt_hz16_size(300,300,3,3, "请输入您的身份证号码", 0x000000, "HZK\\HZK16s");
	
	Line_Thick(300,430,800,430,1, 0xBD32 );
	
	drawdengbotton(400,650,"确认");
	
	//播报时间
	prt_hz16_size(260,150,2,2,"现在是",0x000000,"HZK\\HZK16s");
	put_asc16_size( 260+16*2*3+10,150,2,2,p[0].year,0xFFFFFF);
	put_asc16_size( 260+16*2*3+10+80,150,2,2,p[0].month,0xFFFFFF);
	put_asc16_size( 260+16*2*3+10+110,150,2,2,p[0].day,0xFFFFFF);
	prt_hz16_size(260+16*2*3+10+110+35,150,2,2,"日",0x000000,"HZK\\HZK16s");
	put_asc16_size( 260+16*2*3+10+110+65,150,2,2,p[0].hour,0xFFFFFF);
	prt_hz16_size(260+16*2*3+10+110+100,150,2,2,"时",0x000000,"HZK\\HZK16s");
	put_asc16_size( 260+16*2*3+10+110+140,150,2,2,p[0].minute,0xFFFFFF);
	prt_hz16_size(260+16*2*3+10+110+170,150,2,2,"分",0x000000,"HZK\\HZK16s");
	bar2(250,125,250+16*2*3+110+60+180,200,0x00FF);
}

void save_id(VisitorList *VL,DATE* a,int i)
{
    FILE *fp = fopen("visitorinfo.dat", "wb");
	
    //在文件中记录进校时间
	strcpy(VL->elem[i].jin_month,a[0].month);
	strcpy(VL->elem[i].jin_day,a[0].day);
	strcpy(VL->elem[i].jin_hour,a[0].hour);
	strcpy(VL->elem[i].jin_min,a[0].minute);
	VL->elem[i].jin_xiao=1;
	fwrite(&VL->length, sizeof(int), 1, fp);
	fwrite(VL->elem, sizeof(Visitor), VL->length, fp);
	fclose(fp);
}