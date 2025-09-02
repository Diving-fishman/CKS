#ifndef _M_FUNC_H_
#define _M_FUNC_H_

void history (int *func);
void audit(int *func);
void analyse(int *func);
void draw_history(int x,int y, int xr,int yr);
void draw_audit(void);
void draw_analyse(int n);
void Light_manager_func(int tag);
void Dark_manager_func(int tag);
void draw_bg(Visitor *visitor,int flag);
void draw_tg(int tag);
void draw_info(int x,int y, int xr,int yr,Visitor *p,int flag);
int reserve_num (int n,DATE *a);
int  can_rate(int n,DATE *a);
int pass_rat(int n,DATE *a);
int xiaowai_rate(int n,DATE *a);
int car_num (int n,DATE *a);
int zhuxq_rate(int n,DATE *a);
void draw_jintime(int n,DATE *a);
void draw_reason(int n,DATE *a);
#endif