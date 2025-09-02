#include "allfunc.h"
#include "de_stu.h"
//#include "VLG.h"

void dengji_stu(int* func, int* unum)
{
    int t = 1,state_no=0; // visitor编号以及判断是否点击预约须知的确定按钮
    VisitorList VL;
    DATE a[5];
    Visitor temp;
    temp.state_way = 0;
    temp.state_xiaoqu = 0;
	
	strcpy(temp.cpname[0],"\0");
	strcpy(temp.cpid[0],"\0");
	strcpy(temp.cpname[1],"\0");
	strcpy(temp.cpid[1],"\0");
	
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
				prt_hz16_size(400, 650 + 70, 1, 1, "即将进入同伴登记！", 0x000000, "HZK\\HZK16s");
				delay(3000);
				stu_cp_dj(func,unum,&VL,&temp);
				break;
            }
        }
    }
}