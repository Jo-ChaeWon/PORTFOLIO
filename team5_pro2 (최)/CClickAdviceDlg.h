#pragma once


// CClickAdviceDlg 대화 상자

class CClickAdviceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClickAdviceDlg)

public:
	CClickAdviceDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CClickAdviceDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADVICE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
