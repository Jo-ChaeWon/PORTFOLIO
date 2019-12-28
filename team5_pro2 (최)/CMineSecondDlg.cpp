// CMineSecondDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "team5_pro2.h"
#include "CMineSecondDlg.h"
#include "afxdialogex.h"


// CMineSecondDlg 대화 상자

IMPLEMENT_DYNAMIC(CMineSecondDlg, CDialogEx)

CMineSecondDlg::CMineSecondDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SECOND, pParent)
	, m_bStart(false)
	, m_bClock(false)
	, m_nFlag(0)
	, m_nMine(0)
	, m_Flag(0)
{
	m_nFlag = 0;
	m_nMine = 0;
	m_Mine[100][100] = 0;
	m_Flag = 0;
	m_Block[100][100] = 0;
	m_FindMine = 0;
	M[100][100] = 0;

	m_T = 0;
}

CMineSecondDlg::~CMineSecondDlg()
{
}

void CMineSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LANDMINE_SECOND, m_Mine[100][100]);
}


BEGIN_MESSAGE_MAP(CMineSecondDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_START_SECOND, &CMineSecondDlg::OnClickedButtonStartSecond)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMineSecondDlg 메시지 처리기


void CMineSecondDlg::OnPaint()
{

	SetTimer(1, 1000, NULL);
		
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CPen OnePen, *oldPen;
	OnePen.CreatePen(PS_SOLID, 1, RGB(213, 213, 213));
	oldPen = dc.SelectObject(&OnePen);
	CBrush OneBrush(RGB(213, 213, 213));
	CBrush *oldBrush = dc.SelectObject(&OneBrush);
	dc.Rectangle(10, 10, 510, 510);

	CPen TwoPen;
	TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = dc.SelectObject(&TwoPen);
	for (int i = 0; i < 26; i++)
	{
		dc.MoveTo(10 + 20 * i, 10); //가
		dc.LineTo(10 + 20 * i, 10 + 20 * 25);
		dc.MoveTo(10, 10 + 20 * i);
		dc.LineTo(10 + 20 * 25, 10 + 20 * i);
	}
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 80; i++)
	{
		m_Mine[i][0] = rand() % 25;
		m_Mine[i][1] = rand() % 25;

		for (int j = 0; j < i; j++)
		{
			if (m_Mine[i][0] == m_Mine[j][0] && m_Mine[i][1] == m_Mine[j][1])
			{
				i--;
			}
		}
	}

	m_bBolckClick = false;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			m_Block[i][j] = 0;
		}
	}
	//m_bClock = 0;
	m_nMine = 80;
	m_Mine[100][100] = 80;
	m_bStart = false;

	UpdateData(false);

					   
}


void CMineSecondDlg::Game(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.

	if (m_Block[x][y] == 0)
	{
		CClientDC dc(this);
		CPen TwoPen, *oldPen;
		TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		oldPen = 0;

		CBrush ThreeBrush(RGB(220, 83, 80));
		CBrush FourBrush(RGB(116, 116, 116));
		CBrush *oldBrush = 0;

		bool Mine = false;
		for (int i = 0; i < 80; i++)
		{
			if (m_Mine[i][0] == x && m_Mine[i][1] == y)
			{
				Mine = true;
			}
		}

		
		if (Mine)
		{
			oldPen = dc.SelectObject(&TwoPen);
			oldBrush = dc.SelectObject(&ThreeBrush);
			dc.Rectangle(10 + 20 * x, 10 + 20 * y, 30 + 20 * x, 30 + 20 * y);
			m_Block[x][y] = 1;
			End();
		}
		else
		{
			oldPen = dc.SelectObject(&TwoPen);
			oldBrush = dc.SelectObject(&FourBrush);
			dc.Rectangle(10 + 20 * x, 10 + 20 * y, 30 + 20 * x, 30 + 20 * y);

			int m_FindMine = 0;
			M[x][y] = 0;
			for (int j = 0; j < 80; j++)
			{
				if (((m_Mine[j][0] - x == 1 || m_Mine[j][0] - x == -1) && (m_Mine[j][1] - y == 1 ||
					m_Mine[j][1] - y == -1 || m_Mine[j][1] - y == 0)) ||
					(m_Mine[j][0] - x == 0 && (m_Mine[j][1] - y == 1 || m_Mine[j][1] - y == -1)))
				{
					m_FindMine++;

					M[x][y]++;
				}
			}
		}

		m_Block[x][y] = 1;
		CRect rect;
		GetClientRect(&rect);
		CDC *pDC;
		pDC = GetDC();
		CString str;
		str.Format(_T("%d"), M[x][y]);
		pDC->TextOut(16 + 20 * x, 13 + 20 * y, str);

		if (!m_FindMine && m_Block[x][y] && !M[x][y])
		{
			if (x != 0 && y != 0)
			{//왼쪽 대각선
				Game(x - 1, y - 1);
			}
			if (y != 0)
			{//위로 직선
				Game(x, y - 1);
			}
			if (x != 24 && y != 0)
			{ //오른쪽 대각선
				Game(x + 1, y - 1);
			}
			if (x != 0)
			{ //왼쪽 진선
				Game(x - 1, y);
			}
			if (x != 24)
			{ //오른쪽 직선
				Game(x + 1, y);
			}
			if (x != 0 && y != 24)
			{ //왼쪽 아래 대각선
				Game(x - 1, y + 1);
			}
			if (y != 24)
			{ //아래직선
				Game(x, y + 1);
			}
			if (x != 24 && y != 24)
			{ //오른쪽 아래 대각선
				Game(x + 1, y + 1);
			}
		}
		if (ClearClick())
		{
			Clear();
		}
		dc.SelectObject(&oldPen);
		dc.SelectObject(&oldBrush);
	}

	
}


void CMineSecondDlg::End()
{
	// TODO: 여기에 구현 코드 추가.

	KillTimer(1);
	if (AfxMessageBox(_T("새 게임?"), MB_YESNO) == IDYES)
	{
		OnPaint();
	}
	else
	{
		OnOK();
	}

	
}


void CMineSecondDlg::Clear()
{
	// TODO: 여기에 구현 코드 추가.
	// TODO: 여기에 구현 코드 추가.
	KillTimer(1);
	CString str;
	str.Format(_T("축하\n%d\n재시작?"), m_T);
	if (AfxMessageBox(str, MB_YESNO) == IDYES)
	{
		OnPaint();
	}
	else
	{
		OnOK();
	}
	
}


bool CMineSecondDlg::ClearClick()
{
	// TODO: 여기에 구현 코드 추가.
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_Block[i][j] != 1)
			{
				bool Clear = false;
				for (int v = 0; v < 80; v++)
				{
					if (m_Mine[v][0] == i && m_Mine[v][1] == j)
					{
						Clear = true;
					}
				}
				if (!Clear)
				{
					return false;
				}
			}
		}
	}

	return true;
}



void CMineSecondDlg::Flag(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.

	if (m_bBolckClick)
	{
		GameSide(x, y);
	}
	else
	{
		if (m_Block[x][y] == 0 && m_nMine != 0)
		{
			m_Block[x][y] = 2;
			m_Mine[100][100]--;
			UpdateData(false);

			CClientDC dc(this);
			CPen TwoPen(PS_SOLID, 1, RGB(0, 0, 0));
			CPen *oldPen = dc.SelectObject(&TwoPen);
			CBrush OneBrush(RGB(0, 0, 255));
			CBrush *oldBrush = dc.SelectObject(&OneBrush);
			dc.Rectangle(10 + 20 * x, 10 + 20 * y, 30 + 20 * x, 30 + 20 * y);
			dc.SelectObject(oldPen);
			dc.SelectObject(oldBrush);

		}
		else if (m_Block[x][y] == 2 && m_nMine != 10)
		{
			m_Block[x][y] = 0;
			m_Mine[100][100]++;
			UpdateData(false);

			CClientDC dc(this);
			CPen TwoPen(PS_SOLID, 1, RGB(0, 0, 0));
			CPen *oldPen = dc.SelectObject(&TwoPen);
			CBrush OneBrush(RGB(213, 213, 213));
			CBrush *oldBrush = dc.SelectObject(&OneBrush);
			dc.Rectangle(10 + 20 * x, 10 + 20 * y, 30 + 20 * x, 30 + 20 * y);
			dc.SelectObject(oldPen);
			dc.SelectObject(oldBrush);
		}
	}
	
}


void CMineSecondDlg::GameSide(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.

	int m_FindMine = 0;
	for (int i = 0; i < 80; i++)
	{
		if (((m_Mine[i][0] - x == 1 || m_Mine[i][0] - x == -1) && (m_Mine[i][1] - y == 1 ||
			m_Mine[i][1] - y == -1 || m_Mine[i][1] - y == 0)) ||
			(m_Mine[i][0] - x == 0 && (m_Mine[i][1] - y == 1 || m_Mine[i][1] - y == -1)))
		{
			m_FindMine++;
		}
	}

	int m_nFlag = 0;
	if (x != 0 && y != 0)
	{
		if (m_Block[x - 1][y - 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (y != 0)
	{
		if (m_Block[x][y - 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 25 && y != 0)
	{
		if (m_Block[x + 1][y - 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 0)
	{
		if (m_Block[x - 1][y] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 25)
	{
		if (m_Block[x + 1][y] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 0 && y != 25)
	{
		if (m_Block[x - 1][y + 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (y != 25)
	{
		if (m_Block[x][y + 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 25 && y != 25)
	{
		if (m_Block[x + 1][y + 1] == 2)
		{
			m_nFlag++;
		}
	}

	if (m_FindMine == m_nFlag)
	{
		if (x != 0 && y != 0)
		{
			Game(x - 1, y - 1);
		}
		if (y != 0)
		{
			Game(x, y - 1);
		}
		if (x != 24 && y != 0)
		{
			Game(x + 1, y - 1);
		}
		if (x != 0)
		{
			Game(x - 1, y);
		}
		if (x != 24)
		{
			Game(x + 1, y);
		}
		if (x != 0 && y != 24)
		{
			Game(x - 1, y + 1);
		}
		if (y != 24)
		{
			Game(x, y + 1);
		}
		if (x != 24 && y != 24)
		{
			Game(x + 1, y + 1);
		}
	}

	
}



void CMineSecondDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	m_bBolckClick = true;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMineSecondDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (point.x < 510 && point.y < 510)
	{
		Game((point.x - 10) / 20, (point.y - 10) / 20);
	}
	m_bBolckClick = false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMineSecondDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (point.x < 510 && point.y < 510)
	{
		Flag((point.x - 10) / 20, (point.y - 10) / 20);
	}


	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMineSecondDlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (point.x < 510 && point.y < 510)
	{
		GameSide((point.x - 10) / 20, (point.y - 10) / 20);
	}

	CDialogEx::OnMButtonDown(nFlags, point);
}



void CMineSecondDlg::OnClickedButtonStartSecond()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CClientDC dc(this);

	CPen OnePen, *oldPen;
	OnePen.CreatePen(PS_SOLID, 1, RGB(213, 213, 213));
	oldPen = dc.SelectObject(&OnePen);
	CBrush OneBrush(RGB(213, 213, 213));
	CBrush *oldBrush = dc.SelectObject(&OneBrush);
	dc.Rectangle(10, 10, 510, 510);

	CPen TwoPen;
	TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = dc.SelectObject(&TwoPen);
	for (int i = 0; i < 26; i++)
	{
		dc.MoveTo(10 + 20 * i, 10); //가
		dc.LineTo(10 + 20 * i, 10 + 20 * 25);
		dc.MoveTo(10, 10 + 20 * i);
		dc.LineTo(10 + 20 * 25, 10 + 20 * i);
	}
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 80; i++)
	{
		m_Mine[i][0] = rand() % 25;
		m_Mine[i][1] = rand() % 25;

		for (int j = 0; j < i; j++)
		{
			if (m_Mine[i][0] == m_Mine[j][0] && m_Mine[i][1] == m_Mine[j][1])
			{
				i--;
			}
		}
	}

	m_bBolckClick = false;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			m_Block[i][j] = 0;
		}
	}
	m_bClock = 0;
	m_nMine = 80;
	m_Mine[100][100] = 80;
	m_bStart = false;
	M[100][100];
	m_T = 0;

	UpdateData(false);

}


void CMineSecondDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	m_T++;
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CDC *pDC;
	pDC = GetDC();
	CString str;
	str.Format(_T("  %d  "), m_T);
	pDC->TextOut(95, 535, str);

	CDialogEx::OnTimer(nIDEvent);
}
