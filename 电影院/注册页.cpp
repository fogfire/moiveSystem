// ע��ҳ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "ע��ҳ.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)


// ע��ҳ �Ի���

IMPLEMENT_DYNAMIC(ע��ҳ, CDialogEx)

ע��ҳ::ע��ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(ע��ҳ::IDD, pParent)
	, m1(_T(""))
	, m2(_T(""))
{

}

ע��ҳ::~ע��ҳ()
{
}

void ע��ҳ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m1);
	DDX_Text(pDX, IDC_EDIT2, m2);
}


BEGIN_MESSAGE_MAP(ע��ҳ, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ע��ҳ::OnBnClickedButton1)
END_MESSAGE_MAP()


// ע��ҳ ��Ϣ�������


void ע��ҳ::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (m1 == m2)
	{
		const size_t strsize = (m1.GetLength() + 1) * 2; // ���ַ��ĳ���;
		char * pstr = new char[strsize]; //����ռ�;
		size_t sz = 0;
		wcstombs_s(&sz, pstr, strsize, m1, _TRUNCATE);

		int n = atoi((const char*)pstr); // �ַ����Ѿ���ԭ����CString ת������ const char*
		FILE *fp;
		if (!(fp = fopen("res\\admin.pwd", "w")))
		{
			MessageBox(_T("��Ȼ�򲻿��ļ���д�����ļ���Ҳ�����ˡ�"));
		}
		fprintf(fp, "%s", pstr);
		fclose(fp);
		EndDialog(0);
	}
}
