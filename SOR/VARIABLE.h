//����һЩ����
#define COLOR_WHITE RGB(255,255,255)//��ɫ
///#define COLOR_DARKGREEN RGB(192,192,192)//����ɫ
#define COLOR_BLACK RGB(0,0,0)//��ɫ
#define COLOR_RED RGB(255,0,0)//��ɫ
#define COLOR_PURPLE RGB(128,0,128)//��ɫ
#define COLOR_YELLOW RGB(255,255,0)//��ɫ����ť�ı���ɫ
#define COLOR_GOLD RGB(255,215,0)//��ɫ,ѡ����Ŀ��ɫ
#define COLOR_BLUEVIOLET RGB(138,43,266)//������������ɫ
#define COLOR_SLATEBLUE RGB(106,90,205)//���Ұ�����ɫ
#define COLOR_DARKGREEN RGB(0,100,0)//����ɫ
#define COLOR_LOWNEEN RGB(124,252,0)//��ƺ��,ѡ����Ŀ��ɫ

#define COLOR_CURVE COLOR_DARKGREEN//������ɫ

//��Ϣ��ʾ��
#define MESSAGE(info) MessageBox(info,_T("��ʾ"),MB_OK|MB_ICONEXCLAMATION)//��ʾ�Ի���
#define MESSAGEYN(info) MessageBox(info,_T("��ʾ"),MB_YESNO|MB_ICONQUESTION)//��ʾ�Ի���,�������Ƿ�IDYES/IDNO
#define MESSAGEOC(info) MessageBox(info,_T("��ʾ"),MB_OKCANCEL|MB_ICONQUESTION)//��ʾ�Ի���,������ȷ��ȡ��IDOK/IDCANCEL
#define SET_CHECK(ID,bCheck) ((CButton*)this->GetDlgItem(ID))->SetCheck(bCheck)//check/radioѡ��
#define GET_CHECK(ID) ((CButton*)this->GetDlgItem(ID))->GetCheck()//check/radioѡ��
#define SET_TEXT(ID,STR) this->GetDlgItem(ID)->SetWindowTextW(STR)//check/radioѡ��
#define GET_TEXT(ID,STR) this->GetDlgItem(ID)->GetWindowTextW(STR)//check/radioѡ��
#define ENABLE_ID(ID,bEn) (this->GetDlgItem(ID)->EnableWindow(bEn))//check/radioѡ��
#define SHOW_ID(ID) (this->GetDlgItem(ID)->ShowWindow(SW_SHOW))//��ʾ
#define HIDE_ID(ID) (this->GetDlgItem(ID)->ShowWindow(SW_HIDE))//����