// TipListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ThumbTips.h"
#include "TipListCtrl.h"
#include ".\tiplistctrl.h"


// TipListCtrl

IMPLEMENT_DYNAMIC(CTipListCtrl, CListCtrl)

CTipListCtrl::CTipListCtrl()
	: m_pToolTipCtrl(NULL)
{
}

CTipListCtrl::~CTipListCtrl()
{
}


BEGIN_MESSAGE_MAP(CTipListCtrl, CListCtrl)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()



// TipListCtrl message handlers
void CTipListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (nSBCode == SB_THUMBTRACK)
	{
		SCROLLINFO si;
		VERIFY(GetScrollInfo(SB_VERT, &si, SIF_ALL));

		CString s = GetThumbTrackToolTipText(si.nPos, si.nTrackPos);
		DisplayThumbTrackToolTip(s);
	}
	else if (nSBCode == SB_THUMBPOSITION)
	{
		DestroyThumbTrackToolTip();
	}

	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CTipListCtrl::FillToolInfo(TOOLINFO *ti)
{
    memset(ti, 0, sizeof(TOOLINFO));
    ti->cbSize = sizeof(TOOLINFO);
    ti->hwnd = GetParent()->GetSafeHwnd();
    ti->uFlags = TTF_IDISHWND | TTF_ABSOLUTE | TTF_TRACK;
    ti->uId = reinterpret_cast<UINT_PTR>(GetSafeHwnd());
}

void CTipListCtrl::DisplayThumbTrackToolTip(const char *toolTipText)
{
    if (!CreateThumbTrackToolTip())
        return;

    /* Move the tooltip off the screen, so that it doesn't flicker when
     * it's resized with the new text.
     */
    int xOffScreen = -4000;
    int yOffScreen = -4000;
    m_pToolTipCtrl->SendMessage(TTM_TRACKPOSITION, 0, MAKELONG(xOffScreen, yOffScreen));

    TOOLINFO ti;
    FillToolInfo(&ti);
    m_pToolTipCtrl->SendMessage(TTM_TRACKACTIVATE, TRUE, (LPARAM)&ti);

    m_toolTipText = toolTipText;
    m_pToolTipCtrl->UpdateTipText(m_toolTipText, this);

    AdjustThumbTrackToolTipPosition();
}

BOOL CTipListCtrl::CreateThumbTrackToolTip()
{
    if (m_pToolTipCtrl)
        return TRUE;	// Already created.

    m_pToolTipCtrl = new CToolTipCtrl;
    if (m_pToolTipCtrl && m_pToolTipCtrl->Create(this))
    {
        TOOLINFO ti;
        FillToolInfo(&ti);

        // We have to use SendMessage, because CToolTipCtrl::AddTool doesn't pass all of the flags.
        m_pToolTipCtrl->SendMessage(TTM_ADDTOOL, 0, (LPARAM)&ti);
        m_pToolTipCtrl->SetDelayTime(TTDT_AUTOPOP, SHRT_MAX);   // stop the tooltip coming up automatically
        m_pToolTipCtrl->SetDelayTime(TTDT_INITIAL, 0);

		m_pToolTipCtrl->SetMaxTipWidth(400);

        return TRUE;	// Created successfully.
    }

    // Something failed.  Clean up and leave.
    delete m_pToolTipCtrl;
    return FALSE;
}

void CTipListCtrl::AdjustThumbTrackToolTipPosition()
{
    CRect toolTipRect;
    m_pToolTipCtrl->GetWindowRect(&toolTipRect);

    CRect thisRect;
    GetWindowRect(&thisRect);

    CPoint pt;
    GetCursorPos(&pt);

    int xOffset = GetSystemMetrics(SM_CXVSCROLL) + GetSystemMetrics(SM_CXDLGFRAME);

    int x = thisRect.right - toolTipRect.Width();
    x -= xOffset;
    int y = pt.y;

    m_pToolTipCtrl->SendMessage(TTM_TRACKPOSITION, 0, MAKELONG(x, y));
}

void CTipListCtrl::DestroyThumbTrackToolTip()
{
    if (m_pToolTipCtrl)
    {
        m_pToolTipCtrl->DestroyWindow();
        delete m_pToolTipCtrl;
        m_pToolTipCtrl = NULL;
    }
}

CString CTipListCtrl::GetThumbTrackToolTipText(int nPos, int nTrackPos)
{
	CString s;

	int columnCount = GetHeaderCtrl()->GetItemCount();
	for (int i = 0; i < columnCount; ++i)
	{
		CString columnName;

		LVCOLUMN col;
		memset(&col, 0, sizeof(LVCOLUMN));
		col.mask = LVCF_TEXT | LVCF_SUBITEM;
		col.pszText = columnName.GetBuffer(250);
		col.cchTextMax = 250;
		VERIFY(GetColumn(i, &col));

		columnName.ReleaseBuffer();

		CString itemText = GetItemText(nTrackPos, i);

		CString line;
		line.Format("%s: %s", (LPCTSTR)columnName, (LPCTSTR)itemText);

		if (!s.IsEmpty())
			s += "\r\n";
		s += line;
	}

	return s;
}
