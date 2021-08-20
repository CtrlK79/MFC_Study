// CModalDlg.cpp: 구현 파일
//

#include "pch.h"
#include "DialogTest.h"
#include "CModalDlg.h"
#include "afxdialogex.h"


// CModalDlg 대화 상자

IMPLEMENT_DYNAMIC(CModalDlg, CDialog)

CModalDlg::CModalDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Dialog_Modal, pParent)
{

}

CModalDlg::~CModalDlg()
{
}

void CModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalDlg, CDialog)
END_MESSAGE_MAP()


// CModalDlg 메시지 처리기
