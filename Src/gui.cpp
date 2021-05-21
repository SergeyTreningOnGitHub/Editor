#include "gui.h"
#include <iostream>

using namespace std;

void Widget::AddClickable(std::unique_ptr<IClickable> clickable){
    cout<< "Add listener click event to this widget" << endl;
}

Widget::~Widget(){
    cout << "Destroy widget" << endl;
}

WidgetContainer::~WidgetContainer(){
    cout << "Destroy widget container" << endl;
}

void Form::Click(){}

void Form::AddWidget(std::shared_ptr<Widget> p_w){
    cout << "Add widget to form" << endl;
}

void Form::DeleteWidget(std::shared_ptr<Widget> p_w){
    cout << "Delete widget from form" << endl;
}

void Menu::Click(){}
void Menu::AddWidget(std::shared_ptr<Widget> p_w){
    cout << "Add widget to menu" << endl;
}

void Menu::DeleteWidget(std::shared_ptr<Widget> p_w){
    cout << "Delete widget from menu" << endl;
}

void Button::Click(){
    cout << "Button clicked" << endl;
}    

void Canvas::Click(){}    
void Canvas::LoadPixels(const std::vector<Pixel>& pixels){
    cout << "Canvas updated image and ready to draw" << endl;
}

void Canvas::Draw(){
    cout << "Canvas draw image" << endl;
}