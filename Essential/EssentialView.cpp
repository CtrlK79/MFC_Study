
// EssentialView.cpp: CEssentialView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Essential.h"
#endif

#include "EssentialDoc.h"
#include "EssentialView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEssentialView

IMPLEMENT_DYNCREATE(CEssentialView, CView)

BEGIN_MESSAGE_MAP(CEssentialView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CEssentialView 생성/소멸

CEssentialView::CEssentialView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CEssentialView::~CEssentialView()
{
}

BOOL CEssentialView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CEssentialView 그리기

void CEssentialView::OnDraw(CDC* /*pDC*/)
{
	CEssentialDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CEssentialView 진단

#ifdef _DEBUG
void CEssentialView::AssertValid() const
{
	CView::AssertValid();
}

void CEssentialView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEssentialDoc* CEssentialView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEssentialDoc)));
	return (CEssentialDoc*)m_pDocument;
}
#endif //_DEBUG


// CEssentialView 메시지 처리기

void CEssentialView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	LRectEdge1.SetPoint(point.x, point.y);
	LDragFlag = true;
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CEssentialView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	LRectEdge2.SetPoint(point.x, point.y);
	LDragFlag = false;
	RRectEdge1.SetPoint(0, 0); RRectEdge2.SetPoint(0, 0);

	CRect rect;
	this->GetWindowRect(&rect);
	int WindowXSize = rect.Width();
	int WindowYSize = rect.Height();
	if (point.x<0 || point.y<0 || point.x>WindowXSize || point.y>WindowYSize)
	{
		AfxMessageBox(_T("Your mouse escape the working area"));
		LRectEdge1.SetPoint(0, 0); LRectEdge2.SetPoint(0, 0);
		RRectEdge1.SetPoint(0, 0); RRectEdge2.SetPoint(0, 0);
	}
	RedrawWindow(NULL, NULL,
		RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CEssentialView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	RRectEdge1.SetPoint(point.x, point.y);
	RDragFlag = true;
	SetCapture();
	CView::OnRButtonDown(nFlags, point);
}


void CEssentialView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	RRectEdge2.SetPoint(point.x, point.y);
	RDragFlag = false;
	LRectEdge1.SetPoint(0, 0); LRectEdge2.SetPoint(0, 0);

	CRect rect;
	this->GetWindowRect(&rect);
	int WindowXSize = rect.Width();
	int WindowYSize = rect.Height();
	if (point.x<0 || point.y<0 || point.x>WindowXSize || point.y>WindowYSize)
	{
		AfxMessageBox(_T("Your mouse escape the working area"));
		LRectEdge1.SetPoint(0, 0); LRectEdge2.SetPoint(0, 0);
		RRectEdge1.SetPoint(0, 0); RRectEdge2.SetPoint(0, 0);
	}

	RedrawWindow(NULL, NULL,
		RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

	ReleaseCapture();
	CView::OnRButtonUp(nFlags, point);
}


void CEssentialView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	//LeftButton Drag
	if (!LDragFlag) {
		CRect Rect(LRectEdge1.x, LRectEdge1.y, LRectEdge2.x, LRectEdge2.y);
		dc.Rectangle(Rect);
	}

	//RightButton Drag
	CDC MemDC;
	BITMAP bmpInfo;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	CBitmap* pOldbmp;
	bmp.LoadBitmap(IDB_BITMAP3);
	bmp.GetBitmap(&bmpInfo);
	pOldbmp = MemDC.SelectObject(&bmp);

	if (!RDragFlag) {
		dc.StretchBlt(RRectEdge1.x, RRectEdge1.y,
			RRectEdge2.x - RRectEdge1.x, RRectEdge2.y - RRectEdge1.y,
			&MemDC,
			0, 0,
			bmpInfo.bmWidth, bmpInfo.bmHeight,
			SRCCOPY);
	}

	MemDC.SelectObject(pOldbmp);
}

