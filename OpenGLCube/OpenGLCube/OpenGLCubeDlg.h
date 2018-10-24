
// OpenGLCubeDlg.h 
//

#pragma once


#include "OpenGLCubeRenderer.h"



// COpenGLCubeDlg 
class COpenGLCubeDlg : public CDialogEx
{
public:
    COpenGLCubeDlg(CWnd* pParent = NULL);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MFCOPENGL_DIALOG };
#endif

    protected:
    virtual void DoDataExchange(CDataExchange* pDX);


protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();

public:
    afx_msg void OnDestroy();


protected:
    CFrameWnd* m_pFrameWnd;
    CStatic m_PictCtrl;
    OpenGLRenderer *m_pLeft;
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonClose();
};
