// ��̨.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "��̨.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)
char str1[3][5][16];
void init1();
void load1();
void save1();
char fileDizhi1[20];
// ��̨ �Ի���
IMPLEMENT_DYNAMIC(��̨, CDialogEx)

��̨::��̨(CWnd* pParent /*=NULL*/)
	: CDialogEx(��̨::IDD, pParent)
	, tuipiao(_T(""))
	, ��Ӱ����(0)
{

}

��̨::~��̨()
{
}

void ��̨::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, tuipiao);
	DDX_CBIndex(pDX, IDC_COMBO1, ��Ӱ����);
}



void init1()
{
	int i, j, k;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			for (k = 0; k<16; k++)
			{
				//���ַ�0�������ݡ�
				str1[i][j][k] = '0';
			}
		}
	}
	save1();

}

// ****************************************************************
// �����ļ����ݵ��ڴ�
//*****************************************************************
void load1()
{
	int i, j;
	FILE *fp = fopen(fileDizhi1, "r");
	if (!fp)
	{
		init1();
		fp = fopen(fileDizhi1, "r");
	}

	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			//ÿ16���ַ�һ��������һ���س��ṩ�����ȷ�ϡ�
			fscanf(fp, "%s", str1[i][j]);
		}
	}
	fclose(fp);
}

// ****************************************************************
// �����е�����д���ļ���������������κ�һ���ڴ����ݸ���ʱȥ���á�
// ****************************************************************
void save1()
{
	int i, j, k;
	FILE *fp = fopen(fileDizhi1, "w");
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			for (k = 0; k<16; k++)
			{
				fprintf(fp, "%c", str1[i][j][k]);
			}
			// д��һ���س����е���Ϊ��load����ִ��ʱÿ16���ַ�����ͨ��%s�ķ�ʽ�����ڴ档
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}


BEGIN_MESSAGE_MAP(��̨, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &��̨::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &��̨::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &��̨::OnBnClickedButton3)
END_MESSAGE_MAP()


// ��̨ ��Ϣ�������


void ��̨::OnBnClickedButton1()//ͬ��
{
	
}


void ��̨::OnBnClickedButton2()//�ܾ�
{
	
}


void ��̨::OnBnClickedButton3()//ˢ��
{
	int i, j, k;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 16; k++)
			{
				if (str1[i][j][k] == '2')
				{
					int y=5;
					switch (y)
					{
					case 1: tuipiao += "��Ӱ1"; break;
					case 2: tuipiao += "��Ӱ2"; break;
					case 3: tuipiao += "��Ӱ3"; break;
					default: tuipiao = "�����쳣"; break;
					}
					break;
				}
			}
		}
	}
}
