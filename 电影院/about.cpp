// about.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "about.h"
#include "afxdialogex.h"


// about 对话框

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
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//类型转换,详见MSDN
	STARTUPINFO si = { sizeof(si) }; //保存进程的启动信息
	PROCESS_INFORMATION pi;   //保存进程的相关信息
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1窗口显示,0表示后台运行
	BOOL bRet = ::CreateProcess  //调用创建进程函数
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
		::CloseHandle(pi.hProcess); //关闭进程句柄
		::CloseHandle(pi.hThread);  //关闭主线程句柄
	}
}

void about::OnBnClickedButton2()
{
	CString CmdLine = L"explorer.exe http://fogfire.xyz/";
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//类型转换,详见MSDN
	STARTUPINFO si = { sizeof(si) }; //保存进程的启动信息
	PROCESS_INFORMATION pi;   //保存进程的相关信息
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1窗口显示,0表示后台运行
	BOOL bRet = ::CreateProcess  //调用创建进程函数
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
		::CloseHandle(pi.hProcess); //关闭进程句柄
		::CloseHandle(pi.hThread);  //关闭主线程句柄
	}
}
