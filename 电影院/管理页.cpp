// ����ҳ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "����ҳ.h"
#include "afxdialogex.h"
#include"ע��ҳ.h"
#pragma warning(disable:4996)


// ����ҳ �Ի���

IMPLEMENT_DYNAMIC(����ҳ, CDialogEx)

����ҳ::����ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(����ҳ::IDD, pParent)
	, psw(_T(""))
	, userName(_T(""))
{

	EnableAutomation();

}

����ҳ::~����ҳ()
{
}

void ����ҳ::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void ����ҳ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Username, user);
	DDX_Text(pDX, IDC_pwd, psw);
	DDX_Text(pDX, IDC_Username, userName);
}


BEGIN_MESSAGE_MAP(����ҳ, CDialogEx)
	ON_BN_CLICKED(IDC_onLoad, &����ҳ::OnBnClickedonload)
	ON_BN_CLICKED(IDC_btnGToS, &����ҳ::OnBnClickedbtngtos)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(����ҳ, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_I����ҳ ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {8ADBD56D-8AAB-46C4-9B69-AD21ABD5292A}
static const IID IID_I����ҳ =
{ 0x8ADBD56D, 0x8AAB, 0x46C4, { 0x9B, 0x69, 0xAD, 0x21, 0xAB, 0xD5, 0x29, 0x2A } };

BEGIN_INTERFACE_MAP(����ҳ, CDialogEx)
	INTERFACE_PART(����ҳ, IID_I����ҳ, Dispatch)
END_INTERFACE_MAP()


// ����ҳ ��Ϣ�������


void ����ҳ::OnBnClickedonload()
{
	UpdateData(TRUE);
	char mi[20];
	FILE *fp;
loop:
	if (!(fp = fopen("res\\admin.pwd", "r")))
	{
		MessageBox(_T("��һ��ʹ�ñ�ϵͳ�����ȷ��ע�ᣡ�û�������admin"));
		ע��ҳ ע��;
		this->ShowWindow(SW_HIDE);
		ע��.DoModal();
		this->ShowWindow(SW_SHOW);
		goto loop;
	}
	fscanf(fp, "%s", mi);
	fclose(fp);
	if (userName != "admin")
	{
		MessageBox(_T("��ѯ��0�����û���Ϣ"));
	}
	if (userName == "admin"&&psw == mi)
	{
		MessageBox(_T("��½�ɹ���"));
		
	}
	else
	{
		MessageBox(_T("���������������"));
	}
	
}



void ����ҳ::OnBnClickedbtngtos()
{
	EndDialog(2);
}
