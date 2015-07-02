#pragma once
#include "mscomm1.h"
#include "afxwin.h"


// 座位详情页 对话框

class 座位详情页 : public CDialogEx
{
	DECLARE_DYNAMIC(座位详情页)

public:
	int  x;
	int flag;
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
	CStatic t11;
	CStatic t12;
	CStatic t13;
	CStatic t14;
	CStatic t21;
	CStatic t22;
	CStatic t23;
	CStatic t24;
	CStatic t31;
	CStatic t32;
	CStatic t33;
	CStatic t34;
	CStatic t41;
	CStatic t43;
	CStatic t42;
	CStatic t44;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
};
