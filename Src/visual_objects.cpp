#include "visual_objects.h"
#include <iostream>
using namespace std;

Position Shape::GetPosition(){
    return {};
}
void Shape::SetPosition(Position p){}  

Shape::~Shape(){
    cout << "Destroy shape" << endl;
}

std::vector<Pixel> Text::GetPixels() {
    return {};
}

Font Text::GetFont(){
    return Font();
}

void Text::SetFont(const Font&){}
void Text::Clear(){}

void Line:: SetBeginPoint(Position p){}
Position Line::GetBeginPoint(){
    return {};
}

void Line::SetEndPoint(Position p){}

Position Line::GetEndPoint(){
    return {};
}

std::vector<Pixel> Line::GetPixels(){
    return {};
}

void Circle::SetLeftTopCorner(Position p){}
Position Circle::GetLeftTopCorner(){
    return {};
}

void Circle::SetRightButtomCorner(Position p){}
Position Circle::GetRightButtomCorner(){
    return {};
}

std::vector<Pixel> Circle::GetPixels(){
    return {};
}

void Image::LineCreator::ClickHandler(){
    cout << "Line object created" << endl;
}

void Image::CircleCreator::ClickHandler(){
    cout << "Circle object created" << endl;
}

void Image::TextCreator::ClickHandler(){
    cout << "Text object created" << endl;
}

void Image::Serializer::ClickHandler(){
    cout << "Image saved to file" << endl;
}

void Image::Deserializer::ClickHandler(){
    cout << "Image is exported from file" << endl;
}

std::vector<Pixel>   Image::GetPixels(){
    cout << "Image return ready pexels" << endl;
    return {};
}
