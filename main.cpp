﻿#include <Novice.h>
#include"Player.h"

const char kWindowTitle[] = "10days";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1270, 720);
	
#pragma region 自機の変数
	Player* player = new Player;
	player->SetX(595.0f);
	player->SetY(480.0f);
	player->SetW(80);
	player->SetH(80);
	player->SetHP(5);
#pragma endregion

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
#pragma region 自機の更新(Itemとの当たり判定もここに)
		player->Update();

#pragma endregion
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();//Player描画

#pragma region デバックコード
		Novice::ScreenPrintf(0, 20, "%d,%d", player->GetX(), player->GetY());
#pragma endregion

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
