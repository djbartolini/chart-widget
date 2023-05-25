#pragma once

#include <wx/wx.h>

class DrawingCanvas : public wxWindow
// Constructor
{
public:
    DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    virtual ~DrawingCanvas() {}

    // Handler for paint events
private:
    void OnPaint(wxPaintEvent &evt);
};
