// ElevatorSimulationDlg.h : header file
//

#if !defined(AFX_ELEVATORSIMULATIONDLG_H__30C843D7_D435_4FDF_A161_095C4C8015C6__INCLUDED_)
#define AFX_ELEVATORSIMULATIONDLG_H__30C843D7_D435_4FDF_A161_095C4C8015C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationDlg dialog

#include "VisualBuilding.h"

class CElevatorSimulationDlg : public CDialog
{
// Construction
public:
  CElevatorSimulationDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
  //{{AFX_DATA(CElevatorSimulationDlg)
  enum { IDD = IDD_ELEVATORSIMULATION_DIALOG };
    // NOTE: the ClassWizard will add data members here
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CElevatorSimulationDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);  // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  HICON m_hIcon;
  VisualBuilding building;

  // Generated message map functions
  //{{AFX_MSG(CElevatorSimulationDlg)
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnTimer(UINT nIDEvent);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELEVATORSIMULATIONDLG_H__30C843D7_D435_4FDF_A161_095C4C8015C6__INCLUDED_)
