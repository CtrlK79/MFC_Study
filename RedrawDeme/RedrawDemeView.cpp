
// RedrawDemeView.cpp: CRedrawDemeView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "RedrawDeme.h"
#endif

#include "RedrawDemeDoc.h"
#include "RedrawDemeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRedrawDemeView

IMPLEMENT_DYNCREATE(CRedrawDemeView, CView)

BEGIN_MESSAGE_MAP(CRedrawDemeView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CRedrawDemeView 생성/소멸

CRedrawDemeView::CRedrawDemeView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CRedrawDemeView::~CRedrawDemeView()
{
}

BOOL CRedrawDemeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CRedrawDemeView 그리기

void CRedrawDemeView::OnDraw(CDC* /*pDC*/)
{
	CRedrawDemeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CRedrawDemeView 진단

#ifdef _DEBUG
void CRedrawDemeView::AssertValid() const
{
	CView::AssertValid();
}

void CRedrawDemeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRedrawDemeDoc* CRedrawDemeView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRedrawDemeDoc)));
	return (CRedrawDemeDoc*)m_pDocument;
}
#endif //_DEBUG


// CRedrawDemeView 메시지 처리기


void CRedrawDemeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	CDC* pDC = GetDC();
//	pDC->Rectangle(10, 10, 100, 100);
//	ReleaseDC(pDC);
	CView::OnLButtonDown(nFlags, point);
}


void CRedrawDemeView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	DWORD style[] = { 6, 3, 3 };
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(192, 192, 192);

	CPen NewPen;
	NewPen.CreatePen(PS_GEOMETRIC | PS_USERSTYLE | PS_ENDCAP_FLAT, 20, &lb, 3, style);
	
CBitmap Bmp;
	Bmp.LoadBitmap(IDB_BITMAP2);
	CBrush NewBrush;
	NewBrush.CreatePatternBrush(&Bmp);

	CPen* pOldPen = dc.SelectObject(&NewPen);
	CBrush* pOldBrush = dc.SelectObject(&NewBrush);
	
	//dc.Rectangle(10, 10, 100, 100);
	CRect Rect;
	GetClientRect(&Rect);
	dc.Rectangle(&Rect);
	//dc.MoveTo(200, 200);
	//dc.LineTo(50, 50);
	//dc.FillSolidRect(10, 10, 90, 90, RGB(0, 0, 0));
	//dc.SetBkMode(TRANSPARENT);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOutW(100, 100, _T("Hello"));

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
}
