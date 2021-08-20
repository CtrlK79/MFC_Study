﻿
// Chapter3ExerciseView.h: CChapter3ExerciseView 클래스의 인터페이스
//

#pragma once


class CChapter3ExerciseView : public CView
{
protected: // serialization에서만 만들어집니다.
	CChapter3ExerciseView() noexcept;
	DECLARE_DYNCREATE(CChapter3ExerciseView)

// 특성입니다.
public:
	CChapter3ExerciseDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CChapter3ExerciseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Chapter3ExerciseView.cpp의 디버그 버전
inline CChapter3ExerciseDoc* CChapter3ExerciseView::GetDocument() const
   { return reinterpret_cast<CChapter3ExerciseDoc*>(m_pDocument); }
#endif

