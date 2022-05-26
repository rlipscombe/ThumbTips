#pragma once


// CTipListCtrl

class CTipListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CTipListCtrl)

public:
	CTipListCtrl();
	virtual ~CTipListCtrl();

protected:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	DECLARE_MESSAGE_MAP()

private:
	CToolTipCtrl *m_pToolTipCtrl;
	CString m_toolTipText;

	void DisplayThumbTrackToolTip(const char *toolTipText);
	
	BOOL CreateThumbTrackToolTip();
	void DestroyThumbTrackToolTip();

	void AdjustThumbTrackToolTipPosition();

	void FillToolInfo(TOOLINFO *ti);

	CString GetThumbTrackToolTipText(int nPos, int nTrackPos);
};


