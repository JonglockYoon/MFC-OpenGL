
// OpenGLCubeDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "OpenGLCube.h"
#include "OpenGLCubeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenGLCubeDlg 대화 상자



COpenGLCubeDlg::COpenGLCubeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCOPENGL_DIALOG, pParent)
{
	m_pLeft = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenGLCubeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OPENGL, m_PictCtrl);
}

BEGIN_MESSAGE_MAP(COpenGLCubeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &COpenGLCubeDlg::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// COpenGLCubeDlg 메시지 처리기

void COpenGLCubeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

BOOL COpenGLCubeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	CRect rectLeft, rect;
	int iPosOffSetX, iPosOffSetY, iWidth, iHeight;

	GetWindowRect(rect);

	////------------------------
	iPosOffSetX = 0;
	iPosOffSetY = 0;
	m_PictCtrl.GetWindowRect(rectLeft);
	iWidth = rectLeft.Width();
	iHeight = rectLeft.Height();

	m_pLeft = new OpenGLRenderer;
	CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_OWNDC, NULL, (HBRUSH)GetStockObject(WHITE_BRUSH), NULL);
	m_pLeft->CreateEx(0, className, _T("OpenGLCube"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rectLeft, this, 0);
	m_pLeft->ShowWindow(SW_SHOW);

	m_pLeft->CreateGLContext(rectLeft, this);
	m_pLeft->PrepareScene(0, 0, iWidth, iHeight); //will show without this but as black & white.
	m_pLeft->initAi();
	m_pLeft->m_unpTimer = m_pLeft->SetTimer(1, 10, 0);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COpenGLCubeDlg::OnPaint()
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
HCURSOR COpenGLCubeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenGLCubeDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}



void COpenGLCubeDlg::OnBnClickedButtonClose()
{
	SendMessage(WM_CLOSE, 0, 0);
}
