//定义一些变量
#define COLOR_WHITE RGB(255,255,255)//白色
///#define COLOR_DARKGREEN RGB(192,192,192)//银白色
#define COLOR_BLACK RGB(0,0,0)//黑色
#define COLOR_RED RGB(255,0,0)//红色
#define COLOR_PURPLE RGB(128,0,128)//紫色
#define COLOR_YELLOW RGB(255,255,0)//黄色，按钮文本颜色
#define COLOR_GOLD RGB(255,215,0)//金色,选中条目颜色
#define COLOR_BLUEVIOLET RGB(138,43,266)//深紫罗兰的蓝色
#define COLOR_SLATEBLUE RGB(106,90,205)//板岩暗蓝灰色
#define COLOR_DARKGREEN RGB(0,100,0)//深绿色
#define COLOR_LOWNEEN RGB(124,252,0)//草坪绿,选中条目颜色

#define COLOR_CURVE COLOR_DARKGREEN//曲线颜色

//信息提示框
#define MESSAGE(info) MessageBox(info,_T("提示"),MB_OK|MB_ICONEXCLAMATION)//提示对话框
#define MESSAGEYN(info) MessageBox(info,_T("提示"),MB_YESNO|MB_ICONQUESTION)//提示对话框,上面有是否IDYES/IDNO
#define MESSAGEOC(info) MessageBox(info,_T("提示"),MB_OKCANCEL|MB_ICONQUESTION)//提示对话框,上面有确定取消IDOK/IDCANCEL
#define SET_CHECK(ID,bCheck) ((CButton*)this->GetDlgItem(ID))->SetCheck(bCheck)//check/radio选中
#define GET_CHECK(ID) ((CButton*)this->GetDlgItem(ID))->GetCheck()//check/radio选中
#define SET_TEXT(ID,STR) this->GetDlgItem(ID)->SetWindowTextW(STR)//check/radio选中
#define GET_TEXT(ID,STR) this->GetDlgItem(ID)->GetWindowTextW(STR)//check/radio选中
#define ENABLE_ID(ID,bEn) (this->GetDlgItem(ID)->EnableWindow(bEn))//check/radio选中
#define SHOW_ID(ID) (this->GetDlgItem(ID)->ShowWindow(SW_SHOW))//显示
#define HIDE_ID(ID) (this->GetDlgItem(ID)->ShowWindow(SW_HIDE))//隐藏