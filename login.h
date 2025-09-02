#ifndef _LOGIN_H_
#define _LOGIN_H_

void rigister_login(int *func);
void draw_rigister_login(void);
void draw_user_login(void);
void draw_commoninput(int x1,int y1,char *s);
void draw_confirmbotton(int x1,int y1,char *s,unsigned int color1,unsigned int color2);
void user_login(int *func,int *unum);
void student_login(int *func,int *unum);
void manager_login(int *func,int *unum);
void draw_student_login(void);
void draw_manager_login(void);
void Light_login(int tag);
void Dark_login(int tag);


#endif