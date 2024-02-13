#include <windows.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static TCHAR currentNumber[128] = { 0 };
	static TCHAR currentNumber2[128] = { 0 };
	static TCHAR currentNumber_temp[128] = { 0 };
	static BOOL bChangeNumber = FALSE;
	static int currentOperation = 0;
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;

	case WM_INITDIALOG:
		static HWND hOutput = GetDlgItem(hWnd, IDC_EDIT1);
		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON1:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"1");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"1");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON2:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"2");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"2");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON3:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"3");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"3");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON4:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"4");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"4");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON5:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"5");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"5");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON6:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"6");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"6");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON7:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"7");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"7");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON8:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"8");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"8");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON9:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"9");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"9");
				SetWindowText(hOutput, currentNumber2);
			}
			break;
		case IDC_BUTTON0:
			if (!bChangeNumber) {
				lstrcat(currentNumber, L"0");
				SetWindowText(hOutput, currentNumber);
			}
			else
			{
				lstrcat(currentNumber2, L"0");
				SetWindowText(hOutput, currentNumber2);
			}
			break;

		case IDC_BUTTON_DELETE:
			SetWindowText(hOutput, NULL);
			ZeroMemory(currentNumber, sizeof(currentNumber));
			ZeroMemory(currentNumber2, sizeof(currentNumber2));
			break;
		case IDC_BUTTON_PLUS:
			SetWindowText(hOutput, NULL);
			currentOperation = IDC_BUTTON_PLUS; // Устанавливаем код операции сложения
			bChangeNumber = TRUE;
			break;

		case IDC_BUTTON_MINUS:
			SetWindowText(hOutput, NULL);
			currentOperation = IDC_BUTTON_MINUS; // Устанавливаем код операции вычитания
			bChangeNumber = TRUE;
			break;

		case IDC_BUTTON_MULTIPLY:
			SetWindowText(hOutput, NULL);
			currentOperation = IDC_BUTTON_MULTIPLY; // Устанавливаем код операции умножения
			bChangeNumber = TRUE;
			break;

		case IDC_BUTTON_DIV:
			SetWindowText(hOutput, NULL);
			currentOperation = IDC_BUTTON_DIV; // Устанавливаем код операции деления
			bChangeNumber = TRUE;
			break;

		case IDC_BUTTON_EQUAL:
			bChangeNumber = FALSE;
			double num1, num2, result{};
			num1 = _wtof(currentNumber2);
			num2 = _wtof(currentNumber);
			if (currentOperation == IDC_BUTTON_PLUS) // Проверяем текущую операцию
				result = num1 + num2;
			else if (currentOperation == IDC_BUTTON_MINUS)
				result = num1 - num2;
			else if (currentOperation == IDC_BUTTON_MULTIPLY)
				result = num1 * num2;
			else if (currentOperation == IDC_BUTTON_DIV || num2 == 0)
			{
				SetWindowText(hOutput, _T("ERROR"));
				ZeroMemory(currentNumber2, sizeof(currentNumber2));
				currentOperation = 0; // Сбрасываем текущую операцию
				return TRUE;
			}
			else if (currentOperation == IDC_BUTTON_DIV)
				result = num1 / num2;

			_stprintf_s(currentNumber, _T("%g"), result);
			SetWindowText(hOutput, currentNumber);
			ZeroMemory(currentNumber2, sizeof(currentNumber2));
			currentOperation = 0; // Сбрасываем текущую операцию
			break;

		}
		return TRUE;
	}
	return FALSE;
}
