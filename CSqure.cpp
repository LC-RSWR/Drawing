#include "pch.h"
#include "CSqure.h"

// 默认构造函数
CSquare::CSquare()
    : Width(0)
{
    Type = SQUARE;
}

// 带参构造函数
CSquare::CSquare(int x, int y, int w)
    : Width(w)
{
    OrgX = x;
    OrgY = y;
    Type = SQUARE;
}

// 析构函数
CSquare::~CSquare() {}

// 绘制正方形
void CSquare::Draw(CDC* pDC)
{
    CRect rect(OrgX - Width / 2, OrgY - Width / 2, OrgX + Width / 2, OrgY + Width / 2);
    pDC->Rectangle(rect);
}

// 判断点是否在正方形内部
bool CSquare::IsMatched(CPoint pnt)
{
    CRect rect(OrgX - Width / 2, OrgY - Width / 2, OrgX + Width / 2, OrgY + Width / 2);
    return rect.PtInRect(pnt);
}

// 序列化正方形的数据
void CSquare::Serialize(CArchive& ar)
{
    if (ar.IsStoring())  // 存储数据
    {
        ar << (WORD)Type;  // 序列化类型
        ar << OrgX << OrgY << Width << BorderColor << BorderType
            << BorderWidth << FillColor << FillType;
    }
    else  // 加载数据
    {
        WORD w;
        ar >> w;  // 反序列化类型
        Type = (ElementType)w;
        ar >> OrgX >> OrgY >> Width >> BorderColor >> BorderType
            >> BorderWidth >> FillColor >> FillType;
    }
}

// 实现序列化
IMPLEMENT_SERIAL(CSquare, CShape, 1)

