#pragma once


// 后台 对话框

class 后台 : public CDialogEx
{
	DECLARE_DYNAMIC(后台)

public:
	后台(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~后台();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString tuipiao;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
