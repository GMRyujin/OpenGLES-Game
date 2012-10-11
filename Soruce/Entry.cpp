#include "../Header/stdafx.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
// LRESULT : Long -> int형 자료형
// CALLBACK : 운영체제에서 호출하는 함수

HINSTANCE g_hInst;
// HINSTANCE : 자료형
// g_ : global 이라는 의미를 가지게 하는 접두어, 즉 전역변수라는 의미

LPCTSTR lpszClass=TEXT("First");
// LPCTSTR : Long Pointer ConsT STRing
// lpszClass : long pointer string zero(null로 끝나는 문자열)
// TEXT : 유니코드로 인식 아니면 아스키 코드로 인식
// 2003이나 2005에선 "test" 를 적으면 에러를 띄울수 있다.
// 그러면 L"test"를 적으면 정상적으로 인식하게 된다.

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
/*
	APIENTRY : api의 시작지점,
			다른 의미는 함수호출 기법중의 하나인데 스택 푸시방법을 사용한다.
			A(1,2,3) 이 있으면  bottom/1-2-3/up(c 표준), bottom/3-2-1/up
			_stdcall로 정의 되어 있다. 이 매크로들은 호환성과 이식성을 위해 존재한다.
	HINSTANCE hInstance : 프로그램의 인스턴스 핸들, 즉 현재 실행중인 부분이라는 의미이다.
	HINSTANCE hPrevInstance : 이 프로그램이 실행되기 전에 실행되었던
							  인스턴스 핸들이다. win32에서는 항상 NULL이다.
	LPSTR lpszCmdParam : 프로그램의 인자. 도스의 argv에 해당된다.
						 보통 실행 직후에 열 파일의 경로가 전달된다.
	int nCmdShow :
*/
{
	HWND hWnd;						// 윈도우 핸들러
	MSG Message;					// 메시지
	WNDCLASS WndClass;				// 구조체
	g_hInst=hInstance;

	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);		// 화면을 흰색으로 칠함
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);					// 마우스 모양을 표시함
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);					// 왼쪽 위 상단에 나타나는 아이콘
	WndClass.hInstance=hInstance;									// 현재 윈도우 인스턴스
	WndClass.lpfnWndProc=WndProc;									// 콜백함수 등록
	WndClass.lpszClassName=lpszClass;								// 창의 이름(lpszClass는 현재 First로 입력되어 있음)
	WndClass.lpszMenuName=NULL;										// 메뉴 이름
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);										// 윈도우 클래스를 등록

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,		// 창을 생성
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,hInstance,NULL);
	/*
		1번째 인자 (lpszClassName): 생성하고자 하는 윈도우 클래스를 지정하는 문자열
		2번째 인자 (lpszWindowName) : 윈도우 타이틀 바에 나타날 문자열
		3번째 인자 (dwStyle): 만들고자 하는 윈도우의 형태를 지정하는 인수
		4번째 인자 ~ 7번째 인자(X,Y,nWidth,nHeight) : X, Y 좌표와 창의 크기 설정
		8번째 인자 (hWndParent) : 부모 윈도우가 있을 경우 부모 윈도우의 핸들을 지정
		9번째 인자 (hmenu) : 윈도우에서 사용할 메뉴의 핸들을 지정
		10번째 인자 (hinst) : 윈도우를 만드는 주체, 즉 프로그램의 핸들을 지정
		11번째 인자 (lpvParam) : CREATSTRUCT라는 구조체의 번지이며
	*/
	ShowWindow(hWnd,nCmdShow);			// 창을 보여주게 해주는 함수
										// 띄울 윈도우의 핸들 값과 윈도우를 화면에 출력하는 방법을 지정


	while (GetMessage(&Message,NULL,0,0)) // 메시지 큐에서 메시지를 읽어들인다.
	{
		TranslateMessage(&Message);		// 키보드 입력 메시지를 가공하여 프로그램에서 쉽게 쓸수 있도록 한다.
		DispatchMessage(&Message);		// 메시지 큐에서 꺼낸 메시지를 윈도우의 메시지 처리 함수(WndProc)로 전달한다.
	}
	return (int)Message.wParam;			// WM_QIUT 메시지로부터 전달된 탈출 코드(exit code)이며
										// 이 프로그램을 실행시킨 운영체제로 리턴된다.
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

