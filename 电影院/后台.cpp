// 后台.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "后台.h"
#include "afxdialogex.h"
char str[3][5][16];
void init();
void load();
void save();
char fileDizhi[20];
// 后台 对话框

IMPLEMENT_DYNAMIC(后台, CDialogEx)

后台::后台(CWnd* pParent /*=NULL*/)
	: CDialogEx(后台::IDD, pParent)
	, tuipiao(_T(""))
{

}

后台::~后台()
{
}

void 后台::DoDataExchange(CDataExchange* pDX)
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
				//用字符0清零数据。
				str[i][j][k] = '0';
			}
		}
	}
	save();

}

// ****************************************************************
// 加载文件数据到内存
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
			//每16个字符一组正好有一个回车提供输入的确认。
			fscanf(fp, "%s", str[i][j]);
		}
	}
	fclose(fp);
}

// ****************************************************************
// 将所有的数据写入文件，这个操作将在任何一个内存数据更新时去调用。
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
	
}


void 后台::OnBnClickedButton2()//拒绝
{
	
}


void 后台::OnBnClickedButton3()//刷新
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
					default: tuipiao = "数据异常"; break;
					}
					
					break;
				}
			}
		}
	}
}
