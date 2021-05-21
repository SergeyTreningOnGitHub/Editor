/*!
    \file main.cpp
*/

/*!
    "Эмуляция работы графического редактора"
*/


#include "gui.h"
#include "visual_objects.h"

using namespace std;

int main(){
    Form main_form;
    Image image;

    auto p_menu = make_shared<Menu>();    
    
    auto p_add_circle_button = make_shared<Button>();
    p_add_circle_button->AddClickable(make_unique<Image::CircleCreator>(&image));
    p_menu->AddWidget(p_add_circle_button);
    
    auto p_add_line_button = make_shared<Button>();
    p_add_line_button->AddClickable(make_unique<Image::LineCreator>(&image));
    p_menu->AddWidget(p_add_line_button);

    auto p_add_text_button = make_shared<Button>();
    p_add_text_button->AddClickable(make_unique<Image::TextCreator>(&image));
    p_menu->AddWidget(p_add_line_button);

    auto p_save_file_button = make_shared<Button>();
    p_save_file_button->AddClickable(make_unique<Image::Serializer>(&image, "OutImage"));
    p_menu->AddWidget(p_save_file_button);

    auto p_open_file_button = make_shared<Button>();
    p_open_file_button->AddClickable(make_unique<Image::Deserializer>(&image, "InputImage"));
    p_menu->AddWidget(p_open_file_button);

    main_form.AddWidget(p_menu);

    auto p_canvas = make_shared<Canvas>();
    main_form.AddWidget(p_canvas);

    p_add_circle_button->Click();
    p_add_line_button->Click();
    p_add_text_button->Click();

    p_canvas->LoadPixels(image.GetPixels());
    p_canvas->Draw();      

    p_save_file_button->Click();
    p_open_file_button->Click();

    return 0;
}