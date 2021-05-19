#pragma once
#include "positioning.h"
#include <memory>
#include <vector>


using EventHandler = void (*)();

class Widget{
public:
    HoldArea GetHoldArea();
    void SetPosition(Position pos);
    Position GetPosition();

    void SetWidth(int32_t w);
    int32_t GetWidth();

    void SetHeight(int32_t h);
    int32_t GetHight();

    void SetEventHandler(EventHandler ev_h);
    
    virtual void Click() = 0;
    virtual ~Widget();
};

using WidgetHandler = int32_t;

class WidgetContainer : public Widget{
public:    
    virtual WidgetHandler AddWidget(std::unique_ptr<Widget> p_w) = 0;
    virtual void DeleteWidget(WidgetHandler h_w) = 0;
    virtual Widget& GetWidget(WidgetHandler h_w) = 0;
    virtual ~WidgetContainer();    
};

class Form : public WidgetContainer{
public:
    void Click() override;    
    WidgetHandler AddWidget(std::unique_ptr<Widget> p_w) override;
    void DeleteWidget(WidgetHandler h_w) override;
    Widget& GetWidget(WidgetHandler h_w) override;
};

class Menu : public WidgetContainer{
public:
    void Click() override;    
    WidgetHandler AddWidget(std::unique_ptr<Widget> p_w) override;
    void DeleteWidget(WidgetHandler h_w) override;
    Widget& GetWidget(WidgetHandler h_w) override;
};

class Button : public Widget{
public:
    void Click() override;    
};

class Canvas : public Widget{
public:
    void Click() override;    
    void LoadPixels(const std::vector<Pixel> pixels);
    void Draw();
};