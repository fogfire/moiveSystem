#pragma once
#include "mscomm1.h"


// 座位详情页 对话框

class 座位详情页 : public CDialogEx
{
	DECLARE_DYNAMIC(座位详情页)

public:
	int  x;
	座位详情页(CWnd* pParent = NULL);
	座位详情页(int a);
	virtual ~座位详情页();
	
// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	//DECLARE_MESSAGE_MAP()
public:
	int diDian;
	int xuanWei;
	CMscomm1 comKou;
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	afx_msg void OnCbnSelchangeCombo1();
	int changCi;
	//DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedupdata();
	afx_msg void OnBnClickedButton3();
};
