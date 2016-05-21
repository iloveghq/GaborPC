// OtdrTrace.cpp : 实现文件
//

#include "stdafx.h"
#include "OtdrTrace.h"
//#include "CursorInfo.h"

COLORREF g_COLORREF[12];

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
FLOAT CGraphElement::m_fRangeX[2];//保存当前绘图时最小最大距离，针对多条曲线
FLOAT CGraphElement::m_fRangeY[2];//保存当前绘图时y轴范围，针对多条曲线
FLOAT CGraphElement::m_fMaxDistance = 0;//最长距离，针对多条曲线
const unsigned C_zll = 299792458 ; //真空中的光速m
//CGraphElement

// CSorDrawStatic 对话框

INT CGraphElement::DistanceToIndex(FLOAT fDistance)
{
	ASSERT(0 != m_fDataSpacing);
	return (fDistance-0.001) / m_fDataSpacing;//zll 2013.12.6 (fDistance-0.001)需要减0.001 否则结果会较大，取整会+1
	//return fDistance/ m_fDataSpacing;//
}
//绘制曲线
void CGraphElement::DrawCurve(CDC* pDC, CRect rect)
 {
	ASSERT(NULL != m_pData);
	//先计算需要绘制哪些点

	INT nStartIndex= DistanceToIndex(m_fRangeX[0]);
	INT nEndIndex = DistanceToIndex(m_fRangeX[1]);
	if (nStartIndex >= m_nPointsCount)
	{
		return;
	}//eif

	if (nEndIndex - nStartIndex < rect.Width())
	{
		nEndIndex++;
	}
	if (nEndIndex >= m_nPointsCount)
	{
		nEndIndex = m_nPointsCount - 1;
	}//eif

	//ASSERT(nStartIndex >= 0);
	if (nStartIndex < 0)
	{
		return;
	}//eif
	//ASSERT(nEndIndex <= m_nPointsCount);
	//TRACE(_T("%d %d  \n"),nStartIndex,nEndIndex);
	//计算当前曲线水平方向上占多少象素
	INT nXAxis = rect.Width();//
	if (m_fRangeX[1] > m_fLength)
	{//按比例求长度
		nXAxis = ((m_fLength - m_fRangeX[0]) / (m_fRangeX[1] - m_fRangeX[0])) * nXAxis;
	}//
	
	//计算绘图点
	INT nPointCountToDraw = nEndIndex - nStartIndex + 1;//总共绘图点

	CPoint* pPointsToDraw = new CPoint[nPointCountToDraw];
	FLOAT fTempX = ((FLOAT)nXAxis) / nPointCountToDraw;//1每一点占x轴多长
	FLOAT fTempY = rect.Height() / (m_fRangeY[1] - m_fRangeY[0]);
	FLOAT fYConst =  rect.bottom + rect.Height() * m_fRangeY[0]  / (m_fRangeY[1] - m_fRangeY[0]) + m_nOffsetY;
	int nTemp;
	INT nIndex = 0;
	//fX = (nTemp * m_fDataSpacing - m_fRangeX[OTDR_TRACE_MIN])*rect.Width() / (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN]);
	for (int i = nStartIndex; i <= nEndIndex; i++)
	{
		pPointsToDraw[nIndex].x = (m_fDataSpacing * i - m_fRangeX[OTDR_TRACE_MIN])*rect.Width() / (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN]);
		pPointsToDraw[nIndex].y = fYConst - m_pData[i] * fTempY;// - 40zll 2013.6.3 -40 使曲线沿y轴向上移动
		nIndex++;
	}//efor
	//处理

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, OTDR_TRACE_COLOR_SELECT);
	CPen* pOldPen = pDC->SelectObject(&pen);
	Polyline(pDC->GetSafeHdc(),pPointsToDraw, nPointCountToDraw);
	//for (int i=0; i<nPointCountToDraw; i++)
	//{
	//	pDC->SetPixel(pPointsToDraw[i], RGB(255,0,0));
	//}
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	delete[] pPointsToDraw;

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//绘事件列表
	if (!m_bShowEvent)
	{
		return;
	}//eif

	////zll 2013.5.11 以下是A或B标旁边的字体属性
	pDC->SetTextColor(OTDR_TRACE_COLOR_EVENT_NUM);//zll 2013.5.12
	pDC->SetBkMode(TRANSPARENT);
	CFont   *pOldFont = pDC->SelectObject(m_fontEventNum);
	CBrush *pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	pOldPen = pDC->SelectObject(m_penLineVertical);
	CString temp;
	int fX,fY;
	CRect rectTemp;
	rectTemp.SetRectEmpty();//zll 2013.5.24 初始化A或B标旁边的字显示框，否则位置乱掉，release版无法显示A或B标旁边的字
	for (int i=0; i<m_vAllEvents.size(); i++)
	{		
		CRect rectLineBottom;//rectLineBottom:直线下方的矩形wcq2011.11.16
		nTemp = m_vAllEvents[i].m_nIndex;

		if ( (nTemp >= nStartIndex ) &&(nTemp <= nEndIndex))
		{
			fX = (m_vAllEvents[i].m_distance - m_fRangeX[OTDR_TRACE_MIN])*rect.Width() / (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN]);
			fY = fYConst - m_pData[nTemp] * fTempY ;//- 40
			//画竖直线
			pDC->MoveTo(fX, fY - 10);//zll 2013.6.3 -10 使竖直线沿y轴向上移动
			pDC->LineTo(fX, fY + 34);
			//竖直线下面的正方形
			rectLineBottom.SetRect(fX - 8,fY + 34,fX - 8 + 16, fY + 34 + 18);
			if (i>8)//两位数
			{
				rectLineBottom.right += 2;
			}
			pDC->Rectangle(&rectLineBottom);

			temp.Format(_T("%d"),i + 1);
			pDC->SelectObject(m_fontEventNum);////
			rectLineBottom.DeflateRect(2,2);
			pDC->DrawText(temp,&rectLineBottom,DT_CENTER | DT_VCENTER | DT_SINGLELINE);//矩形框中的数值

			//距离文本
			float fVal=m_vAllEvents[i].m_distance/Divisor_toKm;
			temp.Format(_T("%.3fkm"), fVal);

			pDC->SelectObject(m_fontEventKm);
			pDC->DrawText(temp, -1, rectTemp, DT_WORDBREAK | DT_CENTER | DT_CALCRECT);////zll 2013.5.11 以下是A或B标旁边的字体属性
			//pDC->TextOut(fX - rectTemp.Height() / 2, fY + rectTemp.Width() + 20, temp);
			pDC->TextOut(fX - rectTemp.Height() / 2 - 10, fY + rectTemp.Width() - 16, temp);
		}//eif
	}//efor

	pDC->SelectObject(pOldFont);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
void CGraphElement::SetYOffset(INT nOffset)
{
	m_nOffsetY += nOffset;
}
//void CGraphElement::DrawEvents(CDC* pDC, INT nStartIndex, INT nEndIndex)
//{
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
// COtdrTrace

IMPLEMENT_DYNAMIC(COtdrTrace, CStatic)

COtdrTrace::COtdrTrace()
{
	m_bLeftButtonDown = false;
	m_nCurMode = CURVE_ZOOM_IN;
	m_rectMouseSelect.SetRectEmpty();
	m_rectCurve.SetRectEmpty();
	m_bInitPaint = FALSE;
	m_bShowLineAB = TRUE;
	m_cursorA.m_strAOrB = _T("A");
	m_cursorB.m_strAOrB = _T("B");
	m_cursorA.m_strDistance = _T("0km");
	m_cursorB.m_strDistance = _T("0km");
	m_cursorA.m_strDB= _T("0dB");
	m_cursorB.m_strDB= _T("0dB");
	m_nCurABSele = OTDRTRACE_AB_SELE_NONE;//默认未选中AB
	m_nABSele = OTDRTRACE_AB_SELE_A;
	m_nCurveIndex = 0;
	m_fMaxDistance = 0;
	m_bDrawGrid = TRUE;//zll 2013.4.22
	m_nSelectCursor = CURSOR_SELECT::CURSOR_A; //默认选中A
	m_nPointA = 0;
	m_nPointB = 0;

	m_nMaxIndex = 0;
	m_nStartPoint=0;
	m_nMaxPoint= INVALID_MAX_POINT;//原为0,wcq2012.02.20
	m_colorBg = OTDR_TRACE_COLOR_BG_CURVE;
	m_font.CreateFont(12, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, FIXED_PITCH | FF_MODERN, _T("宋体"));//微软雅黑

	//m_fontEventNum = new CFont();
	m_fontEventNum.CreateFont(16, 0, 0, 0, FW_BOLD,//从上往下2700
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH,_T("@Arial")); 
	//m_fontEventKm = new CFont();
	m_fontEventKm.CreateFont(18, 0, 900, 900, FW_NORMAL,//从上往下2700
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH,_T("@Arial")); 
	//m_penLineVertical = new CPen();
	m_penLineVertical.CreatePen(PS_SOLID, 1, OTDR_SQUARE_FRAME_COLOR);
	m_nPointCountMax = -1;
	m_pFloatData = NULL;
}

COtdrTrace::~COtdrTrace()
{
	for(int i=0; i< m_vAllData.size(); i++)
	{
		if (m_vAllData[i].m_pData)
		{
			delete[] m_vAllData[i].m_pData;
		}//eif
	}//efor
	m_fontEventKm.DeleteObject();
	m_fontEventNum.DeleteObject();
	m_penLineVertical.DeleteObject();
	if (NULL != m_pFloatData)
	{
		delete[] m_pFloatData;
	}//eif
}


BEGIN_MESSAGE_MAP(COtdrTrace, CButton)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()



// COtdrTrace 消息处理程序



void COtdrTrace::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	if (!m_bInitPaint)//初始化DC等
	{
		InitPaint(&dc);
	}//eif
	CDC memDC ;
	CBitmap memBitmap ;
	CBitmap* oldBitmap ; // bitmap originally found in CMemDC
	CRect rectClient;
	GetClientRect(&rectClient);
	memDC.CreateCompatibleDC(&dc) ;
	memBitmap.CreateCompatibleBitmap(&dc, rectClient.Width(), rectClient.Height()) ;
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap) ;
	if (memDC.GetSafeHdc() != NULL)
	{
		DoDraw(&memDC);
		dc.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &memDC, 0, 0, SRCCOPY); //拷贝内存DC到屏幕
	}//eif
	memDC.SelectObject(oldBitmap) ;
	memDC.DeleteDC();
}
void COtdrTrace::InitPaint(CDC* pDC)
{
	//ASSERT(m_dcGrid.GetSafeHdc());
	//ASSERT(m_dcPlot.GetSafeHdc());
	//DC
	if (!m_dcGrid.GetSafeHdc())
	{
		m_dcGrid.CreateCompatibleDC(pDC);
	}//eif
	if (!m_dcCurve.GetSafeHdc())
	{
		m_dcCurve.CreateCompatibleDC(pDC);
	}//eif

	//内存位图
	if (m_bmpCurve.GetSafeHandle())
	{
		m_bmpCurve.DeleteObject();
	}//eif
	if (m_bmpGrid.GetSafeHandle())
	{
		m_bmpGrid.DeleteObject();
	}//eif
	CRect rectClient;
	GetClientRect(&rectClient);
	m_rectCurve.CopyRect(&rectClient);//绘图区域
	m_rectCurve.left += MARGIN_LEFT;
	m_rectCurve.bottom -= MARGIN_TOP;
	m_bmpCurve.CreateCompatibleBitmap(pDC, m_rectCurve.Width(), m_rectCurve.Height());//
	m_bmpGrid.CreateCompatibleBitmap(pDC, rectClient.Width(), rectClient.Height());//
	m_dcGrid.SelectObject(&m_bmpGrid);
	m_dcCurve.SelectObject(&m_bmpCurve);

	m_bInitPaint = TRUE;
}
void COtdrTrace::DoDraw(CDC* pDC)
{
	CRect rectClient;
	GetClientRect(&rectClient);
	pDC->FillSolidRect(&rectClient, OTDR_TRACE_COLOR_BG);//
	pDC->FillSolidRect(&m_rectCurve, OTDR_TRACE_COLOR_BG_CURVE);//背景色
	DrawGrid(pDC);//格子
	
	//pDC->BitBlt(m_rectCurve.left, m_rectCurve.top, m_rectCurve.Width(), m_rectCurve.Height(), &m_dcCurve, 0, 0, SRCCOPY); //曲线。拷贝内存DC到屏幕
	//////TransparentBlt(pDC->GetSafeHdc(), m_rectCurve.left, m_rectCurve.top, m_rectCurve.Width(), m_rectCurve.Height(), m_dcCurve.GetSafeHdc(), 0, 0, m_rectCurve.Width(), m_rectCurve.Height(), RGB(0, 0, 0));
	TransparentBlt(pDC->GetSafeHdc(), m_rectCurve.left, m_rectCurve.top, m_rectCurve.Width(), m_rectCurve.Height(), m_dcCurve.GetSafeHdc(), 0, 0, m_rectCurve.Width(), m_rectCurve.Height(), RGB(0, 0, 0));

	switch(m_nCurMode)//根据不同模式
	{
	case CURVE_ZOOM_OUT://缩小
	case CURVE_ZOOM_IN://放大
		DrawMouseSeleRect(pDC);
		break;
	}//eswitch

	DrawLineAB(pDC);//
	DrawDbAndLength(pDC);//刻度
	DrawMouseDb(pDC);//鼠标所在位置的dB值和下标
}
//绘制鼠标拖动矩形
void COtdrTrace::DrawMouseSeleRect(CDC* pDc)
{
	//TRACE(_T("%d %d %d %d\n"),m_rectMouseSelect.left, m_rectMouseSelect.top, m_rectMouseSelect.right,m_rectMouseSelect.bottom);
	//if (m_rectMouseSelect.IsRectEmpty())
	//{
	//	return;
	//}//eif
	///*TRACE(_T("%d %d %d %d 2222222222222222222222222222222222222\n"),m_rectMouseSelect.left, m_rectMouseSelect.top, m_rectMouseSelect.right,m_rectMouseSelect.bottom);*/
	CPen zoomRectPen(PS_SOLID, 1, RGB(255,0,0));
	CPen* oldPen = pDc->SelectObject(&zoomRectPen);
	pDc->MoveTo(m_rectMouseSelect.TopLeft());
	pDc->LineTo(m_rectMouseSelect.right,m_rectMouseSelect.top);
	pDc->LineTo(m_rectMouseSelect.BottomRight());
	pDc->LineTo(m_rectMouseSelect.left,m_rectMouseSelect.bottom);
	pDc->LineTo(m_rectMouseSelect.TopLeft());
	pDc->SelectObject(oldPen);
}
//绘制所有曲线
void COtdrTrace::DrawCurves(CDC* pDC,INT m_nCurveIndex)
{
	//pDC->FillSolidRect(&m_rectCurve, RGB(0,0,0));
	CRect rectTemp;
	rectTemp.CopyRect(&m_rectCurve);
	rectTemp.OffsetRect(-MARGIN_LEFT, 0);
	pDC->FillSolidRect(&rectTemp, RGB(0,0,0));
	for(int i = 0; i < m_vAllData.size(); i++)
	{
		m_vAllData[i].DrawCurve(pDC, rectTemp);//m_rectCurve
	}//efor
}
//绘制所有曲线
void COtdrTrace::DrawLineAB(CDC* pDC)
{
	if (!m_bShowLineAB)
	{
		return;
	}//eif
	if (0 ==m_vAllData.size())
	{
		return;
	}//
	//
	if (IsInCurRangeX(m_cursorA.m_fPos))//只有在当前范围内时，才绘制
	{
		DrawLineABDetail(pDC, &m_cursorA);
	}//eif
	if (IsInCurRangeX(m_cursorB.m_fPos))////只有在当前范围内时，才绘制
	{
		DrawLineABDetail(pDC, &m_cursorB);
	}//eif
	DrawLineABGap(pDC);
}
//具体绘制函数.
void COtdrTrace::DrawLineABDetail(CDC* pDC, CursorAB* pCursorAB)
{
	//得到X轴坐标
	CRect rect;
	GetClientRect(&rect);
	rect.bottom -= MARGIN_TOP;
	INT nX = FLOAT2POINTX(pCursorAB->m_fPos);//(pCursorAB->m_fPos - m_fRangeX[OTDR_TRACE_MIN]) * rect.Width() / (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN]);
	CPen pen;//
	if ((("A" == pCursorAB->m_strAOrB) && (OTDRTRACE_AB_SELE_A == m_nABSele)) || (("B" == pCursorAB->m_strAOrB) && (OTDRTRACE_AB_SELE_B == m_nABSele)))
	{//当前选中
		pen.CreatePen(PS_SOLID, 1, OTDR_TRACE_COLOR_LINE_AB_SELECT);//OTDR_TRACE_CURSOR_AB_COLOR_SELE
	}
	else
	{
		pen.CreatePen(PS_SOLID, 1, OTDR_TRACE_COLOR_LINE_AB_NORMAL);//pCursorAB->m_colorLine
	}//eif
	CPen* pOldPen = pDC->SelectObject(&pen);
	INT nMarginTop = OTDR_TRACE_CURSOR_AB_MARGIN_TOP;
	if ("B" == pCursorAB->m_strAOrB)
	{
		nMarginTop += 20;
	}//eif
	//直线
	pDC->MoveTo(nX, rect.top + nMarginTop);
	pDC->LineTo(nX, rect.bottom);

	//文本
	CFont   font;   
	CFont   *pOldFont;   
	CreateMyFont(pDC, font, _T("Arial"));
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(pCursorAB->m_colorLabel);

	//zll 2013.5.11
	float fVal;
	float fDB;
	if ("A" == pCursorAB->m_strAOrB)
	{
		fVal=m_cursorA.m_fPos/Divisor_toKm;
		//fDB=GetYDB(m_cursorA.m_fPos);
		fDB=m_vAllData[m_nCurveIndex].m_pData[m_cursorA.m_nDataIndex];//m_cursorA.m_fPos);
	//m_cursorA.m_strDistance.Format(_T("%.3fkm"), fVal);//zll 2013.5.9
	//m_cursorA.m_strDB.Format(_T("%.2fdB"), fDB);
	}
	else//B
	{
		fVal=m_cursorB.m_fPos/Divisor_toKm;
		//fDB=GetYDB(m_cursorB.m_fPos);
		fDB=m_vAllData[m_nCurveIndex].m_pData[m_cursorB.m_nDataIndex];
	//m_cursorB.m_strDistance.Format(_T("%.3fkm"), fVal);//zll 2013.5.9
	//m_cursorB.m_strDB.Format(_T("%.2fdB"), fDB);
	}

	CString strText,strTextAminusB;
	strText.Format(_T("%s %.3fkm %.3fdB"), pCursorAB->m_strAOrB, fVal,fDB);
	//strText.Format(_T("%s %.3fkm"), pCursorAB->m_strAOrB, fVal);
	CSize sizeText = pDC->GetTextExtent(strText);//得到文本长宽度
	CRect rectText;
	rectText.top = nMarginTop;
	rectText.bottom = rectText.top + sizeText.cy;
	if (nX + sizeText.cx + 1 <= rect.right)//文本正常显示，在右边,1：文本和竖线间隔
	{
		rectText.left = nX + 1;
		rectText.right = nX + 1 + sizeText.cx;
	}
	else//移动到右边，若文本显示不下，则把文本显示到左边
	{
		rectText.left = nX - (sizeText.cx + 1);
		rectText.right = nX - 1;
	}//eif
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(strText, &rectText, DT_LEFT | DT_SINGLELINE);


	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	pOldFont = pDC->SelectObject(pOldFont);
	font.DeleteObject();
}
void COtdrTrace::DrawLineABGap( CDC* pDC )
{
	CFont   font;   
	CFont   *pOldFont;   
	CreateMyFont(pDC, font, _T("Arial"));
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(255,255,255));
	float fVal = fabs((m_cursorA.m_fPos - m_cursorB.m_fPos)/Divisor_toKm);
	//float fDB=fabs(GetYDB(m_cursorA.m_fPos) - GetYDB(m_cursorB.m_fPos));
	float fDB=fabs(m_vAllData[m_nCurveIndex].m_pData[m_cursorA.m_nDataIndex] - m_vAllData[m_nCurveIndex].m_pData[m_cursorB.m_nDataIndex]);
	CString strTextAminusB;
	strTextAminusB.Format(_T("%s %.3fkm %.2fdB"), _T("A-B:"), fVal,fDB);
	//strTextAminusB.Format(_T("%s %.3fkm"), _T("A-B:"), fVal);
	CSize sizeTextAminusB = pDC->GetTextExtent(strTextAminusB);//得到文本长宽度
	CRect rectTextAminusB;
	rectTextAminusB.top = 0;
	rectTextAminusB.bottom = rectTextAminusB.top + sizeTextAminusB.cy;
	rectTextAminusB.left = 1;
	rectTextAminusB.right = 1 + sizeTextAminusB.cx;
	rectTextAminusB.OffsetRect(MARGIN_LEFT, 0);
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(strTextAminusB, &rectTextAminusB, DT_LEFT | DT_SINGLELINE);
	pOldFont = pDC->SelectObject(pOldFont);
}
//绘制GridLine,格子线
void COtdrTrace::DrawGrid(CDC *pDC)//zll 2013.4.22
{
	//如果不需要重绘则退出
	if (!m_bDrawGrid)
	{
		return;
	}
	//m_bDrawGrid = FALSE;


	////CPen penGridLine;//
	//penGridLine.CreatePen (PS_DOT/*虚线*/, 1, OTDR_TRACE_COLOR_GRIDLINE);//g_COLORREF[9]
	////penGridLine.CreatePen (PS_DASH, 1, OTDR_TRACE_COLOR_GRIDLINE);//g_COLORREF[9]
	////CPen* pOldPen = pDC->SelectObject(&penGridLine); //

	float ndx = m_rectCurve.Width ()/COUNT_GRIDLINE_HORIZONE;
	float ndy = m_rectCurve.Height ()/COUNT_GRIDLINE_VERTICAL;
	int bottom = m_rectCurve.Height();
	int left = m_rectCurve.left;
	int itemp;//
	for ( int i = 1; i<COUNT_GRIDLINE_HORIZONE; i++)//竖直
	{	
		itemp=left + ndx * i;
		//横坐标刻度从上到下-------------------------------------------------------
		////pDC->MoveTo (itemp,bottom);
		////pDC->LineTo (itemp,0);
		DrawDotLine(pDC, CPoint(itemp, 0), CPoint(itemp, bottom), OTDR_TRACE_COLOR_GRIDLINE);
	}//efor
	//纵坐标:::	从左到右
	for (int i=1; i<COUNT_GRIDLINE_VERTICAL; i++)
	{
		itemp = bottom - ndy * i;
		pDC->MoveTo (left , itemp);
		pDC->LineTo (m_rectCurve.right,itemp);
		DrawDotLine(pDC, CPoint(left, itemp), CPoint(m_rectCurve.right, itemp), OTDR_TRACE_COLOR_GRIDLINE);
	}//efor

	//pDC->SelectObject(pOldPen);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: CDC * pDC
// Parameter: CPoint pointStart
// Parameter: CPoint pointEnd
// Parameter: COLORREF colorLine
// Comment(2014-10-15):画虚线，用于画Gridline,只针对画水平或竖直线
////////////////////////////////////////////////////////////////////////////////
void COtdrTrace::DrawDotLine( CDC* pDC, CPoint pointStart, CPoint pointEnd, COLORREF colorLine )
{
	INT i;
	if (pointStart.y == pointEnd.y)//水平
	{
		i = pointStart.x;
		while(i <= pointEnd.x)
		{
			pDC->SetPixel(CPoint(i, pointStart.y), colorLine);
			i += 3;
		}//eif
	}
	else//竖直
	{
		i = pointStart.y;
		while(i <= pointEnd.y)
		{
			pDC->SetPixel(CPoint(pointStart.x, i), colorLine);
			i += 3;
		}//eif
	}//eif
}
void COtdrTrace::DrawDbAndLength( CDC* pDC )
{
	if (0 == m_vAllData.size())
	{
		return;
	}//eif
	float fMaxDb=m_fRangeY[1];
	float fMinDb=m_fRangeY[0];
	float fMaxX= m_fRangeX[1];//
	float fMinX= m_fRangeX[0];
	float fTemp = fMinDb;
	CString temp;
	CRect rect(m_rectClient);
	rect.left = 0;
	rect.right = MARGIN_LEFT-2;
	//rect.bottom = m_rectClient.bottom + MARGIN_TOP;
	rect.bottom = m_rectCurve.bottom - 2;
	rect.top = rect.bottom - 16;
	CFont* pOldFont = pDC->SelectObject(&m_font);
	pDC->SetTextColor(RGB(0x33,0x33,0x33));//
	pDC->SetBkMode(TRANSPARENT);
	FLOAT fSpan = (fMaxDb - fMinDb)/GRIDLING_COUNT_Y;
	for(int i=0;i<GRIDLING_COUNT_Y;i++)
	{
		fTemp =  fMinDb + i * fSpan;//
		temp.Format(_T("%.2f"), fTemp);
		pDC->DrawText(temp, &rect, DT_RIGHT|DT_BOTTOM|DT_SINGLELINE );//
		rect.OffsetRect(0, -(m_rectCurve.Height()*1.0/GRIDLING_COUNT_Y));
	}//
	temp.Format(_T("dB"));
	rect.top = 0;
	rect.bottom = rect.top + 30;
	pDC->DrawText(temp, &rect, DT_RIGHT|DT_TOP );//

	//水平
	rect.top = m_rectCurve.bottom + 2;
	rect.bottom = rect.top + 30;
	rect.left = m_rectCurve.left;
	rect.right = m_rectCurve.right;
	BOOL bKm = TRUE;
	if (fMaxX - fMinX < 1000)
	{
		bKm = FALSE;
	}
	for(int i=0;i<GRIDLING_COUNT_X;i++)
	{
		fTemp = fMinX + i * (fMaxX - fMinX)/GRIDLING_COUNT_X;
		if (bKm)
		{
			temp.Format(_T("%.2f"), fTemp/1000);
		}
		else
		{
			temp.Format(_T("%.3f"), fTemp);
		}
		pDC->DrawText(temp, &rect, DT_LEFT|DT_TOP );//
		rect.OffsetRect((m_rectCurve.Width()*1.0/GRIDLING_COUNT_X), 0);
	}//
	temp.Format(_T("km"));
	if (!bKm)
	{
		temp = _T("m");
	}
	rect.right = m_rectCurve.Width()+MARGIN_LEFT;
	rect.left = rect.right - 60;
	pDC->DrawText(temp, &rect, DT_RIGHT|DT_TOP );//
	pDC->SelectObject(&m_font);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: CDC * pDC
// Comment(2015-10-28):鼠标位置
////////////////////////////////////////////////////////////////////////////////
void COtdrTrace::DrawMouseDb( CDC* pDC )
{
	CFont* pOldFont = pDC->SelectObject(&m_font);
	//pDC->SetTextColor(RGB(0xff,0xff,0xff));//
	pDC->SetTextColor(RGB(0xff,0x00,0x00));//
	pDC->SetBkMode(TRANSPARENT);
	CRect rect;
	rect.left = m_mousePoint.x;
	rect.top = m_mousePoint.y;
	rect.right = rect.left + 120;
	rect.bottom = rect.top + 24;
	rect.OffsetRect(-10, 30);
	pDC->DrawText(m_strMouseDbAndIndex, &rect, DT_RIGHT|DT_TOP );//
	pDC->SelectObject(&m_font);
}
//创建字体
void COtdrTrace::CreateMyFont(CDC* pDC, CFont& font, CString fontName)
{
	CString strFontName = fontName;
	LOGFONT lf;
	SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lf, 0);
	if ("" == strFontName)
	{
		strFontName = lf.lfFaceName;
	}//eif
	font.CreateFont(-::MulDiv(lf.lfWidth, pDC->GetDeviceCaps(LOGPIXELSY), 72), 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, 0, 0, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_MODERN, strFontName);//
}
void COtdrTrace::OnLButtonDown(UINT nFlags, CPoint point)
{
	//// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_rectCurve.PtInRect(point))
	{
		m_nCurABSele = GetABSelectState(point);
		if (OTDRTRACE_AB_SELE_NONE != m_nCurABSele)//点击点在A/B标附近，认为后面即将移动A/B标
		{
			m_nABSele = m_nCurABSele;
			CButton::OnLButtonDown(nFlags, point);
			return;
		}//eif
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//拖动缩放
		if(!m_bLeftButtonDown)
		{
			m_rectMouseSelect.BottomRight() = point;
			m_rectMouseSelect.TopLeft() = point;
			m_bLeftButtonDown = true;			
		}//eif
	}//eif
	//TRACE(_T("OnLButtonDown..x:%d y:%d\n"),point.x,point.y);
	CButton::OnLButtonDown(nFlags, point);
	////CRectTracker tracker;
	////double xmin, xmax, ymin, ymax;
	////TRACE(_T("OnLButtonDown..x:%d y:%d\n"),point.x,point.y);
	////if (tracker.TrackRubberBand(this, point) )
	////{
	////	CPoint pt1, pt2;
	////	tracker.m_rect.NormalizeRect ();
	////	pt1= tracker.m_rect.TopLeft ();
	////	pt2= tracker.m_rect.BottomRight ();
	////	TRACE(_T("OnLButtonDown..TrackRubberBand x:%d y:%d x:%d y:%d\n"),pt1.x,pt1.y,pt2.x,pt2.y);

	////	int xmin = 2;
	////	//Invalidate(false);
	////}this->SetFocus();
}

void COtdrTrace::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!m_bLeftButtonDown)
	{
		m_nCurABSele = OTDRTRACE_AB_SELE_NONE;
		CButton::OnLButtonUp(nFlags, point);
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	if (OTDRTRACE_AB_SELE_NONE != m_nCurABSele)//拖动AB标
	{
		CButton::OnLButtonUp(nFlags, point);
		CursorABOnMove(point);
		this->InvalidateRect(m_rectCurve);
		m_bLeftButtonDown = false;
		m_nCurABSele = OTDRTRACE_AB_SELE_NONE;
		return;
	}//eif

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	if(m_rectCurve.PtInRect(point) )
	{
		if(m_bLeftButtonDown)
		{
			m_rectMouseSelect.BottomRight() = point;
		}//eif	
	}//eif
	//TRACE(_T("OnLButtonUp:%d %d %d %d \n"),m_rectMouseSelect.left, m_rectMouseSelect.right,m_rectMouseSelect.top,m_rectMouseSelect.bottom);
	m_bLeftButtonDown = false;
	if ((m_rectMouseSelect.left == m_rectMouseSelect.right) && (m_rectMouseSelect.top == m_rectMouseSelect.bottom))
	{
		ZoomOutClickForBig(m_rectMouseSelect.left, m_rectMouseSelect.top);//
		m_rectMouseSelect.SetRectEmpty();
		CButton::OnLButtonUp(nFlags, point);
		return;////
	}
	SetRange(POINT2FLOATX(m_rectMouseSelect.left), POINT2FLOATX(m_rectMouseSelect.right), POINT2FLOATY(m_rectMouseSelect.bottom), POINT2FLOATY(m_rectMouseSelect.top));
	m_rectMouseSelect.SetRectEmpty();
	CButton::OnLButtonUp(nFlags, point);
}

void COtdrTrace::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_strMouseDbAndIndex = _T("");
	if(m_rectCurve.PtInRect(point))
	{
		//移动A/B标
		if (OTDRTRACE_AB_SELE_NONE != m_nCurABSele)//
		{
			CursorABOnMove(point);
			this->InvalidateRect(m_rectCurve);
			CButton::OnMouseMove(nFlags, point);
			return;
		}//eif
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//拖动缩放
		if(m_bLeftButtonDown)
		{
			switch(m_nCurMode)
			{
			case CURVE_MOVE:
				{	
					m_rectMouseSelect.BottomRight() = point;
					break;
				}		
			case CURVE_ZOOM_IN:
			case CURVE_ZOOM_OUT:
				{
					m_rectMouseSelect.BottomRight() = point;
					break;
				}
			}//eswitch
			this->InvalidateRect(m_rectCurve);
		}
		else
		{
			//显示鼠标所在位置的dB和下标
			CalMouseDbInfo(point);
		}//eif
	}//eif
	CButton::OnMouseMove(nFlags, point);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Comment(2015-10-28):
////////////////////////////////////////////////////////////////////////////////
void COtdrTrace::CalMouseDbInfo(CPoint point)
{
	if ((0 ==m_vAllData.size()) || (0 == m_vAllData[m_nCurveIndex].m_nPointsCount))//没加载曲线
	{
		TRACE(_T("CalMouseDbInfo No Data\n"));
		return;
	}//
	//FLOAT fPos = m_cursorA.m_fPos;//方便记录拖动长度,方便选择AB标时相应移动B标
	INT nPos = point.x;
	FLOAT fPos = POINT2FLOATX(point.x);
	//TRACE(_T("m_cursorA.m_nPos:%d m_cursorA.m_fPos%.3fm\n"),nPos, fPos);
	int nIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(fPos) ;
	fPos = nIndex * m_vAllData[m_nCurveIndex].m_fDataSpacing;
	if (nIndex < 0)
	{
		return;
	}//eif
	if (nIndex >= m_vAllData[m_nCurveIndex].m_nPointsCount)
	{
		nIndex = m_vAllData[m_nCurveIndex].m_nPointsCount - 1;
	}
	TRACE(_T("nIndex:%d fPos:%.3f\n"),nIndex, fPos);
	m_strMouseDbAndIndex.Format(_T("下标:%d Db:%.3f"), nIndex, m_vAllData[m_nCurveIndex].m_pData[nIndex]);//m_pData
	//point.Offset(-m_rectCurve.left, -m_rectCurve.top);
	m_mousePoint = point;
	//m_mousePoint.Offset(-m_rectCurve.left, - m_rectCurve.top);
	this->InvalidateRect(m_rectCurve);
}
//拖动A/B标时重新计算A/B标位置
void COtdrTrace::CursorABOnMove(CPoint pointMoving)
{
	if (m_vAllData.size() <= m_nCurveIndex)//下标越界
	{
		return;
	}//
	if (OTDRTRACE_AB_SELE_A == m_nCurABSele)//拖动A
	{
		FLOAT fPos = m_cursorA.m_fPos;//方便记录拖动长度,方便选择AB标时相应移动B标
		m_cursorA.m_nPos = pointMoving.x;
		m_cursorA.m_fPos = POINT2FLOATX(pointMoving.x);
		TRACE(_T("m_cursorA.m_nPos:%d m_cursorA.m_fPos%.3fm\n"),m_cursorA.m_nPos, m_cursorA.m_fPos);
		int nIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(m_cursorA.m_fPos) ;
		m_cursorA.m_fPos = nIndex * m_vAllData[m_nCurveIndex].m_fDataSpacing;
		if (nIndex >= m_vAllData[m_nCurveIndex].m_nPointsCount)
		{
			nIndex = m_vAllData[m_nCurveIndex].m_nPointsCount - 1;
		}
		m_cursorA.m_nDataIndex = nIndex;//2014.10.17
		TRACE(_T("m_cursorA.nIndex:%d m_cursorA.m_fPos:%.3fm m_vAllData[m_nCurveIndex].m_fDataSpacing:%.3f\n"),m_cursorA.m_nPos, m_cursorA.m_fPos, m_vAllData[m_nCurveIndex].m_fDataSpacing);
		m_cursorA.m_strDistance.Format(_T("%.3fm"), m_cursorA.m_fPos);
		//float fDB=GetYDB(m_cursorA.m_fPos);
		/*float fTemp=(299792458/1000000.0)/(2*25 * 1.46000) * pointMoving.x;
		fTemp = pointMoving.x*(m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN])/818 + m_fRangeX[OTDR_TRACE_MIN];*/
		//TRACE(_T("m_cursorA.m_nPos:%d %.3fm\n"),m_cursorA.m_nPos, fTemp);
		if (IsCurrentTypeAB())//当前选中AB标
		{
			fPos = m_cursorA.m_fPos - fPos;
			m_cursorB.m_fPos = m_cursorB.m_fPos + fPos;
			m_cursorB.m_strDistance.Format(_T("%.3fm"), m_cursorB.m_fPos);
		}//eif
		
	}//eif
	if (OTDRTRACE_AB_SELE_B == m_nCurABSele)//拖动B
	{
		FLOAT fPos = m_cursorB.m_fPos;//方便记录拖动长度,方便选择AB标时相应移动A标
		m_cursorB.m_nPos = pointMoving.x;
		m_cursorB.m_fPos = POINT2FLOATX(pointMoving.x);
		int nIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(m_cursorB.m_fPos);
		m_cursorB.m_fPos = nIndex * m_vAllData[m_nCurveIndex].m_fDataSpacing;
		m_cursorB.m_strDistance.Format(_T("%.3fm"), m_cursorB.m_fPos);
		if (nIndex >= m_vAllData[m_nCurveIndex].m_nPointsCount)
		{
			nIndex = m_vAllData[m_nCurveIndex].m_nPointsCount - 1;
		}
		m_cursorB.m_nDataIndex = nIndex;//2014.10.17
		//float fDB=GetYDB(m_cursorB.m_fPos);
		if (IsCurrentTypeAB())//当前选中AB标
		{
			fPos = m_cursorB.m_fPos - fPos;
			m_cursorA.m_fPos = m_cursorA.m_fPos + fPos;
			m_cursorA.m_strDistance.Format(_T("%.3fm"), m_cursorA.m_fPos);
		}//eif
	}//eif
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//光标移动时计算AB对应的轴坐标
//数据点个数大于屏幕象素点个数时直接返回鼠标位置，小于时寻找最近的数据点位置
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//INT COtdrTrace::GetABPositionOnMove(CPoint pointMoving)
//{
//	if (m_vAllData.size() < m_nCurveIndex + 1)//防止越界
//	{
//		return 0;
//	}//
//	INT nStartIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(m_fRangeX[0]);
//	INT nEndIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(m_fRangeX[1]);
//	if (nEndIndex - nStartIndex + 1 >= m_rectCurve.Width())//数据点个数大于屏幕象素点个数时直接返回鼠标位置
//	{
//		return pointMoving.x;
//	}//eif
//
//	//小于时寻找最近的数据点位置
//	INT nFloor,nCeil;
//	nFloor = pointMoving.x / (nEndIndex - nStartIndex + 1);
//	nCeil = ceil(nFloor);
//	nFloor = floor(nFloor);
//	if (nCeil == nFloor);//刚好在点上
//	{
//		return pointMoving.x;
//	}//eif
//	if (pointMoving.x - nStartIndex > nEndIndex - pointMoving.x)//离左边近
//	{
//		return nStartIndex;
//	}//eif
//	return nEndIndex;//离右边近
//}
////得到AB标上面的距离
//FLOAT COtdrTrace::GetABDistanceOnMove(CPoint pointMoving, INT nXAB)
//{
//	return 0;
//}
//按下鼠标时，判断是否选中AB标,未选中返回OTDRTRACE_AB_SELE_NONE，选中A返回OTDRTRACE_AB_SELE_A，选中B返回OTDRTRACE_AB_SELE_B
INT COtdrTrace::GetABSelectState(CPoint pointClick)
{
	INT nReturn = OTDRTRACE_AB_SELE_NONE;
	INT nMarginA = -1;
	INT nMarginB = -1;
	int nTemp;
	if (IsInCurRangeX(m_cursorA.m_fPos))//A在屏幕显示范围内
	{
		nTemp = FLOAT2POINTX(m_cursorA.m_fPos);//光标屏幕位置，象素
		if (abs(nTemp - pointClick.x) < OTDR_TRACE_CURSOR_AB_VALID_SELE)
		{
			nMarginA = abs(nTemp - pointClick.x);
		}//eif
	}//eif

	if (IsInCurRangeX(m_cursorB.m_fPos))//B在屏幕显示范围内
	{
		nTemp = FLOAT2POINTX(m_cursorB.m_fPos);//光标屏幕位置，象素
		if (abs(nTemp - pointClick.x) < OTDR_TRACE_CURSOR_AB_VALID_SELE)
		{
			nMarginB = abs(nTemp - pointClick.x);
		}//eif
	}//eif

	if ((-1 != nMarginA) && (-1 != nMarginB))//AB都在移动有效区域，选最近的
	{
		if (nMarginA <= nMarginB)
		{
			nReturn = OTDRTRACE_AB_SELE_A;
		}
		else{
			nReturn = OTDRTRACE_AB_SELE_B;
		}//eif
	}
	else if (-1 != nMarginA)//只有A在有效区域
	{
		nReturn = OTDRTRACE_AB_SELE_A;
	}
	else if (-1 != nMarginB)//只有B在有效区域
	{
		nReturn = OTDRTRACE_AB_SELE_B;
	}//eif
	return nReturn;
}
//判断是否在当前显示范围内,针对水平方向
BOOL COtdrTrace::IsInCurRangeX(FLOAT fDistance)
{
	return ((fDistance >= m_fRangeX[OTDR_TRACE_MIN]) && (fDistance <= m_fRangeX[OTDR_TRACE_MAX]));
}
//判断是否在当前显示范围内,针对竖直方向
BOOL COtdrTrace::IsInCurRangeY(FLOAT fDistance)
{
	return ((fDistance >= m_fRangeY[OTDR_TRACE_MIN]) && (fDistance <= m_fRangeY[OTDR_TRACE_MAX]));
}
void COtdrTrace::OnSize(UINT nType, int cx, int cy)
{
	CButton::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	GetClientRect(m_rectClient);
	m_rectCurve = m_rectClient;

	if(m_dcCurve.GetSafeHdc())
	{
		CDC *pDC = GetDC(); // Get device context
		InitPaint(pDC);
		DrawCurves(&m_dcCurve,-1);
		ReleaseDC(pDC);
	}//eif
}
//计算绘图区域
void COtdrTrace::CalculateRect()
{
	GetClientRect(m_rectClient);
	m_rectCurve = m_rectClient;
}
void COtdrTrace::SetRange(float xmin, float xmax, float ymin, float ymax, BOOL bSetScrollInof) 
{
	if (xmin == xmax || ymin == ymax)
	{
		return;
	}
	else if (xmin > xmax || ymin > ymax)
	{
		return;
	}//eif

	if (xmin < 0)
	{
		xmin = 0;
	}//eif

	if (0 == m_vAllData.size())
	{
		return;
	}//eif
	if (xmax > m_vAllData[0].m_fMaxDistance)
	{
		xmax =  m_vAllData[0].m_fMaxDistance;
	}//eif
	//TRACE(_T("m_vAllData[0].DistanceToIndex(xmax):%d %d"),m_vAllData[0].DistanceToIndex(xmax), m_vAllData[0].DistanceToIndex(xmin));
	if((!(m_vAllData[0].DistanceToIndex(xmax) - m_vAllData[0].DistanceToIndex(xmin) >= OTDR_TRACE_VALID_NUM_LOWEST)) || (!(ymax - ymin > OTDR_TRACE_Y_MIN_CHANGE)))//只有一个点
	{
		return;
	}//eif
	if (ymax - ymin <= OTDR_TRACE_Y_MIN_CHANGE)
	{
		return;
	}//eif
	if (ymin < OTDR_TRACE_Y_MIN)
	{
		ymin = OTDR_TRACE_Y_MIN;
	}//eif
	if (ymax > OTDR_TRACE_Y_MAX)
	{
		ymax = OTDR_TRACE_Y_MAX;
	}//eif
	m_vAllData[0].m_fRangeX[0] = xmin;
	m_vAllData[0].m_fRangeX[1] = xmax;
	m_vAllData[0].m_fRangeY[0] = ymin;
	m_vAllData[0].m_fRangeY[1] = ymax;
	 
	
	m_fRangeX[OTDR_TRACE_MIN] = xmin;
	m_fRangeX[OTDR_TRACE_MAX] = xmax;
	m_fRangeY[OTDR_TRACE_MIN] = ymin;
	m_fRangeY[OTDR_TRACE_MAX] = ymax;

	m_fResolutionX = (m_fRangeX[OTDR_TRACE_MAX] - m_fRangeX[OTDR_TRACE_MIN]) / m_rectCurve.Width();
	m_fResolutionY = (m_fRangeY[OTDR_TRACE_MAX] - m_fRangeY[OTDR_TRACE_MIN]) / m_rectCurve.Height();
	DrawCurves(&m_dcCurve,m_nCurveIndex);
	if (bSetScrollInof)
	{
		SetMyScrollInfo(xmin, xmax,ymin,ymax);
	}

	Invalidate(FALSE);
}
//设置最长距离
void COtdrTrace::SetMaxDistance(FLOAT fMaxDistance)
{
	if (m_vAllData.size() > 0)
	{
		if(m_vAllData[0].m_fMaxDistance < fMaxDistance)//只有一个点
		{
			m_vAllData[0].m_fMaxDistance = fMaxDistance;
		}//eif
		m_fMaxDistance=m_vAllData[0].m_fMaxDistance;
	}//eif
}
//得到最长距离
FLOAT COtdrTrace::GetMaxDistance()
{
	if (m_vAllData.size() > 0)
	{
		return m_vAllData[0].m_fMaxDistance;
	}//eif
	
	return 0;
}
//根据当前选择的A/B标，计算缩放时的中心偏移
FLOAT COtdrTrace::GetCenterOffset()
{
	if (IsCurrentTypeAB())//当前选中AB标
	{
		return (m_cursorA.m_fPos + m_cursorB.m_fPos)/2;
	}//eif
	if (OTDRTRACE_AB_SELE_A == m_nABSele)//A
	{
		//return (m_cursorA.m_fPos - m_fRangeX[OTDR_TRACE_MIN])/(m_fRangeX[OTDR_TRACE_MAX] + m_fRangeX[OTDR_TRACE_MIN]);
		return m_cursorA.m_fPos;
	}
	else if (OTDRTRACE_AB_SELE_B == m_nABSele)//B
	{
		//return (m_cursorB.m_fPos - m_fRangeX[OTDR_TRACE_MIN])/(m_fRangeX[OTDR_TRACE_MAX] + m_fRangeX[OTDR_TRACE_MIN]);
		return m_cursorB.m_fPos;// - m_fRangeX[OTDR_TRACE_MIN])/(m_fRangeX[OTDR_TRACE_MAX] + m_fRangeX[OTDR_TRACE_MIN]);
	}//eif
	return (m_cursorA.m_fPos + m_cursorB.m_fPos)/2;
}
//得到某点对应的db值。fPos:某处的位置
//如果比当前最大点数大，如多曲线情况，则以最后一点db值作为返回值
FLOAT COtdrTrace::GetYDB(FLOAT fPos)
{
	if (m_vAllData.size()<m_nCurveIndex + 1)
	{
		return 0;
	}//
	//INT nIndex = FLOAT2POINTX(y);
	INT nIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(fPos);
	TRACE(_T("GetYDBnIndex:%d  fPos:%.3f m_nPointsCount:%d\n"), nIndex, fPos, m_vAllData[m_nCurveIndex].m_nPointsCount);
	if (nIndex >= m_vAllData[m_nCurveIndex].m_nPointsCount)
	{
		nIndex = m_vAllData[m_nCurveIndex].m_nPointsCount - 1;
	}//
	return m_vAllData[m_nCurveIndex].m_pData[nIndex];
}
//水平放大 fPercent放大比例，默认2%
void COtdrTrace::ZoomInHorizonForBig(FLOAT fPercent)
{
	FLOAT fCenter = GetCenterOffset();
	FLOAT m_fRangeXMIN = fCenter - (fCenter - m_fRangeX[OTDR_TRACE_MIN])*(1 - fPercent);
	FLOAT m_fRangeXMAX = fCenter + (m_fRangeX[OTDR_TRACE_MAX] - fCenter)*(1 - fPercent);
	SetRange(m_fRangeXMIN, m_fRangeXMAX, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX]);
}
//水平缩小 fPercent放大比例，默认2%
void COtdrTrace::ZoomOutHorizonForSmall(FLOAT fPercent)
{
	FLOAT fCenter = GetCenterOffset();
	FLOAT m_fRangeXMIN = fCenter - (fCenter - m_fRangeX[OTDR_TRACE_MIN])*(1/(1 - fPercent));
	FLOAT m_fRangeXMAX = fCenter + (m_fRangeX[OTDR_TRACE_MAX] - fCenter)*(1/(1 - fPercent));
	SetRange(m_fRangeXMIN, m_fRangeXMAX, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX]);
}
//竖直放大 fPercent放大比例，默认2%
void COtdrTrace::ZoomInVertialForBig(FLOAT fPercent)
{
	FLOAT fCenter = GetCenterOffset();//AB标距离
	FLOAT fDb = GetYDB(fCenter);//得到光标处DB值
	FLOAT m_fRangeYMIN = fDb - (fDb - m_fRangeY[OTDR_TRACE_MIN])*(1 - fPercent);
	FLOAT m_fRangeYMAX = fDb + (m_fRangeY[OTDR_TRACE_MAX] - fDb)*(1 - fPercent);
	SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_fRangeYMIN, m_fRangeYMAX);
}
//竖直缩小fPercent放大比例，默认2%
void COtdrTrace::ZoomOutVertialForSmall(FLOAT fPercent)
{
	FLOAT fCenter = GetCenterOffset();//AB标距离
	FLOAT fDb = GetYDB(fCenter);//得到光标处DB值
	FLOAT m_fRangeYMIN = fDb - (fDb - m_fRangeY[OTDR_TRACE_MIN])*(1/(1 - fPercent));
	FLOAT m_fRangeYMAX = fDb + (m_fRangeY[OTDR_TRACE_MAX] - fDb)*(1/(1 - fPercent));
	SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_fRangeYMIN, m_fRangeYMAX);
}
//还原，水平竖直缩放为0
void COtdrTrace::ZoomReset()
{
	//竖直偏移量为0
	for(int i=0; i<m_vAllData.size(); i++)
	{
		m_vAllData[i].m_nOffsetY = 0;
	}
	SetRange(0, GetMaxDistance(), OTDR_TRACE_Y_MIN, OTDR_TRACE_Y_MAX);
	SetScrollRangeX();//重设水平方向范围
}
////单击放大，默认放大10%  nPointX：点击的水平x坐标  nPointY：点击的Y坐标 
void COtdrTrace::ZoomOutClickForBig(INT nPointX, INT nPointY, FLOAT fPercent)
{
	m_rectMouseSelect.InflateRect(150,150);
	SetRange(POINT2FLOATX(m_rectMouseSelect.left), POINT2FLOATX(m_rectMouseSelect.right), POINT2FLOATY(m_rectMouseSelect.bottom), POINT2FLOATY(m_rectMouseSelect.top));
	
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void COtdrTrace::SetHorScroll() //设置水平滚动条
{
	//水平滚动条
	SCROLLINFO siHor;
	siHor.cbSize = sizeof(SCROLLINFO);
	siHor.fMask = SIF_ALL; 
	siHor.nMin = 0;
	if (0 != m_fMaxDistance)
	{
		siHor.nMax = m_fMaxDistance;//这么做后windows会把最大的滚动条位置限制为si.nmax-si.npage+1,而不是si.nmax
	}
	else
	{
		siHor.nMax = m_rectCurve.Width();
	}
	//siHor.nMax = 66;
	//siHor.nPage = 22;//m_rectCurve.Width();
	siHor.nMax = m_rectCurve.Width();//zll 2013.4.23
	siHor.nPage = m_rectCurve.Width();//zll 2013.4.23
	siHor.nPos = 0;
	SetScrollInfo(SB_HORZ, &siHor, TRUE);
}

void COtdrTrace::SetVerScoll() //设置竖直滚动条
{
	SCROLLINFO siVer;
	siVer.cbSize = sizeof(SCROLLINFO);
	siVer.fMask = SIF_ALL; 
	siVer.nMin = OTDR_TRACE_Y_MIN;
	siVer.nMax = OTDR_TRACE_Y_MAX;
	siVer.nPage = OTDR_TRACE_Y_MAX;
	siVer.nPos = 0;
	//this->SetScrollRange( SB_VERT,0,10000);
	SetScrollInfo(SB_VERT, &siVer, TRUE);
}

//滚动条
//初始化滚动条
void COtdrTrace::InitScrollInfo()
{
	CRect rectClient;
	GetClientRect(&rectClient);
	m_rectCurve.CopyRect(&rectClient);
	m_nHorzMaxSize = m_rectCurve.Width();
	m_nVertMaxSize = OTDR_TRACE_Y_MAX * OTDR_TRACE_Y_FACTOR;

	m_nHorzPageSize = m_rectCurve.Width();
	if (0==m_rectCurve.Height())
	{
		return;
	}
	m_nVertPageSize = (OTDR_TRACE_Y_MAX - OTDR_TRACE_Y_MIN) * OTDR_TRACE_Y_FACTOR/m_rectCurve.Height();

	m_nHorzOneStep = 0;
	m_nVertOneStep = (OTDR_TRACE_Y_MAX - OTDR_TRACE_Y_MIN) * OTDR_TRACE_Y_FACTOR * OTDR_TRACE_DEFAULT_ZOOM_PERCENT;
	m_nHorzPos = 0;
	m_nVertPos = 0;
	//水平
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_ALL; 
	si.nMin = 0;
	si.nMax = m_rectCurve.Width();
	si.nPage = m_rectCurve.Width();//
	si.nPos = 0;
	SetScrollInfo(SB_HORZ, &si, TRUE);
	//竖直
	si.fMask = SIF_ALL; 
	si.nMin = OTDR_TRACE_Y_MIN * OTDR_TRACE_Y_FACTOR;
	si.nMax = OTDR_TRACE_Y_MAX * OTDR_TRACE_Y_FACTOR;
	si.nPage = (OTDR_TRACE_Y_MAX - OTDR_TRACE_Y_MIN) * OTDR_TRACE_Y_FACTOR;//
	si.nPos = 0;
	SetScrollInfo(SB_VERT, &si, TRUE);
	//SetScrollRange(OTDR_TRACE_Y_MIN, OTDR_TRACE_Y_MAX);
}

//设置滚动条范围
void COtdrTrace::SetMyScrollInfo(float xmin, float xmax, float ymin, float ymax)
{
	SCROLLINFO si;
	//水平
	GetScrollInfo(SB_HORZ, &si);
	si.nPage = xmax - xmin;
	SetScrollInfo(SB_HORZ, &si, TRUE);

	m_nHorzPos = xmin;
	m_nHorzOneStep = si.nPage * OTDR_TRACE_DEFAULT_ZOOM_PERCENT;
	m_nHorzPageSize = si.nPage;
	SetScrollRange(SB_HORZ, 0, m_fMaxDistance);
	SetScrollPos(SB_HORZ, m_nHorzPos);

	//竖直
	ymin *= OTDR_TRACE_Y_FACTOR;
	ymax *= OTDR_TRACE_Y_FACTOR;
	GetScrollInfo(SB_VERT, &si);
	si.nPage = ymax - ymin;
	//si.nMax = ymax;
	SetScrollInfo(SB_VERT, &si, TRUE);

	m_nVertPos = ymin;
	m_nVertOneStep = (ymax - ymin) * OTDR_TRACE_DEFAULT_ZOOM_PERCENT;
	m_nVertPageSize = ymax - ymin;
	//m_nVertMaxSize = 
	SetScrollPos(SB_VERT, m_nVertPos);
	//
}

void COtdrTrace::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch(nSBCode)
	{
		//////////////case SB_LEFT://按Home触发
		//////////////	m_nHorzPos = 0;
		//////////////	this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//////////////	SetRange(0, m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		//////////////	break;
	case SB_LINELEFT:
		if(0 == m_nHorzPos)
		{
			break;
		}
		m_nHorzPos -= m_nHorzOneStep;
		if (m_nHorzPos < 0)
		{
			m_nHorzPos = 0;
		}//

		this->SetScrollPos(SB_HORZ, m_nHorzPos);
		//TRACE(_T("SB_LINELEFT: %d\n"),m_nHorzPos);
		if (0 == m_nHorzPos)
		{
			SetRange(0, m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		}
		else
		{
			SetRange(m_fRangeX[OTDR_TRACE_MIN] - m_nHorzOneStep, m_fRangeX[OTDR_TRACE_MAX]  - m_nHorzOneStep, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		}//eif
		break;
	case SB_PAGELEFT:
		if (m_nHorzPos - m_nHorzPageSize < 0)
		{
			m_nHorzPos = 0;
			this->SetScrollPos(SB_HORZ, 0);
			SetRange(0, m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
			break;
		}//eif
		m_nHorzPos -= m_nHorzPageSize;
		if(m_nHorzPos<0)
		{
			m_nHorzPos = 0;
		}
		this->SetScrollPos(SB_HORZ,m_nHorzPos);
		SetRange(m_fRangeX[OTDR_TRACE_MIN] - m_nHorzPageSize, m_fRangeX[OTDR_TRACE_MAX]  - m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		break;
	case SB_LINERIGHT:
		if (m_nHorzPos + m_nHorzPageSize > m_nHorzMaxSize)
		{
			break;
		}//eif
		m_nHorzPos += m_nHorzOneStep;
		if(m_nHorzPos>m_nHorzMaxSize)
		{
			m_nHorzPos = m_nHorzMaxSize;
		}
		this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//TRACE(_T("SB_LINERIGHT: %d  page: %d max: %d\n"),m_nHorzPos,m_nHorzPageSize,m_nHorzMaxSize);
		SetRange(m_fRangeX[OTDR_TRACE_MIN] + m_nHorzOneStep, m_fRangeX[OTDR_TRACE_MAX] + m_nHorzOneStep, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		break;
	case SB_PAGERIGHT:
		if (m_nHorzPos + m_nHorzPageSize > m_nHorzMaxSize)
		{
			m_nHorzPos = m_nHorzMaxSize;
			SetRange(m_fMaxDistance - m_nHorzPageSize, m_fMaxDistance, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
			break;
		}//eif
		m_nHorzPos += m_nHorzPageSize;
		this->SetScrollPos(SB_HORZ,m_nHorzPos);
		if (m_nHorzPos + m_nHorzPageSize > m_fMaxDistance)
		{
			SetRange(m_fMaxDistance - m_nHorzPageSize, m_fMaxDistance, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
			break;
		}
		SetRange(m_nHorzPos, m_nHorzPos + m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		break;
		//////////////case SB_RIGHT://按End触发
		//////////////	m_nHorzPos = m_nHorzMaxSize;
		//////////////	this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//////////////	SetRange(m_fMaxDistance - m_nHorzPageSize, m_fMaxDistance, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		//////////////	break;
	case SB_THUMBTRACK://拖动过程中
		SCROLLINFO si;
		GetScrollInfo(SB_HORZ, &si);
		m_nHorzPos = si.nTrackPos;
		this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//TRACE(_T("SB_THUMBTRACK0: %d\n"),m_nHorzPos);
		SetRange(m_nHorzPos, m_nHorzPos + m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		break;
	case SB_THUMBPOSITION://拖动结束
		//SCROLLINFO si;
		GetScrollInfo(SB_HORZ, &si);
		m_nHorzPos = si.nPos;
		this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//TRACE(_T("SB_THUMBPOSITION1: %d\n"),m_nHorzPos);
		SetRange(m_nHorzPos, m_nHorzPos + m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		break;
	default:
		break;
	}//eofswitch
	CButton::OnHScroll(nSBCode, nPos, pScrollBar);
}
void COtdrTrace::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nSBCode)
	{
		//////////////case SB_LEFT://按Home触发
		//////////////	m_nHorzPos = 0;
		//////////////	this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//////////////	SetRange(0, m_nHorzPageSize, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		//////////////	break;
		//////////////case SB_RIGHT://按End触发
		//////////////	m_nHorzPos = m_nHorzMaxSize;
		//////////////	this->SetScrollPos(SB_HORZ,m_nHorzPos);
		//////////////	SetRange(m_fMaxDistance - m_nHorzPageSize, m_fMaxDistance, m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX], FALSE);
		//////////////	break;
	case SB_LINELEFT:
		if(0 == m_fRangeY[OTDR_TRACE_MIN])
		{
			break;
		}
		m_nVertPos -= m_nVertOneStep;
		if (m_nVertPos < 0)
		{
			m_nVertPos = 0;
		}//

		this->SetScrollPos(SB_VERT, m_nVertPos);
		//TRACE(_T("SB_LINELEFT: %d\n"),m_nVertPos);
		if (0 == m_nVertPos)
		{
			SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], OTDR_TRACE_Y_MIN, OTDR_TRACE_Y_MIN + m_nVertPageSize / OTDR_TRACE_Y_FACTOR, FALSE);
		}
		else
		{
			SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_fRangeY[OTDR_TRACE_MIN] - m_nVertOneStep / OTDR_TRACE_Y_FACTOR, m_fRangeY[OTDR_TRACE_MAX] - m_nVertOneStep / OTDR_TRACE_Y_FACTOR, FALSE);
		}//eif
		break;
	case SB_PAGELEFT:
		m_nVertPos -= m_nVertPageSize;
		if(m_nVertPos<0)
		{
			m_nVertPos = 0;
		}
		this->SetScrollPos(SB_VERT,m_nVertPos);
		SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_nVertPos / OTDR_TRACE_Y_FACTOR, (m_nVertPos + m_nVertPageSize) / OTDR_TRACE_Y_FACTOR, FALSE);
		break;
	case SB_LINERIGHT:
		if (m_nVertPos == m_nVertMaxSize)
		{
			break;
		}//eif
		m_nVertPos += m_nVertOneStep;
		if(m_nVertPos > m_nVertMaxSize)
		{
			m_nVertPos = m_nVertMaxSize;
		}
		this->SetScrollPos(SB_VERT,m_nVertPos);
		//TRACE(_T("SB_LINERIGHT: %d  page: %d max: %d\n"),m_nVertPos,m_nVertPageSize,m_nVertMaxSize);
		SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_fRangeY[OTDR_TRACE_MIN] + m_nVertOneStep / OTDR_TRACE_Y_FACTOR, m_fRangeY[OTDR_TRACE_MAX] + m_nVertOneStep / OTDR_TRACE_Y_FACTOR, FALSE);
		break;
	case SB_PAGERIGHT:
		m_nVertPos += m_nVertPageSize;
		if(m_nVertPos>m_nVertMaxSize)
		{
			m_nVertPos = m_nVertMaxSize;
			this->SetScrollPos(SB_VERT,m_nVertPos);
			//TRACE(_T("SB_LINERIGHT: %d  page: %.2f max: %.2f\n"),m_nVertPos,m_fRangeY[OTDR_TRACE_MIN] - m_nVertPageSize,m_fRangeY[OTDR_TRACE_MAX] - m_nVertPageSize);
			SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], OTDR_TRACE_Y_MAX - m_nVertPageSize / OTDR_TRACE_Y_FACTOR, OTDR_TRACE_Y_MAX, FALSE);
			break;
		}//eif
		this->SetScrollPos(SB_VERT,m_nVertPos);
		//TRACE(_T("SB_LINERIGHT: %d  page: %.2f max: %.2f\n"),m_nVertPos,m_fRangeY[OTDR_TRACE_MIN] - m_nVertPageSize,m_fRangeY[OTDR_TRACE_MAX] - m_nVertPageSize);
		SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_nVertPos / OTDR_TRACE_Y_FACTOR, (m_nVertPos + m_nVertPageSize) / OTDR_TRACE_Y_FACTOR, FALSE);
		break;
	case SB_THUMBTRACK://拖动过程中
		SCROLLINFO si;
		GetScrollInfo(SB_VERT, &si);
		m_nVertPos = si.nTrackPos;
		this->SetScrollPos(SB_VERT,m_nVertPos);
		//TRACE(_T("SB_THUMBTRACK0: %d\n"),m_nVertPos);
		SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_nVertPos / OTDR_TRACE_Y_FACTOR, (m_nVertPos + m_nVertPageSize) / OTDR_TRACE_Y_FACTOR, FALSE);
		break;
	case SB_THUMBPOSITION://拖动结束
		//SCROLLINFO si;
		GetScrollInfo(SB_VERT, &si);
		m_nVertPos = si.nPos;
		this->SetScrollPos(SB_VERT,m_nVertPos);
		//TRACE(_T("SB_THUMBPOSITION1: %d\n"),m_nVertPos);
		SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_nVertPos / OTDR_TRACE_Y_FACTOR, (m_nVertPos + m_nVertPageSize) / OTDR_TRACE_Y_FACTOR, FALSE);
		break;
	default:
		break;
	}//eofswitch

	CButton::OnVScroll(nSBCode, nPos, pScrollBar);
}

//重设水平方向范围//zll2013.4.23
void COtdrTrace::SetScrollRangeX()
{
	SetScrollRange(SB_HORZ, 0, m_fMaxDistance);
	m_nHorzMaxSize = m_fMaxDistance;
}

//选择了事件列表后，重新绘制曲线;wcq2011-11.15
//nIndex:从0开始相应曲线第几个事件点
void COtdrTrace::MoveEventList(INT nIndex)
{
	if (m_vAllData.size()==0)//若m_vAllData内无数据则先退出，否则超出范围
	{
		return;
	}
	if (OTDRTRACE_AB_SELE_A == m_nABSele) //选中A
	{
		m_cursorA.m_fPos = m_vAllData[m_nCurveIndex].m_vAllEvents[nIndex].m_distance;
	}	
	else if (OTDRTRACE_AB_SELE_B == m_nABSele)////选中B
	{
		m_cursorB.m_fPos = m_vAllData[m_nCurveIndex].m_vAllEvents[nIndex].m_distance;
	}
	Invalidate();//wcq2011.11.16
}
//得到当前光标对应当前曲线下标
INT COtdrTrace::GetCurrentCursorIndex()
{
	if (0  == m_nABSele)
	{
		return 0;
	}//
	int nIndex = 0;
	if (OTDRTRACE_AB_SELE_A == m_nABSele)//拖动A
	{
		nIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(m_cursorA.m_fPos);
	}//eif
	else if(OTDRTRACE_AB_SELE_B == m_nABSele)//拖动B
	{
		nIndex = m_vAllData[m_nCurveIndex].DistanceToIndex(m_cursorB.m_fPos);
	}//eif
	return nIndex;
}

/*
***************************************************************
函数名称:             CalculDispRect()                                                                               
函数说明:             划分曲线显示区，XY轴信息显示区，光纤信息显示区的矩形                                            
入口参数:             bDisplayEventList,是否需要显示事件列表                                                          
出口参数:             无                                                                                             
建立时间:             2011-07-23                                                                
Write By:             XJF                                                                                           
***************************************************************
*/
void COtdrTrace::CalCulDispRect()
{
	//曲线显示区
	GetClientRect(m_rectClient);
	//坐标显示区
	m_rectCurve.left=m_rectCurve.left + MARGIN_LEFT;
	m_rectCurve.right=m_rectCurve.right;//wcq2012.02.14
	m_rectCurve.top=m_rectCurve.top;//wcq2011.12.09
	m_rectCurve.bottom=m_rectCurve.bottom - MARGIN_TOP;
}

CGraphElement* COtdrTrace::GetSeleCurve()
{
	TRACE(_T("%d\n"),m_nCurveIndex);
	return &m_vAllData[m_nCurveIndex];
}
//当前是否选中AB标，同时移动AB标
BOOL COtdrTrace::IsCurrentTypeAB()
{
	return OTDRTRACE_AB_SELE_DOUBLE_AB == m_nABType;
}
//OTDRTRACE_AB_TYPE_SINGLE_A_OR_B或OTDRTRACE_AB_SELE_DOUBLE_AB
void COtdrTrace::SetCurrentTypeAB(INT nABType)
{
	m_nABType = nABType;
	Invalidate(FALSE);
}
//从新计算下最长距离，主要是针对删除一条曲线
void COtdrTrace::ReCalMaxDistance()
{
	FLOAT fMax = 0;
	if (0 == m_vAllData.size())
	{
		return;
	}//eif

	for (int i=0; i<m_vAllData.size(); i++)
	{
		fMax = max(m_vAllData[i].m_fLength, fMax);
	}//efor
	m_vAllData[0].m_fMaxDistance = fMax;
	m_fMaxDistance = fMax;
}
//新增了曲线或删除了曲线，计算下最长距离等
void COtdrTrace::TraceCountChanged()
{
	if (m_vAllData.size()<m_nCurveIndex+1)
	{
		m_nCurveIndex=m_vAllData.size()-1;
		if (m_nCurveIndex<0)
		{
			m_nCurveIndex=0;
		}
	}
	ReCalMaxDistance();//从新计算下最长距离，主要是针对删除一条曲线
	SetRange(m_fRangeX[OTDR_TRACE_MIN], m_fRangeX[OTDR_TRACE_MAX], m_fRangeY[OTDR_TRACE_MIN], m_fRangeY[OTDR_TRACE_MAX]);
}
//设为当前选中曲线
void COtdrTrace::SetCurrentSeleTrace(INT nIndex)
{
	
}
void COtdrTrace::SetShowCurve(int iNum,BOOL boolShow)
{
    if (m_vAllData.size()>iNum)
    {
		m_vAllData[iNum].m_bShow=boolShow;
    }    
}

void COtdrTrace:: SetCurveCursorData()
{

}

//清空所有数据2013.08.14
void COtdrTrace::ReleaseAllData()
{
	for(int i = 0; i < m_vAllData.size(); i++)
	{
		if(NULL != m_vAllData[i].m_pData)
		{
			delete[] m_vAllData[i].m_pData;
		}
		if(NULL != m_vAllData[i].m_pPointsToDraw)
		{
			delete[] m_vAllData[i].m_pPointsToDraw;
		}
		m_vAllData[i].m_vEventPoints.clear();
	}//efor
	m_vAllData.clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: WORD * pData
// Parameter: INT nPointsCount:数据点个数
// Parameter: FLOAT fRange:测量范围
// Comment(2015-4-1):显示一条曲线数据，不含事件列表
////////////////////////////////////////////////////////////////////////////////
void COtdrTrace::ShowCurve( WORD* pData, INT nPointsCount, FLOAT fRange)
{
	if (nPointsCount <= 0)
	{
		return;
	}//eif
	FLOAT fTestRange = (0 == fRange)?nPointsCount:fRange;

	if (0 == m_vAllData.size())//第一次添加数据,添加一个曲线数据
	{
		CGraphElement element;
		element.m_LineColor = RGB(0, 0, 255);
		element.m_fRangeX[0]=0;
		element.m_fRangeX[1]= nPointsCount;
		element.m_fRangeY[0]=OTDR_TRACE_Y_MIN;
		element.m_fRangeY[1]=OTDR_TRACE_Y_MAX;
		//element.m_pData = new FLOAT[nPointsCount];
		element.m_fontEventKm = &(m_fontEventKm);
		element.m_fontEventNum = &(m_fontEventNum);
		element.m_penLineVertical = &(m_penLineVertical);
		m_vAllData.push_back(element);
		//m_otdrTrace.SetRange(0, pOtdrAllUploadData->TestRange, 0, 65.535);//
	}//eif
	CGraphElement& element = m_vAllData[0];//这里只考虑一条曲线

	if (m_nPointCountMax < nPointsCount)
	{
		if (NULL != m_pFloatData)
		{
			delete[] m_pFloatData;
		}//eif
		m_nPointCountMax = nPointsCount;
		m_pFloatData = new FLOAT[nPointsCount];
		element.ReNew(nPointsCount);//
	}//eif
	//element.ReNew(nPointsCount);//

	//WORD* pWord = pData;
	for (int i=0; i<nPointsCount; i++)//转换dB
	{
		m_pFloatData[i] = (65535-(int)pData[i])/1000.0;
	}//efor

	if (fabs(element.m_fLength - fTestRange) > 0.00000001)//两次长度不一样, 重新设置范围
	{
		element.m_nPointsCount = nPointsCount;
		element.m_fDataSpacing = fTestRange*1.0/nPointsCount;
		element.m_fLength = fTestRange;
		element.m_fMaxDistance =element.m_fLength;
		SetMaxDistance(fTestRange);
		SetScrollRangeX();//
		SetRange(0, fTestRange, OTDR_TRACE_Y_MIN, OTDR_TRACE_Y_MAX);//
	}//eif
	element.m_nPointsCount = nPointsCount;
	element.m_fDataSpacing = fTestRange*1.0/nPointsCount;
	memcpy(element.m_pData, m_pFloatData, sizeof(FLOAT) * nPointsCount);

	//得到曲线中的事件列表信息
	ConvertEvent(element);//, pOtdrAllUploadData

	//绘曲线
	DrawCurves(&m_dcCurve);

	Invalidate(FALSE);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: INT * pData
// Parameter: INT nPointsCount
// Parameter: FLOAT fRange
// Parameter: BOOL bReverse:是否已用65535减过了。TRUE:减过; FALSE:没
// Comment(2015-4-1):显示一条曲线数据，不含事件列表
////////////////////////////////////////////////////////////////////////////////
void COtdrTrace::ShowCurveByIntData( INT* pData, INT nPointsCount, FLOAT fRange /*= 0*/ , BOOL bReverse)
{
	if (nPointsCount <= 0)
	{
		return;
	}//eif
	FLOAT fTestRange = (0 == fRange)?nPointsCount:fRange;

	if (0 == m_vAllData.size())//第一次添加数据,添加一个曲线数据
	{
		CGraphElement element;
		element.m_LineColor = RGB(0, 0, 255);
		element.m_fRangeX[0]=0;
		element.m_fRangeX[1]= fTestRange;
		element.m_fRangeY[0]=OTDR_TRACE_Y_MIN;
		element.m_fRangeY[1]=OTDR_TRACE_Y_MAX;
		//element.m_pData = new FLOAT[nPointsCount];
		element.m_fontEventKm = &(m_fontEventKm);
		element.m_fontEventNum = &(m_fontEventNum);
		element.m_penLineVertical = &(m_penLineVertical);
		m_vAllData.push_back(element);
		//m_otdrTrace.SetRange(0, pOtdrAllUploadData->TestRange, 0, 65.535);//
	}//eif
	CGraphElement& element = m_vAllData[0];//这里只考虑一条曲线

	if (m_nPointCountMax < nPointsCount)
	{
		if (NULL != m_pFloatData)
		{
			delete[] m_pFloatData;
		}//eif
		m_nPointCountMax = nPointsCount;
		m_pFloatData = new FLOAT[nPointsCount];
		element.ReNew(nPointsCount);//
	}//eif
	//element.ReNew(nPointsCount);//

	//WORD* pWord = pData;
	if (bReverse)//已用65535减过了
	{
		for (int i=0; i<nPointsCount; i++)//转换dB
		{
			m_pFloatData[i] = pData[i]/1000.0;
		}//efor
	}
	else
	{
		for (int i=0; i<nPointsCount; i++)//转换dB
		{
			m_pFloatData[i] = (65535-(int)pData[i])/1000.0;
		}//efor
	}//eif

	if (fabs(element.m_fLength - fTestRange) > 0.00000001)//两次长度不一样, 重新设置范围
	{
		element.m_nPointsCount = nPointsCount;
		element.m_fDataSpacing = fTestRange*1.0/nPointsCount;
		element.m_fLength = fTestRange;
		element.m_fMaxDistance =element.m_fLength;
		SetMaxDistance(fTestRange);
		SetScrollRangeX();//
		SetRange(0, fTestRange, OTDR_TRACE_Y_MIN, OTDR_TRACE_Y_MAX);//
	}//eif
	element.m_nPointsCount = nPointsCount;
	element.m_fDataSpacing = fTestRange*1.0/nPointsCount;
	memcpy(element.m_pData, m_pFloatData, sizeof(FLOAT) * nPointsCount);

	//得到曲线中的事件列表信息
	ConvertEvent(element);

	//绘曲线
	DrawCurves(&m_dcCurve);

	Invalidate(FALSE);
}
const unsigned C = 299792458 ; //真空中的光速m
//计算距离,以c/2nf公式计算.xpoint:点位置加1，Frequency:频率， Refraction:折射率
float COtdrTrace::GetDistance(unsigned int xpoint, FLOAT Frequency, FLOAT Refraction)
{
	FLOAT ftemp =2 * Frequency *  Refraction * 1000000;//
	if (0 == ftemp)//
	{
		return 0;
	}//eif
	return C/(ftemp/*MHz*/) * xpoint;
}
void COtdrTrace::ConvertEvent( CGraphElement& element )
{
	//CGraphElement& element = m_otdrTrace.m_vAllData[0];//这里只考虑一条曲线
	element.m_vAllEvents.clear();
	//std::vector<OTDR_ALL_UPLOAD_DATA::ENVENT_INFO> ve = pOtdrAllUploadData->VEventInfo;////wcq2012.09.03
	int nSize=m_vEventInfo.size();
	if (0 == nSize)
	{
		return;
	}//eif
	//
	CString temp;
	float preDistance=0;
	float ftemp=0;//
	BOOL bKm = TRUE;//
	BOOL bFeet = FALSE;//
	//FLOAT fDataspcing = pOtdrAllUploadData->TestRange*1.0/pOtdrAllUploadData->DataPointsNum;
	FLOAT Frequence = m_fFrequency;
	FLOAT Refraction = m_fRefraction;
	for (int i=0;i<nSize;i++)//
	{
		CGraphElement::TraceEvent event;
		event.m_nIndex =m_vEventInfo[i].index;
		//event.m_distance = GetDistance(ve[i].Index , Frequence, Refraction)/1000;
		event.m_distance = GetDistance(m_vEventInfo[i].index , Frequence, Refraction);
		element.m_vAllEvents.push_back(event);
	}//efor
}
