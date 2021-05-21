/*!
    \file gui.h
*/

/*!
    "Модуль графического интерфейса"
*/

#pragma once
#include "positioning.h"
#include <memory>
#include <vector>

/// Интерфейс объектов обработчиков событий Click()
class IClickable{
public:
    /// Обработчик события Click()
    virtual void ClickHandler() = 0;
};


/// Базовый класс графического объекта
class Widget{
public:    

    /// Добавление подписчика на событие Click()
    void AddClickable(std::unique_ptr<IClickable> clickable);
    
    /// Событие Click()
    virtual void Click() = 0;
    virtual ~Widget();
};


/// Базовый класс контейнера графических объектов
class WidgetContainer : public Widget{
public:    
    virtual void AddWidget(std::shared_ptr<Widget> p_w) = 0;
    virtual void DeleteWidget(std::shared_ptr<Widget>) = 0;    
    virtual ~WidgetContainer();    
};

class Form : public WidgetContainer{
public:
    void Click() override;    
    void AddWidget(std::shared_ptr<Widget> p_w) override;
    void DeleteWidget(std::shared_ptr<Widget> p_w) override;    
};

class Menu : public WidgetContainer{
public:
    void Click() override;    
    void AddWidget(std::shared_ptr<Widget> p_w) override;
    void DeleteWidget(std::shared_ptr<Widget> p_w) override;    
};

class Button : public Widget{
public:
    void Click() override;    
};


/// Графический объект для отображения рисунков
class Canvas : public Widget{
public:
    void Click() override;

    /// Метод загрузки грфических данных    
    void LoadPixels(const std::vector<Pixel>& pixels);    
    void Draw();
};