#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include "Item.h"

const char kWindowTitle[] = "10days";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1920, 1080);
	//Novice::SetWindowMode(kFullscreen);

#pragma region 自機の変数
	const int Players = 5;
	Player* player[Players] = {
	    new Player, new Player, new Player, new Player, new Player};
	
	for (int i = 0; i < Players; i++) {
		player[i]->SetX(880.0f);
		player[i]->SetY(480.0f);
		player[i]->SetW(1);
		player[i]->SetH(1);
	}
	int Animation = false;//アニメーションしてるかフラグ
	
	struct Timebar //時間制限バー 
	{
		int x;
		int y;
		int w;
		int h;
		int frag;
	};
	Timebar timebar{
	   480,860,1000,100,false
	};

	//delete player;

#pragma endregion

#pragma region 敵の変数
	const int Enemys = 5;
	Enemy* enemy[Enemys] = { new Enemy,new Enemy ,new Enemy ,new Enemy ,new Enemy };

	for (int i = 0; i < Enemys; i++) {
		enemy[i]->SetX(900.0f);
		enemy[i]->SetY(0.0f);
		enemy[i]->SetSpeed(5);
	}
	
#pragma endregion

#pragma region アイテムの変数

	Item* item = new Item;
	item->SetItemNum(0);

#pragma endregion

#pragma region 進行度の変数

	int degreeW = 100;
	int degreeH = 0;
	int degreeFrameW = 100;
	int degreeFlameH = 750;

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
	    2, // シーン
	};
	Scene GamePhase{
	    0, // 敵戦闘シーン
	    1, // アイテム選択画面
	    2. // ゴールシーン
	};

	GameScene.scene = 0;
#pragma endregion
	int playerHP = 3;

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
					for (int i = 0; i < Enemys; i++) {
						enemy[i]->Initialize();
						player[i]->Initialize(); // Player初期化
						
					}
					
					GameScene.scene = 1;

					break;
				}
			}
#pragma endregion

		case 1: // ゲーム中
#pragma region シーン変更
			if (GameScene.scene == 1) {
				if (degreeH < 750) {
					// 敵戦闘とアイテム選択シーンの切り替え
					if (GamePhase.phase == 0) {
						/// 敵の生存フラグがfalseになったらアイテム選択フェーズに移動する////

						if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
							degreeH += 150;
							GamePhase.phase = 1;
						}

						////////////////////////////////////////////////////////////////////
					}
					if (GamePhase.phase == 1) {
						////////////////アイテムを選択するフェーズの処理////////////////////

						if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
							/// 自機のHPが1回復する処理
							if (playerHP < 5) {
								playerHP += 1;
							}
							degreeH += 150;
							GamePhase.phase = 0;
						}
						if (item->GetItemNum() == 2) {
							// 次の入力待機時間が少し長くなる処理
						}
						if (item->GetItemNum() == 3) {
							// 目隠しを消す処理
						}

						////////////////////////////////////////////////////////////////////
					}
					if (Animation == true){
						for (int i = 0; i < Players; i++) {
							player[i]->Update();
						}

					if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
						GameScene.scene = 0;
						Animation = false;
						break;
					}
				}
#pragma endregion
					
					
#pragma region 自機の陣形変更
				if (GamePhase.phase == 0) {
					Animation = true;
					if (Novice::IsTriggerButton(0, kPadButton2)) {
						for (int i = 0; i < 5; i++) {
							player[i]->MoveUpdate();
						}
					}
					if (Novice::IsTriggerButton(0, kPadButton3)) {
						for (int i = 0; i < 5; i++) {
							player[i]->SecondMoveUpdate();
						}
					}
					if (Novice::IsTriggerButton(0, kPadButton0)) {
						for (int i = 0; i < 5; i++) {
							player[i]->ThirdMoveUpdate();
						}
					}
				}
				

#pragma endregion

#pragma region 敵の更新
				
				for (int i = 0; i < Enemys; i++) {

					enemy[i]->Update();
				}
#pragma endregion
					break;
				} else if (degreeH >= 750) {
					GameScene.scene = 2;
				}

			 }
		case 2://ゲームクリア
			 if (GameScene.scene == 2) {
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					GamePhase.phase = 0;
					degreeH = 0;
					GameScene.scene = 0;
				}
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
		
			for (int i = 0; i < Enemys; i++) {
				enemy[i]->Draw();  // Enemy描画
			}
			///進行度バーの描画
			Novice::DrawBox(100, 915 - degreeH, degreeW, degreeH, 0.0f, RED, kFillModeSolid);
			Novice::DrawBox(100, 165, degreeFrameW, degreeFlameH, 0.0f, BLACK, kFillModeWireFrame);

			//時間制限バー描画
			Novice::DrawBox(timebar.x, timebar.y, timebar.w, timebar.h, 0.0f, WHITE, kFillModeSolid);

			

			break;
		case 2:
			if (GameScene.scene == 2) {
				Novice::ScreenPrintf(100, 100, "GAME CLEAR");
			}
			break;
		}

#pragma region デバックコード
		
			Novice::ScreenPrintf(0, 20, "%d,%d", player[0]->GetX(), player[0]->GetY());
			Novice::ScreenPrintf(0, 100, "%d,%d", player[1]->GetX(), player[1]->GetY());
			Novice::ScreenPrintf(0, 120, "%d,%d", player[2]->GetX(), player[2]->GetY());
		
		Novice::ScreenPrintf(0, 40, "%d,%d",GameScene.scene);
		Novice::ScreenPrintf(0, 90, "%d", playerHP);
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
