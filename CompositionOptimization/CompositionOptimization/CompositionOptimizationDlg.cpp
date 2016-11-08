
// CompositionOptimizationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CompositionOptimization.h"
#include "CompositionOptimizationDlg.h"
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


// CCompositionOptimizationDlg 对话框




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


// CCompositionOptimizationDlg 消息处理程序

BOOL CCompositionOptimizationDlg::OnInitDialog()
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
	//初始化
	Init();
	InitMenu();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCompositionOptimizationDlg::OnPaint()
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
	//str可以从另一个列表或是编辑框中获得或配置文件中
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
	str="膨胀系数";
	m_vtNature.push_back(str);
	str="折射率";
	m_vtNature.push_back(str);

	m_natureNumber=m_vtNature.size();
}


void CCompositionOptimizationDlg::LoadResult()
{

}


void CCompositionOptimizationDlg::LoadCalcRatio()
{
	map<CString,float> m_map;
	m_map.insert(make_pair("膨胀系数",(float)35.0));
	m_map.insert(make_pair("折射率",(float)1.46));
	m_mapAllNature.insert(make_pair(0,m_map));
	m_map.clear();

	m_map.insert(make_pair("膨胀系数",(float)-40.0));
	m_map.insert(make_pair("折射率",(float)1.52));
	m_mapAllNature.insert(make_pair(1,m_map));
	m_map.clear();

	m_map.insert(make_pair("膨胀系数",(float)130.0));
	m_map.insert(make_pair("折射率",(float)1.73));
	m_mapAllNature.insert(make_pair(2,m_map));
	m_map.clear();

	m_map.insert(make_pair("膨胀系数",(float)300.0));
	m_map.insert(make_pair("折射率",(float)1.59));
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
	//先删除所有行和所有列，再加载
	m_CompositionList.DeleteAllItems();
	int nColumnCount = m_CompositionList.GetHeaderCtrl()->GetItemCount();
	// Delete all of the columns.
	for (int i=0;i < nColumnCount;i++)
	{
		m_CompositionList.DeleteColumn(0);
	}


	LONG lStyle;
	lStyle = GetWindowLong(m_CompositionList.m_hWnd, GWL_STYLE);//获取当前窗口style
	lStyle |= LVS_REPORT;										//设置style
	DWORD dwStyle = m_CompositionList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;							// 选中某行使整行高亮（只适用与report 风格的listctrl ）   
	dwStyle |= LVS_EX_GRIDLINES;								// 网格线（只适用与report 风格的listctrl ）      
	m_CompositionList.SetExtendedStyle(dwStyle);				// 设置扩展风格 

	m_CompositionList.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 40); 
	m_CompositionList.InsertColumn(1, _T("组成"), LVCFMT_CENTER, 60); 
	m_CompositionList.InsertColumn(2, _T("组成范围"), LVCFMT_CENTER, 60); 
	m_CompositionList.InsertColumn(3,_T("截取值"),LVCFMT_LEFT,240); 
	//自动调整截取宽度
	AutoSizeListColumn(m_CompositionList,3);
	
	//从一个数组里导入需要计算的组成物质
	if (!m_vtComposition.empty())//有数据
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
	//先删除所有行和所有列，再加载
	m_NatureList.DeleteAllItems();
	int nColumnCount = m_CompositionList.GetHeaderCtrl()->GetItemCount();
	// Delete all of the columns.
	for (int i=0;i < nColumnCount;i++)
	{
		m_NatureList.DeleteColumn(0);
	}

	LONG lStyle;
	lStyle = GetWindowLong(m_NatureList.m_hWnd, GWL_STYLE);	//获取当前窗口style
	lStyle |= LVS_REPORT;									//设置style
	DWORD dwStyle = m_NatureList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;						// 选中某行使整行高亮（只适用与report 风格的listctrl ）   
	dwStyle |= LVS_EX_GRIDLINES;							// 网格线（只适用与report 风格的listctrl ）      
	m_NatureList.SetExtendedStyle(dwStyle);					// 设置扩展风格 


	m_NatureList.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 40); 
	m_NatureList.InsertColumn(1, _T("性    质"), LVCFMT_CENTER, 60); 
	m_NatureList.InsertColumn(2,_T("性质范围"),LVCFMT_CENTER,80);
	m_NatureList.InsertColumn(3,_T("取大/小值"),LVCFMT_CENTER,80);

	//从一个数组里导入需要计算的组成物质
	if (!m_vtNature.empty())//有数据
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
	lStyle = GetWindowLong(m_ResultList.m_hWnd, GWL_STYLE);	//获取当前窗口style
	lStyle |= LVS_REPORT;									//设置style
	DWORD dwStyle = m_ResultList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;						// 选中某行使整行高亮（只适用与report 风格的listctrl ）   
	dwStyle |= LVS_EX_GRIDLINES;							// 网格线（只适用与report 风格的listctrl ）      
	m_ResultList.SetExtendedStyle(dwStyle);					// 设置扩展风格 
	m_ResultList.InsertColumn(0, _T("组分及性质"), LVCFMT_CENTER, 80); 

	int pos=1;
	if (!m_vtComposition.empty())//有数据
	{
		vector<CString>::iterator it=m_vtComposition.begin();
		vector<CString>::iterator itEnd=m_vtComposition.end();
		
		for (;it!=itEnd;++it,++pos)
		{
			m_ResultList.InsertColumn(pos, *it, LVCFMT_CENTER, 80);
		}
	}

	if (!m_vtNature.empty())//有数据
	{
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		for (;it!=itEnd;++it,++pos)
		{
			m_ResultList.InsertColumn(pos, *it, LVCFMT_CENTER, 80); 
		}
	}

	m_ResultList.InsertItem(1,_T("优选结果"));

}


void CCompositionOptimizationDlg::InitCombo()
{
	if (m_bIsFirstInit)
	{
		m_combo.AddString(_T("取大值"));
		m_combo.AddString(_T("取小值"));
		m_combo.SetCurSel(0);
		m_bIsFirstInit=false;
	}
	
}


void CCompositionOptimizationDlg::InitCalcRatioList()
{
	//删除行和列
	m_CalcRatioList.DeleteAllItems();
	int nColumnCount = m_CalcRatioList.GetHeaderCtrl()->GetItemCount();
	for (int i=0;i < nColumnCount;i++)
	{
		m_CalcRatioList.DeleteColumn(0);
	}

	LONG lStyle;
	lStyle = GetWindowLong(m_CalcRatioList.m_hWnd, GWL_STYLE);	//获取当前窗口style
	lStyle |= LVS_REPORT;									//设置style
	DWORD dwStyle = m_CalcRatioList.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;						// 选中某行使整行高亮（只适用与report 风格的listctrl ）   
	dwStyle |= LVS_EX_GRIDLINES;							// 网格线（只适用与report 风格的listctrl ）      
	m_CalcRatioList.SetExtendedStyle(dwStyle);					// 设置扩展风格 
	m_CalcRatioList.InsertColumn(0, _T("组分"), LVCFMT_CENTER, 120);
	
	int pos=1;
	if (!m_vtComposition.empty())//有数据
	{
		vector<CString>::iterator it=m_vtComposition.begin();
		vector<CString>::iterator itEnd=m_vtComposition.end();

		for (;it!=itEnd;++it,++pos)
		{
			m_CalcRatioList.InsertColumn(pos, *it, LVCFMT_CENTER, 80);
		}
	}

	if (!m_vtNature.empty())//有数据
	{
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		int pos=1;
		CString str;
		for (;it!=itEnd;++it,++pos)
		{
			str.Format(_T("%s计算系数"),*it);
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
		MessageBox(_T("读取配置文件中的组分失败,请检查配置文件！"));
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
	//1.从配置文件中获取组成的所有种类
	vector<CString> vtCString;
	LoadStrFromIni(vtCString,_T("组成"));
	//2.对组成进行排序
	sort(vtCString.begin(),vtCString.end(),StringSort);
	int m_cNumber=vtCString.size();

	//3.组成菜单初始化
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
			subMenu.AppendMenu(MF_STRING,comID++,vtCString.at(i));//添加组分 如 SiO2 Al2O3这种
			i++;
			if (i>=m_cNumber)
			{
				break;
			}
		} while ((theLetter==vtCString.at(i).Left(1)));
		i--;
		MyMenuTemp.AppendMenu(MF_POPUP,(UINT)subMenu.m_hMenu,theLetter);//添加子菜单，如A B C这种
		subMenu.Detach();
	}
	m_CompositionMenu.AppendMenu(MF_POPUP,(UINT)MyMenuTemp.m_hMenu, _T("添加组成"));
	MyMenuTemp.Detach();
	m_DeleteCompID=comID;
	m_CompositionMenu.AppendMenu(MF_STRING,comID,_T("删除组成"));


	//性质菜单初始化
	vtCString.clear();
	LoadStrFromIni(vtCString,_T("性质"));
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
		MyMenuTemp1.AppendMenu(MF_POPUP,(UINT)subMenu1.m_hMenu,theLetter);//添加子菜单，
		subMenu1.Detach();
	}
	m_NatureMenu.AppendMenu(MF_POPUP,(UINT)MyMenuTemp1.m_hMenu, _T("添加性质"));
	MyMenuTemp1.Detach();
	m_DeleteNatureID=NatureID;
	m_NatureMenu.AppendMenu(MF_STRING,NatureID,_T("删除性质"));

}


void CCompositionOptimizationDlg::Test()
{
	m_CompositionList.SetItemText(0,2,_T("7-8"));//
	m_CompositionList.SetItemText(1,2,_T("1-2"));//
	m_CompositionList.SetItemText(2,2,_T("3-4"));//
	m_CompositionList.SetItemText(3,2,_T("5-6"));//
	//筛选无结果数据
	//m_NatureList.SetItemText(0,2,_T("21-24"));//
	//m_NatureList.SetItemText(1,2,_T("0.24-0.25"));//
	//筛选剩一组数据
	//m_NatureList.SetItemText(0,2,_T("22-23"));//
	//m_NatureList.SetItemText(1,2,_T("0.27-0.29"));//
	//筛选剩四组数据
	m_NatureList.SetItemText(0,2,_T("21-24"));//
	m_NatureList.SetItemText(0,3,_T("取大值"));
	m_NatureList.SetItemText(1,2,_T("0.26-0.29"));//
	m_NatureList.SetItemText(1,3,_T("取小值"));
}


void CCompositionOptimizationDlg::Clear()
{
	m_vtComposition.clear();
	m_vtNature.clear();
	Init();
}

//改变组成和性质时，计算系数列表以及结果列表都应该跟着变
void CCompositionOptimizationDlg::RebuildList()
{
	
	RebuildCompositionList();
	RebuildNatureList();
	//1.重新生成结果列表
	InitResultList();
}

void CCompositionOptimizationDlg::RebuildCompositionList()
{
	//如果是添加，则只在后面添加一行，不重新画
	//
	if (m_compositionNumber<m_vtComposition.size())//有数据增加
	{
		int pos=m_vtComposition.size();
		CString str;
		str.Format(_T("%d"),pos);
		m_CompositionList.InsertItem(pos,str);
		m_CompositionList.SetItemText(pos-1,1,m_vtComposition.back());

		m_CalcRatioList.InsertColumn(pos, m_vtComposition.back(), LVCFMT_CENTER, 80);
	}
	else if (m_compositionNumber>m_vtComposition.size())//有数据删除
	{
		//则，删除选中的行
		m_CompositionList.DeleteItem(m_row);
		m_CalcRatioList.DeleteColumn(m_row+1);
	}
	m_compositionNumber=m_vtComposition.size();//最后更新数组大小
}


void CCompositionOptimizationDlg::RebuildNatureList()
{

	if (m_natureNumber<m_vtNature.size())//有数据增加
	{
		int pos=m_vtNature.size();
		CString str;
		str.Format(_T("%d"),pos);
		m_NatureList.InsertItem(pos, str); 
		m_NatureList.SetItemText(pos-1,1, m_vtNature.back()); 

		str.Format(_T("%s计算系数"),m_vtNature.back());
		m_CalcRatioList.InsertItem(pos, str); 


	}
	else if(m_natureNumber>m_vtNature.size())//有数据删除
	{
		m_NatureList.DeleteItem(m_row);
		m_CalcRatioList.DeleteItem(m_row);
	}
	m_natureNumber=m_vtNature.size();//最后更新数组大小
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
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if(pNMListView->iItem!=-1&&2==pNMListView->iSubItem)
	{
		m_row=pNMListView->iItem;							//m_row为被选中行的行序号（int类型成员变量）
		m_column=pNMListView->iSubItem;						//m_column为被选中行的列序号（int类型成员变量）
		m_CompositionList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//取得子项的矩形

		rc.bottom+=3;

		m_inputComEdit.SetParent(&m_CompositionList);
		//char * ch=new char [5];
		PTSTR ch=new TCHAR[20];
		m_CompositionList.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,20);//取得子项的内容
		m_inputComEdit.SetWindowText(ch);					//将子项的内容显示到编辑框中
		m_inputComEdit.ShowWindow(SW_SHOW);					//显示编辑框
		m_inputComEdit.MoveWindow(&rc);						//将编辑框移动到子项上面，覆盖在子项上
		m_inputComEdit.SetFocus();							//使编辑框取得焦点
		m_inputComEdit.CreateSolidCaret(1,rc.Height()-5);	//创建一个光标
		m_inputComEdit.ShowCaret();							//显示光标
		m_inputComEdit.SetSel(-1);							//使光标移到最后面
	}
	*pResult = 0;
}

//双击
void CCompositionOptimizationDlg::OnNMDblclkListNature(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if(pNMListView->iItem!=-1&&pNMListView->iSubItem==2)
	{
		m_row=pNMListView->iItem;								//m_row为被选中行的行序号（int类型成员变量）
		m_column=pNMListView->iSubItem;							//m_column为被选中行的列序号（int类型成员变量）
		m_NatureList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//取得子项的矩形

		rc.bottom+=3;

		m_inputNatureEdit.SetParent(&m_NatureList);
		PTSTR ch=new TCHAR[20];
		m_NatureList.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,20);//取得子项的内容
		m_inputNatureEdit.SetWindowText(ch);					//将子项的内容显示到编辑框中
		m_inputNatureEdit.ShowWindow(SW_SHOW);					//显示编辑框
		m_inputNatureEdit.MoveWindow(&rc);						//将编辑框移动到子项上面，覆盖在子项上
		m_inputNatureEdit.SetFocus();							//使编辑框取得焦点
		m_inputNatureEdit.CreateSolidCaret(1,rc.Height()-5);	//创建一个光标
		m_inputNatureEdit.ShowCaret();							//显示光标
		m_inputNatureEdit.SetSel(-1);							//使光标移到最后面
	}
	
	*pResult = 0;
}

//单击
void CCompositionOptimizationDlg::OnNMClickListNature(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if (pNMListView->iItem!=-1&&pNMListView->iSubItem==3)
	{
		m_row=pNMListView->iItem;						//m_row为被选中行的行序号（int类型成员变量）
		m_column=pNMListView->iSubItem;					//m_column为被选中行的列序号（int类型成员变量）
		m_NatureList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//取得子项的矩形

		rc.bottom+=3;

		m_combo.SetParent(&m_NatureList);
		m_combo.ShowWindow(SW_SHOW);					//显示编辑框
		m_combo.MoveWindow(&rc);						//将编辑框移动到子项上面，覆盖在子项上
		m_combo.SetFocus();								//使编辑框取得焦点
	}
	*pResult = 0;
}


void CCompositionOptimizationDlg::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断输入是否符合要求（后续处理）
	CString str;
	m_inputComEdit.GetWindowText(str);//取得编辑框的内容
	m_CompositionList.SetItemText(m_row,m_column,str);//将该内容更新到CListCtrl中
	m_inputComEdit.ShowWindow(SW_HIDE);//隐藏编辑框
}


void CCompositionOptimizationDlg::OnEnKillfocusEdit2()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断输入是否符合要求（后续处理）
	CString str;
	m_inputNatureEdit.GetWindowText(str);//取得编辑框的内容
	m_NatureList.SetItemText(m_row,m_column,str);//将该内容更新到CListCtrl中
	m_inputNatureEdit.ShowWindow(SW_HIDE);//隐藏编辑框
}


void CCompositionOptimizationDlg::OnCbnKillfocusCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	//当焦点消失时，把选择的最值填充到表格中“取大值” 或“取小值”
	CString str;
	m_combo.GetWindowText(str);//取得编辑框的内容
	m_NatureList.SetItemText(m_row,m_column,str);//将该内容更新到CListCtrl中
	m_combo.ShowWindow(SW_HIDE);//隐藏编辑框
}


void CCompositionOptimizationDlg::AnalysisData()
{

	//一、解析分析组成数据
	//步骤
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
		//一、从列表中获取数值,因为列表的排列顺序是按照vt中的排的，所以顺序可知
		strGetFromList=m_CompositionList.GetItemText(Item,2);
		//二、转换为浮点值
		//获取*vtIt所对应的列表的值，然后由字符串解析为浮点数
		CStringToFloat(strGetFromList,a,b);
		//三、按加1截断，存放到map中
		while (a+1<b)//做此判断的前提：确认b比a要大，这个应该在输入时做处理
		{
			vt.push_back(a);
			a++;
		}
		vt.push_back(a);
		vt.push_back(b);
		//解析后把截断数据显示到列表中
		int size=vt.size();
		CString strDisplay(""),strTemp("");
		for (int i=0;i<size;i++)
		{
			strTemp.Format(_T("%g  "),vt.at(i));
			strDisplay+=strTemp;
		}
		m_CompositionList.SetItemText(Item,3,strDisplay);//显示到列表中

		//自动调整截取宽度
		m_CompositionList.SetColumnWidth(3, LVSCW_AUTOSIZE);  
		int nColumnWidth = m_CompositionList.GetColumnWidth(3);  
		m_CompositionList.SetColumnWidth(3, LVSCW_AUTOSIZE_USEHEADER);  
		int nHeaderWidth = m_CompositionList.GetColumnWidth(3);  
		m_CompositionList.SetColumnWidth(3, max(nColumnWidth, nHeaderWidth));

		Item++;
		m_mapComposition.insert(make_pair(mapKey++,vt));//把数据加入到map中
	}
	


	//二、解析性质数据
	vtIt=m_vtNature.begin();
	vtItEnd=m_vtNature.end();
	Item=0;
	SNature snatur;
	for (;vtIt!=vtItEnd;++vtIt)
	{
		vt.clear();
		//一、从列表中获取数值,因为列表的排列顺序是按照vt中的排的，所以顺序可知

		strGetFromList=m_NatureList.GetItemText(Item,2);//获取数值

		//二、转换为浮点值
		//获取*vtIt所对应的列表的值，然后由字符串解析为浮点数
		CStringToFloat(strGetFromList,a,b);
		//三、按加1截断，存放到map中
		vt.push_back(a);
		vt.push_back(b);
		snatur.NCompareValue=vt;

		strGetFromList=m_NatureList.GetItemText(Item,3);//判断取大值还是取小值
		if (strGetFromList==_T("取大值"))
		{
			snatur.choiceValue=LargeValue;
		}
		else if (strGetFromList==_T("取小值"))
		{
			snatur.choiceValue=SmallVaule;
		}
		
		m_vtCompareNatur.push_back(snatur);//把数据加入到数组中
		Item++;
	}

	//从系数列表中获取计算系数
	int compositionNumber=m_vtComposition.size();
	map<CString,float> mapCF;
	float fValue=0;
	for (int i=0;i<compositionNumber;i++)
	{
		int natureNumber=m_vtNature.size();
		for(int j=0;j<natureNumber;j++)
		{
			strGetFromList=m_CalcRatioList.GetItemText(j,i+1);//获取数值
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
	if (bNeedSort)//如果需要排序,排序默认为升序即a<b
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
	m_map.insert(make_pair("膨胀系数",(float)35.0));
	m_map.insert(make_pair("折射率",(float)1.46));
	m_mapAllNature.insert(make_pair(0,m_map));
	m_map.clear();

	m_map.insert(make_pair("膨胀系数",(float)-40.0));
	m_map.insert(make_pair("折射率",(float)1.52));
	m_mapAllNature.insert(make_pair(1,m_map));
	m_map.clear();

	m_map.insert(make_pair("膨胀系数",(float)130.0));
	m_map.insert(make_pair("折射率",(float)1.73));
	m_mapAllNature.insert(make_pair(2,m_map));
	m_map.clear();

	m_map.insert(make_pair("膨胀系数",(float)300.0));
	m_map.insert(make_pair("折射率",(float)1.59));
	m_mapAllNature.insert(make_pair(3,m_map));
	m_map.clear();
	
}


void CCompositionOptimizationDlg::CalculateNature()
{
	m_vtSub.clear();
	int typeNumber=m_vtComposition.size();//有多少种物质
	for (int i=0;i<typeNumber;i++)
	{
		m_vtSub.push_back(-1);
	}
	//调用递归函数实现循环，实现分组
	//分组数据存放到了vector<vector<float>> m_subResult中
	//0组 1 3 5 7
	//1组 1 3 5 8
	//2组 1 3 6 7
	//   ...
	map<int,vector<float>>::iterator itMap=m_mapComposition.begin();
	vector<float> vt=itMap->second;
	vector<float>::iterator itVt=vt.begin();
	vector<float>::iterator itVtEnd=vt.end();
	for (;itVt!=itVtEnd;++itVt)//最外层的循环
	{
		m_vtSub.at(itMap->first)=(*itVt);
		Calculate(itMap);
	}
	//分组完成

	
	//接下来计算每一组对应的膨胀系数值、折射率。。（按照输入的顺序来）
	vector<CString>::iterator vtCString=m_vtNature.begin();
	vector<CString>::iterator vtCStringEnd=m_vtNature.end();
	for (;vtCString!=vtCStringEnd;++vtCString)
	{
		//接下来计算每一组对应的膨胀系数值、折射率。。（按照输入的顺序来）
		map<int,map<CString,float>>::iterator itMap2;
		//膨胀系数
		vector<float> vtNature;//获取各物质对应的膨胀系数
		//size大小为m_vtComposition.size();
		for (int i=0;i<typeNumber;i++)
		{
			itMap2=m_mapAllNature.find(i);//找各个物质如 SiO2 Al2O3..
			if (itMap2!=m_mapAllNature.end())//如果找到了
			{
				map<CString,float>::iterator map3=itMap2->second.find(*vtCString);
				if (map3!=itMap2->second.end())//如果找到了
				{
					vtNature.push_back(map3->second);
				}
			}	
		}
		int times=m_subResult.size();//有多少分组，循环多少次
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
	if ((++itMap)!=m_mapComposition.end())//表明这不是最后一个
	{
		//it--;//减去判断时加的1
		vector<float> vt=itMap->second;
		vector<float>::iterator itVt=vt.begin();
		vector<float>::iterator itVtEnd=vt.end();
		for (;itVt!=itVtEnd;++itVt)
		{
			m_vtSub.at(itMap->first)=(*itVt);
			Calculate(itMap);
		}
	}
	else//是最后一个
	{
		m_subResult.push_back(m_vtSub);
	}
	
}


//成功：没有找到返回false 有一个或多个符合返回true
bool CCompositionOptimizationDlg::PreSelect(vector<int> &vtResultIndex)
{
	vector<CString>::iterator itVt=m_vtNature.begin();
	vector<CString>::iterator itVtEnd=m_vtNature.end();
	vector<float> vtTempResult;
	//记录符合要求的序号
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
				fValue=vtTempResult.at(vtSampleResultIndex.at(i));//取出对应的值
				if(!(fValue>=m_vtCompareNatur.at(count).NCompareValue.front()&&fValue<=m_vtCompareNatur.at(count).NCompareValue.back()))//不符合要求
				{
					//删除vtResultIndex中的索引
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
	//如果符合要求的序号为0个返回假，即所有数据都被删除了
	if (0==vtResultIndex.size())
	{
		return false;
	}
	return true;
}

//提取初选结果
void CCompositionOptimizationDlg::ExtractPreResult(vector<int> vtResultIndex)
{
	//先把需要进行精选的数据取出，放入m_afterPreResult和m_mapAfterPreResult中
	//先取出组合的数据
	vector<int>::iterator it=vtResultIndex.begin();
	vector<int>::iterator itEnd=vtResultIndex.end();
	vector<float> vtFloat;
	for (;it!=itEnd;++it)
	{
		vtFloat.clear();

		vtFloat=m_subResult.at(*it);
		m_afterPreResult.push_back(vtFloat);
	}
	//再取出数据计算出的结果
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
	
	//初选结果存储在m_afterPreResult和m_mapAfterPreResult中

	//如果只有一个需要比较的性质，则选出最接近性质的一组并返回
	if (1==m_vtNature.size())
	{
		int index=0;//记录是第几组为最值数据
		vector<float> vt=m_mapAfterPreResult.begin()->second;//因为只有一个性质，所以直接取第一个
		if(LargeValue==m_vtCompareNatur.at(0).choiceValue)//如果性质是取大值
		{
			//从这个计算出的性质结果的数组里面找出最大值即可
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
		else if (SmallVaule==m_vtCompareNatur.at(0).choiceValue)//如果性质是取小值
		{
			//从这个计算出的性质结果的数组里面找出最小值即可
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
		return true;//返回找到的某一组数据的索引，在
	}
	//如果有两个或以上的比较性质，则使用正交法
	else if (m_vtNature.size()>1)
	{
		//一、计算Di值
		vector<CString>::iterator it=m_vtNature.begin();
		vector<CString>::iterator itEnd=m_vtNature.end();
		int index=0;//vector中的索引
		SNature temp;
		for (;it!=itEnd;++it,++index)
		{
			temp=m_vtCompareNatur.at(index);
			float diff=temp.NCompareValue.back()-temp.NCompareValue.front();//大值减小值
			if(LargeValue==temp.choiceValue)//如果是大值
			{
				map<CString,vector<float>>::iterator itMap=m_mapAfterPreResult.find(*it);
				if (itMap!=m_mapAfterPreResult.end())
				{
					vector<float> vtFloat=itMap->second;
					vector<float> vtResult;//存放计算结果
					UINT vectorNumber=vtFloat.size();
					for (UINT i=0;i<vectorNumber;i++)
					{
						vtResult.push_back((temp.NCompareValue.back()-vtFloat.at(i))/diff);//减去大值  Di=( Ymax- Yi)/(Ymax-Ymin)
					}
					m_mapAfterPreResultDi.insert(make_pair(*it,vtResult));
				}
			}
			else if (SmallVaule==temp.choiceValue)//如果是小值
			{
				map<CString,vector<float>>::iterator itMap=m_mapAfterPreResult.find(*it);
				if (itMap!=m_mapAfterPreResult.end())
				{
					vector<float> vtFloat=itMap->second;
					vector<float> vtResult;//存放计算结果
					UINT vectorNumber=vtFloat.size();
					for (UINT i=0;i<vectorNumber;i++)
					{
						vtResult.push_back((vtFloat.at(i)-temp.NCompareValue.front())/diff);//减去小值 Di=(Yi-Ymin)/(Ymax-Ymin)
					}
					m_mapAfterPreResultDi.insert(make_pair(*it,vtResult));
				}
			}
		}//Di计算完毕


		//二、计算综合得分
		UINT groupNumber=m_afterPreResult.size();//初选后的组数
		UINT k=groupNumber;//k值即为组数
		vector<float> comprehensiveScore(groupNumber,1);//综合得分数组
		//计算方法为把得到的Di结果从头到尾遍历一遍，然后使用综合得分数组与每一个性质的数据相乘，最后再开k次方
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
		//开k次放
		float squareValue=1.0/k;
		for (UINT i=0;i<groupNumber;i++)
		{
			comprehensiveScore.at(i)=pow(comprehensiveScore.at(i),squareValue);
		}
		//三、计算T值
		//为了方便计算，把算出的综合得分放入，筛选过后的数组的最后一个  如 第一组为 7 1 3 6 1.3604312
		//															第二组为 7 1 4 5 1.3456212
		//																		...
		groupNumber=m_afterPreResult.size();//初选后的组数
		for (UINT i=0;i<groupNumber;i++)
		{
			m_afterPreResult.at(i).push_back(comprehensiveScore.at(i));
		}
		
		vector<float> finalResult;
		CalculateFinallyGroup(m_afterPreResult,finalResult);//计算最终的数组值，包括计算T值，筛选分组
		//算出最终数组后，再把综合得分取出
		groupNumber=m_afterPreResult.size();//初选后的组数
		for (UINT i=0;i<groupNumber;i++)
		{
			m_afterPreResult.at(i).erase(m_afterPreResult.at(i).begin()+m_compositionNumber);//去掉综合得分
		}

		//四、性质反算
		//判断初选数组里是否存在最终算出的数组，有则返回索引值和true，没有则返回false
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
				if ((*itVt2).at(i)!=finalResult.at(i))//只要有不相等的则退出循环，比较下一组
				{
					break;
				}
				else
				{
					count++;
					if (count==compositionNumber)//如果比较完所有的数据都相等，则返回true和索引
					{
						flag=true;
						vtResultIndex.clear();
						vtResultIndex.push_back(pos);
						return true;
					}
				}
			}
		}

		//五、返回结果
	}
	return false;

}

//计算最终的数组值，包括计算T值，筛选分组
void CCompositionOptimizationDlg::CalculateFinallyGroup(const vector<vector<float>> &m_preResult,vector<float> &ReturnResult)
{
	int compositionNumber=m_vtComposition.size();//组成物质个数
	vector<vector<float>> copyResult;
	for (int i=0;i<compositionNumber;i++)
	{
		//计算第i个物质，如第1个为SiO2
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
			float comprehensiveScore=(*itVt2).back();//综合得分
			++itCompare;
			while (itCompare!=copyResult.end())
			{
				if (compareValue==(*itCompare).at(i))
				{
					count++;
					comprehensiveScore+=(*itCompare).back();
					itCompare=copyResult.erase(itCompare);//把已经计算过的数据清理掉
				}
				else
				{
					++itCompare;
				}
			}
			comprehensiveScore=comprehensiveScore/count;//计算出综合得分
			mapFloat2.insert(make_pair(compareValue,comprehensiveScore));
		}
		//取出最大值对应的数据
		map<float,float>::iterator itMap=mapFloat2.begin();
		map<float,float>::iterator itMapEnd=mapFloat2.end();
		//先假设第一个值为最大值
		float maxKey=itMap->first;
		float maxValue=itMap->second;
		//然后与后面的值比较，取出
		++itMap;
		for (;itMap!=itMapEnd;++itMap)
		{
			if (itMap->second>maxValue)
			{
				maxKey=itMap->first;
				maxValue=itMap->second;
			}
		}
		//推入返回数组中
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
	//显示最优组分得到的结果
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

//计算数据清理，为下一次优选做准备
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

//开始筛选
void CCompositionOptimizationDlg::OnBnClickedBtnStartopt()
{
	/*******************************************

	看看是否后面可以改成类来处理
	因为各个物质都有相似的性质
	添加一个物质，只需要在数组中添加一个实例即可

	还要有一个物质管理类，管理各种物质计算出的数据

	*******************************************/
	//有任意列表没有数据，则退出
	if (m_vtComposition.empty())
	{
		MessageBox(_T("没有输入组分！"));
		return;
	}
	if (m_vtNature.empty())
	{
		MessageBox(_T("没有输入性质！"));
		return;
	}
	//清理输出结果列表
	InitResultList();
	// TODO: 在此添加控件通知处理程序代码
	//一、解析输入的组分数据，做出截断处理
	AnalysisData();
	//二、获取膨胀系数、折射率等。。。
	//GetCalcCOE();//获取计算系数
	//三、开始计算
	CalculateNature();
	
	//所有结果都计算出来了，并存放在了m_mapResult中
	//四、筛选组成
	//4.1初步筛选
	vector<int> vt;
	if (PreSelect(vt))//如果初步筛选成功，则显示结果并退出
	{
		if (1==vt.size())
		{
			Display(m_subResult,m_mapResult,vt.front());
			MessageBox(_T("初选后成功找到！"));
		}
		else if (vt.size()>1)//否则进行精选
		{
			//在各个数组里取出序号为vt.begin的数字
			//4.2精选结果
			//调用函数使初选结果存储在m_afterPreResult和m_mapAfterPreResult中
			//只有需要精选时才需要调用此函数
			ExtractPreResult(vt);

			if (AccuSelect(vt))
			{
				
				//显示最优的组分
				Display(m_afterPreResult,m_mapAfterPreResult,vt.front());
				MessageBox(_T("精选后成功找到！"));
			}
			else
			{
				MessageBox(_T("精选后无结果！"));
			}
		}
	}
	else
	{
		MessageBox(_T("初选后无结果！"));
	}
	
	ClearData();//清除数据，为下次使用做准备
}


void CCompositionOptimizationDlg::OnBnClickedBtnTest()
{
	// TODO: 在此添加控件通知处理程序代码
	LoadComposition();
	LoadNature();
	Init();
	Test();
}


void CCompositionOptimizationDlg::OnBnClickedBtnClear()
{
	// TODO: 在此添加控件通知处理程序代码
	Clear();
}


void CCompositionOptimizationDlg::OnNMRClickListComposition(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	m_row=pNMListView->iItem;							//m_row为被选中行的行序号（int类型成员变量）
	m_column=pNMListView->iSubItem;						//m_column为被选中行的列序号（int类型成员变量）
	CPoint myPoint;  
	ClientToScreen(&myPoint);  
	GetCursorPos(&myPoint); //鼠标位置  
	m_CompositionMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, myPoint.x, myPoint.y, this);
	*pResult = 0;
}

//添加和删除组成
void CCompositionOptimizationDlg::OnAddComposition(UINT nID)
{
	if (m_DeleteCompID!=nID)//如果菜单ID不为删除组成
	{
		CString str=_T("");
		m_CompositionMenu.GetSubMenu(0)->GetMenuString(nID,str,MF_BYCOMMAND);
		if (str!="")
		{
			vector<CString>::iterator itVt=find(m_vtComposition.begin(),m_vtComposition.end(),str);
			if (itVt!=m_vtComposition.end())//如果与之前输入的组成不同，则加入，如相同则弹出对话框
			{
				MessageBox(_T("请输入与之前不同的组分！"));
			}
			else
			{
				m_vtComposition.push_back(str);
				RebuildList();
			}
		}
	}
	else//删除组成
	{
		TCHAR ch[20]={};
		m_CompositionList.GetItemText(m_row, 1,ch,20);//取得子项的内容
		vector<CString>::iterator itVt=find(m_vtComposition.begin(),m_vtComposition.end(),ch);
		if (itVt!=m_vtComposition.end())
		{
			CString str=_T("确认删除组成");
			str.Format(_T("确认删除组成“%s”?"),ch);
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
	// TODO: 在此添加控件通知处理程序代码
	CPoint myPoint;  
	ClientToScreen(&myPoint);  
	GetCursorPos(&myPoint); //鼠标位置  
	m_NatureMenu.TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, myPoint.x, myPoint.y,this);
	*pResult = 0;
}


void CCompositionOptimizationDlg::OnAddNature(UINT nID)
{
	if (m_DeleteNatureID!=nID)//不是删除的菜单ID值,则进行添加
	{
		CString str=_T("");
		m_NatureMenu.GetSubMenu(0)->GetMenuString(nID,str,MF_BYCOMMAND);
		if (str!="")
		{
			vector<CString>::iterator itVt=find(m_vtNature.begin(),m_vtNature.end(),str);
			if (itVt!=m_vtNature.end())//如果与之前输入的组成不同，则加入，如相同则弹出对话框
			{
				MessageBox(_T("请输入与之前不同的性质！"));
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
		m_NatureList.GetItemText(m_row, 1,ch,20);//取得子项的内容
		vector<CString>::iterator itVt=find(m_vtNature.begin(),m_vtNature.end(),ch);
		if (itVt!=m_vtNature.end())
		{
			CString str;
			str.Format(_T("确认删除性质“%s?”"),ch);
			if(IDYES==MessageBox(str,NULL,MB_YESNO))
			{
				m_vtNature.erase(itVt);
				RebuildList();
			}

		}
	}
	
}


//双击计算系数列表响应函数
void CCompositionOptimizationDlg::OnNMDblclkListCalcratio(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if (pNMListView->iItem!=-1&&pNMListView->iSubItem>0)
	{
		m_row=pNMListView->iItem;						//m_row为被选中行的行序号（int类型成员变量）
		m_column=pNMListView->iSubItem;					//m_column为被选中行的列序号（int类型成员变量）
		m_CalcRatioList.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//取得子项的矩形

		rc.bottom+=3;
		m_calcRatioEdit.SetParent(&m_CalcRatioList);
		PTSTR ch=new TCHAR[20];
		m_CalcRatioList.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,20);//取得子项的内容
		m_calcRatioEdit.SetWindowText(ch);					//将子项的内容显示到编辑框中
		m_calcRatioEdit.ShowWindow(SW_SHOW);				//显示编辑框
		m_calcRatioEdit.MoveWindow(&rc);					//将编辑框移动到子项上面，覆盖在子项上
		m_calcRatioEdit.SetFocus();							//使编辑框取得焦点
		m_calcRatioEdit.CreateSolidCaret(1,rc.Height()-5);	//创建一个光标
		m_calcRatioEdit.ShowCaret();						//显示光标
		m_calcRatioEdit.SetSel(-1);							//使光标移到最后面
	}
	*pResult = 0;
}

//双击计算系数列表，编辑框焦点消失后响应函数
void CCompositionOptimizationDlg::OnEnKillfocusEditCalcrtio()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_calcRatioEdit.GetWindowText(str);//取得编辑框的内容
	m_CalcRatioList.SetItemText(m_row,m_column,str);//将该内容更新到CListCtrl中
	m_calcRatioEdit.ShowWindow(SW_HIDE);//隐藏编辑框
}


BOOL CCompositionOptimizationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->wParam==VK_RETURN)//如果按下的是回车键，则进行组分优选
	{
		OnBnClickedBtnStartopt();
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

