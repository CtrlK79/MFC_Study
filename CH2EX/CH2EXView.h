
// CH2EXView.h: CCH2EXView 클래스의 인터페이스
//

#pragma once


class CCH2EXView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCH2EXView() noexcept;
	DECLARE_DYNCREATE(CCH2EXView)

// 특성입니다.
public:
	CCH2EXDoc* GetDocument() const;

// 작업입니다.
public:
	CButton m_wndChild;
	CEdit m_wndChild2;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCH2EXView();
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

#ifndef _DEBUG  // CH2EXView.cpp의 디버그 버전
inline CCH2EXDoc* CCH2EXView::GetDocument() const
   { return reinterpret_cast<CCH2EXDoc*>(m_pDocument); }
#endif

