// ���ҳ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "���ҳ.h"
#include "afxdialogex.h"
#include"��λ����ҳ.h"
#pragma warning(disable:4996)

// ���ҳ �Ի���

IMPLEMENT_DYNAMIC(���ҳ, CDialogEx)
���ҳ::���ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(���ҳ::IDD, pParent)
	, mv1(_T(""))
	, mv2(_T(""))
	, mv3(_T(""))
{
	char temp[200];
	FILE *fp;
	if (!(fp = fopen("res//1.ini", "r")))
		mv1 = "�޷���ȡ��ӰƬ���顣����";
	else
	{
		fclose(fp);
		LONGLONG lOff = 0;         // �ļ�ָ���ƫ������Ҳ�Ƕ�ȡ�������ݵ����ֽ���   
		CFile file(_T("res//1.ini"),  CFile::modeRead);
		while (true)
		{
			// ���ļ���ͷΪ��׼���ƶ��ļ�ָ�뵽lOff��λ��   
			file.Seek(lOff, CFile::begin);
			// ��ȡ100���ֽڵ����ݵ���Ŷ�ȡ���ݵĻ����readBuffer + lOffλ�ô�   
			int nRet = file.Read(temp + lOff, 1);
			// ����ʵ�ʶ�ȡ���ֽ����������ļ�ָ����ƶ���   
			lOff += nRet;
			// �����ȡ����ʱ����ֵС��ָ����100��˵���ѵ��ļ�β������ѭ��   
			if (nRet < 1)
			{
				temp[lOff]='\0';
				break;
			}
		}
		// �ر��ļ�   
		file.Close();
		mv1=temp;
	}
	if (!(fp = fopen("res//2.ini", "r")))
		mv2 = "�޷���ȡ��ӰƬ���顣����";
	else
	{

		fclose(fp);
		LONGLONG lOff = 0;         // �ļ�ָ���ƫ������Ҳ�Ƕ�ȡ�������ݵ����ֽ���   
		CFile file(_T("res//2.ini"), CFile::modeRead);
		while (true)
		{
			// ���ļ���ͷΪ��׼���ƶ��ļ�ָ�뵽lOff��λ��   
			file.Seek(lOff, CFile::begin);
			// ��ȡ100���ֽڵ����ݵ���Ŷ�ȡ���ݵĻ����readBuffer + lOffλ�ô�   
			int nRet = file.Read(temp + lOff, 1);
			// ����ʵ�ʶ�ȡ���ֽ����������ļ�ָ����ƶ���   
			lOff += nRet;
			// �����ȡ����ʱ����ֵС��ָ����100��˵���ѵ��ļ�β������ѭ��   
			if (nRet < 1)
			{
				temp[lOff] = '\0';
				break;
			}
		}
		// �ر��ļ�   
		file.Close();
		mv2 = temp;
	}
	if (!(fp = fopen("res//3.ini", "r")))
		mv3 = "�޷���ȡ��ӰƬ���顣����";
	else
	{
		
		fclose(fp);
		LONGLONG lOff = 0;         // �ļ�ָ���ƫ������Ҳ�Ƕ�ȡ�������ݵ����ֽ���   
		CFile file(_T("res//3.ini"),  CFile::modeRead);
		while (true)
		{
			// ���ļ���ͷΪ��׼���ƶ��ļ�ָ�뵽lOff��λ��   
			file.Seek(lOff, CFile::begin);
			// ��ȡ100���ֽڵ����ݵ���Ŷ�ȡ���ݵĻ����readBuffer + lOffλ�ô�   
			int nRet = file.Read(temp + lOff, 1);
			// ����ʵ�ʶ�ȡ���ֽ����������ļ�ָ����ƶ���   
			lOff += nRet;
			// �����ȡ����ʱ����ֵС��ָ����100��˵���ѵ��ļ�β������ѭ��   
			if (nRet < 1)
			{
				temp[lOff]='\0';
				break;
			}
		}
		// �ر��ļ�   
		file.Close();
		mv3=temp;
	}
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
	ON_BN_CLICKED(IDC_BUTTON1, &���ҳ::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &���ҳ::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &���ҳ::OnBnClickedButton3)
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
	��λ����ҳ zx1(1);
	zx1.DoModal();
	ShowWindow(SW_SHOW);
	EndDialog(5);
}
void ���ҳ::OnBnClickedbtnm2()
{
	ShowWindow(SW_HIDE);
	��λ����ҳ zx2(2);
	zx2.DoModal();
	ShowWindow(SW_SHOW);
	EndDialog(5);
}
void ���ҳ::OnBnClickedbtnm3()
{
	ShowWindow(SW_HIDE);
	��λ����ҳ zx3(3);
	zx3.DoModal();
	ShowWindow(SW_SHOW);
	EndDialog(5);
}


void ���ҳ::OnBnClickedButton1()//�鿴Ԥ��1
{
	CString CmdLine = L"explorer.exe http://v.youku.com/v_show/id_XMTI3NDY2MDgyNA";
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//����ת��,���MSDN
	STARTUPINFO si = { sizeof(si) }; //������̵�������Ϣ
	PROCESS_INFORMATION pi;   //������̵������Ϣ
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1������ʾ,0��ʾ��̨����
	BOOL bRet = ::CreateProcess  //���ô������̺���
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
		::CloseHandle(pi.hProcess); //�رս��̾��
		::CloseHandle(pi.hThread);  //�ر����߳̾��
	}
}


void ���ҳ::OnBnClickedButton2()
{

	CString CmdLine = L"explorer.exe http://http://v.youku.com/v_show/id_XMTI1OTg5MDA3Ng";
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//����ת��,���MSDN
	STARTUPINFO si = { sizeof(si) }; //������̵�������Ϣ
	PROCESS_INFORMATION pi;   //������̵������Ϣ
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1������ʾ,0��ʾ��̨����
	BOOL bRet = ::CreateProcess  //���ô������̺���
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
		::CloseHandle(pi.hProcess); //�رս��̾��
		::CloseHandle(pi.hThread);  //�ر����߳̾��
	}

}


void ���ҳ::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString CmdLine = L"explorer.exe http://v.youku.com/v_show/id_XMTI3MzEzMTU0NA";
	LPTSTR Cmd = (LPTSTR)(LPCTSTR)CmdLine;//����ת��,���MSDN
	STARTUPINFO si = { sizeof(si) }; //������̵�������Ϣ
	PROCESS_INFORMATION pi;   //������̵������Ϣ
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1; //1������ʾ,0��ʾ��̨����
	BOOL bRet = ::CreateProcess  //���ô������̺���
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
		::CloseHandle(pi.hProcess); //�رս��̾��
		::CloseHandle(pi.hThread);  //�ر����߳̾��
	}
}
