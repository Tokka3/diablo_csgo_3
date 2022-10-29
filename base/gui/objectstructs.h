#include <Windows.h>
#include "../common.h"

#include <vector>
#include <chrono>
#include <utility>
#include "../sdk/datatypes/color.h"
#include <map>


struct SliderSt {

    int ctargetX = 99;
    float cX = 84;
    float ceasing = 0.12;
    float cdx = 0;


    int targetX = 99;
    float X = 84;
    float easing = 0.12;
    float dx = 0;

    bool isPressed;
    bool isHovered;


    float mult = 1;
    float dymult = 1;
    float targetmult = 1;
    float musteas = 0.05;
};





struct trans {
    float        a = 582;
    float        aeasing = 0.05;

    float        targeta = 0;
    float        ay = 0;

    float        h = 0;
    float        heasing = 0.05;

    float        targeth = 0;
    float        hy = 0;

    int timer = 0;
    float mult;
};


struct transx {
    float        a = 0;
    float        aeasing = 0.05;

    float        targeta = 0;
    float        ay = 0;

    float        h = 0;
    float        heasing = 0.05;

    float        targeth = 0;
    float        hy = 0;

    int timer = 0;
    float mult;
};

struct transy {
    float        a = 582;
    float        aeasing = 0.05;

    float        targeta = 0;
    float        ay = 0;

    float        h = 0;
    float        heasing = 0.05;

    float        targeth = 0;
    float        hy = 0;

    int timer = 0;
    float mult;
};

struct animList {
    float        a = 0;
    float        aeasing = 0.05;

    float        targeta = 0;
    float        ay = 0;

    float        h = 0;
    float        heasing = 0.05;

    float        targeth = 0;
    float        hy = 0;

    int timer = 0;
    float mult;
};

struct Bool {




    transx xa;
    transy ya;
    int idx = 0;
    bool bSpare = false;
    bool spareClick = false;
    bool multiClicked = false;
    bool isListening = false;
    int keyBindX = -1000;
    int keyBindY = -1000;
    bool keyBindTab = false;
    int hoverTimer = 0;
    bool data = false;
    int vkKey = 0;
    int ToggleType = 0;
    animList aList;
    float targetX;
    float dx;
    float X;

};

struct anim {
    std::chrono::steady_clock::time_point start;
    float value = 0;
    bool enabled = false;
    float targetVal = 0.f;
    float startVal = 0;
    bool init = false;
    bool fadeOut = false;
    bool fadeIn = false;
    bool inProgress = false;
};

struct d_timer {
    std::chrono::steady_clock::time_point start;
    bool inProgress = false;
};
std::map< std::pair<int, std::string>, anim> aList{

};

std::map< std::pair<int, std::string>, SliderSt> sliderMGR{

};
std::map<std::string, d_timer> tMGR{

};




std::map<std::string, Color> colMGR{

};



std::map<Color*, Color> spareColours{

};


std::map<std::pair<const char*, const char*>, Color> mulColMGR{

};

std::map< std::pair<int, std::string>, Bool> cbMGR{

};

struct d_element {
    bool enabled = false;
};

std::map<std::pair<int, std::string>, d_element> elementMGR{

};
static std::vector<ImU32> colours = {
    IM_COL32(255, 255, 255, 255),
    IM_COL32(128, 128, 128, 255),
    IM_COL32(1, 0, 0, 255),
    IM_COL32(255, 0, 51, 255),
    IM_COL32(255, 0, 153, 255),
    IM_COL32(255, 0, 179, 255),
    IM_COL32(255, 0, 230, 255),
    IM_COL32(230, 0, 255, 255),
    IM_COL32(179, 0, 255, 255),
    IM_COL32(153, 0, 255, 255),
    IM_COL32(102, 0, 255, 255),
    IM_COL32(51, 0, 255, 255),
    IM_COL32(0, 0, 255, 255),
    IM_COL32(0, 7, 255, 255),
    IM_COL32(0, 153, 255, 255),
    IM_COL32(0, 204, 255, 255),
    IM_COL32(0, 255, 255, 255),
    IM_COL32(0, 255, 51, 255),
    IM_COL32(102, 255, 0, 255),
    IM_COL32(179, 255, 0, 255),
    IM_COL32(255, 255, 0, 255),
    IM_COL32(255, 153, 0, 255),
    IM_COL32(255, 77, 0, 255),
    IM_COL32(255, 0, 0, 255),
};




enum ObjectType {
    RECTANGLE,
    RECTUF,
    RECTANGLEGRADIENT,
    TEXT,
    TRIANGLE,
    IMAGE,
    CIRCLE,
    LINE,
   
};

struct Object {

    animList anim;


    int x;
    int y;
    int w;
    int h;


    // for triangles
    int x1;
    int y1;
    int x2;
    int y2;
    int scale;
    // --------

    int rounding;
    ImU32 col;
    // for gradients
    ImU32 topl;
    ImU32 topr;
    ImU32 botl;
    ImU32 botr;
    // -----------

    // circle 
    float radius;
    bool filled;
    // --------
     // for lines
    ImVec2 p1;
    ImVec2 p2;
    //

    int thickness;
    ObjectType type;
    const char* message;
    LPDIRECT3DTEXTURE9 texture;
    ImFont* font;
    ImDrawCornerFlags flags;
       
};


struct DropDown {
    bool isClicked = false;
    float a;
    float easing;
    float targeta;
    float delta;
    animList anim;
};


enum ElementType {

    DROPDOWN,
    COLOURPICKER,
    KEYBIND,
    CHECKBOX,
    MULTIPICKER,
};



class Int {
public:
    int data;
    transx xa;
    transy ya;
    Int(int val) {
        this->data = val;
    }
};




struct ColBundle {
    Color* col;
    const char* label;
};
struct Modal {
    Bool* value;
    std::vector<ColBundle> col;
    const char* label;
    bool isClicked;
};

struct MultiDropDown {
    const char* label = "";
    Bool* value;
    int targetX;
    float X;
    float easing;
    float dx;
};

