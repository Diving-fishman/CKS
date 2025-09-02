#include"allfunc.h"
#include"ufunc.h"

//画出登记界面的确认按钮
void drawdengbotton(int x1,int y1,char *s)
{
	Cirbar(x1, y1, x1+240, y1+55, 0x00FF);
	//puthz(x1+70,y1+4,s, 48,55, 0xFFFFFF);
	prt_hz16_size( x1+70,y1+4,2,2,s, 0xFFFFFF, "HZK\\HZK16s");
}

void get_time(DATE *p)    
{
	int i;                                             //当前日期
    int a;
	int b;
	time_t now_time;
	struct tm *local_time;
	now_time=time(NULL);
	local_time=localtime(&now_time);
	a=local_time->tm_year+1900;
	b=local_time->tm_mon+1;
	itoa(a,p[0].year,10);
	itoa(b,p[0].month,10);
	itoa(local_time->tm_mday,p[0].day,10);  
	itoa(local_time->tm_hour, p[0].hour, 10); // 填充小时
    itoa(local_time->tm_min, p[0].minute, 10); // 填充分钟	

    if(b==1||b==3||b==5||b==7||b==8||b==10)           //明天、后天、三天、四天后的日期
    {   
		if(local_time->tm_mday==30)
		{   
	        itoa(a,p[1].year,10);
			itoa(b,p[1].month,10);
			itoa(31,p[1].day,10);
	        itoa(a,p[2].year,10);
	        itoa(b+1,p[2].month,10);
			itoa(1,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b+1,p[3].month,10);
			itoa(2,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(3,p[4].day,10); 
		}
		if(local_time->tm_mday==31)
		{   itoa(a,p[1].year,10);
	        itoa(b+1,p[1].month,10);
			itoa(1,p[1].day,10);
            itoa(a,p[2].year,10);
	        itoa(b+1,p[2].month,10);
			itoa(2,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b+1,p[3].month,10);
			itoa(3,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(4,p[4].day,10); 
		}
		if(local_time->tm_mday==29)
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(30,p[1].day,10); 
            itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(31,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b+1,p[3].month,10);
			itoa(1,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(2,p[4].day,10); 
		}
		if(local_time->tm_mday==28)
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(29,p[1].day,10);      
            itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(30,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b,p[3].month,10);
			itoa(31,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(1,p[4].day,10); 
		}
		else
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(local_time->tm_mday+1,p[1].day,10);
			itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(local_time->tm_mday+2,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b,p[3].month,10);
			itoa(local_time->tm_mday+3,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b,p[4].month,10);
			itoa(local_time->tm_mday+4,p[4].day,10); 
		}	
	}
	if(b==12)
	{   if(local_time->tm_mday==30)
		{   itoa(a,p[1].year,10);
	        itoa(12,p[1].month,10);
			itoa(31,p[1].day,10);  
	        itoa(a+1,p[2].year,10);
	        itoa(1,p[2].month,10);
			itoa(1,p[2].day,10);      
			itoa(a+1,p[3].year,10);
	        itoa(1,p[3].month,10);
			itoa(2,p[3].day,10); 
		    itoa(a+1,p[4].year,10);
	        itoa(1,p[4].month,10);
			itoa(3,p[4].day,10); 
		}
		if(local_time->tm_mday==31)
		{
            itoa(a+1,p[1].year,10);
	        itoa(1,p[1].month,10);
			itoa(1,p[1].day,10);  
			itoa(a+1,p[2].year,10);
	        itoa(1,p[2].month,10);
			itoa(2,p[2].day,10);      
			itoa(a+1,p[3].year,10);
	        itoa(1,p[3].month,10);
			itoa(3,p[3].day,10); 
		    itoa(a+1,p[4].year,10);
	        itoa(1,p[4].month,10);
			itoa(4,p[4].day,10); 
		}
		if(local_time->tm_mday==29)
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(30,p[1].day,10);      
            itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(31,p[2].day,10);      
			itoa(a+1,p[3].year,10);
	        itoa(1,p[3].month,10);
			itoa(1,p[3].day,10); 
		    itoa(a+1,p[4].year,10);
	        itoa(1,p[4].month,10);
			itoa(2,p[4].day,10); 
		}
		if(local_time->tm_mday==28)
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(29,p[1].day,10);     
            itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(30,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b,p[3].month,10);
			itoa(31,p[3].day,10); 
		    itoa(a+1,p[4].year,10);
	        itoa(1,p[4].month,10);
			itoa(1,p[4].day,10); 
		}
		else
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(local_time->tm_mday+1,p[1].day,10);     
			itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(local_time->tm_mday+2,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b,p[3].month,10);
			itoa(local_time->tm_mday+3,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b,p[4].month,10);
			itoa(local_time->tm_mday+4,p[4].day,10); 
		}
	}
    else
	{
		if(local_time->tm_mday==29)
		{   itoa(a,p[1].year,10);
	        itoa(b+1,p[1].month,10);
			itoa(30,p[1].day,10);  
	        itoa(a,p[2].year,10);
	        itoa(b+1,p[2].month,10);
			itoa(1,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b+1,p[3].month,10);
			itoa(2,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(3,p[4].day,10); 
		}
		if(local_time->tm_mday==30)
		{   itoa(a,p[1].year,10);
	        itoa(b+1,p[1].month,10);
			itoa(1,p[1].day,10);      
            itoa(a,p[2].year,10);
	        itoa(b+1,p[2].month,10);
			itoa(2,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b+1,p[3].month,10);
			itoa(3,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(4,p[4].day,10); 
		}
		if(local_time->tm_mday==28)
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(29,p[1].day,10);  
            itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(30,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b+1,p[3].month,10);
			itoa(1,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(2,p[4].day,10); 
		}
		if(local_time->tm_mday==27)
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(28,p[1].day,10);  
            itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(29,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b,p[3].month,10);
			itoa(30,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b+1,p[4].month,10);
			itoa(1,p[4].day,10); 
		}
		else
		{   itoa(a,p[1].year,10);
	        itoa(b,p[1].month,10);
			itoa(local_time->tm_mday+1,p[1].day,10);
			itoa(a,p[2].year,10);
	        itoa(b,p[2].month,10);
			itoa(local_time->tm_mday+2,p[2].day,10);      
			itoa(a,p[3].year,10);
	        itoa(b,p[3].month,10);
			itoa(local_time->tm_mday+3,p[3].day,10); 
		    itoa(a,p[4].year,10);
	        itoa(b,p[4].month,10);
			itoa(local_time->tm_mday+4,p[4].day,10); 
		}
		
	}
	
}


void JianTou(int x1,int y1,int x2,int y2,int x3,int y3,unsigned int color)
{
	Line_Thick(x1,y1,x2,y2,2,color);
	Line_Thick(x2,y2,x2,y3,2,color);
	Line_Thick(x2,y3,x3,y3,2,color);
	Line_Thick(x1,y1,x2,2*y1-y2,2,color);
	Line_Thick(x2,2*y1-y2,x2,2*y1-y3,2,color);
	Line_Thick(x2,2*y1-y3,x3,2*y1-y3,2,color);
	Line_Thick(x3,y3,x3,2*y1-y3,2,color);
}

void InitVisitorList(VisitorList *VL) 
{
    VL->elem = (Visitor *)malloc(100 * sizeof(Visitor));
    if (VL->elem == NULL) 
	{
        printf("Memory allocation failed!\n");
        exit(1);
    }
    VL->length = 0;
    VL->listsize = 100;
}

void DestroyVisitorList(VisitorList *VL) 
{
    free(VL->elem);
    VL->length = 0;
    VL->listsize = 0;
}

void VisitorListInsert(VisitorList *VL, Visitor visitor) 
{
    if (VL->length >= VL->listsize) 
	{
        printf("Visitor list is full!\n");
        return;
    }
    VL->elem[VL->length++] = visitor;
}

int save_visitor(VisitorList *VL, Visitor visitor) 
{
	FILE *fp = fopen("visitorinfo.dat", "wb");
    if (VL->length >= VL->listsize) 
	{
        return -1;  // 存储空间已满
    }

    VisitorListInsert(VL, visitor);

    
    if (fp == NULL) 
	{
        return -2;  // 文件打开失败
    }

    fwrite(&VL->length, sizeof(int), 1, fp);
    fwrite(VL->elem, sizeof(Visitor), VL->length, fp);

    fclose(fp);

    return 0;
}

void ReadAllVisitors(VisitorList *VL) 
{
    FILE *fp = fopen("visitorinfo.dat", "rb");
    if (fp == NULL) 
	{
        return;
    }

    fread(&VL->length, sizeof(int), 1, fp);
    fread(VL->elem, sizeof(Visitor), VL->length, fp);
    fclose(fp);
}

void SaveAllVisitors(VisitorList *VL) 
{
    FILE *fp = fopen("visitorinfo.dat", "wb");
    if (fp == NULL) {
        printf("Failed to open file for writing!\n");
        return;
    }

    fwrite(&VL->length, sizeof(int), 1, fp);
    fwrite(VL->elem, sizeof(Visitor), VL->length, fp);
    fclose(fp);
}

int DeleteVisitor(VisitorList *VL, int index) 
{
    int i;
    if (index < 0 || index >= VL->length) 
	{
        printf("Invalid index!\n");
        return -1;  // 无效索引
    }

    // 将后面的访客信息向前移动一位
    for ( i = index; i < VL->length - 1; i++) 
	{
        VL->elem[i] = VL->elem[i + 1];
    }

    VL->length--;  // 更新访客数量

    // 保存更新后的访客信息到文件
    SaveAllVisitors(VL);

    return 0;  // 成功删除
}

void UpdataVisitor(Visitor visitor)
{
	int visitornum=0;//用户位置 
	VisitorList VL={0};//用户线性表 
	FILE *fp=NULL;
	ReadAllVisitors(&VL);//获取所有用户到线性表 
	if((fp=fopen("visitorinfo.dat","rb+"))==NULL)
	{
		prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	visitornum=Visitorposition(VL,visitor);//得到用户在线性表中的位置 
	VL.elem[visitornum]=visitor;//更新线性表中用户信息 
	fseek(fp,0,SEEK_SET);
	fwrite(&VL.length, sizeof(int), 1, fp);
	fwrite(&VL.listsize, sizeof(int), 1, fp);
	fwrite(VL.elem, sizeof(Visitor), VL.length, fp);
	fclose(fp);
	DestroyVisitorList(&VL);//销毁线性表 
}

int Visitorposition(VisitorList VL,Visitor e)
{
	int i=-1;
	for(i=0;i<VL.length;i++)
	{
		if(strcmp(e.dengji_name,VL.elem[i].dengji_name)==0)
		{
			return i;
		}	
	}
	return -1;
}

void DrawSector(int xc, int yc, int radius, int start_angle, int end_angle, unsigned int color)
{
    // 定义所有变量在函数最前面
    double start_rad;
    double end_rad;
    double angle;
    int x;
    int y;
    int r;
    int px;
    int py;

    if (radius <= 0)
    {
        return;
    }

    // 将角度转换为弧度
    start_rad = (double)start_angle * 3.1415926 / 180.0;
    end_rad = (double)end_angle * 3.1415926 / 180.0;

    // 遍历每个角度
    for (angle = start_rad; angle <= end_rad; angle += 0.01)
    {
        // 计算当前角度对应的点的坐标
        x = xc + (int)(radius * cos(angle));
        y = yc + (int)(radius * sin(angle));

        // 绘制从圆心到当前点的线段
        for (r = 0; r <= radius; r++)
        {
            px = xc + (int)(r * cos(angle));
            py = yc + (int)(r * sin(angle));
            Putpixel64k(px, py, color);
        }
    }
}
void bianxie(int unum)
{
	Visitor temp;
	VisitorList VL;
	
	InitVisitorList(&VL);

    // 读取所有访客信息
    ReadAllVisitors(&VL);
	
	temp.dengji_user=unum;
	strcpy(temp.dengji_year,"2025");
	strcpy(temp.dengji_month,"4");
	
	temp.bianhao=22;
	temp.user_stu=0;
	strcpy(temp.dengji_name,"rocky");
	strcpy(temp.dengji_id,"11111113");
	temp.reason=1;
	temp.state_xiaoqu=2;
	stpcpy(temp.tele,"165254203");
	strcpy(temp.dengji_date,"24");
	temp.state_way=2;
	strcpy(temp.car_number,"\0");
	temp.condition=1;
	temp.jin_xiao=1;
	
	strcpy(temp.jin_month,"4");
	strcpy(temp.jin_day,"24");
	strcpy(temp.jin_hour,"18");
	strcpy(temp.jin_min,"36");
	strcpy(temp.cancel_year,"\0");
	strcpy(temp.cancel_month,"\0");
	strcpy(temp.cancel_day,"\0");
	strcpy(temp.cpname[0],"\0");
	strcpy(temp.cpid[0],"\0");
	strcpy(temp.cpname[1],"\0");
	strcpy(temp.cpid[1],"\0");
	
	if (save_visitor(&VL, temp) == 0)
		bar1(200,200,300,300,0x0000000);
}