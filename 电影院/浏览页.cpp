// ���ҳ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "���ҳ.h"
#include "afxdialogex.h"
#include"��λ����ҳ.h"


// ���ҳ �Ի���

IMPLEMENT_DYNAMIC(���ҳ, CDialogEx)

���ҳ::���ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(���ҳ::IDD, pParent)
	, mv1(_T(""))
	, mv2(_T(""))
	, mv3(_T(""))
{

	EnableAutomation();

}

���ҳ::~���ҳ()
{
}

void ���ҳ::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void ���ҳ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, mv1);
	DDV_MaxChars(pDX, mv1, 200);
	DDX_Text(pDX, IDC_EDIT1, mv2);
	DDV_MaxChars(pDX, mv2, 200);
	DDX_Text(pDX, IDC_EDIT4, mv3);
	DDV_MaxChars(pDX, mv3, 200);
}


BEGIN_MESSAGE_MAP(���ҳ, CDialogEx)
	ON_BN_CLICKED(IDC_btnm1, &���ҳ::OnBnClickedbtnm1)
	ON_BN_CLICKED(IDC_btnm2, &���ҳ::OnBnClickedbtnm2)
	ON_BN_CLICKED(IDC_btnm3, &���ҳ::OnBnClickedbtnm3)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(���ҳ, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_I���ҳ ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {141B5978-2CC7-40DE-ACB4-EA358399AA22}
static const IID IID_I���ҳ =
{ 0x141B5978, 0x2CC7, 0x40DE, { 0xAC, 0xB4, 0xEA, 0x35, 0x83, 0x99, 0xAA, 0x22 } };

BEGIN_INTERFACE_MAP(���ҳ, CDialogEx)
	INTERFACE_PART(���ҳ, IID_I���ҳ, Dispatch)
END_INTERFACE_MAP()


// ���ҳ ��Ϣ�������


void ���ҳ::OnBnClickedbtnm1()
{
	ShowWindow(SW_HIDE);
	��λ����ҳ zx1;
	zx1.x = 1;
	zx1.DoModal();
	ShowWindow(SW_SHOW);
}


void ���ҳ::OnBnClickedbtnm2()
{
	ShowWindow(SW_HIDE);
	��λ����ҳ zx2;
	zx2.x = 2;
	zx2.DoModal();
	ShowWindow(SW_SHOW);
}


void ���ҳ::OnBnClickedbtnm3()
{
	ShowWindow(SW_HIDE);
	��λ����ҳ zx3;
	zx3.x = 3;
	zx3.DoModal();
	ShowWindow(SW_SHOW);
}
