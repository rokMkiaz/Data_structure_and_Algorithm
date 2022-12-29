#include <Windows.h>
#define MY_DRAW_WND (TEXT("ex_drawing"))


void RegWindowClass();
void MessageLoop();

INT APIENTRY WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR cmd, INT nShow)
{
    RegWindowClass();//윈도우 클래스 속성 설정 및 등록


    //윈도우 인스턴스 생성

    HWND hWnd = CreateWindow(MY_DRAW_WND,//클래스 이름

        TEXT("그리기 예제"), //캡션 명

        WS_OVERLAPPEDWINDOW, //윈도우 스타일

        10, 10, 520, 420,//좌,상,폭,높이

        0,//부모 윈도우 핸들

        0,//메뉴 핸들

        hIns,//인스턴스 핸들

        0);//생성 시 전달 인자



    ShowWindow(hWnd, nShow);//윈도우 인스턴스 시각화, SW_SHOW(시각화), SW_HIDE(비시각화)       

    MessageLoop();//메시지 루프

    return 0;

}



//윈도우 클래스 속성 설정 및 등록
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

void RegWindowClass()
{
    WNDCLASS wndclass = { 0 };

    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//흰색 브러쉬 핸들

    wndclass.hCursor = LoadCursor(0, IDC_ARROW); //마우스 커서 핸들

    wndclass.hIcon = LoadIcon(0, IDI_APPLICATION); //아이콘 핸들

    wndclass.hInstance = GetModuleHandle(0);//자신 모듈의 인스턴스 핸들

    wndclass.lpfnWndProc = MyWndProc;//윈도우 콜백 프로시저

    wndclass.lpszClassName = MY_DRAW_WND;//클래스 이름 - 클래스 구분자

    wndclass.style = CS_DBLCLKS;//클래스 종류

    RegisterClass(&wndclass);//윈도우 클래스 등록

}



//메시지 루프
void MessageLoop()
{

    MSG Message;

    while (GetMessage(&Message, 0, 0, 0))//메시지 루프에서 메시지 꺼냄(WM_QUIT이면 FALSE 반환)
    {

        TranslateMessage(&Message);//WM_KEYDOWN이고 키가 문자 키일 때 WM_CHAR 발생

        DispatchMessage(&Message);//콜백 프로시저가 수행할 수 있게 디스패치 시킴

    }

}



//윈도우 콜백 프로시저

void OnPaint(HWND hWnd);

void OnDestroy(HWND hWnd);

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)

{

    switch (iMessage)

    {

    case WM_PAINT: OnPaint(hWnd); return 0;

    case WM_DESTROY: OnDestroy(hWnd); return 0;

    }

    return DefWindowProc(hWnd, iMessage, wParam, lParam);

}



#define STEP_WIDTH  100//출력할 폭
#define STEP_HEIGHT 100//출력할 높이
#define LEFT(pi)       (pi*STEP_WIDTH) //펜 인덱스에 따라 출력할 좌측 X좌표
#define RIGHT(pi)     ((pi+1)*STEP_WIDTH-20) //브러쉬 인덱스에 따라 출력할 상단 Y좌표
#define TOP(bi)        (bi*STEP_HEIGHT + 30) //펜 인덱스에 따라 출력할 우측 X좌표
#define BOTTOM(bi)  ((bi+1)*STEP_HEIGHT - 30) //브러쉬 인덱스에 따라 출력할 하단 Y좌표

enum EN_PEN { HP_RED, HP_GREEN, HP_BLUE, HP2_RED, HPD_RED, HP_MAX }; //펜 스타일 열거형

enum EH_BRUSH { HB_RED, HB_GREEN, HB_BLUE, HBS_RED, HB_MAX }; //브러쉬 스타일 열거형



LPCTSTR pstrs[HP_MAX] = { TEXT("R"), TEXT("G"), TEXT("B"),TEXT("T R"), TEXT("DD R") }; //펜 출력 문자열

LPCTSTR bstrs[HB_MAX] = { TEXT("R"), TEXT("G"), TEXT("B"),TEXT("C R") }; //브러쉬 출력 문자열

//그리기 작업

void DrawDiagram(HWND hWnd, HDC hdc, HPEN hPen, HBRUSH hBrush, LPRECT prt);

void OnDraw(HWND hWnd, HDC hdc)

{

    HPEN hPens[HP_MAX];

    //그리기에 사용할 펜 개체 생성 요청

    hPens[HP_RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

    hPens[HP_GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

    hPens[HP_BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

    hPens[HP2_RED] = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));

    hPens[HPD_RED] = CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));



    HBRUSH hBrushes[HB_MAX];

    //그리기에 사용할 브러쉬 개체 생성 요청

    hBrushes[HB_RED] = CreateSolidBrush(RGB(255, 0, 0));

    hBrushes[HB_GREEN] = CreateSolidBrush(RGB(0, 255, 0));

    hBrushes[HB_BLUE] = CreateSolidBrush(RGB(0, 0, 255));

    hBrushes[HBS_RED] = CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));



    TCHAR buf[256] = TEXT("");

    RECT rt;

    for (int pi = 0; pi < HP_MAX; pi++)

    {

        for (int bi = 0; bi < HB_MAX; bi++)

        {

            //펜과 브러쉬 스타일 문자열 조합

            wsprintf(buf, TEXT("%s, %s"), pstrs[pi], bstrs[bi]);

            //츨력할 좌표 설정

            rt.left = LEFT(pi);

            rt.top = TOP(bi);

            rt.right = RIGHT(pi);

            rt.bottom = BOTTOM(bi);

            //펜과 브러쉬 스타일 문자열 출력

            TextOut(hdc, pi * STEP_WIDTH, bi * STEP_HEIGHT, buf, lstrlen(buf));


            //특정 펜과 브러쉬로 도형 출력
            DrawDiagram(hWnd, hdc, hPens[pi], hBrushes[bi], &rt);

        }

    }



    //펜 개체 소멸 요청

    for (int pi = 0; pi < HP_MAX; pi++)
    {
        DeleteObject(hPens[pi]);
    }

    //브러쉬 개체 소멸 요청

    for (int bi = 0; bi < HB_MAX; bi++)
    {
        DeleteObject(hBrushes[bi]);
    }

}



//도형 그리기
void DrawDiagram(HWND hWnd, HDC hdc, HPEN hPen, HBRUSH hBrush, LPRECT prt)
{
    HPEN oPen;//DC에 기존 선택 펜 핸들 기억할 변수

    oPen = (HPEN)SelectObject(hdc, hPen); //입력 인자로 전달받은 펜을 DC에 선택



    HBRUSH oBrush;//DC에 기존 선택 브러쉬 핸들 기억할 변수   

    oBrush = (HBRUSH)SelectObject(hdc, hBrush);//입력 인자로 전달받은 브러쉬를 DC에 선택



    Rectangle(hdc, prt->left, prt->top, prt->right, prt->bottom);//사각형 그리기

    Ellipse(hdc, prt->left, prt->top, prt->right, prt->bottom); //타원 그리기



    SelectObject(hdc, oPen);//기존 선택 펜을 DC에 선택

    SelectObject(hdc, oBrush);//기존 선택 브러쉬를 DC에 선택

}



//WM_PAINT 메시지 처리기
void OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps;

    BeginPaint(hWnd, &ps);//DC 발급 및 무효화 영역 계산

    OnDraw(hWnd, ps.hdc);//그리기 작업 요청

    EndPaint(hWnd, &ps); //DC 해제 및 무효화 영역을 유효화 영역으로 변경

}

//WM_DESTROY 메시지 처리기

void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);//메시지 큐에 WM_QUIT 메시지를 붙임

}