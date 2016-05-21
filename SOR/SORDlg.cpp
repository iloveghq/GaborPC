// SORDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SOR.h"
#include "SORDlg.h"
#include "Filter.h"
#include "../gabor_dll/gabordllFun.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSORDlg �Ի���




CSORDlg::CSORDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSORDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_yMin=0;//y����Сֵ
	m_yMax=65;//y�����ֵ
	m_ptData=NULL;
	m_testResultInfo.pDataPoints=NULL;
	m_pOut=NULL;
	m_nDataCount = 0;
	m_pThread = NULL;
	m_bDeal = FALSE;
	m_fAttenuation = 0;//˥��ϵ��
	m_fReflect = 0;//����ϵ��
	m_fFiberEnd = 0;//����ĩ��
	m_fScatteringCoefficient = 0;//ɢ��ϵ��
}

CSORDlg::~CSORDlg()
{
	if (NULL != m_pOut)
	{
		delete m_pOut;
	}
}
void CSORDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUT_OTDR_TRACE, m_otdrTrace);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CSORDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CSORDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CSORDlg::OnBnClickedButton1)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_READ, &CSORDlg::OnBnClickedRead)
	ON_BN_CLICKED(IDC_SAVE, &CSORDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_SAVE2, &CSORDlg::OnBnClickedSave2)
	ON_BN_CLICKED(IDC_READ2, &CSORDlg::OnBnClickedRead2)
	ON_BN_CLICKED(IDC_READ3, &CSORDlg::OnBnClickedRead3)
	ON_BN_CLICKED(IDC_SAVE3, &CSORDlg::OnBnClickedSave3)
	ON_WM_SIZE()	
	//ON_COMMAND_RANGE(IDC_MY_SPIN8,IDC_MY_SPIN16, &CSORDlg::OnSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN8, &CSORDlg::OnDeltaposMySpin8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN16, &CSORDlg::OnDeltaposMySpin16)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN9, &CSORDlg::OnDeltaposMySpin9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN10, &CSORDlg::OnDeltaposMySpin10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN11, &CSORDlg::OnDeltaposMySpin11)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN12, &CSORDlg::OnDeltaposMySpin12)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN13, &CSORDlg::OnDeltaposMySpin13)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN14, &CSORDlg::OnDeltaposMySpin14)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN15, &CSORDlg::OnDeltaposMySpin15)
	ON_BN_CLICKED(IDC_DEFAULT, &CSORDlg::OnBnClickedDefault)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN19, &CSORDlg::OnDeltaposMySpin19)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN21, &CSORDlg::OnDeltaposMySpin21)
	ON_BN_CLICKED(IDC_DEFAULT2, &CSORDlg::OnBnClickedDefault2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN23, &CSORDlg::OnDeltaposMySpin23)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN25, &CSORDlg::OnDeltaposMySpin25)
	ON_NOTIFY(UDN_DELTAPOS, IDC_MY_SPIN27, &CSORDlg::OnDeltaposMySpin27)
	ON_BN_CLICKED(IDC_BUT_OTDR_TRACE, &CSORDlg::OnBnClickedButOtdrTrace)
END_MESSAGE_MAP()


// CSORDlg ��Ϣ�������

BOOL CSORDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//this->GetDlgItem(IDC_START)->SetWindowText(_T("130"));
	//this->GetDlgItem(IDC_FILENAME)->SetWindowText(_T("E:\\�³�������ļ���\\��־��\\SOR\\FILE_003.SOR"));
	m_SpinUtil.m_pDlg = this;
	InitParams();
	InitParamsCurve();
	RefreshParamsCurve();
	InitList();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSORDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSORDlg::OnPaint()
{
	////TRACE(_T("OnPaint::1\n"));
	//CPaintDC dc(this);

	//////ʹ��˫���弼����ͼ
	////CRect ClientRect;
	////GetClientRect(&ClientRect);

	////CRect InvalidRect;
	////dc.GetClipBox(&InvalidRect); //��ȡ��Ч��,����Ҫ�ػ������

	////CDC MemDC;
	////CBitmap MemBitMap;
	////CBitmap *pOldBitMap;

	//////����һ����dc���ݵ��ڴ��ڴ��豸����
	////if (MemDC.CreateCompatibleDC(&dc))
	////{
	////	//����һ����dc���ݵ�λͼ����СΪ�����ͻ���
	////	if (MemBitMap.CreateCompatibleBitmap(&dc,ClientRect.Width(),ClientRect.Height()))
	////	{
	////		//��λͼѡ���ڴ滷��
	////		pOldBitMap=MemDC.SelectObject(&MemBitMap);

	////		//ʹMemDC�������ͻ���������Ч��
	////		MemDC.SelectClipRgn(NULL);
	////		//�� "����" ��ȡ����Ч����ʹ�ڴ滷����dc��ȡ����Ч�����
	////		MemDC.IntersectClipRect(InvalidRect);

	////		//�ñ���ɫ��λͼ����ɾ�
	////		MemDC.FillSolidRect(&ClientRect,RGB(236,233,216));
	////	}

	////}

	////CalCulDispRect();
	////DrawCoord(&MemDC);
	////DrawCurve(&MemDC);
	////////DrawLineAB(&MemDC);

	////////if (m_bReceiveResultOK && m_bReadFromFile) //�����������ͬʱ���ڣ�������ʾ
	////////{
	////////	DrawIndicate(&MemDC);
	////////}

	//////�ѻ��ƺõ�ͼ����BitBlt()"����"����Ļ��
	////dc.BitBlt(0,0,ClientRect.Width(),ClientRect.Height(),&MemDC, 0, 0,SRCCOPY); 
	////MemDC.SelectObject(pOldBitMap);
	////MemBitMap.DeleteObject();
	////MemDC.DeleteDC();

//Ĭ��
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		 //ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		 //����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialog::OnPaint();
		CRect ClientRect;
		GetClientRect(&ClientRect);
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		dc.FillSolidRect(&ClientRect, RGB(236,233,216));
		//TRACE(_T("OnPaint::1\n"));
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CSORDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSORDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
void CSORDlg::OnOK()
{

}
BOOL CSORDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	///return CDialog::OnEraseBkgnd(pDC);
	return TRUE;
}

UINT threadProc(LPVOID lParam)
{
	CSORDlg* dlg=(CSORDlg*)lParam;
	//dlg->decode();//ԭ��ֱ����ʾ���ߣ���������
	dlg->decodeOtdrTrace();//�����������

	dlg->m_pThread = NULL;
	return 0;
}
void CSORDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString defaultfilename;
	CFileDialog dlg(TRUE,NULL,defaultfilename,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("OTDR�ļ�(*.SOR)|*.SOR||�����ļ�(*.*)|*.*||"));
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
	m_txtpath=dlg.GetPathName();
	CString temp=dlg.GetFileName();
	m_fileName=temp.Left(temp.GetLength()-4)+_T(".txt");
	this->GetDlgItem(IDC_FILENAME)->SetWindowTextW(m_txtpath);
	m_bContinue=TRUE;
	m_bDeal = FALSE;
	RefreshParams();
	RefreshParamsCurve();
	m_pThread=AfxBeginThread(threadProc,this);
}

void CSORDlg::OnBnClickedRead()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_bDeal = FALSE;
	m_bContinue=TRUE;
	//m_pThread=AfxBeginThread(threadProc,this);
	if (NULL == m_pThread)
	{
		m_pThread=AfxBeginThread(threadProc,this);
	}
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-10-22):���ļ�����
////////////////////////////////////////////////////////////////////////////////
void CSORDlg::decodeOtdrTrace()
{
	TRACE(_T("decodeOtdrTrace enter\n"));
	CString temp;
	this->GetDlgItem(IDC_FILENAME)->GetWindowTextW(temp);
	float ftemp;
	if(1==m_sorfileBase.readSorFile(temp,m_sorDATA))
	{
		m_sorAssist.convert(m_sorDATA, m_testResultInfo);//
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		//�����㷨���õ��¼��б�
		m_otdrTrace.m_fFrequency = m_testResultInfo.Frequency;
		m_otdrTrace.m_fRefraction = m_testResultInfo.Refraction;
		m_otdrTrace.m_vEventInfo.clear();
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		int len=m_sorDATA.vAllData[0].vData.size();

		float fC=299792458.0;
		float ff;//=(299792458.0/(2*(m_sorfileBase.m_fixedParas.groupIndex /100000.0)))*(m_sorfileBase.m_fixedParas.vDataSpacing[0]  * m_sorfileBase.m_fixedParas.vDataPointsEach[0]/ 100000000000000.0);
		m_record.clear();//�������Record��¼λ��
		m_recordInt.clear();//
		//int factorCount=m_sorfile.m_dataPoints.vAllData.size();//ϵ������
		int countEachFactor;
		////�����������ݷŵ�m_record��
		////for (int i=0;i<factorCount;i++)
		////{
		vector<WORD>& data=m_sorfileBase.m_dataPoints.vAllData[0].vData;
		countEachFactor=data.size();
		ff=(countEachFactor-1)*m_sorDATA.DataSpacing;
       
		if (m_bDeal)//����"ȥ���㷨"����.��Ӧ"�����"
		{
			INT* pIn = new INT[countEachFactor];
			INT* pOut = new INT[countEachFactor];
			memset(pOut, 0, countEachFactor*4);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
			if (NULL != m_pOut)
			{
				delete m_pOut;
			}//eif
			m_pOut =  new INT[countEachFactor];
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////


			for (int j=0;j<countEachFactor;j++)
			{
				//pIn[j] = (INT)(65535-(int)data[j]);
				pIn[j] = (int)data[j];//Ԭ���㷨Ҫ�����
				m_recordInt.push_back(data[j]);
			}//efor
			m_filter.Filter(pIn, countEachFactor, pOut);
			memcpy(m_pOut, pOut, countEachFactor*sizeof(INT));
			////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////
			for (int j=0;j<countEachFactor;j++)
			{
				
				m_testResultInfo.pDataPoints[j] = pOut[j];
			}//efor
			GetEventList(m_testResultInfo.pDataPoints);
			//m_otdrTrace.ShowCurveByIntData(pOut, countEachFactor, m_sorDATA.Length, TRUE);
			m_otdrTrace.ShowCurveByIntData(pOut, countEachFactor, m_sorDATA.Length, FALSE);
			////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////
			delete[] pIn;
			delete[] pOut;
		}
		else{//����"ȥ���㷨"����,"����ǰ"
			//for (int j=0;j<countEachFactor;j++)
			//{
			//	m_testResultInfo.pDataPoints[j] = 65535-m_testResultInfo.pDataPoints[j];
			//}//efor
			GetEventList(m_testResultInfo.pDataPoints);
			//for (int j=0;j<countEachFactor;j++)
			//{
			//	m_testResultInfo.pDataPoints[j] = 65535-m_testResultInfo.pDataPoints[j];
			//}//efor
			m_otdrTrace.ShowCurve(m_testResultInfo.pDataPoints, countEachFactor, m_sorDATA.Length);
		}//eif
		
		//Invalidate(FALSE);//ˢ��
	}
	else{//����
		//MESSAGE(m_sorfile.m_errInfo);
	}//eif
	//Sleep(100);
	TRACE(_T("decodeOtdrTrace exit\n"));
}

Gabor_Result Acount_Total_Losss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result *sGabor_Result,float Index_N/*������*/,float Sample_freaq)
{
	float start_loss_dB=0;
	int Reflex_Event_start_mark_cn=sGabor_Result->Event_Array[0];

	//���ڹ����д������ٶ�
	double Light_fiber_speed=300/Index_N;//��С��10^6��
	//��������֮���ʱ������
	double Sample_time=Sample_freaq;//�Ŵ���10^6��
	Sample_time=1/Sample_time;

	int i=0,j=0;
	/////////////////////////////////////////////////////////////////////////////////
	//	int pulseNum=0;
	//	switch(pulsewidth)
	//	{
	//	case 3:
	//		pulseNum=0;
	//		break;
	//	case 5:
	//		pulseNum=1;
	//		break;
	//	case 10:
	//		pulseNum=2;
	//		break;
	//	case 20:
	//		pulseNum=3;
	//		break;
	//	case 50:
	//		pulseNum=4;
	//		break;
	//	case 100:
	//		pulseNum=5;
	//		break;
	//	case 200:
	//		pulseNum=6;
	//		break;
	//	case 500:
	//		pulseNum=7;	
	//		break;
	//	case 1000:
	//		pulseNum=8;
	//		break;
	//	case 2000:
	//		pulseNum=9;
	//		break;
	//	case 5000:
	//		pulseNum=10;
	//		break;
	//	case 10000:
	//		pulseNum=11;
	//		break;
	//	case 20000:
	//		pulseNum=12;
	//		break;
	//	default:pulseNum=12;break;
	//	}
	//	//���Ҽ�����ĵ������ʼ�㡣
	//	int step_L=0;
	//	int Start_point=0,End_point=0;
	//	float avg_roias=0;
	//	int up_time=0,fault_time=0;
	//	int data1=0,data2=0;
	//	int count_success_time=0;
	//
	//	step_L=2*lEventGenerate(pulseNum, wavelength,Sample_freaq);
	//	if(sGabor_Result->Event_Array[0]<step_L)Start_point=step_L;
	//	else Start_point=sGabor_Result->Event_Array[0];
	//	if((sGabor_Result->Event_Array[1]-Start_point)<4*step_L)
	//	{
	//		End_point=sGabor_Result->Event_Array[1]-step_L/4;
	//	}
	//	else End_point=Start_point+4*step_L;
	//	for(i=Start_point;i<End_point;i++)
	//	{
	//		//�����������
	//		avg_roias=avg_roias+abs(input_data[i]-input_data[i+1]);
	//
	//	}
	//	avg_roias=2*avg_roias/(End_point-Start_point);
	//	if(avg_roias<100)avg_roias=100;
	//	if((End_point-Start_point)>20)
	//	{
	//		for(i=End_point;i>Start_point;i--)
	//		{
	//			fault_time=0;
	//			up_time=0;
	//			count_success_time=0;
	//			for(j=i;j>Start_point;j--)
	//			{
	//				data1=input_data[i];
	//				data2=input_data[j];
	//				if((data1-data2)>avg_roias)
	//				{
	//					up_time++;
	//					fault_time=0;
	//					if(up_time>=10)
	//					{
	//						//Start_point=i;
	//						count_success_time++;
	//						if(count_success_time>=5)
	//						{
	//							Start_point=i;
	//							break;
	//						}
	//						
	//					}
	//					continue;
	//				}
	//				else
	//				{
	//					fault_time++;
	//					
	//					if(fault_time>=3)
	//					{
	//						count_success_time=0;
	//						break;
	//					}
	//					
	//				}
	//			}
	//			if(j<=Start_point)Start_point=i;
	//		}
	//	}
	//	sGabor_Result->Event_Array[0]=Start_point;
	//
	///////////////////////////////////////////////////////////////////////////////////
	if(sGabor_Result->Valid_Num==2)
	{
		if(sGabor_Result->Line_k[1]==0)
		{
			sGabor_Result->Total_Loss[i]=0;
		}
		else
		{
			sGabor_Result->Total_Loss[1]=sGabor_Result->Line_k[1]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000+0.02;
		}
	}
	else if(sGabor_Result->Valid_Num>2)
	{
		if(sGabor_Result->Line_k[1]!=0)
		{
			start_loss_dB=sGabor_Result->Line_k[1]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
		}
		else if(sGabor_Result->Line_k[2]!=0)
		{
			start_loss_dB=sGabor_Result->Line_k[2]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
		}
		else 
		{
			if(wavelength==1310)
			{
				start_loss_dB=Avg_loss_1310*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1490)
			{
				start_loss_dB=Avg_loss_1490*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1550)
			{
				start_loss_dB=Avg_loss_1550*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1625)
			{
				start_loss_dB=Avg_loss_1625*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1300)
			{
				start_loss_dB=Avg_loss_1300*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==850)
			{
				start_loss_dB=Avg_loss_850*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1650)
			{
				start_loss_dB=Avg_loss_1650*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
		}
		start_loss_dB=start_loss_dB+0.02;
		sGabor_Result->Total_Loss[1]=start_loss_dB;
		for(i=2;i<sGabor_Result->Valid_Num;i++)
		{
			if(sGabor_Result->Event_Array[i]>=15&&pulsewidth>3&&sGabor_Result->Event_Array[1]>=10)
			{
				sGabor_Result->Total_Loss[i]=(input_data[sGabor_Result->Event_Array[i]-15]+input_data[sGabor_Result->Event_Array[i]-14]+input_data[sGabor_Result->Event_Array[i]-13]+input_data[sGabor_Result->Event_Array[i]-12]+input_data[sGabor_Result->Event_Array[i]-11])/5
					-(input_data[sGabor_Result->Event_Array[1]-6]+input_data[sGabor_Result->Event_Array[1]-7]+input_data[sGabor_Result->Event_Array[1]-8]+input_data[sGabor_Result->Event_Array[1]-9]+input_data[sGabor_Result->Event_Array[1]-10])/5;
				sGabor_Result->Total_Loss[i]=(sGabor_Result->Total_Loss[i])/1000+start_loss_dB;//-sGabor_Result->Event_Loss[0];///-sGabor_Result->Event_Loss[0]20130617
				if(sGabor_Result->Total_Loss[i]<=0.1)sGabor_Result->Total_Loss[i]=0;
				if(i>0)
				{

					for(j=0;j<i;j++)//������������ļ�������ǰ�������Ľ����ҪС��˵�����󣬼�Ϊ0
					{
						if(sGabor_Result->Total_Loss[i]<sGabor_Result->Total_Loss[j])
							sGabor_Result->Total_Loss[i]=0;
					}
				}


			}
			else
			{
				sGabor_Result->Total_Loss[i]=0;
			}

		}
	}
	return *sGabor_Result;
}
//ƽ���������ͨ��dll�ļ��㹫ʽ�õ��¼��б�wcq2011-11.03
void CSORDlg::GetEventList(WORD* pDataPoints)
{
	int wavelength = m_testResultInfo.WaveLength;
	int pulseWidth = m_testResultInfo.PulseWidth;
	WORD* input_data = pDataPoints;
	INT paramLen = m_testResultInfo.DataPointsNum;

	double thresholdUpSet = 2.08;//����Ҷ�仯��ֵ���ޡ�Ĭ��Ϊ2.08
	double thresholdDownSet = 2.08;//����Ҷ�仯��ֵ����.Ĭ��Ϊ2.08
	float dB_Loss = m_fAttenuation;
	float dB_reflex = m_fReflect;
	float dB_End = m_fFiberEnd;
	float Return_loss_Tybe = m_fScatteringCoefficient;//ɢ��ϵ��
	float Sample_freaq = m_testResultInfo.Frequency;
	float Index_N = m_testResultInfo.Refraction;
	int link_point_number=0;
	for(int i=0;i<paramLen;i++)
	{
		if(pDataPoints[i]!=65535&&pDataPoints[i]>0)
		pDataPoints[i]=pDataPoints[i]-1;
	}

	TRACE(_T("\n\n\n\n"));
for (int i=0;i<100;i++)
{
	TRACE(_T("%d\n"),pDataPoints[i]);
}
TRACE(_T("\n\n"));

for (int i=0;i<100;i++)
{
	TRACE(_T("%d\n"),pDataPoints[paramLen-(100 -i)]);
}

	__try{
		m_GaborResult = gabor_arithmetic(wavelength,pulseWidth,input_data,paramLen,thresholdUpSet,thresholdDownSet,dB_Loss,dB_reflex,dB_End,Return_loss_Tybe,Sample_freaq, Index_N,link_point_number);//
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return;
	}
    Deadzoon_function(wavelength,pulseWidth,input_data,paramLen,m_GaborResult,Index_N,Sample_freaq,Return_loss_Tybe);
	GaborResultToEvent();////����dll�õ����ݺ�ת��Ϊ�¼��б�
	 FreshEventList();
}
FLOAT GetThreePresizeFloat(FLOAT fVal)
{
	return ((int)((fVal+0.0005)*1000))/1000.0;
}
#define OTDR_EVENT_NUM_MAX 100//����¼����� ��gabo_dll.dll�е����鳤�Ⱦ���
void CSORDlg::GaborResultToEvent()
{
	//�Ƚ���
	m_otdrTrace.m_vEventInfo.clear();
	EventInfo eventinfo;
	int len = m_GaborResult.Valid_Num;//
	if ((len < 0)  || (len > OTDR_EVENT_NUM_MAX))//��ֹ��������
	{
		return;
	}//eif
	float fDisTwo = m_testResultInfo.DataSpacing;//

	for(int i=0;i<len;i++)//Ϊ�˺ͱ������ļ�һ�£����еĶ�С�������λ�������뵽С�������λ
	{
		m_GaborResult.Event_Loss[i] = GetThreePresizeFloat(m_GaborResult.Event_Loss[i]);
		m_GaborResult.Event_Hight[i] = GetThreePresizeFloat(m_GaborResult.Event_Hight[i]);
		m_GaborResult.Line_k[i] = GetThreePresizeFloat(m_GaborResult.Line_k[i]);//
		m_GaborResult.Reflect =GetThreePresizeFloat(m_GaborResult.Reflect);
	}//efor
	m_GaborResult = Acount_Total_Losss(m_testResultInfo.WaveLength, m_testResultInfo.PulseWidth, m_testResultInfo.pDataPoints, &m_GaborResult, m_testResultInfo.Refraction, m_testResultInfo.Frequency);
	for(int i=0;i<len;i++)
	{
		eventinfo.index = m_GaborResult.Event_Array[i];//�±꣬�ڼ���
		eventinfo.nEventType = m_GaborResult.Reflect_Type[i];//�¼�����
		eventinfo.fLocation = fDisTwo * m_GaborResult.Event_Array[i];//
		eventinfo.fEventloss = m_GaborResult.Event_Loss[i];
		eventinfo.fEventHigh = m_GaborResult.Event_Hight[i];
		eventinfo.fLineK = m_GaborResult.Line_k[i];//
		eventinfo.fTotalLoss = m_GaborResult.Total_Loss[i];//���㷨�õ�

		eventinfo.fReflect =m_GaborResult.Reflect;
		eventinfo.fTrailEnd = m_GaborResult.Trail_End;
		eventinfo.cEventType = m_GaborResult.Event_type[i];//
		m_otdrTrace.m_vEventInfo.push_back(eventinfo);
	}//efor
}
const unsigned C = 299792458 ; //����еĹ���m
//�������,��c/2nf��ʽ����.xpoint:��λ�ü�1��Frequency:Ƶ�ʣ� Refraction:������
float GetDistance(unsigned int xpoint, FLOAT Frequency, FLOAT Refraction)
{
	FLOAT ftemp =2 * Frequency *  Refraction * 1000000;//
	if (0 == ftemp)//
	{
		return 0;
	}//eif
	return C/(ftemp/*MHz*/) * xpoint;
}
//���ļ���ȡ�¼��б��ת��Ϊʹ�õ�GaborResult�ṹ�� wcq2012.06.11
void CSORDlg::ConvertEvent()
{
	////CGraphElement& element = m_otdrTrace.m_vAllData[0];//����ֻ����һ������
	////element.m_vAllEvents.clear();
	//////std::vector<OTDR_ALL_UPLOAD_DATA::ENVENT_INFO> ve = pOtdrAllUploadData->VEventInfo;////wcq2012.09.03
	////int nSize=m_vEventInfo.size();
	////if (0 == nSize)
	////{
	////	return;
	////}//eif
	//////
	////CString temp;
	////float preDistance=0;
	////float ftemp=0;//
	////BOOL bKm = TRUE;//
	////BOOL bFeet = FALSE;//
	//////FLOAT fDataspcing = pOtdrAllUploadData->TestRange*1.0/pOtdrAllUploadData->DataPointsNum;
	////FLOAT Frequence = m_testResultInfo.Frequency;
	////FLOAT Refraction = m_testResultInfo.Refraction;
	////for (int i=0;i<nSize;i++)//
	////{
	////	CGraphElement::TraceEvent event;
	////	event.m_nIndex =m_vEventInfo[i].index;
	////	//event.m_distance = GetDistance(ve[i].Index , Frequence, Refraction)/1000;
	////	event.m_distance = GetDistance(m_vEventInfo[i].index , Frequence, Refraction);
	////	element.m_vAllEvents.push_back(event);
	////}//efor
}
//wcq2012.07.23
#define GABOR_RESULT_EVENT_TYPE_REFLECT 1//Gabor_Result�ṹ���¼����ͷ���/�Ƿ����еķ���
#define GABOR_RESULT_EVENT_TYPE_NON_REFLECT 0//Gabor_Result�ṹ���¼����ͷ���/�Ƿ����еķǷ���
#define GABOR_RESULT_EVENT_TYPE_CHAR_START 'S'//Gabor_Result�ṹ���¼�������ʼ/�����е���ʼ�¼����ͣ���ӦcEventType
#define GABOR_RESULT_EVENT_TYPE_CHAR_TERMINAL 'E'//Gabor_Result�ṹ���¼�������ʼ/�����еĽ����¼����ͣ���ӦcEventType
#define EVENT_TYPE_UPLOAD_DATA_START 0//ͨ�������ϴ��������¼������е�"0�� ��ʼ�¼�"
#define EVENT_TYPE_UPLOAD_DATA_REFLECT 1//ͨ�������ϴ��������¼������е�"1�� �����¼�"
#define EVENT_TYPE_UPLOAD_DATA_NON_REFLECT 2//ͨ�������ϴ��������¼������е�"2�� �Ƿ����¼�"
#define EVENT_TYPE_UPLOAD_DATA_TERMINAL 3//ͨ�������ϴ��������¼������е�"3�� �����¼�"
void CSORDlg::FreshEventList()
{
	m_list.DeleteAllItems();
	std::vector<EventInfo> ve = m_otdrTrace.m_vEventInfo;//
	int nSize=ve.size();
	//
	CString temp;
	float preDistance=0;
	float ftemp=0;////wcq2012.04.24
	BOOL bKm = TRUE;//
	BOOL bFeet = FALSE;//
	BOOL bPreciseMeter = (m_testResultInfo.Frequency <= 100);//

	//��Ϊ����ʾ��һ���¼� wcq2013.12.19
	CString strEventType,strDistance,strSegment,strLoss,strTotalLoss,strSlope,strReflect;
	int nIndex;
	for (int i=0;i<nSize;i++)//
	{
		strEventType.Format(_T("%d%c"),ve[i].nEventType,ve[i].cEventType);//

		//if (0 == i)//��һ���¼����붼Ϊ0//wcq2012.07.09
		//{
		//	preDistance = 0;
		//}
		//else
		{

			//if (bKm)
			{
				if (bPreciseMeter)
				{
					strDistance.Format(_T("%.3f"),ve[i].fLocation/1000);//����
					strSegment.Format(_T("%.3f"),(ve[i].fLocation-preDistance)/1000);//��,���¼�������
				}
				else
				{
					strDistance.Format(_T("%.5f"),ve[i].fLocation/1000);//����
					strSegment.Format(_T("%.5f"),(ve[i].fLocation-preDistance)/1000);//��,���¼�������
				}
				preDistance = ve[i].fLocation;
			}
		}//eif

		////if (0 == ve[i].fEventloss)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
		////{
		////	temp.Format(_T("--"));//���
		////}
		////else
		{
			temp.Format(_T("%.3f"),ve[i].fEventloss);//���
		}
		strLoss =temp;

		////if (0 == ve[i].fTotalLoss)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
		////{
		////	temp.Format(_T("--"));//�����
		////}
		////else
		{
			temp.Format(_T("%.3f"),ve[i].fTotalLoss);//�����
		}
		strTotalLoss = temp;

		////if (0 == ve[i].fLineK)//Ϊ0ʱ��ʾ"-"//wcq2015.01.05
		////{
		////	temp.Format(_T("--"));
		////}
		////else
		{
			temp.Format(_T("%.3f"),ve[i].fLineK);//б��
		}
		strSlope = temp;

		////if (0 == ve[i].nEventType)//����
		////{
		////	temp = _T("--");
		////}
		////else if (0 == ve[i].fEventHigh)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
		////{
		////	//m_lstEventList.SetItemText(i,7,_T("--"));
		////	temp = _T("--");
		////}
		////else
		{
			temp.Format(_T("%.3f"),ve[i].fEventHigh);//-52 + 20log10(����/1us)-2fEventHigh;����1310:-50;1550:-52;log10:��10Ϊ�ס�.�Ժ�Ҫ����Ӧ�޸�wcq2011.11.30
		}
		strReflect = temp;
		//if (0 != i)//����ʾ��һ���¼�
		{
			temp.Format(_T("%d"),i+1);
			//nIndex = i - 1;
			nIndex = i;
			m_list.InsertItem(nIndex,temp);
			m_list.SetItemText(nIndex,1,strEventType);
			m_list.SetItemText(nIndex,2,strDistance);
			m_list.SetItemText(nIndex,3,strSegment);
			m_list.SetItemText(nIndex,4,strLoss);
			m_list.SetItemText(nIndex,5,strTotalLoss);
			m_list.SetItemText(nIndex,6,strSlope);
			m_list.SetItemText(nIndex,7,strReflect);
		}
	}//efor




	////////////std::vector<OTDR_ALL_UPLOAD_DATA::ENVENT_INFO> ve = pOtdrAllUploadData->VEventInfo;////wcq2012.09.03
	//////////int nSize=m_otdrTrace.m_vEventInfo.size();
	////////////
	//////////CString temp;
	//////////float preDistance=0;
	//////////float ftemp=0;//
	//////////BOOL bKm = TRUE;//
	//////////BOOL bFeet = FALSE;//
	//////////BOOL bPreciseMeter =(m_testResultInfo.Frequency <= 100);////
	//////////FLOAT fDataspcing = m_testResultInfo.DataSpacing;
	//////////FLOAT Frequence = m_testResultInfo.Frequency;
	//////////FLOAT Refraction = m_testResultInfo.Refraction;
	//////////
	//////////for (int i=0;i<nSize;i++)//
	//////////{
	//////////	temp.Format(_T("%d"),i+1);
	//////////	m_list.InsertItem(i,temp);

	//////////	//temp.Format(_T("%d"),ve[i].EventType);
	//////////	switch(m_GaborResult[i].EventType)
	//////////	{
	//////////	case EVENT_TYPE_UPLOAD_DATA_START:
	//////////		temp = _T("��ʼ");
	//////////		break;
	//////////	case EVENT_TYPE_UPLOAD_DATA_REFLECT:
	//////////		temp = _T("����");
	//////////		break;
	//////////	case EVENT_TYPE_UPLOAD_DATA_NON_REFLECT:
	//////////		temp = _T("�Ƿ���");
	//////////		break;
	//////////	case EVENT_TYPE_UPLOAD_DATA_TERMINAL:
	//////////		temp =_T("����");
	//////////		break;
	//////////	}
	//////////	m_list.SetItemText(i, 1, temp);//

	//////////	if (0 == i)//��һ���¼����붼Ϊ0//wcq2012.07.09
	//////////	{
	//////////		temp = _T("0.000");//����
	//////////		m_list.SetItemText(i,2,temp);
	//////////		m_list.SetItemText(i,3,temp);
	//////////		preDistance = 0;
	//////////	}
	//////////	else
	//////////	{

	//////////		if (bKm)
	//////////		{
	//////////			if (bPreciseMeter)
	//////////			{
	//////////				temp.Format(_T("%.3f"),GetDistance(m_GaborResult[i].Index , Frequence, Refraction)/1000);//����
	//////////				m_list.SetItemText(i,2,temp);

	//////////				temp.Format(_T("%.3f"),(GetDistance(m_GaborResult[i].Index , Frequence, Refraction)-preDistance)/1000);//��,���¼�������
	//////////				m_list.SetItemText(i,3,temp);
	//////////				preDistance = GetDistance(m_GaborResult[i].Index + 1, Frequence, Refraction);
	//////////			}
	//////////			else
	//////////			{
	//////////				temp.Format(_T("%.5f"),GetDistance(m_GaborResult[i].Index , Frequence, Refraction)/1000);//����
	//////////				m_list.SetItemText(i,2,temp);

	//////////				temp.Format(_T("%.5f"),( GetDistance(m_GaborResult[i].Index , Frequence, Refraction) - preDistance)/1000);//��,���¼�������
	//////////				m_list.SetItemText(i,3,temp);
	//////////				preDistance = GetDistance(m_GaborResult[i].Index + 1, Frequence, Refraction);

	//////////			}
	//////////		}

	//////////	}//eif

	//////////	//////if (0 == m_GaborResult[i].Loss)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
	//////////	//////{
	//////////	//////	temp.Format(_T("--"));//�����
	//////////	//////}
	//////////	//////else
	//////////	{
	//////////		temp.Format(_T("%.3f"),m_GaborResult[i].Loss);//���
	//////////	}
	//////////	//temp.Format(_T("%.3f"),ve[i].fEventloss);//��� //cwcq2012.07.09
	//////////	m_list.SetItemText(i,4,temp);

	//////////	////if (0 == m_GaborResult[i].TotalLoss)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
	//////////	////{
	//////////	////	temp.Format(_T("--"));//�����
	//////////	////}
	//////////	////else
	//////////	{
	//////////		////if (m_GaborResult[i].TotalLoss < -1000)
	//////////		////{
	//////////		////	temp.Format(_T("--"));//�����
	//////////		////}
	//////////		////else 
	//////////		{
	//////////			temp.Format(_T("%.3f"),m_GaborResult[i].TotalLoss);//�����
	//////////		}//eif
	//////////	}
	//////////	m_list.SetItemText(i,5,temp);

	//////////	//if (fabs(ve[i].fLineK)>0.3)//cwcq2012.05.09
	//////////	////if (fabs(m_GaborResult[i].Slope)>0.5)//wcq2012.05.09
	//////////	////{
	//////////	////	temp.Format(_T("--"));
	//////////	////}
	//////////	////else if (0 == m_GaborResult[i].Slope)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
	//////////	////{
	//////////	////	temp.Format(_T("--"));
	//////////	////}
	//////////	////else
	//////////	{
	//////////		temp.Format(_T("%.3f"),m_GaborResult[i].Slope);//б��
	//////////	}
	//////////	m_list.SetItemText(i,6,temp);

	//////////	//if (0 == m_GaborResult[i].Reflect)//����
	//////////	//{
	//////////	//	m_list.SetItemText(i,7,_T("--"));
	//////////	//}
	//////////	////else if (0 == m_GaborResult[i].Reflect)//Ϊ0ʱ��ʾ"-"wcq2012.07.09
	//////////	////{
	//////////	////	m_list.SetItemText(i,7,_T("--"));
	//////////	////}
	//////////	//else
	//////////	{
	//////////		temp.Format(_T("%.3f"),m_GaborResult[i].Reflect);//-52 + 20log10(����/1us)-2fEventHigh;����1310:-50;1550:-52;log10:��10Ϊ�ס�.�Ժ�Ҫ����Ӧ�޸�wcq2011.11.30
	//////////		m_list.SetItemText(i,7,temp);
	//////////	}
	//////////}//efor
}





void CSORDlg::decode()
{
	CString temp;
	this->GetDlgItem(IDC_FILENAME)->GetWindowTextW(temp);
	float ftemp;
	if(1==m_sorfileBase.readSorFile(temp,m_sorDATA))
	{
		m_sorAssist.convert(m_sorDATA, m_testResultInfo);//wcq2012.07.24
		int len=m_sorDATA.vAllData[0].vData.size();
		for(int i=0;i<10;i++)
		{
			//TRACE(_T("%d \t%d\n"),m_sorDATA.vAllData[0].vData[len-1 - i],m_testResultInfo.pDataPoints[len-1 - i]);
			TRACE(_T("%d\n"),m_testResultInfo.pDataPoints[ i]);
		}
		float fC=299792458.0;
		float ff;//=(299792458.0/(2*(m_sorfileBase.m_fixedParas.groupIndex /100000.0)))*(m_sorfileBase.m_fixedParas.vDataSpacing[0]  * m_sorfileBase.m_fixedParas.vDataPointsEach[0]/ 100000000000000.0);
		////float fReflect=m_sorfileBase.m_dataPoints.vAllData[0].scaleFactor /100000.0;
		////float numEachTime=m_sorfileBase.m_fixedParas.vDataSpacing[0]/100000000000000.0;
		////ff=(fC * numEachTime * m_sorfileBase.m_fixedParas.vDataPointsEach[0] /(fReflect));
		m_record.clear();//�������Record��¼λ��
		//int factorCount=m_sorfile.m_dataPoints.vAllData.size();//ϵ������
		int countEachFactor;
		////�����������ݷŵ�m_record��
		////for (int i=0;i<factorCount;i++)
		////{
			vector<WORD>& data=m_sorfileBase.m_dataPoints.vAllData[0].vData;
			countEachFactor=data.size();
			if (m_bDeal)
			{
				INT* pIn = new INT[countEachFactor];
				INT* pOut = new INT[countEachFactor];
				for (int j=0;j<countEachFactor;j++)
				{
					//m_record.push_back((65535-(int)data[j])/1000.0);
					//////pIn[j] = (INT)data[j];
					pIn[j] = (INT)(65535-(int)data[j]);
				}//efor
				for(int i=0;i<10;i++)
				{
					TRACE(_T("INT %d\n"),pIn[i] );
				}
				m_filter.Filter(pIn, countEachFactor, pOut);
				for (int j=0;j<countEachFactor;j++)
				{
					//m_record.push_back(pOut);
					//////m_record.push_back((65535-(int)pOut[j])/1000.0);

					m_record.push_back(pOut[j]/1000.0);
				}//efor
				////}//efor
				recordToPoint();//������������ת��Ϊ��ͼ�õ����������ݡ�
				delete[] pIn;
				delete[] pOut;
			}
			else{
				for (int j=0;j<countEachFactor;j++)
				{
					m_record.push_back((65535-(int)data[j])/1000.0);
				}//efor
				recordToPoint();//������������ת��Ϊ��ͼ�õ����������ݡ�
			}
		//
		InvalidateRect(&m_rectCurve);//ˢ��
	}
	else{//����
		//MESSAGE(m_sorfile.m_errInfo);
	}
}
//
////////////////////////////////////////////////////////////////////////////////////
//����˵��:������������ת��Ϊ��ͼ�õ����������ݡ�
//��ڲ���:
//���ڲ���:
//����ʱ��:2011.7.9
//Write By:wcq
////////////////////////////////////////////////////////////////////////////////////
void CSORDlg::recordToPoint()
{
	int m_dataLen=m_record.size();
	if(0==m_dataLen)
	{
		return;
	}
	//������ת��Ϊ������ʽ
	if(NULL!=m_ptData)
	{
		delete[] m_ptData;
	}
	m_ptData=new CPoint[m_dataLen];
	//
	INT i=m_dataLen-1;
	INT rectWidth=m_rectCoord.Width();
	INT rectHeight=m_rectCoord.Height();
	INT itemp;
	int yValueAll=m_yMax-m_yMin;//y�����ݷ�Χ
	while (i>=0)
	{
		m_ptData[i].x=(i*rectWidth*1.0)/m_dataLen+m_rectCoord.left;
		itemp=m_rectCoord.top +  rectHeight-(m_record[i]/yValueAll)*rectHeight;//-MARGIN_BOTTOM;
		if(itemp>m_rectCoord.top +  rectHeight)
		{
			itemp=rectHeight;
		}
		///TRACE(_T("x:%d, y:%d\n"),m_ptData[i].x,itemp);
		m_ptData[i].y=itemp;
		i--;
	}//ewhile
}
void CSORDlg::drawData()
{
	int count=m_record.size();
	if(0==count)
	{
		return;
	}
}/*
 ***************************************************************
 ��������:             CalculDispRect()                                                                               
 ����˵��:             ����������ʾ����XY����Ϣ��ʾ����������Ϣ��ʾ���ľ���                                                                             
 ��ڲ���:             ��                                                                                             
 ���ڲ���:             ��                                                                                             
 ����ʱ��:             2010-06-23                                                                
 Write By:             LDL                                                                                           
 ***************************************************************
 */
void CSORDlg::CalCulDispRect()
{
	CRect rtClient;
	GetClientRect(&rtClient);

	//������ʾ��
	m_rectCurve.left	= rtClient.left+20 ;
	m_rectCurve.top	= rtClient.top+80 ;
	m_rectCurve.right = rtClient.right - 20;
	m_rectCurve.bottom = rtClient.bottom-20;

	m_rectCoord.left=m_rectCurve.left+0;
	m_rectCoord.right=m_rectCurve.right;
	m_rectCoord.top=m_rectCurve.top+20;
	m_rectCoord.bottom=m_rectCurve.bottom-20;
}
void CSORDlg::DrawCoord(CDC *pDC)
{

	int nSaveDC=pDC->SaveDC();

	CPen penGridLine,penCoord;
	penGridLine.CreatePen (PS_DOT/*����*/,5,RGB(COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE));
	penCoord.CreatePen (PS_SOLID,1,COLOR_PURPLE);
	//���ο�
	pDC->SelectObject (&penCoord);
	pDC->Rectangle(&m_rectCoord);

	//XY��

	//
	
	
	//�ָ�
	pDC->RestoreDC(nSaveDC);
}
void CSORDlg::DrawCurve(CDC *pDC)
{
	int m_dataLen=m_record.size();
	if(0==m_dataLen)
	{
		return;
	}
	//���û���ݣ��򲻻�
	//
	int nSaveDC=pDC->SaveDC();

	CPen penCoord;
	CPen* oldPen;
	//penGridLine.CreatePen (PS_DOT/*����*/,5,RGB(COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE));
	penCoord.CreatePen (PS_SOLID,1,COLOR_CURVE);
	//���ο�
	oldPen=pDC->SelectObject (&penCoord);

	//XY��

	//////������ת��Ϊ������ʽ
	////if(NULL!=m_ptData)
	////{
	////	delete[] m_ptData;
	////}
	////m_ptData=new CPoint[m_dataLen];
	//////
	////INT i=m_dataLen-1;
	////INT rectWidth=m_rectCoord.Width();
	////INT rectHeight=m_rectCoord.Height();
	////INT itemp;
	////int yValueAll=m_yMax-m_yMin;//y�����ݷ�Χ
	////while (i>=0)
	////{
	////	m_ptData[i].x=(i*rectWidth*1.0)/m_dataLen+m_rectCoord.left;
	////	itemp=rectHeight-(m_record[i]/yValueAll)*rectHeight;//-MARGIN_BOTTOM;
	////	if(itemp>rectHeight)
	////	{
	////		itemp=rectHeight;
	////	}
	////	///TRACE(_T("x:%d, y:%d\n"),m_ptData[i].x,itemp);
	////	m_ptData[i].y=itemp;
	////	i--;
	////}

	//
	pDC->Polyline(m_ptData,m_dataLen);//��ʾ
	
	//�ָ�
	//pDC->RestoreDC(nSaveDC);
	pDC->SelectObject (oldPen);
}
void CSORDlg::saveData()
{	
	CString defaultfilename=m_fileName;
	CFileDialog dlg(FALSE,_T("*.txt"),defaultfilename,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("txt (�ı��ļ�)(*.txt)|*.txt||"));
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
	CString m_txtpath=dlg.GetPathName();
	
	CFileException mExcept;
	CStdioFile mFile;
	if(!mFile.Open(m_txtpath,CFile::modeReadWrite|CFile::modeCreate,&mExcept))//���ļ��Ա�д��
	{
		return;
	}

//
	CString temp,values=_T("");
	int count=m_record.size();
	for(int i=0;i<count;i++)
	{
		temp.Format(_T("%.3f"),m_record[i]);
		mFile.WriteString(temp);
		mFile.WriteString(_T("\r\n"));
	}
//
	mFile.Flush();
	mFile.Close();
}
void CSORDlg::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_sorAssist.convert(m_testResultInfo,m_sorDATA);
	m_sorfileBase.saveSorFile(_T("e:\\a.sor"),m_sorDATA);
//	m_sorfileBase2.saveSorFile(_T("e:\\a.sor"),m_testResultInfo);
	//saveData();
}

void CSORDlg::OnBnClickedSave2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString defaultfilename=m_fileName;
	CFileDialog dlg(FALSE,_T("*.txt"),defaultfilename,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("txt (�ı��ļ�)(*.txt)|*.txt||"));
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
	CString m_txtpath=dlg.GetPathName();

	CFileException mExcept;
	CStdioFile mFile;
	if(!mFile.Open(m_txtpath,CFile::modeReadWrite|CFile::modeCreate,&mExcept))//���ļ��Ա�д��
	{
		return;
	}

	//
	CString temp,values=_T("");
	int count=m_recordInt.size();
	temp.Format(_T("%d"),count);
	mFile.WriteString(temp);
	mFile.WriteString(_T("\r\n"));
	for(int i=0;i<count;i++)
	{
		temp.Format(_T("%d"),m_recordInt[i]);
		mFile.WriteString(temp);
		mFile.WriteString(_T("\r\n"));
	}
	//
	mFile.Flush();
	mFile.Close();
}

void CSORDlg::OnBnClickedRead2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_bDeal = TRUE;
	m_bContinue=TRUE;
	RefreshParams();
	RefreshParamsCurve();
	if (NULL == m_pThread)
	{
		m_pThread=AfxBeginThread(threadProc,this);
	}
}

void CSORDlg::OnBnClickedRead3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_otdrTrace.ZoomReset();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-5-7):�����㷨����������+����+����+����
////////////////////////////////////////////////////////////////////////////////
void CSORDlg::OnBnClickedSave3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString defaultfilename=m_fileName;
	CFileDialog dlg(FALSE,_T("*.txt"),defaultfilename,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("txt (�ı��ļ�)(*.txt)|*.txt||"));
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
	CString m_txtpath=dlg.GetPathName();

	CFileException mExcept;
	CStdioFile mFile;
	if(!mFile.Open(m_txtpath,CFile::modeReadWrite|CFile::modeCreate,&mExcept))//���ļ��Ա�д��
	{
		return;
	}

	//
	CString temp,values=_T("");
	int count=m_recordInt.size();
	//���ݵ����
	//temp.Format(_T("%d"),count);
	//mFile.WriteString(temp);
	//mFile.WriteString(_T("\r\n"));
	//���ݵ�
	for(int i=0;i<count;i++)
	{
		temp.Format(_T("%d"),m_pOut[i]);
		mFile.WriteString(temp);
		mFile.WriteString(_T("\r\n"));
	}//efor

	temp.Format(_T("%d"), m_sorDATA.WaveLength);
	mFile.WriteString(temp);
	mFile.WriteString(_T("\r\n"));

	temp.Format(_T("%d"), m_sorDATA.PulseWidth);
	mFile.WriteString(temp);
	mFile.WriteString(_T("\r\n"));

	temp.Format(_T("%.2f"), m_sorDATA.Frequency);
	mFile.WriteString(temp);
	mFile.WriteString(_T("\r\n"));
	//
	mFile.Flush();
	mFile.Close();
}

void CSORDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}

void CSORDlg::OnSpin(UINT nID)
{
	INT nIndex = nID - IDC_MY_SPIN8;//afx_msg void OnSpin(UINT uID);
}

BOOL CSORDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	return CDialog::PreTranslateMessage(pMsg);
}

void CSORDlg::SetEditText( UINT nEditID, INT nAdd, INT nPrecision /*= 0*/ )
{
	m_SpinUtil.ChangeText(nEditID, nAdd, nPrecision);
	OnBnClickedRead2();
}
void CSORDlg::OnDeltaposMySpin8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������,
	SetEditText(IDC_ALPHA_COEFF_SMOOTH, pNMUpDown->iDelta, 2);
	*pResult = 0;
}
void CSORDlg::OnDeltaposMySpin9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_ALPHA_COEFF_RISE, pNMUpDown->iDelta, 1);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_ALPHA_COEFF_DOWN, pNMUpDown->iDelta, 1);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin11(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_ALPHA_COEFF_MDY, pNMUpDown->iDelta, 1);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin12(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_ALPHA_COEFF_DIF, pNMUpDown->iDelta, 2);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin13(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_DIF_DEGREE_MULTI, pNMUpDown->iDelta, 1);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin14(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	SetEditText(IDC_FILST_REF_LENGTH, pNMUpDown->iDelta);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin15(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	SetEditText(IDC_REVB_DOWN_LENGTH, pNMUpDown->iDelta);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
void CSORDlg::OnDeltaposMySpin16(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_REVB_RISE_LENGTH, pNMUpDown->iDelta, 0);
	*pResult = 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-6-3):
////////////////////////////////////////////////////////////////////////////////
void CSORDlg::InitParams()
{
	CString temp;
	temp.Format(_T("%.2f"), FILTER_ALPHA_COEFF_SMOOTH);
	SetDlgItemText(IDC_ALPHA_COEFF_SMOOTH, temp);
	temp.Format(_T("%.1f"), FILTER_ALPHA_COEFF_RISE);
	SetDlgItemText(IDC_ALPHA_COEFF_RISE, temp);
	temp.Format(_T("%.1f"), FILTER_ALPHA_COEFF_DOWN);
	SetDlgItemText(IDC_ALPHA_COEFF_DOWN, temp);
	temp.Format(_T("%.1f"), FILTER_ALPHA_COEFF_MDY);
	SetDlgItemText(IDC_ALPHA_COEFF_MDY, temp);
	temp.Format(_T("%.2f"), FILTER_ALPHA_COEFF_DIF);
	SetDlgItemText(IDC_ALPHA_COEFF_DIF, temp);
	temp.Format(_T("%.1f"), FILTER_DIF_DEGREE_MULTI);
	SetDlgItemText(IDC_DIF_DEGREE_MULTI, temp);
	temp.Format(_T("%d"), FILTER_FILST_REF_LENGTH);
	SetDlgItemText(IDC_FILST_REF_LENGTH, temp);
	temp.Format(_T("%d"), FILTER_REVB_DOWN_LENGTH);
	SetDlgItemText(IDC_REVB_DOWN_LENGTH, temp);
	temp.Format(_T("%d"), FILTER_REVB_RISE_LENGTH);
	SetDlgItemText(IDC_REVB_RISE_LENGTH, temp);
	temp.Format(_T("%.3f"), FILTER_LOW_NOISE_THD);
	SetDlgItemText(IDC_ENVELOPE_REC_COEFF, temp);
}

void CSORDlg::OnBnClickedDefault()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InitParams();
	OnBnClickedRead2();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-6-3):���������µ�m_filter
////////////////////////////////////////////////////////////////////////////////
void CSORDlg::RefreshParams()
{
	CString temp;
	GetDlgItemText(IDC_ALPHA_COEFF_SMOOTH, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_ALPHA_COEFF_SMOOTH = _tstof(temp);
	}

	GetDlgItemText(IDC_ALPHA_COEFF_RISE, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_ALPHA_COEFF_RISE = _tstof(temp);
	}

	GetDlgItemText(IDC_ALPHA_COEFF_DOWN, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_ALPHA_COEFF_DOWN = _tstof(temp);
	}

	GetDlgItemText(IDC_ALPHA_COEFF_MDY, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_ALPHA_COEFF_MDY = _tstof(temp);
	}

	GetDlgItemText(IDC_ALPHA_COEFF_DIF, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_ALPHA_COEFF_DIF = _tstof(temp);
	}

	GetDlgItemText(IDC_DIF_DEGREE_MULTI, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_DIF_DEGREE_MULTI = _tstof(temp);
	}

	GetDlgItemText(IDC_FILST_REF_LENGTH, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_nFILST_REF_LENGTH = _ttoi(temp);
	}

	GetDlgItemText(IDC_REVB_DOWN_LENGTH, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_nREVB_DOWN_LENGTH = _ttoi(temp);
	}

	GetDlgItemText(IDC_REVB_RISE_LENGTH, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_nREVB_RISE_LENGTH = _ttoi(temp);
	}

	GetDlgItemText(IDC_ENVELOPE_REC_COEFF, temp);
	if (_T("") != temp)
	{
		m_filter.m_paramInfo.m_LOW_NOISE_THD = _tstof(temp);
	}
}
void CSORDlg::OnDeltaposMySpin19(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_ENVELOPE_REC_COEFF, pNMUpDown->iDelta, 1);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin21(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_EDIT_ATTENUCTION, pNMUpDown->iDelta, 2);
	*pResult = 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-10-22):�¼�����Ĭ��
////////////////////////////////////////////////////////////////////////////////
void CSORDlg::OnBnClickedDefault2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InitParamsCurve();
}

void CSORDlg::InitParamsCurve()
{
	CString temp;
	temp.Format(_T("%d"), 0);
	SetDlgItemText(IDC_EDIT_ATTENUCTION, temp);
	temp.Format(_T("%d"), 0);
	SetDlgItemText(IDC_REFLECT, temp);
	temp.Format(_T("%d"), 0);
	SetDlgItemText(IDC_EDIT_FIBER_END, temp);
	temp.Format(_T("%.1f"), -81.0);
	SetDlgItemText(IDC_EDIT_SCATTER_COEFF, temp);
}

void CSORDlg::RefreshParamsCurve()
{
	CString temp;
	GetDlgItemText(IDC_EDIT_ATTENUCTION, temp);
	m_fAttenuation = _tstof(temp);
	GetDlgItemText(IDC_REFLECT, temp);
	m_fReflect = _tstof(temp);
	GetDlgItemText(IDC_EDIT_FIBER_END, temp);
	m_fFiberEnd = _tstof(temp);
	GetDlgItemText(IDC_EDIT_SCATTER_COEFF, temp);
	m_fScatteringCoefficient = _tstof(temp);
}
void CSORDlg::OnDeltaposMySpin23(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_REFLECT, pNMUpDown->iDelta, 2);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin25(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_EDIT_FIBER_END, pNMUpDown->iDelta, 0);
	*pResult = 0;
}

void CSORDlg::OnDeltaposMySpin27(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetEditText(IDC_EDIT_SCATTER_COEFF, pNMUpDown->iDelta, 1);
	*pResult = 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-10-22):
////////////////////////////////////////////////////////////////////////////////
void CSORDlg::InitList()
{
	DWORD dwStyle=::GetWindowLong(m_list.m_hWnd,GWL_STYLE);
	SetWindowLong(m_list.m_hWnd,GWL_STYLE,dwStyle|LVS_SHOWSELALWAYS|LVS_REPORT|LVS_NOLABELWRAP);
	ListView_SetExtendedListViewStyle(m_list.m_hWnd,LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_list.InsertColumn(0, _T("���"), LVCFMT_CENTER, 40);//_T("")
	m_list.InsertColumn(1, _T("����"), LVCFMT_CENTER, 40);//_T("")
	m_list.InsertColumn(2, _T("����"), LVCFMT_CENTER, 60);//_T("")
	m_list.InsertColumn(3,_T("��") , LVCFMT_CENTER, 60);//_T("")
	m_list.InsertColumn(4,_T("���") , LVCFMT_CENTER, 60);//_T("")
	m_list.InsertColumn(5,_T("�����"), LVCFMT_CENTER, 60);//_T("")
	m_list.InsertColumn(6, _T("б��"), LVCFMT_CENTER, 60);//_T("")
	m_list.InsertColumn(7,_T("����"), LVCFMT_CENTER, 60);//_T("")
}
void CSORDlg::OnBnClickedButOtdrTrace()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
