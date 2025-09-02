#include <allfunc.h>
#include "lgfunc.h"
#include"login.h"

//新用户注册
void rigister_login(int *func)
{
	int f[10]={0};
	struct USER temp={0};//存储信息的用户结构体 
	char judge[10]="\0";//用于判断的密码 

    mouse_off(&mouse);
	draw_rigister_login();
    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        if(mouse_press(280,240,1074-280,240+46)==1)   //输入账号
		{
			mouse_off(&mouse);
			bar1(280,240,1074-280,240+46,0x87CEFA);
			strcpy(temp.name,"\0");
			Getinfo(280,240,temp.name,10,280,240,1074-280,240+46);
			mouse_on(mouse);
		}
		else if(mouse_press(280,340,1074-280,340+46)==1)    //输入密码
		{
			mouse_off(&mouse);
			bar1(280,340,1074-280,340+46,0x87CEFA);
			strcpy(temp.code,"\0");
			Getcode(280,340,temp.code,10,280,340,1074-280,340+46);
			mouse_on(mouse);
		}
		else if(mouse_press(280,440,1074-280,440+46)==1)     //重新输入密码
		{
			mouse_off(&mouse);
			bar1(280,440,1074-280,440+46,0x87CEFA);
			strcpy(judge,"\0");
			Getcode(280,440,judge,10,280,440+46,1074-280,440+46);
			mouse_on(mouse);
		}
		if(mouse.x>600&&mouse.x<600+236&&mouse.y>620&&mouse.y<620+55)
		{
			if(mouse_press(600,620,600+236,620+55)==1)     //点击确认键
			{
				if(strcmp(temp.name,"\0")!=0)//用户名不为空 
				{
					if(strcmp(temp.code,"\0")!=0)//密码不为空 
					{
						if(!strcmp(temp.code,judge))//两次密码相同 
						{
						  if(save_user(temp)==0)
						  {
							*func=2;
							break;
						  }
						  else
						  {
							prt_hz24(512-7*24/2,720,"用户名已被注册！",10,"HZK\\Hzk24h");
							delay(500);
							bar1(200,720,1000,767,0x87CEFA);
						  }
						}
						else
						{
						  prt_hz24(512-7*16/2,720,"两次密码不相同！",0,"HZK\\Hzk24h");
						  delay(500);
						  bar1(200,720,1000,767,0x87CEFA);
						}  
					}
					else
					{
						prt_hz24(512-4*16/2,720,"密码为空！",0,"HZK\\Hzk24h");
						delay(500);
						bar1(200,720,1000,767,0x87CEFA);
					}	
				}
				else
				{
					prt_hz24(512-5*16/2,720,"用户名为空！",0,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);			//遮盖字体
				}	
			}else if(f[0]==0)
					{
						Light_login(1);
						f[0]=1;
						continue;
					}
		}else 
		{
			if (f[0]==1)
			{
				Dark_login(1);
				f[0]=0;
			}
		}
		//返回
		if(mouse.x>280&&mouse.x<280+236&&mouse.y>620&&mouse.y<620+55)
		{
			if (mouse_press(280,620,280+236,620+55)==1)
			{
				*func=0;
				break;
			}else if(f[1]==0)
				{
					Light_login(0);
					f[1]=1;
					continue;
				}
		} else 
		{
			if (f[1]==1)
			{
				Dark_login(0);
				f[1]=0;
			}
		}
    }
}

//用户使用账号登录
void user_login(int *func,int *unum)
{
	int f[10]={0};
    char name[10]="\0";
	char code[10]="\0";
    int i=-5;

    UserList UL={0};
	InitUList(&UL);				//链表初始化
	ReadAllUser(&UL);

    mouse_off(&mouse);
	
	draw_user_login();
   
    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        if(mouse_press(280,240,1074-280,240+46)==1)//点击账号框 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(280,240,1074-280,240+46,0x87CEFA);
			Getinfo(280,240,name,10,280,240,1074-280,240+46);//得到账号 
			mouse_on(mouse);
		}
        else if(mouse_press(280,340,1074-280,340+46)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(280,340,1074-280,340+46,0x87CEFA);
			Getcode(280,340,code,10,280,340,1074-280,340+46);//得到密码 
			mouse_on(mouse);
		}
		//登录
		if(mouse.x>600&&mouse.x<600+236&&mouse.y>620&&mouse.y<620+55)
		{
			if(mouse_press(600,620,600+236,620+55)==1)//点击登录
			{
				i=Check_userinfo(UL,name,code);
				if(i>=0)
				{
					*unum=i+2;
					DestroyUList(&UL);
					*func=31;      //进入用户主界面
					break;
				}
				if(i==-2)//密码输入错误 
				{
					prt_hz24(512-4*24/2,720,"密码错误！",10,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);
				}
				if(i==-3)//用户不存在 
				{
					prt_hz24(512-5*24/2,720,"用户不存在！",10,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);
				} 
			}else if(f[2]==0)
				{
					Light_login(3);
					f[2]=1;
					continue;
				}
		}else 
		{
			if (f[2]==1)
			{
				Dark_login(3);
				f[2]=0;
			}
		}
		//返回上级
        if(mouse.x>280&&mouse.x<280+236&&mouse.y>620&&mouse.y<620+55)
		{
			if (mouse_press(280,620,280+236,620+55)==1)
			{
				*func=0;
				break;
			}else if(f[3]==0)
				{
					Light_login(2);
					f[3]=1;
					continue;
				}
		} else 
		{
			if (f[3]==1)
			{
				Dark_login(2);
				f[3]=0;
			}
		}
    }

}

//the function that is used to log in by student
void student_login(int *func,int *unum)
{
	int f[10]={0};
    char name[10]="\0";
	char code[10]="\0";
    int i=-5;

    StudentList UL={0};
	InitSList(&UL);
	ReadAllStudent(&UL);

    mouse_off(&mouse);
	
	draw_student_login();
   
    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        if(mouse_press(280,240,1074-280,240+46)==1)//点击账号框 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(280,240,1074-280,240+46,0x87CEFA);
			Getinfo(280,240,name,10,280,240,1074-280,240+46);//得到账号 
			mouse_on(mouse);
		}
        else if(mouse_press(280,340,1074-280,340+46)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(280,340,1074-280,340+46,0x87CEFA);
			Getcode(280,340,code,10,280,340,1074-280,340+46);//得到密码 
			mouse_on(mouse);
		}
		//登录
		if(mouse.x>600&&mouse.x<600+236&&mouse.y>620&&mouse.y<620+55)
		{
			if(mouse_press(600,620,600+236,620+55)==1)//点击登录
			{
				i=Check_studentinfo(UL,name,code);
				if(i>=0)
				{
					*unum=i;
					DestroySList(&UL);
					*func=32;      //进入学生主界面
					break;
				}
				if(i==-2)//密码输入错误 
				{
					prt_hz24(512-4*24/2,720,"密码错误！",10,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);
				}
				if(i==-3)//用户不存在 
				{
					prt_hz24(512-5*24/2,720,"用户不存在！",10,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);
				} 
			}else if(f[4]==0)
				{
					Light_login(5);
					f[4]=1;
					continue;
				}
		}else 
		{
			if (f[4]==1)
			{
				Dark_login(5);
				f[4]=0;
			}
		}
		//返回上级
        if(mouse.x>280&&mouse.x<280+236&&mouse.y>620&&mouse.y<620+55)
		{
			if (mouse_press(280,620,280+236,620+55)==1)
			{
				*func=12;
				break;
			}else if(f[5]==0)
				{
					Light_login(4);
					f[5]=1;
					continue;
				}
		} else 
		{
			if (f[5]==1)
			{
				Dark_login(4);
				f[5]=0;
			}
		}
        
    }

}
 
//this is the function that is used to log in by manager
void manager_login(int *func,int *unum)
{
	int f[10]={0};
    char name[10]="\0";
	char code[10]="\0";
    int i=-5;

    ManagerList UL={0};
	InitMList(&UL);
	ReadAllManager(&UL);

    mouse_off(&mouse);
	
	draw_manager_login();
   
    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        if(mouse_press(280,240,1074-280,240+46)==1)//点击账号框 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(280,240,1074-280,240+46,0x87CEFA);
			Getinfo(280,240,name,10,280,240,1074-280,240+46);//得到账号 
			mouse_on(mouse);
		}
        else if(mouse_press(280,340,1074-280,340+46)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(280,340,1074-280,340+46,0x87CEFA);
			Getcode(280,340,code,10,280,340,1074-280,340+46);//得到密码 
			mouse_on(mouse);
		}
		//登录
		if(mouse.x>600&&mouse.x<600+236&&mouse.y>620&&mouse.y<620+55)
		{
			if(mouse_press(600,620,600+236,620+55)==1)//点击登录
			{
				i=Check_managerinfo(UL,name,code);
				if(i>=0)
				{
					*unum=i;
					DestroyMList(&UL);
					*func=33;      //进入管理员主界面
					break;
				}
				if(i==-2)//密码输入错误 
				{
					prt_hz24(512-4*24/2,720,"密码错误！",10,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);
				}
				if(i==-3)//用户不存在 
				{
					prt_hz24(512-5*24/2,720,"用户不存在！",10,"HZK\\Hzk24h");
					delay(500);
					bar1(200,720,1000,767,0x87CEFA);
				} 
			}else if(f[4]==0)
				{
					Light_login(5);
					f[4]=1;
					continue;
				}
		}else 
		{
			if (f[4]==1)
			{
				Dark_login(5);
				f[4]=0;
			}
		}
		//返回选择
        if(mouse.x>280&&mouse.x<280+236&&mouse.y>620&&mouse.y<620+55)
		{
			if (mouse_press(280,620,280+236,620+55)==1)
			{
				*func=12;
				break;
			}else if(f[5]==0)
				{
					Light_login(4);
					f[5]=1;
					continue;
				}
		} else 
		{
			if (f[5]==1)
			{
				Dark_login(4);
				f[5]=0;
			}
		}
        
    }

}

//画出普通输入栏
void draw_commoninput(int x1,int y1,char *s)
{
//	bar1(x1,y1,1024+50-x1,y1+60,0xBD32);
	Line_Thick(x1, y1+3, 1024-x1+50, y1+3, 1, 0xBD32 );
	prt_hz16_size(x1 + 16, y1 - 46, 2, 2, s, 0x000000, "HZK\\HZK16s");
}

//画出确认按钮
void draw_confirmbotton(int x1,int y1,char *s,unsigned int color1,unsigned int color2)
{
	Cirbar(x1, y1, x1+240, y1+55, color1);
	prt_hz16_size(x1+22,y1+4, 3,3,s, color2, "HZK\\HZK16s");
}

void draw_rigister_login(void)
{

	bar1(0,0,1023,767,0x87CEFA);//背景色
	
	prt_hz16_size(420,80, 3, 3, "用户注册", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,240, 2, 2, "账号", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,340, 2, 2, "密码", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,440, 2, 2, "密码", 0x000000, "HZK\\HZK16s");
	
    draw_commoninput(200+80,240+46,"请设定您的账号"); 
	draw_commoninput(200+80,340+46,"请设定您的密码");  
    draw_commoninput(200+80,440+46,"请确认您的密码"); 
    draw_confirmbotton(280,620,"返回登录",0x00FF,0xFFFFFF);
    draw_confirmbotton(600,620,"立即注册",0x00FF,0xFFFFFF);
	prt_hz16_size(280,540, 2, 2, "已阅读并同意《华中科技大学预约须知》", 0x00FF, "HZK\\HZK16s");
}

void draw_user_login(void)
{

	bar1(0,0,1023,767,0x87CEFA);//背景色
	
	prt_hz16_size(420,80, 3, 3, "用户登录", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,240, 2, 2, "账号", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,340, 2, 2, "密码", 0x000000, "HZK\\HZK16s");
	
    draw_commoninput(200+80,240+46,"请输入您的账号"); 
	draw_commoninput(200+80,340+46,"请输入您的密码");  
    draw_confirmbotton(280,620,"返回注册",0x00FF,0xFFFFFF);
    draw_confirmbotton(600,620,"立即登录",0x00FF,0xFFFFFF);
	prt_hz16_size(280,540, 2, 2, "已阅读并同意《华中科技大学预约须知》", 0x00FF, "HZK\\HZK16s");
}

void draw_student_login(void)
{
 
	bar1(0,0,1023,767,0x87CEFA);//背景色
	
	prt_hz16_size(420,80, 3, 3, "学生登录", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,240, 2, 2, "账号", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,340, 2, 2, "密码", 0x000000, "HZK\\HZK16s");
	
    draw_commoninput(200+80,240+46,"请输入您的学号"); 
	draw_commoninput(200+80,340+46,"请输入您的密码");  
    draw_confirmbotton(280,620,"返回上级",0x00FF,0xFFFFFF);
    draw_confirmbotton(600,620,"立即登录",0x00FF,0xFFFFFF);
	prt_hz16_size(280,540, 2, 2, "已阅读并同意《华中科技大学预约须知》", 0x00FF, "HZK\\HZK16s");
}

void draw_manager_login(void)
{

	bar1(0,0,1023,767,0x87CEFA);//背景色
	
	prt_hz16_size(420,80, 3, 3, "管理员登录", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,240, 2, 2, "账号", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(200,340, 2, 2, "密码", 0x000000, "HZK\\HZK16s");
	
    draw_commoninput(200+80,240+46,"请输入您的账号"); 
	draw_commoninput(200+80,340+46,"请输入您的密码");  
    draw_confirmbotton(280,620,"返回上级",0x00FF,0xFFFFFF);
    draw_confirmbotton(600,620,"立即登录",0x00FF,0xFFFFFF);
	prt_hz16_size(280,540, 2, 2, "已阅读并同意《华中科技大学预约须知》", 0x00FF, "HZK\\HZK16s");
}

void Light_login(int tag)
{
	mouse_off(&mouse);
	//01 注册    23 用户    45学生、管理员
	switch(tag)
	{
		case 0:
		{
			draw_confirmbotton(280,620,"返回登录",0xB3B5B6,0xDC2DF1);
			break;
		}
		case 1:
		{
			draw_confirmbotton(600,620,"立即注册",0xB3B5B6,0xDC2DF1);
			break;
		}
		case 2:
		{
			draw_confirmbotton(280,620,"返回注册",0xB3B5B6,0xDC2DF1);
			break;
		}
		case 3:
		{
			draw_confirmbotton(600,620,"立即登录",0xB3B5B6,0xDC2DF1);
			break;
		}
		case 4:
		{
			draw_confirmbotton(280,620,"返回上级",0xB3B5B6,0xDC2DF1);
			break;
		}
		case 5:
		{
			draw_confirmbotton(600,620,"立即登录",0xB3B5B6,0xDC2DF1);
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}

void Dark_login(int tag)
{
	mouse_off(&mouse);
	//01 注册    23 用户    45学生、管理员
	switch(tag)
	{
		case 0:
		{
			draw_confirmbotton(280,620,"返回登录",0x00FF,0xFFFFFF);
			break;
		}
		case 1:
		{
			draw_confirmbotton(600,620,"立即注册",0x00FF,0xFFFFFF);
			break;
		}
		case 2:
		{
			draw_confirmbotton(280,620,"返回注册",0x00FF,0xFFFFFF);
			break;
		}
		case 3:
		{
			draw_confirmbotton(600,620,"立即登录",0x00FF,0xFFFFFF);
			break;
		}
		case 4:
		{
			draw_confirmbotton(280,620,"返回上级",0x00FF,0xFFFFFF);
			break;
		}
		case 5:
		{
			draw_confirmbotton(600,620,"立即登录",0x00FF,0xFFFFFF);
			break;
		}
	}
	mouse_on(mouse);
	mouse_show(&mouse);
}







