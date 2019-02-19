// ElevatorSimulationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ElevatorSimulation.h"
#include "ElevatorSimulationDlg.h"

#include <cstdlib>
#include <ctime>

#include <iomanip>
using std::fixed;
using std::setprecision;

#include <sstream>
using std::ostringstream;

#include ".\elevatorsimulationdlg.h"

#ifdef _DEBUGg
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
  CAboutDlg();

// Dialog Data
  //{{AFX_DATA(CAboutDlg)
  enum { IDD = IDD_ABOUTBOX };
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CAboutDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  //{{AFX_MSG(CAboutDlg)
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
  //{{AFX_DATA_INIT(CAboutDlg)
  //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CAboutDlg)
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
  //{{AFX_MSG_MAP(CAboutDlg)
    // No message handlers
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationDlg dialog

CElevatorSimulationDlg::CElevatorSimulationDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CElevatorSimulationDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(CElevatorSimulationDlg)
    // NOTE: the ClassWizard will add member initialization here
  //}}AFX_DATA_INIT
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CElevatorSimulationDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CElevatorSimulationDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CElevatorSimulationDlg, CDialog)
  //{{AFX_MSG_MAP(CElevatorSimulationDlg)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_WM_TIMER()
  //}}AFX_MSG_MAP
  ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CElevatorSimulationDlg message handlers

BOOL CElevatorSimulationDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Add "About..." menu item to system menu.

  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    CString strAboutMenu;
    strAboutMenu.LoadString(IDS_ABOUTBOX);
    if (!strAboutMenu.IsEmpty())
    {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
    }
  }

  SetIcon(m_hIcon, TRUE);     // Set big icon
  SetIcon(m_hIcon, FALSE);    // Set small icon
  
  // TODO: Add extra initialization here
  RECT r;
  CStatic* pPic = (CStatic*)GetDlgItem(IDC_PIC);
  pPic->GetClientRect(&r);

  srand((unsigned int)time(0));
  building.initializeForMfc(r.right - r.left, r.bottom - r.top, 32, 2, 4);
  SetTimer(1, 1000, 0);
    
  return TRUE;  // return TRUE  unless you set the focus to a control
}

void CElevatorSimulationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
  if ((nID & 0xFFF0) == IDM_ABOUTBOX)
  {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
  }
  else
  {
    CDialog::OnSysCommand(nID, lParam);
  }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CElevatorSimulationDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    CDialog::OnPaint();
  }
}

HCURSOR CElevatorSimulationDlg::OnQueryDragIcon()
{
  return (HCURSOR) m_hIcon;
}

void CElevatorSimulationDlg::OnTimer(UINT nIDEvent) 
{
  CStatic* pPic = (CStatic*)GetDlgItem(IDC_PIC); // this is a Picture control in the DLG window
  CClientDC dc(pPic); // create a "device context" for drawing in the Picture control

  CBrush BrushRand(RGB(255, 255, 255)); // white brush for background
  CPen PenRand(PS_SOLID, 1, RGB(0, 0, 0)); // black pen

  CBrush* pOldBrush = dc.SelectObject(&BrushRand); // put the brush...
  CPen* pOldPen = dc.SelectObject(&PenRand); // ...and the pen in the dc

  // white-out the whole picture
  RECT r;
  dc.GetWindow()->GetClientRect(&r);
  dc.FillRect(&r, &BrushRand);

  // draw the floor levels
  int i, j, n, count, x;
  n = building.FLOORS;
  for (i = 0; i < n; i++)
  {
    // draw the left-side for up riders
    dc.MoveTo(0, building.getFloorY(i));
    dc.LineTo(building.getUpFloorX(), building.getFloorY(i));

    // draw the right-side for up riders
    dc.MoveTo(building.getDownFloorX(), building.getFloorY(i));
    dc.LineTo(r.right - r.left, building.getFloorY(i));
    
    // draw the up riders waiting
    x = building.getUpFloorX() - building.getRiderSeparation();
    count = building.getUpRiderCount(i);
    for (j = 0; j < count; j++, x -= building.getRiderSeparation())
    {
      dc.MoveTo(x, building.getFloorY(i));
      dc.LineTo(x, building.getFloorY(i) - building.getRiderHeight());
    }
    
    // draw the down riders waiting
    x = building.getDownFloorX() + building.getRiderSeparation();
    count = building.getDownRiderCount(i);
    for (j = 0; j < count; j++, x += building.getRiderSeparation())
    {
      dc.MoveTo(x, building.getFloorY(i));
      dc.LineTo(x, building.getFloorY(i) - building.getRiderHeight());
  } }

  // draw the elevators
  n = building.ELEVATORS;
  for (i = 0; i < n; i++)
  {
    // draw the elevator
    r.bottom = building.getElevatorY(i) + 1;
    r.top = r.bottom - building.getElevatorHeight();
    r.left = building.getElevatorX(i) + 1;
    r.right = r.left + building.getElevatorWidth(i);
    dc.Rectangle(&r);

    // indicate up
    if (building.isDirectionUp(i))
    {
      dc.MoveTo(r.left, r.top + 5);
      dc.LineTo( (r.left + r.right) / 2, r.top);
      dc.LineTo(r.right, r.top + 5);
    }

    // indicate down
    if (building.isDirectionDown(i))
    {
      dc.MoveTo(r.left, r.bottom - 6);
      dc.LineTo( (r.left + r.right) / 2, r.bottom - 1);
      dc.LineTo(r.right, r.bottom - 6);
    }

    // draw riders in elevator
    count = building.getRiderCount(i);
    x = (r.left + r.right) / 2 - (count - 1) * building.getRiderSeparation() / 2;
    for (j = 0; j < count; j++, x += building.getRiderSeparation())
    {
      dc.MoveTo(x, building.getElevatorY(i) - 1);
      dc.LineTo(x, building.getElevatorY(i) - building.getRiderHeight() - 1);
  } }

  dc.SelectObject(pOldBrush);
  dc.SelectObject(pOldPen);

  ostringstream sout; // a buffer
  sout << fixed << setprecision(1) << building.getRidersPerSecond() << " riders/sec";
  CStatic* pRate = (CStatic*)GetDlgItem(IDC_RATE);
  pRate->SetWindowText(sout.str().c_str());

  building.action(building.poissonHits());
  CDialog::OnTimer(nIDEvent);
}

void CElevatorSimulationDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
  // TODO: Add your control notification handler code here
  if (pNMUpDown->iDelta == 1) building.decrementRidersPerSecond();
  else if (pNMUpDown->iDelta == -1) building.incrementRidersPerSecond();
}
