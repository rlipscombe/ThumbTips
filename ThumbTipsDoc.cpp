// ThumbTipsDoc.cpp : implementation of the CThumbTipsDoc class
//

#include "stdafx.h"
#include "ThumbTips.h"

#include "ThumbTipsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThumbTipsDoc

IMPLEMENT_DYNCREATE(CThumbTipsDoc, CDocument)

BEGIN_MESSAGE_MAP(CThumbTipsDoc, CDocument)
END_MESSAGE_MAP()


// CThumbTipsDoc construction/destruction

CThumbTipsDoc::CThumbTipsDoc()
{
	// TODO: add one-time construction code here

}

CThumbTipsDoc::~CThumbTipsDoc()
{
}

BOOL CThumbTipsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CThumbTipsDoc serialization

void CThumbTipsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CThumbTipsDoc diagnostics

#ifdef _DEBUG
void CThumbTipsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CThumbTipsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CThumbTipsDoc commands
