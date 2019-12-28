#pragma once


// CMineFirstDlg 대화 상자

class CMineFirstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMineFirstDlg)

public:
	CMineFirstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMineFirstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIRST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

protected:
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

	afx_msg void OnClickedButtonStartFirst();
	COLORREF m_colorPen;
	COLORREF m_colorBrush;
	bool m_bStart;
	bool m_bClock;
	int m_nFlag;
	int m_nMine;
	int m_Mine[100][100];
	int m_Flag;
	bool m_bBolckClick;
	int m_Block[100][100];
	int m_FindMine;
	void End();
	void Clear();
	bool ClearClick();
	void Game(int x, int y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void Flag(int x, int y);
	void GameSide(int x, int y);
	int i;
	int j;
//	void Format();
	afx_msg void OnTimer(UINT nIDEvent);
//	CPoint m_ptText;
//	CString m_strText;
	bool m_bTimerRun;
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	int M[100][100];
	int m_T;
	int m_timer;
//	CString m_Button;
};
