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
int a=-1, b, c;
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
	if (a == -1)
	{
		;
	}
	else
	{
		str1[a][b][c] = 'k';
	}
	a = -1;
	if (��Ӱ���� == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (��Ӱ���� == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (��Ӱ���� == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	save1();
	OnBnClickedButton3();
}


void ��̨::OnBnClickedButton2()//�ܾ�
{
	if (a == -1)
	{
		;
	}
	else
	{
		str1[a][b][c] = '1';
	}
	a = -1;
	if (��Ӱ���� == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (��Ӱ���� == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (��Ӱ���� == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	save1();
	OnBnClickedButton3();
}


void ��̨::OnBnClickedButton3()//ˢ��
{
	int i, j, k;
	UpdateData(TRUE);
	if (��Ӱ���� == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (��Ӱ���� == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (��Ӱ���� == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	load1();
	if (��Ӱ���� == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (��Ӱ���� == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (��Ӱ���� == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 16; k++)
			{
				if (str1[i][j][k] == 't')
				{
					switch (i)
					{
					case 0:tuipiao = "1-1��"; break;
					case 1:tuipiao = "1-2��"; break;
					case 2:tuipiao = "1-3��"; break;
					default:
						break;
					}
					switch (j)
					{
					case 0:tuipiao += "9:00��"; break;
					case 1:tuipiao += "11:15��"; break;
					case 2:tuipiao += "14:00��"; break;
					case 3:tuipiao += "16:15��"; break;
					case 4:tuipiao += "20:00��"; break;
					default:
						break;
					}
					switch (k)
					{
					case 0: tuipiao += "1"; break;
					case 1: tuipiao += "2"; break;
					case 2: tuipiao += "3"; break;
					case 3: tuipiao += "4"; break;
					case 4: tuipiao += "5"; break;
					case 5: tuipiao += "6"; break;
					case 6: tuipiao += "7"; break;
					case 7: tuipiao += "8"; break;
					case 8: tuipiao += "9"; break;
					case 9: tuipiao += "10"; break;
					case 10: tuipiao += "11"; break;
					case 11: tuipiao += "12"; break;
					case 12: tuipiao += "13"; break;
					case 13: tuipiao += "14"; break;
					case 14: tuipiao += "15"; break;
					case 15: tuipiao += "16"; break;
					default:
						break;
					}
					tuipiao += "��";
					a = i;
					b = j;
					c = k;
					
					k = 16;
					j = 5;
					i = 20;
					
				}
			}
		}
	}
	if (i != 21)
		tuipiao = "����Ʊ����";
	UpdateData(FALSE);
}
