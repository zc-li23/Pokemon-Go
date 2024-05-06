// Pokemon_Go.cpp : 定义应用程序的入口点。
#include "Pokemon_Go.h"

#pragma region 全局变量定义
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

HBITMAP bmp_slash;
HBITMAP bmp_num;
HBITMAP bmp_info_1;
HBITMAP bmp_info_2;
HBITMAP bmp_info_3;
HBITMAP bmp_info_4;
HBITMAP bmp_draw_cards;
HBITMAP bmp_discarded_cards;
HBITMAP bmp_energy;
HBITMAP bmp_attack;
HBITMAP bmp_affect;
HBITMAP bmp_defense;
HBITMAP bmp_power;
HBITMAP bmp_speed;
HBITMAP bmp_win;
HBITMAP bmp_lose;
HBITMAP bmp_databox_me;
HBITMAP bmp_databox_rival;
HBITMAP bmp_hp_line;
HBITMAP bmp_button_start;
HBITMAP bmp_button_help;
HBITMAP bmp_button_return;
HBITMAP bmp_button_end_round;
HBITMAP bmp_button_return_game;
HBITMAP bmp_button_regame;
HBITMAP bmp_button_menu;
HBITMAP bmp_button_stop;
HBITMAP bmp_title;
HBITMAP bmp_pikachu;
HBITMAP bmp_choose_bg;
HBITMAP bmp_help_bg;
HBITMAP bmp_battle_bg;
HBITMAP bmp_button_skip_card_choose;
HBITMAP bmp_button_next_help_page;
HBITMAP bmp_button_last_help_page;
HBITMAP bmp_pokemon_2;
HBITMAP bmp_pokemon_3;
HBITMAP bmp_pokemon_4;
HBITMAP bmp_pokeback_1;
HBITMAP bmp_pokeback_2;
HBITMAP bmp_pokeback_3;
HBITMAP bmp_pokeback_4;
HBITMAP bmp_rival_1;
HBITMAP bmp_rival_2;
HBITMAP bmp_rival_3;
HBITMAP bmp_rival_4;
HBITMAP bmp_rival_5;
HBITMAP bmp_boss;
HBITMAP bmp_nothing;
HBITMAP bmp_route_choose_bg;
HBITMAP bmp_card_choose_bg;
HBITMAP bmp_boss_route;					
HBITMAP bmp_battle_route;				
HBITMAP bmp_hospital_route;
HBITMAP bmp_shop_route;
HBITMAP bmp_left_route = NULL;
HBITMAP bmp_mid_route = NULL;
HBITMAP bmp_right_route = NULL;
HBITMAP bmp_left_card = NULL;
HBITMAP bmp_mid_card = NULL;
HBITMAP bmp_right_card = NULL;
HBITMAP bmp_card_1;
HBITMAP bmp_card_2;
HBITMAP bmp_card_3;
HBITMAP bmp_card_4;
HBITMAP bmp_card_5;
HBITMAP bmp_card_6;
HBITMAP bmp_card_7;
HBITMAP bmp_card_8;
HBITMAP bmp_card_9;
HBITMAP bmp_card_10;
HBITMAP bmp_card_11;
HBITMAP bmp_card_12;
HBITMAP bmp_help_1;
HBITMAP bmp_help_2;
HBITMAP bmp_help_3;
HBITMAP bmp_help_4;
HBITMAP bmp_help_5;
HBITMAP bmp_help_6;
HBITMAP bmp_card_wound;
HBITMAP bmp_hand_card_1;
HBITMAP bmp_hand_card_2;
HBITMAP bmp_hand_card_3;
HBITMAP bmp_hand_card_4;

int round_num = 0;
int stop_stage = 0;
int mouseX = 0;
int mouseY = 0;
int pokemon_select = 0;
int help_page = 0;
int route_num = 0;
int left_route = 0;
int mid_route = 0;
int right_route = 0;
int left_card = 0;
int mid_card = 0;
int right_card = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keyWDown = false;
bool keySDown = false;
bool keyADown = false;
bool keyDDown = false;
bool keyESC = false;

Stage* currentStage = NULL;
Me* MyPokemon = new Me(50, 200, 200, 100, 400, bmp_pokeback_1, 3);
Rival* RivalPokemon = new Rival(50, 200, 200, 580, 130, bmp_rival_1);

vector<Button*> buttons;
vector<Stage*> stages;
vector<Card*> cards;
vector<Card*> hand_cards;
vector<Card*> discarded_cards;
vector<Card*> draw_cards;
vector<Pokemon*> pokemons;
#pragma endregion


// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_POKEMONGO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_POKEMONGO));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//目标: 注册窗口类。
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_POKEMONGO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


//目标: 保存实例句柄并创建主窗口
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle,
       WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化,
       CW_USEDEFAULT,
       CW_USEDEFAULT,
       WINDOW_WIDTH,
       WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


//  目标: 处理主窗口的消息。
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        InitGame(hWnd, wParam, lParam);
        break;
    case WM_PAINT:
        Paint(hWnd);
        break;
    case WM_KEYDOWN:
        // 键盘按下事件
        KeyDown(hWnd, wParam, lParam);
        break;
    case WM_KEYUP:
        // 键盘松开事件
        KeyUp(hWnd, wParam, lParam);
        break;
    case WM_MOUSEMOVE:
        // 鼠标移动事件
        MouseMove(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONDOWN:
        // 鼠标左键按下事件
        LButtonDown(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONUP:
        // 鼠标左键松开事件
        LButtonUp(hWnd, wParam, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_TIMER:
        TimerUpdate(hWnd, wParam, lParam);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}