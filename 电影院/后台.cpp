// ��̨.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "��̨.h"
#include "afxdialogex.h"


// ��̨ �Ի���

IMPLEMENT_DYNAMIC(��̨, CDialogEx)

��̨::��̨(CWnd* pParent /*=NULL*/)
	: CDialogEx(��̨::IDD, pParent)
	, tuipiao(_T(""))
{

}

��̨::~��̨()
{
}

void ��̨::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, tuipiao);
}


BEGIN_MESSAGE_MAP(��̨, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &��̨::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &��̨::OnBnClickedButton2)
END_MESSAGE_MAP()


// ��̨ ��Ϣ�������


void ��̨::OnBnClickedButton1()//ͬ��
{
	
}


void ��̨::OnBnClickedButton2()//�ܾ�
{
	
}
