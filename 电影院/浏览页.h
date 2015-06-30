#pragma once


// 浏览页 对话框

class 浏览页 : public CDialogEx
{
	DECLARE_DYNAMIC(浏览页)

public:
	浏览页(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~浏览页();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_liulan };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
