// 注册页.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "注册页.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)


// 注册页 对话框

IMPLEMENT_DYNAMIC(注册页, CDialogEx)

注册页::注册页(CWnd* pParent /*=NULL*/)
	: CDialogEx(注册页::IDD, pParent)
	, m1(_T(""))
	, m2(_T(""))
{

}

注册页::~注册页()
{
}

void 注册页::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m1);
	DDX_Text(pDX, IDC_EDIT2, m2);
}


BEGIN_MESSAGE_MAP(注册页, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &注册页::OnBnClickedButton1)
END_MESSAGE_MAP()


// 注册页 消息处理程序


void 注册页::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (m1 == m2)
	{
		const size_t strsize = (m1.GetLength() + 1) * 2; // 宽字符的长度;
		char * pstr = new char[strsize]; //分配空间;
		size_t sz = 0;
		wcstombs_s(&sz, pstr, strsize, m1, _TRUNCATE);

		int n = atoi((const char*)pstr); // 字符串已经由原来的CString 转换成了 const char*
		FILE *fp;
		if (!(fp = fopen("res\\admin.pwd", "w")))
		{
			MessageBox(_T("居然打不开文件，写不到文件我也是醉了。"));
		}
		fprintf(fp, "%s", pstr);
		fclose(fp);
		EndDialog(0);
	}
}
