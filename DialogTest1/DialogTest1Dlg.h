
// DialogTest1Dlg.h: 헤더 파일
//

#pragma once


// CDialogTest1Dlg 대화 상자
class CDialogTest1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CDialogTest1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGTEST1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnStnClickedStaticResultwnd();
	void Calculator();
	float input = 0, result = 0;
	int opr = 0, reset_flag = 0;
	CString sResult, sInput;
	CStatic Static_ResultWnd;
	CStatic Static_InputWnd;
	afx_msg void OnStnClickedStaticInputwnd();
	
};
