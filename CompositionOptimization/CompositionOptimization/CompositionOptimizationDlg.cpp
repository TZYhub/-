
// CompositionOptimizationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CompositionOptimization.h"
#include "CompositionOptimizationDlg.h"
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


// CCompositionOptimizationDlg �Ի���




CCompositionOptimizationDlg::CCompositionOptimizationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCompositionOptimizationDlg::IDD, pParent)
	,m_bIsFirstInit(true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCompositionOptimizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COMPOSITION, m_CompositionList);
	DDX_Control(pDX, IDC_LIST_NATURE, m_NatureList);
	DDX_Control(pDX, IDC_EDIT1, m_inputComEdit);
	DDX_Control(pDX, IDC_EDIT2, m_inputNatureEdit);
	DDX_Control(pDX, IDC_LIST_RESULT, m_ResultList);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_LIST_CALCRATIO, m_CalcRatioList);
	DDX_Control(pDX, IDC_EDIT_CALCRTIO, m_calcRatioEdit);
}

BEGIN_MESSAGE_MAP(CCompositionOptimizationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_COMPOSITION, &CCompositionOptimizationDlg::OnNMDblclkListComposition)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_NATURE, &CCompositionOptimizationDlg::OnNMDblclkListNature)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CCompositionOptimizationDlg::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, &CCompositionOptimizationDlg::OnEnKillfocusEdit2)
	ON_BN_CLICKED(IDC_BTN_STARTOPT, &CCompositionOptimizationDlg::OnBnClickedBtnStartopt)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CCompositionOptimizationDlg::OnCbnKillfocusCombo1)
	ON_NOTIFY(NM_CLICK, IDC_LIST_NATURE, &CCompositionOptimizationDlg::OnNMClickListNature)
	ON_BN_CLICKED(IDC_BTN_TEST, &CCompositionOptimizationDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CCompositionOptimizationDlg::OnBnClickedBtnClear)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_COMPOSITION, &CCompositionOptimizationDlg::OnNMRClickListComposition)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_NATURE, &CCompositionOptimizationDlg::OnNMRClickListNature)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CALCRATIO, &CCompositionOptimizationDlg::OnNMDblclkListCalcratio)
	ON_EN_KILLFOCUS(IDC_EDIT_CALCRTIO, &CCompositionOptimizationDlg::OnEnKillfocusEditCalcrtio)
	ON_COMMAND_RANGE(ID_COMPO_START,ID_COMPO_END,&CCompositionOptimizationDlg::OnAddComposition)
	ON_COMMAND_RANGE(ID_NATURE_START,ID_NATURE_END,&CCompositionOptimizationDlg::OnAddNature)
END_MESSAGE_MAP()


// CCompositionOptimizationDlg ��Ϣ�������

BOOL CCompositionOptimizationDlg::OnInitDialog()
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
	//��ʼ��
	Init();
	InitMenu();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CCompositionOptimizationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCompositionOptimizationDlg::OnPaint()
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
HCURSOR CCompositionOptimizationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCompositionOptimizationDlg::Init()
{	
	InitCompositionList();
	InitNatureList();
	InitResultList();
	InitCombo();
	InitCalcRatioList();
	LoadCalcRatio();
	
}


void CCompositionOptimizationDlg::LoadComposition()
{
	//str���Դ���һ���б���Ǳ༭���л�û������ļ���
	CString str=_T("SiO2");
	m_vtComposition.push_back(str);
	str=_T("Al2O3");
	m_vtComposition.push_back(str);
	str=_T("CaO");
	m_vtComposition.push_back(str);
	str=_T("Na2O");
	m_vtComposition.push_back(str);

	m_compositionNumber=m_vtComposition.size();
}


void CCompositionOptimizationDlg::LoadNature()
{
	CString str;
	str="����ϵ��";
	m_vtNature.push_back(str);
	str="������";
	m_vtNature.push_back(str);

	m_natureNumber=m_vtNature.size();
}


void CCompositionOptimizationDlg::LoadResult()
{

}


void CCompositionOptimizationDlg::LoadCalcRatio()
{
	map<CString,float> m_map;
	m_map.insert(make_pair("����ϵ��",(float)35.0));
	m_map.insert(make_pair("������",(float)1.46));
	m_mapAllNature.insert(make_pair(0,m_map));
	m_map.clear();

	m_map.insert(make_pair("����ϵ��",(float)-40.0));
	m_map.insert(make_pair("������",(float)1.52));
	m_mapAllNature.insert(make_pair(1,m_map));
	m_map.clear();

	m_map.insert(make_pair("����ϵ��",(float)130.0));
	m_map.insert(make_pair("������",(float)1.73));
	m_mapAllNature.insert(make_pair(2,m_map));
	m_map.clear();

	m_map.insert(make_pair("����ϵ��",(float)300.0));
	m_map.insert(make_pair("������",(float)1.59));
	m_mapAllNature.insert(make_pair(3,m_map));
	m_map.clear();

	m_CalcRatioList.SetItemText(0,1,_T("35.0"));
	m_CalcRatioList.SetItemText(0,2,_T("-40.0"));
	m_CalcRatioList.SetItemText(0,3,_T("130"));
	m_CalcRatioList.SetItemText(0,4,_T("300.0"));
	m_CalcRatioList.SetItemText(1,1,_T("1.46"));
	m_CalcRatioList.SetItemText(1,2,_T("1.52"));
	m_CalcRatioList.SetItemText(1,3,_T("1.73"));
	m_CalcRatioList.SetItemText(1,4,_T("1.59"));
	
}


void CCompositionOptimizationDlg::InitCompositionList()
{
	//��ɾ�������к������У��ټ���
	m_CompositionList.DeleteAllItems();
	int nColumnCount = m_CompositionList.GetHeaderCtrl()->GetItemCount();
	// Delete all of the columns.
	for (int i=0;i < nColumnCount;i++)
	{
		m_CompositionList.DeleteColumn(0);
	}


	LONG lStyle;
	lStyle = GetWindowLong(m_CompositionList.m_hWnd, GWL_STYLE);//��ȡ��ǰ����style
	lStyle |= LVS_REPORT;										//����style
	DWORD dwStyle = m_CompositionList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;							// ѡ��ĳ��ʹ���и�����ֻ������report ����listctrl ��   
	dwStyle |= LVS_EX_GRIDLINES;								// �����ߣ�ֻ������report ����listctrl ��      
	m_CompositionList.SetExtendedStyle(dwStyle);				// ������չ��� 

	m_CompositionList.InsertColumn(0, _T("���"), LVCFMT_CENTER, 40); 
	m_CompositionList.InsertColumn(1, _T("���"), LVCFMT_CENTER, 60); 
	m_CompositionList.InsertColumn(2, _T("��ɷ�Χ"), LVCFMT_CENTER, 60); 
	m_CompositionList.InsertColumn(3,_T("��ȡֵ"),LVCFMT_LEFT,240); 
	//�Զ�������ȡ���
	AutoSizeListColumn(m_CompositionList,3);
	
	//��һ�������ﵼ����Ҫ������������
	if (!m_vtComposition.empty())//������
	{
		vector<CString>::iterator it=m_vtComposition.begin();
		vector<CString>::iterator itEnd=m_vtComposition.end();
		int pos=1;
		CString str;
		for (;it!=itEnd;++it,++pos)
		{
			str.Format(_T("%d"),pos);
			m_CompositionList.InsertItem(pos,str);
			m_CompositionList.SetItemText(pos-1,1,*it);
		}
	}
	m_compositionNumber=m_vtComposition.size();
}


void CCompositionOptimizationDlg::InitNatureList()
{
	//��ɾ�������к������У��ټ���
	m_NatureList.DeleteAllItems();
	int nColumnCount = m_CompositionList.GetHeaderCtrl()->GetItemCount();
	// Delete all of the columns.
	for (int i=0;i < nColumnCount;i++)
	{
		m_NatureList.DeleteColumn(0);
	}

	LONG lStyle;
	lStyle = GetWindowLong(m_NatureList.m_hWnd, GWL_STYLE);	//��ȡ��ǰ����style
	lStyle |= LVS_REPORT;									//����style
	DWORD dwStyle = m_NatureList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;						// ѡ��ĳ��ʹ���и�����ֻ������report ����listctrl ��   
	dwStyle |= LVS_EX_GRIDLINES;							// �����ߣ�ֻ������report ����listctrl ��      
	m_NatureList.SetExtendedStyle(dwStyle);					// ������չ��� 


	m_NatureList.InsertColumn(0, _T("���"), LVCFMT_CENTER, 40); 
	m_NatureList.InsertColumn(1, _T("��    ��"), LVCFMT_CENTER, 60); 
	m_NatureList.InsertColumn(2,_T("���ʷ�Χ"),LVCFMT_CENTER,80);
	m_NatureList.InsertColumn(3,_T("ȡ��/Сֵ"),LVCFMT_CENTER,80);

	//��һ�������ﵼ����Ҫ������������
	if (!m_vtNature.empty())//������
	{
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		int pos=1;
		CString str;
		for (;it!=itEnd;++it,++pos)
		{
			str.Format(_T("%d"),pos);
			m_NatureList.InsertItem(pos, str); 
			m_NatureList.SetItemText(pos-1,1, *it); 
		}
	}

	m_natureNumber=m_vtNature.size();
}


void CCompositionOptimizationDlg::InitResultList()
{
	m_ResultList.DeleteAllItems();
	int nColumnCount = m_ResultList.GetHeaderCtrl()->GetItemCount();
	for (int i=0;i < nColumnCount;i++)
	{
		m_ResultList.DeleteColumn(0);
	}
	LONG lStyle;
	lStyle = GetWindowLong(m_ResultList.m_hWnd, GWL_STYLE);	//��ȡ��ǰ����style
	lStyle |= LVS_REPORT;									//����style
	DWORD dwStyle = m_ResultList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;						// ѡ��ĳ��ʹ���и�����ֻ������report ����listctrl ��   
	dwStyle |= LVS_EX_GRIDLINES;							// �����ߣ�ֻ������report ����listctrl ��      
	m_ResultList.SetExtendedStyle(dwStyle);					// ������չ��� 
	m_ResultList.InsertColumn(0, _T("��ּ�����"), LVCFMT_CENTER, 80); 

	int pos=1;
	if (!m_vtComposition.empty())//������
	{
		vector<CString>::iterator it=m_vtComposition.begin();
		vector<CString>::iterator itEnd=m_vtComposition.end();
		
		for (;it!=itEnd;++it,++pos)
		{
			m_ResultList.InsertColumn(pos, *it, LVCFMT_CENTER, 80);
		}
	}

	if (!m_vtNature.empty())//������
	{
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		for (;it!=itEnd;++it,++pos)
		{
			m_ResultList.InsertColumn(pos, *it, LVCFMT_CENTER, 80); 
		}
	}

	m_ResultList.InsertItem(1,_T("��ѡ���"));

}


void CCompositionOptimizationDlg::InitCombo()
{
	if (m_bIsFirstInit)
	{
		m_combo.AddString(_T("ȡ��ֵ"));
		m_combo.AddString(_T("ȡСֵ"));
		m_combo.SetCurSel(0);
		m_bIsFirstInit=false;
	}
	
}


void CCompositionOptimizationDlg::InitCalcRatioList()
{
	//ɾ���к���
	m_CalcRatioList.DeleteAllItems();
	int nColumnCount = m_CalcRatioList.GetHeaderCtrl()->GetItemCount();
	for (int i=0;i < nColumnCount;i++)
	{
		m_CalcRatioList.DeleteColumn(0);
	}

	LONG lStyle;
	lStyle = GetWindowLong(m_CalcRatioList.m_hWnd, GWL_STYLE);	//��ȡ��ǰ����style
	lStyle |= LVS_REPORT;									//����style
	DWORD dwStyle = m_CalcRatioList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;						// ѡ��ĳ��ʹ���и�����ֻ������report ����listctrl ��   
	dwStyle |= LVS_EX_GRIDLINES;							// �����ߣ�ֻ������report ����listctrl ��      
	m_CalcRatioList.SetExtendedStyle(dwStyle);					// ������չ��� 
	m_CalcRatioList.InsertColumn(0, _T("���"), LVCFMT_CENTER, 120);
	
	int pos=1;
	if (!m_vtComposition.empty())//������
	{
		vector<CString>::iterator it=m_vtComposition.begin();
		vector<CString>::iterator itEnd=m_vtComposition.end();

		for (;it!=itEnd;++it,++pos)
		{
			m_CalcRatioList.InsertColumn(pos, *it, LVCFMT_CENTER, 80);
		}
	}

	if (!m_vtNature.empty())//������
	{
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		int pos=1;
		CString str;
		for (;it!=itEnd;++it,++pos)
		{
			str.Format(_T("%s����ϵ��"),*it);
			m_CalcRatioList.InsertItem(pos, str); 
		}
	}
	//AutoSizeListColumn(m_CalcRatioList,0);
}


void CCompositionOptimizationDlg::LoadStrFromIni(vector<CString> &vtStr,CString keyStr)
{
	CString strRead=_T("");
	CString des=_T("");
	::GetCurrentDirectory(MAX_PATH,des.GetBuffer(MAX_PATH));
	des.ReleaseBuffer();
	des+="\\config.ini";
	int nCount=GetPrivateProfileInt(keyStr,_T("nCount"),0,des);
	if (0==nCount)
	{
		MessageBox(_T("��ȡ�����ļ��е����ʧ��,���������ļ���"));
		return;
	}
	else
	{
		TCHAR ch[10];
		for (int i=1;i<=nCount;i++)
		{
			_itot_s(i,ch,_countof(ch),10);
			GetPrivateProfileString(keyStr,ch,_T(""),strRead.GetBufferSetLength(10),10,des);
			strRead.ReleaseBuffer();
			vtStr.push_back(strRead);
		}
	}
}


bool StringSort(CString str1,CString str2)
{
	return str1<str2;
}


void CCompositionOptimizationDlg::InitMenu()
{
	//1.�������ļ��л�ȡ��ɵ���������
	vector<CString> vtCString;
	LoadStrFromIni(vtCString,_T("���"));
	//2.����ɽ�������
	sort(vtCString.begin(),vtCString.end(),StringSort);
	int m_cNumber=vtCString.size();

	//3.��ɲ˵���ʼ��
	int comID=ID_COMPO_START;
	m_CompositionMenu.CreatePopupMenu();
	
	CMenu MyMenuTemp;
	MyMenuTemp.CreateMenu();

	for (int i=0;i<m_cNumber;i++)
	{
		CMenu subMenu;
		subMenu.CreateMenu();
		CString theLetter=vtCString.at(i).Left(1);
		do 
		{
			subMenu.AppendMenu(MF_STRING,comID++,vtCString.at(i));//������ �� SiO2 Al2O3����
			i++;
			if (i>=m_cNumber)
			{
				break;
			}
		} while ((theLetter==vtCString.at(i).Left(1)));
		i--;
		MyMenuTemp.AppendMenu(MF_POPUP,(UINT)subMenu.m_hMenu,theLetter);//����Ӳ˵�����A B C����
		subMenu.Detach();
	}
	m_CompositionMenu.AppendMenu(MF_POPUP,(UINT)MyMenuTemp.m_hMenu, _T("������"));
	MyMenuTemp.Detach();
	m_DeleteCompID=comID;
	m_CompositionMenu.AppendMenu(MF_STRING,comID,_T("ɾ�����"));


	//���ʲ˵���ʼ��
	vtCString.clear();
	LoadStrFromIni(vtCString,_T("����"));
	sort(vtCString.begin(),vtCString.end(),StringSort);
	int m_nNumber=vtCString.size();
	
	int NatureID=ID_NATURE_START;

	m_NatureMenu.CreatePopupMenu();
	CMenu MyMenuTemp1;
	MyMenuTemp1.CreateMenu();

	for (int i=0;i<m_nNumber;i++)
	{
		CMenu subMenu1;
		subMenu1.CreateMenu();
		CString theLetter=vtCString.at(i).Left(1);
		do 
		{
			subMenu1.AppendMenu(MF_STRING,NatureID++,vtCString.at(i));//
			i++;
			if (i>=m_nNumber)
			{
				break;
			}
		} while ((theLetter==vtCString.at(i).Left(1)));
		i--;
		MyMenuTemp1.AppendMenu(MF_POPUP,(UINT)subMenu1.m_hMenu,theLetter);//����Ӳ˵���
		subMenu1.Detach();
	}
	m_NatureMenu.AppendMenu(MF_POPUP,(UINT)MyMenuTemp1.m_hMenu, _T("�������"));
	MyMenuTemp1.Detach();
	m_DeleteNatureID=NatureID;
	m_NatureMenu.AppendMenu(MF_STRING,NatureID,_T("ɾ������"));

}


void CCompositionOptimizationDlg::Test()
{
	m_CompositionList.SetItemText(0,2,_T("7-8"));//
	m_CompositionList.SetItemText(1,2,_T("1-2"));//
	m_CompositionList.SetItemText(2,2,_T("3-4"));//
	m_CompositionList.SetItemText(3,2,_T("5-6"));//
	//ɸѡ�޽������
	//m_NatureList.SetItemText(0,2,_T("21-24"));//
	//m_NatureList.SetItemText(1,2,_T("0.24-0.25"));//
	//ɸѡʣһ������
	//m_NatureList.SetItemText(0,2,_T("22-23"));//
	//m_NatureList.SetItemText(1,2,_T("0.27-0.29"));//
	//ɸѡʣ��������
	m_NatureList.SetItemText(0,2,_T("21-24"));//
	m_NatureList.SetItemText(0,3,_T("ȡ��ֵ"));
	m_NatureList.SetItemText(1,2,_T("0.26-0.29"));//
	m_NatureList.SetItemText(1,3,_T("ȡСֵ"));
}


void CCompositionOptimizationDlg::Clear()
{
	m_vtComposition.clear();
	m_vtNature.clear();
	Init();
}

//�ı���ɺ�����ʱ������ϵ���б��Լ�����б�Ӧ�ø��ű�
void CCompositionOptimizationDlg::RebuildList()
{
	
	RebuildCompositionList();
	RebuildNatureList();
	//1.�������ɽ���б�
	InitResultList();
}

void CCompositionOptimizationDlg::RebuildCompositionList()
{
	//�������ӣ���ֻ�ں������һ�У������»�
	//
	if (m_compositionNumber<m_vtComposition.size())//����������
	{
		int pos=m_vtComposition.size();
		CString str;
		str.Format(_T("%d"),pos);
		m_CompositionList.InsertItem(pos,str);
		m_CompositionList.SetItemText(pos-1,1,m_vtComposition.back());

		m_CalcRatioList.InsertColumn(pos, m_vtComposition.back(), LVCFMT_CENTER, 80);
	}
	else if (m_compositionNumber>m_vtComposition.size())//������ɾ��
	{
		//��ɾ��ѡ�е���
		m_CompositionList.DeleteItem(m_row);
		m_CalcRatioList.DeleteColumn(m_row+1);
	}
	m_compositionNumber=m_vtComposition.size();//�����������С
}


void CCompositionOptimizationDlg::RebuildNatureList()
{

	if (m_natureNumber<m_vtNature.size())//����������
	{
		int pos=m_vtNature.size();
		CString str;
		str.Format(_T("%d"),pos);
		m_NatureList.InsertItem(pos, str); 
		m_NatureList.SetItemText(pos-1,1, m_vtNature.back()); 

		str.Format(_T("%s����ϵ��"),m_vtNature.back());
		m_CalcRatioList.InsertItem(pos, str); 


	}
	else if(m_natureNumber>m_vtNature.size())//������ɾ��
	{
		m_NatureList.DeleteItem(m_row);
		m_CalcRatioList.DeleteItem(m_row);
	}
	m_natureNumber=m_vtNature.size();//�����������С
}


void CCompositionOptimizationDlg::AutoSizeListColumn(CListCtrl &clist,int column)
{
	clist.SetColumnWidth(column, LVSCW_AUTOSIZE);  
	int nColumnWidth = clist.GetColumnWidth(column);  
	clist.SetColumnWidth(column, LVSCW_AUTOSIZE_USEHEADER);  
	int nHeaderWidth = clist.GetColumnWidth(column);  
	clist.SetColumnWidth(column, max(nColumnWidth, nHeaderWidth));

}


void CCompositionOptimizationDlg::OnNMDblclkListComposition(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if(pNMListView->iItem!=-1&&2==pNMListView->iSubItem)
	{
		m_row=pNMListView->iItem;							//m_rowΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_column=pNMListView->iSubItem;						//m_columnΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_CompositionList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//ȡ������ľ���

		rc.bottom+=3;

		m_inputComEdit.SetParent(&m_CompositionList);
		//char * ch=new char [5];
		PTSTR ch=new TCHAR[20];
		m_CompositionList.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,20);//ȡ�����������
		m_inputComEdit.SetWindowText(ch);					//�������������ʾ���༭����
		m_inputComEdit.ShowWindow(SW_SHOW);					//��ʾ�༭��
		m_inputComEdit.MoveWindow(&rc);						//���༭���ƶ����������棬������������
		m_inputComEdit.SetFocus();							//ʹ�༭��ȡ�ý���
		m_inputComEdit.CreateSolidCaret(1,rc.Height()-5);	//����һ�����
		m_inputComEdit.ShowCaret();							//��ʾ���
		m_inputComEdit.SetSel(-1);							//ʹ����Ƶ������
	}
	*pResult = 0;
}

//˫��
void CCompositionOptimizationDlg::OnNMDblclkListNature(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if(pNMListView->iItem!=-1&&pNMListView->iSubItem==2)
	{
		m_row=pNMListView->iItem;								//m_rowΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_column=pNMListView->iSubItem;							//m_columnΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_NatureList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//ȡ������ľ���

		rc.bottom+=3;

		m_inputNatureEdit.SetParent(&m_NatureList);
		PTSTR ch=new TCHAR[20];
		m_NatureList.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,20);//ȡ�����������
		m_inputNatureEdit.SetWindowText(ch);					//�������������ʾ���༭����
		m_inputNatureEdit.ShowWindow(SW_SHOW);					//��ʾ�༭��
		m_inputNatureEdit.MoveWindow(&rc);						//���༭���ƶ����������棬������������
		m_inputNatureEdit.SetFocus();							//ʹ�༭��ȡ�ý���
		m_inputNatureEdit.CreateSolidCaret(1,rc.Height()-5);	//����һ�����
		m_inputNatureEdit.ShowCaret();							//��ʾ���
		m_inputNatureEdit.SetSel(-1);							//ʹ����Ƶ������
	}
	
	*pResult = 0;
}

//����
void CCompositionOptimizationDlg::OnNMClickListNature(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if (pNMListView->iItem!=-1&&pNMListView->iSubItem==3)
	{
		m_row=pNMListView->iItem;						//m_rowΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_column=pNMListView->iSubItem;					//m_columnΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_NatureList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//ȡ������ľ���

		rc.bottom+=3;

		m_combo.SetParent(&m_NatureList);
		m_combo.ShowWindow(SW_SHOW);					//��ʾ�༭��
		m_combo.MoveWindow(&rc);						//���༭���ƶ����������棬������������
		m_combo.SetFocus();								//ʹ�༭��ȡ�ý���
	}
	*pResult = 0;
}


void CCompositionOptimizationDlg::OnEnKillfocusEdit1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ж������Ƿ����Ҫ�󣨺�������
	CString str;
	m_inputComEdit.GetWindowText(str);//ȡ�ñ༭�������
	m_CompositionList.SetItemText(m_row,m_column,str);//�������ݸ��µ�CListCtrl��
	m_inputComEdit.ShowWindow(SW_HIDE);//���ر༭��
}


void CCompositionOptimizationDlg::OnEnKillfocusEdit2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ж������Ƿ����Ҫ�󣨺�������
	CString str;
	m_inputNatureEdit.GetWindowText(str);//ȡ�ñ༭�������
	m_NatureList.SetItemText(m_row,m_column,str);//�������ݸ��µ�CListCtrl��
	m_inputNatureEdit.ShowWindow(SW_HIDE);//���ر༭��
}


void CCompositionOptimizationDlg::OnCbnKillfocusCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��������ʧʱ����ѡ�����ֵ��䵽����С�ȡ��ֵ�� ��ȡСֵ��
	CString str;
	m_combo.GetWindowText(str);//ȡ�ñ༭�������
	m_NatureList.SetItemText(m_row,m_column,str);//�������ݸ��µ�CListCtrl��
	m_combo.ShowWindow(SW_HIDE);//���ر༭��
}


void CCompositionOptimizationDlg::AnalysisData()
{

	//һ�����������������
	//����
	vector<CString>::iterator vtIt=m_vtComposition.begin();
	vector<CString>::iterator vtItEnd=m_vtComposition.end();
	vector<float> vt;
	CString strGetFromList;
	
	float a;
	float b;
	int Item=0;
	int mapKey=0;
	for (;vtIt!=vtItEnd;++vtIt)
	{
		vt.clear();
		//һ�����б��л�ȡ��ֵ,��Ϊ�б������˳���ǰ���vt�е��ŵģ�����˳���֪
		strGetFromList=m_CompositionList.GetItemText(Item,2);
		//����ת��Ϊ����ֵ
		//��ȡ*vtIt����Ӧ���б��ֵ��Ȼ�����ַ�������Ϊ������
		CStringToFloat(strGetFromList,a,b);
		//��������1�ضϣ���ŵ�map��
		while (a+1<b)//�����жϵ�ǰ�᣺ȷ��b��aҪ�����Ӧ��������ʱ������
		{
			vt.push_back(a);
			a++;
		}
		vt.push_back(a);
		vt.push_back(b);
		//������ѽض�������ʾ���б���
		int size=vt.size();
		CString strDisplay(""),strTemp("");
		for (int i=0;i<size;i++)
		{
			strTemp.Format(_T("%g  "),vt.at(i));
			strDisplay+=strTemp;
		}
		m_CompositionList.SetItemText(Item,3,strDisplay);//��ʾ���б���

		//�Զ�������ȡ���
		m_CompositionList.SetColumnWidth(3, LVSCW_AUTOSIZE);  
		int nColumnWidth = m_CompositionList.GetColumnWidth(3);  
		m_CompositionList.SetColumnWidth(3, LVSCW_AUTOSIZE_USEHEADER);  
		int nHeaderWidth = m_CompositionList.GetColumnWidth(3);  
		m_CompositionList.SetColumnWidth(3, max(nColumnWidth, nHeaderWidth));

		Item++;
		m_mapComposition.insert(make_pair(mapKey++,vt));//�����ݼ��뵽map��
	}
	


	//����������������
	vtIt=m_vtNature.begin();
	vtItEnd=m_vtNature.end();
	Item=0;
	SNature snatur;
	for (;vtIt!=vtItEnd;++vtIt)
	{
		vt.clear();
		//һ�����б��л�ȡ��ֵ,��Ϊ�б������˳���ǰ���vt�е��ŵģ�����˳���֪

		strGetFromList=m_NatureList.GetItemText(Item,2);//��ȡ��ֵ

		//����ת��Ϊ����ֵ
		//��ȡ*vtIt����Ӧ���б��ֵ��Ȼ�����ַ�������Ϊ������
		CStringToFloat(strGetFromList,a,b);
		//��������1�ضϣ���ŵ�map��
		vt.push_back(a);
		vt.push_back(b);
		snatur.NCompareValue=vt;

		strGetFromList=m_NatureList.GetItemText(Item,3);//�ж�ȡ��ֵ����ȡСֵ
		if (strGetFromList==_T("ȡ��ֵ"))
		{
			snatur.choiceValue=LargeValue;
		}
		else if (strGetFromList==_T("ȡСֵ"))
		{
			snatur.choiceValue=SmallVaule;
		}
		
		m_vtCompareNatur.push_back(snatur);//�����ݼ��뵽������
		Item++;
	}

	//��ϵ���б��л�ȡ����ϵ��
	int compositionNumber=m_vtComposition.size();
	map<CString,float> mapCF;
	float fValue=0;
	for (int i=0;i<compositionNumber;i++)
	{
		int natureNumber=m_vtNature.size();
		for(int j=0;j<natureNumber;j++)
		{
			strGetFromList=m_CalcRatioList.GetItemText(j,i+1);//��ȡ��ֵ
			fValue=_ttof(strGetFromList);
			mapCF.insert(make_pair(m_vtNature.at(j),fValue));
		}
		m_mapAllNature.insert(make_pair(i,mapCF));
	}
	
	
	

}


void CCompositionOptimizationDlg::CStringToFloat(CString str,float &a,float &b,bool bNeedSort/*=true*/)
{
	int pos=str.Find('-');
	CString strA=str.Left(pos);
	int n=str.GetLength();
	CString strB=str.Right(n-1-pos);
	a=_ttof(strA);
	b=_ttof(strB);
	if (bNeedSort)//�����Ҫ����,����Ĭ��Ϊ����a<b
	{
		if (a>b)
		{
			float t=a;
			a=b;
			b=t;
		}
	}
}


void CCompositionOptimizationDlg::GetCalcCOE()
{
	map<CString,float> m_map;
	m_map.insert(make_pair("����ϵ��",(float)35.0));
	m_map.insert(make_pair("������",(float)1.46));
	m_mapAllNature.insert(make_pair(0,m_map));
	m_map.clear();

	m_map.insert(make_pair("����ϵ��",(float)-40.0));
	m_map.insert(make_pair("������",(float)1.52));
	m_mapAllNature.insert(make_pair(1,m_map));
	m_map.clear();

	m_map.insert(make_pair("����ϵ��",(float)130.0));
	m_map.insert(make_pair("������",(float)1.73));
	m_mapAllNature.insert(make_pair(2,m_map));
	m_map.clear();

	m_map.insert(make_pair("����ϵ��",(float)300.0));
	m_map.insert(make_pair("������",(float)1.59));
	m_mapAllNature.insert(make_pair(3,m_map));
	m_map.clear();
	
}


void CCompositionOptimizationDlg::CalculateNature()
{
	m_vtSub.clear();
	int typeNumber=m_vtComposition.size();//�ж���������
	for (int i=0;i<typeNumber;i++)
	{
		m_vtSub.push_back(-1);
	}
	//���õݹ麯��ʵ��ѭ����ʵ�ַ���
	//�������ݴ�ŵ���vector<vector<float>> m_subResult��
	//0�� 1 3 5 7
	//1�� 1 3 5 8
	//2�� 1 3 6 7
	//   ...
	map<int,vector<float>>::iterator itMap=m_mapComposition.begin();
	vector<float> vt=itMap->second;
	vector<float>::iterator itVt=vt.begin();
	vector<float>::iterator itVtEnd=vt.end();
	for (;itVt!=itVtEnd;++itVt)//������ѭ��
	{
		m_vtSub.at(itMap->first)=(*itVt);
		Calculate(itMap);
	}
	//�������

	
	//����������ÿһ���Ӧ������ϵ��ֵ�������ʡ��������������˳������
	vector<CString>::iterator vtCString=m_vtNature.begin();
	vector<CString>::iterator vtCStringEnd=m_vtNature.end();
	for (;vtCString!=vtCStringEnd;++vtCString)
	{
		//����������ÿһ���Ӧ������ϵ��ֵ�������ʡ��������������˳������
		map<int,map<CString,float>>::iterator itMap2;
		//����ϵ��
		vector<float> vtNature;//��ȡ�����ʶ�Ӧ������ϵ��
		//size��СΪm_vtComposition.size();
		for (int i=0;i<typeNumber;i++)
		{
			itMap2=m_mapAllNature.find(i);//�Ҹ��������� SiO2 Al2O3..
			if (itMap2!=m_mapAllNature.end())//����ҵ���
			{
				map<CString,float>::iterator map3=itMap2->second.find(*vtCString);
				if (map3!=itMap2->second.end())//����ҵ���
				{
					vtNature.push_back(map3->second);
				}
			}	
		}
		int times=m_subResult.size();//�ж��ٷ��飬ѭ�����ٴ�
		float resultValue=0;
		vector<float> vtFloat;
		vtFloat.clear();
		for (int i=0;i<times;i++)
		{
			resultValue=0;
			for (int j=0;j<typeNumber;j++)
			{
				resultValue+=vtNature.at(j)*m_subResult.at(i).at(j);
			}
			vtFloat.push_back(resultValue/100);
		}
		m_mapResult.insert(make_pair(*vtCString,vtFloat));
	}
}


void CCompositionOptimizationDlg::Calculate(map<int,vector<float>>::iterator itMap)
{
	if ((++itMap)!=m_mapComposition.end())//�����ⲻ�����һ��
	{
		//it--;//��ȥ�ж�ʱ�ӵ�1
		vector<float> vt=itMap->second;
		vector<float>::iterator itVt=vt.begin();
		vector<float>::iterator itVtEnd=vt.end();
		for (;itVt!=itVtEnd;++itVt)
		{
			m_vtSub.at(itMap->first)=(*itVt);
			Calculate(itMap);
		}
	}
	else//�����һ��
	{
		m_subResult.push_back(m_vtSub);
	}
	
}


//�ɹ���û���ҵ�����false ��һ���������Ϸ���true
bool CCompositionOptimizationDlg::PreSelect(vector<int> &vtResultIndex)
{
	vector<CString>::iterator itVt=m_vtNature.begin();
	vector<CString>::iterator itVtEnd=m_vtNature.end();
	vector<float> vtTempResult;
	//��¼����Ҫ������
	vector<int>::iterator itErase;
	float fValue;
	int size=m_subResult.size();
	vector<int> vtSampleResultIndex;
	vtResultIndex.clear();
	for (int i=0;i<size;i++)
	{
		vtResultIndex.push_back(i);
	}
	
	int count=0;
	for (;itVt!=itVtEnd;++itVt)
	{
		vtSampleResultIndex=vtResultIndex;
		map<CString,vector<float>>::iterator itMap=m_mapResult.find(*itVt);
		if (itMap!=m_mapResult.end())
		{
			vtTempResult=itMap->second;
			int sizeIndex=vtResultIndex.size();
			for (int i=0;i<sizeIndex;i++)
			{
				fValue=vtTempResult.at(vtSampleResultIndex.at(i));//ȡ����Ӧ��ֵ
				if(!(fValue>=m_vtCompareNatur.at(count).NCompareValue.front()&&fValue<=m_vtCompareNatur.at(count).NCompareValue.back()))//������Ҫ��
				{
					//ɾ��vtResultIndex�е�����
					itErase=find(vtResultIndex.begin(),vtResultIndex.end(),vtSampleResultIndex.at(i));
					if (itErase!=vtResultIndex.end())
					{
						vtResultIndex.erase(itErase);
					}
				}
			}
		}
		count++;
	}
	//�������Ҫ������Ϊ0�����ؼ٣����������ݶ���ɾ����
	if (0==vtResultIndex.size())
	{
		return false;
	}
	return true;
}

//��ȡ��ѡ���
void CCompositionOptimizationDlg::ExtractPreResult(vector<int> vtResultIndex)
{
	//�Ȱ���Ҫ���о�ѡ������ȡ��������m_afterPreResult��m_mapAfterPreResult��
	//��ȡ����ϵ�����
	vector<int>::iterator it=vtResultIndex.begin();
	vector<int>::iterator itEnd=vtResultIndex.end();
	vector<float> vtFloat;
	for (;it!=itEnd;++it)
	{
		vtFloat.clear();

		vtFloat=m_subResult.at(*it);
		m_afterPreResult.push_back(vtFloat);
	}
	//��ȡ�����ݼ�����Ľ��
	vector<CString>::iterator itCString=m_vtNature.begin();
	vector<CString>::iterator itCStringEnd=m_vtNature.end();
	for (;itCString!=itCStringEnd;++itCString)
	{
		map<CString,vector<float>>::iterator itMap=m_mapResult.find(*itCString);
		if (itMap!=m_mapResult.end())
		{
			vector<float> vt=itMap->second;

			vector<int>::iterator it=vtResultIndex.begin();
			vector<int>::iterator itEnd=vtResultIndex.end();
			vector<float> vtFloat;
			vtFloat.clear();
			for (;it!=itEnd;++it)
			{
				vtFloat.push_back(vt.at(*it));
			}
			m_mapAfterPreResult.insert(make_pair(*itCString,vtFloat));
		}
	}
}


bool CCompositionOptimizationDlg::AccuSelect(vector<int> &vtResultIndex)
{
	
	//��ѡ����洢��m_afterPreResult��m_mapAfterPreResult��

	//���ֻ��һ����Ҫ�Ƚϵ����ʣ���ѡ����ӽ����ʵ�һ�鲢����
	if (1==m_vtNature.size())
	{
		int index=0;//��¼�ǵڼ���Ϊ��ֵ����
		vector<float> vt=m_mapAfterPreResult.begin()->second;//��Ϊֻ��һ�����ʣ�����ֱ��ȡ��һ��
		if(LargeValue==m_vtCompareNatur.at(0).choiceValue)//���������ȡ��ֵ
		{
			//���������������ʽ�������������ҳ����ֵ����
			vector<float>::iterator itVt=vt.begin();
			vector<float>::iterator itVtEnd=vt.end();
			int pos=0;
			for (;itVt!=itVtEnd;++itVt,++pos)
			{
				if (vt.at(index)<*itVt)
				{
					index=pos;
				}
			}
		}
		else if (SmallVaule==m_vtCompareNatur.at(0).choiceValue)//���������ȡСֵ
		{
			//���������������ʽ�������������ҳ���Сֵ����
			vector<float>::iterator itVt=vt.begin();
			vector<float>::iterator itVtEnd=vt.end();
			int pos=0;
			for (;itVt!=itVtEnd;++itVt,++pos)
			{
				if (vt.at(index)>*itVt)
				{
					index=pos;
				}
			}
		}
		vtResultIndex.clear();
		vtResultIndex.push_back(index);
		return true;//�����ҵ���ĳһ�����ݵ���������
	}
	//��������������ϵıȽ����ʣ���ʹ��������
	else if (m_vtNature.size()>1)
	{
		//һ������Diֵ
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		int index=0;//vector�е�����
		SNature temp;
		for (;it!=itEnd;++it,++index)
		{
			temp=m_vtCompareNatur.at(index);
			float diff=temp.NCompareValue.back()-temp.NCompareValue.front();//��ֵ��Сֵ
			if(LargeValue==temp.choiceValue)//����Ǵ�ֵ
			{
				map<CString,vector<float>>::iterator itMap=m_mapAfterPreResult.find(*it);
				if (itMap!=m_mapAfterPreResult.end())
				{
					vector<float> vtFloat=itMap->second;
					vector<float> vtResult;//��ż�����
					UINT vectorNumber=vtFloat.size();
					for (UINT i=0;i<vectorNumber;i++)
					{
						vtResult.push_back((temp.NCompareValue.back()-vtFloat.at(i))/diff);//��ȥ��ֵ  Di=( Ymax- Yi)/(Ymax-Ymin)
					}
					m_mapAfterPreResultDi.insert(make_pair(*it,vtResult));
				}
			}
			else if (SmallVaule==temp.choiceValue)//�����Сֵ
			{
				map<CString,vector<float>>::iterator itMap=m_mapAfterPreResult.find(*it);
				if (itMap!=m_mapAfterPreResult.end())
				{
					vector<float> vtFloat=itMap->second;
					vector<float> vtResult;//��ż�����
					UINT vectorNumber=vtFloat.size();
					for (UINT i=0;i<vectorNumber;i++)
					{
						vtResult.push_back((vtFloat.at(i)-temp.NCompareValue.front())/diff);//��ȥСֵ Di=(Yi-Ymin)/(Ymax-Ymin)
					}
					m_mapAfterPreResultDi.insert(make_pair(*it,vtResult));
				}
			}
		}//Di�������


		//���������ۺϵ÷�
		UINT groupNumber=m_afterPreResult.size();//��ѡ�������
		UINT k=groupNumber;//kֵ��Ϊ����
		vector<float> comprehensiveScore(groupNumber,1);//�ۺϵ÷�����
		//���㷽��Ϊ�ѵõ���Di�����ͷ��β����һ�飬Ȼ��ʹ���ۺϵ÷�������ÿһ�����ʵ�������ˣ�����ٿ�k�η�
		vector<CString>::iterator itVt=m_vtNature.begin();
		vector<CString>::iterator itVtEnd=m_vtNature.end();

		
		map<CString,vector<float>>::iterator itDiMapEnd=m_mapAfterPreResultDi.end();
		for (;itVt!=itVtEnd;++itVt)
		{
			map<CString,vector<float>>::iterator itDiMap=m_mapAfterPreResult.find(*itVt);
			if (itDiMap!=m_mapAfterPreResult.end())
			{
				vector<float> vtFloat=itDiMap->second;
				UINT size=vtFloat.size();
				for (UINT i=0;i<size;i++)
				{
					comprehensiveScore.at(i)=comprehensiveScore.at(i)*vtFloat.at(i);
				}
			}
		}
		//��k�η�
		float squareValue=1.0/k;
		for (UINT i=0;i<groupNumber;i++)
		{
			comprehensiveScore.at(i)=pow(comprehensiveScore.at(i),squareValue);
		}
		//��������Tֵ
		//Ϊ�˷�����㣬��������ۺϵ÷ַ��룬ɸѡ�������������һ��  �� ��һ��Ϊ 7 1 3 6 1.3604312
		//															�ڶ���Ϊ 7 1 4 5 1.3456212
		//																		...
		groupNumber=m_afterPreResult.size();//��ѡ�������
		for (UINT i=0;i<groupNumber;i++)
		{
			m_afterPreResult.at(i).push_back(comprehensiveScore.at(i));
		}
		
		vector<float> finalResult;
		CalculateFinallyGroup(m_afterPreResult,finalResult);//�������յ�����ֵ����������Tֵ��ɸѡ����
		//�������������ٰ��ۺϵ÷�ȡ��
		groupNumber=m_afterPreResult.size();//��ѡ�������
		for (UINT i=0;i<groupNumber;i++)
		{
			m_afterPreResult.at(i).erase(m_afterPreResult.at(i).begin()+m_compositionNumber);//ȥ���ۺϵ÷�
		}

		//�ġ����ʷ���
		//�жϳ�ѡ�������Ƿ����������������飬���򷵻�����ֵ��true��û���򷵻�false
		vector<vector<float>>::iterator itVt2=m_afterPreResult.begin();
		vector<vector<float>>::iterator itVt2End=m_afterPreResult.end();
		bool flag=false;
		int pos=0;
		for (;itVt2!=itVt2End;++itVt2,++pos)
		{
			int count=1;
			int compositionNumber=(*itVt2).size();
			for (int i=0;i<compositionNumber;i++)
			{
				if ((*itVt2).at(i)!=finalResult.at(i))//ֻҪ�в���ȵ����˳�ѭ�����Ƚ���һ��
				{
					break;
				}
				else
				{
					count++;
					if (count==compositionNumber)//����Ƚ������е����ݶ���ȣ��򷵻�true������
					{
						flag=true;
						vtResultIndex.clear();
						vtResultIndex.push_back(pos);
						return true;
					}
				}
			}
		}

		//�塢���ؽ��
	}
	return false;

}

//�������յ�����ֵ����������Tֵ��ɸѡ����
void CCompositionOptimizationDlg::CalculateFinallyGroup(const vector<vector<float>> &m_preResult,vector<float> &ReturnResult)
{
	int compositionNumber=m_vtComposition.size();//������ʸ���
	vector<vector<float>> copyResult;
	for (int i=0;i<compositionNumber;i++)
	{
		//�����i�����ʣ����1��ΪSiO2
		copyResult=m_preResult;
		vector<vector<float>>::iterator itVt2=copyResult.begin();
		vector<vector<float>>::iterator itCompare;
		map<float,float> mapFloat2;
		mapFloat2.clear();
		for(;itVt2!=copyResult.end();++itVt2)
		{
			float compareValue=(*itVt2).at(i);
			itCompare=itVt2;
			int count=1;
			float comprehensiveScore=(*itVt2).back();//�ۺϵ÷�
			++itCompare;
			while (itCompare!=copyResult.end())
			{
				if (compareValue==(*itCompare).at(i))
				{
					count++;
					comprehensiveScore+=(*itCompare).back();
					itCompare=copyResult.erase(itCompare);//���Ѿ�����������������
				}
				else
				{
					++itCompare;
				}
			}
			comprehensiveScore=comprehensiveScore/count;//������ۺϵ÷�
			mapFloat2.insert(make_pair(compareValue,comprehensiveScore));
		}
		//ȡ�����ֵ��Ӧ������
		map<float,float>::iterator itMap=mapFloat2.begin();
		map<float,float>::iterator itMapEnd=mapFloat2.end();
		//�ȼ����һ��ֵΪ���ֵ
		float maxKey=itMap->first;
		float maxValue=itMap->second;
		//Ȼ��������ֵ�Ƚϣ�ȡ��
		++itMap;
		for (;itMap!=itMapEnd;++itMap)
		{
			if (itMap->second>maxValue)
			{
				maxKey=itMap->first;
				maxValue=itMap->second;
			}
		}
		//���뷵��������
		ReturnResult.push_back(maxKey);
	}
}


void CCompositionOptimizationDlg::Display(vector<vector<float>> &result,map<CString,vector<float>> &mapResult,int resultIndex)
{
	vector<float> vtResult=result.at(resultIndex);
	vector<float>::iterator itVt=vtResult.begin();
	vector<float>::iterator itVtEnd=vtResult.end();
	int pos=1;
	CString str;
	for (;itVt!=itVtEnd;++itVt)
	{
		str.Format(_T("%g"),*itVt);
		m_ResultList.SetItemText(0,pos++,str);
	}
	//��ʾ������ֵõ��Ľ��
	vector<CString>::iterator itVtCString=m_vtNature.begin();
	vector<CString>::iterator itVtCStringEnd=m_vtNature.end();
	for (;itVtCString!=itVtCStringEnd;++itVtCString)
	{
		map<CString,vector<float>>::iterator itMap=mapResult.find(*itVtCString);
		if (itMap!=mapResult.end())
		{
			vector<float> vtf=itMap->second;
			str.Format(_T("%g"),vtf.at(resultIndex));
			m_ResultList.SetItemText(0,pos++,str);
		}
	}
}

//������������Ϊ��һ����ѡ��׼��
void CCompositionOptimizationDlg::ClearData()
{
	m_vtCompareNatur.clear();
	m_mapComposition.clear();
	m_vtSub.clear();
	m_subResult.clear();
	m_mapResult.clear();
	m_afterPreResult.clear();
	m_mapAfterPreResult.clear();
	m_mapAfterPreResultDi.clear();
}

//��ʼɸѡ
void CCompositionOptimizationDlg::OnBnClickedBtnStartopt()
{
	/*******************************************

	�����Ƿ������Ըĳ���������
	��Ϊ�������ʶ������Ƶ�����
	���һ�����ʣ�ֻ��Ҫ�����������һ��ʵ������

	��Ҫ��һ�����ʹ����࣬����������ʼ����������

	*******************************************/
	//�������б�û�����ݣ����˳�
	if (m_vtComposition.empty())
	{
		MessageBox(_T("û��������֣�"));
		return;
	}
	if (m_vtNature.empty())
	{
		MessageBox(_T("û���������ʣ�"));
		return;
	}
	//�����������б�
	InitResultList();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//һ�����������������ݣ������ضϴ���
	AnalysisData();
	//������ȡ����ϵ���������ʵȡ�����
	//GetCalcCOE();//��ȡ����ϵ��
	//������ʼ����
	CalculateNature();
	
	//���н������������ˣ����������m_mapResult��
	//�ġ�ɸѡ���
	//4.1����ɸѡ
	vector<int> vt;
	if (PreSelect(vt))//�������ɸѡ�ɹ�������ʾ������˳�
	{
		if (1==vt.size())
		{
			Display(m_subResult,m_mapResult,vt.front());
			MessageBox(_T("��ѡ��ɹ��ҵ���"));
		}
		else if (vt.size()>1)//������о�ѡ
		{
			//�ڸ���������ȡ�����Ϊvt.begin������
			//4.2��ѡ���
			//���ú���ʹ��ѡ����洢��m_afterPreResult��m_mapAfterPreResult��
			//ֻ����Ҫ��ѡʱ����Ҫ���ô˺���
			ExtractPreResult(vt);

			if (AccuSelect(vt))
			{
				
				//��ʾ���ŵ����
				Display(m_afterPreResult,m_mapAfterPreResult,vt.front());
				MessageBox(_T("��ѡ��ɹ��ҵ���"));
			}
			else
			{
				MessageBox(_T("��ѡ���޽����"));
			}
		}
	}
	else
	{
		MessageBox(_T("��ѡ���޽����"));
	}
	
	ClearData();//������ݣ�Ϊ�´�ʹ����׼��
}


void CCompositionOptimizationDlg::OnBnClickedBtnTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LoadComposition();
	LoadNature();
	Init();
	Test();
}


void CCompositionOptimizationDlg::OnBnClickedBtnClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Clear();
}


void CCompositionOptimizationDlg::OnNMRClickListComposition(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	m_row=pNMListView->iItem;							//m_rowΪ��ѡ���е�����ţ�int���ͳ�Ա������
	m_column=pNMListView->iSubItem;						//m_columnΪ��ѡ���е�����ţ�int���ͳ�Ա������
	CPoint myPoint;  
	ClientToScreen(&myPoint);  
	GetCursorPos(&myPoint); //���λ��  
	m_CompositionMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, myPoint.x, myPoint.y, this);
	*pResult = 0;
}

//��Ӻ�ɾ�����
void CCompositionOptimizationDlg::OnAddComposition(UINT nID)
{
	if (m_DeleteCompID!=nID)//����˵�ID��Ϊɾ�����
	{
		CString str=_T("");
		m_CompositionMenu.GetSubMenu(0)->GetMenuString(nID,str,MF_BYCOMMAND);
		if (str!="")
		{
			vector<CString>::iterator itVt=find(m_vtComposition.begin(),m_vtComposition.end(),str);
			if (itVt!=m_vtComposition.end())//�����֮ǰ�������ɲ�ͬ������룬����ͬ�򵯳��Ի���
			{
				MessageBox(_T("��������֮ǰ��ͬ����֣�"));
			}
			else
			{
				m_vtComposition.push_back(str);
				RebuildList();
			}
		}
	}
	else//ɾ�����
	{
		TCHAR ch[20]={};
		m_CompositionList.GetItemText(m_row, 1,ch,20);//ȡ�����������
		vector<CString>::iterator itVt=find(m_vtComposition.begin(),m_vtComposition.end(),ch);
		if (itVt!=m_vtComposition.end())
		{
			CString str=_T("ȷ��ɾ�����");
			str.Format(_T("ȷ��ɾ����ɡ�%s��?"),ch);
			if(IDYES==MessageBox(str,NULL,MB_YESNO))
			{
				m_vtComposition.erase(itVt);
				RebuildList();
			}
		}
	}
	
}


void CCompositionOptimizationDlg::OnNMRClickListNature(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPoint myPoint;  
	ClientToScreen(&myPoint);  
	GetCursorPos(&myPoint); //���λ��  
	m_NatureMenu.TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, myPoint.x, myPoint.y,this);
	*pResult = 0;
}


void CCompositionOptimizationDlg::OnAddNature(UINT nID)
{
	if (m_DeleteNatureID!=nID)//����ɾ���Ĳ˵�IDֵ,��������
	{
		CString str=_T("");
		m_NatureMenu.GetSubMenu(0)->GetMenuString(nID,str,MF_BYCOMMAND);
		if (str!="")
		{
			vector<CString>::iterator itVt=find(m_vtNature.begin(),m_vtNature.end(),str);
			if (itVt!=m_vtNature.end())//�����֮ǰ�������ɲ�ͬ������룬����ͬ�򵯳��Ի���
			{
				MessageBox(_T("��������֮ǰ��ͬ�����ʣ�"));
			}
			else
			{
				m_vtNature.push_back(str);
				RebuildList();
			}
		}
	}
	else
	{
		TCHAR ch[20]={};
		m_NatureList.GetItemText(m_row, 1,ch,20);//ȡ�����������
		vector<CString>::iterator itVt=find(m_vtNature.begin(),m_vtNature.end(),ch);
		if (itVt!=m_vtNature.end())
		{
			CString str;
			str.Format(_T("ȷ��ɾ�����ʡ�%s?��"),ch);
			if(IDYES==MessageBox(str,NULL,MB_YESNO))
			{
				m_vtNature.erase(itVt);
				RebuildList();
			}

		}
	}
	
}


//˫������ϵ���б���Ӧ����
void CCompositionOptimizationDlg::OnNMDblclkListCalcratio(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if (pNMListView->iItem!=-1&&pNMListView->iSubItem>0)
	{
		m_row=pNMListView->iItem;						//m_rowΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_column=pNMListView->iSubItem;					//m_columnΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_CalcRatioList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//ȡ������ľ���

		rc.bottom+=3;
		m_calcRatioEdit.SetParent(&m_CalcRatioList);
		PTSTR ch=new TCHAR[20];
		m_CalcRatioList.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,20);//ȡ�����������
		m_calcRatioEdit.SetWindowText(ch);					//�������������ʾ���༭����
		m_calcRatioEdit.ShowWindow(SW_SHOW);				//��ʾ�༭��
		m_calcRatioEdit.MoveWindow(&rc);					//���༭���ƶ����������棬������������
		m_calcRatioEdit.SetFocus();							//ʹ�༭��ȡ�ý���
		m_calcRatioEdit.CreateSolidCaret(1,rc.Height()-5);	//����һ�����
		m_calcRatioEdit.ShowCaret();						//��ʾ���
		m_calcRatioEdit.SetSel(-1);							//ʹ����Ƶ������
	}
	*pResult = 0;
}

//˫������ϵ���б��༭�򽹵���ʧ����Ӧ����
void CCompositionOptimizationDlg::OnEnKillfocusEditCalcrtio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	m_calcRatioEdit.GetWindowText(str);//ȡ�ñ༭�������
	m_CalcRatioList.SetItemText(m_row,m_column,str);//�������ݸ��µ�CListCtrl��
	m_calcRatioEdit.ShowWindow(SW_HIDE);//���ر༭��
}


BOOL CCompositionOptimizationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->wParam==VK_RETURN)//������µ��ǻس���������������ѡ
	{
		OnBnClickedBtnStartopt();
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

