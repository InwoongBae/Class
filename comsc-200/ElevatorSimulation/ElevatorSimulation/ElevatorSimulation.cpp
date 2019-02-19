// ElevatorSimulation.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ElevatorSimulation.h"
#include "ElevatorSimulationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationApp

BEGIN_MESSAGE_MAP(CElevatorSimulationApp, CWinApp)
	//{{AFX_MSG_MAP(CElevatorSimulationApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationApp construction

CElevatorSimulationApp::CElevatorSimulationApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CElevatorSimulationApp object

CElevatorSimulationApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationApp initialization

BOOL CElevatorSimulationApp::InitInstance()
{
	// Standard initialization

	CElevatorSimulationDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
