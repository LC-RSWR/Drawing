#pragma once
#include "CShape.h"

class CSquare : public CShape
{
public:
    CSquare();  // 默认构造函数
    CSquare(int x, int y, int w);  // 带参构造函数，创建正方形
    virtual ~CSquare();

    virtual void Draw(CDC* pDC);         // 绘制正方形
    virtual bool IsMatched(CPoint pnt);  // 判断点是否在正方形内
    virtual void Serialize(CArchive& ar); // 序列化正方形数据

private:
    int Width;  // 正方形的边长

    DECLARE_SERIAL(CSquare)  // 声明支持序列化
};
