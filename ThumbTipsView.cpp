// ThumbTipsView.cpp : implementation of the CThumbTipsView class
//

#include "stdafx.h"
#include "ThumbTips.h"

#include "ThumbTipsDoc.h"
#include "ThumbTipsView.h"
#include ".\thumbtipsview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThumbTipsView

IMPLEMENT_DYNCREATE(CThumbTipsView, CFormView)

BEGIN_MESSAGE_MAP(CThumbTipsView, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CThumbTipsView construction/destruction

CThumbTipsView::CThumbTipsView()
	: CFormView(CThumbTipsView::IDD)
{
	// TODO: add construction code here

}

CThumbTipsView::~CThumbTipsView()
{
}

void CThumbTipsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL, m_listCtrl);
}

BOOL CThumbTipsView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void CThumbTipsView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_listCtrl.InsertColumn(0, "Title", LVCFMT_LEFT, 300, 0);
	m_listCtrl.InsertColumn(1, "Artist", LVCFMT_LEFT, 400, 1);
	m_listCtrl.InsertColumn(2, "Album", LVCFMT_LEFT, 500, 2);

	PopulateListCtrl();
}

void CThumbTipsView::PopulateListCtrl()
{
	struct SongInfo {
		const char *pszTitle;
		const char *pszArtist;
		const char *pszAlbum;
	};

	SongInfo songs[] = {
		{ "In And Out Of My Life", "Onephatdeeva", "Ministry of Sound - The Annual Millenium Edition - Disc 1 (Judge Jules)", },
		{ "Go On Move", "Reel 2 Reel featuring The Mad Stuntman", "Dance Zone 94 - Disc 1", },
		{ "The theatre", "Pet Shop Boys", "Very", },
		{ "Pause", "Art Of Noise", "The Seduction of Claude Debussy", },
		{ "Hot Stuff", "Donna Summer", "The Full Monty", },
		{ "The Fear", "Travis", "The Man Who", },
		{ "Butterfly", "Kylie Minogue", "Light Years", },
		{ "AC-DC (Gangbanger Mix)", "X-Press 2", "Clubber's Guide to... 2001 - Disc 1 (Tall Paul)", },
		{ "Don't Give Up (Original Mix)", "Chicane feat. Brian Adams", "Breakdown (Orange) - The Very Best Of Euphoric Dance CD2", },
		{ "Weekend (Weekend Mix)", "Todd Terry Project", "The House Collection Volume 3 - Disc 1 (Jeremy Healy)", },
		{ "K-I-N-O-B-E Skit", "Kinobe", "Soundphiles", },
		{ "Dooms Night Remix (Timo Maas Remix)", "Azzido da Bass", "Breakdown (Blue) - The Very Best Of Euphoric Dance CD1", },
		{ "No More Tears", "The KLF", "The White Room", },
		{ "Ubik", "Timo Maas featuring Martin Bettinghaus", "Cream Anthems 2001 - Disc 2", },
		{ "Sixth Sense", "Josh Wink", "Carl Cox Non Stop 98 - Disc 1", },
		{ "I Got You (I Feel Good)", "James Brown", "Good Morning Vietnam", },
		{ "Let Them Have Their Fun", "Douglas Adams", "The Hitch-Hiker's Guide To The Galaxy - The Primary Phase - Fit the First", },
		{ "Vegas (Fear And Loathing Mix)", "Agnelli & Nelson", "Cream Live 2001 - Disc 2", },
		{ "Only The Wind", "Pet Shop Boys", "Behaviour", },
		{ "Chariots of Fire", "Vangelis", "Themes", },
		{ "Chaos", "Astral Projection", "White Label Euphoria Level 2 - Disc 2", },
		{ "Lee", "Tenacious D", "Tenacious D", },
		{ "Grass Roots Horizon", "Kinobe", "Soundphiles", },
		{ "Go (Jam And Spoon in Dub Mix)", "Moby", "Back To Mine - Nick Warren", },
		{ "Closer", "Melanie C", "Northern Star", },
		{ "Synaethesia (Fly Away)", "The Thrillseekers featuring Sheryl Dean", "Trance Nation 2001 - Disc 1 (Ferry Corsten)", },
		{ "Everybody in the world", "Hasha", "Dance Zone Level 5 - Disc 2", },
		{ "End Theme", "Zero 7", "Simple Things", },
		{ "On Ya Way", "Helicopter", "Cream Anthems - Disc 2 (Paul Bleasdale)", },
		{ "Marshall Mathers", "Eminem", "Marshall Mathers", },
		{ "Happy People", "Static Revenger", "Ministry of Sound - The Annual 2002 - Disc 1", },
		{ "Walk To The Water", "U2", "The B-Sides 1980-1990", },
		{ "Shoop", "Salt N Pepa", "Pass The Vibes", },
		{ "The Major Problem", "Douglas Adams", "The Hitch-Hiker's Guide To The Galaxy - The Secondary Phase - Fit the Eleventh", },
		{ "Flight 643", "DJ Tiesto", "Trance Nation 2001 - Disc 2 (Ferry Corsten)", },
		{ "Remember Me (Cavern 3 remix)", "The Blueboy", "Remember Me", },
		{ "Theme from S-Express", "S-Express", "In The Mix 96 Vol 2 - Disc 2", },
		{ "Suburbia", "Pet Shop Boys", "Please", },
		{ "Seven Days & One Week (Club Mix)", "B.B.E.", "Breakdown (Green) - The Very Best Of Euphoric Dance CD2", },
		{ "I wouldn't normally do this kind of thing (seven-inch Version)", "Pet Shop Boys", "Further Listening 1992-1994", },
		{ "No Good (Start The Dance)", "The Prodigy", "Music For The Jilted Generation", },
		{ "Underwater Love (Morales Underwater Club Mix)", "Smoke City", "Underwater Love", },
		{ "Drifting", "Mojolators featuring Camilla", "Clubber's Guide to... Ibiza - Summer 2001 - Disc 1", },
		{ "Injected with a Poison", "Praga Khan", "Back to the Old Skool - Disc 2", },
		{ "Chapter 6- Talons and Tea Leaves", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Prisoner of Azkaban - Disc 03", },
		{ "Love City Groove", "Love City Groove", "Dance Zone Level 5 - Disc 1", },
		{ "Give Me A Little More Time", "Gabrielle", "In The Mix 96 Vol 2 - Disc 2", },
		{ "Wild, Sweet And Cool (Static Revenger Mix)", "The Crystal Method", "Community Service", },
		{ "Who's That Girl ", "Annie Lennox", "Live in Central Park", },
		{ "I'm Gonna Sit Right Down And Cry (Over You)", "The Beatles", "Live at the BBC - Disc 1", },
		{ "Nu Blud", "DJ Food", "Journeys By DJ - Special Release", },
		{ "Hermaphrodite", "Jam & Spoon", "Tripomatic Fairytales 2002", },
		{ "Shake Your Groove Thang", "Peaches & Herb", "Disco Fever - Disc 2", },
		{ "Firestarter", "The Prodigy", "The House Collection Volume 4 - Disc 1 (Jeremy Healy)", },
		{ "The End Of The World", "Pet Shop Boys", "Behaviour", },
		{ "A Horribly Awkward First Sexual Encounter Was Quote 'Worth The Wait' For A Pair Of Christian Newlyweds", "Onion Radio News", "Onion Radio News", },
		{ "In The Waiting Line", "Zero 7", "Ministry of Sound - The Chillout Annual 2002 - Disc 1", },
		{ "cylons in love", "Bent", "Programmed to Love", },
		{ "Rockin' For Myself", "Motiv 8", "Dance Zone 94 - Disc 2", },
		{ "The Test", "The Chemical Brothers", "Come With Us", },
		{ "Witch Doktor (prelude)", "Armand Van Helden", "Cream Live - Disc 2 (Paul Oakenfold & Justin Robertson)", },
		{ "Exploration Of Space", "Cosmic Gate", "Clubber's Guide to... 2002 - Disc 1", },
		{ "Nerve Rackingly Enough", "Douglas Adams", "The Hitch-Hiker's Guide To The Galaxy - The Secondary Phase - Fit the Twelfth", },
		{ "Zombie Nation (DJ Gius Remix)", "Kernkraft 400", "Cream Anthems 2001 - Disc 1", },
		{ "Secret Kind Of Love", "Jam & Spoon", "Tripomatic Fairytales 2002", },
		{ "This Ain't A Love Song", "Bon Jovi", "These Days", },
		{ "You Don't Know Me", "Armand Van Helden", "You Don't Know Me", },
		{ "Outro", "Limp Bizkit", "Significant Other", },
		{ "Who Keeps Changing Your Mind (Sure Is Pure Mix)", "South Street Players", "The House Collection Volume 3 - Disc 1 (Jeremy Healy)", },
		{ "Underwater Love (Radio Edit)", "Smoke City", "Underwater Love", },
		{ "Sunshines Better (Talvin Singh)", "John Martyn", "Café del Mar Volumen Cuatro", },
		{ "Buddy Bye Bye", "Johnny Osbourne", "Essential Mix Vol 4 - Disc 3 (Jon Carter)", },
		{ "Some L.A. Niggaz", "Dr. Dre", "2001", },
		{ "Man Research (Clapper)", "Gorillaz", "Gorillaz", },
		{ "Hot Flush", "Red Snapper", "Journeys By DJ - Special Release", },
		{ "And Here I Stand", "Skunk Anansie", "Paranoid and Sunburnt", },
		{ "Ready To Go (Original Mix)", "Republica", "Republica", },
		{ "Air 2000 (Oliver Lieb Remix)", "Albion", "Trance Nation 4 - Disc 2 (Ferry Corsten)", },
		{ "Sweet Love 2K (Trouser Enthusiasts' Mix)", "Fierce", "Breakdown (Orange) - The Very Best Of Euphoric Dance CD2", },
		{ "I Turn To You", "Melanie C", "Northern Star", },
		{ "At Least We Tried", "Moby", "18", },
		{ "Neptune", "Blame", "Essential Mix Vol 4 - Disc 3 (Jon Carter)", },
		{ "Darlin' (Mr G's REM Remix)", "Bob Sinclar", "Ministry of Sound - The Annual - Spring 2001 - Disc 1", },
		{ "Western", "PFM", "Cream Live 2 - Disc 1", },
		{ "Meeting up with Ron & Hermione", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Prisoner of Azkaban - Disc 02", },
		{ "Pounds N Penz", "Corvin Dalek", "Clubber's Guide to... 2001 - Disc 2 (Tall Paul)", },
		{ "Poison", "The Prodigy", "Music For The Jilted Generation", },
		{ "Dance Valley Theme 2001", "System F", "Trance Nation 2002 - Disc 1", },
		{ "Funny How Love Is", "Fine Young Cannibals", "The Finest", },
		{ "Nervous Breakdown", "Shrink", "Clubber's Guide to... Ibiza - Disc 2 (Judge Jules)", },
		{ "Newborn Friend", "Seal", "Seal (1994)", },
		{ "Come As You Are", "Nirvana", "Nevermind", },
		{ "Peanut Head", "Senser", "Stacked Up", },
		{ "A Hard Day's Night", "The Beatles", "A Hard Day's Night", },
		{ "Clint Eastwood", "Gorillaz", "Gorillaz", },
		{ "An Adorable Puppy Nets Its Owner A Handjob", "Onion Radio News", "Onion Radio News", },
		{ "Soap", "Eminem", "Slim Shady (Special Edition) - Disc 1", },
		{ "Out of hospital", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Prisoner of Azkaban - Disc 10", },
		{ "It never rains", "Dire Straits", "Love over Gold", },
		{ "The Sinner", "Orbital", "The Saint (CD Single)", },
		{ "A Breakthrough Drug Eliminates Crying In Infants", "Onion Radio News", "Onion Radio News", },
		{ "Crazy English Summer", "Faithless", "Outrospective", },
		{ "Age Of Panic", "Senser", "Stacked Up", },
		{ "The Drug", "DJ Worris", "Clubber's Guide to... Ibiza - Summer 2000 - Disc 1 (Judge Jules)", },
		{ "I Sit on Acid (Soulwax Remix)", "Lords of Acid", "2 many dj's: As Heard on Radio Soulwax pt. 2", },
		{ "Seven-And-A-Half Million Years Later", "Douglas Adams", "The Hitch-Hiker's Guide To The Galaxy - The Primary Phase - Fit the Fourth", },
		{ "18", "Moby", "18", },
		{ "Hit Music", "Pet Shop Boys", "Actually", },
		{ "Dirty Disco Dubs (That Sound)", "DJ Disco", "Fantazia - British Anthems Summertime - Disc 1 (Jeremy Healy)", },
		{ "Talking to snakes", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Chamber of Secrets - Disc 05", },
		{ "Eclipse", "Pink Floyd", "Dark Side of the Moon", },
		{ "The Way", "Lara Sea", "Clubber's Guide to... Trance - Disc 1 (atb)", },
		{ "Barrel Of A Gun", "Depeche Mode", "Back To Mine - Underworld", },
		{ "Aerodynamic", "Daft Punk", "Discovery", },
		{ "I'm Your Man '96", "Wham!", "If You Were There - The Best Of Wham!", },
		{ "The Naughty North & The Sexy South (Naughty But Nice Mix)", "E-Motion", "Club Mix 96 - Disc 2", },
		{ "Switch", "Senser", "Stacked Up", },
		{ "For Miss Caulker", "The Animals", "The Most Of The Animals", },
		{ "Chapter 19- The Hungarian Horntail", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Goblet of Fire - Disc 08", },
		{ "Joy (Ruff Ryder Pumpin' House Remix)", "Mark 'Ruff' Ryder featuring Special MC", "Ministry of Sound - The Annual - Spring 2001 - Disc 2", },
		{ "Visiting the Leaky Cauldron", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Philosopher's Stone - Disc 02", },
		{ "You Give Love A Bad Name", "Bon Jovi", "Slippery When Wet", },
		{ "Sound Check (Gravity)", "Gorillaz", "Gorillaz", },
		{ "On The Run (Big Ron Mix)", "Big Time Charlie", "Ministry of Sound - The Annual Millenium Edition - Disc 1 (Judge Jules)", },
		{ "State Of Independence (Murk Vocal Club Mix)", "Donna Summer", "Club Mix 96 - Disc 1", },
		{ "7", "Moby", "Play", },
		{ "They all leave in the car", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Philosopher's Stone - Disc 01", },
		{ "Dream On", "The Chemical Brothers", "Surrender", },
		{ "Just hold on", "Toploader", "Onka's Big Moka", },
		{ "Street Beats Vol. 2", "Truper", "Journeys By DJ - Special Release", },
		{ "Flying to Hogwarts", "J. K. Rowling, read by Stephen Fry", "Harry Potter and the Chamber of Secrets - Disc 02", },
		{ "Megablast", "Real McCoy", "Another Night (US Album)", },
		{ "Superstring", "Cygnus X", "Northern Exposure 2 - Westcoast (Sasha & Digweed)", },
		{ "We Can Be Like They Are", "JEC", "The Very Best Of Euphoric Dance - Breakdown CD 2", },
		{ NULL, NULL, NULL, },
	};

	int iItem = 0;
	for (const SongInfo *p = songs; p->pszTitle; ++p)
	{
		LVITEM item;
		memset(&item, 0, sizeof(LVITEM));
		item.mask = LVIF_TEXT|LVIF_IMAGE;
		item.iImage = iItem % 3;
		item.iItem = iItem;
		item.iSubItem = 0;
		item.pszText = const_cast<char *>(p->pszTitle);
		VERIFY(m_listCtrl.InsertItem(&item) != -1);

		item.iSubItem = 1;
		item.pszText = const_cast<char *>(p->pszArtist);
		VERIFY(m_listCtrl.SetItem(&item));

		item.iSubItem = 2;
		item.pszText = const_cast<char *>(p->pszAlbum);
		VERIFY(m_listCtrl.SetItem(&item));

		++iItem;
	}
}

// CThumbTipsView diagnostics

#ifdef _DEBUG
void CThumbTipsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CThumbTipsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CThumbTipsDoc* CThumbTipsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThumbTipsDoc)));
	return (CThumbTipsDoc*)m_pDocument;
}
#endif //_DEBUG


// CThumbTipsView message handlers

void CThumbTipsView::OnSize(UINT nType, int cx, int cy)
{
	if (m_listCtrl.GetSafeHwnd())
		m_listCtrl.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOZORDER);
}
