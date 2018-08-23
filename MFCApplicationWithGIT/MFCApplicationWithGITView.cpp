
// MFCApplicationWithGITView.cpp : implementation of the CMFCApplicationWithGITView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplicationWithGIT.h"
#endif

#include "MFCApplicationWithGITDoc.h"
#include "MFCApplicationWithGITView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationWithGITView

IMPLEMENT_DYNCREATE(CMFCApplicationWithGITView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationWithGITView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplicationWithGITView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplicationWithGITView construction/destruction

CMFCApplicationWithGITView::CMFCApplicationWithGITView()
{
	// TODO: add construction code here

}

CMFCApplicationWithGITView::~CMFCApplicationWithGITView()
{
}

BOOL CMFCApplicationWithGITView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationWithGITView drawing

void CMFCApplicationWithGITView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationWithGITDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApplicationWithGITView printing


void CMFCApplicationWithGITView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplicationWithGITView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationWithGITView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplicationWithGITView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplicationWithGITView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationWithGITView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicationWithGITView diagnostics

#ifdef _DEBUG
void CMFCApplicationWithGITView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationWithGITView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationWithGITDoc* CMFCApplicationWithGITView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationWithGITDoc)));
	return (CMFCApplicationWithGITDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationWithGITView message handlers
