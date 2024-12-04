#pragma once

#include <afx.h>
#include <afxwin.h>

enum ElementType { NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

class CShape : public CObject
{
public:
    CShape();
    virtual ~CShape();
    virtual void Draw(CDC* pDC) = 0;  // 绘制图元
    virtual bool IsMatched(CPoint pnt) = 0;  // 判断点是否在图形内部
    virtual void Serialize(CArchive& ar) = 0;  // 支持序列化



protected:
    ElementType Type;  // 图元类型
    int OrgX, OrgY;  // 原点坐标
    COLORREF BorderColor;  // 边界颜色
    int BorderType;  // 边界线型
    int BorderWidth;  // 边界宽度
    COLORREF FillColor;  // 填充颜色
    int FillType;  // 填充类型
};
