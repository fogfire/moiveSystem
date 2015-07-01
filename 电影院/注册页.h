#pragma once


// 注册页 对话框

class 注册页 : public CDialogEx
{
	DECLARE_DYNAMIC(注册页)

public:
	注册页(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~注册页();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m1;
	CString m2;
	afx_msg void OnBnClickedButton1();
};
