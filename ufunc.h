#ifndef _UFUNC_H_
#define _UFUNC_H_

typedef   struct
{
	char year[10];
	char month[5];
    char day[5];
	char hour[5];       // 添加小时字段
    char minute[5];     // 添加分钟字段
}DATE;  

typedef struct Visitor
{
	int bianhao;			//编号从1开始
    int dengji_user;
    char dengji_name[20];
	char dengji_id[20];
	int state_way;			//0为未记录，1为驾车，2为步行
	int state_xiaoqu;		//0为未记录，1为同济校区，2为主校区
	int user_stu;     		//0为游客，1为学生
	char tele[20];
	char dengji_year[10];
	char dengji_month[5];
	char dengji_date[5];
	int reason;                //记录来访原因，1为参观校园，2为探亲，3为其他
	char car_number[30];
	int condition;			//-1为未审批，0为不通过，1为通过,-2为用户取消
	int jin_xiao;			//0为没有，1为已进校
	char jin_month[10];//进校的日期
	char jin_day[10];		
	char jin_hour[10];		
	char jin_min[10];
	char cancel_year[10];
	char cancel_month[10];
	char cancel_day[10];
	char cpname[2][20];		//学生携带游客基本信息
	char cpid[2][20];
}Visitor;

typedef struct {
    Visitor *elem;         // 存储访客信息的数组
    int length;            // 当前访客信息的数量
    int listsize;          // 分配的存储空间大小
} VisitorList;

void drawdengbotton(int x1,int y1,char *s);
void get_time(DATE *p) ;
void JianTou(int x1,int y1,int x2,int y2,int x3,int y3,unsigned int color);

void InitVisitorList(VisitorList *VL);
void DestroyVisitorList(VisitorList *VL);
void VisitorListInsert(VisitorList *VL, Visitor visitor);
int save_visitor(VisitorList *VL, Visitor visitor);
void ReadAllVisitors(VisitorList *VL);
void SaveAllVisitors(VisitorList *VL);
int DeleteVisitor(VisitorList *VL, int index);
void UpdataVisitor(Visitor visitor);
int Visitorposition(VisitorList VL,Visitor e);
void DrawSector(int xc, int yc, int radius, int start_angle, int end_angle, unsigned int color);
void bianxie(int unum);

#endif
