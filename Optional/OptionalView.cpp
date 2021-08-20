
// OptionalView.cpp: COptionalView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Optional.h"
#endif

#include "OptionalDoc.h"
#include "OptionalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COptionalView

IMPLEMENT_DYNCREATE(COptionalView, CView)

BEGIN_MESSAGE_MAP(COptionalView, CView)
	ON_WM_KEYDOWN()
//	ON_WM_MOUSEACTIVATE()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_PAINT()
//ON_WM_ERASEBKGND()
//ON_WM_SYSKEYDOWN()
END_MESSAGE_MAP()

// COptionalView 생성/소멸

COptionalView::COptionalView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COptionalView::~COptionalView()
{
}

BOOL COptionalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COptionalView 그리기

void COptionalView::OnDraw(CDC* /*pDC*/)
{
	COptionalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// COptionalView 진단

#ifdef _DEBUG
void COptionalView::AssertValid() const
{
	CView::AssertValid();
}

void COptionalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COptionalDoc* COptionalView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COptionalDoc)));
	return (COptionalDoc*)m_pDocument;
}
#endif //_DEBUG


// COptionalView 메시지 처리기


void COptionalView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((nChar <= 0x39 && nChar >= 0x30)
		|| (nChar <= 0x5A && nChar >= 0x41)
		|| (nChar <= 0x7A && nChar >= 0x61))
	{
		CString s = _T("");
		s.Format(_T("Character '%c' pressed"), nChar);
		AfxMessageBox(s);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void COptionalView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	InitialPoint.SetPoint(point.x, point.y);
	CView::OnLButtonDown(nFlags, point);
	SetCapture();
}


void COptionalView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	FinalPoint.SetPoint(point.x, point.y);
	
	CRect rect;
	this->GetWindowRect(&rect);
	int WindowXSize = rect.Width();
	int WindowYSize = rect.Height();
	if(point.x<0 || point.y<0 || point.x>WindowXSize || point.y>WindowYSize)
	{
		AfxMessageBox(_T("Error : Your mouse escape the woring area"));
		EscapeFlag = true;
	}
	RedrawWindow(NULL, NULL, 
		RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void COptionalView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	CString s = _T("");
	if(!EscapeFlag)
	{
		s.Format(_T("Initial Point : (%d, %d)\n Final Point : (%d, %d)"),
			InitialPoint.x, InitialPoint.y,
			FinalPoint.x, FinalPoint.y);
	}
	else
	{
		s.Format(_T("Error"));
		EscapeFlag = false;
	}
	
	if (!DragFlag) { dc.TextOutW(10, 10, s); }

}