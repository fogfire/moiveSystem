#pragma once


// ע��ҳ �Ի���

class ע��ҳ : public CDialogEx
{
	DECLARE_DYNAMIC(ע��ҳ)

public:
	ע��ҳ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ע��ҳ();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m1;
	CString m2;
	afx_msg void OnBnClickedButton1();
};
