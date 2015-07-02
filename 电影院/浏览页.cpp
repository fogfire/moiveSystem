// 浏览页.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "浏览页.h"
#include "afxdialogex.h"
#include"座位详情页.h"
#pragma warning(disable:4996)

// 浏览页 对话框

IMPLEMENT_DYNAMIC(浏览页, CDialogEx)
浏览页::浏览页(CWnd* pParent /*=NULL*/)
	: CDialogEx(浏览页::IDD, pParent)
	, mv1(_T(""))
	, mv2(_T(""))
	, mv3(_T(""))
{
	char temp[200];
	FILE *fp;
	if (!(fp = fopen("res//1.ini", "r")))
		mv1 = "无法读取到影片详情。。。";
	else
	{
		fclose(fp);
		LONGLONG lOff = 0;         // 文件指针的偏移量，也是读取到的数据的总字节数   
		CFile file(_T("res//1.ini"),  CFile::modeRead);
		while (true)
		{
			// 以文件开头为基准，移动文件指针到lOff的位置   
			file.Seek(lOff, CFile::begin);
			// 读取100个字节的数据到存放读取数据的缓存的readBuffer + lOff位置处   
			int nRet = file.Read(temp + lOff, 1);
			// 根据实际读取的字节数，增加文件指针的移动量   
			lOff += nRet;
			// 如果读取数据时返回值小于指定的100，说明已到文件尾，跳出循环   
			if (nRet < 1)
			{
				temp[lOff]='\0';
				break;
			}
		}
		// 关闭文件   
		file.Close();
		mv1=temp;
	}
	if (!(fp = fopen("res//2.ini", "r")))
		mv2 = "无法读取到影片详情。。。";
	else
	{

		fclose(fp);
		LONGLONG lOff = 0;         // 文件指针的偏移量，也是读取到的数据的总字节数   
		CFile file(_T("res//2.ini"), CFile::modeRead);
		while (true)
		{
			// 以文件开头为基准，移动文件指针到lOff的位置   
			file.Seek(lOff, CFile::begin);
			// 读取100个字节的数据到存放读取数据的缓存的readBuffer + lOff位置处   
			int nRet = file.Read(temp + lOff, 1);
			// 根据实际读取的字节数，增加文件指针的移动量   
			lOff += nRet;
			// 如果读取数据时返回值小于指定的100，说明已到文件尾，跳出循环   
			if (nRet < 1)
			{
				temp[lOff] = '\0';
				break;
			}
		}
		// 关闭文件   
		file.Close();
		mv2 = temp;
	}
	if (!(fp = fopen("res//3.ini", "r")))
		mv3 = "无法读取到影片详情。。。";
	else
	{
		
		fclose(fp);
		LONGLONG lOff = 0;         // 文件指针的偏移量，也是读取到的数据的总字节数   
		CFile file(_T("res//3.ini"),  CFile::modeRead);
		while (true)
		{
			// 以文件开头为基准，移动文件指针到lOff的位置   
			file.Seek(lOff, CFile::begin);
			// 读取100个字节的数据到存放读取数据的缓存的readBuffer + lOff位置处   
			int nRet = file.Read(temp + lOff, 1);
			// 根据实际读取的字节数，增加文件指针的移动量   
			lOff += nRet;
			// 如果读取数据时返回值小于指定的100，说明已到文件尾，跳出循环   
			if (nRet < 1)
			{
				temp[lOff]='\0';
				break;
			}
		}
		// 关闭文件   
		file.Close();
		mv3=temp;
	}
	EnableAutomation();

}
浏览页::~浏览页()
{
}
void 浏览页::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。
	CDialogEx::OnFinalRelease();
}
void 浏览页::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, mv1);
	DDV_MaxChars(pDX, mv1, 200);
	DDX_Text(pDX, IDC_EDIT1, mv2);
	DDV_MaxChars(pDX, mv2, 200);
	DDX_Text(pDX, IDC_EDIT4, mv3);
	DDV_MaxChars(pDX, mv3, 200);
}
BEGIN_MESSAGE_MAP(浏览页, CDialogEx)
	ON_BN_CLICKED(IDC_btnm1, &浏览页::OnBnClickedbtnm1)
	ON_BN_CLICKED(IDC_btnm2, &浏览页::OnBnClickedbtnm2)
	ON_BN_CLICKED(IDC_btnm3, &浏览页::OnBnClickedbtnm3)
	ON_BN_CLICKED(IDC_BUTTON1, &浏览页::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &浏览页::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &浏览页::OnBnClickedButton3)
END_MESSAGE_MAP()
BEGIN_DISPATCH_MAP(浏览页, CDialogEx)
END_DISPATCH_MAP()
// 注意: 我们添加 IID_I浏览页 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。
// {141B5978-2CC7-40DE-ACB4-EA358399AA22}
static const IID IID_I浏览页 =
{ 0x141B5978, 0x2CC7, 0x40DE, { 0xAC, 0xB4, 0xEA, 0x35, 0x83, 0x99, 0xAA, 0x22 } };
BEGIN_INTERFACE_MAP(浏览页, CDialogEx)
	INTERFACE_PART(浏览页, IID_I浏览页, Dispatch)
END_INTERFACE_MAP()
// 浏览页 消息处理程序
void 浏览页::OnBnClickedbtnm1()
{
	ShowWindow(SW_HIDE);
	座位详情页 zx1(1);
	zx1.DoModal();
	ShowWindow(SW_SHOW);
	EndDialog(5);
}
void 浏览页::OnBnClickedbtnm2()
{
	ShowWindow(SW_HIDE);
	座位详情页 zx2(2);
	zx2.DoModal();
	ShowWindow(SW_SHOW);
	EndDialog(5);
}
void 浏览页::OnBnClickedbtnm3()
{
	ShowWindow(SW_HIDE);
	座位详情页 zx3(3);
	zx3.DoModal();
	ShowWindow(SW_SHOW);
	EndDialog(5);
}


void 浏览页::OnBnClickedButton1()//查看预告1
{
	CString CmdLine = L"explorer.exe http://v.youku.com/v_show/id_XMTI3NDY2MDgyNA";
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


void 浏览页::OnBnClickedButton2()
{

	CString CmdLine = L"explorer.exe http://http://v.youku.com/v_show/id_XMTI1OTg5MDA3Ng";
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


void 浏览页::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CString CmdLine = L"explorer.exe http://v.youku.com/v_show/id_XMTI3MzEzMTU0NA";
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
