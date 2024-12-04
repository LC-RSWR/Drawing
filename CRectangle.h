#pragma once
#include "CShape.h"

class CRectangle : public CShape
{
public:
    CRectangle();
    CRectangle(int x, int y, int w, int h);
    virtual ~CRectangle();

    virtual void Draw(CDC* pDC);
    virtual bool IsMatched(CPoint pnt);
    virtual void Serialize(CArchive& ar);

private:
    int Width, Height;  // 矩形的宽和高

    DECLARE_SERIAL(CRectangle)
};
