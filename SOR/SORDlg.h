// SORDlg.h : ͷ�ļ�
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
///#define  MESSAGE(info) MessageBox(info,_T("��ʾ"),MB_OK|MB_ICONEXCLAMATION)//��ʾ�Ի���
//struct EventInfo //�¼�����Ϣ�ṹ��
//{
//	unsigned int index;//λ����������ĵڼ�����
//	unsigned int nEventType;//�¼�����0,��ʼ�¼���1�����¼���2�Ƿ����¼���3�����¼���4�����¼�//ʵ��ֻ��0/1
//	float fLocation;//�¼�λ��,(C/(2nf))*index,���ݵڼ������õ�����//2011.11.24
//	float fEventloss;//���//2011.11.24
//	float fEventHigh;////�¼��㷴��dB//2011.11.24
//	float fLineK;////����б��//2011.11.24
//	float fTotalLoss;////����ġ��ۼ����//2011.11.24
//	float fReflect;//����ֵ
//	float fTrailEnd;////β��λ��
//	char cEventType;// event code �ڶ������� A���û��Լӣ�M: E:����ĩ�ˣ�F:������в��ң�O:����������Χ�Ĺ���ĩ�� D: wcq2012.06.11//��ģ�飬ֻ�����ж���ʼ������
//};

// CSORDlg �Ի���
class CSORDlg : public CDialog
{
// ����
public:
	CSORDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CSORDlg();	//

// �Ի�������
	enum { IDD = IDD_SOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	CWinThread* m_pThread;
	HANDLE hEvent;//�øñ�������WaitForSingleObject����Sleep
	BOOL m_bContinue;//�Ƿ��˳��߳�
	BYTE m_data[100*1024];//100K
	vector<FLOAT> m_record;//
	vector<INT> m_recordInt;//
	CPoint *m_ptData; //��ͼ�����
	INT m_yMin;//y����Сֵ
	INT m_yMax;//y�����ֵ
	CUtil m_util;
	CSorFile m_sorfile;
	CSorFileBase m_sorfileBase;
	CSorFileBase m_sorfileBase2;
	CString m_fileName;
	TestResultInfo m_testResultInfo;
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//�����ȡsor�ļ� wcq2012.07.24
public:	
	CSorAssist m_sorAssist;//����ת������
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
	CRect m_rectCurve; //�������ߵľ�������
	CRect m_rectCoord; //���������ھ�������
	long int m_iStartLocation; //���λ�ã���λΪ(m)
	long int m_iMaxLocation; //ĩ��λ�ã���λ(m)
	unsigned int m_nStartPoint;  //���ߺ���������
	unsigned int m_nMaxPoint;    //���ߺ�������������ֵ
	CPoint *m_ptRecord; //��ͼ�����
	float m_fStartDB;    //������������ʼdb
	float m_fMaxDB;      //�������������ֵ
public:
	CString m_txtpath;//Ҫ���͵��ļ���ַ
public:
	INT* m_pOut;//���ݵ�
	INT  m_nDataCount;//���ݵ����
public:
	CSpinUtil m_SpinUtil;
public:
	Gabor_Result m_GaborResult;//�¼��б�
	float m_fAttenuation;//˥��ϵ��
	float m_fReflect;//����ϵ��
	float m_fFiberEnd;//����ĩ��
	float m_fScatteringCoefficient;//ɢ��ϵ��
	std::vector<EventInfo> m_vEventInfo; //
	COtdrTrace m_otdrTrace;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
