#pragma once
#include <math.h>
////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//OTDR���߻�����
//wcq2013.02.04
//˵����
//plot:��ͼ
//Cur:Current��ǰ
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
#define OTDR_TRACE_MAX 1
#define OTDR_TRACE_MIN 0
//#define POINT2FLOATX(x) m_fRangeX[OTDR_TRACE_MIN] + ( (x - m_rectCurve.left)   * m_fResolutionX)
#define POINT2FLOATX(x) m_fRangeX[OTDR_TRACE_MIN] + ( ((x - m_rectCurve.left)   * (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN])) / m_rectCurve.Width())
////#define POINT2FLOATY(y) m_fRangeY[OTDR_TRACE_MIN] + ( (m_rectCurve.bottom - y-HIKE_UP_HEIGHT+10) * m_fResolutionY)//zll 2013.6.25 -HIKE_UP_HEIGHT+10
#define POINT2FLOATY(y) m_fRangeY[OTDR_TRACE_MIN] + ( (m_rectCurve.bottom - y) * m_fResolutionY)//
#define FLOAT2POINTX(x) m_rectCurve.left + (x - m_fRangeX[OTDR_TRACE_MIN]) * m_rectCurve.Width() / (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN])//���ݾ���õ�X����
#define FLOAT2RATIO(x) (x-m_fRangeX[OTDR_TRACE_MIN]) / (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN])//xjf 2014.03.03  ��ȡ����ϵ��
#define OTDR_TRACE_Y_MAX 65.535//45
#define OTDR_TRACE_Y_MIN 0
#define OTDR_TRACE_DEFAULT_ZOOM_PERCENT 0.02//2%Ĭ�����ű��� zll 2013.5.11
#define OTDR_TRACE_Y_MIN_CHANGE 0.01//����ֱ����Ŵ��ֻ��0.1dbʱ��������
#define OTDR_TRACE_CURSOR_AB_MARGIN_TOP 30//���AB��ֱ�����붥����Զ
#define OTDR_TRACE_CURSOR_AB_VALID_SELE 6//��������֮����Ϊѡ����A/B��
//#define OTDR_TRACE_CURSOR_AB_COLOR_SELE g_COLORREF[11]//A/B��ѡ����ɫ
#define OTDR_TRACE_VALID_NUM_LOWEST 10//��ͼʱ���ټ���������������
#define OTDR_TRACE_Y_FACTOR 1000//y�������ΧΪ�����ͣ����Ŵ�һ��������nPageΪ0��������Ҫ�Ŵ�һ��������������Ϊ1000//zll 2013.4.24
#define ZOOM_VERTICAL_STANDARD 30*1000//wcq2011.09.26������ֱ��������ʱȷ��������̣����ڸ�ֵʱΪ-65~30,С��ʱΪ-55��40
#define CursorAB_Coefficient 1000.0//ϵ�� zll 2013.3.15
#define  COUNT_GRIDLINE_HORIZONE 10//��ͼ�á�ˮƽ������//wcq2011.12.19
#define  COUNT_GRIDLINE_VERTICAL 9//��ͼ�á���ֱ������//wcq2011.12.19
#define  Divisor_toKm 1000//zll 2013.5.11
#define OTDR_TRACE_COLOR_SELECT RGB(255, 255, 0)//zll 2013.5.11
#define OTDR_SQUARE_FRAME_COLOR RGB(255, 0, 0)//zll 2013.10.29,����Ϊ��ɫ����Ĭ��ѡ������Ϊ��ɫ����
#define OTDR_TRACE_COLOR_GRIDLINE RGB(65, 65, 65)//������ɫ
#define HIKE_UP_HEIGHT 50//zll 2013.6.25
#define INVALID_MAX_POINT 0//

#define OTDR_TRACE_COLOR_BG RGB(246, 232, 110)//������ͼ���򱳾�ɫ,��ʾЧ��Ϊ�̶ȵı���ɫ,����ɫ
#define OTDR_TRACE_COLOR_BG_CURVE RGB(0,0,0)//���߱���ɫ,��ɫ
#define OTDR_TRACE_COLOR_LINE_AB_NORMAL RGB(255,255,255)//������ͼ���򱳾�ɫ
#define OTDR_TRACE_COLOR_LINE_AB_SELECT RGB(255,0,0)//������ͼ���򱳾�ɫ
#define OTDR_TRACE_COLOR_EVENT_NUM RGB(128,255,0)//������ͼ���򱳾�ɫ

#define MARGIN_LEFT 36
#define MARGIN_TOP 20
#define GRIDLING_COUNT_X 10
#define GRIDLING_COUNT_Y 9
//#define  M_FMINDB -65.63//
//#define  M_FMAXDB -20.63//
#define  EVENT_POINT_HEIGHT 30//
#define  EVENT_POINT_NUM_HEIGHT 20//

extern COLORREF g_COLORREF[12];

enum CURVE_CURRECT_MODE
{
	CURVE_NONE=0,
	CURVE_GET_DATA,
	CURVE_SELECT,
	CURVE_ZOOM_OUT ,
	CURVE_ZOOM_OUT_V,
	CURVE_ZOOM_OUT_H,
	CURVE_ZOOM_IN,
	CURVE_ZOOM_IN_V,
	CURVE_ZOOM_IN_H,
	CURVE_MOVE,
	CURVE_MOVE_UP,
	CURVE_MOVE_DOWN,
	CURVE_MOVE_LEFT,
	CURVE_MOVE_RIGHT,
	CURVE_RESET
};
enum OTDR_TRACE_AB_SELECT//���ABѡ��״̬
{
	OTDRTRACE_AB_SELE_NONE=0,
	OTDRTRACE_AB_SELE_A,
	OTDRTRACE_AB_SELE_B,
	OTDRTRACE_AB_SELE_AB
};
enum OTDR_TRACE_AB_TYPE//���ABģʽ  
{
	OTDRTRACE_AB_TYPE_SINGLE_A_OR_B = 0,//ѡһ��(A/B)
	OTDRTRACE_AB_SELE_DOUBLE_AB//ABģʽ
};
///////////////////////////////////////////////////////////

//ͼ�λ�������
enum CURSOR_SELECT : int
{
	CURSOR_NONE = 0,
	CURSOR_A = 1,		//ѡ��A
	CURSOR_B = 2,		//ѡ��B
	CURSOR_AB = 4,		//ѡ��AB
	CURSOR_EVENT = 8	//ѡ���¼�
};
///////////////////////////////////////////////////////////
//����
class CGraphElement
{
public:
	CGraphElement()
	{
		m_bIsPlotAvailable = FALSE;
		m_LineColor = RGB(0,0,0);
		m_bShow = TRUE;
		//m_strName.Format(_T("Element-%d"),id);
		m_pData = NULL;
		m_nOffsetY = 0;
		m_bShowEvent = TRUE;
		m_bSelected = FALSE;
		m_pData = NULL;
		m_pPointsToDraw = NULL;
		m_nPointsCountMax = 0;
		m_fLength = 0;
		m_nPointsCount = 0;
	}//efun
	~CGraphElement()
	{
		//m_fontEventNum->DeleteObject();
		//m_fontEventKm->DeleteObject();
		//m_penLineVertical->DeleteObject();
	}
	void ReNew(INT nPointCount)
	{
		if (nPointCount <= m_nPointsCountMax)
		{
			return;
		}//eif
		if (NULL != m_pData)
		{
			delete[] m_pData;
		}//eif
		m_nPointsCountMax = nPointCount;
		m_pData = new FLOAT[nPointCount];
	}//efun
	struct TraceEvent
	{
		INT m_nIndex;
		FLOAT m_distance;
	};
	INT  DistanceToIndex(FLOAT fDistance);//���ݾ���ת��Ϊ��Ӧ�����ݵ��±�,һ������ȷ��ÿ�λ�ͼ����ʼ�㼰������
	void DrawCurve(CDC* pDC, CRect rect);//��������
	void SetYOffset(INT nOffset=1);//��ֱ����ƽ��
	//void DrawEvents(CDC* pDC, INT nStartIndex, INT nEndIndex);//�����¼�
	BOOL m_bShow;//�Ƿ���ʾ
	BOOL m_bShowEvent;//�Ƿ���ʾ�¼��б�
	BOOL m_bSelected;//�Ƿ���ѡ������
	BOOL m_bIsPlotAvailable;//�Ƿ�ɻ�
	COLORREF m_LineColor;//������ɫ
	CFont* m_fontEventNum;//�¼��б��±�����
	CFont* m_fontEventKm;//�¼��б��������
	CPen* m_penLineVertical;//��ֱ��
	CString m_strName;//����
	INT m_nPointsCount;//�ܹ��ж��ٸ����ݵ�,��ǰ����ʵ�ʵ���
	INT m_nPointsCountMax;//��β��Ժ��������ݵ����������ȷ���Ƿ����·����ڴ�
	//INT m_nPointsCountVirtual;//�������ߵ�������Ҫ��Ϊ�˶���������ʾ�������������Ϊ׼���㵱ǰ����Ӧ���ж��ٸ���(�ȵ�ǰʵ�ʵĵ�����)ʱ���õ��ĳ��ȵ�����������߳���
	INT m_nOffsetY;//y��ƫ����
	FLOAT m_fLength;//����
	////static FLOAT m_fRange[2];//���浱ǰ��ͼʱ��С������,���x�ᣬ��Զ�������
	static FLOAT m_fRangeX[2];//���浱ǰ��ͼʱ��С������,���x�ᣬ��Զ�������
	static FLOAT m_fRangeY[2];//���浱ǰ��ͼʱy�᷶Χ����Զ�������
	static FLOAT m_fMaxDistance;//����룬��Զ�������
	FLOAT m_fDataSpacing;//���Ϊ��������,������������
	FLOAT* m_pData;//�㼯��
	std::vector<TraceEvent> m_vAllEvents;
	std::vector<INT> m_vEventPoints;//�¼����б�
	CPoint* m_pPointsToDraw;//
};

// COtdrTrace

class COtdrTrace : public CButton
{
	DECLARE_DYNAMIC(COtdrTrace)

public:
	COtdrTrace();
	virtual ~COtdrTrace();

public:
	struct CursorAB
	{
		CursorAB()
		{
			m_nPos = 0;
			m_fPos = 0;
			m_nDataIndex = 0;
			m_colorLine = RGB(0,0,255);//��ѡ��A�����ʱBΪm_colorLine��ѡ��B�����ʱAΪm_colorLine
			m_colorLabel = RGB(255,255,255);//A��B�����Աߵ��ı������¼������Աߵ��ı�
		}
		INT m_nPos;//λ�ã������Ļ����������
		INT m_nDataIndex;//�����������е��±�
		FLOAT m_fPos;//λ�ã�����km,�������λ��
		CString m_strAOrB;//"A"/"B"
		CString m_strDistance;//���پ��룬��100km���������ʾ���ַ���
		CString m_strDB;//zll 2013.12.6 ���� AB����dBֵ
		COLORREF m_colorLine;//������ɫ
		COLORREF m_colorLabel;//�������ı�����A 100km��ɫ
	}m_cursorA,m_cursorB,m_cursorAminusB;//zll 2013.6.25 ����m_cursorAminusB
public:
	void InitPaint(CDC* pDC);//��ʼ����ͼ�õı�ˢ��
	void DoDraw(CDC* pDC);
	void CreateMyFont(CDC* pDC, CFont& font, CString fontName = _T(""));//��������
	void DrawMouseSeleRect(CDC* pDc);//��������϶�����
	void DrawCurves(CDC* pDC,INT m_nCurveIndex = 0);//������������//zll 2013.6.25�����Ӳ���INT m_nCurveIndex
	void DrawLineAB(CDC* pDC);//����AB���
	void DrawLineABGap(CDC* pDC);//����AB�����
	void DrawLineABDetail(CDC* pDC, CursorAB* pCursorAB);//������ƺ���.����AB���
	void DrawGrid(CDC *pDC);//����GridLine//zll 2013.4.22
	void DrawDotLine(CDC* pDC, CPoint pointStart, CPoint pointEnd, COLORREF colorLine);//�����ߣ����ڻ�Gridline,ֻ��Ի�ˮƽ����ֱ��
	void DrawDbAndLength(CDC* pDC);
	void CalculateRect();//�����ͼ����
	void SetRange(float xmin, float xmax, float ymin, float ymax, BOOL bSetScrollInof = TRUE);//���û�ͼ���ޣ���Ҫ�ػ�
	void SetMaxDistance(FLOAT fMaxDistance);//���������
	FLOAT GetMaxDistance();//�õ������
	void ZoomInHorizonForBig(FLOAT fPercent = OTDR_TRACE_DEFAULT_ZOOM_PERCENT);//ˮƽ�Ŵ� fPercent�Ŵ������Ĭ��2%
	void ZoomOutHorizonForSmall(FLOAT fPercent = OTDR_TRACE_DEFAULT_ZOOM_PERCENT);//ˮƽ��С fPercent�Ŵ������Ĭ��2%
	void ZoomInVertialForBig(FLOAT fPercent = OTDR_TRACE_DEFAULT_ZOOM_PERCENT);//��ֱ�Ŵ� fPercent�Ŵ������Ĭ��2%
	void ZoomOutVertialForSmall(FLOAT fPercent = OTDR_TRACE_DEFAULT_ZOOM_PERCENT);//��ֱ��С fPercent�Ŵ������Ĭ��2%
	void ZoomReset();//��ԭ��ˮƽ��ֱ����Ϊ
	void ZoomOutClickForBig(INT nPointX, INT nPointY, FLOAT fPercent = OTDR_TRACE_DEFAULT_ZOOM_PERCENT * 5);//�����Ŵ�Ĭ�ϷŴ�10%
	void CursorABOnMove(CPoint pointMoving);//�϶�A/B��ʱ���¼���A/B��λ��
	FLOAT  GetCenterOffset();//���ݵ�ǰѡ���A/B�꣬��������ʱ������ƫ��
	FLOAT GetYDB(FLOAT fPos);//�õ�ĳ���Ӧ��dbֵ��fPos:ĳ����λ��
	//INT GetABPositionOnMove(CPoint pointMoving);//����ƶ�ʱ����AB��Ӧ��X������
	//FLOAT GetABDistanceOnMove(CPoint pointMoving, INT nXAB);//�õ�AB������ľ���

	INT GetABSelectState(CPoint pointClick);//�������ʱ���ж��Ƿ�ѡ��AB��
	BOOL IsInCurRangeX(FLOAT fDistance);//�ж��Ƿ��ڵ�ǰ��ʾ��Χ��,���ˮƽ����
	BOOL IsInCurRangeY(FLOAT fDistance);//�ж��Ƿ��ڵ�ǰ��ʾ��Χ��,�����ֱ����
	CGraphElement* GetSeleCurve();


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	void SetVerScoll(); //������ֱ������
	void SetHorScroll();//����ˮƽ������
	void InitScrollInfo();//��ʼ��������//zll 2013.4.24
	void SetMyScrollInfo(float xmin, float xmax, float ymin, float ymax);//���ù�������Χ

	//////////////////////////////////////////////////////////////////////////
	void SetScrollRangeX();//����ˮƽ����Χ//zll2013.4.23

	void MoveEventList(INT nIndex);//ѡ�����¼��б�����»�������;wcq2011-11.15
	void VerticalZoom();


	void EventIsSelected(int PointAOrB);

public:
	void ReleaseAllData();//�����������
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	void ShowCurve(WORD* pData, INT nPointsCount, FLOAT fTestRange = 0);//��ʾһ���������ݣ������¼��б�
	void ShowCurveByIntData(INT* pData, INT nPointsCount, FLOAT fTestRange = 0, BOOL bReverse = FALSE);//��ʾһ���������ݣ������¼��б�
public:
	INT m_nPointCountMax;//������ݵ����
	FLOAT* m_pFloatData;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	CRect m_rectMouseSelect;//���ѡ������cwcq
	CRect m_rectClient;//��������
	CRect m_rectCurve; //���������ھ�������,�������ߵľ�������
	//CRect m_rectCurve; //�������ߵľ�������,����m_rectCoord���߶�Ϊm_rectCoord+20
	BOOL m_bLeftButtonDown;
	BOOL m_bInitPaint;//�Ƿ��ѽ��й���ʼ����ˢ��
	INT m_nCurMode;//ģʽ
	CDC m_dcGrid;//������DC
	CDC m_dcCurve;//��ͼDC�ֱ���
	CBitmap m_bmpGrid;
	CBitmap m_bmpCurve;
	FLOAT m_fResolutionY, m_fResolutionX;//(��Ļÿһ����ռ���ٸ����ݵ�/ÿһ���ض�Ӧ���߶೤����)
	FLOAT m_fRangeY[2], m_fRangeX[2];//�����Сֵ
	FLOAT m_fOldRangeX[2], m_fOldRangeY[2];//ԭ���������Сֵ,������С
	FLOAT m_fMaxDistance;//����룬��Զ�������
	std::vector<CGraphElement> m_vAllData;//��������

	BOOL m_bShowLineAB;//�Ƿ���ʾA/B���
	BOOL m_bDrawGrid;//�Ƿ���Ƹ�����(GridLine)//zll 2013.4.22
	INT  m_nCurABSele;//��ǰ�Ƿ�ѡ��AB�꣬���ѡ�У�ѡ����A����B
	INT  m_nABSele;//��ǰA����B��Ϊ��������
	INT  m_nCurveIndex;//��ǰѡ�������±�
	INT  m_nABType;//���ѡ��ģʽ����ǰֻѡһ�����(A/B)��ͬʱѡ����(AB,�϶�һ����һ��Ҳ�ᶯ)
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//������
	int m_nHorzPos;
	FLOAT m_nVertPos;
	int m_nHorzMaxSize;
	FLOAT m_nVertMaxSize;
	int m_nHorzPageSize;
	FLOAT m_nVertPageSize;
	int m_nHorzOneStep;
	FLOAT m_nVertOneStep;
	int m_nOneStep;

	int m_nSelectCursor; //Seleced��־,1ѡ��A��2ѡ��B, 4ѡ��AB
	int m_nPointA;//A�ߵ�λ�õ㣬������ ������Ϊ�޷�����,  //ʼ��������������Ϊ׼wcq
	int m_nPointB;//B�ߵ�λ�õ㣬������  //ʼ��������������Ϊ׼wcq

	int m_iHorizonZoomNum; //ˮƽ�Ŵ����
	int m_nDrawWidth; //��ͼ������
	int m_nZoomCount;//���Ŵ���
	unsigned int m_nStartPoint;  //���ߺ���������
	unsigned int m_nMaxPoint;    //���ߺ�������������ֵ
	int m_nMaxIndex;
	//CRect m_rectCoord; //���������ھ�������
	int m_iVerticalZoomNum; //��ֱ�Ŵ����
	float m_fCoeff; //��ֱ����ϵ��
	int m_nDrawHeight; //��ͼ����߶�(�������߶�)
	float m_fStartDB;    //������������ʼdb
	float m_fMaxDB;      //�������������ֵ

	int m_nDataLenMsg;//��Ϣ�а��������ݸ���wcq2012.02.07
	WORD* m_pRecvbuf; //�������ݻ�����
	DWORD m_dwMaxPointCount;//��������������,�����ڻ�������ʱʹ�� wcq 2011.09.15
	BOOL m_bFirstRead;//���β����Ƿ��һ���յ����� wcq2012.02.21
	BOOL m_bBusy;//�Ƿ��յ���Ϣ�����ڴ������� wcq 2011.09.15
	BOOL m_bNeedHorizonZoom;//�Ƿ���Ҫ�������ţ������������������� wcq2012.02.17
	BOOL m_bEventCursor; //�Ƿ�Ϊ�¼����
	int m_nSelectIndex; //ѡ�е��¼�������
	DWORD m_dwWaveSelected;//ѡ������������ wcq 2011.09.16
	int m_nPointEvent; //��ǰ�¼��㣬 ������
	CRect m_rectSubInfo; //AB������ʾ����wcq2011.11.16
public:
	CFont m_font;
	COLORREF m_colorBg;//������ͼ���򱳾�ɫ
	CFont m_fontEventNum;//�¼��б��±�����
	CFont m_fontEventKm;//�¼��б��������
	CPen m_penLineVertical;//��ֱ��
	///
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
	struct LastTestInfo//wcq2012.02.21
	{//��Ҫ��¼���ϴβ���ʱ��һЩ����
		LastTestInfo()
		{
			m_distanceA = 0;
			m_distanceB = 0;
		}
		FLOAT m_distanceA;//A����ԭ�����
		FLOAT m_distanceB;//B����ԭ�����
	}m_lastTestInfo;
public:
	INT GetCurrentCursorIndex();//�õ���ǰ����Ӧ��ǰ�����±�
//zll 2013.5.9
	public:
		void CalCulDispRect();
		BOOL IsCurrentTypeAB();//��ǰ�Ƿ�ѡ��AB�꣬ͬʱ�ƶ�AB��
		void SetCurrentTypeAB(INT nABType);//OTDRTRACE_AB_TYPE_SINGLE_A_OR_B��OTDRTRACE_AB_SELE_DOUBLE_AB
		void TraceCountChanged();//���������߻�ɾ�������ߣ�������������
		void ReCalMaxDistance();//���¼���������룬��Ҫ�����ɾ��һ������
		void SetCurrentSeleTrace(INT nIndex);//��Ϊ��ǰѡ������//zll 2013.5.11
		void SetShowCurve(int iNum,BOOL boolShow);
		void SetCurveCursorData(); //�������߹������ //xjf 2014.3.3
public://2015.10.22
		void ConvertEvent( CGraphElement& element );
		float GetDistance(unsigned int xpoint, FLOAT Frequency, FLOAT Refraction);
public:
		void CalMouseDbInfo(CPoint point);//�����������λ�õ�dBֵ�������±�
		void DrawMouseDb( CDC* pDC );
		CString m_strMouseDbAndIndex;
		CPoint m_mousePoint;//���λ��
public:
	std::vector<EventInfo> m_vEventInfo; //2015.10.22
	FLOAT m_fFrequency;
	FLOAT m_fRefraction;
};


