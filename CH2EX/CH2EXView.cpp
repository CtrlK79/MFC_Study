
// CH2EXView.cpp: CCH2EXView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CH2EX.h"
#endif

#include "CH2EXDoc.h"
#include "CH2EXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH2EXView

IMPLEMENT_DYNCREATE(CCH2EXView, CView)

BEGIN_MESSAGE_MAP(CCH2EXView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CCH2EXView 생성/소멸

CCH2EXView::CCH2EXView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCH2EXView::~CCH2EXView()
{
}

BOOL CCH2EXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCH2EXView 그리기

void CCH2EXView::OnDraw(CDC* /*pDC*/)
{
	CCH2EXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCH2EXView 인쇄

BOOL CCH2EXView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCH2EXView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCH2EXView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCH2EXView 진단

#ifdef _DEBUG
void CCH2EXView::AssertValid() const
{
	CView::AssertValid();
}

void CCH2EXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH2EXDoc* CCH2EXView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH2EXDoc)));
	return (CCH2EXDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH2EXView 메시지 처리기


int CCH2EXView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_wndChild.Create(_T("It is a button"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(50, 50, 250, 150), this, 1234);

	m_wndChild2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(350, 350, 850, 500), GetDesktopWindow(), 1234);
	return 0;
}
