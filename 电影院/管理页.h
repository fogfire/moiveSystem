#pragma once


// 管理页 对话框

class 管理页 : public CDialogEx
{
	DECLARE_DYNAMIC(管理页)

public:
	管理页(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~管理页();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedonload();
};
