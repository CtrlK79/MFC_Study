
// MFCserialportDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCserialport.h"
#include "MFCserialportDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCserialportDlg 대화 상자



CMFCserialportDlg::CMFCserialportDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSERIALPORT_DIALOG, pParent)
	, m_str_comport(_T(""))
	, m_str_baudrate(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCserialportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_combo_comport_list);
	DDX_CBString(pDX, IDC_COMBO_COMPORT, m_str_comport);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_combo_baudrate_list);
	DDX_CBString(pDX, IDC_COMBO_BAUDRATE, m_str_baudrate);
	DDX_Control(pDX, IDC_EDIT_RCV_VIEW, m_edit_rcv_view);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA, m_edit_sent_data);
}

BEGIN_MESSAGE_MAP(CMFCserialportDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


	ON_MESSAGE(WM_MYCLOSE, &CMFCserialportDlg::OnThreadClosed)
	ON_MESSAGE(WM_MYRECEIVE, &CMFCserialportDlg::OnReceive)


	ON_BN_CLICKED(IDC_BT_CONNECT, &CMFCserialportDlg::OnBnClickedBtConnect)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, &CMFCserialportDlg::OnCbnSelchangeComboComport)
	ON_CBN_SELCHANGE(IDC_COMBO_BAUDRATE, &CMFCserialportDlg::OnCbnSelchangeComboBaudrate)
	ON_BN_CLICKED(IDC_BT_CLEAR, &CMFCserialportDlg::OnBnClickedBtClear)
	ON_BN_CLICKED(IDC_BT_SEND, &CMFCserialportDlg::OnBnClickedBtSend)
END_MESSAGE_MAP()


// CMFCserialportDlg 메시지 처리기

BOOL CMFCserialportDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_combo_comport_list.AddString(_T("COM1"));
	m_combo_comport_list.AddString(_T("COM2"));
	m_combo_comport_list.AddString(_T("COM3"));
	m_combo_comport_list.AddString(_T("COM4"));

	m_combo_baudrate_list.AddString(_T("9600"));
	m_combo_baudrate_list.AddString(_T("19200"));
	m_combo_baudrate_list.AddString(_T("115200"));


	comport_state = false;
	GetDlgItem(IDC_BT_CONNECT)->SetWindowTextA(_T("OPEN"));
	m_str_comport = _T("COM1");
	m_str_baudrate = _T("9600");
	UpdateData(FALSE);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCserialportDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCserialportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CMFCserialportDlg::OnThreadClosed(WPARAM length, LPARAM lpara)
{
	//overlapped i/o 핸들을 닫는다.
	((CMycomm*)lpara)->HandleClose();
	delete((CMycomm*)lpara);

	return 0;
}

LRESULT CMFCserialportDlg::OnReceive(WPARAM length, LPARAM lpara)
{
	CString str;
	char data[20000];
	if (m_comm)
	{
		m_comm->Receive(data, length); //length 길이만큼 데이터를 받는다.
		data[length] = _T('\0');
		str += _T("\r\n");
		for (int i = 0; i < length; i++)
		{
			str += data[i];
		}
		m_edit_rcv_view.ReplaceSel(str); //에디트 박스에 표시하기 위함
		str = "";
		//UpdateData(FALSE);
		m_edit_rcv_view.LineScroll(m_edit_rcv_view.GetLineCount());
	}
	return 0;
}


void CMFCserialportDlg::OnBnClickedBtConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (comport_state)
	{
		if (m_comm)
		{
			m_comm->Close();
			m_comm = NULL;
			AfxMessageBox(_T("COM 포트닫힘"));
			comport_state = false;
			GetDlgItem(IDC_BT_CONNECT)->SetWindowTextA(_T("OPEN"));
			GetDlgItem(IDC_BT_SEND)->EnableWindow(false);
		}
	}
	else
	{
		m_comm = new CMycomm(_T("\\\\.\\") + m_str_comport, m_str_baudrate, _T("None"), _T("8 Bit"), _T("1 Bit"));
		if (m_comm->Create(GetSafeHwnd()) != 0)
		{
			AfxMessageBox(_T("COM 포트열림"));
			comport_state = true;
			GetDlgItem(IDC_BT_CONNECT)->SetWindowTextA(_T("CLOSE"));
			GetDlgItem(IDC_BT_SEND)->EnableWindow(true);
		}
		else 
		{
			AfxMessageBox(_T("ERROR!"));
		}
	}

}

void CMFCserialportDlg::OnCbnSelchangeComboComport()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
}


void CMFCserialportDlg::OnCbnSelchangeComboBaudrate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
}


void CMFCserialportDlg::OnBnClickedBtClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_EDIT_RCV_VIEW)->SetWindowTextA(_T(" "));
}


void CMFCserialportDlg::OnBnClickedBtSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItem(IDC_EDIT_SEND_DATA)->GetWindowTextA(str);
	str += "\r\n";
	m_comm->Send(str, str.GetLength());
}
