#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウモード
	ChangeWindowMode(TRUE);
	// ウインドウの名前を変更
	SetWindowText("DxLib　テストプロジェクト");

	// DxLibの初期化
	if (DxLib_Init() == -1)	return -1;

	int i = 0;

	// 裏画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);

	while (CheckHitKeyAll() == 0)
	{
		// 描画されているものを削除
		ClearDrawScreen();

		i++;

		// 画像の描画
		LoadGraphScreen(i, 0, "Image/test1.bmp", FALSE);

		// 裏画面の内容を表画面にコピーする
		ScreenFlip();

		// Windowsからのメッセージ処理
		if (ProcessMessage() == -1) break;
	}

	// キー入力で終了できることを表示する
	DrawString(0, 0, "キー入力で終了", GetColor(255, 255, 255));
	// キー入力待ち
	WaitKey();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了 
	return 0;
}