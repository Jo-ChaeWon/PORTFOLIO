// CMineFirstDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "team5_pro2.h"
#include "CMineFirstDlg.h"
#include "afxdialogex.h"


// CMineFirstDlg 대화 상자

IMPLEMENT_DYNAMIC(CMineFirstDlg, CDialogEx)

CMineFirstDlg::CMineFirstDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FIRST, pParent)
	,m_bStart(false)
	,m_nFlag(0)
	,m_nMine(0)
	,m_Flag(0)
{
	m_nFlag = 0;
	m_nMine = 0;
	m_Mine[100][100] = 0;
	m_Flag = 0;
	m_Block[100][100] = 0;
	m_FindMine = 0;
	M[100][100] = 0;
	m_timer = 0;
}

CMineFirstDlg::~CMineFirstDlg()
{
}

void CMineFirstDlg::DoDataExchange(CDataExchange* pDX)
{

	
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT_LANDMNE_FIRST,m_Mine[100][100]);	

}


BEGIN_MESSAGE_MAP(CMineFirstDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_START_FIRST, &CMineFirstDlg::OnClickedButtonStartFirst)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
//	ON_WM_CREATE()
END_MESSAGE_MAP()


// CMineFirstDlg 메시지 처리기

//void CMineFirstDlg::Format()
//{
//	// TODO: 여기에 구현 코드 추가.
//	
//}

void CMineFirstDlg::OnPaint()
{
	
	
	SetTimer(1, 1000, NULL);
	
	CPaintDC dc(this); // device context for painting

	//dc.TextOutW(, 0, L"CPaintDC class를 이용해 화면에 문자열 출력");
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CPen OnePen, *oldPen;
	OnePen.CreatePen(PS_SOLID, 1, RGB(213, 213, 213));
	oldPen = dc.SelectObject(&OnePen);
	CBrush OneBrush(RGB(213, 213, 213));
	CBrush *oldBrush = dc.SelectObject(&OneBrush);
	dc.Rectangle(10, 10, 330, 330);

	CPen TwoPen;
	TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = dc.SelectObject(&TwoPen);
	for (int i = 0; i < 17; i++)
	{
		dc.MoveTo(10 + 20 * i, 10); //가
		dc.LineTo(10 + 20 * i, 10 + 20 * 16);
		dc.MoveTo(10, 10 + 20 * i);
		dc.LineTo(10 + 20 * 16, 10 + 20 * i);
	}
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 25; i++)
	{
		m_Mine[i][0] = rand() % 16;
		m_Mine[i][1] = rand() % 16;

		for (int j = 0; j < i; j++)
		{
			if (m_Mine[i][0] == m_Mine[j][0] && m_Mine[i][1] == m_Mine[j][1])
			{
				i--;
			}
		}
	}

	m_bBolckClick = false;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			m_Block[i][j] = 0;
		}
	}
	
	m_nMine = 25;
	m_Mine[100][100] = 25;
	m_bStart = false;

	
	UpdateData(false);
}

void CMineFirstDlg::Game(int x, int y)
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
		for (int i = 0; i < 25; i++)
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
			for (int j = 0; j < 25; j++)
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
			if (x != 15 && y != 0)
			{ //오른쪽 대각선
				Game(x + 1, y - 1);
			}
			if (x != 0)
			{ //왼쪽 진선
				Game(x - 1, y);
			}
			if (x != 15)
			{ //오른쪽 직선
				Game(x + 1, y);
			}
			if (x != 0 && y != 15)
			{ //왼쪽 아래 대각선
				Game(x - 1, y + 1);
			}
			if (y != 15)
			{ //아래직선
				Game(x, y + 1);
			}
			if (x != 15 && y != 15)
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

void CMineFirstDlg::OnClickedButtonStartFirst()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CClientDC dc(this); 

	CPen OnePen, *oldPen;
	OnePen.CreatePen(PS_SOLID, 1, RGB(213, 213, 213));
	oldPen = dc.SelectObject(&OnePen);

	CBrush OneBrush(RGB(213, 213, 213));
	CBrush *oldBrush = dc.SelectObject(&OneBrush);
	dc.Rectangle(10, 10, 330, 330);

	CPen TwoPen;
	TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = dc.SelectObject(&TwoPen);
	for (int i = 0; i < 17; i++)
	{
		dc.MoveTo(10 + 20 * i, 10); //가
		dc.LineTo(10 + 20 * i, 10 + 20 * 16);
		dc.MoveTo(10, 10 + 20 * i);
		dc.LineTo(10 + 20 * 16, 10 + 20 * i);
	}
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 25; i++)
	{
		m_Mine[i][0] = rand() % 16;
		m_Mine[i][1] = rand() % 16;

		for (int j = 0; j < i; j++)
		{
			if (m_Mine[i][0] == m_Mine[j][0] && m_Mine[i][1] == m_Mine[j][1])
			{
				i--;
			}
		}
	}

	m_bBolckClick = false;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			m_Block[i][j] = 0;
		}
	}
	
	m_nMine = 25;
	m_Mine[100][100] = 25;
	m_bStart = false;
	M[100][100];
	m_T = 0;

	UpdateData(false);
}


void CMineFirstDlg::End()
{
	//TODO: 여기에 구현 코드 추가.
	KillTimer(1);

	if (AfxMessageBox(_T("Re Game?"), MB_YESNO) == IDYES)
	{
		OnPaint();
	}
	else if(IDNO)
	{
		OnOK();
	}
}


void CMineFirstDlg::Clear()
{
	// TODO: 여기에 구현 코드 추가.
	KillTimer(1);
	CString str;
	str.Format(_T("Congratulations\nSecond :  %d\nRe Start?"), m_T);
	if (AfxMessageBox(str, MB_YESNO) == IDYES)
	{
		OnPaint();
	}
	else if(IDNO)
	{
		OnOK();
	}
	
}


bool CMineFirstDlg::ClearClick()
{
	// TODO: 여기에 구현 코드 추가.
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (m_Block[i][j] != 1)
			{
				bool Clear = false;
				for (int v = 0; v < 25; v++)
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





void CMineFirstDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	

	m_bBolckClick = true;
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMineFirstDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (point.x < 330 && point.y < 330)
	{
		Game((point.x - 10) / 20, (point.y - 10) / 20); // 한 개 이미지의 선택 범위를 나타내기 위헤 20을 나눔
	}
	m_bBolckClick = false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMineFirstDlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (point.x < 330 && point.y < 330)
	{
		GameSide((point.x - 10) / 20, (point.y - 10) / 20);
	}

	CDialogEx::OnMButtonDown(nFlags, point);
}


void CMineFirstDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (point.x < 330 && point.y < 330)
	{
		Flag((point.x - 10) / 20, (point.y - 10) / 20);
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMineFirstDlg::Flag(int x, int y)
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
			CPen TwoPen, *oldPen;
			TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			oldPen = dc.SelectObject(&TwoPen);
			
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
			CPen TwoPen, *oldPen;
			TwoPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			oldPen = dc.SelectObject(&TwoPen);

			CBrush OneBrush(RGB(213, 213, 213));
			CBrush *oldBrush = dc.SelectObject(&OneBrush);
			dc.Rectangle(10 + 20 * x, 10 + 20 * y, 30 + 20 * x, 30 + 20 * y);
			dc.SelectObject(oldPen);
			dc.SelectObject(oldBrush);
		}
	}

}


void CMineFirstDlg::GameSide(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.
	int m_FindMine = 0;
	for (int i = 0; i < 25; i++)
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
	if (x != 15 && y != 0)
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
	if (x != 15)
	{
		if (m_Block[x + 1][y] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 0 && y != 15)
	{
		if (m_Block[x - 1][y + 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (y != 15)
	{
		if (m_Block[x][y + 1] == 2)
		{
			m_nFlag++;
		}
	}
	if (x != 15 && y != 15)
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
		if (x != 15 && y != 0)
		{
			Game(x + 1, y - 1);
		}
		if (x != 0)
		{
			Game(x - 1, y);
		}
		if (x != 15)
		{
			Game(x + 1, y);
		}
		if (x != 0 && y != 15)
		{
			Game(x - 1, y + 1);
		}
		if (y != 15)
		{
			Game(x, y + 1);
		}
		if (x != 15 && y != 15)
		{
			Game(x + 1, y + 1);
		}
	}

}


void CMineFirstDlg::OnTimer(UINT nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CDC *pDC;
	pDC = GetDC();
	CString str;
	str.Format(_T("  %d  "),m_T);
	pDC->TextOut(60, 360, str);

	m_T++;

	CDialogEx::OnTimer(nIDEvent);
}


//int CMineFirstDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
//	SetTimer(0, 1000, NULL);   // 타이머 설정, 1초에 한번씨 WM_TIMER 메시지 발생
//
//	m_bTimerRun = TRUE;        // 타이머 동작
//	return 0;
//}
