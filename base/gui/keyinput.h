#include <Windows.h>
#include <string>

static bool ks[256];
static bool pvks[256];
std::string type[] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    " ",
    " ",
    " ",
    " ",
    " ",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};
std::string col[] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};
std::string key_names[] = {
    "none",
    "",
    "",
    "",
    "m3",
    "m4",
    "m5",
    "none",
    "none",
    "tab",
    "none",
    "none",
    "clr",
    "rtrn",
    "none",
    "none",
    "shift",
    "ctrl",
    "menu",
    "pause",
    "caps",
    "kana",
    "none",
    "junja",
    "final",
    "kanji",
    "none",
    "none",
    "cvrt",
    "ncvrt",
    "acpt",
    "mch",
    "space",
    "prior",
    "next",
    "end",
    "home",
    "left",
    "up",
    "right",
    "down",
    "slct",
    "print",
    "exec",
    "snap",
    "ins",
    "del",
    "help",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
    "lwin",
    "rwin",
    "apps",
    "none",
    "sleep",
    "num 0",
    "num 1",
    "num 2",
    "num 3",
    "num 4",
    "num 5",
    "num 6",
    "num 7",
    "num 8",
    "num 9",
    "mltpl",
    "add",
    "sprtr",
    "sub",
    "dec",
    "div",
    "f1",
    "f2",
    "f3",
    "f4",
    "f5",
    "f6",
    "f7",
    "f8",
    "f9",
    "f10",
    "f11",
    "f12",
    "f13",
    "f14",
    "f15",
    "f16",
    "f17",
    "f18",
    "f19",
    "f20",
    "f21",
    "f22",
    "f23",
    "f24",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "numl",
    "scrl",
    "necequal",
    "masshou",
    "touroku",
    "loya",
    "roya",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "lshift",
    "rshift",
    "l-ctrl",
    "r-ctrl",
    "l-menu",
    "r-menu",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        ";",
        "=",
        ",",
        "-",
        ".",
        "/",
        "`",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none", //200
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "none",
        "",
        "[",
        "\\",
        "]"
        "\""
  


};

struct key_code_info {
    int vk;

    char regular;
    char shift;
};
static  key_code_info special_characters[22] = {
        {48,  '0',  ')'},
        {49,  '1',  '!'},
        {50,  '2',  '@'},
        {51,  '3',  '#'},
        {52,  '4',  '$'},
        {53,  '5',  '%'},
        {54,  '6',  '^'},
        {55,  '7',  '&'},
        {56,  '8',  '*'},
        {57,  '9',  '('},
        {32,  ' ',  ' '},
        {192, '`',  '~'},
        {189, '-',  '_'},
        {187, '=',  '+'},
        {219, '[',  '{'},
        {220, '\\', '|'},
        {221, ']',  '}'},
        {186, ';',  ':'},
        {222, '\'', '"'},
        {188, ',',  '<'},
        {190, '.',  '>'},
        {191, '/',  '?'}
};
const char* listentoKeys() {

    for (int i = 0; i < 256; i++) {
        pvks[i] = ks[i];
        
        ks[i] = GetAsyncKeyState(i);
    }

    return "";
}


bool keypress(const int key) {
    return ks[key] && !pvks[key];
}
std::string listeningKey(int &ret) {

    for (int i = 0; i < 256; i++) {
        if (keypress(i)) {
            ret = i;
            return type[i];
        }
    }
    return "";
}
std::string listeningKeyA() {

    for (int i = 0; i < 256; i++) {
        if (keypress(i)) return col[i];
    }
    return "";
}


