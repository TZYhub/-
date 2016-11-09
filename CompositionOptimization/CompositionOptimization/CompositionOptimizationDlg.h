
// CompositionOptimizationDlg.h : ͷ�ļ�
//

#pragma once

enum ChoiceValue
{
	LargeValue,SmallVaule
};

typedef struct Nature
{
	vector<float> NCompareValue;//����ķ�Χֵ������������ϵ��88-89 �������ֵΪ88��89
	ChoiceValue choiceValue;	//����ȷ�ϴ����ʾ�ѡʱȡ��ֵ����ȡСֵ
}SNature;


#define ID_USER 40000//�����û��Լ�ʹ�õ�ID
#define ID_COMPO_START ID_USER		//��ɲ˵���ID��ΧΪ40000-42000
#define ID_COMPO_END ID_USER+2000

#define ID_NATURE_START ID_USER+2001		//���ʲ˵���ID��ΧΪ42001-44000
#define ID_NATURE_END ID_USER+4000

// CCompositionOptimizationDlg �Ի���
class CCompositionOptimizationDlg : public CDialogEx
{
// ����
public:
	CCompositionOptimizationDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COMPOSITIONOPTIMIZATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	vector<CString> m_vtComposition;				//��Ҫ���������������������
	int m_compositionNumber;						//������ʵ���Ŀ
	vector<CString> m_vtNature;						//��Ҫ�Ƚϵ�������������� �������� �����ʵ�
	int m_natureNumber;								//��Ҫ�Ƚϵ�������Ŀ

	map<CString,CString> m_mapNatureCHtoEN;			//���ʵ����Ķ�Ӧ��Ӣ���ַ�
	map<CString,CString> m_mapNatureChoiceValue;	//���ʶ�Ӧ��ȡֵ����ȡ��ֵ����ȡСֵ


	vector<SNature> m_vtCompareNatur;			//����m_vtNature����˳���ŵ�����Ƚϵ�����
	//int Ϊ��m_vtComposition����ͬ��˳�� ��m_vtComposition�д��ΪSiO2 Al2O3 ��0����SiO2,1����Al2O3
	map<int,vector<float>> m_mapComposition;	//������ʶ�Ӧ�ضϵ����� SiO2 1.1 2.1 3.1 ��������
													//					   Al2O3 2.2 3.2 4.2 


	//int Ϊ��m_vtComposition����ͬ��˳�� ��m_vtComposition�д��ΪSiO2 Al2O3 ��0����SiO2,1����Al2O3
	map<int,map<CString,float>> m_mapAllNature;//���е������磺SiO2������ϵ����35
													//				  �������ʣ�1.46

	vector<float> m_vtSub;
	vector<vector<float>> m_subResult;
	map<CString,vector<float>> m_mapResult;			//����ĸ������ 0 ����ϵ�������еĽ����vector<float>������
													//				1 ������ �����еĽ����vector<float>������

	vector<vector<float>> m_afterPreResult;			//��ѡ֮������ ��������������ϣ���Ҫ���о�ѡ
	map<CString,vector<float>> m_mapAfterPreResult;	//��ѡ֮��Ľ������ͨ������������ϼ�������Ľ��

	map<CString,vector<float>> m_mapAfterPreResultDi;//��ѡ֮������Diֵ

	int m_row;
	int m_column;
	bool m_bIsFirstInit;							//�Ƿ�Ϊ�ʼ�ĳ�ʼ��������������ٳ�ʼ��combo
	CMenu m_CompositionMenu;						//������ɲ˵�
	CMenu m_NatureMenu;								//���ʲ˵�
	int m_DeleteCompID;
	int m_DeleteNatureID;

	void Init();									//���г�ʼ��
	void LoadComposition();							//������Ҫ�����������ʵ��б���
	void LoadNature();								//������Ҫ�Ƚϵ����ʵ��б���
	void LoadResult();								//�������б���Ҫ��ʾ������
	void LoadCalcRatio();							//�������ϵ��
	void InitCompositionList();						//��ʼ������б�
	void InitNatureList();							//��ʼ�������б�
	void InitResultList();							//��ʼ������б�
	void InitCombo();								//��ʼ����ѡ��
	void InitCalcRatioList();						//��ʼ������ϵ���б�
	void LoadStrFromIni(vector<CString> &vtStr,CString keyStr);	//�������ļ��л�ȡ�ַ�������
	void InitMenu();								//��ʼ�������˵�
	void Test();									//���ز�������
	void Clear();									//�������
	void RebuildList();								//��ӻ�ɾ�����ݺ����������б�
	void RebuildCompositionList();
	void RebuildNatureList();
	void RebuildResultList();
	void AutoSizeListColumn(CListCtrl &clist,int column);//�Զ������б��� 


	void AnalysisData();							//�������ݣ��������������Ӧ������
	void CStringToFloat(CString str,float &a,float &b,bool bNeedSort=true);//�ַ�������Ϊ���� �硰1-2����a=1.0,b=2.0;
	void GetCalcCOE();								//��ȡ����ϵ����������ϵ���������ʵȡ�����
	void CalculateNature();							//������������
	void Calculate(map<int,vector<float>>::iterator itMap);

	bool PreSelect(vector<int> &vtResultIndex);		//��ѡ  
	void ExtractPreResult(vector<int> vtResultIndex);//��ȡ��ѡ�������m_afterPreResult��m_mapAfterPreResult��
	bool AccuSelect(vector<int> &vtResultIndex);	//��ѡ  ����true��ѡ�ɹ�������false ���޽��

	void CalculateFinallyGroup(const vector<vector<float>> &m_preResult,vector<float> &ReturnResult);//�������յ�����ֵ����������Tֵ��ɸѡ����

	void Display(vector<vector<float>> &vtResult,map<CString,vector<float>> &mapResult,int resultIndex);				//��ʾ���
	void ClearData();								//��������
	
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_CompositionList;
	CListCtrl m_NatureList;
	CListCtrl m_CalcRatioList;//����ϵ���б�
	CEdit m_inputComEdit;
	CEdit m_inputNatureEdit;
	CEdit m_calcRatioEdit;
	CListCtrl m_ResultList;
	CComboBox m_combo;//ѡ��ȡ��ֵ����ȡСֵ

	afx_msg void OnNMDblclkListComposition(NMHDR *pNMHDR, LRESULT *pResult);//˫������б�
	afx_msg void OnNMDblclkListNature(NMHDR *pNMHDR, LRESULT *pResult);		//˫�������б�
	afx_msg void OnNMClickListNature(NMHDR *pNMHDR, LRESULT *pResult);		//���������б�
	afx_msg void OnEnKillfocusEdit1();						//�����ɷ�Χ�༭�򽹵���ʧ��
	afx_msg void OnEnKillfocusEdit2();						//������ʷ�Χ�༭�򽹵���ʧ��
	afx_msg void OnCbnKillfocusCombo1();					//ȡ��ֵ��Сֵ��combo������ʧ��

	afx_msg void OnBnClickedBtnStartopt();					//��ʼ��ѡ��ť��Ӧ����

	afx_msg void OnBnClickedBtnTest();						//���ز��԰�ť��Ӧ����
	afx_msg void OnBnClickedBtnClear();						//����б���水ť��Ӧ����
	
	afx_msg void OnNMRClickListComposition(NMHDR *pNMHDR, LRESULT *pResult);//�Ҽ�����б���Ӧ����
	afx_msg void OnNMRClickListNature(NMHDR *pNMHDR, LRESULT *pResult);		//�Ҽ������б���Ӧ����
	
	
	afx_msg void OnNMDblclkListCalcratio(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusEditCalcrtio();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnAddComposition(UINT nID);				//��ӻ�ɾ�����
	afx_msg void OnAddNature(UINT nID);						//��ӻ�ɾ������
};
