
// ReplaceFileNameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReplaceFileName.h"
#include "ReplaceFileNameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

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


// CReplaceFileNameDlg �Ի���




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


// CReplaceFileNameDlg ��Ϣ�������

BOOL CReplaceFileNameDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CReplaceFileNameDlg::OnPaint()
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
HCURSOR CReplaceFileNameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReplaceFileNameDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	char szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName= szDir;
	bi.lpszTitle = "��ѡ��Ŀ¼";
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName= szDir;
	bi.lpszTitle = "��ѡ��Ŀ¼";
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strSourText;
	CString strDestText;
	GetDlgItem(IDC_EDIT_SOUTEX)->GetWindowText(strSourText);
	GetDlgItem(IDC_EDIT_DESTEXT)->GetWindowText(strDestText);
	if (strDestText.IsEmpty() || strSourText.IsEmpty())
	{
		MessageBoxA("����������");
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
	MessageBoxA("�ļ����滻���");
}
