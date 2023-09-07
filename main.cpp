#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include "Item.h"

const char kWindowTitle[] = "10days";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1270, 720);

#pragma region 自機の変数
	const int Players = 5;
	Player* player[Players] = {
	    new Player, new Player, new Player, new Player, new Player}; // int nums[6];
	
	for (int i = 0; i < Players; i++) {
		player[i]->SetX(595.0f);
		player[i]->SetY(480.0f);
		player[i]->SetW(80);
		player[i]->SetH(80);
	}
	struct MoveFrag //陣フラグ構造体 
	{
		int Move1;
		int Move2;
		int Move3;
	};
	MoveFrag moveFrag{
	    false,
	    false,
	    false,
	};
	//delete player;

#pragma endregion

#pragma region 敵の変数
	Enemy* enemy = new Enemy;
	enemy->SetX(575.0f);
	enemy->SetY(0.0f);
	enemy->SetSpeed(5.0f);
#pragma endregion

#pragma region アイテムの変数

	Item* item = new Item;
	item->SetItemNum(0);

#pragma endregion


#pragma region シーン
	struct Scene {
		int Title;
		int Game;
		// シーン用関数
		int scene;
		int phase;
	};
	Scene GameScene{
	    0, // タイトル
	    1, // ゲーム画面
	    0, // シーン
	};
	Scene GamePhase{
	    0, // 敵戦闘シーン
	    1, // アイテム選択画面
	    2. // ゴールシーン
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
		switch (GameScene.scene) {
		case 0: // タイトル
#pragma region シーン変更
			if (GameScene.scene == 0) {
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					enemy->Initialize();
					GameScene.scene = 1;

					break;
				}
			}
#pragma endregion
			for (int i = 0; i < Players; i++) {
				player[i]->Initialize(); // Player初期化
			}
			break;

		case 1: // ゲーム中
#pragma region シーン変更
			if (GameScene.scene == 1) {





				//敵戦闘とアイテム選択シーンの切り替え
				if (GamePhase.phase == 0) {
					///敵の生存フラグがfalseになったらアイテム選択フェーズに移動する////

					
					////////////////////////////////////////////////////////////////////
					
					////////////////アイテムを選択したら敵戦闘フェーズに移行する////////

					item->Update();

					if (item->GetItemNum() == 1) {
						///自機のHPが1回復する処理
					}
					if (item->GetItemNum() == 2) {
						//処理
					}
					if (item->GetItemNum() == 3) {
						//処理
					}

					////////////////////////////////////////////////////////////////////
				}
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					GameScene.scene = 0;

					break;
				}
#pragma endregion
#pragma region 自機の陣形変更
				if (Novice::IsTriggerButton(0, kPadButton2)) {
					for (int i = 0; i < 5; i++) {
						player[i]->MoveUpdate();
					}
				}

#pragma endregion

#pragma region 敵の更新
				enemy->Update();

#pragma endregion
				break;
			  }
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
			for (int i = 0; i < Players; i++) {
				player[i]->Draw(); // Player描画
			}
		

			enemy->Draw();  // Enemy描画
			break;
			
		}

#pragma region デバックコード
		
			Novice::ScreenPrintf(0, 20, "%d,%d", player[0]->GetX(), player[0]->GetY());
			Novice::ScreenPrintf(0, 100, "%d,%d", player[1]->GetX(), player[1]->GetY());
			Novice::ScreenPrintf(0, 120, "%d,%d", player[2]->GetX(), player[2]->GetY());
		
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
