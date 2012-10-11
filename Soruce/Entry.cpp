#include "../Header/stdafx.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
// LRESULT : Long -> int�� �ڷ���
// CALLBACK : �ü������ ȣ���ϴ� �Լ�

HINSTANCE g_hInst;
// HINSTANCE : �ڷ���
// g_ : global �̶�� �ǹ̸� ������ �ϴ� ���ξ�, �� ����������� �ǹ�

LPCTSTR lpszClass=TEXT("First");
// LPCTSTR : Long Pointer ConsT STRing
// lpszClass : long pointer string zero(null�� ������ ���ڿ�)
// TEXT : �����ڵ�� �ν� �ƴϸ� �ƽ�Ű �ڵ�� �ν�
// 2003�̳� 2005���� "test" �� ������ ������ ���� �ִ�.
// �׷��� L"test"�� ������ ���������� �ν��ϰ� �ȴ�.

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
/*
	APIENTRY : api�� ��������,
			�ٸ� �ǹ̴� �Լ�ȣ�� ������� �ϳ��ε� ���� Ǫ�ù���� ����Ѵ�.
			A(1,2,3) �� ������  bottom/1-2-3/up(c ǥ��), bottom/3-2-1/up
			_stdcall�� ���� �Ǿ� �ִ�. �� ��ũ�ε��� ȣȯ���� �̽ļ��� ���� �����Ѵ�.
	HINSTANCE hInstance : ���α׷��� �ν��Ͻ� �ڵ�, �� ���� �������� �κ��̶�� �ǹ��̴�.
	HINSTANCE hPrevInstance : �� ���α׷��� ����Ǳ� ���� ����Ǿ���
							  �ν��Ͻ� �ڵ��̴�. win32������ �׻� NULL�̴�.
	LPSTR lpszCmdParam : ���α׷��� ����. ������ argv�� �ش�ȴ�.
						 ���� ���� ���Ŀ� �� ������ ��ΰ� ���޵ȴ�.
	int nCmdShow :
*/
{
	HWND hWnd;						// ������ �ڵ鷯
	MSG Message;					// �޽���
	WNDCLASS WndClass;				// ����ü
	g_hInst=hInstance;

	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);		// ȭ���� ������� ĥ��
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);					// ���콺 ����� ǥ����
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);					// ���� �� ��ܿ� ��Ÿ���� ������
	WndClass.hInstance=hInstance;									// ���� ������ �ν��Ͻ�
	WndClass.lpfnWndProc=WndProc;									// �ݹ��Լ� ���
	WndClass.lpszClassName=lpszClass;								// â�� �̸�(lpszClass�� ���� First�� �ԷµǾ� ����)
	WndClass.lpszMenuName=NULL;										// �޴� �̸�
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);										// ������ Ŭ������ ���

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,		// â�� ����
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,hInstance,NULL);
	/*
		1��° ���� (lpszClassName): �����ϰ��� �ϴ� ������ Ŭ������ �����ϴ� ���ڿ�
		2��° ���� (lpszWindowName) : ������ Ÿ��Ʋ �ٿ� ��Ÿ�� ���ڿ�
		3��° ���� (dwStyle): ������� �ϴ� �������� ���¸� �����ϴ� �μ�
		4��° ���� ~ 7��° ����(X,Y,nWidth,nHeight) : X, Y ��ǥ�� â�� ũ�� ����
		8��° ���� (hWndParent) : �θ� �����찡 ���� ��� �θ� �������� �ڵ��� ����
		9��° ���� (hmenu) : �����쿡�� ����� �޴��� �ڵ��� ����
		10��° ���� (hinst) : �����츦 ����� ��ü, �� ���α׷��� �ڵ��� ����
		11��° ���� (lpvParam) : CREATSTRUCT��� ����ü�� �����̸�
	*/
	ShowWindow(hWnd,nCmdShow);			// â�� �����ְ� ���ִ� �Լ�
										// ��� �������� �ڵ� ���� �����츦 ȭ�鿡 ����ϴ� ����� ����


	while (GetMessage(&Message,NULL,0,0)) // �޽��� ť���� �޽����� �о���δ�.
	{
		TranslateMessage(&Message);		// Ű���� �Է� �޽����� �����Ͽ� ���α׷����� ���� ���� �ֵ��� �Ѵ�.
		DispatchMessage(&Message);		// �޽��� ť���� ���� �޽����� �������� �޽��� ó�� �Լ�(WndProc)�� �����Ѵ�.
	}
	return (int)Message.wParam;			// WM_QIUT �޽����κ��� ���޵� Ż�� �ڵ�(exit code)�̸�
										// �� ���α׷��� �����Ų �ü���� ���ϵȴ�.
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

