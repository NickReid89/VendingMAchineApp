
// ReidOOPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReidOOP.h"
#include "ReidOOPDlg.h"
#include "afxdialogex.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CReidOOPDlg dialog




CReidOOPDlg::CReidOOPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CReidOOPDlg::IDD, pParent)
	, m_txtDollarDrop(0)
	, m_txtQuartDrop(0)
	, m_txtDimeDrop(0)
	, m_txtNickleDrop(0)
	, m_txtTotalDrop(0)
	, m_txtDollar(0)
	, m_txtQuarter(0)
	, m_txtDime(0)
	, m_txtNickle(0)
	, m_txtCoinTotal(0)
	, m_txtColaTotal(0)
	, m_txtDietColaTotal(0)
	, m_txtOrangeTotal(0)
	, m_txtRootBeerTotal(0)
	, m_txtDispenseSlot(_T(""))
	, m_txtCoinReturn(0)
	, m_txtReturnDollar(0)
	, m_txtReturnQuarter(0)
	, m_txtReturnDime(0)
	, m_txtReturnNickle(0)
	, m_radSelected(0)
	, m_chkService(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReidOOPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_txtDollarDrop, m_txtDollarDrop);
	DDX_Text(pDX, IDC_txtQuartdrop, m_txtQuartDrop);
	DDX_Text(pDX, IDC_txtDimeDrop, m_txtDimeDrop);
	DDX_Text(pDX, IDC_txtNickleDrop, m_txtNickleDrop);
	DDX_Text(pDX, IDC_txtTotalDrop, m_txtTotalDrop);
	DDX_Text(pDX, IDC_txtDollar, m_txtDollar);
	DDX_Text(pDX, IDC_txtQuarter, m_txtQuarter);
	DDX_Text(pDX, IDC_txtDime, m_txtDime);
	DDX_Text(pDX, IDC_txtNickle, m_txtNickle);
	DDX_Text(pDX, IDC_txtCoinTotal, m_txtCoinTotal);
	DDX_Text(pDX, IDC_txtColaTotal, m_txtColaTotal);
	DDX_Text(pDX, IDC_txtDietColaTotal, m_txtDietColaTotal);
	DDX_Text(pDX, IDC_txtOrangeTotal, m_txtOrangeTotal);
	DDX_Text(pDX, IDC_txtRootBeerTotal, m_txtRootBeerTotal);
	DDX_Text(pDX, IDC_txtDispenseSlot, m_txtDispenseSlot);
	DDX_Text(pDX, IDC_txtCoinReturn, m_txtCoinReturn);
	DDX_Text(pDX, IDC_txtReturnDollar, m_txtReturnDollar);
	DDX_Text(pDX, IDC_txtReturnQuarter, m_txtReturnQuarter);
	DDX_Text(pDX, IDC_txtReturnDime, m_txtReturnDime);
	DDX_Text(pDX, IDC_txtReturnNickle, m_txtReturnNickle);
	// Checks to see if there is pop in the machine.
	IfNoPop();
	DDX_Check(pDX, IDC_chkServiceMachine, m_chkService);
}

BEGIN_MESSAGE_MAP(CReidOOPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_cmdEnterDollar, &CReidOOPDlg::OnBnClickedcmdenterdollar)
	ON_BN_CLICKED(IDC_cmdEnterQuarter, &CReidOOPDlg::OnBnClickedcmdenterquarter)
	ON_BN_CLICKED(IDC_cmdEnterDime, &CReidOOPDlg::OnBnClickedcmdenterdime)
	ON_BN_CLICKED(IDC_cmdEnterNickle, &CReidOOPDlg::OnBnClickedcmdenternickle)
	ON_BN_CLICKED(IDC_cmdEnterCola, &CReidOOPDlg::OnBnClickedcmdentercola)
	ON_BN_CLICKED(IDC_cmdEnterDietCola, &CReidOOPDlg::OnBnClickedcmdenterdietcola)
	ON_BN_CLICKED(IDC_cmdEnterOrange, &CReidOOPDlg::OnBnClickedcmdenterorange)
	ON_BN_CLICKED(IDC_cmdEnterRootBeer, &CReidOOPDlg::OnBnClickedcmdenterrootbeer)
	ON_BN_CLICKED(IDC_cmdServiceDollar, &CReidOOPDlg::OnBnClickedcmdservicedollar)
	ON_BN_CLICKED(IDC_cmdSerivceQuarter, &CReidOOPDlg::OnBnClickedcmdserivcequarter)
	ON_BN_CLICKED(IDC_cmdServiceDime, &CReidOOPDlg::OnBnClickedcmdservicedime)
	ON_BN_CLICKED(IDC_cmdServiceNickle, &CReidOOPDlg::OnBnClickedcmdservicenickle)
	ON_BN_CLICKED(IDC_cmdTakeDollar, &CReidOOPDlg::OnBnClickedcmdtakedollar)
	ON_BN_CLICKED(IDC_cmdTakeQuater, &CReidOOPDlg::OnBnClickedcmdtakequater)
	ON_BN_CLICKED(IDC_cmdTakeDime, &CReidOOPDlg::OnBnClickedcmdtakedime)
	ON_BN_CLICKED(IDC_cmdTakeNickle, &CReidOOPDlg::OnBnClickedcmdtakenickle)
	ON_BN_CLICKED(IDC_radCoinReturn, &CReidOOPDlg::OnBnClickedradcoinreturn)
	ON_BN_CLICKED(IDC_radCola, &CReidOOPDlg::OnBnClickedradcola)
	ON_BN_CLICKED(IDC_radDietCola, &CReidOOPDlg::OnBnClickedraddietcola)
	ON_BN_CLICKED(IDC_radOrange, &CReidOOPDlg::OnBnClickedradorange)
	ON_BN_CLICKED(IDC_radRootBeer, &CReidOOPDlg::OnBnClickedradrootbeer)
	ON_BN_CLICKED(IDC_chkServiceMachine, &CReidOOPDlg::OnBnClickedchkservicemachine)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CReidOOPDlg message handlers

BOOL CReidOOPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReidOOPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReidOOPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CReidOOPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReidOOPDlg::OnBnClickedcmdenterdollar()
{
	// Adds a user dollar to the machine.
	m_txtDollar++;
	UpdateCoinsEnteredTotal();
	
}


void CReidOOPDlg::OnBnClickedcmdenterquarter()
{
	// Adds a users quarter to the machine
	m_txtQuarter++;
	UpdateCoinsEnteredTotal();
}


void CReidOOPDlg::OnBnClickedcmdenterdime()
{
	// Adds a users dime to the machine
	m_txtDime++;
	UpdateCoinsEnteredTotal();
}


void CReidOOPDlg::OnBnClickedcmdenternickle()
{
	// Adds a user nickle to the machine.
	m_txtNickle++;
	UpdateCoinsEnteredTotal();
}


void CReidOOPDlg::OnBnClickedcmdentercola()
{

	// Adds a can of a cola to the machine.
	m_txtColaTotal++;
	UpdateData(FALSE);
}


void CReidOOPDlg::OnBnClickedcmdenterdietcola()
{
	// Adds a can of Diet Cola to the machine.
	m_txtDietColaTotal++;
	UpdateData(FALSE);
}


void CReidOOPDlg::OnBnClickedcmdenterorange()
{
	// Adds a can of Orange Cola to the machine.
	m_txtOrangeTotal++;
	UpdateData(FALSE);
}


void CReidOOPDlg::OnBnClickedcmdenterrootbeer()
{
	// Adds a can of Root Beer to the machine.
	m_txtRootBeerTotal++;
	UpdateData(FALSE);
}


void CReidOOPDlg::OnBnClickedcmdservicedollar()
{
	//Enables the button to take away dollars.
	GetDlgItem(IDC_cmdTakeDollar)->EnableWindow(TRUE);
	// Adds a dollar to the machine.
	m_txtDollarDrop++;
	UpdateCoinStackTotal();
}


void CReidOOPDlg::OnBnClickedcmdserivcequarter()
{
	//Enables the button to take away quarters.
	GetDlgItem(IDC_cmdTakeQuater)->EnableWindow(TRUE);
	// Adds a quarter to the machine
	m_txtQuartDrop++;
	UpdateCoinStackTotal();

}


void CReidOOPDlg::OnBnClickedcmdservicedime()
{
	//Enables the button to take away dimes.
	GetDlgItem(IDC_cmdTakeDime)->EnableWindow(TRUE);
	// Adds a dime to the machine.
	m_txtDimeDrop++;
	UpdateCoinStackTotal();
}


void CReidOOPDlg::OnBnClickedcmdservicenickle()
{
	//Enables the button to take away nickles.
	GetDlgItem(IDC_cmdTakeNickle)->EnableWindow(TRUE);
	// Adds a nickle to the machine.
	m_txtNickleDrop++;
	UpdateCoinStackTotal();
}


void CReidOOPDlg::OnBnClickedcmdtakedollar()
{
	// Takes a dollar from the machine.


	if (m_txtDollarDrop >= 1){
	m_txtDollarDrop--;
	UpdateCoinStackTotal();
	}
	// IF there is no dollar left in the machine disable the button to take away dollars.
	if(m_txtDollarDrop == 0){
		GetDlgItem(IDC_cmdTakeDollar)->EnableWindow(FALSE);
	}
}


void CReidOOPDlg::OnBnClickedcmdtakequater()
{
	// Takes out a quarter from the machine.
	if (m_txtQuartDrop >= 1){
	m_txtQuartDrop--;
	UpdateCoinStackTotal();
	}
	// IF there is no quarters left in the machine disable the button to take away quarters.
	if(m_txtQuartDrop == 0){
		GetDlgItem(IDC_cmdTakeQuater)->EnableWindow(FALSE);
	}
}


void CReidOOPDlg::OnBnClickedcmdtakedime()
{
	// Takes out a Dime from the machine.

	if (m_txtDimeDrop >= 1){
	m_txtDimeDrop--;
	UpdateCoinStackTotal();
	}
	// If there is no dimes left in the machine disable the button to take away dimes.
	if(m_txtDimeDrop == 0){
		GetDlgItem(IDC_cmdTakeDime)->EnableWindow(FALSE);
	}
}


void CReidOOPDlg::OnBnClickedcmdtakenickle()
{
	// Takes out a nickle from the machine.

	if (m_txtNickleDrop >= 1) {
	m_txtNickleDrop--;
	UpdateCoinStackTotal();
	}
	// If there is no nickles left in the machine disable the button to take away nickles.
	if(m_txtNickleDrop == 0){
		GetDlgItem(IDC_cmdTakeNickle)->EnableWindow(FALSE);
	}
}


// Calculate $ amount ofcontents of CoinStack


void CReidOOPDlg::UpdateCoinStackTotal(void)
{
	// Updates the coins in the machine to give a dollar value.
	m_txtTotalDrop = ((m_txtDollarDrop * 1.00) + (m_txtQuartDrop * 0.25) + (m_txtDimeDrop * 0.10) + (m_txtNickleDrop * 0.05));
	UpdateData(FALSE);
}


// The total amount of coins entered.
void CReidOOPDlg::UpdateCoinsEnteredTotal(void)
{
	// Updates the coins the user entered for an dollar value.
	m_txtCoinTotal = ((m_txtDollar * 1.00) + (m_txtQuarter * 0.25) + (m_txtDime * 0.10) + (m_txtNickle * 0.05));
	UpdateData(FALSE);
}


// Returns change to user.
void CReidOOPDlg::Dispense(void)
{
	
	enum ACTION {COLA,DIET, ORANGE,ROOT, COINRETURN } ButtonPressed;
	// Checks to see which button was pressed.
	ButtonPressed = (ACTION) m_radSelected;
	// resets the dispense slot.
	m_txtDispenseSlot = "";
	m_txtReturnDollar = 0;
	m_txtReturnQuarter = 0;
	m_txtReturnDime = 0;
	m_txtReturnNickle = 0;

	// Returns coins to the user.
	if(ButtonPressed == COINRETURN){
		// If there is nothing in the machine they don't get the kerching sign.
		if(m_txtCoinTotal != 0){
			m_txtDispenseSlot = "Kerching!";
		}
		// Takes the users change and put it in the machine.
		m_txtCoinReturn = m_txtCoinTotal;
		m_txtReturnDollar = m_txtDollar;
		m_txtReturnQuarter = m_txtQuarter;
		m_txtReturnDime = m_txtDime;
		m_txtReturnNickle = m_txtNickle;
		ChangeDeposit();
		return;
	}

	// IF the user has too much change in the machine.
	if(m_txtCoinTotal * 100 > 105){	
			m_txtCoinReturn = m_txtCoinTotal;
			m_txtReturnDollar = m_txtDollar;
			m_txtReturnQuarter = m_txtQuarter;
			m_txtReturnDime = m_txtDime;
			m_txtReturnNickle = m_txtNickle;
			// Message to user.
			InsufficientFunds();
		}
		// if the user has to little money.
	else if((m_txtCoinTotal * 100) < 105){
		InsufficientFunds();
	}
	else{

	// Tells the user there is no pop.
	if(ButtonPressed == COLA  && m_txtColaTotal == 0){
		InsufficientFunds();
	}
	if(ButtonPressed == DIET  && m_txtDietColaTotal == 0){
		InsufficientFunds();
	}
	if(ButtonPressed == ORANGE  && m_txtOrangeTotal == 0){
		InsufficientFunds();
	}
	if(ButtonPressed == ROOT  && m_txtRootBeerTotal == 0){
		InsufficientFunds();
	}

	// Dispenses sode from machine.
	if(ButtonPressed == COLA && m_txtColaTotal >= 1){
		m_txtColaTotal --;
		PopDrop();
	}
	if(ButtonPressed == DIET && m_txtDietColaTotal >= 1){
		m_txtDietColaTotal --;
		PopDrop();
	}
	if(ButtonPressed == ORANGE && m_txtOrangeTotal >= 1){
		m_txtOrangeTotal--;
		PopDrop();
	}
	if(ButtonPressed == ROOT && m_txtRootBeerTotal >= 1){
		m_txtRootBeerTotal--;
		PopDrop();
		
	}
	}
}


void CReidOOPDlg::OnBnClickedradcoinreturn()
{
	// Sets the radio selection to return the change.
	CheckDlgButton(IDC_radCoinReturn, BST_UNCHECKED);
	m_radSelected=4;
	Dispense();


}

void CReidOOPDlg::OnBnClickedradcola()
{
	// Sets selection to request a Cola.
	m_radSelected=0;
	Dispense();
}


void CReidOOPDlg::OnBnClickedraddietcola()
{
	// Sets selection to request a Diet Cola.
	m_radSelected=1;
	Dispense();
}


void CReidOOPDlg::OnBnClickedradorange()
{
	// Sets selection to request an Orange soda.
	m_radSelected=2;
	Dispense();
}


void CReidOOPDlg::OnBnClickedradrootbeer()
{
	// Sets selection to request a Root Beer.
	m_radSelected=3;
	Dispense();
}


// resets the user change slots.
void CReidOOPDlg::ChangeDeposit(void)
{
	//Incoming: Nothing
	//Outgoing: Nothing
	//Responsibilies: Takes the coins that would be entered by the user
	//				  and resets them.
		 m_txtDollar = 0;
		 m_txtQuarter = 0;
		 m_txtDime = 0;
		 m_txtNickle = 0;
		 m_txtCoinTotal = 0;
		 UpdateData(FALSE);	
}

void CReidOOPDlg::InsufficientFunds(void)
{
	//Incoming: Nothing
	//Outgoing: Nothing
	//Responsibilites: Tells the user they do not have enough money.
	 MessageBox( "Exact change only, please.", "Sorry!", MB_ICONSTOP); 
		m_radSelected = 4;
		UpdateData(FALSE);
		Dispense();
		return;
}


// Disables the buttons if there is no pop.
void CReidOOPDlg::IfNoPop(void)
{
	//Incoming: Nothing
	//Outgoing: Nothing.
	/*Responsibilites: for each of the controls below if the pop in the machine runs out, it 
	   disables being able to press for another as well unchecks the radio button.
	*/
	if (m_txtColaTotal == 0){
		GetDlgItem(IDC_radCola)->EnableWindow(FALSE);
		CheckDlgButton(IDC_radCola, BST_UNCHECKED);
	}
	else
	{
		GetDlgItem(IDC_radCola)->EnableWindow(TRUE);
	}

	if (m_txtDietColaTotal == 0){
		GetDlgItem(IDC_radDietCola)->EnableWindow(FALSE);
		CheckDlgButton(IDC_radDietCola, BST_UNCHECKED);
	}
	else{
		GetDlgItem(IDC_radDietCola)->EnableWindow(TRUE);
	}

	if(m_txtOrangeTotal == 0){
		GetDlgItem(IDC_radOrange)->EnableWindow(FALSE);
		CheckDlgButton(IDC_radOrange, BST_UNCHECKED);
	}
	else{
		GetDlgItem(IDC_radOrange)->EnableWindow(TRUE);
	}

	if(m_txtRootBeerTotal == 0){
		GetDlgItem(IDC_radRootBeer)->EnableWindow(FALSE);
		CheckDlgButton(IDC_radRootBeer, BST_UNCHECKED);
	}
	else{
		GetDlgItem(IDC_radRootBeer)->EnableWindow(TRUE);
	}
}

void CReidOOPDlg::OnBnClickedchkservicemachine()
{		

		int Result;
		CPassword PW;
		// DoModal “pops up” the Password Dialog
		// When you click on the OK button, it puts IDOK into the Result variable
		// When you click on the Cancel button, it puts IDCANCEL into the Result variable
		// if false it prompts for a password, else it finishes servicing the machine.
		if(m_chkService == false){

		Result = PW.DoModal();
		// In case the password is wrong.
		if(Result == IDOK){
				if (PW.m_txtPassword != "Password") {
			MessageBox( "Incorrect Password!",
			"Security Violation",
			MB_ICONSTOP );
			m_chkService=FALSE; UpdateData(FALSE);
			return;
		}
		}
		// Password input successful.
		else{
			m_chkService = true;
			// This chages the button state of the check box to unchecked.
			CheckDlgButton(IDC_chkServiceMachine, BST_UNCHECKED);
		}
		}



	

	// Shows the services buttons.
	if(m_chkService == false){
		GetDlgItem(IDC_cmdEnterCola)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdEnterDietCola)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdEnterOrange)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdEnterRootBeer)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdServiceDollar)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdSerivceQuarter)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdServiceDime)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdServiceNickle)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdTakeDollar)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdTakeQuater)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdTakeDime)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cmdTakeNickle)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_cboSetColaPrice)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_grpService)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_grpCoinStacks)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_txtDollarDrop)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_txtQuartdrop)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_txtDimeDrop)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_txtNickleDrop)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_txtTotalDrop)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_lblDollarOne)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_lstVendInfo)->ShowWindow(SW_SHOW);
	}
	// Hides all the service buttons.
	else{
	GetDlgItem(IDC_cmdEnterCola)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdEnterDietCola)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdEnterOrange)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdEnterRootBeer)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdServiceDollar)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdSerivceQuarter)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdServiceDime)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdServiceNickle)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdTakeDollar)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdTakeQuater)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdTakeDime)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cmdTakeNickle)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_cboSetColaPrice)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_grpService)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_grpCoinStacks)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_txtDollarDrop)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_txtQuartdrop)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_txtDimeDrop)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_txtNickleDrop)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_txtTotalDrop)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_lblDollarOne)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_lstVendInfo)->ShowWindow(SW_HIDE);
	m_chkService == true;
	}
	// checks for user input.
	UpdateData(TRUE);
}


// Gives the user pop as well adds money to the machine and sends a message to the dispense slot.
void CReidOOPDlg::PopDrop(void)
{
		// Dispense slot displays status.
		m_txtDispenseSlot = "Klunk";
		// Adds coin to the machine.
		m_txtDollarDrop += m_txtDollar;
		m_txtNickleDrop += m_txtNickle;
		m_txtQuartDrop += m_txtQuarter;
		m_txtDimeDrop += m_txtDime;
		// updates total
		UpdateCoinStackTotal();
		//Resets so the user can put in more change.
		ChangeDeposit();

	// this disables the button that takes away a dollar.
	if(m_txtDollarDrop == 0){
		GetDlgItem(IDC_cmdTakeDollar)->EnableWindow(FALSE);
	}
	// this enables the button that takes away a dollar.
	else{
		GetDlgItem(IDC_cmdTakeDollar)->EnableWindow(TRUE);
	}
	// this disables the button that takes away a quarter.
	if(m_txtQuartDrop == 0){
		GetDlgItem(IDC_cmdTakeQuater)->EnableWindow(FALSE);
	}
	// this enables the button that takes away a quarter
	else{
		GetDlgItem(IDC_cmdTakeQuater)->EnableWindow(TRUE);
	}
	// this disables the button that takes away a dime.
	if(m_txtDimeDrop == 0){
		GetDlgItem(IDC_cmdTakeDime)->EnableWindow(FALSE);
	}
	// this enables the button that takes away a dollar.
	else{
		GetDlgItem(IDC_cmdTakeDime)->EnableWindow(TRUE);
	}
	// this disables the button that takes away a nickle.
	if(m_txtNickleDrop == 0){
		GetDlgItem(IDC_cmdTakeNickle)->EnableWindow(FALSE);
	}
	// this enables the button that takes away a nickle.
	else{
		GetDlgItem(IDC_cmdTakeNickle)->EnableWindow(TRUE);
	}


}


void CReidOOPDlg::OnClose()
{
	// Closing dialogue for user.
	int Result;
		Result = MessageBox(
		"Thanks for your patronage!\nAre you sure you want to exit?",
		"Orville says...",
		MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2);
	if (Result == IDYES) CDialog::OnClose();
}
