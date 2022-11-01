#pragma once

#include "common.h"
#include "sdk/datatypes/color.h"


class dbl
{
public:

    int getNav();
    int getCat();
    void Begin();
    void End();
    void ChildBackGround(int col, int h);
    void DrawCheckBox(bool& change, const char* label, std::string id = "default");
    void DrawCheckBoxColourPicker(bool& change, Color& col, const char* label);
    void DrawMultiPicker(bool& change, Color& col1, Color& col2, Color& col3, const char* label,  std::string id = "default", std::vector<const char*> data = { "Visible", "Not Visible" }, std::string tooltip = "");
  
    void DrawSliderInt(int& change, int min, int max, const char* label);
    void DrawSliderFloat(float& change, float min, float max, const char* label);
    void DrawDropDown(int& manage, std::vector<const char*> data, const char* label);
    void LoadImages(IDirect3DDevice9* device);
    void LoadFonts(ImGuiIO& io);
    void CleanUp();
    void InputListener();
    void BackGround(bool open);
    bool CanCloseMenu();
    void Separator();

};

