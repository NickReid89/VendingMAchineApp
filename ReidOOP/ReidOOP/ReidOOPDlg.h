
// ReidOOPDlg.h : header file
//

#pragma once


// CReidOOPDlg dialog
class CReidOOPDlg : public CDialogEx
{
// Construction
public:
	CReidOOPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_REIDOOP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit13();
	afx_msg void OnLbnSelchangeList13();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedbtndietcola();
	// Controls the dollars IN the machine
	UINT m_txtDollarDrop;
	// Controls the quarters IN the machine
	UINT m_txtQuartDrop;
	// Controls the dimes IN the machine
	UINT m_txtDimeDrop;
	// Controls the nickles IN the machine
	UINT m_txtNickleDrop;
	// Controls the total amount of change IN the machine.
	double m_txtTotalDrop;
	// User controled dollars  the user places in the machine
	UINT m_txtDollar;
	// The amount of nickles returned to a user
	UINT m_txtReturnNickle;
	// User controled quarters in the machine
	UINT m_txtQuarter;
	// User controled dimes in the machine.
	UINT m_txtDime;
	afx_msg void OnEnChangetxtdollardrop();
	// User controled nickles in the machine.
	UINT m_txtNickle;
	afx_msg void OnEnChangetxttotaldrop();
	// Amount of user coins in the machine.
	double m_txtCoinTotal;
	// Controls the amount of cola in the machine.
	UINT m_txtColaTotal;
	// Controls the amount of diet cola in the machine.
	UINT m_txtDietColaTotal;
	// Controls the amount of Orange pop in the machine.
	UINT m_txtOrangeTotal;
	// Controls the amount of Root Beer in the machine.
	UINT m_txtRootBeerTotal;
	// Shows if transaction was successful.
	CString m_txtDispenseSlot;
	// Shows amount of dimes return to user.
	UINT m_txtReturnDime;
	// Shows amount of quarters returned to user.
	UINT m_txtReturnQuarter;
	// Shows amount of dollars returnd to user.
	UINT m_txtReturnDollar;
	// Shows amount of change returned to user.
	double m_txtCoinReturn;

	// group of radio buttons for use of cola.
	int m_radSelected;
	afx_msg void OnBnClickedcmdenterdollar();
	afx_msg void OnBnClickedcmdenterquarter();
	afx_msg void OnBnClickedcmdenterdime();
	afx_msg void OnBnClickedcmdenternickle();
	afx_msg void OnBnClickedcmdentercola();
	afx_msg void OnBnClickedcmdenterdietcola();
	afx_msg void OnBnClickedcmdenterorange();
	afx_msg void OnBnClickedcmdenterrootbeer();
	afx_msg void OnBnClickedcmdservicedollar();
	afx_msg void OnBnClickedcmdserivcequarter();
	afx_msg void OnBnClickedcmdservicedime();
	afx_msg void OnBnClickedcmdservicenickle();
	afx_msg void OnBnClickedcmdtakedollar();
	afx_msg void OnBnClickedcmdtakequater();
	afx_msg void OnBnClickedcmdtakedime();
	afx_msg void OnBnClickedcmdtakenickle();
	// Calculate $ amount of contents ofCoinStack
	void UpdateCoinStackTotal(void);
	// The total amount of coins entered.
	void UpdateCoinsEnteredTotal(void);
	// Returns change to user.
	void Dispense(void);
	afx_msg void OnBnClickedradcoinreturn();
	afx_msg void OnBnClickedradcola();
	afx_msg void OnBnClickedraddietcola();
	afx_msg void OnBnClickedradorange();
	afx_msg void OnBnClickedradrootbeer();
	// Takes money away from the machine.
	void ChangeDeposit(void);
	// Tells the user they do not have enough money
	void InsufficientFunds(void);
	// Disables the buttons if there is no pop.
	void IfNoPop(void);
	afx_msg void OnBnClickedchkservicemachine();
	// Allows service on machine.
	BOOL m_chkService;
	// Gives the user pop as well adds money to the machine.
	void PopDrop(void);
	afx_msg void OnClose();
};
