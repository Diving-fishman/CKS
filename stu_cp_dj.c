#include "allfunc.h"
#include "stu_cpdj.h"
#include "lgfunc.h"

void stu_cp_dj(int* func, int* unum, VisitorList* VL, Visitor* temp)
{
    FILE* fp = fopen("visitorinfo.dat", "wb");
    int i = 0, dj_number, t = 1; // 记录登记同伴数

    mouse_off(&mouse);
    draw_stu_cp_dj();
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);
        if (mouse_press(15, 10, 120 + 48 * 2, 90) == 1)
        {
            *func = 32; // 返回上一页
            break;
        }

        // 游客姓名输入
        if (mouse_press(250, 200 + 0 * 65, 900, 200 + 0 * 65 + 65) == 1)
        {
            mouse_off(&mouse);
            strcpy(temp->cpname[0], "\0");
            bar1(250, 200 + 0 * 65, 900, 200 + 0 * 65 + 65, 0x87CEFA);
            Getinfo(300, 200 + 0 * 65, temp->cpname[0], 20, 300, 200 + 0 * 65, 900, 200 + 0 * 65 + 60);
            mouse_on(mouse);
        }

        // 游客姓名输入
        if (mouse_press(250, 200 + 2 * 65, 900, 200 + 2 * 65 + 65) == 1)
        {
            mouse_off(&mouse);
            strcpy(temp->cpname[1], "\0");
            bar1(250, 200 + 2 * 65, 900, 200 + 2 * 65 + 65, 0x87CEFA);
            Getinfo(300, 200 + 2 * 65, temp->cpname[1], 20, 300, 200 + 2 * 65, 900, 200 + 2 * 65 + 60);
            mouse_on(mouse);
        }

        // 游客身份证号输入
        if (mouse_press(250, 200 + 0 * 65 + 66, 900, 200 + 1 * 65 + 66 + 65) == 1)
        {
            mouse_off(&mouse);
            strcpy(temp->cpid[0], "\0");
            bar1(250, 200 + 0 * 65 + 66, 900, 200 + 1 * 65 + 66 + 65, 0x87CEFA);
            Getinfo(300, 200 + 0 * 66 + 66, temp->cpid[0], 18, 300, 200 + 0 * 66 + 66, 900, 200 + 1 * 66 + 66 + 60);
            mouse_on(mouse);
        }

        if (mouse_press(250, 200 + 2 * 65 + 66, 900, 200 + 2 * 65 + 66 + 65) == 1)
        {
            mouse_off(&mouse);
            strcpy(temp->cpid[1], "\0");
            bar1(250, 200 + 2 * 65 + 66, 900, 200 + 2 * 65 + 66 + 65, 0x87CEFA);
            Getinfo(300, 200 + 2 * 66 + 66, temp->cpid[1], 18, 300, 200 + 2 * 66 + 66, 900, 200 + 2 * 66 + 66 + 60);
            mouse_on(mouse);
        }

        // 确认登记按钮
        if (mouse_press(400, 650, 600, 690) == 1)
        {
            if (strcmp(temp->cpname[0], "\0") == 0 && strcmp(temp->cpname[1], "\0") == 0)
            {
                prt_hz16_size(300, 720, 2, 2, "至少输入一个姓名！", 0xFF0000, "HZK\\HZK16s");
				delay(2000);
				bar1(300,720,800,900,0x87CEFA);
				
            }
            else if (strcmp(temp->cpid[0], "\0") == 0 && strcmp(temp->cpid[1], "\0") == 0)
            {
                prt_hz16_size(300, 720, 2, 2, "至少输入一个身份证号！", 0xFF0000, "HZK\\HZK16s");
				delay(2000);
				bar1(300,720,800,900,0x87CEFA);
            }
            else if (( strcmp(temp->cpname[0], "\0") == 0 &&strcmp(temp->cpid[0] , "\0") != 0  )|| ( strcmp(temp->cpid[0] , "\0") != 0  && strcmp(temp->cpid[0], "\0") == 0) ||
                     (strcmp(temp->cpname[1], "\0") == 0 && strcmp(temp->cpid[1], "\0") != 0 ) || (strcmp(temp->cpname[1] , "\0") != 0 && strcmp(temp->cpid[1], "\0") == 0))
            {
                prt_hz16_size(300, 720, 2, 2, "请输入完整信息！", 0xFF0000, "HZK\\HZK16s");
				delay(2000);
				bar1(300,720,800,900,0x87CEFA);
            }
            else
            {
			    temp->dengji_user = *unum;
                temp->user_stu = 1;
                temp->bianhao = t++;
                temp->condition = -1;

                if (save_visitor(VL, *temp) == 0)
                {
                    prt_hz16_size(400, 650 + 70, 2, 2, "登记成功，请记得及时到访！", 0x000000, "HZK\\HZK16s");
                    delay(3000);
                    *func = 32;
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
    DestroyVisitorList(VL);
}

void draw_stu_cp_dj(void)
{
    // 清屏
    bar1(0, 0, 1023, 767, 0x87CEFA);

    // 绘制标题
    JianTou(15, 50, 60, 10, 115, 30, 0x000000);
    prt_hz16_size(120, 50 - 16 * 3 / 2, 3, 3, "学生信息登记", 0x000000, "HZK\\HZK16s");
	
	// 调整提示信息的打印位置，使其与输入框对齐
	prt_hz16_size(50, 200 + 0 * 65, 2, 2, "游客姓名", 0x000000, "HZK\\HZK16s");
	Line_Thick(290, 200 + 0 * 65+60, 900, 200 + 0 * 65+60, 1, 0xBD32);
	prt_hz16_size(50,200 + 1 * 65 , 2, 2, "身份证号", 0x000000, "HZK\\HZK16s");
	Line_Thick(290, 200 + 1 * 65+60, 900, 200 + 1 * 65+60, 1, 0xBD32);
	prt_hz16_size(50, 200 + 2 * 65, 2, 2, "游客姓名", 0x000000, "HZK\\HZK16s");
	Line_Thick(290, 200 + 2 * 65+60, 900, 200 + 2 * 65+60, 1, 0xBD32);
	prt_hz16_size(50,200 + 3 * 65 , 2, 2, "身份证号", 0x000000, "HZK\\HZK16s");
	Line_Thick(290, 200 + 3 * 65+60, 900, 200 + 3 * 65+60, 1, 0xBD32);


    drawdengbotton(400, 650, "确认登记");
}