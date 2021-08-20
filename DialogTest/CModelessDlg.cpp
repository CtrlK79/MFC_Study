// CModelessDlg.cpp: 구현 파일
//

#include "pch.h"
#include "DialogTest.h"
#include "CModelessDlg.h"
#include "afxdialogex.h"


// CModelessDlg 대화 상자

IMPLEMENT_DYNAMIC(CModelessDlg, CDialog)

CModelessDlg::CModelessDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Dialog_Modeless, pParent)
{

}

CModelessDlg::~CModelessDlg()
{
}

void CModelessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModelessDlg, CDialog)
END_MESSAGE_MAP()


// CModelessDlg 메시지 처리기
