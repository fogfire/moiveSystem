
// ��ӰԺDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ӰԺ.h"
#include "��ӰԺDlg.h"
#include "afxdialogex.h"
#include "����ҳ.h"
#include "���ҳ.h"
#include"about.h"
bool isTrue;
int x;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
/*

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButton1();
	//afx_msg void OnBnClickedgo();
	afx_msg void OnBnClickedgo();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

*/


// C��ӰԺDlg �Ի���



C��ӰԺDlg::C��ӰԺDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��ӰԺDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ӰԺDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, btnManage);
	DDX_Control(pDX, IDC_BUTTON2, btnLiulan);
}

BEGIN_MESSAGE_MAP(C��ӰԺDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��ӰԺDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ӰԺDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_btnOut, &C��ӰԺDlg::OnBnClickedbtnout)
	ON_BN_CLICKED(IDC_BUTTON3, &C��ӰԺDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// C��ӰԺDlg ��Ϣ�������

BOOL C��ӰԺDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��ӰԺDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		about dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��ӰԺDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��ӰԺDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C��ӰԺDlg::OnBnClickedButton1()//����ť
{
	����ҳ manage;
	this->ShowWindow(SW_HIDE);
	int managef=manage.DoModal();
	this->ShowWindow(SW_SHOW);
/*	if (managef == IDOK)
	{
		isTrue = TRUE;
	}
	else
	{
		isTrue = FALSE;
	}
	
	if (isTrue)
	{
		this->btnLiulan.DestroyWindow();
		delete btnLiulan;
		btnManage.DestroyWindow();
		delete btnManage;
	}
	*/
}


void C��ӰԺDlg::OnBnClickedButton2()//���ҳ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	���ҳ view;
	this->ShowWindow(SW_HIDE);
	view.DoModal();
	this->ShowWindow(SW_SHOW);
	
}

void C��ӰԺDlg::OnBnClickedbtnout()
{
	exit(0);
}

void C��ӰԺDlg::OnBnClickedButton3()
{
	about ����;
	this->ShowWindow(SW_HIDE);
	����.DoModal();
	this->ShowWindow(SW_SHOW);
}
