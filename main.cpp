#include <Novice.h>
#include"Player.h"
#include"Enemy.h"

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

#pragma region 敵の変数
	Enemy* enemy = new Enemy;
	enemy->SetX(575.0f);
	enemy->SetY(0.0f);
	enemy->SetSpeed(5.0f);
#pragma endregion

#pragma region シーン
	struct Scene {
		int Title;
		int Game;
		// シーン用関数
		int scene;
	};
	Scene GameScene{
	    0, // タイトル
	    1, // ゲーム画面
	    0, // シーン
	};


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
		switch (GameScene.scene) 
		{ 
		case 0://タイトル
			if (GameScene.scene == 0) {
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					enemy->Initialize();
					GameScene.scene = 1;

					break;
				}
			}
			break;
		case 1://ゲーム中
			if (GameScene.scene == 1) {
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					GameScene.scene = 0;

					break;
				}
			}
#pragma region 自機の更新(Itemとの当たり判定もここに)
			player->Update();

#pragma endregion

#pragma region 敵の更新
			enemy->Update();

#pragma endregion
			break;

		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (GameScene.scene) {
		case 0:             // タイトル
			
			break;
		case 1:
			player->Draw(); // Player描画
			enemy->Draw();  // Enemy描画
			break;
			
		}

#pragma region デバックコード
		Novice::ScreenPrintf(0, 20, "%d,%d", player->GetX(), player->GetY());
		Novice::ScreenPrintf(0, 40, "%d,%d",GameScene.scene);
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
