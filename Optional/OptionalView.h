
// OptionalView.h: COptionalView 클래스의 인터페이스
//

#pragma once


class COptionalView : public CView
{
protected: // serialization에서만 만들어집니다.
	COptionalView() noexcept;
	DECLARE_DYNCREATE(COptionalView)

// 특성입니다.
public:
	COptionalDoc* GetDocument() const;

// 작업입니다.
public:
	CPoint InitialPoint, FinalPoint;
	bool DragFlag = false;
	bool EscapeFlag = false;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~COptionalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // OptionalView.cpp의 디버그 버전
inline COptionalDoc* COptionalView::GetDocument() const
   { return reinterpret_cast<COptionalDoc*>(m_pDocument); }
#endif

