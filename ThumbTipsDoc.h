// ThumbTipsDoc.h : interface of the CThumbTipsDoc class
//


#pragma once

class CThumbTipsDoc : public CDocument
{
protected: // create from serialization only
	CThumbTipsDoc();
	DECLARE_DYNCREATE(CThumbTipsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CThumbTipsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


