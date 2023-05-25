#include "drawingcanvas.h"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent, id, pos, size)
{
    // set background style to `wxBG_STYLE_PAINT` telling Window we will provide painting
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    // bind to the paint event
    this->Bind(wxEVT_PAINT, &DrawingCanvas::OnPaint, this);
}

void DrawingCanvas::OnPaint(wxPaintEvent &evt)
{
    // acquire device context
    wxAutoBufferedPaintDC dc(this);
    // clear method cleans up drawing artifacts
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);

    if (gc)
    {
        // set size and origin using `FromDIP`
        // ensures proper scaling upon resize for Win32
        wxPoint rectOrigin = this->FromDIP(wxPoint(189, 200));
        wxSize rectSize = this->FromDIP(wxSize(100, 80));

        gc->SetBrush(*wxRED_BRUSH);
        gc->DrawRectangle(rectOrigin.x, rectOrigin.y, rectSize.GetWidth(), rectSize.GetHeight());

        delete gc;
    }
}
