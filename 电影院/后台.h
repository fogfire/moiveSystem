#pragma once


// ��̨ �Ի���

class ��̨ : public CDialogEx
{
	DECLARE_DYNAMIC(��̨)

public:
	��̨(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~��̨();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString tuipiao;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
