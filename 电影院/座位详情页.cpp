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
char str[7][7][16];

// ��λ����ҳ �Ի���

IMPLEMENT_DYNAMIC(��λ����ҳ, CDialogEx)

��λ����ҳ::��λ����ҳ(CWnd* pParent /*=NULL*/)
	: CDialogEx(��λ����ҳ::IDD, pParent)
	, diDian(0)
	, xuanWei(0)
	, changCi(0)
{

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
	case 1: str[xuanWei][changCi - 1][0] = '1'; save(); load(); break;
	case 2: str[xuanWei][changCi - 1][1] = '1'; save(); load(); break;
	case 3: str[xuanWei][changCi - 1][2] = '1'; save(); load(); break;
	case 4: str[xuanWei][changCi - 1][3] = '1'; save(); load(); break;
	case 5: str[xuanWei][changCi - 1][4] = '1'; save(); load(); break;
	case 6: str[xuanWei][changCi - 1][5] = '1'; save(); load();  break;
	case 7: str[xuanWei][changCi - 1][6] = '1'; save(); load();  break;
	case 8: str[xuanWei][changCi - 1][7] = '1'; save(); load(); break;
	case 9: str[xuanWei][changCi - 1][8] = '1'; save(); load();  break;
	case 10: str[xuanWei - 1][changCi - 1][9] = '1'; save(); load(); break;
	case 11: str[xuanWei - 1][changCi - 1][10] = '1'; save(); load();  break;
	case 12: str[xuanWei - 1][changCi - 1][11] = '1'; save(); load();  break;
	case 13: str[xuanWei - 1][changCi - 1][12] = '1'; save(); load(); break;
	case 14: str[xuanWei - 1][changCi - 1][13] = '1'; save(); load();  break;
	case 15: str[xuanWei - 1][changCi - 1][14] = '1'; save(); load();  break;
	case 16: str[xuanWei - 1][changCi - 1][15] = '1'; save(); load(); break;
	case 17: break;
	case 18: break;
	case 19: break;
	case 20: break;
	default: break;
	}
}
void init()
{
	int i, j, k;
	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
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
	FILE *fp = fopen("test.txt", "r");
	if (!fp)
	{
		init();
		fp = fopen("test.txt", "r");
	}

	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
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
	FILE *fp = fopen("test.txt", "w");
	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
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


