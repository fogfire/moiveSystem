#pragma once
#include "mscomm1.h"


// ��λ����ҳ �Ի���

class ��λ����ҳ : public CDialogEx
{
	DECLARE_DYNAMIC(��λ����ҳ)

public:
	��λ����ҳ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~��λ����ҳ();
	int x;
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
};
