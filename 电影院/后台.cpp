// ��̨.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "��̨.h"
#include "afxdialogex.h"
char str[3][5][16];
void init();
void load();
void save();
char fileDizhi[20];
// ��̨ �Ի���

IMPLEMENT_DYNAMIC(��̨, CDialogEx)

��̨::��̨(CWnd* pParent /*=NULL*/)
	: CDialogEx(��̨::IDD, pParent)
	, tuipiao(_T(""))
{

}

��̨::~��̨()
{
}

void ��̨::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, tuipiao);
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
				if (str[i][j][k] == '2')
				{
					switch ()
					{
					case 1: tuipiao += "1"; break;
					case 2: tuipiao += "2"; break;
					case 3: tuipiao += "3"; break;
					default: tuipiao = "�����쳣"; break;
					}
					
					break;
				}
			}
		}
	}
}
