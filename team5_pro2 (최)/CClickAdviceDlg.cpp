// CClickAdviceDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "team5_pro2.h"
#include "CClickAdviceDlg.h"
#include "afxdialogex.h"


// CClickAdviceDlg 대화 상자

IMPLEMENT_DYNAMIC(CClickAdviceDlg, CDialogEx)

CClickAdviceDlg::CClickAdviceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADVICE, pParent)
{

}

CClickAdviceDlg::~CClickAdviceDlg()
{
}

void CClickAdviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClickAdviceDlg, CDialogEx)
END_MESSAGE_MAP()


// CClickAdviceDlg 메시지 처리기
