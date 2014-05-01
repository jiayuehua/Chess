#if !defined(AFX_NET_H__2292CCBA_1235_4277_8084_28CC67DBFA2E__INCLUDED_)
#define AFX_NET_H__2292CCBA_1235_4277_8084_28CC67DBFA2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Net.h : header file
//
class NetControl;

/////////////////////////////////////////////////////////////////////////////
// CNet command target

class CNet : public CSocket
{
// Attributes
public:

// Operations
public:
	CNet();
	CNet(NetControl *m_Ncc);
	virtual ~CNet();

// Overrides
public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnAccept(int nErrorCode);
	NetControl *m_Nc;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNet)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NET_H__2292CCBA_1235_4277_8084_28CC67DBFA2E__INCLUDED_)
