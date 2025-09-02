#include "allfunc.h"
#include "dengji.h"
//#include "VLG.h"

void dengji(int* func, int* unum)
{
    int t = 1,state_no=0; // visitor编号以及判断是否点击预约须知的确定按钮
    VisitorList VL;
    DATE a[5];
    Visitor temp;
    temp.state_way = 0;
    temp.state_xiaoqu = 0;
	strcpy(temp.car_number,"\0");

    InitVisitorList(&VL);

    // 读取所有访客信息
    ReadAllVisitors(&VL);

    get_time(a);
    mouse_off(&mouse);
    draw_dengji(a);
    draw_notice();
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);
		
		if (mouse_press(430,220+50+20+50+20+50+20+50,570,220+50+20+50+20+50+20+50+60) == 1&&state_no==0)//检测是否点击预约确定
		{
			mouse_off(&mouse);
			draw_dengji(a);
			mouse_on(mouse);
			state_no=1;
		}

        if (mouse_press(15, 10, 120 + 48 * 2, 90) == 1)//当点击返回时
        {
            *func = 31;
            break;
        }
        if (mouse_press(250, 200 - 66, 900, 200 + 65 - 66) == 1)//输入登记姓名
        {
            mouse_off(&mouse);
            strcpy(temp.dengji_name, "\0");
            bar1(250, 200 - 65, 900, 200, 0x87CEFA);
            Getinfo(300, 200 - 65, temp.dengji_name, 10, 300, 200 - 65, 900, 200 - 65 + 48);
            Line_Thick(290, 200 - 65 + 60, 900, 200 - 65 + 60, 1, 0xBD32);
            mouse_on(mouse);
        }
        if (mouse_press(250, 200, 900, 200 + 65) == 1)//输入登记身份证号
        {
            mouse_off(&mouse);
            strcpy(temp.dengji_id, "\0");
            bar1(290, 200, 900, 200 + 65, 0x87CEFA);
            Getinfo(300, 200, temp.dengji_id, 18, 300, 200, 900, 189 + 66);
            Line_Thick(290, 200 + 60, 900, 200 + 60, 1, 0xBD32);
            mouse_on(mouse);
        }
        if (mouse_press(300, 200 + 66, 300 + 40, 200 + 66 + 40) == 1) // 选择步行
        {
            mouse_off(&mouse);
			bar1(250, 200 + 65 * 5 + 66, 900, 200 + 65 * 7, 0x87CEFA);
            Circlefill(300 + 20, 200 + 66 + 20, 10, 0x00FF);
            Circlefill(300 + 20 + 300, 200 + 66 + 20, 10, 0x87CEFA);
            mouse_on(mouse);
            mouse_show(&mouse);
            bar1(50, 200 + 65 * 6, 700, 200 + 65 * 6 + 50, 0x87CEFA);
            temp.state_way = 2;
        }
        if (mouse_press(300 + 300, 200 + 66, 300 + 300 + 40, 200 + 66 + 40) == 1) // 选择驾车
        {
            mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 + 20, 10, 0x87CEFA);
            Circlefill(300 + 20 + 300, 200 + 66 + 20, 10, 0x00FF);
            mouse_on(mouse);
            mouse_show(&mouse);
            prt_hz16_size(50, 200 + 65 * 6, 2, 2, "车牌号", 0x000000, "HZK\\HZK16s");
            Line_Thick(290, 200 + 65 * 6 + 60, 900, 200 + 65 * 6 + 60, 1, 0xBD32);
            temp.state_way = 1;
        }
        if (mouse_press(300, 200 + 66 * 2, 300 + 40, 200 + 66 * 2 + 40) == 1) // 选择主校区
        {
            mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 * 2 + 20, 10, 0x00FF);
            Circlefill(300 + 20 + 300, 200 + 66 * 2 + 20, 10, 0x87CEFA);
            mouse_on(mouse);
            mouse_show(&mouse);
            temp.state_xiaoqu = 2;
        }
        if (mouse_press(300 + 300, 200 + 66 * 2, 300 + 300 + 40, 200 + 66 * 2 + 40) == 1) // 选择同济校区
        {
            mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 * 2 + 20, 10, 0x87CEFA);
            Circlefill(300 + 20 + 300, 200 + 66 * 2 + 20, 10, 0x00FF);
            mouse_on(mouse);
            mouse_show(&mouse);
            temp.state_xiaoqu = 1;
        }
        if (mouse_press(300, 200 + 65 * 2 + 66, 300 + 40, 200 + 65 * 4) == 1) // 选择今天进校
        {
            mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 * 3 + 20, 10, 0x00FF);
            Circlefill(300 + 20 + 300, 200 + 66 * 3 + 20, 10, 0x87CEFA);
            mouse_on(mouse);
            mouse_show(&mouse);
			strcpy(temp.dengji_year,a[0].year);
            strcpy(temp.dengji_month,a[0].month);
            strcpy(temp.dengji_date,a[0].day);
        }
        if (mouse_press(300 + 300, 200 + 65 * 2 + 66, 300 + 300 + 40, 200 + 65 * 4) == 1) // 选择第二天进校
        {
            mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 * 3 + 20, 10, 0x87CEFA);
            Circlefill(300 + 20 + 300, 200 + 66 * 3 + 20, 10, 0x00FF);
            mouse_on(mouse);
            mouse_show(&mouse);
            strcpy(temp.dengji_year,a[1].year);
            strcpy(temp.dengji_month,a[1].month);
            strcpy(temp.dengji_date,a[1].day);
        }
        if (mouse_press(300 , 200 + 65 * 3 + 66, 300 + 40, 200 + 65 * 5) == 1) // 选择参观校园
		{
		    mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 + 20 + 66 + 66 +66 , 10, 0x00FF);
            Circlefill(300 + 20 + 200 , 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x87CEFA);
			Circlefill(300 + 20 + 400 , 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x87CEFA);
            mouse_on(mouse);
            mouse_show(&mouse);
			temp.reason=1;
		}
		 if (mouse_press(300 + 200 , 200 + 65 * 3 + 66, 300 + 200 + 40, 200 + 65 * 5) == 1) // 选择探亲
		{
		    mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x87CEFA);
            Circlefill(300 + 20 + 200 , 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x00FF);
			Circlefill(300 + 20 + 400 , 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x87CEFA);
            mouse_on(mouse);
            mouse_show(&mouse);
			temp.reason=2;
		}
		 if (mouse_press(300 + 400 , 200 + 65 * 3 + 66, 300 + 400 + 40, 200 + 65 * 5) == 1) // 选择其他
		{
		    mouse_off(&mouse);
            Circlefill(300 + 20, 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x87CEFA);
            Circlefill(300 + 20 + 200 , 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x87CEFA);
			Circlefill(300 + 20 + 400 , 200 + 66 + 20 + 66 + 66 + 66 , 10, 0x00FF);
            mouse_on(mouse);
            mouse_show(&mouse);
			temp.reason=3;
		}
		 if (mouse_press(250, 200 + 65 * 4 + 66, 900, 200 + 65 * 6) == 1) // 输入电话
        {
            mouse_off(&mouse);
            strcpy(temp.tele, "\0");
            bar1(250, 200 + 65 * 4 + 66, 900, 200 + 65 * 6, 0x87CEFA);
            Getinfo(300, 200 + 65 * 4 + 66, temp.tele, 11, 300, 200 + 65 * 4 + 66, 900, 189 + 65 * 5 + 60);
            Line_Thick(290, 200 + 65 * 5 + 60, 900, 200 + 65 * 5 + 60, 1, 0xBD32);
            mouse_on(mouse);
        }
		if (mouse_press(250, 200 + 65 * 5 + 66, 900, 200 + 65 * 7) == 1&&temp.state_way==1) // 输入车牌号
        {
            mouse_off(&mouse);
            strcpy(temp.car_number, "\0");
            bar1(250, 200 + 65 * 5 + 66, 900, 200 + 65 * 7, 0x87CEFA);
            Getinfo(300, 200 + 65 * 5 + 66, temp.car_number, 100, 300, 200 + 65 * 5 + 66, 900, 200 + 65 * 7);
            Line_Thick(290, 200 + 65 * 6 + 60, 900, 200 + 65 * 6 + 60, 1, 0xBD32);
            mouse_on(mouse);
        }
        if (mouse_press(400, 650 + 10, 400 + 240, 650 + 55 + 10) == 1) // 点击确认按钮
        {
            if (strcmp(temp.dengji_name, "\0") == 0)  // 检查姓名是否为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "姓名不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if (strcmp(temp.dengji_id, "\0") == 0)  // 检查身份证号是否为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "身份证号不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if (strcmp(temp.tele, "\0") == 0)  // 检查电话是否为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "电话不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if ( strcmp(temp.dengji_year, "\0") == 0|| strcmp(temp.dengji_month, "\0") == 0 || strcmp(temp.dengji_date, "\0") == 0)  // 检查日期是否为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "日期不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if (temp.reason==0)  // 检查来访事由是否为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "来访事由不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if (temp.state_way == 0)  // 检查交通方式是否已选择
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "交通方式不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if (temp.state_way == 1 && strcmp(temp.car_number, "\0") == 0)  // 如果选择驾车但车牌号为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "车牌号不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else if (temp.state_xiaoqu == 0)  // 检查校区选择是否为空
            {
                prt_hz24(512 - 7 * 16 / 2, 720, "校区选择不能为空！", 0, "HZK\\Hzk24h");
                delay(500);
                bar1(200, 720, 1000, 767, 0x87CEFA);
            }
            else
            {
			    temp.dengji_user = *unum;
                temp.user_stu = 0;
                temp.bianhao = t++;
                temp.condition = -1;
				temp.jin_xiao=0;
				
				strcpy(temp.cpname[0],"\0");
				strcpy(temp.cpid[0],"\0");
				strcpy(temp.cpname[1],"\0");
				strcpy(temp.cpid[1],"\0");

                if (save_visitor(&VL, temp) == 0)
                {
                    prt_hz16_size(400, 650 + 70, 1, 1, "登记成功，请记得及时到访！", 0x000000, "HZK\\HZK16s");
                    delay(3000);
                    *func = 31;
                    break;
                }
                else
                {
                    prt_hz24(512 - 7 * 16 / 2, 720, "登记失败，请重试！", 0, "HZK\\Hzk24h");
                    delay(500);
                    bar1(200, 720, 1000, 767, 0x87CEFA);
                }
            }
        }
    }
    DestroyVisitorList(&VL);
}

void draw_dengji(DATE* p)
{
    // 清屏
    bar1(0, 0, 1023, 767, 0x87CEFA);

    // 绘制标题
    JianTou(15, 50, 60, 10, 115, 30, 0x000000);
    prt_hz16_size(120, 50 - 16 * 3 / 2, 3, 3, "返回", 0x000000, "HZK\\HZK16s");

    // 绘制各输入框标题
    prt_hz16_size(50, 200 - 65, 2, 2, "登记姓名", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 - 65 + 60, 900, 200 - 65 + 60, 1, 0xBD32);
    prt_hz16_size(50, 200, 2, 2, "登记身份证号", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 + 60, 900, 200 + 60, 1, 0xBD32);
    prt_hz16_size(50, 200 + 65, 2, 2, "交通方式", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 + 65 + 60, 900, 200 + 65 + 60, 1, 0xBD32);
    prt_hz16_size(50, 200 + 65 * 2, 2, 2, "校区选择", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 + 65 * 2 + 60, 900, 200 + 65 * 2 + 60, 1, 0xBD32);
    prt_hz16_size(50, 200 + 65 * 3, 2, 2, "登记日期", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 + 65 * 3 + 60, 900, 200 + 65 * 3 + 60, 1, 0xBD32);
    prt_hz16_size(50, 200 + 65 * 4, 2, 2, "来访事由", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 + 65 * 4 + 60, 900, 200 + 65 * 4 + 60, 1, 0xBD32);
	 prt_hz16_size(50, 200 + 65 * 5, 2, 2, "来访电话", 0x000000, "HZK\\HZK16s");
    Line_Thick(290, 200 + 65 * 5 + 60, 900, 200 + 65 * 5 + 60, 1, 0xBD32);

    // 绘制交通方式选项
    Circle(300 + 20, 200 + 66 + 20, 20, 0x00FF);
    prt_hz16_size(450, 200 + 66, 2, 2, "步行", 0x000000, "HZK\\HZK16s");
    Circle(300 + 20 + 300, 200 + 66 + 20, 20, 0x00FF);
    prt_hz16_size(450 + 300, 200 + 66, 2, 2, "驾车", 0x000000, "HZK\\HZK16s");

    // 绘制校区选择选项
    Circle(300 + 20, 200 + 66 + 20 + 66, 20, 0x00FF);
    prt_hz16_size(450, 200 + 66 * 2, 2, 2, "主校区", 0x000000, "HZK\\HZK16s");
    Circle(300 + 20 + 300, 200 + 66 + 20 + 66, 20, 0x00FF);
    prt_hz16_size(450 + 300, 200 + 66 * 2, 2, 2, "同济校区", 0x000000, "HZK\\HZK16s");

    // 绘制日期选择选项
    Circle(300 + 20, 200 + 66 + 20 + 66 + 66, 20, 0x00FF);
    put_asc16_size( 360, 200 + 65 * 3,2,2,p[0].year,0x000000);
	put_asc16_size( 360+80, 200 + 65 * 3,2,2,p[0].month,0x000000);
	put_asc16_size( 360+80+30, 200 + 65 * 3,2,2,p[0].day,0x000000);
    Circle(300 + 20 + 300, 200 + 66 + 20 + 66 + 66, 20, 0x00FF);
    put_asc16_size(360 + 300, 200 + 66 * 3 ,2,2,p[1].year,0x000000);
	put_asc16_size( 360 + 300+80, 200 + 66 * 3,2,2,p[1].month,0x000000);
	put_asc16_size( 360 + 300+80+30, 200 + 66 * 3,2,2,p[1].day,0x000000);
	
	// 绘制事由选择选项
    Circle(300 + 20, 200 + 66 + 20 + 66 + 66 + 66 , 20, 0x00FF);
    prt_hz16_size(300+50, 200 + 66 + 20 + 66 + 66 + 66  , 2, 2, "参观校园", 0x000000, "HZK\\HZK16s");
    Circle(300 + 20 + 200, 200 + 66 + 20 + 66 + 66 + 66 , 20, 0x00FF);
    prt_hz16_size(300+250, 200 + 66 + 20 + 66 + 66 + 66 , 2, 2, "探亲", 0x000000, "HZK\\HZK16s");
	Circle(300 + 20 + 400, 200 + 66 + 20 + 66 + 66 + 66 , 20, 0x00FF);
    prt_hz16_size(300+450, 200 + 66 + 20 + 66 + 66 + 66 , 2, 2, "其他", 0x000000, "HZK\\HZK16s");


    // 绘制确认按钮
    drawdengbotton(400, 650 + 10, "确认登记");
}

void draw_notice(void)
{
     bar2(200,100,800,600,0x000000);
     bar1(200,100,800,600,0xFFFF);
	 
	 prt_hz16_size(430,120,2,2,"预约须知",0x000000,"HZK\\HZK16s");
	 
	 prt_hz16_size(250,200,1,1,"自觉遵守华中科技大学校园管理制度，自愿按",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220,1,1,"按照要求办理进校申请手续；",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220+50,1,1,"严格遵守中央、省、市、区和学校疫情防控规",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220+50+20,1,1,"定和要求；",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220+50+20+50,1,1,"本人真实填报所有信息，如有虚假信息，由本",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220+50+20+50+20,1,1,"人（申报人）承担相应责任并接受处理；",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220+50+20+50+20+50,1,1,"持本人身份证，确保与预约申请内容一致，刷",0x000000,"HZK\\HZK16s");
	 prt_hz16_size(250,220+50+20+50+20+50+20,1,1,"身份证通行。",0x000000,"HZK\\HZK16s");
	 
	 Cirbar(430,220+50+20+50+20+50+20+50,570,220+50+20+50+20+50+20+50+60,0x000000);
	 prt_hz16_size(480,220+50+20+50+20+50+20+50,2,2,"确认",0x00ff,"HZK\\HZK16s");
}