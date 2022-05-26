// ThumbTipsView.h : interface of the CThumbTipsView class
//


#pragma once
#include "afxcmn.h"
#include "TipListCtrl.h"

class CThumbTipsView : public CFormView
{
protected: // create from serialization only
	CThumbTipsView();
	DECLARE_DYNCREATE(CThumbTipsView)

public:
	enum{ IDD = IDD_THUMBTIPS_FORM };

// Attributes
public:
	CThumbTipsDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	void PopulateListCtrl();

// Implementation
public:
	virtual ~CThumbTipsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTipListCtrl m_listCtrl;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in ThumbTipsView.cpp
inline CThumbTipsDoc* CThumbTipsView::GetDocument() const
   { return reinterpret_cast<CThumbTipsDoc*>(m_pDocument); }
#endif

