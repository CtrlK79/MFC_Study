
// Chapter3ExerciseView.cpp: CChapter3ExerciseView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Chapter3Exercise.h"
#endif

#include "Chapter3ExerciseDoc.h"
#include "Chapter3ExerciseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChapter3ExerciseView

IMPLEMENT_DYNCREATE(CChapter3ExerciseView, CView)

BEGIN_MESSAGE_MAP(CChapter3ExerciseView, CView)
END_MESSAGE_MAP()

// CChapter3ExerciseView 생성/소멸

CChapter3ExerciseView::CChapter3ExerciseView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CChapter3ExerciseView::~CChapter3ExerciseView()
{
}

BOOL CChapter3ExerciseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChapter3ExerciseView 그리기

void CChapter3ExerciseView::OnDraw(CDC* /*pDC*/)
{
	CChapter3ExerciseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CChapter3ExerciseView 진단

#ifdef _DEBUG
void CChapter3ExerciseView::AssertValid() const
{
	CView::AssertValid();
}

void CChapter3ExerciseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChapter3ExerciseDoc* CChapter3ExerciseView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChapter3ExerciseDoc)));
	return (CChapter3ExerciseDoc*)m_pDocument;
}
#endif //_DEBUG


// CChapter3ExerciseView 메시지 처리기
