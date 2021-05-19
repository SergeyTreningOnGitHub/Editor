#pragma once
#include "positioning.h"
#include <vector>
#include <memory>

enum class TypeShape{SYMBOL, TEXT, CIRCLE, LINE, RECTANGLE, IMAGE};

class Shape{
public:
    Position GetPosition();
    void SetPosition(Position p);    

    virtual std::vector<Pixel> GetPixels() = 0;
    virtual ~Shape();
};

class Font{

};

class Symbol : public Shape{
public:    
    std::vector<Pixel> GetPixels() override;
};

class Text : public Shape{
public:
    std::vector<Pixel> GetPixels() override;
    void AddSymbol(std::unique_ptr<Symbol> p_symb);
    Font GetFont();
    void SetFont(const Font&);
    void Clear();
};

class Line : public Shape{
public:
    void SetBeginPoint(Position p);
    Position GetBeginPoint();
    void SetEndPoint(Position p);
    Position GetEndPoint();

    std::vector<Pixel> GetPixels() override;
};

class Rectangle : public Shape{
public:
    void SetLeftTopCorner(Position p);
    Position GetLeftTopCorner();
    void SetRightButtomCorner(Position p);
    Position GetRightButtomCorner();
    std::vector<Pixel> GetPixels() override;
};

class Circle : public Shape{
public:
    
    void SetLeftTopCorner(Position p);
    Position GetLeftTopCorner();
    void SetRightButtomCorner(Position p);
    Position GetRightButtomCorner();
    std::vector<Pixel> GetPixels() override;
};

using ShapeHandler = uint32_t;

class Image : public Shape{
public:
    std::vector<Pixel> GetPixels() override;
    ShapeHandler AddShape(std::unique_ptr<Shape> p_sh);
    void DeleteShape(ShapeHandler shape_h);
    void Clear();
    std::vector<Pixel> GetPixels() override;
};