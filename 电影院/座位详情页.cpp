// ��λ����ҳ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "��λ����ҳ.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)
void init();
void load();
void save();
char str[3][5][16];
char fileDizhi[20];
// ��λ����ҳ �Ի���

IMPLEMENT_DYNAMIC(��λ����ҳ, CDialogEx)

��λ����ҳ::��λ����ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(��λ����ҳ::IDD, pParent)
	, diDian(0)
	, xuanWei(0)
	, changCi(0)
{
}

��λ����ҳ::��λ����ҳ(int a)
: CDialogEx(��λ����ҳ::IDD, NULL)
, diDian(0)
, xuanWei(0)
, changCi(0)
{
	x = a;
	switch (x)
	{
	case 1: strcpy(fileDizhi, "res\\1.res"); break;
	case 2: strcpy(fileDizhi, "res\\2.res"); break;
	case 3: strcpy(fileDizhi, "res\\3.res"); break;
	default:
		EndDialog(0);
		break;
	}
}
��λ����ҳ::~��λ����ҳ()
{
}

void ��λ����ҳ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO1, diDian);
	DDX_Text(pDX, IDC_EDIT1, xuanWei);
	DDV_MinMaxInt(pDX, xuanWei, 1, 16);
	DDX_Control(pDX, IDC_MSCOMM1, comKou);
	DDX_CBIndex(pDX, IDC_COMBO2, changCi);
	/*
	DDX_Control(pDX, IDC_w11, t11);
	DDX_Control(pDX, IDC_w12, t12);
	DDX_Control(pDX, IDC_w13, t13);
	DDX_Control(pDX, IDC_w14, t14);
	DDX_Control(pDX, IDC_w15, t21);
	DDX_Control(pDX, IDC_w16, t22);
	DDX_Control(pDX, IDC_w17, t23);
	DDX_Control(pDX, IDC_w18, t24);
	DDX_Control(pDX, IDC_w19, t31);
	DDX_Control(pDX, IDC_w20, t32);
	DDX_Control(pDX, IDC_w21, t33);
	DDX_Control(pDX, IDC_w22, t34);
	DDX_Control(pDX, IDC_w23, t41);
	DDX_Control(pDX, IDC_w24, t42);
	DDX_Control(pDX, IDC_w25, t43);
	DDX_Control(pDX, IDC_w26, t44);
	*/
}




// ��λ����ҳ ��Ϣ�������
BEGIN_EVENTSINK_MAP(��λ����ҳ, CDialogEx)
	ON_EVENT(��λ����ҳ, IDC_MSCOMM1, 1, ��λ����ҳ::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void ��λ����ҳ::OnCommMscomm1()
{
	VARIANT input1;

	BYTE rxdata[2048];  //���ݽ��ջ����������ڴ�Ž��ܵ�������

	COleSafeArray safearray1;

	if (comKou.get_CommEvent() == 2)  //�ж��Ƿ�Ϊ�������ݵ����¼�
	{
		input1 = comKou.get_Input(); //��ȡ��������

		safearray1 = input1;  //�������ݰ�ȫ��ת��

		long dataLength = safearray1.GetOneDimSize();  //��ȡ���ݵ��ֽڳ���

		for (long k = 0; k < dataLength; k++)  //���ζ�ȡÿһ���ֽ�
			safearray1.GetElement(&k, rxdata + k);//��һ�������ǿ�ʼ������ָ�룬�ڶ����Ǵ�ŵ�����ָ��
	}
	//if (rxdata[0] == 0x01)//0x01������һҳ��
	// MessageBox(_T("���ѿ�"));
	//	OnBnClickedpremoive();
	//else if (rxdata[0] == 0x02)//0x02��ʾ��һҳ��
	// MessageBox(_T("���ѹ�"));
	//OnBnClickednextmoive();
	switch (rxdata[0])
	{
	case 0: break;
	case 1: str[xuanWei][changCi][0] = '1'; save(); load(); break;
	case 2: str[xuanWei][changCi][1] = '1'; save(); load(); break;
	case 3: str[xuanWei][changCi][2] = '1'; save(); load(); break;
	case 4: str[xuanWei][changCi][3] = '1'; save(); load(); break;
	case 5: str[xuanWei][changCi][4] = '1'; save(); load(); break;
	case 6: str[xuanWei][changCi][5] = '1'; save(); load();  break;
	case 7: str[xuanWei][changCi][6] = '1'; save(); load();  break;
	case 8: str[xuanWei][changCi][7] = '1'; save(); load(); break;
	case 9: str[xuanWei][changCi][8] = '1'; save(); load();  break;
	case 10: str[xuanWei][changCi][9] = '1'; save(); load(); break;
	case 11: str[xuanWei][changCi][10] = '1'; save(); load();  break;
	case 12: str[xuanWei][changCi][11] = '1'; save(); load();  break;
	case 13: str[xuanWei][changCi][12] = '1'; save(); load(); break;
	case 14: str[xuanWei][changCi][13] = '1'; save(); load();  break;
	case 15: str[xuanWei][changCi][14] = '1'; save(); load();  break;
	case 16: str[xuanWei][changCi][15] = '1'; save(); load(); break;
	default: MessageBox(_T("���յ��쳣����")); break;
	}
}
void init()
{
	int i, j, k;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			for (k = 0; k<16; k++)
			{
				//���ַ�0�������ݡ�
				str[i][j][k] = '0';
			}
		}
	}
	save();

}

// ****************************************************************
// �����ļ����ݵ��ڴ�
//*****************************************************************
void load()
{
	int i, j;
	FILE *fp = fopen(fileDizhi, "r");
	if (!fp)
	{
		init();
		fp = fopen(fileDizhi, "r");
	}

	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			//ÿ16���ַ�һ��������һ���س��ṩ�����ȷ�ϡ�
			fscanf(fp, "%s", str[i][j]);
		}
	}
	fclose(fp);
}

// ****************************************************************
// �����е�����д���ļ���������������κ�һ���ڴ����ݸ���ʱȥ���á�
// ****************************************************************
void save()
{
	int i, j, k;
	FILE *fp = fopen(fileDizhi, "w");
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			for (k = 0; k<16; k++)
			{
				fprintf(fp, "%c", str[i][j][k]);
			}
			// д��һ���س����е���Ϊ��load����ִ��ʱÿ16���ַ�����ͨ��%s�ķ�ʽ�����ڴ档
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}


BEGIN_MESSAGE_MAP(��λ����ҳ, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &��λ����ҳ::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &��λ����ҳ::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &��λ����ҳ::OnBnClickedButton4)
END_MESSAGE_MAP()


void ��λ����ҳ::OnBnClickedButton1()
{	
	
	int k;
	for (k = 0; k < 16; k++)
	{
		if (str[xuanWei][changCi][k] == '0')
			;
		else
		{
			//���������ʾ��λ����䡣
		}
		
	}
	UpdateData(FALSE);
}


void ��λ����ҳ::OnBnClickedButton5()//tui
{
	UpdateData(TRUE);
	str[xuanWei][changCi][xuanWei] = '2';
	OnBnClickedButton1();
}


void ��λ����ҳ::OnBnClickedButton4()//ding
{
	UpdateData(TRUE);
	str[xuanWei][changCi][xuanWei] = '1';
	OnBnClickedButton1();
}
