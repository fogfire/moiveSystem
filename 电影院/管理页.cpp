// 管理页.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "管理页.h"
#include "afxdialogex.h"
#include"注册页.h"
#pragma warning(disable:4996)


// 管理页 对话框

IMPLEMENT_DYNAMIC(管理页, CDialogEx)

管理页::管理页(CWnd* pParent /*=NULL*/)
	: CDialogEx(管理页::IDD, pParent)
	, psw(_T(""))
	, userName(_T(""))
{

	EnableAutomation();

}

管理页::~管理页()
{
}

void 管理页::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void 管理页::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Username, user);
	DDX_Text(pDX, IDC_pwd, psw);
	DDX_Text(pDX, IDC_Username, userName);
}


BEGIN_MESSAGE_MAP(管理页, CDialogEx)
	ON_BN_CLICKED(IDC_onLoad, &管理页::OnBnClickedonload)
	ON_BN_CLICKED(IDC_btnGToS, &管理页::OnBnClickedbtngtos)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(管理页, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_I管理页 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {8ADBD56D-8AAB-46C4-9B69-AD21ABD5292A}
static const IID IID_I管理页 =
{ 0x8ADBD56D, 0x8AAB, 0x46C4, { 0x9B, 0x69, 0xAD, 0x21, 0xAB, 0xD5, 0x29, 0x2A } };

BEGIN_INTERFACE_MAP(管理页, CDialogEx)
	INTERFACE_PART(管理页, IID_I管理页, Dispatch)
END_INTERFACE_MAP()


// 管理页 消息处理程序


void 管理页::OnBnClickedonload()
{
	UpdateData(TRUE);
	char mi[20];
	FILE *fp;
loop:
	if (!(fp = fopen("res\\admin.pwd", "r")))
	{
		MessageBox(_T("第一次使用本系统，点击确认注册！用户名请填admin"));
		注册页 注册;
		this->ShowWindow(SW_HIDE);
		注册.DoModal();
		this->ShowWindow(SW_SHOW);
		goto loop;
	}
	fscanf(fp, "%s", mi);
	fclose(fp);
	if (userName != "admin")
	{
		MessageBox(_T("查询到0条此用户信息"));
	}
	if (userName == "admin"&&psw == mi)
	{
		MessageBox(_T("登陆成功！"));
		
	}
	else
	{
		MessageBox(_T("密码错误！重新输入"));
	}
	
}



void 管理页::OnBnClickedbtngtos()
{
	EndDialog(2);
}
