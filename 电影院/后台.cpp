// 后台.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "后台.h"
#include "afxdialogex.h"


// 后台 对话框

IMPLEMENT_DYNAMIC(后台, CDialogEx)

后台::后台(CWnd* pParent /*=NULL*/)
	: CDialogEx(后台::IDD, pParent)
	, tuipiao(_T(""))
{

}

后台::~后台()
{
}

void 后台::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, tuipiao);
}


BEGIN_MESSAGE_MAP(后台, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &后台::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &后台::OnBnClickedButton2)
END_MESSAGE_MAP()


// 后台 消息处理程序


void 后台::OnBnClickedButton1()//同意
{
	
}


void 后台::OnBnClickedButton2()//拒绝
{
	
}
