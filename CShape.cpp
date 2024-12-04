#include "pch.h"
#include <afx.h>
#include "CShape.h"

CShape::CShape()
    : Type(NOTSET), OrgX(0), OrgY(0), BorderColor(RGB(0, 0, 0)),
    BorderType(0), BorderWidth(1), FillColor(RGB(255, 255, 255)), FillType(0) {}

CShape::~CShape() {}
