#include "pch.h"
#include "CRectangle.h"


CRectangle::CRectangle()
    : Width(0), Height(0)
{
    Type = RECTANGLE;
}

CRectangle::CRectangle(int x, int y, int w, int h)
    : Width(w), Height(h)
{
    OrgX = x;
    OrgY = y;
    Type = RECTANGLE;
}

CRectangle::~CRectangle() {}

void CRectangle::Draw(CDC* pDC)
{
    CRect rect(OrgX - Width / 2, OrgY - Height / 2, OrgX + Width / 2, OrgY + Height / 2);
    pDC->Rectangle(rect);
}

bool CRectangle::IsMatched(CPoint pnt)
{
    CRect rect(OrgX - Width / 2, OrgY - Height / 2, OrgX + Width / 2, OrgY + Height / 2);
    return rect.PtInRect(pnt);
}

void CRectangle::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        ar << (WORD)Type;
        ar << OrgX << OrgY << Width << Height << BorderColor << BorderType
            << BorderWidth << FillColor << FillType;
    }
    else
    {
        WORD w;
        ar >> w;
        Type = (ElementType)w;
        ar >> OrgX >> OrgY >> Width >> Height >> BorderColor >> BorderType
            >> BorderWidth >> FillColor >> FillType;
    }
}

IMPLEMENT_SERIAL(CRectangle, CShape, 1)
