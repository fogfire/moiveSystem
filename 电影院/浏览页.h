#pragma once


// ���ҳ �Ի���

class ���ҳ : public CDialogEx
{
	DECLARE_DYNAMIC(���ҳ)

public:
	���ҳ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~���ҳ();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_liulan };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString mv1;
	CString mv2;
	CString mv3;
	afx_msg void OnBnClickedbtnm1();
	afx_msg void OnBnClickedbtnm2();
	afx_msg void OnBnClickedbtnm3();
};
