// Do_RegDlg.h : header file
//

#if !defined(AFX_DO_REGDLG_H__68C0C613_0E35_4F58_A1AF_3916A6E57A14__INCLUDED_)
#define AFX_DO_REGDLG_H__68C0C613_0E35_4F58_A1AF_3916A6E57A14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDo_RegDlg dialog

class CDo_RegDlg : public CDialog
{
// Construction
public:
	CDo_RegDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDo_RegDlg)
	enum { IDD = IDD_DO_REG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDo_RegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDo_RegDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnumValue();
	afx_msg void OnCreateValue();
	afx_msg void OnDeleteValue();
	afx_msg void OnEnumKey();
	afx_msg void OnCreateKey();
	afx_msg void OnDeleteKey();
	afx_msg void onRecover();
	afx_msg void backup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedRecover();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DO_REGDLG_H__68C0C613_0E35_4F58_A1AF_3916A6E57A14__INCLUDED_)
