//#include "allfunc.h"
#include"SVGA.h"
#include"main.h"
void main()
{      
    int func=0;
    int unum=0;
	int snum=0;
	

    SetSVGA64k();//启动SVGA画图界面

    mouse_init();
	donghua();
    
	while(1)   
	{
        switch(func)
        {
            case 0:
            {
                welcome(&func);
                break;
            }
            case 1:								//用户注册
            {
                rigister_login(&func);
                break;
            }
			case 12:
			{
				xuanze(&func);					//选择用户身份
				break;
			}
            case 2:								
            {
                user_login(&func,&unum);		//用户登录
                break;
            }
			case 21:
			{
				student_login(&func,&unum);
				break;
			}
			case 22:
			{
				manager_login(&func,&unum);
				break;
			}
			case 31:							//用户主界面
			{
				user_main(&func,&unum);
				break;
			}
			case 32:							//学生主界面
			{
				stu_main(&func,&unum);		
				break;
			}
			case 33:							//管理员主界面
			{
				manager_main(&func);
				break;
			}
			case 4:
			{
				history(&func);			//管理员查看历史记录
				break;
			}
			case 41:
			{
				audit(&func);				//审核申请
				break;
			}
			case 42:							//数据分析
			{
				analyse(&func);
				break;
			}
			case 43:                            //管理员邮件系统
			{
				m_mail(&func);
				break;
			}
			 case 51:                           //普通访客登记信息
			 {
				 dengji(&func,&unum);
				 break;
			 }
			 case 52:                           //普通访客取消信息
			 {
				 can_dengji(&func,unum,&unum);
				 break;
			 }
			 case 53:                           //普通访客查看历史记录
			 {
				 story_user(&func,unum,&unum);
				 break;
		     }
			 case 54:                          //模拟进校系统
			 {
			     user_enter(&func,&unum,&func);
				 break;
			 }
	         case 61:                          //学生带人预约
			 {
				 dengji_stu(&func,&unum);
				 break;
			 }
			 case 62:                          //学生取消登记
			 {
			     can_dengji(&func,unum,&unum);
				 break;
			 }
			 case 63:                          //学生查看历史记录
			 {
			     story_user(&func,unum,&unum);
				 break;
		     }
        }
	}
	CloseSVGA();//关闭图形界面 
}

/*
mouse_off(&mouse);
mouse_on(mouse);
mouse_show(&mouse);

B3B5B6灰色--点亮
DC2DF1蓝绿--点亮
87CEFA浅蓝--底色
00FF深蓝--BC色
*/

