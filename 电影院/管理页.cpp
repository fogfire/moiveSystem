// ����ҳ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "����ҳ.h"
#include "afxdialogex.h"


// ����ҳ �Ի���

IMPLEMENT_DYNAMIC(����ҳ, CDialogEx)

����ҳ::����ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(����ҳ::IDD, pParent)
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
	MessageBox(_T("��½�ɹ���"));
	CDialog::OnOK();
}



void ����ҳ::OnBnClickedbtngtos()
{
	EndDialog(2);
}
