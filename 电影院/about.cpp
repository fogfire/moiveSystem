// about.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "about.h"
#include "afxdialogex.h"


// about �Ի���

IMPLEMENT_DYNAMIC(about, CDialogEx)

about::about(CWnd* pParent /*=NULL*/)
	: CDialogEx(about::IDD, pParent)
{

}

about::~about()
{
}

void about::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(about, CDialogEx)
	ON_BN_CLICKED(btn_go, &about::OnBnClickedgo)
	ON_BN_CLICKED(IDC_BUTTON2, &about::OnBnClickedButton2)
END_MESSAGE_MAP()


/*BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(btn_go, &CAboutDlg::OnBnClickedgo)
	ON_BN_CLICKED(btn_go, &CAboutDlg::OnBnClickedgo)
END_MESSAGE_MAP()*/
void about::OnBnClickedgo()
{
	CString CmdLine = L"explorer.exe https://github.com/fogfire/moiveSystem/";
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//����ת��,���MSDN
	STARTUPINFO si = { sizeof(si) }; //������̵�������Ϣ
	PROCESS_INFORMATION pi;   //������̵������Ϣ
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1������ʾ,0��ʾ��̨����
	BOOL bRet = ::CreateProcess  //���ô������̺���
		(
		NULL,
		Cmd,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
		);
	if (bRet)
	{
		::CloseHandle(pi.hProcess); //�رս��̾��
		::CloseHandle(pi.hThread);  //�ر����߳̾��
	}
}

void about::OnBnClickedButton2()
{
	CString CmdLine = L"explorer.exe http://fogfire.xyz/";
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//����ת��,���MSDN
	STARTUPINFO si = { sizeof(si) }; //������̵�������Ϣ
	PROCESS_INFORMATION pi;   //������̵������Ϣ
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1������ʾ,0��ʾ��̨����
	BOOL bRet = ::CreateProcess  //���ô������̺���
		(
		NULL,
		Cmd,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
		);
	if (bRet)
	{
		::CloseHandle(pi.hProcess); //�رս��̾��
		::CloseHandle(pi.hThread);  //�ر����߳̾��
	}
}
