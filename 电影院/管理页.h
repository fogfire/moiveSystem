#pragma once


// ����ҳ �Ի���

class ����ҳ : public CDialogEx
{
	DECLARE_DYNAMIC(����ҳ)

public:
	����ҳ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~����ҳ();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedonload();
};
