//// XinWuDlg.cpp : 实现文件
////
//
#include "stdafx.h"
//#include "XZSQH.h"
//#include "XinWuDlg.h"
//#include "afxdialogex.h"
//
//
//// CXinWuDlg 对话框
//
//IMPLEMENT_DYNAMIC(CXinWuDlg, CDialog)
//
//	CXinWuDlg::CXinWuDlg(CWnd* pParent /*=NULL*/)
//	: CDialog(IDD_XinWuDlg, pParent)
//	, Zu_Al(_T(""))
//	, Zu_B(_T(""))
//	, Zu_Ba(_T(""))
//	, Zu_Ca(_T(""))
//	, Zu_Fe(_T(""))
//	, Zu_K(_T(""))
//	, Zu_Li(_T(""))
//	, Zu_Mg(_T(""))
//	, Zu_Na(_T(""))
//	, Zu_P(_T(""))
//	, Zu_Pb(_T(""))
//	, Zu_Sb(_T(""))
//	, Zu_Si(_T(""))
//	, Zu_Zn(_T(""))
//	, m_strZhi(_T(""))
//	, m_strhoudu(_T(""))
//	, Zu_Sr(_T(""))
//{
//
//}
//
//CXinWuDlg::~CXinWuDlg()
//{
////}
//
//void CXinWuDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialog::DoDataExchange(pDX);
//	DDX_Text(pDX, IDC_ZuAl, Zu_Al);
//	DDX_Text(pDX, IDC_ZuB, Zu_B);
//	DDX_Text(pDX, IDC_ZuBa, Zu_Ba);
//	DDX_Text(pDX, IDC_ZuCa, Zu_Ca);
//	DDX_Text(pDX, IDC_ZuFe, Zu_Fe);
//	DDX_Text(pDX, IDC_ZuK, Zu_K);
//	DDX_Text(pDX, IDC_ZuLi, Zu_Li);
//	DDX_Text(pDX, IDC_ZuMg, Zu_Mg);
//	DDX_Text(pDX, IDC_ZuNa, Zu_Na);
//	DDX_Text(pDX, IDC_ZuP, Zu_P);
//	DDX_Text(pDX, IDC_ZuPb, Zu_Pb);
//	DDX_Text(pDX, IDC_ZuSb, Zu_Sb);
//	DDX_Text(pDX, IDC_ZuSi, Zu_Si);
//	DDX_Text(pDX, IDC_ZuZn, Zu_Zn);
//	DDX_Text(pDX, IDC_ZHI, m_strZhi);
//	DDX_Text(pDX, IDC_houdu, m_strhoudu);
//	DDX_Text(pDX, IDC_Sr, Zu_Sr);
//	DDX_Control(pDX, IDC_Sr, m_Sr);
//	DDX_Control(pDX, IDC_ZuAl, m_Al);
//	DDX_Control(pDX, IDC_ZuB, m_B);
//	DDX_Control(pDX, IDC_ZuBa, m_Ba);
//	DDX_Control(pDX, IDC_ZuCa, m_Ca);
//	DDX_Control(pDX, IDC_ZuFe, m_Fe);
//	DDX_Control(pDX, IDC_ZuK, m_K);
//	DDX_Control(pDX, IDC_ZuLi, m_Li);
//	DDX_Control(pDX, IDC_ZuMg, m_Mg);
//	DDX_Control(pDX, IDC_ZuNa, m_Na);
//	DDX_Control(pDX, IDC_ZuP, m_P);
//	DDX_Control(pDX, IDC_ZuPb, m_Pb);
//	DDX_Control(pDX, IDC_ZuSb, m_Sb);
//	DDX_Control(pDX, IDC_ZuSi, m_Si);
//	DDX_Control(pDX, IDC_ZuZn, m_Zn);
//}
//
//
//BEGIN_MESSAGE_MAP(CXinWuDlg, CDialog)
//	ON_BN_CLICKED(IDC_HESUAN, &CXinWuDlg::OnBnClickedHesuan)
//	ON_BN_CLICKED(IDC_DOUT, &CXinWuDlg::OnBnClickedDout)
//	ON_BN_CLICKED(IDC_DAORU, &CXinWuDlg::OnBnClickedDaoru)
//	ON_EN_CHANGE(IDC_ZuSi, &CXinWuDlg::OnEnChangeZusi)
//	ON_EN_CHANGE(IDC_ZuAl, &CXinWuDlg::OnEnChangeZual)
//	ON_EN_CHANGE(IDC_ZuFe, &CXinWuDlg::OnEnChangeZufe)
//	ON_EN_CHANGE(IDC_ZuCa, &CXinWuDlg::OnEnChangeZuca)
//	ON_EN_CHANGE(IDC_ZuMg, &CXinWuDlg::OnEnChangeZumg)
//	ON_EN_CHANGE(IDC_ZuNa, &CXinWuDlg::OnEnChangeZuna)
//	ON_EN_CHANGE(IDC_ZuK, &CXinWuDlg::OnEnChangeZuk)
//	ON_EN_CHANGE(IDC_ZuB, &CXinWuDlg::OnEnChangeZub)
//	ON_EN_CHANGE(IDC_ZuBa, &CXinWuDlg::OnEnChangeZuba)
//	ON_EN_CHANGE(IDC_ZuZn, &CXinWuDlg::OnEnChangeZuzn)
//	ON_EN_CHANGE(IDC_ZuPb, &CXinWuDlg::OnEnChangeZupb)
//	ON_EN_CHANGE(IDC_Sr, &CXinWuDlg::OnEnChangeSr)
//	ON_EN_CHANGE(IDC_ZuLi, &CXinWuDlg::OnEnChangeZuli)
//	ON_EN_CHANGE(IDC_ZuP, &CXinWuDlg::OnEnChangeZup)
//	ON_EN_CHANGE(IDC_ZuSb, &CXinWuDlg::OnEnChangeZusb)
//END_MESSAGE_MAP()
//
//
//// CXinWuDlg 消息处理程序
//
//
//BOOL CXinWuDlg::OnInitDialog()
//{
//	CDialog::OnInitDialog();
//
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//	// 异常: OCX 属性页应返回 FALSE
//}
//BOOL CXinWuDlg::PreTranslateMessage(MSG* pMsg)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	m_ToolTip.RelayEvent(pMsg);
//
//	return CDialog::PreTranslateMessage(pMsg);
//}
//
//
//
//void CXinWuDlg::OnBnClickedHesuan()
//{
//	UpdateData();
//	//Zu_Si,Zu_Al,Zu_Na,Zu_Na,Zu_Ca,Zu_B是编辑框输入数据的变量CString，也就是您代码中截段的组分数据
//	//将截段的数据换算为摩尔分数
//	double mol_Si = atof(Zu_Si) / 60.08;
//	double mol_Al = atof(Zu_Al) / 101.96;
//	double mol_Na = atof(Zu_Na) / 61.98;
//	double mol_Ca = atof(Zu_Ca) / 56.08;
//	double mol_B = atof(Zu_B) / 69.62;
//	double mol_sum = mol_Si + mol_Al + mol_Na + mol_Ca+ mol_B;
//	//核算摩尔百分比，这个摩尔百分比就是后的组分截段数据，只是这个截段数据已经经过了换算；
//	double M_Si = 100 * mol_Si / mol_sum;
//	double M_Al = 100 * mol_Al / mol_sum;
//	double M_Na = 100 * mol_Na / mol_sum;
//	double M_Ca = 100 * mol_Ca / mol_sum;
//	double M_B = 100 * mol_B / mol_sum;
//
//
//	//1.Na2O系数
//	//double定义的是性质种类，上次文件中是列的两种性质,若修改上次代码，可以随便选两种性质就行了，可以节约点儿时间
//	double n_Na, nFnC_Na, CTE_Na, β_Na, W_Na, E_Na, G_Na, λ_Na, V_Na, R_Na, C1_Na, C2_Na, n2_Na, P_Na, Q_Na;
//	if (M_Na <= 35)
//	{
//		n_Na = 1.59;
//		nFnC_Na = 1420;
//		CTE_Na = 400;
//		β_Na = -180;
//		W_Na = 10;
//		E_Na = 5.8;
//		G_Na = 1.95;
//		λ_Na = 2;
//		V_Na = 20.2;
//		R_Na = 6.82;
//		C1_Na = 0.168;
//		C2_Na = 0.442;
//		n2_Na = 42.1;
//		P_Na = 15.78;
//		Q_Na = 6.2;
//	}
//	if (M_Na > 35)
//	{
//		MessageBox("Na2O超出核算范围，请检视！");
//		return;
//	}
//
//
//	//2. CaO的系数,完整系数-------------------------------------------------------------------------------
//	//double定义的是性质种类，上次文件中是列的两种性质,若修改上次代码，可以随便选两种性质就行了，可以节约点儿时间
//	double n_Ca, nFnC_Ca, CTE_Ca, β_Ca, W_Ca, E_Ca, G_Ca, λ_Ca, V_Ca, R_Ca, C1_Ca, C2_Ca, n2_Ca, P_Ca, Q_Ca;
//	if (M_Ca <= 30)
//	{
//		if (M_P > 0)//磷酸盐玻璃
//		{
//			n_Ca = 1.71;
//			nFnC_Ca = 1400;
//			CTE_Ca = 140;
//			β_Ca = 40;
//			W_Ca = 120;
//			E_Ca = 9.5;
//			G_Ca = 3.0;
//			λ_Ca = 20;
//			V_Ca = 17;
//			R_Ca = 6.64;
//			C1_Ca = -0.14;
//			C2_Ca = -0.02;
//			n2_Ca = 30.5;
//			P_Ca = 3.3;
//			Q_Ca = 1.62;
//		}
//		else
//		{
//			n_Ca = 1.73;
//			nFnC_Ca = 1480;
//			CTE_Ca = 130;
//			β_Ca = 60;
//			W_Ca = 140;
//			E_Ca = 12.5;
//			G_Ca = 4.8;
//			λ_Ca = 20;
//			V_Ca = 14.4;
//			R_Ca = 5.75;
//			C1_Ca = -0.14;
//			C2_Ca = -0.02;
//			n2_Ca = 32.4;
//			P_Ca = 3.3;
//			Q_Ca = 1.62;
//		}
//	}
//	if (M_Ca>30)
//	{
//		MessageBox("CaO超出核算范围，请检视！");
//		return;
//	}
//
//	//3.氧化硼的系数（上次文件没有这个组分），-----------------------------------------------------------------------------
//	//double定义的是性质种类，上次文件中是列的两种性质,若修改上次代码，可以随便选两种性质就行了，可以节约点儿时间
//	double n_B, C1_B, C2_B, V_B, E_B, G_B, CTE_B, β_B, W_B, nFnC_B, λ_B, P_B, Q_B, R_B, n2_B;
//
//	double Fenzibi = ((M_Na + M_K) + 0.8*(M_Li + M_Ba) + 0.6*(M_Pb + M_P + M_Sr) + 0.4*M_Ca + 0.2*(M_Zn + M_Mg) - (M_Al + M_B)) / M_B;
//	//定义组分为零时，分子比中分母为零的情况
//	if (M_B == 0)
//	{
//		Fenzibi = 0;
//		n_B = 0;
//		nFnC_B = 0;
//		CTE_B = 0;
//		β_B = 0;
//		W_B = 0;
//		E_B = 0;
//		G_B = 0;
//		λ_B = 0;
//		V_B = 0;
//		R_B = 0;
//		C1_B = 0;
//		C2_B = 0;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (M_Si >= 67 && M_Si <= 100 && Fenzibi > 4)//不能连续写大小，比如 67<= M_Si<100，这样写会提示出错
//	{
//
//		n_B = 1.72;//折射率
//		nFnC_B = 900;
//		CTE_B = -50;
//		β_B = 150;
//		W_B = 100;
//		E_B = 18;
//		G_B = 7.5;
//		λ_B = 23;
//		V_B = 18;
//		R_B = 0;
//		C1_B = -0.32;
//		C2_B = -0.29;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (M_Si >= 67 && M_Si <= 100 && Fenzibi > 1.5 && Fenzibi <= 4)//不能连续写大小，比如 67<= M_Si<100，这样写会提示出错
//	{
//		//else if (Fenzibi > 1.5 && Fenzibi <= 4)	
//		n_B = 1.72;//折射率
//		nFnC_B = 900 - 65 * (4 - Fenzibi);
//		CTE_B = 12.4*(4 - Fenzibi) - 50;
//		β_B = 150 - 20 * (4 - Fenzibi);
//		W_B = 100 - 10 * (4 - Fenzibi);
//		E_B = 18;
//		G_B = 7.5;
//		λ_B = 23;
//		V_B = 18;
//		R_B = 0;
//		C1_B = -0.32;
//		C2_B = -0.29;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (M_Si >= 67 && M_Si <= 100 && Fenzibi > 1 && Fenzibi <= 1.5)//不能连续写大小，比如 67<= M_Si<100，这样写会提示出错
//	{
//		n_B = 1.72 - 0.16*(1.5 - Fenzibi);//折射率
//		nFnC_B = 900 - 65 * (4 - Fenzibi);     //平均色散
//		CTE_B = 12.4*(4 - Fenzibi) - 50;          //膨胀系数	
//		β_B = 150 - 20 * (4 - Fenzibi);        //折射率温度系数	
//		W_B = 100 - 10 * (4 - Fenzibi);          //热光系数
//		E_B = 18 - (1.5 - Fenzibi);      //弹性模量
//		G_B = 7.5 - 0.5*(1.5 - Fenzibi);   //剪切模量
//		λ_B = 23;
//		V_B = 18 + 10.4*(1.5 - Fenzibi);  //分子体积
//		R_B = 0;
//		C1_B = -0.32 + 0.04*(1.5 - Fenzibi);
//		C2_B = -0.29 + 0.06*(1.5 - Fenzibi);
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (M_Si >= 67 && M_Si <= 100 && Fenzibi > 0.5 && Fenzibi <= 1.0)//不能连续写大小，比如 67<= M_Si<100，这样写会提示出错
//	{
//		n_B = 1.52 + 0.12*(2 - 1 / Fenzibi);//折射率
//		nFnC_B = 900 - 65 * (4 - Fenzibi);     //平均色散
//		CTE_B = 12.4*(4 - Fenzibi) - 50;          //膨胀系数	
//		β_B = 150 - 20 * (4 - Fenzibi);        //折射率温度系数	
//		W_B = 100 - 10 * (4 - Fenzibi);          //热光系数
//		E_B = 10 + 5 * (2 - 1 / Fenzibi);      //弹性模量
//		G_B = 3 + 3 * (2 - 1 / Fenzibi);   //剪切模量	
//		λ_B = 23;
//		V_B = 31 - 7.8*(2 - 1 / Fenzibi);  //分子体积
//		R_B = 0;
//		C1_B = -0.2*(2 - 1 / Fenzibi);         //C1
//		C2_B = -0.19 - 0.3*(2 - 1 / Fenzibi);       //C2
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (M_Si >= 67 && M_Si <= 100 && Fenzibi > 0 && Fenzibi <= 0.5)//不能连续写大小，比如 67<= M_Si<100，这样写会提示出错
//	{
//		n_B = 1.46 + 0.12*Fenzibi;//折射率
//		nFnC_B = 900 - 65 * (4 - Fenzibi);     //平均色散
//		CTE_B = 12.4*(4 - Fenzibi) - 50;          //膨胀系数	
//		β_B = 150 - 20 * (4 - Fenzibi);        //折射率温度系数	
//		W_B = 100 - 10 * (4 - Fenzibi);          //热光系数
//		E_B = 1.8 + 16.4*Fenzibi;     //弹性模量
//		G_B = 0.7 + 4.6*Fenzibi;   //剪切模量
//		λ_B = 23;
//		V_B = 38 - 14 * Fenzibi;  //分子体积
//		R_B = 0;
//		C1_B = 0.328 - 0.656*Fenzibi;
//		C2_B = 0.682 - 0.984*Fenzibi;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//
//	if (40 >= M_Si && M_Si < 67 && Fenzibi > 4)
//	{
//		n_B = 1.72;//折射率
//		nFnC_B = 900;     //平均色散
//		CTE_B = -50;          //膨胀系数
//		β_B = 150;        //折射率温度系数
//		W_B = 100;           //热光系数
//		E_B = 18;      //弹性模量	
//		G_B = 7.5;   //剪切模量
//		λ_B = 23;
//		V_B = 18;  //分子体积
//		R_B = 0;
//		C1_B = -0.32;
//		C2_B = -0.29;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (40 >= M_Si && M_Si < 67 && Fenzibi > 1 && Fenzibi <= 4)
//	{
//		n_B = 1.72 - 0.05*(4 - Fenzibi);//折射率
//		nFnC_B = 900 - 65 * (4 - Fenzibi);  //平均色散
//		E_B = 18 - 2 * (4 - Fenzibi);      //弹性模量
//		β_B = 150 - 20 * (4 - Fenzibi);   //折射率温度系数	
//		W_B = 100 - 10 * (4 - Fenzibi);   //热光系数
//		G_B = 7.5 - 1.2*(4 - Fenzibi);   //剪切模量	
//		CTE_B = 12.4*(4 - Fenzibi) - 50;   //膨胀系数
//		C1_B = -0.32 + 0.08*(4 - Fenzibi);   //C1
//		C2_B = -0.29 + 0.12*(4 - Fenzibi);  //C2
//		V_B = 18 + 3.8*(4 - Fenzibi);  //分子体积
//		λ_B = 23;
//		R_B = 0;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (40 >= M_Si && M_Si < 67 && Fenzibi > 0.5 && Fenzibi <= 1)
//	{
//		n_B = 1.52 + 0.05*(2 - 1 / Fenzibi);//折射率
//		C1_B = -0.08*(2 - 1 / Fenzibi);         //C1
//		C2_B = 0.19 - 0.12*(2 - 1 / Fenzibi);       //C2
//		V_B = 31 - 3 * (2 - 1 / Fenzibi);  //分子体积
//		E_B = 10 + 2 * (2 - 1 / Fenzibi);      //弹性模量
//		G_B = 3 + 3 * (2 - 1 / Fenzibi);   //剪切模量
//		CTE_B = 12.4*(4 - Fenzibi) - 50;          //膨胀系数	
//		β_B = 150 - 20 * (4 - Fenzibi);        //折射率温度系数	
//		W_B = 100 - 10 * (4 - Fenzibi);          //热光系数
//		nFnC_B = 900 - 65 * (4 - Fenzibi);     //平均色散
//		λ_B = 23;
//		R_B = 0;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (40 >= M_Si && M_Si < 67 && Fenzibi > 0 && Fenzibi <= 0.5)
//	{
//		n_B = 1.46 + 0.12*Fenzibi;//折射率
//		C1_B = 0.328 - 0.656*Fenzibi;         //C1
//		C2_B = 0.682 - 0.984*Fenzibi;       //C2
//		V_B = 38 - 14 * Fenzibi;  //分子体积
//		E_B = 1.8 + 16.4*Fenzibi;      //弹性模量
//		G_B = 0.7 + 4.6*Fenzibi;   //剪切模量
//		CTE_B = 12.4*(4 - Fenzibi) - 50;          //膨胀系数	
//		β_B = 150 - 20 * (4 - Fenzibi);        //折射率温度系数	
//		W_B = 100 - 10 * (4 - Fenzibi);          //热光系数
//		nFnC_B = 900 - 65 * (4 - Fenzibi);     //平均色散
//		λ_B = 23;
//		R_B = 0;
//		n2_B = 0;
//		P_B = 0;
//		Q_B = 0;
//	}
//	if (M_Si<40)
//	{
//		MessageBox("B2O3组分中SiO2含量超出核算范围！");
//		return;
//	}
//
//	//4 Al2O3的系数------------------------------------------------------------------------------
//	//double定义的是性质种类，上次文件中是列的两种性质,若修改上次代码，可以随便选两种性质就行了，可以节约点儿时间
//	double n_Al, nFnC_Al, V_Al, E_Al, G_Al, λ_Al, C1_Al, C2_Al, CTE_Al, W_Al, β_Al, R_Al, n2_Al, P_Al, Q_Al;
//	double Fenzibi_Al = ((M_Na + M_K) + 0.8*(M_Li + M_Ba) + 0.6*(M_Pb + M_P + M_Sr) + 0.4*M_Ca + 0.2*(M_Zn + M_Mg) - (M_Al + M_B)) / M_Al;
//	//定义组分为零时，分子比中分母为零的情况
//	if (M_Al == 0)
//	{
//		Fenzibi_Al = 0;
//	}
//
//	if (M_Al <= 80 && M_Li <= 0 && M_Na <= 0 && M_K <= 0 && M_P <= 0 && M_Ba <= 0 && Fenzibi_Al > 1)
//	{
//		n_Al = 1.68;
//		nFnC_Al = 1070;
//		CTE_Al = 16;
//		β_Al = 220;
//		W_Al = 200;
//		E_Al = 11;
//		G_Al = 4.5;
//		λ_Al = 24;
//		V_Al = 30;
//		R_Al = 11.34;
//		C1_Al = -0.04;
//		C2_Al = 0.13;
//		n2_Al = 16.9;
//		P_Al = 19.01;
//		Q_Al = -0.48;
//	}
//	if (M_Al <= 80 && M_Li <= 0 && M_Na <= 0 && M_K <= 0 && M_P <= 0 && M_Ba <= 0 && Fenzibi_Al < 1)
//	{
//		n_Al = 1.68 - 0.16*Fenzibi_Al;
//		V_Al = 30 + 11 * Fenzibi_Al;
//		nFnC_Al = 1070 - 220 * Fenzibi_Al;
//		CTE_Al = 36 - 76 * Fenzibi_Al;
//		β_Al = 220;
//		W_Al = 200;
//		E_Al = 11;
//		G_Al = 4.5;
//		λ_Al = 24;
//		R_Al = 11.34;
//		C1_Al = -0.04;
//		C2_Al = 0.13;
//		n2_Al = 16.9;
//		P_Al = 19.01;
//		Q_Al = -0.48;
//	}
//	if (M_Al <= 80 && M_Li > 0 || M_Na > 0 || M_K > 0)
//	{
//		n_Al = 1.52;
//		nFnC_Al = 850;
//		CTE_Al = -40;
//		β_Al = 200;
//		W_Al = 180;
//		E_Al = 11;
//		G_Al = 4.5;
//		λ_Al = 24;
//		V_Al = 41;
//		R_Al = 12.5;
//		C1_Al = -0.04;
//		C2_Al = 0.13;
//		n2_Al = 16.9;
//		P_Al = 19.01;
//		Q_Al = -0.43;
//	}
//	if (M_Al>80)
//	{
//		MessageBox("Al2O3超出核算范围，请检视！！");
//		return;
//	}
//	//SiO2的系数----------------------------------------------------------------------------------------------
//	//double定义的是性质种类，上次文件中是列的两种性质,若修改上次代码，可以随便选两种性质就行了，可以节约点儿时间
//	double n_Si, CTE_Si, C1_Si, C2_Si, V_Si, E_Si, β_Si, n2_Si, G_Si, W_Si, P_Si, R_Si, Q_Si, nFnC_Si, λ_Si;
//	if (M_Si > 67 && M_Si <= 100)
//	{
//		n_Si = 1.475 - 0.0005*(M_Si - 67);//折射率
//		CTE_Si = 35 - (M_Si - 67);          //膨胀系数
//		C1_Si = 0.207 - 0.001*M_Si;         //C1
//		C2_Si = 0.5005 - 0.0015*M_Si;       //C2
//		V_Si = 26.1 + 0.035*(M_Si - 67);  //分子体积
//		E_Si = 6.5 + 0.025*(M_Si - 67);      //弹性模量
//		β_Si = 70 + (M_Si - 67);        //折射率温度系数
//		n2_Si = 11.1 - 0.04*(M_Si - 67); //非线性折射率
//		G_Si = 2.75 + 0.013*(M_Si - 67);   //剪切模量
//		W_Si = 85 + 0.6*(M_Si - 67);           //热光系数
//		P_Si = 8.85 + 0.045*(M_Si - 67);       //应力热光系数
//		R_Si = 7.55 + 0.08*(100 - M_Si);   //分子折射度
//		Q_Si = 0.36 - 0.0102*(M_Si - 67);      //应力双折射系数
//		nFnC_Si = 660 + 0.55*(M_Si - 67);     //平均色散	
//		λ_Si = 31.5 - (100 - M_Si)*0.05;
//	}
//	if (M_Si > 34 && M_Si <= 67)
//	{
//		n_Si = 1.475 - 0.000475*(67 - M_Si);//折射率
//		CTE_Si = 35 + 0.5* (67 - M_Si);          //膨胀系数
//		C1_Si = 0.1641 - 0.00038*M_Si;         //C1
//		C2_Si = 0.4362 - 0.00054*M_Si;       //C2
//		V_Si = 26.1 + 0.032*(67 - M_Si);  //分子体积
//		E_Si = 6.5 - 0.009*(67 - M_Si);      //弹性模量
//		β_Si = 70 - 0.5* (67 - M_Si);        //折射率温度系数
//		n2_Si = 11.1; //非线性折射率
//		G_Si = 2.75 - 0.003*(67 - M_Si);   //剪切模量
//		W_Si = 85 - 0.1*(M_Si - 67);           //热光系数
//		P_Si = 8.04 + 0.025*(M_Si - 34);       //应力热光系数
//		R_Si = 7.55 + 0.08*(100 - M_Si);   //分子折射度
//		Q_Si = 0.52 - 0.00485*(M_Si - 34);      //应力双折射系数
//		nFnC_Si = 660 - 1.2*(67 - M_Si);     //平均色散
//		λ_Si = 31.5 - (100 - M_Si)*0.05;
//
//	}
//	if (M_Si > 0 && M_Si <= 34)
//	{
//		n_Si = 1.46;//折射率
//		CTE_Si = 52;     //膨胀系数
//		C1_Si = 0.152;   //C1
//		C2_Si = 0.418;   //C2
//		V_Si = 27.2;  //分子体积
//		E_Si = 6.2;   //弹性模量
//		β_Si = 58;   //折射率温度系数
//		n2_Si = 11.1; //非线性折射率
//		G_Si = 2.65;   //剪切模量
//		W_Si = 82.8;   //热光系数
//		P_Si = 8.04;   //应力热光系数
//		R_Si = 7.45;   //分子折射度
//		Q_Si = 0.52;   //应力双折射系数
//		nFnC_Si = 620; //平均色散
//		λ_Si = 29;
//	}
//
//	//这里是计算公式：性质=计算系数*换算后的截段数据
//	//1.折射率计算
//	double nD = (M_Si*n_Si + M_Al*n_Al +  M_Ca*n_Ca  + M_Na*n_Na + M_B*n_B / 100;
//	//2.密度计算
//	double Sum_Zuhe = atof(Zu_Si) + atof(Zu_Al) +  atof(Zu_Ca) + atof(Zu_Na) + atof(Zu_B) ;
//	double Mi_Xishu = mol_Si*V_Si + mol_Al*V_Al + mol_Ca*V_Ca + mol_Na*V_Na + mol_B*V_B;
//	double Midu = Sum_Zuhe / Mi_Xishu;//密度性质计算结果
//	//3.膨胀系数
//	double CTE = (M_Si*CTE_Si + M_Al*CTE_Al +  M_Ca*CTE_Ca + M_Na*CTE_Na + M_B*CTE_B / 100;
//}