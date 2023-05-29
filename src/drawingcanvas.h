#pragma once

#include <wx/wx.h>
#include <list>

#include "graphicobject.h"

class DrawingCanvas : public wxWindow
// Constructor
{
public:
    DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    virtual ~DrawingCanvas() {}

    void addRect(int width, int height, int centerX, int centerY, double angle, wxColor color, const std::string &text);

    // Handler for paint events
private:
    void OnPaint(wxPaintEvent &evt);
    void OnMouseDown(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnMouseUp(wxMouseEvent &event);
    void OnMouseLeave(wxMouseEvent &event);

    void finishDrag();
    void finishRotation();

    std::list<GraphicObject> objectList;

    GraphicObject *draggedObj;
    bool shouldRotate;

    wxPoint2DDouble lastDragOrigin;
};
