/*!
    \file visual_objects.h
*/

/*!
    "Модуль графических примитивов"
*/


#pragma once
#include "positioning.h"
#include "gui.h"
#include <vector>
#include <memory>


/// Базовый класс графического примитива
class Shape{
public:
    Position GetPosition();
    void SetPosition(Position p);    

    /// Метод получения графических данных, ассоциированных с данным примитивом
    virtual std::vector<Pixel> GetPixels() = 0;    
    virtual ~Shape();
};

class Font{

};

class Text : public Shape{
public:
    std::vector<Pixel> GetPixels() override;    
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

class Circle : public Shape{
public:
    
    void SetLeftTopCorner(Position p);
    Position GetLeftTopCorner();
    void SetRightButtomCorner(Position p);
    Position GetRightButtomCorner();
    std::vector<Pixel> GetPixels() override;
};


/// Контейнер графических примитивов

class Image : public Shape{
public:

    /// Базловый класс фабричного метода создания графических примитивов
    class ShapeCreator : public IClickable{
    public:
        virtual void ClickHandler() = 0;
    };

    class LineCreator : public ShapeCreator{
    public:
        LineCreator(Image* p_im){}
        void ClickHandler() override;
    };

    class TextCreator : public ShapeCreator{
    public:
        TextCreator(Image* p_im){}
        void ClickHandler() override;
    };

    class CircleCreator : public ShapeCreator{
    public:
        CircleCreator(Image* p_im){}
        void ClickHandler() override;
    };
    

    /// Класс сохранения текущего состояния Image в файл
    class Serializer : public IClickable{
    public:
        Serializer(Image* p_im, const std::string& path){}
        void ClickHandler() override;
    };


    /// Класс восстановления сохранённого состояния из файла
    class Deserializer : public IClickable{
    public:
        Deserializer(Image* p_im, const std::string& path){}
        void ClickHandler() override;
    };

    std::vector<Pixel> GetPixels() override;
};