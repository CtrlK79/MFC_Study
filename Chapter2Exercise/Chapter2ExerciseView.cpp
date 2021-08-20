
// Chapter2ExerciseView.cpp: CChapter2ExerciseView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Chapter2Exercise.h"
#endif

#include "Chapter2ExerciseDoc.h"
#include "Chapter2ExerciseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChapter2ExerciseView

IMPLEMENT_DYNCREATE(CChapter2ExerciseView, CView)

BEGIN_MESSAGE_MAP(CChapter2ExerciseView, CView)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CChapter2ExerciseView 생성/소멸

CChapter2ExerciseView::CChapter2ExerciseView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CChapter2ExerciseView::~CChapter2ExerciseView()
{
}

BOOL CChapter2ExerciseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChapter2ExerciseView 그리기

void CChapter2ExerciseView::OnDraw(CDC* /*pDC*/)
{
	CChapter2ExerciseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CChapter2ExerciseView 진단

#ifdef _DEBUG
void CChapter2ExerciseView::AssertValid() const
{
	CView::AssertValid();
}

void CChapter2ExerciseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChapter2ExerciseDoc* CChapter2ExerciseView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChapter2ExerciseDoc)));
	return (CChapter2ExerciseDoc*)m_pDocument;
}
#endif //_DEBUG


// CChapter2ExerciseView 메시지 처리기


int CChapter2ExerciseView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	//m_wndChild1.Create(_T("BUTTON"), _T("Click me!"),
		//WS_CHILD | WS_VISIBLE | WS_BORDER,
		//CRect(50, 50, 50 + 200, 50 + 100), this, 0713);
	//The above code is the solution for #2 and #3
	m_wndChild1.Create(_T("BUTTON"), _T("I'm out of the View"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(50, 50, 50+200, 50+100), GetDesktopWindow(), 0713);


	m_wndChild2.Create(_T("EDIT"), _T("You can write down anything here!"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(50, 200, 50 + 200, 200 + 100), this, 0713);
	return 0;
}
