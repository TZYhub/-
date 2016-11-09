
// CompositionOptimizationDlg.h : 头文件
//

#pragma once

enum ChoiceValue
{
	LargeValue,SmallVaule
};

typedef struct Nature
{
	vector<float> NCompareValue;//输入的范围值，如输入膨胀系数88-89 则里面的值为88、89
	ChoiceValue choiceValue;	//用来确认此性质精选时取大值还是取小值
}SNature;


#define ID_USER 40000//定义用户自己使用的ID
#define ID_COMPO_START ID_USER		//组成菜单的ID范围为40000-42000
#define ID_COMPO_END ID_USER+2000

#define ID_NATURE_START ID_USER+2001		//性质菜单的ID范围为42001-44000
#define ID_NATURE_END ID_USER+4000

// CCompositionOptimizationDlg 对话框
class CCompositionOptimizationDlg : public CDialogEx
{
// 构造
public:
	CCompositionOptimizationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_COMPOSITIONOPTIMIZATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	vector<CString> m_vtComposition;				//需要计算的组成物质数组的名字
	int m_compositionNumber;						//组成物质的数目
	vector<CString> m_vtNature;						//需要比较的性质数组的名字 如膨胀率 折射率等
	int m_natureNumber;								//需要比较的性质数目

	map<CString,CString> m_mapNatureCHtoEN;			//性质的中文对应的英文字符
	map<CString,CString> m_mapNatureChoiceValue;	//性质对应的取值，是取大值还是取小值


	vector<SNature> m_vtCompareNatur;			//根据m_vtNature数据顺序存放的输入比较的数据
	//int 为与m_vtComposition中相同的顺序 如m_vtComposition中存放为SiO2 Al2O3 则0代表SiO2,1代表Al2O3
	map<int,vector<float>> m_mapComposition;	//组成物质对应截断的数据 SiO2 1.1 2.1 3.1 此类数据
													//					   Al2O3 2.2 3.2 4.2 


	//int 为与m_vtComposition中相同的顺序 如m_vtComposition中存放为SiO2 Al2O3 则0代表SiO2,1代表Al2O3
	map<int,map<CString,float>> m_mapAllNature;//所有的性质如：SiO2，膨胀系数，35
													//				  ，折射率，1.46

	vector<float> m_vtSub;
	vector<vector<float>> m_subResult;
	map<CString,vector<float>> m_mapResult;			//计算的各个结果 0 膨胀系数，所有的结果在vector<float>数组中
													//				1 折射率 ，所有的结果在vector<float>数组中

	vector<vector<float>> m_afterPreResult;			//初选之后的组合 即满足条件的组合，需要进行精选
	map<CString,vector<float>> m_mapAfterPreResult;	//初选之后的结果，即通过满足条件组合计算出来的结果

	map<CString,vector<float>> m_mapAfterPreResultDi;//初选之后结果的Di值

	int m_row;
	int m_column;
	bool m_bIsFirstInit;							//是否为最开始的初始化，如果不是则不再初始化combo
	CMenu m_CompositionMenu;						//物质组成菜单
	CMenu m_NatureMenu;								//性质菜单
	int m_DeleteCompID;
	int m_DeleteNatureID;

	void Init();									//所有初始化
	void LoadComposition();							//导入需要计算的组成物质到列表中
	void LoadNature();								//导入需要比较的性质到列表中
	void LoadResult();								//导入结果列表需要显示的数据
	void LoadCalcRatio();							//导入计算系数
	void InitCompositionList();						//初始化组成列表
	void InitNatureList();							//初始化性质列表
	void InitResultList();							//初始化结果列表
	void InitCombo();								//初始化复选框
	void InitCalcRatioList();						//初始化计算系数列表
	void LoadStrFromIni(vector<CString> &vtStr,CString keyStr);	//从配置文件中获取字符串数据
	void InitMenu();								//初始化弹出菜单
	void Test();									//加载测试数据
	void Clear();									//清空数据
	void RebuildList();								//添加或删减数据后，重新生成列表
	void RebuildCompositionList();
	void RebuildNatureList();
	void RebuildResultList();
	void AutoSizeListColumn(CListCtrl &clist,int column);//自动调节列表宽度 


	void AnalysisData();							//分析数据，把数据填充至对应变量中
	void CStringToFloat(CString str,float &a,float &b,bool bNeedSort=true);//字符串解析为浮点 如“1-2”，a=1.0,b=2.0;
	void GetCalcCOE();								//获取计算系数，如膨胀系数、折射率等。。。
	void CalculateNature();							//计算各组的性质
	void Calculate(map<int,vector<float>>::iterator itMap);

	bool PreSelect(vector<int> &vtResultIndex);		//初选  
	void ExtractPreResult(vector<int> vtResultIndex);//提取初选结果，到m_afterPreResult和m_mapAfterPreResult中
	bool AccuSelect(vector<int> &vtResultIndex);	//精选  返回true则精选成功，返回false 则无结果

	void CalculateFinallyGroup(const vector<vector<float>> &m_preResult,vector<float> &ReturnResult);//计算最终的数组值，包括计算T值，筛选分组

	void Display(vector<vector<float>> &vtResult,map<CString,vector<float>> &mapResult,int resultIndex);				//显示结果
	void ClearData();								//清理数据
	
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_CompositionList;
	CListCtrl m_NatureList;
	CListCtrl m_CalcRatioList;//计算系数列表
	CEdit m_inputComEdit;
	CEdit m_inputNatureEdit;
	CEdit m_calcRatioEdit;
	CListCtrl m_ResultList;
	CComboBox m_combo;//选择取大值还是取小值

	afx_msg void OnNMDblclkListComposition(NMHDR *pNMHDR, LRESULT *pResult);//双击组成列表
	afx_msg void OnNMDblclkListNature(NMHDR *pNMHDR, LRESULT *pResult);		//双击性质列表
	afx_msg void OnNMClickListNature(NMHDR *pNMHDR, LRESULT *pResult);		//单击性质列表
	afx_msg void OnEnKillfocusEdit1();						//添加组成范围编辑框焦点消失后
	afx_msg void OnEnKillfocusEdit2();						//添加性质范围编辑框焦点消失后
	afx_msg void OnCbnKillfocusCombo1();					//取大值和小值的combo焦点消失后

	afx_msg void OnBnClickedBtnStartopt();					//开始优选按钮响应函数

	afx_msg void OnBnClickedBtnTest();						//加载测试按钮响应函数
	afx_msg void OnBnClickedBtnClear();						//清除列表界面按钮响应函数
	
	afx_msg void OnNMRClickListComposition(NMHDR *pNMHDR, LRESULT *pResult);//右键组成列表响应函数
	afx_msg void OnNMRClickListNature(NMHDR *pNMHDR, LRESULT *pResult);		//右键性质列表响应函数
	
	
	afx_msg void OnNMDblclkListCalcratio(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusEditCalcrtio();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnAddComposition(UINT nID);				//添加或删除组成
	afx_msg void OnAddNature(UINT nID);						//添加或删除性质
};
