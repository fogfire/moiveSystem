// 座位详情页.cpp : 实现文件
//

#include "stdafx.h"
#include "电影院.h"
#include "座位详情页.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)
void init();
void load();
void save();
char str[3][5][16];
char fileDizhi[20];
// 座位详情页 对话框

IMPLEMENT_DYNAMIC(座位详情页, CDialogEx)

座位详情页::座位详情页(CWnd* pParent /*=NULL*/)
	: CDialogEx(座位详情页::IDD, pParent)
	, diDian(0)
	, xuanWei(0)
	, changCi(0)
{
}

座位详情页::座位详情页(int a)
: CDialogEx(座位详情页::IDD, NULL)
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
座位详情页::~座位详情页()
{
}

void 座位详情页::DoDataExchange(CDataExchange* pDX)
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




// 座位详情页 消息处理程序
BEGIN_EVENTSINK_MAP(座位详情页, CDialogEx)
	ON_EVENT(座位详情页, IDC_MSCOMM1, 1, 座位详情页::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void 座位详情页::OnCommMscomm1()
{
	VARIANT input1;

	BYTE rxdata[2048];  //数据接收缓冲区，用于存放接受到的数据

	COleSafeArray safearray1;

	if (comKou.get_CommEvent() == 2)  //判断是否为串口数据到达事件
	{
		input1 = comKou.get_Input(); //读取串口内容

		safearray1 = input1;  //进行数据安全性转换

		long dataLength = safearray1.GetOneDimSize();  //读取数据的字节长度

		for (long k = 0; k < dataLength; k++)  //依次读取每一个字节
			safearray1.GetElement(&k, rxdata + k);//第一个参数是开始的数组指针，第二个是存放的数组指针
	}
	//if (rxdata[0] == 0x01)//0x01就是上一页。
	// MessageBox(_T("灯已开"));
	//	OnBnClickedpremoive();
	//else if (rxdata[0] == 0x02)//0x02表示下一页。
	// MessageBox(_T("灯已关"));
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
	default: MessageBox(_T("接收到异常数据")); break;
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


BEGIN_MESSAGE_MAP(座位详情页, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &座位详情页::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &座位详情页::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &座位详情页::OnBnClickedButton4)
END_MESSAGE_MAP()


void 座位详情页::OnBnClickedButton1()
{	
	
	int k;
	for (k = 0; k < 16; k++)
	{
		if (str[xuanWei][changCi][k] == '0')
			;
		else
		{
			//这里添加显示座位的语句。
		}
		
	}
	UpdateData(FALSE);
}


void 座位详情页::OnBnClickedButton5()//tui
{
	UpdateData(TRUE);
	str[xuanWei][changCi][xuanWei] = '2';
	OnBnClickedButton1();
}


void 座位详情页::OnBnClickedButton4()//ding
{
	UpdateData(TRUE);
	str[xuanWei][changCi][xuanWei] = '1';
	OnBnClickedButton1();
}
