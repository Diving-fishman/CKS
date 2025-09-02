#include "allfunc.h"
#include"welcome.h"

void welcome(int* func)
{
    mouse_off(&mouse);
	delay(100);

    draw_welcome();//画欢迎界面的特有元素

    mouse_on(mouse);

    while(1)
    {
//		if(mouse.x<1022&&mouse.x>2&&mouse.y>2&&mouse.y<770)
			mouse_show(&mouse);

        if(mouse_press(512-300,430,512+300,430+100)==1)//点击登录
        {
            *func=12;
            break;
        }

        else if(mouse_press(512-300,560+40,512+300,560+40+100)==1)						//点击注册
        {
            *func=1;
            break;
        }
		if (mouse_press(15,10,120+48*2,90)==1)
		{
			exit(0);
		}
    }
}

void draw_welcome()
{
	
	bar1(0,0,1023,767,0x87CEFA);//底色覆盖
	//Readbmp64k(0,0,"bmp\\wel.bmp"); 
	
	JianTou(15,50,60,10,115,30,0x000000);
    prt_hz16_size( 120,50-16*3/2, 3, 3, "退出", 0x000000, "HZK\\HZK16s");
	
    //标题
	prt_hz16_size(30,260, 5, 5, "华中科技大学进校预约系统", 0x00000, "HZK\\HZK16s");

	//选项框
	Cirbar(512-300,430,512+300,430+100,0x00FF);
	Cirbar(512-300,560+40,512+300,560+40+100,0x00FF);

	//写字
	prt_hz16_size(512-48,480-24, 3, 3, "登录", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size(512-48,650-24, 3, 3, "注册", 0xFFFFFF, "HZK\\HZK16s");
}

void donghua(void )
{
	bar1(0,0,1023,767,0x87CEFA);
	prt_hz16_size(512-16*5*6/2,70, 5, 5, "华中科技大学", 0x00000, "HZK\\HZK16s");
	Circlefill(512,400,230,0xFFFFFF);
	prt_hz16_size(512-16*5*3/2-100,360, 5, 5, "欢", 0x00000, "HZK\\HZK16s");
	delay(200);
	prt_hz16_size(512-16*5/2,360, 5, 5, "迎", 0x00000, "HZK\\HZK16s");
	delay(200);
	prt_hz16_size(512+16*5/2+100,360, 5, 5, "您", 0x00000, "HZK\\HZK16s");
	delay(200);
	
	put_asc16_size(600,670,3,3,"by cjf and ylz",0x00000 );
	
	Circlefill(512-100,570, 5, 0x00000);
	delay(500);
	Circlefill(512,570, 5, 0x00000);
	delay(500);
	Circlefill(512+100,570, 5, 0x00000);
	delay(500);
	
	//delay(5000);
}