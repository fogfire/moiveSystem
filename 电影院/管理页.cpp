// 管理页.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "管理页.h"
#include "afxdialogex.h"


// 管理页 对话框

IMPLEMENT_DYNAMIC(管理页, CDialogEx)

管理页::管理页(CWnd* pParent /*=NULL*/)
	: CDialogEx(管理页::IDD, pParent)
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
}


BEGIN_MESSAGE_MAP(管理页, CDialogEx)
	ON_BN_CLICKED(IDC_onLoad, &管理页::OnBnClickedonload)
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

	MessageBox(_T("登陆成功！"));
	CDialog::OnOK();
	// TODO:  在此添加控件通知处理程序代码
}
