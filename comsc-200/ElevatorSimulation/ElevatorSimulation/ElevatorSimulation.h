// ElevatorSimulation.h : main header file for the ELEVATORSIMULATION application
//

#if !defined(AFX_ELEVATORSIMULATION_H__FF269815_5F3F_4933_9015_119DB5B7223C__INCLUDED_)
#define AFX_ELEVATORSIMULATION_H__FF269815_5F3F_4933_9015_119DB5B7223C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationApp:
// See ElevatorSimulation.cpp for the implementation of this class
//

class CElevatorSimulationApp : public CWinApp
{
public:
	CElevatorSimulationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElevatorSimulationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CElevatorSimulationApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELEVATORSIMULATION_H__FF269815_5F3F_4933_9015_119DB5B7223C__INCLUDED_)
