#pragma once


// CMineThirdDlg 대화 상자

class CMineThirdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMineThirdDlg)

public:
	CMineThirdDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMineThirdDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_THIRD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
protected:
	HICON m_hIcon;
public:
	afx_msg void OnPaint();
	bool m_bStart;
	bool m_bClock;
	int m_nFlag;
	int m_nMine;
	int m_Mine[100][100];
	int m_Flag;
	bool m_bBolckClick;
	int m_Block[100][100];
	int m_FindMine;
	int i;
	int j;
	void End();
	void Game(int x, int y);
	void Clear();
	bool ClearClick();
	void Flag (int x, int y);
	void GameSide(int x, int y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClickedButtonStartThird();
	int M[100][100];
	int m_T;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};