
// Chapter2ExerciseView.h: CChapter2ExerciseView 클래스의 인터페이스
//

#pragma once


class CChapter2ExerciseView : public CView
{
protected: // serialization에서만 만들어집니다.
	CChapter2ExerciseView() noexcept;
	DECLARE_DYNCREATE(CChapter2ExerciseView)

// 특성입니다.
public:
	CChapter2ExerciseDoc* GetDocument() const;

// 작업입니다.
public:
	CWnd m_wndChild1;
	CWnd m_wndChild2;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CChapter2ExerciseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Chapter2ExerciseView.cpp의 디버그 버전
inline CChapter2ExerciseDoc* CChapter2ExerciseView::GetDocument() const
   { return reinterpret_cast<CChapter2ExerciseDoc*>(m_pDocument); }
#endif

