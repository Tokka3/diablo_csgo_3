#include "dbl_gui.h"
#include "gui/objectstructs.h"
#include "gui/keyinput.h"
#include "gui/keywords.h"
#include "gui/color.h"
#include "gui/fonts.h"
#include "gui/images.h"
#include "sdk/datatypes/color.h"
#include <d3dx9tex.h>

IDirect3DTexture9* tickTexture;
IDirect3DTexture9* gradientTexture;
IDirect3DTexture9* borderTexture;
IDirect3DTexture9* triangleTexture;
IDirect3DTexture9* dropText;
IDirect3DTexture9* crossTexture;
IDirect3DTexture9* modalTexture;
IDirect3DTexture9* settingsNonHovered;
IDirect3DTexture9* settings;
IDirect3DTexture9* selectedCircle;
IDirect3DTexture9* modelTexture;
IDirect3DTexture9* diabloTexture;
IDirect3DTexture9* diabloHighResTexture;

IDirect3DTexture9* diabloTextureNon;
IDirect3DTexture9* onButton;
IDirect3DTexture9* offButton;
IDirect3DTexture9* searchIcon;
IDirect3DTexture9* returnIcon;
IDirect3DTexture9* colourPicker;

IDirect3DTexture9* spectrumTexture;
IDirect3DTexture9* bucketTexture;
IDirect3DTexture9* wandTexture;
IDirect3DTexture9* wandTextureNon;
IDirect3DTexture9* visualTexutre;
IDirect3DTexture9* visualTexutreNon;
IDirect3DTexture9* recticleTexture;
IDirect3DTexture9* recticleTextureNon;
IDirect3DTexture9* coderTexture;
IDirect3DTexture9* infoTexture;

ImFont* pFontNavBar = nullptr;
ImFont* bigModern = nullptr;
ImFont* multiModern = nullptr;
ImFont* ReturnModern = nullptr;
ImFont* modernBold = nullptr;
ImFont* smallPix = nullptr;
ImFont* SearchModern = nullptr;
ImFont* MenuModern = nullptr;
ImVec2 mpSet;




//ImVec2 dbl::SetPos() {
//    return mpSet;
//}


namespace Index {
    int DDI; // drop down index for individual animations and checks for whether they are opened

}
namespace IGui {

    Color ColorClipboard = Color(0, 0, 0, 0);
    animList PageTrans;
    std::string SearchSequence;
    bool categoryIDChange = false;
    int changeCategoryTemp = 0;
    bool waiting = false; // bool used to check if any menu element is open, this prevents clicking shit when dropdowns are open and overlapping other elements
    bool waitingM = false;
    bool MO = false; // multi picker open
    bool GO = false;
    bool GK = false;
    bool GM = false;
    int ActualSwitch;
    bool calledFromMulti = false;
    bool waitingK = false;
    bool watingM = false;
    int CheckBoxWidth = 15;
    int DropDownTextMargin = 0;
    int DropDownWidth = 150;
    int DropDownHeight = 22;
    int Block = 0;
    int SliderWidth = 180;
    int SearchPadding = 0;
    float childYAddition = 0;
    float dx = 0;
    float targetAddiol = 0;

    float CchildYAddition = 0;
    float Cdx = 0;
    float CtargetAddiol = 0;

    float easing = 0.05;
    float animationA = 1.0f; // used for when switching nav ids
    float actAnimA = 0.f;
    int MaxTTipWidth = 150;
    bool SearchBarOpen = false;
}
static int          targetXAA = 66;
int globalTimer;
int          navID = 0;
int col1Spacing = 10;
int col2Spacing = 10;
int childX = 0;
int childY = 0;
int elementSpacing = 0;
int ObjI = 0;
std::vector<animList> animsSearch = {};
static int          prevIDCat = 1;
static bool key_state[256];
static bool prev_key_state[256];
ImU32 espCol;
int categoryActiveID;
bool catClicked = false;
bool isMenuMoving = false;
COLORREF _color;
COLORREF mainCol;
ImU32 accent = IM_COL32(232, 36, 114, 255);
ImVec2 menuPos;

POINT cp;

void dbl::LoadImages(IDirect3DDevice9* device) {
    D3DXCreateTextureFromFileInMemory(device, CrossIcon, sizeof(CrossIcon), &crossTexture);
    D3DXCreateTextureFromFileInMemory(device, settingsNon, sizeof(settingsNon), &settingsNonHovered);
    D3DXCreateTextureFromFileInMemory(device, coder, sizeof(coder), &coderTexture);
    D3DXCreateTextureFromFileInMemory(device, info, sizeof(info), &infoTexture);
    D3DXCreateTextureFromFileInMemory(device, highResImg, sizeof(highResImg), &diabloHighResTexture);
    D3DXCreateTextureFromFileInMemory(device, MenuIcon, sizeof(MenuIcon), &settings);
    D3DXCreateTextureFromFileInMemory(device, whiteIcon, sizeof(whiteIcon), &onButton);
    D3DXCreateTextureFromFileInMemory(device, modalData, sizeof(modalData), &modalTexture);
    D3DXCreateTextureFromFileInMemory(device, redIcon, sizeof(redIcon), &offButton);
    D3DXCreateTextureFromFileInMemory(device, returnIco, sizeof(returnIco), &returnIcon);
    D3DXCreateTextureFromFileInMemory(device, search, sizeof(search), &searchIcon);
    D3DXCreateTextureFromFileInMemory(device, diablo, sizeof(diablo), &diabloTexture);
    D3DXCreateTextureFromFileInMemory(device, dropIcon, sizeof(dropIcon), &dropText);
    D3DXCreateTextureFromFileInMemory(device, diabloNon, sizeof(diabloNon), &diabloTextureNon);
    D3DXCreateTextureFromFileInMemory(device, rectData, sizeof(rectData), &recticleTexture);
    D3DXCreateTextureFromFileInMemory(device, rectLow, sizeof(rectLow), &recticleTextureNon);
    D3DXCreateTextureFromFileInMemory(device, wandData, sizeof(wandData), &wandTexture);
    D3DXCreateTextureFromFileInMemory(device, wandDataLow, sizeof(wandDataLow), &wandTextureNon);
    D3DXCreateTextureFromFileInMemory(device, visualData, sizeof(visualData), &visualTexutre);
    D3DXCreateTextureFromFileInMemory(device, visualDataLow, sizeof(visualDataLow), &visualTexutreNon);
    D3DXCreateTextureFromFileInMemory(device, tickData, sizeof(tickData), &tickTexture);
    D3DXCreateTextureFromFileInMemory(device, gradient, sizeof(gradient), &gradientTexture);
    D3DXCreateTextureFromFileInMemory(device, colourPickerData, sizeof(colourPickerData), &colourPicker);
    D3DXCreateTextureFromFileInMemory(device, spectrumData, sizeof(spectrumData), &spectrumTexture);
    D3DXCreateTextureFromFileInMemory(device, borderData, sizeof(borderData), &borderTexture);
    D3DXCreateTextureFromFileInMemory(device, triangleData, sizeof(triangleData), &triangleTexture);
    D3DXCreateTextureFromFileInMemory(device, modelData, sizeof(modelData), &modelTexture);
    D3DXCreateTextureFromFileInMemory(device, selectedData, sizeof(selectedData), &selectedCircle);
    D3DXCreateTextureFromFileInMemory(device, bucketData, sizeof(bucketData), &bucketTexture);
}

void dbl::LoadFonts(ImGuiIO& io) {
 
   // font = io.Fonts->AddFontFromMemoryCompressedTTF(modernbold_compressed_data, modernbold_compressed_size, cfg.SizePixels, &cfg, Helpers::getFontGlyphRanges());
    multiModern = io.Fonts->AddFontFromMemoryCompressedTTF(modern_compressed_data, modern_compressed_size, 13);
    bigModern = io.Fonts->AddFontFromMemoryCompressedTTF(modern_compressed_data, modern_compressed_size, 14.f);
    pFontNavBar = io.Fonts->AddFontFromMemoryCompressedTTF(GilroyBold_compressed_data, GilroyBold_compressed_size, 16);
    SearchModern = io.Fonts->AddFontFromMemoryCompressedTTF(modern_compressed_data, modern_compressed_size, 17.f);
    ReturnModern = io.Fonts->AddFontFromMemoryCompressedTTF(modern_compressed_data, modern_compressed_size, 17);
    MenuModern = io.Fonts->AddFontFromMemoryCompressedTTF(modern_compressed_data, modern_compressed_size, 16.5f);

    // modernB.GlyphExtraSpacing = ImVec2(0.3, 0);
    modernBold = io.Fonts->AddFontFromMemoryCompressedTTF(modernbold_compressed_data, modernbold_compressed_size, 17.f);
    smallPix = io.Fonts->AddFontFromMemoryCompressedTTF(SmallestPixel_compressed_data, SmallestPixel_compressed_size, 9.f);
}
int dbl::getNav() {
    return navID;
}
int dbl::getCat() {
    return categoryActiveID;
}
ImU32 Float4ToCol32(std::array<float, 4U>& col1) {
    return IM_COL32(col1[0] * 255, col1[1] * 255, col1[2] * 255, col1[3] * 255);
}

void dbl::CleanUp() {
    ImGui::End();
}

bool key_pressed(const int key) {
    return key_state[key] && !prev_key_state[key];
}
// ========================================================================
bool key_down(const int key) {
    return key_state[key];
}
int toggleLayerKeybinds = 0;
static float X = 0;
static DropDown* DropDownList = new DropDown[100];
static std::vector<Object> DrawList;
static animList SANIM;
//static SliderSt* sliderStructureArr = new SliderSt[20][100];
static int sliderArrCount = 0;
static animList* anims = new animList[20];
bool itemInKeywords(std::string str) {
    for (int i = 0; i < keywordList.size(); i++) {
        if (str == keywordList[i].String) {
            return true;
        }
    }
    return false;
}



#define DRAGNDROP_HINT(l) \
{ \
	ImGui::ButtonEx("cfg", {}, ImGuiButtonFlags_Disabled); \
	ImGui::SameLine(); \
	ImGui::TextUnformatted(l); \
}

constexpr auto windowFlags = ImGuiWindowFlags_NoResize
| ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;



#include <cstring>

#define get_time() (std::chrono::high_resolution_clock::now());
#define time_millis(start) (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count())


    void animEase(float dx, float targetx, float easing, float& x) {
        dx = targetx - x;
        x += dx * easing;
    }

    float lerp(float a, float b, float t) {
        return a + t * (b - a);
    }
    void animLinear(std::string label, float length) {
        int temp = categoryActiveID;
        if (label == "category") {
            categoryActiveID = 0;
         }
        if (!aList[std::make_pair(categoryActiveID, label)].inProgress) {
            aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
        }
        float elapsed = time_millis(aList[std::make_pair(categoryActiveID, label)].start);



        float percentComplete = elapsed / length;
        if (percentComplete >= 1) {
            percentComplete = 1;
            aList[std::make_pair(categoryActiveID, label)].inProgress = false;
            aList[std::make_pair(categoryActiveID, label)].startVal = aList[std::make_pair(categoryActiveID, label)].targetVal;

        }
        else {

            aList[std::make_pair(categoryActiveID, label)].inProgress = true;
        }

        aList[std::make_pair(categoryActiveID, label)].value = lerp(aList[std::make_pair(categoryActiveID, label)].startVal, aList[std::make_pair(categoryActiveID, label)].targetVal, percentComplete);
        if (label == "category") {
            categoryActiveID = temp;
        }
    }

    void animLinear2(std::string label, float length) {
        int temp = categoryActiveID;
        if (label == "category") {
            categoryActiveID = 0;
        }
       // if (!aList[std::make_pair(categoryActiveID, label)].inProgress) {
           // aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
      //  }
        float elapsed = time_millis(aList[std::make_pair(categoryActiveID, label)].start);



        float percentComplete = elapsed / length;
        if (percentComplete >= 0.98) {
            percentComplete = 1;
            aList[std::make_pair(categoryActiveID, label)].inProgress = false;
            aList[std::make_pair(categoryActiveID, label)].startVal = aList[std::make_pair(categoryActiveID, label)].targetVal;

        }
        else {

            aList[std::make_pair(categoryActiveID, label)].inProgress = true;
        }

        aList[std::make_pair(categoryActiveID, label)].value = lerp(aList[std::make_pair(categoryActiveID, label)].startVal, aList[std::make_pair(categoryActiveID, label)].targetVal, percentComplete);
        if (label == "category") {
            categoryActiveID = temp;
        }
    }

    bool StringInString(std::string str1, std::string str2) {
        if (str2.find(str1) != std::string::npos) return true;
        return false;
    }
    std::string rgb2hex(int r, int g, int b, bool with_head)
    {
        std::stringstream ss;
        if (with_head)
            ss << "#";
        ss << std::hex << (r << 16 | g << 8 | b);
        return ss.str();
    }
    unsigned long createRGB(int r, int g, int b)
    {
        return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
    }

    uint32_t hash(const char* str, uint32_t value = 0x811c9dc5) {
        return *str ? hash(str + 1, (value ^ *str) * 0x1000193ull) : value;
    }

    bool cursorInRegion(int x, int y, int w, int h) {
        GetCursorPos(&cp);
        ImVec2 mp = ImGui::GetWindowPos();

        if (cp.x > mp.x + x && cp.x < mp.x + x + w && cp.y > mp.y + y && cp.y < mp.y + y + h) return true;
        else return false;
    }
    ImVec4 ColorConvertU32ToFloat4(ImU32 in)
    {

        return ImVec4(
            ((in >> IM_COL32_R_SHIFT) & 0xFF),
            ((in >> IM_COL32_G_SHIFT) & 0xFF),
            ((in >> IM_COL32_B_SHIFT) & 0xFF),
            ((in >> IM_COL32_A_SHIFT) & 0xFF));
    }

    int CalcTextSize(const char* text) {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 size = ImGui::CalcTextSize(text);

        return size.x;
    }
    void DrawMessage(ImFont* font, unsigned int x, unsigned int y, const char* Message)
    {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 textPos = ImVec2(menuPos.x + x, menuPos.y + y);
        ImGui::PushFont(font);

        DrawList->AddText(textPos, IM_COL32(255, 255, 255, 255), Message);
        ImGui::PopFont();

    }

    void DrawMessageA(ImFont* font, unsigned int x, unsigned int y, const char* Message, ImU32 col)
    {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 textPos = ImVec2(menuPos.x + x, menuPos.y + y);
        ImGui::PushFont(font);

        DrawList->AddText(textPos, col, Message);

        ImGui::PopFont();

    }
    void DrawTriangle(int x, int y, int x1, int y1, int x2, int y2, ImU32 col) {

        menuPos = ImGui::GetWindowPos();
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        DrawList->AddTriangleFilled(ImVec2(wp.x + x, wp.y + y), ImVec2(wp.x + x1, wp.y + y1), ImVec2(wp.x + x2, wp.y + y2), col);

    }

    void DrawRectGradient(int x, int y, int w, int h, ImU32 topl, ImU32 topr, ImU32 botl, ImU32 botr) {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddRectFilledMultiColor(startPos, endPos, topl, topr, botr, botl);
    }

    void DrawRectGradientNonRL(int x, int y, int w, int h, ImU32 topl, ImU32 topr, ImU32 botl, ImU32 botr) {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2( x, y);
        ImVec2 endPos = ImVec2( x + w,  y + h);
        DrawList->AddRectFilledMultiColor(startPos, endPos, topl, topr, botr, botl);
    }

    void DrawRectGradientQ(int x, int y, int w, int h, ImU32 topl, ImU32 topr, ImU32 botr, ImU32 botl) {
        Object Gradient;
        Gradient.type = ObjectType::RECTANGLEGRADIENT;
        Gradient.x = x;
        Gradient.y = y;
        Gradient.w = w;
        Gradient.h = h;
        Gradient.topl = topl;
        Gradient.topr = topr;
        Gradient.botl = botl;
        Gradient.botr = botr;
        DrawList.emplace_back(Gradient);
    }
    void DrawTriangleQ(int x, int y, ImU32 col, bool up, bool big = false, bool left = false) {
        Object Triangle;
        Triangle.x = x;
        Triangle.y = y;
        Triangle.col = col;
        Triangle.type = ObjectType::TRIANGLE;
        if (!left) {
            if (!up) {

                if (!big) {
                    Triangle.x1 = x + 3;
                    Triangle.y1 = y - 4;
                    Triangle.x2 = x + 6;
                    Triangle.y2 = y;
                }
                else {
                    Triangle.x1 = x + 6;
                    Triangle.y1 = y - 8;
                    Triangle.x2 = x + 12;
                    Triangle.y2 = y;
                }
            }
            else {
                Triangle.x1 = x + 6;
                Triangle.y1 = y;
                Triangle.x2 = x + 3;
                Triangle.y2 = y + 4;

            }
        }
        else {
            Triangle.x2 = x + 6;
            Triangle.y2 = y - 5;
            Triangle.x1 = x + 6;
            Triangle.y1 = y + 6;
        }

        DrawList.emplace_back(Triangle);

    }
    void DrawMessageQ(ImFont* font, unsigned int x, unsigned int y, const char* message, ImU32 col)
    {

        Object Text;
        Text.x = x;
        Text.y = y;
        Text.message = message;
        Text.col = col;
        Text.font = font;
        Text.type = ObjectType::TEXT;
        DrawList.emplace_back(Text);

    }

    void DrawRectUFQ(int x, int y, int w, int h, int rounding, ImU32 col, int thickness) {
        Object uf;
        uf.x = x;
        uf.y = y;
        uf.w = w;
        uf.h = h;
        uf.rounding = rounding;
        uf.type = ObjectType::RECTUF;
        uf.thickness = thickness;
        uf.col = col;
        DrawList.emplace_back(uf);
    }
    void DrawRectQ(int x, int y, int w, int h, int rounding, ImU32 col, ImDrawCornerFlags flags = ImDrawCornerFlags_All) {
        Object Rect;
        Rect.x = x;
        Rect.y = y;
        Rect.w = w;
        Rect.h = h;
        Rect.rounding = rounding;
        Rect.col = col;
        Rect.type = ObjectType::RECTANGLE;
        Rect.flags = flags;
        DrawList.emplace_back(Rect);

    }

    void DrawImageQ(int x, int y, int w, int h, ImU32 col, LPDIRECT3DTEXTURE9 texture) {

        Object Image;
        Image.x = x;
        Image.y = y;
        Image.w = w;
        Image.h = h;
        Image.col = col;
        Image.texture = texture;
        Image.type = ObjectType::IMAGE;
        DrawList.emplace_back(Image);
    }

    void DrawRect(int x, int y, int w, int h, int rounding, ImU32 col) {

        menuPos = ImGui::GetWindowPos();
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddRectFilled(startPos, endPos, col, rounding);

    }
    void DrawLine(ImVec2 p1, ImVec2 p2, int thickness, ImU32 col) {

        menuPos = ImGui::GetWindowPos();
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        p1.x += wp.x;
        p1.y += wp.y;
        p2.x += wp.x;
        p2.y += wp.y;
        DrawList->AddLine(p1, p2, col, thickness);

    }
    void DrawRectC(int x, int y, int w, int h, int rounding, ImU32 col) {


        DrawRect(x - w / 2, y - h / 2, w, h, rounding, col);
    }
    void DrawImageOE(int x, int y, int w, int h, LPDIRECT3DTEXTURE9 texture, ImU32 col) {


        // h += 1;

        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddImage(texture, startPos, endPos, ImVec2(0, 0), ImVec2(1, 1), col);

    }
    void DrawImageC(int x, int y, int w, int h, LPDIRECT3DTEXTURE9 texture, ImU32 col) {
        if (!(w % 2 == 0)) w += 1;
        if (!(h % 2 == 0)) h += 1;
        DrawImageOE(x - w / 2, y - h / 2, w, h, texture, col);


    }

    void DrawRectUF(int x, int y, int w, int h, int rounding, ImU32 col) {

        menuPos = ImGui::GetWindowPos();
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddRect(startPos, endPos, col, rounding, ImDrawCornerFlags_All, 1);

    }
    void DrawRectCUF(int x, int y, int w, int h, int rounding, ImU32 col) {


        DrawRectUF(x - w / 2, y - h / 2, w, h, rounding, col);
    }


    void DrawRectUFA(int x, int y, int w, int h, int rounding, int thickness, ImU32 col) {

        menuPos = ImGui::GetWindowPos();
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddRect(startPos, endPos, col, rounding, ImDrawCornerFlags_All, thickness);

    }

    void DrawRectF(int x, int y, int w, int h, int rounding, ImU32 col, ImDrawCornerFlags flags = ImDrawCornerFlags_All) {

        menuPos = ImGui::GetWindowPos();
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        
        if (flags > 0)
            DrawList->AddRectFilled(startPos, endPos, col, rounding, flags);
        else
            DrawList->AddRectFilled(startPos, endPos, col, rounding);

    }

    void DrawImage(int x, int y, int w, int h, LPDIRECT3DTEXTURE9 texture) {

        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddImage(texture, startPos, endPos, ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 255));

    }
    void DrawImageA(int x, int y, int w, int h, ImU32 col, LPDIRECT3DTEXTURE9 texture) {

        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddImage(texture, startPos, endPos, ImVec2(0, 0), ImVec2(1, 1), col);

    }
    void DrawImageNonRel(int x, int y, int w, int h, ImU32 col, LPDIRECT3DTEXTURE9 texture) {

        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImVec2(0, 0);
        ImVec2 startPos = ImVec2(wp.x + x, wp.y + y);
        ImVec2 endPos = ImVec2(wp.x + x + w, wp.y + y + h);
        DrawList->AddImage(texture, startPos, endPos, ImVec2(0, 0), ImVec2(1, 1), col);

    }
    void DrawNavBarButton(const char* message, int ID, IDirect3DTexture9* enabled, IDirect3DTexture9* nonenabled) {

        GetCursorPos(&cp);

        static bool         showActive = false;
        static float        a = 0;
        static float        aeasing = 0.05;

        static float        targeta = 0;
        static float        ay = 0;

        static float        y = navID * 45;
        static float        easing = 0.05;

        static float        targetY = 48 + (navID * 45);
        static float        dy = 0;
        static float        mult = 1;
        float        measing = 0.02;
        static float        targetMult = 1;
        static float        dmult = 0;
        static int prevID;
        ImGui::PushFont(ReturnModern);
        ImVec2 tW = ImGui::CalcTextSize(message);
        ImGui::PopFont();
        tW.x += 1;


        anims[ID].targeth = 0;
        DrawRectC(32, 15 + (ID * 45) + 15, 47 * 1, 43 * 1, 5, IM_COL32(30, 30, 30, 255 * anims[ID].h * aList[std::make_pair(0, "background")].value));
        DrawRectCUF(32, 15 + (ID * 45) + 15, 47 * 1, 43 * 1, 5, IM_COL32(35, 35, 35, 255 * anims[ID].h * aList[std::make_pair(0, "background")].value));

        if (cp.x > menuPos.x && cp.x < menuPos.x + 63 && cp.y >(ID * 45) + menuPos.y + 12 && cp.y < (ID * 45) + 45 + menuPos.y + 12) {



            //DrawRectC(32, 15 + (ID * 45) + 15, 47 * 1, 43 * 1, 5, IM_COL32(30, 30, 30, 255 * anims[ID].h));
          //  DrawRectCUF(32, 15 + (ID * 45) + 15, 47 * 1, 43 * 1, 5, IM_COL32(35, 35, 35, 255 * anims[ID].h));


            anims[ID].timer += globalTimer;
            anims[ID].targeth = 1;
            if (!(ID == navID && !showActive) && anims[ID].timer > 500) {

                anims[ID].targeta = 1;
                if (ID != navID)
                    DrawMessageQ(ReturnModern, 58 + 6, 20 + (ID * 45), message, IM_COL32(255, 255, 255, 255 * anims[ID].a * aList[std::make_pair(0, "background")].value ));

                else
                    DrawMessageQ(ReturnModern, 58 + 6, 20 + (ID * 45), message, IM_COL32(237 * 1.05, 36 * 1.05, 116 * 1.05, 255 * anims[ID].a * aList[std::make_pair(0, "background")].value));
                DrawTriangleQ(54, 20 + (ID * 45) + 10, IM_COL32(48, 48, 48, 255 * anims[ID].a), false, false, true);
                DrawRectQ(58, 19 + (ID * 45), tW.x + 12, 22, 4, IM_COL32(48, 48, 48, 255 * anims[ID].a));
                DrawRectQ(59, 20 + (ID * 45), tW.x + 10, 20, 4, IM_COL32(40, 40, 40, 255 * anims[ID].a));

            }
            if (key_pressed(VK_LBUTTON)) {
                prevID = navID;
                categoryActiveID = 0;
                targetXAA = 66 + categoryActiveID * 32;
                aList[std::make_pair(0, "category")].targetVal = targetXAA;
                if (ID != prevID) {
                    categoryActiveID = 0;
                    IGui::childYAddition = 100;
                    IGui::targetAddiol = 1.f;

                    IGui::CchildYAddition = 100;
                    IGui::CtargetAddiol = 1.f;
                    showActive = false;
                    aList[std::make_pair(0, "pageTrans")].targetVal = 1.f;





                    targetY = 48 + (ID * 45);
                    IGui::ActualSwitch = ID;
                    targetMult = 0.7;
                }


            }
        }
        else {

            anims[ID].targeta = 0.f;


            anims[ID].timer = 0;
        }

        if (!(cp.x > menuPos.x && cp.x < menuPos.x + 63 && cp.y >(navID * 45) + menuPos.y && cp.y < (navID * 45) + 45 + menuPos.y)) {
            showActive = true;
        }


        if (!key_down(VK_LBUTTON))
            if (mult > 0.68 && mult < 0.72) targetMult = 1;
        //if (mult > 1.09 && mult < 1.11) targetMult = 1.2;

        dy = targetY - y;
        y += dy * easing;

        IGui::dx = IGui::targetAddiol - IGui::childYAddition;
        IGui::childYAddition += IGui::dx * 0.02;

        IGui::Cdx = IGui::CtargetAddiol - IGui::CchildYAddition;
        IGui::CchildYAddition += IGui::Cdx * 0.005;


        //  float m = (1.f - (99 -  sliderMGR[std::make_pair(categoryActiveID, label)].cX) / 15);
        float m = ((100 - IGui::CchildYAddition) / 100);
        int fr = ImGui::GetIO().Framerate;
        float ease = 0.25;
        if (fr <= 60) {
            ease = 0.5;
            measing = 0.1;
        }
        else if (fr <= 30) {
            ease = 0.7;
            measing = 0.4;
        }
        else if (fr <= 15) {
            ease = 0.9;
            measing = 0.7;

        }


        dmult = targetMult - mult;
        mult += dmult * measing;

        int x = 0;
        if (ID == 1) x = 1;
        else {
            x = 0;
        }
        if (ID == IGui::ActualSwitch) {



            DrawRectC(32, 15 + (ID * 45) + 15, 47 * 1, 43 * 1, 5, IM_COL32(30, 30, 30, 255 * mult* aList[std::make_pair(0, "background")].value));
            DrawRectCUF(32, 15 + (ID * 45) + 15, 47 * 1, 43 * 1, 5, IM_COL32(35, 35, 35, 255 * mult * aList[std::make_pair(0, "background")].value));


        }


        if (ID == IGui::ActualSwitch)
            DrawImageC(32 + x, 21 + ID * 45 + 9, ceil(63 * mult), ceil(48 * mult), enabled, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(0, "background")].value)); else
            DrawImageC(32 + x, 21 + ID * 45 + 9, (63 / 1.1), (48 / 1.1), enabled, IM_COL32(220, 220, 220, 255 * aList[std::make_pair(0, "background")].value)); // non hovered



        anims[ID].ay = anims[ID].targeta - anims[ID].a;
        anims[ID].a += anims[ID].ay * ease;

        anims[ID].hy = anims[ID].targeth - anims[ID].h;
        anims[ID].h += anims[ID].hy * ease / 5;
    }
    void CategoryOptions(const char* label, int ID) {


        if (!aList[std::make_pair(0, "category")].init) {
            aList[std::make_pair(0, "category")].value = 66 + categoryActiveID * 32;
            aList[std::make_pair(0, "category")].targetVal = 66 + categoryActiveID * 32;
            aList[std::make_pair(0, "category")].startVal = 66 + categoryActiveID * 32;
            aList[std::make_pair(0, "category")].init = true;
        }
        static int timer = 0;

        if (catClicked) {
            timer += globalTimer;
            if (!tMGR["catClicked"].inProgress) {
                tMGR["catClicked"].start = get_time();
                tMGR["catClicked"].inProgress = true;
            }
           
        }
        if (time_millis(tMGR["catClicked"].start)) {
            catClicked = false;
            tMGR["catClicked"].inProgress = false;
        }

        static float        easing = 0.05;
        static float        dx = 0;

        dx = targetXAA - X;
        X += (dx * easing);

        if (ID == categoryActiveID) {


            // DrawCircle(85, 64 + (ID * 32), 3, IM_COL32(232, 36, 114, (1.f - (99 - X) / 15) * 255));
            DrawMessageA(modernBold, 78, 53 + (ID * 32), label, IM_COL32(232 * 1.08, 36 * 1.08, 114 * 1.08, 255 * aList[std::make_pair(0, "background")].value));
        }
        else {
            DrawMessageA(ReturnModern, 78, 53 + (ID * 32), label, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(0, "background")].value));
        }

        bool hovered = false;
        if ((cp.x > menuPos.x + 58 && cp.x < menuPos.x + 58 + 165 && cp.y > 50 + (ID * 32) + menuPos.y && cp.y < 50 + (ID * 32) + 30 + menuPos.y) && ID != categoryActiveID) {
            if (key_pressed(VK_LBUTTON) && !catClicked) {

                aList[std::make_pair(0, "category")].startVal = 66 + categoryActiveID * 32;
                aList[std::make_pair(0, "category")].start = std::chrono::high_resolution_clock::now();
                IGui::changeCategoryTemp = ID; // don't change it straight away so the animation is more seemless 
                IGui::categoryIDChange = true;
                targetXAA = 66 + IGui::changeCategoryTemp * 32;

                aList[std::make_pair(0, "category")].targetVal = targetXAA;
                aList[std::make_pair(0, "pageTrans")].targetVal = 1.f;

            }
        }

        animLinear("category", 150);
    }
    bool findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
    {
        // Convert complete given String to lower case
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        // Convert complete given Sub String to lower case
        std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
        // Find sub string in given string

        return StringInString(data, toSearch);
    }
    void SearchBar() {



        static bool isPressedEnter = false;

        static float targeth;
        static float h;
        static float dyh;
        static float heasing = 0.12;
        IGui::SearchPadding = 0;
        ImGuiContext& g = *GImGui;

        ImGuiIO& io = g.IO;
        const ImGuiStyle& style = g.Style;






        static bool        once = true;

        static bool        clicked = false;
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        static  std::vector<std::string> RecognizedWords = {};
        static std::string input = "";
        static char inputchar[30]{ "" };
        static int FlashPosX = 0;
        int   textWidth = 0;
        static int goToNav;
        static int goToCat;
        static bool go = false;
        static bool justClicked = false;

        if (input != "") textWidth = CalcTextSize(input.c_str());



        ImGui::SetCursorPos(ImVec2( 93, 15));
        ImGui::SetNextItemWidth(100);
        ImGui::PushFont(SearchModern);

        ImGui::InputText("##searchbar", inputchar, IM_ARRAYSIZE(inputchar));
    
        bool isActive = ImGui::IsItemActive();



        ImGui::PopFont();
        input = inputchar;
        if ((key_down(VK_LCONTROL) || key_down(VK_RCONTROL)) && key_pressed('F')) {
            if (!clicked) {
                clicked = true;

                isPressedEnter = false;
            }
            else {
                clicked = false;
            }
        }
        if (once) {
            animsSearch.resize(20);
            once = false;
        }
        if ((cp.x > menuPos.x + 97 && cp.x < menuPos.x + 82 + 95 && cp.y > menuPos.y + 13 && cp.y < menuPos.y + 40)) {
            if (!aList[std::make_pair(0, "borderFade")].fadeIn && !isActive) {
                aList[std::make_pair(0, "borderFade")].start = std::chrono::high_resolution_clock::now();
                aList[std::make_pair(0, "borderFade")].targetVal = 130;
                aList[std::make_pair(0, "borderFade")].startVal = 70;
                aList[std::make_pair(0, "borderFade")].fadeIn = true;
                aList[std::make_pair(0, "borderFade")].fadeOut = false;
            }
            g.MouseCursor = ImGuiMouseCursor_TextInput;
            if (key_pressed(VK_LBUTTON)) {
                clicked = true;

                isPressedEnter = false;
            }
        }
        else {
            if (!aList[std::make_pair(0, "borderFade")].fadeOut && !isActive) {
                aList[std::make_pair(0, "borderFade")].start = std::chrono::high_resolution_clock::now();
                g.MouseCursor = ImGuiMouseCursor_Arrow;
                aList[std::make_pair(0, "borderFade")].targetVal = 70;
                aList[std::make_pair(0, "borderFade")].startVal = 130;
                aList[std::make_pair(0, "borderFade")].fadeOut = true;
                aList[std::make_pair(0, "borderFade")].fadeIn = false;
            }
        }

        if (!aList[std::make_pair(0, "borderFade")].init) {
            aList[std::make_pair(0, "borderFade")].targetVal = 70;
            aList[std::make_pair(0, "borderFade")].value = 70;
            aList[std::make_pair(0, "borderFade")].startVal = 70;
            aList[std::make_pair(0, "borderFade")].init = true;
        }
        if (!aList[std::make_pair(0, "crossFade")].init) {
            aList[std::make_pair(0, "crossFade")].targetVal = 0;
            aList[std::make_pair(0, "crossFade")].value = 0;
            aList[std::make_pair(0, "crossFade")].startVal = 0;
            aList[std::make_pair(0, "crossFade")].init = true;
        }

        if (isActive) {
            if (!aList[std::make_pair(0, "iconFade")].fadeIn)
                aList[std::make_pair(0, "iconFade")].start = std::chrono::high_resolution_clock::now();
            aList[std::make_pair(0, "iconFade")].targetVal = 255;

            aList[std::make_pair(0, "iconFade")].fadeOut = false;
            aList[std::make_pair(0, "iconFade")].fadeIn = true;

            if (!aList[std::make_pair(0, "borderFade")].enabled)
                aList[std::make_pair(0, "borderFade")].start = std::chrono::high_resolution_clock::now();
            aList[std::make_pair(0, "borderFade")].targetVal = 255;


            aList[std::make_pair(0, "borderFade")].enabled = true;


        }
        else {
            if (!aList[std::make_pair(0, "iconFade")].fadeOut)
                aList[std::make_pair(0, "iconFade")].start = std::chrono::high_resolution_clock::now();
            aList[std::make_pair(0, "iconFade")].targetVal = 160;

            aList[std::make_pair(0, "iconFade")].fadeOut = true;
            aList[std::make_pair(0, "iconFade")].fadeIn = false;
            aList[std::make_pair(0, "borderFade")].enabled = false;


        }





        if (true) {
            if (!isPressedEnter) {
                if (key_pressed(VK_ESCAPE)) {
                    clicked = false;
                    aList[std::make_pair(0, "crossFade")].targetVal = 0;
                    aList[std::make_pair(0, "crossFade")].startVal = 0;
                    aList[std::make_pair(0, "crossFade")].value = 0;
                }




                bool anyResultsFound = false;
                for (int i = 0; i < keywordList.size(); i++) {
                    // keywordList[i].dya = keywordList[i].targeta - keywordList[i].a;
                   //  keywordList[i].a += keywordList[i].dya * 0.1;
                    animLinear(std::string(keywordList[i].String + "keyword").c_str(), 300);

                    if (!findCaseInsensitive(input, keywordList[i].String)) {
                        aList[std::make_pair(0, std::string(keywordList[i].String + "keyword").c_str())].targetVal = 0.f;

                    }
                    else {

                        aList[std::make_pair(0, std::string(keywordList[i].String + "keyword").c_str())].targetVal = 1.f;

                    }

                    //    DrawRectQ(72, 40 + IGui::SearchPadding, 146, 25, 0, IM_COL32(35, 35, 35, 255 ));


                    float ma = (1.f - (105 - animsSearch[i].a) / 24);

                    if (findCaseInsensitive(input, keywordList[i].String) && input != "") {
                        //   animsSearch[i].ay = animsSearch[i].targeta - animsSearch[i].a;
                        //   animsSearch[i].a += animsSearch[i].ay * 0.04;

                        anyResultsFound = true;

                        if (i != keywordList.size())
                            DrawRectQ(72, 40 + IGui::SearchPadding, 146, 1, 0, IM_COL32(34, 34, 34, 255)); // line inbetween

                        DrawMessageQ(SearchModern, 81, 44 + IGui::SearchPadding, keywordList[i].String.c_str(), IM_COL32(200, 200, 200, 255 * aList[std::make_pair(0, std::string(keywordList[i].String + "keyword").c_str())].value));
                        //  DrawRectQ(72, 40 + IGui::SearchPadding, 146, 1, 3, IM_COL32(30, 30, 30, 255));

                        if (cursorInRegion(74, 40 + IGui::SearchPadding, 148, 20)) {





                            if (key_pressed(VK_LBUTTON)) {

                                IGui::SearchSequence = keywordList[i].String;
                                keywordList[i].initiateSequence = true;
                                memset(inputchar, 0, sizeof inputchar);
                                categoryActiveID = keywordList[i].categoryID;
                                navID = keywordList[i].pageID;
                                targetXAA = 66 + categoryActiveID * 32;
                                catClicked = true;
                                input = "";


                            }



                            //   DrawRectQ(72, 40 + IGui::SearchPadding, 146, 1, 0, IM_COL32(40, 40, 40, 255 * ma));
                       //        DrawRectQ(72, 40 + IGui::SearchPadding + 27, 146, 1, 0, IM_COL32(40, 40, 40, 255 * ma));
                            DrawRectQ(72, 40 + IGui::SearchPadding, 146, 27, 0, IM_COL32(35, 35, 35, 255 * ma));

                        }
                        else {
                            animsSearch[i].targeta = 81;
                        }


                        //  if (i == keywordList.size() - 1 && !input.empty()) IGui::SearchPadding += 5;
                        IGui::SearchPadding += 25;

                    }

                }

                if (!anyResultsFound && !input.empty() && isActive) {
                    // DrawRectQ(72, 40, 146, 1, 0, IM_COL32(34, 34, 34, 255));
                    IGui::SearchPadding = 26;
                    DrawRectQ(72, 40, 146, 1, 0, IM_COL32(34, 34, 34, 255));
                    DrawMessageQ(SearchModern, 81, 45, "No results found", IM_COL32(210, 68, 85, 255));
                    DrawRectQ(72, 40, 146, 27, 3, IM_COL32(27, 27, 27, 255), ImDrawCornerFlags_Bot); // line inbetween
                  //  DrawRectQ(71, 39, 148, 29, 3, IM_COL32(70, 70, 70, aList[std::make_pair(0, "borderFade")].value), ImDrawCornerFlags_Bot); // line inbetween

                }

            }
            else {
                input.clear();
            }



            dyh = targeth - h;
            h += dyh * heasing;

            targeth = IGui::SearchPadding;
            aList[std::make_pair(0, "searchHeight")].targetVal = IGui::SearchPadding;

            int temp = categoryActiveID;
            categoryActiveID = 0;
            animLinear("searchHeight", 200);
            categoryActiveID = temp;


            if (!clicked) {

                IGui::SearchPadding = 0;
                RecognizedWords.clear();

            }


            DrawImageQ(69, 12, 146 * 1.2, 25 * 1.2, IM_COL32(255, 255, 255, aList[std::make_pair(0, "iconFade")].value), searchIcon);
            if (input.empty()) {
                DrawMessageQ(SearchModern, 98, 17, "Search", IM_COL32(180, 180, 180, aList[std::make_pair(0, "iconFade")].value));
            }
            ImVec4 fadeRedCol = ImLerp(ImVec4(1, 1, 1, 1), ImVec4(1, 0.23, 0.28, 1), (aList[std::make_pair(0, "crossFade")].value / 255));

            DrawImageQ(70, 15, 146, 25, IM_COL32(fadeRedCol.x * 255, fadeRedCol.y * 255, fadeRedCol.z * 255, aList[std::make_pair(0, "crossFade")].value), crossTexture);
            if (!input.empty()) {
                DrawImageQ(70, 15, 146, 25, IM_COL32(fadeRedCol.x * 255, fadeRedCol.y * 255, fadeRedCol.z * 255, 255), crossTexture);
                if (cursorInRegion(178, 14, 40, 30)) {

                    /* dyh = targeth - h;
                     h += dyh * heasing;*/

                    if (!aList[std::make_pair(0, "crossFade")].fadeIn)
                        aList[std::make_pair(0, "crossFade")].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(0, "crossFade")].targetVal = 255;
                    aList[std::make_pair(0, "crossFade")].fadeIn = true;

                    aList[std::make_pair(0, "crossFade")].fadeOut = false;




                }
                else { // this is causing the bug

                    if (!aList[std::make_pair(0, "crossFade")].fadeOut && aList[std::make_pair(0, "crossFade")].fadeIn)
                        aList[std::make_pair(0, "crossFade")].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(0, "crossFade")].targetVal = 0;

                    aList[std::make_pair(0, "crossFade")].fadeOut = true;
                    aList[std::make_pair(0, "crossFade")].fadeIn = false;

                }


                if (cursorInRegion(200, 14, 40, 30)) {
                    g.MouseCursor = ImGuiMouseCursor_Arrow;
                    if (key_pressed(VK_LBUTTON)) {
                        input.clear();
                        memset(inputchar, 0, sizeof inputchar);

                        FlashPosX = 0;

                        aList[std::make_pair(0, "crossFade")].targetVal = 1;
                        aList[std::make_pair(0, "crossFade")].startVal = 255;
                        aList[std::make_pair(0, "crossFade")].start = std::chrono::high_resolution_clock::now();;
                        aList[std::make_pair(0, "crossFade")].fadeOut = false;
                        aList[std::make_pair(0, "crossFade")].fadeIn = false;

                    }

                }
            }
            DrawRectQ(196, 18, 19, 18, 3, IM_COL32(40, 40, 40, aList[std::make_pair(0, "crossFade")].value));
            DrawRectQ(72, 14, 146, 27 + aList[std::make_pair(0, "searchHeight")].value, 3, IM_COL32(27, 27, 27, 255));

            DrawRectQ(71, 13, 148, 29 + aList[std::make_pair(0, "searchHeight")].value, 3, IM_COL32(70, 70, 70, aList[std::make_pair(0, "borderFade")].value));


        }
        int temp = categoryActiveID;
        categoryActiveID = 0;
        animLinear("borderFade", 200);
        animLinear("crossFade", 100);
        animLinear("iconFade", 200);
        categoryActiveID = temp;
        //animEase(borderFade.ay, borderFade.targeta, 0.05, borderFade.a);
       // animEase(crossFade.ay, crossFade.targeta, crossFade.aeasing, crossFade.a);
       // animEase(iconFade.ay, iconFade.targeta, 0.05, iconFade.a);
    }
    void dbl::InputListener() {
        for (int i = 0; i < 256; i++) {
            prev_key_state[i] = key_state[i];
            key_state[i] = GetAsyncKeyState(i);
        }

        if (isOpen["copyPasteTab"].isOpen && isOpen["copyPasteTab"].waiting) {
            if (!key_down(VK_LBUTTON)) {
                isOpen["copyPasteTab"].isOpen = false;
                isOpen["copyPasteTab"].waiting = false;
            }
        }
        if (IGui::waiting && IGui::GO) {
            if (!key_down(VK_LBUTTON)) {
                IGui::GO = false;
                IGui::waiting = false;
            }
        }

        if (IGui::waitingM && IGui::GM) {
            if (!key_down(VK_LBUTTON)) {
                IGui::GM = false;
                IGui::waitingM = false;
            }
        }


        if (IGui::waitingK && IGui::GK) {
            if (!key_down(VK_LBUTTON)) {
                IGui::GK = false;
                IGui::waitingK = false;
            }
        }

    }
    enum MENUNAV {
        HOME = 0,
        MAIN = 1,
        VISUALS = 2,
        SKINCHANGER = 3,
        SETTINGS = 4,
    };

    bool dbl::CanCloseMenu() {
       return aList[std::make_pair(0, "background")].value < 0.03;
    }


    void dbl::BackGround(bool open) {

        if (!aList[std::make_pair(0, "background")].inProgress) {
            if (!aList[std::make_pair(0, "background")].fadeIn && open) {

                aList[std::make_pair(0, "background")].targetVal = 1.f;
                aList[std::make_pair(0, "background")].startVal = 0.f;
                aList[std::make_pair(0, "background")].fadeIn = true;
                aList[std::make_pair(0, "background")].fadeOut = false;
            }
            if (!aList[std::make_pair(0, "background")].fadeOut && !open) {

                aList[std::make_pair(0, "background")].targetVal = 0.f;
                aList[std::make_pair(0, "background")].startVal = 1.f;
                aList[std::make_pair(0, "background")].fadeIn = false;
                aList[std::make_pair(0, "background")].fadeOut = true;
            }
        }
        ImDrawList* pBackgroundDrawList = ImGui::GetBackgroundDrawList();
  
            pBackgroundDrawList->AddRectFilled(ImVec2(0, 0), ImVec2(5000, 3000), IM_COL32(0, 0, 0, 75 * aList[std::make_pair(0, "background")].value));
            pBackgroundDrawList->AddRect(ImVec2(0, 0), ImVec2(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), IM_COL32(237, 36, 116, 255 * aList[std::make_pair(0, "background")].value));

            ImU32 col = IM_COL32(237, 36, 116, 50 * aList[std::make_pair(0, "background")].value);
            ImU32 trans = IM_COL32(237, 36, 116, 0);
            int w = GetSystemMetrics(SM_CXSCREEN);
            int h = GetSystemMetrics(SM_CYSCREEN);
            DrawRectGradientNonRL(0, 0, w, 100, col, col, trans, trans);
            DrawRectGradientNonRL(0, h - 100, w, 100, trans, trans, col, col);

            DrawRectGradientNonRL(0, 0, 100, h, col, trans, col, trans);
            DrawRectGradientNonRL( w - 100, 0, 100, h, trans, col, trans, col);
            //482 // 135
            DrawImageNonRel(w / 2 - (241 / 2), h - 90, 241 , 68, IM_COL32(210, 210, 210, 255 * aList[std::make_pair(0, "background")].value), diabloHighResTexture);
            int temp = categoryActiveID;
            categoryActiveID = 0;
            animLinear("background", 75);
            categoryActiveID = temp;

        
    }
    void dbl::Begin() {

        int temp = categoryActiveID;
        categoryActiveID = 0;
        animLinear("pageTrans", 250);
        categoryActiveID = temp;
        ImGuiIO & io = ImGui::GetIO();
        const ImVec2 vecScreenSize = io.DisplaySize;
     //   menuPos.x = std::clamp<int>(menuPos.x, 0, GetSystemMetrics(SM_CXSCREEN));
     //   menuPos.y = std::clamp<int>(menuPos.y, 0, GetSystemMetrics(SM_CYSCREEN));
    
        if (cp.x > menuPos.x && cp.x < menuPos.x + 824 && cp.y > menuPos.y && cp.y < menuPos.y + 29) {
            ImGui::Begin("Hello, world!", reinterpret_cast<bool*>(true), ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize );
         
        }
        else {
            ImGui::Begin("Hello, world!", reinterpret_cast<bool*>(true), ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        }
        
        ImVec2 pos = ImGui::GetWindowPos();
        ImGui::SetWindowPos(ImVec2(std::clamp<int>(pos.x, 0, GetSystemMetrics(SM_CXSCREEN) - 758), std::clamp<int>(pos.y, 0, GetSystemMetrics(SM_CYSCREEN) - 592)));

        int fr = ImGui::GetIO().Framerate;
        float ease = 0.25;
        if (fr <= 60) {
            ease = 0.5;

        }
        else if (fr <= 30) {
            ease = 1;

        }
        else if (fr <= 15) {
            ease = 2;


        }

    

        if (aList[std::make_pair(0, "pageTrans")].value > 0.99) {
            aList[std::make_pair(0, "pageTrans")].targetVal = 0.f;
            categoryActiveID = IGui::changeCategoryTemp;
            IGui::categoryIDChange = true;
            navID = IGui::ActualSwitch;
        }
        DrawRectF(0, 0, 63, 592, 6, IM_COL32(23, 22, 23, 255 * aList[std::make_pair(0, "background")].value), ImDrawCornerFlags_BotLeft | ImDrawCornerFlags_TopLeft);
        DrawRect(63, 0, 165, 592, 0, IM_COL32(31, 30, 31, 255 * aList[std::make_pair(0, "background")].value));
        DrawRectF(228, 0, 532, 592, 6, IM_COL32(20, 20, 20, 255 * aList[std::make_pair(0, "background")].value), ImDrawCornerFlags_TopRight | ImDrawCornerFlags_BotRight);
        DrawRect(227, 0, 1, 592, 6, IM_COL32(37, 37, 37, 255 * aList[std::make_pair(0, "background")].value));
        DrawRectUF(1, 1, 758, 590, 5, IM_COL32(37, 37, 37, 255 * aList[std::make_pair(0, "background")].value));

       sliderArrCount = 0;
        if (navID != MENUNAV::HOME) {
            DrawRectC(145, aList[std::make_pair(0, "category")].value - 4, 148, 27, 4, IM_COL32(36, 36, 36, 255 * aList[std::make_pair(0, "background")].value));
            DrawRectCUF(145, aList[std::make_pair(0, "category")].value - 4, 148, 27, 4, IM_COL32(44, 44, 44, 255 * aList[std::make_pair(0, "background")].value));
        }

        if (navID == MENUNAV::SETTINGS) {
            CategoryOptions("Settings", 0);
            CategoryOptions("Configs", 1);
            CategoryOptions("Support", 2);

        }
        if (navID == MENUNAV::SKINCHANGER) {
            CategoryOptions("Inventory", 0);
            CategoryOptions("Settings", 1);

        }
        if (navID == MENUNAV::VISUALS) {
            CategoryOptions("Enemy", 0);
            CategoryOptions("Team", 1);
            CategoryOptions("Local", 2);
            CategoryOptions("Weapons", 3);
            CategoryOptions("World", 4);
            CategoryOptions("View", 5);
            CategoryOptions("Grenades", 6);

        }
        if (navID == MENUNAV::MAIN) {
            CategoryOptions("Main", 0);
            CategoryOptions("Aimbot", 1);
            CategoryOptions("Anti Aim", 2);

        }

        DrawNavBarButton("Home", 0, diabloTexture, diabloTextureNon);
        DrawNavBarButton("Main", 1, recticleTexture, recticleTextureNon);
        DrawNavBarButton("Visuals", 2, visualTexutre, visualTexutreNon);
        DrawNavBarButton("Skins", 3, wandTexture, wandTextureNon);
        DrawNavBarButton("Settings", 4, settings, settingsNonHovered);

        SearchBar();
       // DrawRect(0, 0, 5000, 5000, 0, IM_COL32(0, 0, 0, 30));
        End();


    }

    void DrawCircle(int x, int y, int r, ImU32 col) {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 pos = ImVec2(wp.x + x, wp.y + y);
        DrawList->AddCircleFilled(pos, r, col, 50);
    }
    void DrawCircleUnfilled(int x, int y, int r, ImU32 col) {
        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 pos = ImVec2(wp.x + x, wp.y + y);
        DrawList->AddCircle(pos, r, col, 50);
    }


    void DrawCircleQ(int x, int y, float r, bool filled, ImU32 col) {
        Object Circle;
        Circle.x = x;
        Circle.y = y;
        Circle.radius = r;
        Circle.col = col;
        Circle.type = ObjectType::CIRCLE;
        Circle.filled = filled;
        DrawList.emplace_back(Circle);
    }

    void DrawLineQ(ImVec2 p1, ImVec2 p2, int thickness, ImU32 col) {
        Object line;

        line.type = ObjectType::LINE;
        line.p1 = p1;
        line.p2 = p2;
        line.thickness = thickness;
        line.col = col;
        DrawList.emplace_back(line);
    }
    void dbl::ChildBackGround(int col, int h) {

        elementSpacing = 10;
        DrawRectQ(238, 6, 510, 580, 5, IM_COL32(23, 22, 23, 255 * aList[std::make_pair(0, "pageTrans")].value * aList[std::make_pair(0, "background")].value));

        if (col == 1) {
            DrawRect(238, col1Spacing, 251, h, 5, IM_COL32(23, 22, 23, 255 * aList[std::make_pair(0, "background")].value));
            DrawRectUF(239, col1Spacing + 1, 249, h - 2, 5, IM_COL32(30, 30, 30, 255 * aList[std::make_pair(0, "background")].value));

           // DrawRectQ(244, col1Spacing + 6, 243, h + 2 - 10, 5, IM_COL32(23, 22, 23, 255 * IGui::PageTrans.a * aList[std::make_pair(0, "background")].value));



            childX = 248;
            childY = col1Spacing;
            col1Spacing += h + 10;

        }
        else {
            DrawRect(499, col2Spacing, 251, h, 5, IM_COL32(23, 22, 23, 255 * aList[std::make_pair(0, "background")].value));
            DrawRectUF(500, col2Spacing + 1, 249, h - 2, 5, IM_COL32(30, 30, 30, 255 * aList[std::make_pair(0, "background")].value));

       




            childX = 509;
            childY = col2Spacing;
            col2Spacing += h + 10;

        }

    }

    void DrawImageR(int x, int y, int w, int h, LPDIRECT3DTEXTURE9 texture) {
        // h += 1;

        ImDrawList* DrawList = ImGui::GetBackgroundDrawList();
        ImVec2 wp = ImGui::GetWindowPos();
        ImVec2 startPos = ImVec2(wp.x + x + childX, wp.y + y + childY);
        ImVec2 endPos = ImVec2(wp.x + x + w + childX, wp.y + y + h + childY);
        DrawList->AddImage(texture, startPos, endPos);

    }

    bool DrawDropDownA(int x, int y, int& manage, std::vector<const char*> data, const char* label) {

        bool active = false;
        bool isKBDropDown = false;


        if (label == "null") isKBDropDown = true;
        static float Y;
        static float targetY;
        static float dy;
        static float easing = 0.1;


        static float targetA = 1;       static float A = 1;
        static float da = 1;
        static float aEasing = 0.05;

        da = targetA - A;
        A += da * aEasing;





        if (cursorInRegion(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight)) {
            if (key_pressed(VK_LBUTTON) && !IGui::GO && (!IGui::GK || label == "null")) {


                elementMGR[std::make_pair(categoryActiveID, label)].enabled = !elementMGR[std::make_pair(categoryActiveID, label)].enabled;


                if (elementMGR[std::make_pair(categoryActiveID, label)].enabled) {


                    aList[std::make_pair(categoryActiveID, label)].targetVal = 1;
                    aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(categoryActiveID, label)].startVal = 0;
                }
                else {
                    aList[std::make_pair(categoryActiveID, label)].targetVal = 0;
                    aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(categoryActiveID, label)].startVal = 1;
                    IGui::waiting = true;
                }


                IGui::GO = true;

                return false;

            }
        }



        if (cursorInRegion(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight) && elementMGR[std::make_pair(categoryActiveID,label)  ].enabled) {
            if (key_pressed(VK_LBUTTON)) {

                elementMGR[std::make_pair(categoryActiveID, label)].enabled = false;

                aList[std::make_pair(categoryActiveID, label)].targetVal = 0;

                IGui::waiting = true;

            }
        }



        int c = label == "null" ? 35 : 30;
        if (!elementMGR[std::make_pair(categoryActiveID, label)].enabled) {

            DrawTriangleQ(x + IGui::DropDownWidth - 14, y + IGui::DropDownTextMargin + 10, IM_COL32(255, 255, 255, 255), true);
          //  DrawRectGradientQ(c != 35 ? x + IGui::DropDownWidth - 30 : x + IGui::DropDownWidth - 20, y + IGui::DropDownTextMargin, 15, IGui::DropDownHeight, IM_COL32(c, c, c, 0), IM_COL32(c, c, c, 255), IM_COL32(c, c, c, 255), IM_COL32(c, c, c, 0));
            DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownTextMargin + 1, data[manage], IGui::DropDownWidth > 100 ? IM_COL32(255, 255, 255, 255) : IM_COL32(220, 220, 220, 255));
            DrawRectQ(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 4, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255) : IM_COL32(35, 35, 35, 255), ImDrawCornerFlags_All);

        }
        else {
            DrawTriangleQ(x + IGui::DropDownWidth - 14, y + IGui::DropDownTextMargin + 14, IM_COL32(255, 255, 255, 255), false);

           // DrawRectGradientQ(c != 35 ? x + IGui::DropDownWidth - 30 : x + IGui::DropDownWidth - 20, y + IGui::DropDownTextMargin, 15, IGui::DropDownHeight, IM_COL32(c, c, c, 0), IM_COL32(c, c, c, 255), IM_COL32(c, c, c, 255), IM_COL32(c, c, c, 0));
            DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownTextMargin + 2, IGui::DropDownWidth > 100 ? "Waiting..." : "...", IM_COL32(180, 180, 180, 255));
            DrawRectQ(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 4, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255) : IM_COL32(35, 35, 35, 255), ImDrawCornerFlags_Top);
        }

        if (elementMGR[std::make_pair(categoryActiveID, label)].enabled || aList[std::make_pair(categoryActiveID, label)].value > 0.01) {



            if (elementMGR[std::make_pair(categoryActiveID, label)].enabled) {
                IGui::GO = true;
            }



            if (aList[std::make_pair(categoryActiveID, label)].value > 0.01) {

                active = true;

                for (int i = 0; i < data.size(); i++) {
                    if (i != manage)
                        DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22) + 1, data[i], IM_COL32(255, 255, 255, 255 * aList[std::make_pair(categoryActiveID, label)].value));
                    else
                        DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22) + 1, data[i], IM_COL32(237, 36, 116, 255 * aList[std::make_pair(categoryActiveID, label)].value));

                    if (cursorInRegion(x, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22), IGui::DropDownWidth, IGui::DropDownHeight)) {
                        if (i != data.size() - 1)
                            DrawRectQ(x, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22), IGui::DropDownWidth, IGui::DropDownHeight, 0, IM_COL32(45, 45, 45, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_All);
                        else
                            DrawRectQ(x, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22), IGui::DropDownWidth, IGui::DropDownHeight, 4, IM_COL32(45, 45, 45, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_Bot);

                        if (key_pressed(VK_LBUTTON)) {
                            manage = i;

                            aList[std::make_pair(categoryActiveID, label)].targetVal = 0;
                            aList[std::make_pair(categoryActiveID, label)].startVal = 1;
                            aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                            elementMGR[std::make_pair(categoryActiveID, label)].enabled = false;
                            IGui::waiting = true;

                        }
                    }
                    if (i != data.size() - 1)
                        DrawRectQ(x, y + 22 + (i * 22) + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 0, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255 * aList[std::make_pair(categoryActiveID, label)].value) : IM_COL32(35, 35, 35, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_All);
                    else
                        DrawRectQ(x, y + 22 + (i * 22) + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 4, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255 * aList[std::make_pair(categoryActiveID, label)].value) : IM_COL32(35, 35, 35, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_Bot);
                }
            }

            if (!cursorInRegion(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, (data.size() + 1) * 22)) {
                if (key_pressed(VK_LBUTTON)) {
                    elementMGR[std::make_pair(categoryActiveID, label)].enabled = false;
                    IGui::waiting = true;
                    aList[std::make_pair(categoryActiveID, label)].targetVal = 0;


                }
            }

            if (key_pressed(VK_ESCAPE)) {
                elementMGR[std::make_pair(categoryActiveID, label)].enabled = false;
                IGui::waiting = true;
                aList[std::make_pair(categoryActiveID, label)].targetVal = 0;

            }
        }
        else {


        }




        animLinear(label, 150);

        return active;
    }

    void DrawCheckBoxA(int x, int y, bool& change, const char* label, std::string id, std::string tooltip) {

        tooltip += " ";

        std::string preCut = label;
        std::string idStr = preCut + id;

        

        if (!aList[std::make_pair(categoryActiveID, idStr)].init) {
            if (change) {
                aList[std::make_pair(categoryActiveID, idStr)].startVal = 1;
                aList[std::make_pair(categoryActiveID, idStr)].targetVal = 1;
                aList[std::make_pair(categoryActiveID, idStr)].startVal = 1;
            }
            else {
                aList[std::make_pair(categoryActiveID, idStr)].startVal = 0;
                aList[std::make_pair(categoryActiveID, idStr)].targetVal = 0;
                aList[std::make_pair(categoryActiveID, idStr)].value = 0;
            }
            aList[std::make_pair(categoryActiveID, idStr)].init = true;
        }

        static int timer = 0;
        static bool ready = true;
        bool isOpen = false;
        ImGui::PushFont(MenuModern);
        int width = CalcTextSize(label);
        ImGui::PopFont();
        if (cursorInRegion(x, y, IGui::CheckBoxWidth + width + 20, IGui::CheckBoxWidth)) {
            cbMGR[std::make_pair(categoryActiveID, idStr)].hoverTimer += globalTimer;
            if (key_pressed(VK_LBUTTON) && !IGui::GO && !IGui::GK) {
                change = !change;

            }

            if (key_pressed(VK_RBUTTON) && !IGui::GO && !IGui::GK && !tMGR["kbReady"].inProgress) {
                 cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX = cp.x - menuPos.x;
                 cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY = cp.y - menuPos.y;
                 cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindTab = ! cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindTab;
                ready = false;
               if (!tMGR["kbReady"].inProgress) tMGR["kbReady"].start = get_time();

            }
            if (!tMGR[label].inProgress)
            tMGR[label].start = get_time();
        }
        else {

           
             cbMGR[std::make_pair(categoryActiveID, idStr)].spareClick = false;
        }
        if (change) {
            aList[std::make_pair(categoryActiveID, idStr)].targetVal = 1;



        }
        else {
            aList[std::make_pair(categoryActiveID, idStr)].targetVal = 0;

        }


         cbMGR[std::make_pair(categoryActiveID, idStr)].aList.ay =  cbMGR[std::make_pair(categoryActiveID, idStr)].aList.targeta -  cbMGR[std::make_pair(categoryActiveID, idStr)].aList.a;
         cbMGR[std::make_pair(categoryActiveID, idStr)].aList.a +=  cbMGR[std::make_pair(categoryActiveID, idStr)].aList.ay * 0.05;
        if (time_millis(tMGR[label].start)> 1000 && tooltip.size() > 10) {
             cbMGR[std::make_pair(categoryActiveID, idStr)].aList.targeta = 1;
            aList[std::make_pair(categoryActiveID, tooltip.c_str())].targetVal = 1;
            tMGR[label].inProgress = false;
        }
        else {
            aList[std::make_pair(categoryActiveID, tooltip.c_str())].targetVal = 0;
        }
        animLinear(tooltip.c_str(), 200);
        int xa = x;
        int ya = y + 30;

        int totalWidth = 0;
        int currentLine = 0;
        std::string currentWord;
        int wordWidth = 0;

        //  xa = cp.x - menuPos.x;
         // ya = cp.y - menuPos.y;
        xa += 20;
         cbMGR[std::make_pair(categoryActiveID, idStr)].spareClick = true;


        for (int i = 0; i < tooltip.size(); i++) {
            if (tooltip[i] != ' ')
                currentWord += tooltip[i];
            else {

                currentWord += " ";
                ImGui::PushFont(MenuModern);
                wordWidth = CalcTextSize(currentWord.c_str());
                ImGui::PopFont();
                if (totalWidth + wordWidth < 200) {


                    const char* send = _strdup(currentWord.c_str());

                    DrawMessageQ(MenuModern, xa + totalWidth + 5, ya + ((currentLine) * 22) + 4, send, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(categoryActiveID, tooltip.c_str())].value));
                    currentWord.clear();
                    totalWidth += wordWidth;

                }
                else {
                    currentLine++;
                    totalWidth = 0;


                    const char* send = _strdup(currentWord.c_str());
                    DrawMessageQ(MenuModern, xa + totalWidth + 5, ya + ((currentLine) * 22) + 4, send, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(categoryActiveID, tooltip.c_str())].value));
                    currentWord.clear();
                    totalWidth += wordWidth;

                }



            }



        }


        DrawTriangleQ(xa + 5, ya, IM_COL32(35, 35, 35, 255 * aList[std::make_pair(categoryActiveID, tooltip.c_str())].value), false, true);
        DrawRectQ(xa, ya - 1, IGui::MaxTTipWidth + 60, (1 + currentLine) * 22 + 10, 4, IM_COL32(35, 35, 35, 255 * aList[std::make_pair(categoryActiveID,tooltip.c_str())].value));


        currentLine = 0;
        totalWidth = 0;
        wordWidth = 0;





        if (!ready) {
            timer += globalTimer;
            if (timer > 100)
            {
                timer = 0;
                ready = true;
            }
        }

        static int keyBindTimer = 0;
        static bool justKeyBind = false;

        if (justKeyBind) {
            
            keyBindTimer += globalTimer;

            if (keyBindTimer > 100) {
                keyBindTimer = 0;
                justKeyBind = false;
            }
        }
        if (!justKeyBind) {


        }
        if ( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindTab) {

            if (key_pressed(VK_ESCAPE) && !justKeyBind && ! cbMGR[std::make_pair(categoryActiveID, idStr)].isListening) {
                 cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindTab = false;
                IGui::GK = false;
            }
            IGui::GK = true;
            IGui::DropDownWidth = 68;
            isOpen = DrawDropDownA( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 47,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY - IGui::DropDownTextMargin + 3,  cbMGR[std::make_pair(categoryActiveID, idStr)].ToggleType, { "Toggle", "Hold" }, "null");
            DrawRectQ( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 46,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 2, 70, 24, 4, IM_COL32(38, 38, 38, 255)); // background drop down

            if ( cbMGR[std::make_pair(categoryActiveID, idStr)].isListening) {

                DrawMessageQ(MenuModern,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 78,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 29, "...", IM_COL32(255, 255, 255, 255));
                for (int i = 0; i < 256; i++) {
                    if (key_pressed(i) && i != VK_LBUTTON) {
                        justKeyBind = true;

                        tMGR["justKeyBind"].start = get_time();

                        if ( cbMGR[std::make_pair(categoryActiveID, idStr)].vkKey != VK_ESCAPE)
                             cbMGR[std::make_pair(categoryActiveID, idStr)].vkKey = i;
                        else   cbMGR[std::make_pair(categoryActiveID, idStr)].vkKey = 10000;


                         cbMGR[std::make_pair(categoryActiveID, idStr)].isListening = false;

                        break;
                    }
                }
            }
            else {
                ImGui::PushFont(MenuModern);
                int width = CalcTextSize(key_names[ cbMGR[std::make_pair(categoryActiveID, idStr)].vkKey].c_str());

                ImGui::PopFont();
                int start =  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 47;
                int end = 70;
                int widtha = end - start;
                DrawMessageQ(MenuModern, start + (end / 2) - width / 2,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 29, key_names[ cbMGR[std::make_pair(categoryActiveID, idStr)].vkKey].c_str(), IM_COL32(220, 220, 220, 255));
            }

            DrawMessageQ(MenuModern,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 5,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 5, "Mode", IM_COL32_WHITE);
            DrawMessageQ(MenuModern,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 5,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 30, "Key", IM_COL32_WHITE);
            DrawRectQ( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 47,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 29, 68, 22, 4, IM_COL32(35, 35, 35, 255)); // main keybind
            DrawRectQ( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 46,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 28, 70, 24, 4, IM_COL32(38, 38, 38, 255)); // background keybind

            if (cursorInRegion( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX + 46,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY + 28, 70, 24)) {
                if (key_pressed(VK_LBUTTON) && !IGui::GO) {
                    
                     cbMGR[std::make_pair(categoryActiveID, idStr)].isListening = ! cbMGR[std::make_pair(categoryActiveID, idStr)].isListening;
                }
            }



            DrawRectQ( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY, 118, 54, 4, IM_COL32(30, 30, 30, 255));
            DrawRectQ( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX - 1,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY - 1, 120, 56, 4, IM_COL32(36, 36, 36, 255));


        }
        if (!cursorInRegion( cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindX - 1,  cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindY - 1, 110, 56)) {
            if (key_pressed(VK_LBUTTON) || key_pressed(VK_RBUTTON)) {
                if (!isOpen && !IGui::GO && time_millis(tMGR["kbReady"].start) > 30) {
                     cbMGR[std::make_pair(categoryActiveID, idStr)].keyBindTab = false;
                    IGui::waitingK = true;
                    tMGR["kbReady"].inProgress = false;
                }
            }
        }




        animLinear(idStr, 100);
        DrawImageQ(x - 1, y, 16, 16, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(categoryActiveID, idStr)].value), tickTexture);
        DrawRectQ(x, y, IGui::CheckBoxWidth, IGui::CheckBoxWidth, 3, IM_COL32(237, 36, 116, 255 * aList[std::make_pair(categoryActiveID, idStr)].value), ImDrawCornerFlags_All); // if clicked, draw link rectange with tick 
         cbMGR[std::make_pair(categoryActiveID, idStr)].dx =  cbMGR[std::make_pair(categoryActiveID, idStr)].targetX -  cbMGR[std::make_pair(categoryActiveID, idStr)].X;
         cbMGR[std::make_pair(categoryActiveID, idStr)].X +=  cbMGR[std::make_pair(categoryActiveID, idStr)].dx * 0.1;

        if (!StringInString("cockinass", tooltip)) {
            DrawRectQ(x + 2, y + 2, 11, 11, 2, IM_COL32(22, 22, 22, 255), ImDrawCornerFlags_All); // checkbox inside
        }
        else {
            DrawRectQ(x + 2, y + 2, 11, 11, 2, IM_COL32(30, 30, 30, 255), ImDrawCornerFlags_All);

        }
        DrawRectQ(x, y, 15, 15, 3, IM_COL32(45, 45, 45, 255), ImDrawCornerFlags_All); // checkbox border


        std::string cmpit(label);

        static bool startedSequenceDown = false;

        if (IGui::SearchSequence == cmpit) {
            SANIM.ay = SANIM.targeta - SANIM.a;
            SANIM.a += SANIM.ay * 0.03;
            if (!startedSequenceDown)
                SANIM.targeta = 1.f;
            float m2 = SANIM.a;
            float m = 1.f - m2;
            static float rMult = 255.f / 232.f;

            static  float gMult = 255.f / 36.f;
            static float bMult = 255.f / 114.f;

            DrawMessageQ(MenuModern, x + 24, y - 2, label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255));
            //  DrawRect(x + 24, y + 18, width, 1, 0, IM_COL32(232, 36, 114, 255 * SANIM.a));
            if (!startedSequenceDown) {

                DrawLine(ImVec2(x + 24, y + 18), ImVec2(x + 24 + (width * SANIM.a), y + 18), 1, IM_COL32(232, 36, 114, 255));
            }
            else {

                DrawLine(ImVec2(x + 24 + (width * m), y + 18), ImVec2(x + 24 + width, y + 18), 1, IM_COL32(232, 36, 114, 255 * SANIM.a));
            }
            if (SANIM.a > 0.95) {
                SANIM.targeta = 0.f;
                startedSequenceDown = true;
            }

            if (SANIM.a < 0.05 && startedSequenceDown) {
                IGui::SearchSequence = "";
                startedSequenceDown = false;
            }


        }
        else {
            DrawMessageQ(MenuModern, x + 24, y - 2, label, IM_COL32_WHITE);
        }






    }


    void dbl::DrawCheckBox(bool& change, const char* label, std::string id) {
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

        }
        DrawCheckBoxA(childX, childY + elementSpacing, change, label, id, "");
        elementSpacing += 23;
    }

    void DrawCheckBoxTT(bool& change, const char* label, std::string tooltip) {
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

        }
       // DrawCheckBoxA(childX, childY + elementSpacing, change, label, tooltip);
        elementSpacing += 23;
    }


   

    bool DrawMultiDropDownA(int x, int y, std::vector<MultiDropDown> data, const char* label) {


        static float Y;
        static float targetY;
        static float dy;
        static float easing = 0.12;




        bool anyTrue = false;

        for (int i = 0; i < data.size(); i++) {
            if (data[i].value->data) {
                anyTrue = true;
            }
        }
        int TotalWidth = 0; // make sure that we dont draw text extending the with of the bar
        int NTW = 0; // next text width for the texts in the main bar
        bool active = false;

        if (cursorInRegion(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight)) {
            if (key_pressed(VK_LBUTTON) && ((!IGui::GK && !IGui::GO) || (!anyTrue && DropDownList[Index::DDI].isClicked))) {
                DropDownList[Index::DDI].isClicked = !DropDownList[Index::DDI].isClicked;

                if (DropDownList[Index::DDI].isClicked) {
                    aList[std::make_pair(categoryActiveID, label)].targetVal = 1;
                    aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(categoryActiveID, label)].startVal = 0;
                    Y = 0;
                    targetY = 1;
                }
                else {
                    aList[std::make_pair(categoryActiveID, label)].targetVal = 0;
                    aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(categoryActiveID, label)].startVal = 1;
                }
                IGui::GO = true;

            }
        }
        dy = targetY - Y;
        Y += dy * easing;

        if (DropDownList[Index::DDI].isClicked) {
            DrawTriangleQ(x + IGui::DropDownWidth - 14, y + IGui::DropDownTextMargin + 14, IM_COL32(255, 255, 255, 255), false);
            DrawRectGradientQ(x + IGui::DropDownWidth - 30, y + IGui::DropDownTextMargin, 15, IGui::DropDownHeight, IM_COL32(30, 30, 30, 0), IM_COL32(30, 30, 30, 255), IM_COL32(30, 30, 30, 255), IM_COL32(30, 30, 30, 0));
            DrawRectQ(x + IGui::DropDownWidth - 15, y + IGui::DropDownTextMargin, 15, IGui::DropDownHeight, 3, IM_COL32(30, 30, 30, 255));
        }
        if (!DropDownList[Index::DDI].isClicked) {
            DrawTriangleQ(x + IGui::DropDownWidth - 14, y + IGui::DropDownTextMargin + 10, IM_COL32(255, 255, 255, 255), true);
            DrawRectGradientQ(x + IGui::DropDownWidth - 30, y + IGui::DropDownTextMargin, 15, IGui::DropDownHeight, IM_COL32(30, 30, 30, 0), IM_COL32(30, 30, 30, 255), IM_COL32(30, 30, 30, 255), IM_COL32(30, 30, 30, 0));
            DrawRectQ(x + IGui::DropDownWidth - 15, y + IGui::DropDownTextMargin, 15, IGui::DropDownHeight, 3, IM_COL32(30, 30, 30, 255));

        }
        if (!anyTrue) {
            DrawMessageQ(MenuModern, x + 6, y + IGui::DropDownTextMargin + 2, "No Selection...", IM_COL32(180, 180, 180, 255));

            //  if (cursorInRegion())
        }


        for (int i = 0; i < data.size(); i++) {


            if (!data[i].value->data) continue;
            ImGui::PushFont(multiModern);
            int addOn = 0;
            if (i + 1 < data.size())
                addOn = CalcTextSize(data[i + 1].label);
            int width = CalcTextSize(data[i].label) + 8;


            ImGui::PopFont();
            DrawMessageQ(multiModern, x + 6 + NTW, y + IGui::DropDownTextMargin + 4, data[i].label, IM_COL32(255, 255, 255, 255));
            if (cursorInRegion(x + 2 + NTW, y + IGui::DropDownTextMargin + 4, width, 14) && (x + 2 + NTW + width) < x + IGui::DropDownWidth - 15) {
                DrawRectQ(x + 2 + NTW, y + IGui::DropDownTextMargin + 3, width, 17, 3, IM_COL32(53, 53, 53, 255));
                if (key_pressed(VK_LBUTTON) && ((!IGui::GK && !IGui::GO) || DropDownList[Index::DDI].isClicked)) {
                    data[i].value->data = false;
                }
            }
            else {
                DrawRectQ(x + 2 + NTW, y + IGui::DropDownTextMargin + 3, width, 17, 3, IM_COL32(43, 43, 43, 255));
            }

            NTW += CalcTextSize(data[i].label) + 10;

            if (NTW + addOn > IGui::DropDownWidth) break;

        }

        if (DropDownList[Index::DDI].isClicked || aList[std::make_pair(categoryActiveID, label)].value > 0.1) {
            if (DropDownList[Index::DDI].isClicked) {
                active = true;
                IGui::GO = true;
            }
            DrawTriangleQ(x + IGui::DropDownWidth - 14, y + IGui::DropDownTextMargin + 14, IM_COL32(255, 255, 255, 255), false);
            DrawRectQ(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 4, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255) : IM_COL32(35, 35, 35, 255), ImDrawCornerFlags_Top);

            for (int i = 0; i < data.size(); i++) {




                data[i].value->dx = data[i].value->targetX - data[i].value->X;
                data[i].value->X += data[i].value->dx * 0.05;

                static float rMult = 255.f / 232.f;

                static  float gMult = 255.f / 36.f;
                static float bMult = 255.f / 114.f;
                float m2 = aList[std::make_pair(categoryActiveID, data[i].label)].value;
                float m = 1.f - m2;

                if (!data[i].value->data) {
                    data[i].value->targetX = 0.01f;
                    aList[std::make_pair(categoryActiveID, data[i].label)].targetVal = 0.01f;


                    //    ch - ------------------------------------------ ainm here

                }
                else {
                    data[i].value->targetX = 1.f;
                    aList[std::make_pair(categoryActiveID, data[i].label)].targetVal = 1.f;
                    //  DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22) + 1 , data[i].label, IM_COL32(rMult* m > 1 ? 232 * (rMult * m) : 232, gMult* m> 1 ? 36 * (gMult * m) : 36, bMult* m > 1 ? 114 * (bMult * m) : 114, 255));

                }
                animLinear(data[i].label, 150);
                DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22) + 1, data[i].label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255 * aList[std::make_pair(categoryActiveID, label)].value));

                if (cursorInRegion(x, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22), IGui::DropDownWidth, IGui::DropDownHeight)) {
                    if (i != data.size() - 1)
                        DrawRectQ(x, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22), IGui::DropDownWidth, IGui::DropDownHeight, 0, IM_COL32(45, 45, 45, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_All);
                    else
                        DrawRectQ(x, y + IGui::DropDownHeight + IGui::DropDownTextMargin + (i * 22), IGui::DropDownWidth, IGui::DropDownHeight, 4, IM_COL32(45, 45, 45, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_Bot);

                    if (key_pressed(VK_LBUTTON)) {
                        data[i].value->data = !data[i].value->data;
                        // DropDownList[Index::DDI].isClicked = false;
                        // IGui::waiting = true;


                    }
                }
                if (i != data.size() - 1)
                    DrawRectQ(x, y + 22 + (i * 22) + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 0, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255 * aList[std::make_pair(categoryActiveID, label)].value) : IM_COL32(35, 35, 35, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_All);
                else
                    DrawRectQ(x, y + 22 + (i * 22) + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 4, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255 * aList[std::make_pair(categoryActiveID, label)].value) : IM_COL32(35, 35, 35, 255 * aList[std::make_pair(categoryActiveID, label)].value), ImDrawCornerFlags_Bot);



            }

            if (!cursorInRegion(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, (data.size() + 1) * 22)) {
                if (key_pressed(VK_LBUTTON)) {
                    DropDownList[Index::DDI].isClicked = false;
                    IGui::waiting = true;
                    targetY = 0;
                    aList[std::make_pair(categoryActiveID, label)].targetVal = 0;
                    aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                    aList[std::make_pair(categoryActiveID, label)].startVal = 1;
                }
            }

            if (key_pressed(VK_ESCAPE)) {
                DropDownList[Index::DDI].isClicked = false;
                IGui::waiting = true;
                targetY = 0;
                aList[std::make_pair(categoryActiveID, label)].targetVal = 0;
                aList[std::make_pair(categoryActiveID, label)].start = std::chrono::high_resolution_clock::now();
                aList[std::make_pair(categoryActiveID, label)].startVal = 1;
            }

        }
        if (!DropDownList[Index::DDI].isClicked) {
            //   DrawTriangleQ(x + IGui::DropDownWidth - 14, y + IGui::DropDownTextMargin + 10, IM_COL32(255, 255, 255, 255), true);

               //   DrawMessageQ(MenuModern, x + 5, y + IGui::DropDownTextMargin + 1, data[manage], IM_COL32(255, 255, 255, 255));
            DrawRectQ(x, y + IGui::DropDownTextMargin, IGui::DropDownWidth, IGui::DropDownHeight, 4, IGui::DropDownWidth > 100 ? IM_COL32(30, 30, 30, 255) : IM_COL32(35, 35, 35, 255), ImDrawCornerFlags_All);

        }


        animLinear(label, 100);
        Index::DDI++;
        return active;
    }
    void dbl::DrawDropDown(int& manage, std::vector<const char*> data, const char* label) {
        elementSpacing += 1;
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

        }
        int width = CalcTextSize(label);
        int x = childX;
        int y = childY + elementSpacing;
        IGui::DropDownWidth = 120;
        DrawDropDownA(childX + 110, childY + elementSpacing, manage, data, label);
        std::string cmpit(label);

        static bool startedSequenceDown = false;

        if (IGui::SearchSequence == cmpit) {
            SANIM.ay = SANIM.targeta - SANIM.a;
            SANIM.a += SANIM.ay * 0.03;
            if (!startedSequenceDown)
                SANIM.targeta = 1.f;
            float m2 = SANIM.a;
            float m = 1.f - m2;
            static float rMult = 255.f / 232.f;

            static  float gMult = 255.f / 36.f;
            static float bMult = 255.f / 114.f;

            DrawMessageQ(MenuModern, x, y + 1, label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255));
            //  DrawRect(x + 24, y + 18, width, 1, 0, IM_COL32(232, 36, 114, 255 * SANIM.a));
            if (!startedSequenceDown) {

                DrawLine(ImVec2(x, y + 17), ImVec2(x + (width * SANIM.a), y + 17), 1, IM_COL32(232, 36, 114, 255));
            }
            else {

                DrawLine(ImVec2(x + (width * m), y + 17), ImVec2(x + width, y + 17), 1, IM_COL32(232, 36, 114, 255 * SANIM.a));
            }
            if (SANIM.a > 0.95) {
                SANIM.targeta = 0.f;
                startedSequenceDown = true;
            }

            if (SANIM.a < 0.05 && startedSequenceDown) {
                IGui::SearchSequence = "";
                startedSequenceDown = false;
            }


        }
        else {
            DrawMessageQ(MenuModern, x, y + 1, label, IM_COL32_WHITE);
        }


        // DrawMessageQ(MenuModern, childX, childY + elementSpacing + 1, label, IM_COL32(255, 255, 255, 255));
        elementSpacing += 27;
    }
    void DrawMultiDropDown(std::vector<MultiDropDown> data, const char* label) {
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

        }
        IGui::DropDownWidth = 120;
        DrawMultiDropDownA(childX + 110, childY + elementSpacing, data, label);

        int x = childX;
        int y = childY + elementSpacing;
        int width = CalcTextSize(label);
        std::string cmpit(label);

        static bool startedSequenceDown = false;

        if (IGui::SearchSequence == cmpit) {
            SANIM.ay = SANIM.targeta - SANIM.a;
            SANIM.a += SANIM.ay * 0.03;
            if (!startedSequenceDown)
                SANIM.targeta = 1.f;
            float m2 = SANIM.a;
            float m = 1.f - m2;
            static float rMult = 255.f / 232.f;

            static  float gMult = 255.f / 36.f;
            static float bMult = 255.f / 114.f;

            DrawMessageQ(MenuModern, x, y + 1, label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255));
            //  DrawRect(x + 24, y + 18, width, 1, 0, IM_COL32(232, 36, 114, 255 * SANIM.a));
            if (!startedSequenceDown) {

                DrawLine(ImVec2(x, y + 17), ImVec2(x + (width * SANIM.a), y + 17), 1, IM_COL32(232, 36, 114, 255));
            }
            else {

                DrawLine(ImVec2(x + (width * m), y + 17), ImVec2(x + width, y + 17), 1, IM_COL32(232, 36, 114, 255 * SANIM.a));
            }
            if (SANIM.a > 0.95) {
                SANIM.targeta = 0.f;
                startedSequenceDown = true;
            }

            if (SANIM.a < 0.05 && startedSequenceDown) {
                IGui::SearchSequence = "";
                startedSequenceDown = false;
            }


        }
        else {
            DrawMessageQ(MenuModern, x, y + 1, label, IM_COL32_WHITE);
        }
        elementSpacing += 26;
    }
    void DrawDropDownKeyBind(int& manage, std::vector<const char*> data, const char* label) {
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

        }
        IGui::DropDownWidth = 60;

        DrawDropDownA(childX, childY + elementSpacing, manage, data, label);
        DrawMessageQ(MenuModern, childX + 5, childY + elementSpacing, label, IM_COL32(255, 255, 255, 255));
        // elementSpacing += 55;
    }
    int StringHexToInt(std::string hex) {
        if (hex.empty()) return 0;
        unsigned int x;
        std::stringstream ss;
        ss << std::hex << hex;
        ss >> x;
        return x;
    }

    ImVec4 HexToImVec4(int hexValue)
    {
        return ImVec4(((hexValue >> 16) & 0xFF), ((hexValue >> 8) & 0xFF), ((hexValue) & 0xFF), 255);
    }
    void ColourPickerInit(int x, int y, Color& col) {

        int maxAlphaX = x + 138;
        int minAlphaX = x + 10;
        int minHueY = y + 34;
        int maxHueY = y + 34 + 128;


        col.HueYPos = minHueY + ((maxHueY - minHueY) * col.Hue());

        float start = menuPos.y + y + 34;
        float end = menuPos.y + y + 34 + 128;
        col.hue = (menuPos.y + col.HueYPos - start) / (end - start);
        col.CircleY = minHueY + ((maxHueY - minHueY) * (1 - col.Brightness()));
        col.CircleX = minAlphaX + ((maxAlphaX - minAlphaX) * col.Saturation());
        ImVec4 colv = ColorConvertU32ToFloat4(col.GetU32());
        col.r.str = std::to_string((int)colv.x);
        col.g.str = std::to_string((int)colv.y);
        col.b.str = std::to_string((int)colv.z);
        col.hex.str = rgb2hex(colv.x, colv.y, colv.z, false);
        col.AlphaX = maxAlphaX;
        int test = createRGB(colv.x, colv.y, colv.z);
        //col.hue = (menuPos.y + col.HueYPos - minHueY) / (maxHueY - minHueY);



    }

    bool DrawInputBox(int x, int y, int w, int h, String& str, int max, bool allowletters) {

        h += 1;
        static int timer = 0;
        ImGui::PushFont(bigModern);
        int width = CalcTextSize(str.str.c_str());
        int rectWidth = x + w - x;
        ImGui::PopFont();
        int xa = x + (rectWidth - width) / 2;
        DrawMessageQ(bigModern, xa, y + 1, str.str.c_str(), IM_COL32(220, 220, 220, 255));

        bool active = false;
        if (str.isClicked) {
            if (key_pressed(VK_RETURN)) str.isClicked = false;
            timer += globalTimer;
            if (timer > 500 && timer < 1000)
                DrawRectQ(xa + width + 1, y + 3, 1, 14, 0, IM_COL32(220, 220, 220, 255));
            if (timer > 1000) timer = 0;
            listentoKeys();
            DrawRectQ(x, y, w, h, 3, IM_COL32(60, 60, 60, 255));
            if ((key_pressed(VK_BACK)) && str.str.length() > 0) {
                str.str.pop_back();
                Sleep(50);
            }
            if (str.str.empty()) {
                DrawMessage(SearchModern, 82 + 21, 54, "...");

            }

            if (str.str.length() < max) {

                std::string hold = listeningKeyA();
                int val = 0;
                if (max == 3) {
                    val = !str.str.empty() ? std::stoi(str.str + hold) : 0;
                }
                if ((!(!allowletters && hold == "a" || hold == "b" || hold == "c" || hold == "d" || hold == "e" || hold == "f")) || max > 3) {
                    if ((max == 3 && val <= 255) || max > 3) {
                        active = true;
                        str.str += hold;
                    }
                }

            }
        }
        else {
            active = false;
        }

        if (cursorInRegion(x, y, w, h)) {
            DrawRectQ(x, y, w, h, 3, IM_COL32(50, 50, 50, 255));
            if (key_pressed(VK_LBUTTON)) {
                str.isClicked = !str.isClicked;
            }
        }
        else {
            DrawRectQ(x, y, w, h, 3, IM_COL32(35, 35, 35, 255));

            if (key_pressed(VK_LBUTTON)) {
                str.isClicked = false;
            }
        }


        return active;

    }

    void DClamp(int& val, int min, int max) {
        if (val > max) val = max;
        if (val < min) val = min;
    }
    bool DrawColourPickerA(int x, int y, Color& col, const char* id) {

        bool active = false;

        static float circleS = 1;
        static float tCircleS = 1;
        static float dyCircleS = 1;
        static float dyCirleEasing = 0.1;
        static float Y;
        static float targetY;
        static float dy;
        static float easing = 0.07;

        Y = aList[std::make_pair(categoryActiveID, "colpicker")].value;
        int maxAlphaX = x + 133;
        int minAlphaX = x + 5;
        int minHueY = y + 29;
        int maxHueY = y + 29 + 123;

        if (colMGR[id].AlphaX < x && colMGR[id].CircleX < x && colMGR[id].CircleY < y && colMGR[id].HueYPos < y) {
            ColourPickerInit(x - 5, y - 5, colMGR[id]);
            colMGR[id].SetColour(col[0] * 255, col[1] * 255, col[2] * 255, col[3] * 255);
        }


        if (!key_down(VK_LBUTTON)) {
            colMGR[id].isHeldDown = false;
            colMGR[id].isHeldDownAlpha = false;
            colMGR[id].isHeldDownHue = false;
        }
        const ImU32 col_hues[6 + 1] = { IM_COL32(255,0,0,255), IM_COL32(255,255,0,255), IM_COL32(0,255,0,255), IM_COL32(0,255,255,255), IM_COL32(0,0,255,255), IM_COL32(255,0,255,255), IM_COL32(255,0,0,255) };

        /*if (colMGR[id].isActive) {*/
            DrawRectQ(x + 24, y + 5, 9, 9, 3, colMGR[id].GetU32());
       /* }*/
       /* else {
            DrawRectQ(x + 24, y + 5, 9, 9, 3, colMGR[id].tempCol);
        }*/
        DrawImageQ(x, y - 1, 40, 20, IM_COL32(255, 255, 255, 255), bucketTexture);
        DrawRectQ(x, y, 40, 19, 5, IM_COL32(30, 30, 30, 255));

        ImVec4 hue_color_f(1, 1, 1, 1);
        ImGui::ColorConvertHSVtoRGB(colMGR[id].hue, 1, 1, hue_color_f.x, hue_color_f.y, hue_color_f.z);
        ImU32 hue_color32 = ImGui::ColorConvertFloat4ToU32(hue_color_f);
        float s = 1;
        float v = 1;
        if (cursorInRegion(x, y, 40, 19)) {
            if (key_pressed(VK_LBUTTON) && !IGui::GO && (!IGui::GK || IGui::calledFromMulti)) {
                colMGR[id].isClicked = !colMGR[id].isClicked;

                if (colMGR[id].isClicked) {
                    aList[std::make_pair(categoryActiveID, "colpicker")].startVal = 20;
                    aList[std::make_pair(categoryActiveID, "colpicker")].targetVal = 0;
                    aList[std::make_pair(categoryActiveID, "colpicker")].start = std::chrono::high_resolution_clock::now();

                }
                return true; // prevents instantly closing colour picker

            }
        }
        animLinear("colpicker", 80);

        ImVec4 colConv = ColorConvertU32ToFloat4(colMGR[id].GetU32());

        if (colMGR[id].isClicked) {
            x -= 5;
            y -= 5;
            y += Y;

            active = true;
            IGui::GO = true;
            DrawRectQ(x + 145, colMGR[id].HueYPos + Y, 10, 3, 0, IM_COL32_WHITE);





            DrawRectQ(x + 145, y + 33 + 128 + 8, 10, 10, 0, colMGR[id].GetU32()); // col preview bot right
            DrawRectQ(x + 144, y + 33 + 128 + 7, 12, 12, 0, IM_COL32(60, 60, 60, 255)); // col preview bot right border



            if ((cursorInRegion(x + 10, y + 34 + 128 + 7, 128, 10) && !colMGR[id].isHeldDown && !colMGR[id].isHeldDownHue) || colMGR[id].isHeldDownAlpha) { // alpha bar 
                if (key_down(VK_LBUTTON)) {
                    colMGR[id].AlphaX = cp.x - menuPos.x;
                    DClamp(colMGR[id].AlphaX, x + 10, x + 138);
                    colMGR[id].isHeldDownAlpha = true;


                    float startS = menuPos.x + x + 10;
                    float endS = menuPos.x + x + 10 + 128;
                    float alpha = (menuPos.x + colMGR[id].AlphaX - startS) / (endS - startS);
                    colMGR[id].SetA(alpha * 255);
                }
            }

            if ((cursorInRegion(x + 145, y + 34, 10, 128) || colMGR[id].isHeldDownHue) && !colMGR[id].isHeldDown && !colMGR[id].isHeldDownAlpha) { // hue bar
                if (key_down(VK_LBUTTON)) {
                    GetCursorPos(&cp);
                    colMGR[id].HueYPos = cp.y - menuPos.y;
                    DClamp(colMGR[id].HueYPos, y + 34, y + 34 + 124);
                    colMGR[id].isHeldDownHue = true;
                    float startS = menuPos.x + x + 10;
                    float endS = menuPos.x + x + 10 + 128;
                    float startV = menuPos.y + y + 34;
                    float endV = menuPos.y + y + 34 + 128;
                    float start = menuPos.y + y + 34;
                    float end = menuPos.y + y + 34 + 128;
                    colMGR[id].hue = (menuPos.y + colMGR[id].HueYPos - start) / (end - start);
                    s = (menuPos.x + colMGR[id].CircleX - startS) / (endS - startS);
                    v = (menuPos.y + colMGR[id].CircleY - startV) / (endV - startV);

                    colMGR[id] = colMGR[id].FromHSB((menuPos.y + colMGR[id].HueYPos - start) / (end - start), s, 1 - v, 1);
                    ImVec4 col4 = ColorConvertU32ToFloat4(colMGR[id].GetU32());
                    int rVal = col4.x;
                    int gVal = col4.y;
                    int bVal = col4.z;
                    colMGR[id].temp = ColorConvertU32ToFloat4(colMGR[id].GetU32());
                    colMGR[id].hex.str = rgb2hex(rVal, gVal, bVal, false);
                    colMGR[id].r.str = std::to_string(rVal);
                    colMGR[id].g.str = std::to_string(gVal);
                    colMGR[id].b.str = std::to_string(bVal);

                    float alpha = (menuPos.x + colMGR[id].AlphaX - startS) / (endS - startS);
                    colMGR[id].SetA(alpha * 255);
                }
            }

            if (colMGR[id].CircleX > maxAlphaX) colMGR[id].CircleX = maxAlphaX;
            if (colMGR[id].CircleX < minAlphaX) colMGR[id].CircleX = minAlphaX;
            if (colMGR[id].CircleY > maxHueY + 3) colMGR[id].CircleY = maxHueY + 3;
            if (colMGR[id].CircleY < minHueY) colMGR[id].CircleY = minHueY;

            if (cursorInRegion(x + 10, y + 34, 128, 128) && !colMGR[id].isHeldDownHue && !colMGR[id].isHeldDownAlpha || colMGR[id].isHeldDown) { // square bar
                int tempAlpha = colMGR[id].alpha;
                if (key_down(VK_LBUTTON)) {
                    tCircleS = 1.5;
                    colMGR[id].CircleX = cp.x - menuPos.x;
                    colMGR[id].CircleY = cp.y - menuPos.y;
                    if (colMGR[id].CircleX > maxAlphaX) colMGR[id].CircleX = maxAlphaX;
                    if (colMGR[id].CircleX < minAlphaX) colMGR[id].CircleX = minAlphaX;
                    if (colMGR[id].CircleY > maxHueY + 5) colMGR[id].CircleY = maxHueY + 5;
                    if (colMGR[id].CircleY < minHueY) colMGR[id].CircleY = minHueY;

                    float startS = menuPos.x + x + 10;
                    float endS = menuPos.x + x + 10 + 128;
                    float startV = menuPos.y + y + 34;
                    float endV = menuPos.y + y + 34 + 128;
                    s = (menuPos.x + colMGR[id].CircleX - startS) / (endS - startS);
                    v = (menuPos.y + colMGR[id].CircleY - startV) / (endV - startV);

                    colMGR[id] = colMGR[id].FromHSB((menuPos.y + colMGR[id].HueYPos - startV) / (endV - startV), s, 1 - v, 1);
                    colMGR[id].alpha = tempAlpha;
                    ImVec4 col4 = ColorConvertU32ToFloat4(colMGR[id].GetU32());



                    int rVal = col4.x;
                    int gVal = col4.y;
                    int bVal = col4.z;
                    colMGR[id].hex.str = rgb2hex(rVal, gVal, bVal, false);
                    colMGR[id].r.str = std::to_string(rVal);
                    colMGR[id].g.str = std::to_string(gVal);
                    colMGR[id].b.str = std::to_string(bVal);

                    colMGR[id].isHeldDown = true;

                    float alpha = (menuPos.x + colMGR[id].AlphaX - startS) / (endS - startS);
                    colMGR[id].SetA(alpha * 255);

                }
                else {
                    tCircleS = 1;
                }
            }
            else {
                tCircleS = 1;
            }

            dyCircleS = tCircleS - circleS;
            circleS += dyCircleS * dyCirleEasing;
            DrawCircleQ(colMGR[id].CircleX, colMGR[id].CircleY + Y, 6 * circleS, false, IM_COL32_WHITE);
            DrawCircleQ(colMGR[id].CircleX, colMGR[id].CircleY + Y, 6 * circleS, true, colMGR[id].GetU32());


            DrawRectQ(colMGR[id].AlphaX, y + 34 + 128 + 7, 3, 10, 0, IM_COL32_WHITE);
            DrawRectGradientQ(x + 10, y + 34 + 128 + 7, 128, 10, IM_COL32_BLACK_TRANS, IM_COL32(colConv.x, colConv.y, colConv.z, 255), IM_COL32(colConv.x, colConv.y, colConv.z, 255), IM_COL32_BLACK_TRANS); // alpha bar
            DrawRectQ(x + 9, y + 33 + 128 + 7, 130, 12, 0, IM_COL32(60, 60, 60, 255));
            for (int i = 0; i < 6; i++) {
                DrawRectGradientQ(x + 145, y + 34 + i * (130 / 6), 10, 130 / 6, col_hues[i], col_hues[i], col_hues[i + 1], col_hues[i + 1]); // hue bar 360 / 6 relative
            }
            DrawRectQ(x + 144, y + 33, 12, 128, 0, IM_COL32(0, 0, 0, 255));

            DrawRectGradientQ(x + 10, y + 34, 128, 128, 0, 0, IM_COL32_BLACK, IM_COL32_BLACK); // square --------------------------------------
            DrawRectGradientQ(x + 10, y + 34, 128, 128, IM_COL32_WHITE, hue_color32, hue_color32, IM_COL32_WHITE);
            DrawRectQ(x + 9, y + 33, 130, 130, 0, IM_COL32(60, 60, 60, 255));


            if (DrawInputBox(x + 106, y + 187, 50, 17, colMGR[id].hex, 6, true)) { // hex input box

                colMGR[id].hexInt = StringHexToInt(colMGR[id].hex.str); // convert the string of hex value to int
                ImVec4 temp = HexToImVec4(colMGR[id].hexInt); // convert integer of hex value to imvec4 

                colMGR[id].SetColour(temp.x, temp.y, temp.z, 255);
                ColourPickerInit(x, y, colMGR[id]); // initialize colour picker positions (circle, huebarypos, alphaxpos) after changing the input


            }
            if (DrawInputBox(x + 10, y + 187, 30, 17, colMGR[id].r, 3, false)) { // r input box 
                if (!colMGR[id].r.str.empty()) {
                    int val = std::stoi(colMGR[id].r.str);
                    colMGR[id].SetR(val);
                    ImVec4 col4 = ColorConvertU32ToFloat4(colMGR[id].GetU32());
                    colMGR[id].hex.str = rgb2hex(col4.x, col4.y, col4.z, true);
                    ColourPickerInit(x, y, colMGR[id]);
                }
            }
            if (DrawInputBox(x + 42, y + 187, 30, 17, colMGR[id].g, 3, false)) { // g input box 
                if (!colMGR[id].g.str.empty()) {
                    int val = std::stoi(colMGR[id].g.str);
                    colMGR[id].SetG(val);
                    ImVec4 col4 = ColorConvertU32ToFloat4(colMGR[id].GetU32());
                    colMGR[id].hex.str = rgb2hex(col4.x, col4.y, col4.z, true);
                    ColourPickerInit(x, y, colMGR[id]); // initialize colour picker positions (circle, huebarypos, alphaxpos) after changing the input
                }
            }
            if (DrawInputBox(x + 74, y + 187, 30, 17, colMGR[id].b, 3, false)) { // b input box
                if (!colMGR[id].b.str.empty()) {
                    int val = std::stoi(colMGR[id].b.str);
                    colMGR[id].SetB(val);
                    ImVec4 col4 = ColorConvertU32ToFloat4(colMGR[id].GetU32());
                    colMGR[id].hex.str = rgb2hex(col4.x, col4.y, col4.z, true);
                    ColourPickerInit(x, y, colMGR[id]); // initialize colour picker positions (circle, huebarypos, alphaxpos) after changing the input
                }
            }

            x += 5;
            y += 5;
            y -= Y;

            DrawRectQ(x, y + 24 + Y, 155, 180, 3, IM_COL32(28, 28, 28, 255)); // entire background
            DrawRectQ(x - 1, y + 23 + Y, 157, 182, 3, IM_COL32(38, 38, 38, 255)); // entire background

            if (!cursorInRegion(x, y + 24, 165, 225)) {
                if (key_pressed(VK_LBUTTON)) {
                    colMGR[id].isClicked = false;
                    IGui::waiting = true;

                    aList[std::make_pair(categoryActiveID, "colpicker")].targetVal = 20;

                }
            }

            if (key_pressed(VK_ESCAPE)) {
                colMGR[id].isClicked = false;
                IGui::waiting = true;

                aList[std::make_pair(categoryActiveID, "colpicker")].targetVal = 20;

            }

        }
      
        return active;
    }

    Color DrawColourPickerMA(int x, int y, Color& col, const char* id, const char* label, bool isActive, Color realCol) {

        //tempCol = IM_COL32(arrColor[COLOR_R], arrColor[COLOR_G], arrColor[COLOR_B], tempAlpha);
        //col.tempCol = IM_COL32(col.ge[COLOR_R], col.arrColor[COLOR_G], col.arrColor[COLOR_B], col.tempAlpha);
        bool active = false;

        static float circleS = 1;
        static float tCircleS = 1;
        static float dyCircleS = 1;
        static float dyCirleEasing = 0.1;
        static float Y;
        static float targetY;
        static float dy;
        static float easing = 0.07;

        Y = aList[std::make_pair(categoryActiveID, "colpicker")].value;
        int maxAlphaX = x + 133;
        int minAlphaX = x + 5;
        int minHueY = y + 29;
        int maxHueY = y + 29 + 123;

        if (!col.init) {
            col = realCol;
            col.init = true;
        }
        if (col.AlphaX < x && col.CircleX < x && col.CircleY < y && col.HueYPos < y) {

            ColourPickerInit(x - 5, y - 5, col);

        }


        if (!key_down(VK_LBUTTON)) {
            col.isHeldDown = false;
            col.isHeldDownAlpha = false;
            col.isHeldDownHue = false;
        }
        const ImU32 col_hues[6 + 1] = { IM_COL32(255,0,0,255), IM_COL32(255,255,0,255), IM_COL32(0,255,0,255), IM_COL32(0,255,255,255), IM_COL32(0,0,255,255), IM_COL32(255,0,255,255), IM_COL32(255,0,0,255) };

        /*   if (col.isActive) {*/
        DrawRectQ(x + 24, y + 5, 9, 9, 3, col.GetU32());
        /*   }*/
         /*  else {
               DrawRectQ(x + 24, y + 5, 9, 9, 3, col.tempCol);
           }*/
        DrawImageQ(x, y - 1, 40, 20, IM_COL32(255, 255, 255, 255), bucketTexture);


        ImVec4 hue_color_f(1, 1, 1, 1);
        ImGui::ColorConvertHSVtoRGB(col.hue, 1, 1, hue_color_f.x, hue_color_f.y, hue_color_f.z);
        ImU32 hue_color32 = ImGui::ColorConvertFloat4ToU32(hue_color_f);
        float s = 1;
        float v = 1;
        if (cursorInRegion(x, y, 40, 19)) {

            DrawRectQ(x, y, 40, 19, 5, IM_COL32(45, 45, 45, 255));
            if (key_pressed(VK_LBUTTON) && !isOpen["copyPasteTab"].isOpen && !IGui::GO && (!IGui::GK || IGui::calledFromMulti)) {

                col.isClicked = !col.isClicked;

                if (col.isClicked) {
                    aList[std::make_pair(categoryActiveID, "colpicker")].startVal = 20;
                    aList[std::make_pair(categoryActiveID, "colpicker")].targetVal = 0;
                    aList[std::make_pair(categoryActiveID, "colpicker")].start = std::chrono::high_resolution_clock::now();

                }
                if (isActive)
                    return col; // prevents instantly closing colour picker
                else
                    return Color(0, 0, 0, 0);

            }
            if (key_pressed(VK_RBUTTON) && !IGui::GO && (!IGui::GK || IGui::calledFromMulti)) {
                col.copyPasteTab = !col.copyPasteTab;

                if (isActive)
                    return col; // prevents instantly closing colour picker
                else
                    return Color(0, 0, 0, 0);

            }
        }
        DrawRectQ(x, y, 40, 19, 5, IM_COL32(30, 30, 30, 255));
        animLinear("colpicker", 80);

        ImVec4 colConv = ColorConvertU32ToFloat4(col.GetU32());

        if (col.isClicked) {
            x -= 5;
            y -= 5;
            y += Y;

            active = true;
            IGui::GO = true;
            DrawRectQ(x + 145, col.HueYPos + Y, 10, 3, 0, IM_COL32_WHITE);





            DrawRectQ(x + 145, y + 33 + 128 + 8, 10, 10, 0, col.GetU32()); // col preview bot right
            DrawRectQ(x + 144, y + 33 + 128 + 7, 12, 12, 0, IM_COL32(60, 60, 60, 255)); // col preview bot right border



            if ((cursorInRegion(x + 10, y + 34 + 128 + 7, 128, 10) && !col.isHeldDown && !col.isHeldDownHue) || col.isHeldDownAlpha) { // alpha bar 
                if (key_down(VK_LBUTTON)) {
                    col.AlphaX = cp.x - menuPos.x;
                    DClamp(col.AlphaX, x + 10, x + 138);
                    col.isHeldDownAlpha = true;


                    float startS = menuPos.x + x + 10;
                    float endS = menuPos.x + x + 10 + 128;
                    float alpha = (menuPos.x + col.AlphaX - startS) / (endS - startS);
                    col.SetA(alpha * 255);
                }
            }

            if ((cursorInRegion(x + 145, y + 34, 10, 128) || col.isHeldDownHue) && !col.isHeldDown && !col.isHeldDownAlpha) { // hue bar
                if (key_down(VK_LBUTTON)) {
                    GetCursorPos(&cp);
                    col.HueYPos = cp.y - menuPos.y;
                    DClamp(col.HueYPos, y + 34, y + 34 + 124);
                    col.isHeldDownHue = true;
                    float startS = menuPos.x + x + 10;
                    float endS = menuPos.x + x + 10 + 128;
                    float startV = menuPos.y + y + 34;
                    float endV = menuPos.y + y + 34 + 128;
                    float start = menuPos.y + y + 34;
                    float end = menuPos.y + y + 34 + 128;
                    col.hue = (menuPos.y + col.HueYPos - start) / (end - start);
                    s = (menuPos.x + col.CircleX - startS) / (endS - startS);
                    v = (menuPos.y + col.CircleY - startV) / (endV - startV);

                    col = col.FromHSB((menuPos.y + col.HueYPos - start) / (end - start), s, 1 - v, 1);
                    ImVec4 col4 = ColorConvertU32ToFloat4(col.GetU32());
                    int rVal = col4.x;
                    int gVal = col4.y;
                    int bVal = col4.z;
                    col.temp = ColorConvertU32ToFloat4(col.GetU32());
                    col.hex.str = rgb2hex(rVal, gVal, bVal, false);
                    col.r.str = std::to_string(rVal);
                    col.g.str = std::to_string(gVal);
                    col.b.str = std::to_string(bVal);

                    float alpha = (menuPos.x + col.AlphaX - startS) / (endS - startS);
                    col.SetA(alpha * 255);
                }
            }

            if (col.CircleX > maxAlphaX) col.CircleX = maxAlphaX;
            if (col.CircleX < minAlphaX) col.CircleX = minAlphaX;
            if (col.CircleY > maxHueY + 3) col.CircleY = maxHueY + 3;
            if (col.CircleY < minHueY) col.CircleY = minHueY;

            if (cursorInRegion(x + 10, y + 34, 128, 128) && !col.isHeldDownHue && !col.isHeldDownAlpha || col.isHeldDown) { // square bar
                int tempAlpha = col.alpha;
                if (key_down(VK_LBUTTON)) {
                    tCircleS = 1.5;
                    col.CircleX = cp.x - menuPos.x;
                    col.CircleY = cp.y - menuPos.y;
                    if (col.CircleX > maxAlphaX) col.CircleX = maxAlphaX;
                    if (col.CircleX < minAlphaX) col.CircleX = minAlphaX;
                    if (col.CircleY > maxHueY + 5) col.CircleY = maxHueY + 5;
                    if (col.CircleY < minHueY) col.CircleY = minHueY;

                    float startS = menuPos.x + x + 10;
                    float endS = menuPos.x + x + 10 + 128;
                    float startV = menuPos.y + y + 34;
                    float endV = menuPos.y + y + 34 + 128;
                    s = (menuPos.x + col.CircleX - startS) / (endS - startS);
                    v = (menuPos.y + col.CircleY - startV) / (endV - startV);

                    col = col.FromHSB((menuPos.y + col.HueYPos - startV) / (endV - startV), s, 1 - v, 1);
                    col.alpha = tempAlpha;
                    ImVec4 col4 = ColorConvertU32ToFloat4(col.GetU32());



                    int rVal = col4.x;
                    int gVal = col4.y;
                    int bVal = col4.z;
                    col.hex.str = rgb2hex(rVal, gVal, bVal, false);
                    col.r.str = std::to_string(rVal);
                    col.g.str = std::to_string(gVal);
                    col.b.str = std::to_string(bVal);

                    col.isHeldDown = true;

                    float alpha = (menuPos.x + col.AlphaX - startS) / (endS - startS);
                    col.SetA(alpha * 255);

                }
                else {
                    tCircleS = 1;
                }
            }
            else {
                tCircleS = 1;
            }

            dyCircleS = tCircleS - circleS;
            circleS += dyCircleS * dyCirleEasing;
            DrawCircleQ(col.CircleX, col.CircleY + Y, 6 * circleS, false, IM_COL32_WHITE);
            DrawCircleQ(col.CircleX, col.CircleY + Y, 6 * circleS, true, col.GetU32());


            DrawRectQ(col.AlphaX, y + 34 + 128 + 7, 3, 10, 0, IM_COL32_WHITE);
            DrawRectGradientQ(x + 10, y + 34 + 128 + 7, 128, 10, IM_COL32_BLACK_TRANS, IM_COL32(colConv.x, colConv.y, colConv.z, 255), IM_COL32(colConv.x, colConv.y, colConv.z, 255), IM_COL32_BLACK_TRANS); // alpha bar
            DrawRectQ(x + 9, y + 33 + 128 + 7, 130, 12, 0, IM_COL32(60, 60, 60, 255));
            for (int i = 0; i < 6; i++) {
                DrawRectGradientQ(x + 145, y + 34 + i * (130 / 6), 10, 130 / 6, col_hues[i], col_hues[i], col_hues[i + 1], col_hues[i + 1]); // hue bar 360 / 6 relative
            }
            DrawRectQ(x + 144, y + 33, 12, 128, 0, IM_COL32(0, 0, 0, 255));

            DrawRectGradientQ(x + 10, y + 34, 128, 128, 0, 0, IM_COL32_BLACK, IM_COL32_BLACK); // square --------------------------------------
            DrawRectGradientQ(x + 10, y + 34, 128, 128, IM_COL32_WHITE, hue_color32, hue_color32, IM_COL32_WHITE);
            DrawRectQ(x + 9, y + 33, 130, 130, 0, IM_COL32(60, 60, 60, 255));


            if (DrawInputBox(x + 106, y + 187, 50, 17, col.hex, 6, true)) { // hex input box

                col.hexInt = StringHexToInt(col.hex.str); // convert the string of hex value to int
                ImVec4 temp = HexToImVec4(col.hexInt); // convert integer of hex value to imvec4 

                col.SetColour(temp.x, temp.y, temp.z, 255);
                ColourPickerInit(x, y, col); // initialize colour picker positions (circle, huebarypos, alphaxpos) after changing the input


            }
            if (DrawInputBox(x + 10, y + 187, 30, 17, col.r, 3, false)) { // r input box 
                if (!col.r.str.empty()) {
                    int val = std::stoi(col.r.str);
                    col.SetR(val);
                    ImVec4 col4 = ColorConvertU32ToFloat4(col.GetU32());
                    col.hex.str = rgb2hex(col4.x, col4.y, col4.z, true);
                    ColourPickerInit(x, y, col);
                }
            }
            if (DrawInputBox(x + 42, y + 187, 30, 17, col.g, 3, false)) { // g input box 
                if (!col.g.str.empty()) {
                    int val = std::stoi(col.g.str);
                    col.SetG(val);
                    ImVec4 col4 = ColorConvertU32ToFloat4(col.GetU32());
                    col.hex.str = rgb2hex(col4.x, col4.y, col4.z, true);
                    ColourPickerInit(x, y, col); // initialize colour picker positions (circle, huebarypos, alphaxpos) after changing the input
                }
            }
            if (DrawInputBox(x + 74, y + 187, 30, 17, col.b, 3, false)) { // b input box
                if (!col.b.str.empty()) {
                    int val = std::stoi(col.b.str);
                    col.SetB(val);
                    ImVec4 col4 = ColorConvertU32ToFloat4(col.GetU32());
                    col.hex.str = rgb2hex(col4.x, col4.y, col4.z, true);
                    ColourPickerInit(x, y, col); // initialize colour picker positions (circle, huebarypos, alphaxpos) after changing the input
                }
            }

            x += 5;
            y += 5;
            y -= Y;

            DrawRectQ(x, y + 24 + Y, 155, 180, 3, IM_COL32(28, 28, 28, 255)); // entire background
            DrawRectQ(x - 1, y + 23 + Y, 157, 182, 3, IM_COL32(38, 38, 38, 255)); // entire background

            if (!cursorInRegion(x, y + 24, 165, 225)) {

                if (key_pressed(VK_LBUTTON)) {
                    col.isClicked = false; // not this
                    IGui::waiting = true;

                    aList[std::make_pair(categoryActiveID, "colpicker")].targetVal = 20;

                }
            }


            if (key_pressed(VK_ESCAPE)) {
                col.isClicked = false;
                IGui::waiting = true;

                aList[std::make_pair(categoryActiveID, "colpicker")].targetVal = 20;

            }

        }

        if (col.copyPasteTab) {
            ImGui::PushFont(MenuModern);
            int widthCopy = CalcTextSize("Copy");
            int widthPaste = CalcTextSize("Paste");
            ImGui::PopFont();


            DrawMessageQ(MenuModern, x + 57, y + 3, "Copy", IM_COL32(210, 210, 210, 255));
            DrawMessageQ(MenuModern, x + 57, y + 25, "Paste", IM_COL32(210, 210, 210, 255));

            if (cursorInRegion(x + 52, y + 2, widthPaste + 10, 20)) { // copy hover

                DrawRectQ(x + 52, y + 2, widthPaste + 10, 20, 3, IM_COL32(50, 50, 50, 255)); // hover rect

                if (key_pressed(VK_LBUTTON)) {
                    IGui::ColorClipboard = col;
                }

            }


            DrawRectQ(x + 52, y + 2, widthPaste + 10, 20, 3, IM_COL32(40, 40, 40, 255));

            if (cursorInRegion(x + 52, y + 24, widthPaste + 10, 20)) { // paste hover

                DrawRectQ(x + 52, y + 24, widthPaste + 10, 20, 3, IM_COL32(50, 50, 50, 255)); // hover rect

                if (key_pressed(VK_LBUTTON)) {

                    col = IGui::ColorClipboard;
                    ColourPickerInit(x - 5, y - 5, col);
                }
            }



            DrawRectQ(x + 52, y + 24, widthPaste + 10, 20, 3, IM_COL32(40, 40, 40, 255));


            isOpen["copyPasteTab"].isOpen = true;
            DrawRectQ(x + 50, y, widthPaste + 14, 46, 5, IM_COL32(30, 30, 30, 255));

            if (!cursorInRegion(x + 50, y, 100, 60)) {
                if (key_pressed(VK_LBUTTON) || key_pressed(VK_RBUTTON)) {
                    col.copyPasteTab = false;
                    isOpen["copyPasteTab"].waiting = true;
                    if (isActive)
                        return col; // prevents instantly closing colour picker
                    else
                        return Color(0, 0, 0, 0);
                }
            }


        }

        if (isActive)
            return col; // prevents instantly closing colour picker

        return Color(0, 0, 0, 0);
    }
    bool DrawMultiPickerA(int x, int y, bool& change, const char* label, Color& col1, Color& col2, Color& col3, std::string id, std::vector<const char*> data) {
        IGui::calledFromMulti = true;
        ImGuiContext& g = *GImGui;
        std::string preCut = label;
        std::string idStr = preCut + id;

        ImGuiIO& io = g.IO;
        const ImGuiStyle& style = g.Style;
        std::string label2 = label;
        bool active = false;
        int margin = 190;
        int maxwidth = 0;
        bool colb1, colb2, colb3;
        for (int i = 0; i < data.size(); i++) { // Drawing the labels next to the colour pickers
            std::string dataLabel = data[i];
            animLinear2(idStr + dataLabel, 150);
            float a = aList[std::make_pair(categoryActiveID, idStr + dataLabel)].value;
            ImGui::PushFont(MenuModern);
            int width = CalcTextSize(data[i]); // calculating the width of the text to draw the cross for disabling
            ImGui::PopFont();
            if (width > maxwidth) maxwidth = width;
            if (mulColMGR[std::make_pair(idStr, data[0])].mulClicked) {

                if ((i == 0 && !mulColMGR[std::make_pair(idStr, data[0])].isActive || i == 1 && !mulColMGR[std::make_pair(idStr, data[1])].isActive || i == 2 && !mulColMGR[std::make_pair(idStr, data[2])].isActive) || aList[std::make_pair(categoryActiveID, idStr + dataLabel)].inProgress) {

                    DrawLineQ(ImVec2(x + margin + 5, y + 10 + (25 * (i + 1)) + 9), ImVec2(x + margin + 5 + (width * a), y + 10 + (25 * (i + 1)) + 9), 1, IM_COL32(255, 255, 255, 255 * a));

                }
                if (cursorInRegion(x + margin + 5, y + 5 + (25 * (i + 1)), width, 22)) {

                    g.MouseCursor = ImGuiMouseCursor_Hand;
                    if (key_pressed(VK_LBUTTON) && !isOpen["copyPasteTab"].isOpen) {
                        aList[std::make_pair(categoryActiveID, idStr + dataLabel)].start = std::chrono::high_resolution_clock::now();
                        if (i == 0) {
                            mulColMGR[std::make_pair(idStr, data[0])].isActive = !mulColMGR[std::make_pair(idStr, data[0])].isActive;
                            mulColMGR[std::make_pair(idStr, data[0])].ManageColour();
                            if (!mulColMGR[std::make_pair(idStr, data[0])].isActive) {

                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].targetVal = 1.f;
                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].startVal = 0.f;
                            }
                            else {

                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].targetVal = 0.f;
                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].startVal = 1.f;
                            }
                        }
                        if (i == 1) {
                            mulColMGR[std::make_pair(idStr, data[1])].isActive = !mulColMGR[std::make_pair(idStr, data[1])].isActive;
                            mulColMGR[std::make_pair(idStr, data[1])].ManageColour();
                            if (!mulColMGR[std::make_pair(idStr, data[1])].isActive) {

                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].targetVal = 1.f;
                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].startVal = 0.f;
                            }
                            else {

                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].targetVal = 0.f;
                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].startVal = 1.f;
                            }
                        }
                        if (i == 2) {
                            if (!mulColMGR[std::make_pair(idStr, data[2])].isActive) {

                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].targetVal = 1.f;
                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].startVal = 0.f;
                            }
                            else {

                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].targetVal = 0.f;
                                aList[std::make_pair(categoryActiveID, idStr + dataLabel)].startVal = 1.f;
                            }
                            mulColMGR[std::make_pair(idStr, data[2])].isActive = !mulColMGR[std::make_pair(idStr, data[2])].isActive;
                            mulColMGR[std::make_pair(idStr, data[2])].ManageColour();
                        }
                    }
                }
                DrawMessageQ(MenuModern, x + margin + 5, y + 10 + (25 * (i + 1)), data[i], IM_COL32(210, 210, 210, 255 - (100 * a))); // text being drawn (visible, not visible)
            }
        }
        if (mulColMGR[std::make_pair(idStr, data[0])].mulClicked) {
            IGui::GM = true;
            active = true;

            maxwidth += 10;
            IGui::GK = true;

            col1 = DrawColourPickerMA(x + margin + maxwidth, y + 35, spareColours[&col1], data[0], label, mulColMGR[std::make_pair(idStr, data[0])].isActive, col1);
            DrawRectQ(x + margin + maxwidth - 1, y + 35 - 1, 42, 21, 5, IM_COL32(38, 38, 38, 255));
            col2 = DrawColourPickerMA(x + margin + maxwidth, y + 60, spareColours[&col2], data[1], label, mulColMGR[std::make_pair(idStr, data[1])].isActive, col2);
            DrawRectQ(x + margin + maxwidth - 1, y + 60 - 1, 42, 21, 5, IM_COL32(38, 38, 38, 255));
            if (data.size() == 3) {
                col3 = DrawColourPickerMA(x + margin + maxwidth, y + 85, spareColours[&col3], data[2], label, mulColMGR[std::make_pair(idStr, data[2])].isActive, col3);
                DrawRectQ(x + margin + maxwidth - 1, y + 85 - 1, 42, 21, 5, IM_COL32(38, 38, 38, 255));
            }
            DrawRectQ(x + margin, y + 30, maxwidth + 44, data.size() * 25 + 4, 3, IM_COL32(32, 32, 32, 255));
            DrawRectQ(x + margin - 1, y + 30 - 1, maxwidth + 46, data.size() * 25 + 6, 3, IM_COL32(38, 38, 38, 255));


            if (!cursorInRegion(x + margin - 1, y + 30 - 1, maxwidth + 46, data.size() * 25 + 7) && !isOpen["copyPasteTab"].isOpen) {
                if ((key_pressed(VK_LBUTTON) && !IGui::GO && IGui::GM)) {
                    IGui::waitingM = true;
                    mulColMGR[std::make_pair(idStr, data[0])].mulClicked = false;
                    IGui::waitingK = true;
                    // return active;



                }
            }

        }


        if (key_pressed(VK_ESCAPE) && !IGui::GO) {
            mulColMGR[std::make_pair(idStr, data[0])].mulClicked = false;
            IGui::GM = false;
            IGui::GK = false;

        }

        DrawRectUFQ(x + margin + 22, y + 3, 13, 13, 5, IM_COL32(30, 30, 30, 255), 3);
        /*
          if (mulColMGR[std::make_pair(label, id)].isActive) {
            DrawRectQ(x + 24, y + 5, 9, 9, 3, mulColMGR[std::make_pair(label, id)].GetU32());
        }
        else {
            DrawRectQ(x + 24, y + 5, 9, 9, 3, mulColMGR[std::make_pair(label, id)].tempCol);
        }*/
        /*  std::string dataLabel = data[0];
          std::string dataLabel1 = data[1];
          ImU32 col1D = IM_COL32(col1.Base<COLOR_R>() * 255, col1.Base<COLOR_G>() * 255, col1.Base<COLOR_B>() * 255, 255 * (1.f - aList[std::make_pair(categoryActiveID, label + dataLabel)].value));
          ImU32 col2D = IM_COL32(col2.Base<COLOR_R>() * 255, col2.Base<COLOR_G>() * 255, col2.Base<COLOR_B>() * 255, 255 * (1.f - aList[std::make_pair(categoryActiveID, label + dataLabel1)].value));*/
        DrawRectGradientQ(x + margin + 24, y + 5, 9, 9, col1.GetU32(), col1.GetU32(), col2.GetU32(), col2.GetU32());

        DrawImageQ(x + margin, y - 1, 40, 20, IM_COL32(255, 255, 255, 255), bucketTexture);
        DrawRectQ(x + margin, y, 40, 19, 5, IM_COL32(30, 30, 30, 255));



        IGui::calledFromMulti = false;
        if (cursorInRegion(x + margin, y - 1, 40, 20)) {
            if (key_pressed(VK_LBUTTON) && !IGui::GO && !IGui::GM) {
                mulColMGR[std::make_pair(idStr, data[0])].mulClicked = !mulColMGR[std::make_pair(idStr, data[0])].mulClicked;
                return active;
            }
        }


        return active;
    }
    void dbl::DrawMultiPicker(bool& change, Color& col1, Color& col2, Color& col3, const char* label, std::string id, std::vector<const char*> data, std::string tooltip) {

        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

            mulColMGR[std::make_pair(label, data[0])].SetColour(col1[0] * 255, col1[1] * 255, col1[2] * 255, col1[3] * 255);
            mulColMGR[std::make_pair(label, data[1])].SetColour(col2[0] * 255, col2[1] * 255, col2[2] * 255, col2[3] * 255);
            if (data.size() == 3) {
                mulColMGR[std::make_pair(label, data[2])].SetColour(col3[0] * 255, col3[1] * 255, col3[2] * 255, col3[3] * 255);
            }

        }

        DrawMultiPickerA(childX, childY + elementSpacing, change, label, col1, col2, col3, id, data);
        DrawCheckBoxA(childX, childY + elementSpacing, change, label, id, tooltip);
        elementSpacing += 23;
    }

  

    void dbl::DrawCheckBoxColourPicker(bool& change, Color& col, const char* label) {
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);

        }
        DrawCheckBoxA(childX, childY + elementSpacing, change, label, "someid", "");
        DrawColourPickerA(childX + 190, childY + elementSpacing + 1, col, label);
        elementSpacing += 25;
    }
    /*
    void DrawModal(const char* label, std::vector<Modal> data) {
        bool anyTabOpen = false;
        for (Modal obj : data) {
            if (obj.value->keyBindTab) anyTabOpen = true;
        }
        static int timer = 0;
        static bool ready = false;
        static bool AnyOpen = false; // used so we don't close the popup when interacting with a colour picker
        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);
        }
        int xa = childX;
        int ya = childY + elementSpacing;
        int width = CalcTextSize(label);
        std::string cmpit(label);
        static bool startedSequenceDown = false;
        if (IGui::SearchSequence == cmpit) {
            SANIM.ay = SANIM.targeta - SANIM.a;
            SANIM.a += SANIM.ay * 0.03;
            if (!startedSequenceDown)
                SANIM.targeta = 1.f;
            float m2 = SANIM.a;
            float m = 1.f - m2;
            static float rMult = 255.f / 232.f;
            static  float gMult = 255.f / 36.f;
            static float bMult = 255.f / 114.f;
            DrawMessageQ(MenuModern, xa, ya + 1, label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255));
            //  DrawRect(x + 24, y + 18, width, 1, 0, IM_COL32(232, 36, 114, 255 * SANIM.a));
            if (!startedSequenceDown) {
                DrawLine(ImVec2(xa, ya + 17), ImVec2(xa + (width * SANIM.a), ya + 17), 1, IM_COL32(232, 36, 114, 255));
            }
            else {
                DrawLine(ImVec2(xa + (width * m), ya + 17), ImVec2(xa + width, ya + 17), 1, IM_COL32(232, 36, 114, 255 * SANIM.a));
            }
            if (SANIM.a > 0.95) {
                SANIM.targeta = 0.f;
                startedSequenceDown = true;
            }
            if (SANIM.a < 0.05 && startedSequenceDown) {
                IGui::SearchSequence = "";
                startedSequenceDown = false;
            }
        }
        else {
            DrawMessageQ(MenuModern, xa, ya + 1, label, IM_COL32_WHITE);
        }
        //  DrawMessageQ(MenuModern, childX, childY + elementSpacing + 1, label, IM_COL32(255, 255, 255, 255));
        DrawImageQ(childX + 201, childY + elementSpacing, 20, 20, IM_COL32_WHITE, modalTexture);
        DrawRectQ(childX + 190, childY + elementSpacing, 40, 20, 4, IM_COL32(30, 30, 30, 255));
        if (!ready) {
            timer += globalTimer;
        }
        if (timer > 50) ready = true;
        int x = childX + 190;
        int y = childY + elementSpacing;
        if (data[0].value->bSpare) {
            IGui::GO = true;
            AnyOpen = false;
            for (int i = 0; i < data.size(); i++) {
                IGui::GO = false;
                if (!data[i].value->data) {
                    //   DrawRectQ(x + 10 + 2, y + 35 + i * 25 + 2, 11, 11, 2, IM_COL32(30, 30, 30, 255), ImDrawCornerFlags_All);
                }
                DrawCheckBoxA(x + 10, y + 35 + i * 25, *data[i].value, data[i].label, "cockinass");
                if (data[i].colMGR[id].size() == 1) {
                    if (DrawColourPickerA(x + 150, y + 33 + i * 25, *data[i].col[0].col)) {
                        AnyOpen = true;
                    }
                }
                else if (data[i].colMGR[id].size() == 2) {
                    if (DrawMultiPickerA(x - 40, y + 33 + i * 25, *data[0].value, "", *data[i].col[0].col, *data[i].col[1].col, *data[i].col[1].col, { data[i].col[0].label, data[i].col[1].label })) {
                        AnyOpen = true;
                    }
                }
                IGui::GO = true;
                //   DrawMessageQ(MenuModern, x + 33, y + 33 + i * 25, data[i].label, IM_COL32_WHITE);
            }
            DrawRectQ(x, y + 25, 200, data.size() * 25 + 10, 4, IM_COL32(30, 30, 30, 255));
            DrawRectQ(x - 1, y + 24, 202, data.size() * 25 + 12, 4, IM_COL32(38, 38, 38, 255));
        }
        if (!cursorInRegion(x, y + 25, 200, data.size() * 25 + 12) && ready && !AnyOpen && !anyTabOpen) {
            if (key_pressed(VK_LBUTTON)) {
                IGui::waiting = true;
                data[0].value->bSpare = false;
            }
        }
        if (key_pressed(VK_ESCAPE) && ready && !AnyOpen && !anyTabOpen) {
            IGui::waiting = true;
            data[0].value->bSpare = false;
        }
        if (cursorInRegion(childX + 190, childY + elementSpacing, 40, 20)) {
            if (key_pressed(VK_LBUTTON) && !IGui::GK && !IGui::GO) {
                data[0].value->bSpare = !data[0].value->bSpare;
                if (data[0].value->bSpare) {
                }
                else {
                }
                if (data[0].value->bSpare == false) {
                }
                ready = false;
                timer = 0;
            }
        }
        elementSpacing += 25;
    }
    */

   
    void dbl::DrawSliderInt(int& change, int min, int max, const char* label) {
        change *= 100;
        min *= 100;
        max *= 100;
        std::string animLabel = std::string(label) + "hover";
        childY += 5;
        ImGuiContext& g = *GImGui;

        ImGuiIO& io = g.IO;
        static  int valueX;
        const ImGuiStyle& style = g.Style;

        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);
            if (change >= max) change = max;
            if (change <= min) change = min;
            valueX = ((change - min) * (IGui::SliderWidth) / (max - min));
            sliderMGR[std::make_pair(categoryActiveID, label)].targetX = valueX;
            sliderMGR[std::make_pair(categoryActiveID, label)].X = valueX;
            if (valueX < 0) valueX = 0;

        }
      //  static const char* selectedSlider = "";
        float aMult = 255.f / 1;
        int fr = ImGui::GetIO().Framerate;
        float easing = 0.3;
        if (fr < 60) {
            easing = 0.6;
        }
        else if (fr < 30) {
            easing = 0.8;
        }
        else if (fr < 15) {
            easing = 1;
        }


        sliderMGR[std::make_pair(categoryActiveID, label)].easing = easing;
        sliderMGR[std::make_pair(categoryActiveID, label)].dx =  sliderMGR[std::make_pair(categoryActiveID, label)].targetX -  sliderMGR[std::make_pair(categoryActiveID, label)].X;
         sliderMGR[std::make_pair(categoryActiveID, label)].X +=  sliderMGR[std::make_pair(categoryActiveID, label)].dx *  sliderMGR[std::make_pair(categoryActiveID, label)].easing;

         sliderMGR[std::make_pair(categoryActiveID, label)].ceasing = easing / 2;
         sliderMGR[std::make_pair(categoryActiveID, label)].cdx =  sliderMGR[std::make_pair(categoryActiveID, label)].ctargetX -  sliderMGR[std::make_pair(categoryActiveID, label)].cX;
         sliderMGR[std::make_pair(categoryActiveID, label)].cX +=  sliderMGR[std::make_pair(categoryActiveID, label)].cdx *  sliderMGR[std::make_pair(categoryActiveID, label)].ceasing;


         static auto selectedSlider = std::make_pair(0, "");
        int sliderPosX = 50;
        std::string value_string(16, '\0');




       


         sliderMGR[std::make_pair(categoryActiveID, label)].dymult =  sliderMGR[std::make_pair(categoryActiveID, label)].targetmult -  sliderMGR[std::make_pair(categoryActiveID, label)].mult;
         sliderMGR[std::make_pair(categoryActiveID, label)].mult +=  sliderMGR[std::make_pair(categoryActiveID, label)].dymult * 0.1;

        bool anyTrue = false;
        //  for (int l = 0; l < sliderArrCount; l++) {
           //   if (sliderStructureArr[l].isPressed) anyTrue = true;
        //  }

        float m = (1.f - (99 -  sliderMGR[std::make_pair(categoryActiveID, label)].cX) / 15);
        float m2 = (99 -  sliderMGR[std::make_pair(categoryActiveID, label)].cX) / 15;


        if ((cursorInRegion(childX, childY + elementSpacing + 19, IGui::SliderWidth - 6, 9) || sliderMGR[std::make_pair(categoryActiveID, label)].isPressed) && key_down(VK_LBUTTON) && (selectedSlider == std::make_pair(categoryActiveID, label) || selectedSlider == std::make_pair(0, "notpressed"))) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isPressed = true;

             selectedSlider = std::make_pair(categoryActiveID, label);

            float value_unmapped = std::clamp(cp.x - menuPos.x - childX, 0.0f, static_cast<float>(IGui::SliderWidth)); // yoinked from zgui
            int value_mapped = static_cast<int>(value_unmapped / IGui::SliderWidth * (max - min) + min);
            ImGuiContext& g = *GImGui;
            g.MouseCursor = ImGuiMouseCursor_ResizeEW;
            change = value_mapped;
             sliderMGR[std::make_pair(categoryActiveID, label)].targetmult = 2;
            if (!aList[std::make_pair(categoryActiveID, label)].inProgress)
                aList[std::make_pair(categoryActiveID, label)].targetVal = 2;

           // selectedSlider = sliderArrCount;
            valueX = ((change - min) * (IGui::SliderWidth) / (max - min));
            sliderMGR[std::make_pair(categoryActiveID, label)].targetX = valueX;

        }





        

        {
            //if (cp.x >= menuPos.x + childX - 10 && cp.x <= menuPos.x + childX + 210 && cp.y >= menuPos.y + elementSpacing + childY && cp.y + 5 <= menuPos.y + elementSpacing + childY + 37) {
            // 
            //   //  sliderMGR[std::make_pair(categoryActiveID, label)].ctargetX = 99;
            // 
            //}
            //else {
            // 
            //    if (! sliderMGR[std::make_pair(categoryActiveID, label)].isPressed) 
            //     sliderMGR[std::make_pair(categoryActiveID, label)].ctargetX = 84;
            //}
        }
        if (!key_down(VK_LBUTTON)) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isPressed = false;
             sliderMGR[std::make_pair(categoryActiveID, label)].targetmult = 1;
            if (!aList[std::make_pair(categoryActiveID, label)].inProgress)
                aList[std::make_pair(categoryActiveID, label)].targetVal = 1;
            selectedSlider = std::make_pair(0, "notpressed");
        }
        if (change >= max) change = max;
        if (change <= min) change = min;
        auto written = std::snprintf(&value_string[0], value_string.size(), "%d.0", change / 100);
        value_string.resize(written);





        std::string buff = std::to_string(change / 100) + ".0";



        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 4, true, IM_COL32(180, 180, 180, 255));

        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 5, true, IM_COL32(255, 255, 255, 255));

        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 7, true, IM_COL32(220, 221, 222, 255));
        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 7 * aList[std::make_pair(categoryActiveID, label)].value, true, IM_COL32(220, 220, 220, 140));
        //if (change != 0)
        DrawRectQ(childX, childY + elementSpacing + 20,  sliderMGR[std::make_pair(categoryActiveID, label)].X, 7, 5, IM_COL32(237, 36, 116, 255));



        DrawRectQ(childX, childY + elementSpacing + 20, IGui::SliderWidth - 7, 7, 5, IM_COL32(20, 20, 20, 255));
        DrawRectQ(childX, childY + elementSpacing + 19, IGui::SliderWidth - 6, 9, 5, IM_COL32(36, 36, 36, 255));

        char* actual = _strdup(buff.c_str());

        int widd = CalcTextSize(actual);
        //  DrawTriangeB( sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 5, childY + elementSpacing - 5 + 17, IM_COL32(32, 32, 32, 255));
        if (!IGui::GK && !IGui::GO) {
            DrawTriangleQ( sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 3, childY + elementSpacing + 10, IM_COL32(32, 32, 32, 255 * aList[std::make_pair(categoryActiveID, animLabel)].value), true);
            DrawMessageQ(MenuModern,  sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 2 - widd / 2, childY + elementSpacing - 8, actual, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(categoryActiveID,animLabel)].value));
            DrawRectQ( sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 20, childY + elementSpacing - 7, 40, 17, 3, IM_COL32(32, 32, 32, 255 * aList[std::make_pair(categoryActiveID, animLabel)].value));


        }
        animLinear(animLabel, 100);
        if (cursorInRegion(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X - 6, childY + elementSpacing + 23 - 6, 12, 12) ||  sliderMGR[std::make_pair(categoryActiveID, label)].isPressed) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isHovered = true;
            if (!aList[std::make_pair(categoryActiveID, animLabel)].inProgress)
                aList[std::make_pair(categoryActiveID, animLabel)].targetVal = 1;

        }
        else {
             sliderMGR[std::make_pair(categoryActiveID, label)].isHovered = false;
            if (!aList[std::make_pair(categoryActiveID, animLabel)].inProgress)
                aList[std::make_pair(categoryActiveID, animLabel)].targetVal = 0;

        }


        //  DrawRectQ(childX - 1, childY + elementSpacing + 20 - 1, IGui::SliderWidth, 9, 5, IM_COL32(25, 25, 25, 255));

        std::string cmpit(label);
        childY -= 5;
        if (!(IGui::SearchSequence == cmpit))
            DrawMessageQ(MenuModern, childX, childY + elementSpacing, label, IM_COL32_WHITE);
        int x = childX;
        int y = childY + elementSpacing;
        ImGui::PushFont(MenuModern);
        int width = CalcTextSize(label);

        ImGui::PopFont();
        if (IGui::GK || IGui::GO) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isHovered = false;
             sliderMGR[std::make_pair(categoryActiveID, label)].isPressed = false;
        }


        static bool startedSequenceDown = false;

        if (IGui::SearchSequence == cmpit) {
            SANIM.ay = SANIM.targeta - SANIM.a;
            SANIM.a += SANIM.ay * 0.03;
            if (!startedSequenceDown)
                SANIM.targeta = 1.f;
            float m2 = SANIM.a;
            float m = 1.f - m2;
            static float rMult = 255.f / 232.f;

            static  float gMult = 255.f / 36.f;
            static float bMult = 255.f / 114.f;

            DrawMessageQ(MenuModern, x, y, label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255));
            //  DrawRect(x + 24, y + 18, width, 1, 0, IM_COL32(232, 36, 114, 255 * SANIM.a));
            if (!startedSequenceDown) {

                DrawLine(ImVec2(x, y + 18), ImVec2(x + (width * SANIM.a), y + 18), 1, IM_COL32(232, 36, 114, 255));
            }
            else {

                DrawLine(ImVec2(x + (width * m), y + 18), ImVec2(x + width, y + 18), 1, IM_COL32(232, 36, 114, 255 * SANIM.a));
            }
            if (SANIM.a > 0.95) {
                SANIM.targeta = 0.f;
                startedSequenceDown = true;
            }

            if (SANIM.a < 0.05 && startedSequenceDown) {
                IGui::SearchSequence = "";
                startedSequenceDown = false;
            }


        }
        else {

        }

        animLinear(label, 100);
        elementSpacing += 40;
     

        change /= 100;
        min /= 100;
        max /= 100;
    }

  
    void dbl::DrawSliderFloat(float& change, float min, float max, const char* label) {
        change *= 100;
        min *= 100;
        max *= 100;
        std::string animLabel = std::string(label) + "hover";
        childY += 5;
        ImGuiContext& g = *GImGui;

        ImGuiIO& io = g.IO;
        static  int valueX;
        const ImGuiStyle& style = g.Style;

        if (!itemInKeywords(label)) {
            KeyWordInfo add;
            add.String = label;
            std::string test = "bla";
            add.categoryID = categoryActiveID;
            add.pageID = navID;
            keywordList.emplace_back(add);
            valueX = ((change - min) * (IGui::SliderWidth) / (max - min));

            if (valueX < 0) valueX = 0;
        }
        static    int selectedSlider = 0;
        float aMult = 255.f / 1;
        int fr = ImGui::GetIO().Framerate;
        float easing = 0.3;
        if (fr < 60) {
            easing = 0.6;
        }
        else if (fr < 30) {
            easing = 0.8;
        }
        else if (fr < 15) {
            easing = 1;
        }


         sliderMGR[std::make_pair(categoryActiveID, label)].easing = easing;
         sliderMGR[std::make_pair(categoryActiveID, label)].dx =  sliderMGR[std::make_pair(categoryActiveID, label)].targetX -  sliderMGR[std::make_pair(categoryActiveID, label)].X;
         sliderMGR[std::make_pair(categoryActiveID, label)].X +=  sliderMGR[std::make_pair(categoryActiveID, label)].dx *  sliderMGR[std::make_pair(categoryActiveID, label)].easing;

         sliderMGR[std::make_pair(categoryActiveID, label)].ceasing = easing / 2;
         sliderMGR[std::make_pair(categoryActiveID, label)].cdx =  sliderMGR[std::make_pair(categoryActiveID, label)].ctargetX -  sliderMGR[std::make_pair(categoryActiveID, label)].cX;
         sliderMGR[std::make_pair(categoryActiveID, label)].cX +=  sliderMGR[std::make_pair(categoryActiveID, label)].cdx *  sliderMGR[std::make_pair(categoryActiveID, label)].ceasing;


        int sliderPosX = 50;
        std::string value_string(16, '\0');




        animLinear(label, 100);


         sliderMGR[std::make_pair(categoryActiveID, label)].dymult =  sliderMGR[std::make_pair(categoryActiveID, label)].targetmult -  sliderMGR[std::make_pair(categoryActiveID, label)].mult;
         sliderMGR[std::make_pair(categoryActiveID, label)].mult +=  sliderMGR[std::make_pair(categoryActiveID, label)].dymult * 0.1;

        bool anyTrue = false;
        //  for (int l = 0; l < sliderArrCount; l++) {
           //   if (sliderStructureArr[l].isPressed) anyTrue = true;
        //  }

        float m = (1.f - (99 -  sliderMGR[std::make_pair(categoryActiveID, label)].cX) / 15);
        float m2 = (99 -  sliderMGR[std::make_pair(categoryActiveID, label)].cX) / 15;


        if ((((((cp.x >= menuPos.x + childX - 10 && cp.x <= menuPos.x + childX + 210 && cp.y >= menuPos.y + elementSpacing + childY && cp.y + 5 <= menuPos.y + elementSpacing + childY + 37) && !IGui::GO && !IGui::GK && key_pressed(VK_LBUTTON)))) && selectedSlider != 0) && !IGui::GO ||  sliderMGR[std::make_pair(categoryActiveID, label)].isPressed && selectedSlider == sliderArrCount) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isPressed = true;

            float value_unmapped = std::clamp(cp.x - menuPos.x - childX, 0.0f, static_cast<float>(IGui::SliderWidth)); // yoinked from zgui
            int value_mapped = static_cast<int>(value_unmapped / IGui::SliderWidth * (max - min) + min);

            change = value_mapped;
             sliderMGR[std::make_pair(categoryActiveID, label)].targetmult = 2;
            if (!aList[std::make_pair(categoryActiveID, label)].inProgress)
                aList[std::make_pair(categoryActiveID, label)].targetVal = 2;

            selectedSlider = sliderArrCount;
            valueX = ((change - min) * (IGui::SliderWidth) / (max - min));

        }





         sliderMGR[std::make_pair(categoryActiveID, label)].targetX = valueX;

        {
            //if (cp.x >= menuPos.x + childX - 10 && cp.x <= menuPos.x + childX + 210 && cp.y >= menuPos.y + elementSpacing + childY && cp.y + 5 <= menuPos.y + elementSpacing + childY + 37) {
            // 
            //   //  sliderMGR[std::make_pair(categoryActiveID, label)].ctargetX = 99;
            // 
            //}
            //else {
            // 
            //    if (! sliderMGR[std::make_pair(categoryActiveID, label)].isPressed) 
            //     sliderMGR[std::make_pair(categoryActiveID, label)].ctargetX = 84;
            //}
        }
        if (!key_down(VK_LBUTTON)) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isPressed = false;
             sliderMGR[std::make_pair(categoryActiveID, label)].targetmult = 1;
            if (!aList[std::make_pair(categoryActiveID, label)].inProgress)
                aList[std::make_pair(categoryActiveID, label)].targetVal = 1;
            selectedSlider = -1;
        }
        if (change >= max) change = max;
        if (change <= min) change = min;
        auto written = std::snprintf(&value_string[0], value_string.size(), "%d.0", change / 100);
        value_string.resize(written);





        std::string buff = std::to_string(change / 100) + ".0";



        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 4, true, IM_COL32(180, 180, 180, 255));

        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 5, true, IM_COL32(255, 255, 255, 255));

        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 7, true, IM_COL32(220, 221, 222, 255));
        DrawCircleQ(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X, childY + elementSpacing + 23, 7 * aList[std::make_pair(categoryActiveID, label)].value, true, IM_COL32(220, 220, 220, 140));
        //if (change != 0)
        DrawRectQ(childX, childY + elementSpacing + 20,  sliderMGR[std::make_pair(categoryActiveID, label)].X, 7, 5, IM_COL32(237, 36, 116, 255));



        DrawRectQ(childX, childY + elementSpacing + 20, IGui::SliderWidth - 7, 7, 5, IM_COL32(20, 20, 20, 255));
        DrawRectQ(childX, childY + elementSpacing + 19, IGui::SliderWidth - 6, 9, 5, IM_COL32(36, 36, 36, 255));

        char* actual = _strdup(buff.c_str());

        int widd = CalcTextSize(actual);
        //  DrawTriangeB( sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 5, childY + elementSpacing - 5 + 17, IM_COL32(32, 32, 32, 255));
        if (!IGui::GK && !IGui::GO) {
            DrawTriangleQ( sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 3, childY + elementSpacing + 10, IM_COL32(32, 32, 32, 255 * aList[std::make_pair(categoryActiveID, animLabel)].value), true);
            DrawMessageQ(MenuModern,  sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 2 - widd / 2, childY + elementSpacing - 8, actual, IM_COL32(255, 255, 255, 255 * aList[std::make_pair(categoryActiveID, animLabel)].value));
            DrawRectQ( sliderMGR[std::make_pair(categoryActiveID, label)].X + childX - 20, childY + elementSpacing - 7, 40, 17, 3, IM_COL32(32, 32, 32, 255 * aList[std::make_pair(categoryActiveID, animLabel)].value));


        }
        animLinear(animLabel, 100);
        if (cursorInRegion(childX +  sliderMGR[std::make_pair(categoryActiveID, label)].X - 6, childY + elementSpacing + 23 - 6, 12, 12) ||  sliderMGR[std::make_pair(categoryActiveID, label)].isPressed) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isHovered = true;
            if (!aList[std::make_pair(categoryActiveID, animLabel)].inProgress)
                aList[std::make_pair(categoryActiveID, animLabel)].targetVal = 1;

        }
        else {
             sliderMGR[std::make_pair(categoryActiveID, label)].isHovered = false;
            if (!aList[std::make_pair(categoryActiveID, animLabel)].inProgress)
                aList[std::make_pair(categoryActiveID, animLabel)].targetVal = 0;

        }


        //  DrawRectQ(childX - 1, childY + elementSpacing + 20 - 1, IGui::SliderWidth, 9, 5, IM_COL32(25, 25, 25, 255));

        std::string cmpit(label);
        childY -= 5;
        if (!(IGui::SearchSequence == cmpit))
            DrawMessageQ(MenuModern, childX, childY + elementSpacing, label, IM_COL32_WHITE);
        int x = childX;
        int y = childY + elementSpacing;
        ImGui::PushFont(MenuModern);
        int width = CalcTextSize(label);

        ImGui::PopFont();
        if (IGui::GK || IGui::GO) {
             sliderMGR[std::make_pair(categoryActiveID, label)].isHovered = false;
             sliderMGR[std::make_pair(categoryActiveID, label)].isPressed = false;
        }


        static bool startedSequenceDown = false;

        if (IGui::SearchSequence == cmpit) {
            SANIM.ay = SANIM.targeta - SANIM.a;
            SANIM.a += SANIM.ay * 0.03;
            if (!startedSequenceDown)
                SANIM.targeta = 1.f;
            float m2 = SANIM.a;
            float m = 1.f - m2;
            static float rMult = 255.f / 232.f;

            static  float gMult = 255.f / 36.1f;
            static float bMult = 255.f / 114.f;

            DrawMessageQ(MenuModern, x, y, label, IM_COL32(rMult * m > 1 ? 232 * (rMult * m) : 232, gMult * m > 1 ? 36 * (gMult * m) : 36, bMult * m > 1 ? 114 * (bMult * m) : 114, 255));
            //  DrawRect(x + 24, y + 18, width, 1, 0, IM_COL32(232, 36, 114, 255 * SANIM.a));
            if (!startedSequenceDown) {

                DrawLine(ImVec2(x, y + 18), ImVec2(x + (width * SANIM.a), y + 18), 1, IM_COL32(232, 36, 114, 255));
            }
            else {

                DrawLine(ImVec2(x + (width * m), y + 18), ImVec2(x + width, y + 18), 1, IM_COL32(232, 36, 114, 255 * SANIM.a));
            }
            if (SANIM.a > 0.95) {
                SANIM.targeta = 0.f;
                startedSequenceDown = true;
            }

            if (SANIM.a < 0.05 && startedSequenceDown) {
                IGui::SearchSequence = "";
                startedSequenceDown = false;
            }


        }
        else {

        }
        elementSpacing += 40;
        sliderArrCount++;

        change /= 100;
        min /= 100;
        max /= 100;
        
    }




    void returnBar() {


        if (cp.x > menuPos.x + 63 && cp.x < menuPos.x + 150 && cp.y > menuPos.y + 10 && cp.y < menuPos.y + 40)
            DrawMessageA(modernBold, 110, 14, "Return", IM_COL32(225, 225, 225, 255));
        else {
            DrawMessageA(modernBold, 110, 14, "Return", IM_COL32(255, 255, 255, 255));
        }
        DrawImage(64, 4, 56, 40, returnIcon);

    }


   


    void dbl::Separator() {
        elementSpacing += 2;
        DrawRect(childX + 2, childY + elementSpacing, 224, 1, 0, IM_COL32(50, 50, 50, 180));
        elementSpacing += 10;
    }


    bool stringInVec(std::string str, std::vector<std::string> vec) {
        for (int i = 0; i < vec.size(); i++) {
            if (str == vec[i]) return true;
        }
        return false;
    }

    bool wordExistsInVector(std::string str, std::vector<std::string> vec) {


        if (str == "") return false;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].find(str) != std::string::npos) return true;
        }
        return false;
    }

  

    void swap(int& a, int& b) {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }
    


    void dbl::End() {
        ImGuiContext& g = *GImGui;

        ImGuiIO& io = g.IO;
        const ImGuiStyle& style = g.Style;
        bool anySliderH = false;
      /*  for (int i = 0; i < sliderArrCount; i++) {
            if (sliderStructureArr[i].isHovered) anySliderH = true;
        }*/


        if (g.MouseCursor != ImGuiMouseCursor_TextInput)
            if (anySliderH) {
                ImGuiContext& g = *GImGui;
                g.MouseCursor = ImGuiMouseCursor_ResizeEW;
            }
            else {
                g.MouseCursor = ImGuiMouseCursor_Arrow;
            }
       
        for (int i = DrawList.size() - 1; i >= 0; i--) {
            // ImVec2(760, 592)
            if (DrawList[i].y > 575 && IGui::animationA < 0.9) continue;
           // DrawList[i].col

           ImVec4 col = ImGui::ColorConvertU32ToFloat4(DrawList[i].col);
            col.w = col.w* aList[std::make_pair(0, "background")].value;
            DrawList[i].col = ImGui::ColorConvertFloat4ToU32(col);
     
      
            switch (DrawList[i].type) {


            case ObjectType::RECTANGLE: {
                DrawRectF(DrawList[i].x, DrawList[i].y, DrawList[i].w, DrawList[i].h, DrawList[i].rounding, DrawList[i].col, DrawList[i].flags);
                break;
            }
            case ObjectType::RECTUF: {
                DrawRectUFA(DrawList[i].x, DrawList[i].y, DrawList[i].w, DrawList[i].h, DrawList[i].rounding, DrawList[i].thickness, DrawList[i].col);
                break;
            }

            case ObjectType::IMAGE: {
                DrawImageA(DrawList[i].x, DrawList[i].y, DrawList[i].w, DrawList[i].h, DrawList[i].col, DrawList[i].texture);
                break;
            }

            case ObjectType::TEXT: {
                DrawMessageA(DrawList[i].font, DrawList[i].x, DrawList[i].y, DrawList[i].message, DrawList[i].col);

                break;
            }
            case ObjectType::LINE: {
                DrawLine(DrawList[i].p1, DrawList[i].p2, DrawList[i].thickness, DrawList[i].col);
                break;
            }
            case ObjectType::TRIANGLE: {
                DrawTriangle(DrawList[i].x, DrawList[i].y, DrawList[i].x1, DrawList[i].y1, DrawList[i].x2, DrawList[i].y2, DrawList[i].col);
                break;
            }
            case ObjectType::RECTANGLEGRADIENT: {
                DrawRectGradient(DrawList[i].x, DrawList[i].y, DrawList[i].w, DrawList[i].h, DrawList[i].topl, DrawList[i].topr, DrawList[i].botl, DrawList[i].botr);
                break;
            }
            case ObjectType::CIRCLE: {
                if (DrawList[i].filled)
                    DrawCircle(DrawList[i].x, DrawList[i].y, DrawList[i].radius, DrawList[i].col);
                else
                    DrawCircleUnfilled(DrawList[i].x, DrawList[i].y, DrawList[i].radius, DrawList[i].col);
                break;
            }
            }
        }

        DrawList.clear();
        col1Spacing = 10;
        col2Spacing = 10;
        elementSpacing = 10;
        Index::DDI = 0;


    }



