
// ReplaceFileNameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ReplaceFileName.h"
#include "ReplaceFileNameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CReplaceFileNameDlg 对话框




CReplaceFileNameDlg::CReplaceFileNameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CReplaceFileNameDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReplaceFileNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CReplaceFileNameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CReplaceFileNameDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_DEST, &CReplaceFileNameDlg::OnBnClickedButtonDest)
	ON_BN_CLICKED(IDOK, &CReplaceFileNameDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CReplaceFileNameDlg 消息处理程序

BOOL CReplaceFileNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CReplaceFileNameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CReplaceFileNameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CReplaceFileNameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReplaceFileNameDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	char szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName= szDir;
	bi.lpszTitle = "请选择目录";
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;

	pidl = SHBrowseForFolder(&bi);
	if(pidl == NULL)
		return;
	if(!SHGetPathFromIDList(pidl, szDir)) 
		return;

	GetDlgItem(IDC_SOURCR_EDIT)->SetWindowTextA(szDir);
	
}


void CReplaceFileNameDlg::OnBnClickedButtonDest()
{
	// TODO: 在此添加控件通知处理程序代码
	char szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName= szDir;
	bi.lpszTitle = "请选择目录";
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;

	pidl = SHBrowseForFolder(&bi);
	if(pidl == NULL)
		return;
	if(!SHGetPathFromIDList(pidl, szDir)) 
		return;

	GetDlgItem(IDC_DEST_EDIT)->SetWindowTextA(szDir);
}


void CReplaceFileNameDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSourText;
	CString strDestText;
	GetDlgItem(IDC_EDIT_SOUTEX)->GetWindowText(strSourText);
	GetDlgItem(IDC_EDIT_DESTEXT)->GetWindowText(strDestText);
	if (strDestText.IsEmpty() || strSourText.IsEmpty())
	{
		MessageBoxA("请输入内容");
		return;
	}

	CString strDir;
	CString strDirCpy;
	GetDlgItem(IDC_SOURCR_EDIT)->GetWindowText(strDir);
	strDirCpy = strDir;
	strDir.Append("\\*.*");
	

	CString strDestDir;
	CString strDestCpy;
	GetDlgItem(IDC_DEST_EDIT)->GetWindowText(strDestDir);
	if (strDestDir.IsEmpty())
	{
		strDestCpy = strDirCpy;
		strDestDir.Append("\\*.*");
	}
	else
	{
		strDestCpy = strDestDir;
		strDestDir.Append("\\*.*");
	}

	CFileFind tempFind;
	BOOL IsFind = tempFind.FindFile(strDir);
	CString strOrigName;
	CString strDestName;
	while(IsFind)
	{
		IsFind = tempFind.FindNextFileA();
		if (!tempFind.IsDots())
		{
			strOrigName = tempFind.GetFileName();
			if (-1 != strOrigName.Find(strSourText))
			{
				strDestName = strOrigName;
				strDestName.Replace(strSourText, strDestText);
				//rename(strDir+strOrigName, strDir+strDestName);
				CString tempSource;
				CString tempDest;
				tempSource.Format("%s\\%s", strDirCpy, strOrigName);
				tempDest.Format("%s\\%s", strDestCpy, strDestName);
				int iRet = rename(tempSource, tempDest);
				CString tempInfo;
				tempInfo.Format("%d", iRet);
				OutputDebugStringA(tempInfo);
			}
		}
	}
	MessageBoxA("文件名替换完毕");
}
