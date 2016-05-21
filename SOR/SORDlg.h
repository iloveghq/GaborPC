// SORDlg.h : 头文件
//

#pragma once
#include <map>
#include <vector>
#include "afxwin.h"
#include "Util.h"
#include "SorFile.h"
#include "SorFileBase.h"
#include "SorAssist.h"
#include "SORDATA.h"
#include "Filter.h"
#include "otdrtrace.h"
#include "SpinUtil.h"
#include "../gabor_dll/GaborResult.h"
#include "c:\program files\microsoft visual studio 8\vc\ce\atlmfc\include\afxcmn.h"
using namespace std;
///#define  MESSAGE(info) MessageBox(info,_T("提示"),MB_OK|MB_ICONEXCLAMATION)//提示对话框
//struct EventInfo //事件点信息结构体
//{
//	unsigned int index;//位于数据数组的第几个点
//	unsigned int nEventType;//事件类型0,开始事件，1反射事件，2非反射事件，3反射事件，4结束事件//实际只有0/1
//	float fLocation;//事件位置,(C/(2nf))*index,根据第几点计算得到距离//2011.11.24
//	float fEventloss;//损耗//2011.11.24
//	float fEventHigh;////事件点反射dB//2011.11.24
//	float fLineK;////区段斜率//2011.11.24
//	float fTotalLoss;////总损耗、累计损耗//2011.11.24
//	float fReflect;//反射值
//	float fTrailEnd;////尾端位置
//	char cEventType;// event code 第二个参数 A：用户自加；M: E:光纤末端；F:软件自行查找；O:超出测量范围的光纤末端 D: wcq2012.06.11//对模块，只用来判断起始、结束
//};

// CSORDlg 对话框
class CSORDlg : public CDialog
{
// 构造
public:
	CSORDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CSORDlg();	//

// 对话框数据
	enum { IDD = IDD_SOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	CWinThread* m_pThread;
	HANDLE hEvent;//用该变量控制WaitForSingleObject代替Sleep
	BOOL m_bContinue;//是否退出线程
	BYTE m_data[100*1024];//100K
	vector<FLOAT> m_record;//
	vector<INT> m_recordInt;//
	CPoint *m_ptData; //画图坐标点
	INT m_yMin;//y轴最小值
	INT m_yMax;//y轴最大值
	CUtil m_util;
	CSorFile m_sorfile;
	CSorFileBase m_sorfileBase;
	CSorFileBase m_sorfileBase2;
	CString m_fileName;
	TestResultInfo m_testResultInfo;
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//方便读取sor文件 wcq2012.07.24
public:	
	CSorAssist m_sorAssist;//用于转换两种
	SORDATA    m_sorDATA;//
	CFilter m_filter;
	BOOL m_bDeal;
	/////////////////////////////////////////////////////////////////////////////////////////////////
public:
	void OnOK();
	void decode();
	void decodeOtdrTrace();
	void drawData();
	void CalCulDispRect();
	void DrawCoord(CDC *pDC);
	void DrawCurve(CDC *pDC);
	void saveData();
	void recordToPoint();
	void OnSpin(UINT nID);
	void SetEditText(UINT nEditID, INT nAdd, INT nPrecision = 0);
	void InitParams();
	void InitParamsCurve();
	void RefreshParams();
	void RefreshParamsCurve();
	void InitList();
public:
	CRect m_rectCurve; //绘制曲线的矩形区域
	CRect m_rectCoord; //坐标轴以内矩形区域
	long int m_iStartLocation; //起点位置，单位为(m)
	long int m_iMaxLocation; //末点位置，单位(m)
	unsigned int m_nStartPoint;  //曲线横坐标的起点
	unsigned int m_nMaxPoint;    //曲线横坐标点数的最大值
	CPoint *m_ptRecord; //画图坐标点
	float m_fStartDB;    //曲线纵坐标起始db
	float m_fMaxDB;      //曲线纵坐标最大值
public:
	CString m_txtpath;//要发送的文件地址
public:
	INT* m_pOut;//数据点
	INT  m_nDataCount;//数据点个数
public:
	CSpinUtil m_SpinUtil;
public:
	Gabor_Result m_GaborResult;//事件列表
	float m_fAttenuation;//衰减系数
	float m_fReflect;//反射系数
	float m_fFiberEnd;//光纤末端
	float m_fScatteringCoefficient;//散射系数
	std::vector<EventInfo> m_vEventInfo; //
	COtdrTrace m_otdrTrace;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedRead();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedSave2();
	afx_msg void OnBnClickedRead2();
	afx_msg void OnBnClickedRead3();
	afx_msg void OnBnClickedSave3();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDeltaposMySpin8(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnDeltaposMySpin16(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin9(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin10(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin11(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin12(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin13(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin14(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin15(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDefault();
	afx_msg void OnDeltaposMySpin19(NMHDR *pNMHDR, LRESULT *pResult);
	void GetEventList(WORD* pDataPoints);
	void GaborResultToEvent();
	void ConvertEvent();
	afx_msg void OnDeltaposMySpin21(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDefault2();
	afx_msg void OnDeltaposMySpin23(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin25(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposMySpin27(NMHDR *pNMHDR, LRESULT *pResult);
	void FreshEventList();
	CListCtrl m_list;
	afx_msg void OnBnClickedButOtdrTrace();
};
