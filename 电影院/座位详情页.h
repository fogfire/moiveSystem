#pragma once
#include "mscomm1.h"


// ��λ����ҳ �Ի���

class ��λ����ҳ : public CDialogEx
{
	DECLARE_DYNAMIC(��λ����ҳ)

public:
	int  x;
	��λ����ҳ(CWnd* pParent = NULL);
	��λ����ҳ(int a);
	virtual ~��λ����ҳ();
	
// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
