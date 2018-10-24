
// OpenGLCubeDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "OpenGLCube.h"
#include "OpenGLCubeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenGLCubeDlg



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

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    CRect rectLeft;
    int iWidth, iHeight;

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
    m_pLeft->SetTimer(1, 10, 0);

    return TRUE;
}

void COpenGLCubeDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();

    }
}

HCURSOR COpenGLCubeDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void COpenGLCubeDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

}



void COpenGLCubeDlg::OnBnClickedButtonClose()
{
    SendMessage(WM_CLOSE, 0, 0);
}
