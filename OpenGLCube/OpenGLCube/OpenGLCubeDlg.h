
// OpenGLCubeDlg.h : ��� ����
//

#pragma once


#include "OpenGLCubeRenderer.h"



// COpenGLCubeDlg ��ȭ ����
class COpenGLCubeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	COpenGLCubeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCOPENGL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

public:
	void GLResize(int cx, int cy);

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
