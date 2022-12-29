#include <Windows.h>
#define MY_DRAW_WND (TEXT("ex_drawing"))


void RegWindowClass();
void MessageLoop();

INT APIENTRY WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR cmd, INT nShow)
{
    RegWindowClass();//������ Ŭ���� �Ӽ� ���� �� ���


    //������ �ν��Ͻ� ����

    HWND hWnd = CreateWindow(MY_DRAW_WND,//Ŭ���� �̸�

        TEXT("�׸��� ����"), //ĸ�� ��

        WS_OVERLAPPEDWINDOW, //������ ��Ÿ��

        10, 10, 520, 420,//��,��,��,����

        0,//�θ� ������ �ڵ�

        0,//�޴� �ڵ�

        hIns,//�ν��Ͻ� �ڵ�

        0);//���� �� ���� ����



    ShowWindow(hWnd, nShow);//������ �ν��Ͻ� �ð�ȭ, SW_SHOW(�ð�ȭ), SW_HIDE(��ð�ȭ)       

    MessageLoop();//�޽��� ����

    return 0;

}



//������ Ŭ���� �Ӽ� ���� �� ���
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

void RegWindowClass()
{
    WNDCLASS wndclass = { 0 };

    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��� �귯�� �ڵ�

    wndclass.hCursor = LoadCursor(0, IDC_ARROW); //���콺 Ŀ�� �ڵ�

    wndclass.hIcon = LoadIcon(0, IDI_APPLICATION); //������ �ڵ�

    wndclass.hInstance = GetModuleHandle(0);//�ڽ� ����� �ν��Ͻ� �ڵ�

    wndclass.lpfnWndProc = MyWndProc;//������ �ݹ� ���ν���

    wndclass.lpszClassName = MY_DRAW_WND;//Ŭ���� �̸� - Ŭ���� ������

    wndclass.style = CS_DBLCLKS;//Ŭ���� ����

    RegisterClass(&wndclass);//������ Ŭ���� ���

}



//�޽��� ����
void MessageLoop()
{

    MSG Message;

    while (GetMessage(&Message, 0, 0, 0))//�޽��� �������� �޽��� ����(WM_QUIT�̸� FALSE ��ȯ)
    {

        TranslateMessage(&Message);//WM_KEYDOWN�̰� Ű�� ���� Ű�� �� WM_CHAR �߻�

        DispatchMessage(&Message);//�ݹ� ���ν����� ������ �� �ְ� ����ġ ��Ŵ

    }

}



//������ �ݹ� ���ν���

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



#define STEP_WIDTH  100//����� ��
#define STEP_HEIGHT 100//����� ����
#define LEFT(pi)       (pi*STEP_WIDTH) //�� �ε����� ���� ����� ���� X��ǥ
#define RIGHT(pi)     ((pi+1)*STEP_WIDTH-20) //�귯�� �ε����� ���� ����� ��� Y��ǥ
#define TOP(bi)        (bi*STEP_HEIGHT + 30) //�� �ε����� ���� ����� ���� X��ǥ
#define BOTTOM(bi)  ((bi+1)*STEP_HEIGHT - 30) //�귯�� �ε����� ���� ����� �ϴ� Y��ǥ

enum EN_PEN { HP_RED, HP_GREEN, HP_BLUE, HP2_RED, HPD_RED, HP_MAX }; //�� ��Ÿ�� ������

enum EH_BRUSH { HB_RED, HB_GREEN, HB_BLUE, HBS_RED, HB_MAX }; //�귯�� ��Ÿ�� ������



LPCTSTR pstrs[HP_MAX] = { TEXT("R"), TEXT("G"), TEXT("B"),TEXT("T R"), TEXT("DD R") }; //�� ��� ���ڿ�

LPCTSTR bstrs[HB_MAX] = { TEXT("R"), TEXT("G"), TEXT("B"),TEXT("C R") }; //�귯�� ��� ���ڿ�

//�׸��� �۾�

void DrawDiagram(HWND hWnd, HDC hdc, HPEN hPen, HBRUSH hBrush, LPRECT prt);

void OnDraw(HWND hWnd, HDC hdc)

{

    HPEN hPens[HP_MAX];

    //�׸��⿡ ����� �� ��ü ���� ��û

    hPens[HP_RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

    hPens[HP_GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

    hPens[HP_BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

    hPens[HP2_RED] = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));

    hPens[HPD_RED] = CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));



    HBRUSH hBrushes[HB_MAX];

    //�׸��⿡ ����� �귯�� ��ü ���� ��û

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

            //��� �귯�� ��Ÿ�� ���ڿ� ����

            wsprintf(buf, TEXT("%s, %s"), pstrs[pi], bstrs[bi]);

            //������ ��ǥ ����

            rt.left = LEFT(pi);

            rt.top = TOP(bi);

            rt.right = RIGHT(pi);

            rt.bottom = BOTTOM(bi);

            //��� �귯�� ��Ÿ�� ���ڿ� ���

            TextOut(hdc, pi * STEP_WIDTH, bi * STEP_HEIGHT, buf, lstrlen(buf));


            //Ư�� ��� �귯���� ���� ���
            DrawDiagram(hWnd, hdc, hPens[pi], hBrushes[bi], &rt);

        }

    }



    //�� ��ü �Ҹ� ��û

    for (int pi = 0; pi < HP_MAX; pi++)
    {
        DeleteObject(hPens[pi]);
    }

    //�귯�� ��ü �Ҹ� ��û

    for (int bi = 0; bi < HB_MAX; bi++)
    {
        DeleteObject(hBrushes[bi]);
    }

}



//���� �׸���
void DrawDiagram(HWND hWnd, HDC hdc, HPEN hPen, HBRUSH hBrush, LPRECT prt)
{
    HPEN oPen;//DC�� ���� ���� �� �ڵ� ����� ����

    oPen = (HPEN)SelectObject(hdc, hPen); //�Է� ���ڷ� ���޹��� ���� DC�� ����



    HBRUSH oBrush;//DC�� ���� ���� �귯�� �ڵ� ����� ����   

    oBrush = (HBRUSH)SelectObject(hdc, hBrush);//�Է� ���ڷ� ���޹��� �귯���� DC�� ����



    Rectangle(hdc, prt->left, prt->top, prt->right, prt->bottom);//�簢�� �׸���

    Ellipse(hdc, prt->left, prt->top, prt->right, prt->bottom); //Ÿ�� �׸���



    SelectObject(hdc, oPen);//���� ���� ���� DC�� ����

    SelectObject(hdc, oBrush);//���� ���� �귯���� DC�� ����

}



//WM_PAINT �޽��� ó����
void OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps;

    BeginPaint(hWnd, &ps);//DC �߱� �� ��ȿȭ ���� ���

    OnDraw(hWnd, ps.hdc);//�׸��� �۾� ��û

    EndPaint(hWnd, &ps); //DC ���� �� ��ȿȭ ������ ��ȿȭ �������� ����

}

//WM_DESTROY �޽��� ó����

void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);//�޽��� ť�� WM_QUIT �޽����� ����

}