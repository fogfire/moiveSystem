// 后台.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "后台.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)
char str1[3][5][16];
void init1();
void load1();
void save1();
char fileDizhi1[20];
int a=-1, b, c;
// 后台 对话框
IMPLEMENT_DYNAMIC(后台, CDialogEx)

后台::后台(CWnd* pParent /*=NULL*/)
	: CDialogEx(后台::IDD, pParent)
	, tuipiao(_T(""))
	, 电影场次(0)
{

}

后台::~后台()
{
}

void 后台::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, tuipiao);
	DDX_CBIndex(pDX, IDC_COMBO1, 电影场次);
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
				//用字符0清零数据。
				str1[i][j][k] = '0';
			}
		}
	}
	save1();

}

// ****************************************************************
// 加载文件数据到内存
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
			//每16个字符一组正好有一个回车提供输入的确认。
			fscanf(fp, "%s", str1[i][j]);
		}
	}
	fclose(fp);
}

// ****************************************************************
// 将所有的数据写入文件，这个操作将在任何一个内存数据更新时去调用。
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
			// 写入一个回车换行的是为了load函数执行时每16个字符可以通过%s的方式读入内存。
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}


BEGIN_MESSAGE_MAP(后台, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &后台::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &后台::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &后台::OnBnClickedButton3)
END_MESSAGE_MAP()


// 后台 消息处理程序


void 后台::OnBnClickedButton1()//同意
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
	if (电影场次 == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (电影场次 == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (电影场次 == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	save1();
	OnBnClickedButton3();
}


void 后台::OnBnClickedButton2()//拒绝
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
	if (电影场次 == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (电影场次 == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (电影场次 == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	save1();
	OnBnClickedButton3();
}


void 后台::OnBnClickedButton3()//刷新
{
	int i, j, k;
	UpdateData(TRUE);
	if (电影场次 == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (电影场次 == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (电影场次 == 2)
	{
		strcpy(fileDizhi1, "res\\mv3.ini");
	}
	load1();
	if (电影场次 == 0)
	{
		strcpy(fileDizhi1, "res\\mv1.ini");
	}
	if (电影场次 == 1)
	{
		strcpy(fileDizhi1, "res\\mv2.ini");
	}
	if (电影场次 == 2)
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
					case 0:tuipiao = "1-1厅"; break;
					case 1:tuipiao = "1-2厅"; break;
					case 2:tuipiao = "1-3厅"; break;
					default:
						break;
					}
					switch (j)
					{
					case 0:tuipiao += "9:00第"; break;
					case 1:tuipiao += "11:15第"; break;
					case 2:tuipiao += "14:00第"; break;
					case 3:tuipiao += "16:15第"; break;
					case 4:tuipiao += "20:00第"; break;
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
					tuipiao += "号";
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
		tuipiao = "无退票请求。";
	UpdateData(FALSE);
}
