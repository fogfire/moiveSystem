#pragma once


// about �Ի���

class about : public CDialogEx
{
	DECLARE_DYNAMIC(about)

public:
	about(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~about();
	afx_msg void OnBnClickedgo();
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};
