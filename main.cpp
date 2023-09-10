#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include"Item.h"
#include"Title.h"

const char kWindowTitle[] = "Formation_Ocean";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1920, 1080);
	//Novice::SetWindowMode(kFullscreen);

	// 背景用の変数
	int backGround1 = Novice::LoadTexture("./Resource/Backgraund1.png");
	int backGround2 = Novice::LoadTexture("./Resource/Backgraund2.png");
	int backGroundNum = 0;
	int backGroundFlame = 0;

	// 幕用の変数
	int curtainDown = false;
	int curtainUp = false;
	int curtainFlame = 0;
	int curtainY = -1080;

	//敵のフェーズの番号
	int enemyPhaseNum = 0;
	
	//難易度
	int level = 0;

#pragma region 自機の変数
	const int Players = 5;
	Player* player[Players] = {new Player, new Player, new Player, new Player, new Player};

	for (int i = 0; i < Players; i++) {
		player[i]->SetX(880.0f);
		player[i]->SetY(480.0f);
		player[i]->SetW(1);
		player[i]->SetH(1);
	}

	//delete player;

#pragma endregion

#pragma region 敵の変数
	const int Enemys = 5;
	Enemy* enemy[Enemys] = {new Enemy, new Enemy, new Enemy, new Enemy, new Enemy};

	for (int i = 0; i < Enemys; i++) {
		enemy[i]->SetX(900.0f);
		enemy[i]->SetY(0.0f);
		enemy[i]->SetSpeed(5);
	}
	enemy[0]->Setformation(0);
	enemy[0]->SetTimever(1080);

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
	    2, // ゲームクリア
		3, //ゲームオーバー
	};
	Scene GamePhase{
	    0, // 敵戦闘シーン
	    1, // アイテム選択画面
	    2. // ゴールシーン
	};

	GameScene.scene = 0;
#pragma endregion

#pragma region タイトルアニメーション生成
	TitleAction* Titleanime = new TitleAction;
	Titleanime->TitleAnimation = 0;
	Titleanime->TitleFrame = 0;
	Titleanime->ButtonAnimation = 0;
	Titleanime->ButtonFrame = 0;
	Titleanime->GameoverAnimation = 0;
	Titleanime->GameoverFrame = 0;
#pragma endregion

	int playerHP = 3;//自機の体力
	int enemyHP = 3;//敵の体力

	int PlayerFormation = 0;

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
				//タイトルアニメーション
				Titleanime->Update();
				//難易度：イージー
				if (Novice::IsTriggerButton(0, kPadButton12)) {
					for (int i = 0; i < Enemys; i++) {
						enemy[i]->Initialize();
						player[i]->Initialize(); // Player初期化
						Titleanime->Initialize();
						playerHP = 3;
						enemyHP = 3;
						degreeH = 0;
						PlayerFormation = 0;
					}
					curtainDown = true;
				}
				//難易度：ノーマル
				if (Novice::IsTriggerButton(0, kPadButton13)) {
					for (int i = 0; i < Enemys; i++) {
						enemy[i]->Initialize();
						player[i]->Initialize(); // Player初期化
						Titleanime->Initialize();
						playerHP = 3;
						enemyHP = 3;
						degreeH = 0;
						PlayerFormation = 0;
					}
					curtainDown = true;
						break;
				}
				//難易度：ハード
				if (Novice::IsTriggerButton(0, kPadButton11)) {
					for (int i = 0; i < Enemys; i++) {
						enemy[i]->Initialize();
						player[i]->Initialize(); // Player初期化
						playerHP = 3;
						enemyHP = 3;
						degreeH = 0;
						PlayerFormation = 0;
					}
					curtainDown = true;
				}
			}
			if (curtainDown == true) {
				    curtainY += 5;
			}
			if (curtainY >= 0) {
				    curtainDown = false;
			}

			if (curtainDown == false && curtainY >= 0) {
				    GameScene.scene = 1;
			}
#pragma endregion

			case 1: // ゲーム中
#pragma region シーン変更
			//幕の処理
			if (curtainFlame <= 60) {
				    if (curtainY == 0) {
					    curtainFlame++;
				    }
			} else if (curtainFlame > 60) {
				    curtainUp = true;
				    if (curtainUp == true) {
					    curtainY -= 2;
					    if (curtainY <= -1080) {
							curtainY = -1080;
							curtainUp == false;
					    }
					    curtainFlame = 0;
				    }
				    if (Novice::IsTriggerButton(0, kPadButton1)) {
					    for (int i = 0; i < 5; i++) {
							player[i]->Initialize();
					    }
				    }
			}
			if (curtainY >= 0) {
				    curtainFlame++;
			}
			if (curtainFlame >= 60) {
				    curtainUp = true;
			}
			if (curtainUp == true) {
				    curtainY -= 5;
			}
			if (curtainY <= -1080) {
				    curtainY = -1080;
				    curtainUp = false;
				    curtainFlame = 0;
			}
			if (curtainY >= 0) {
				    curtainFlame++;
			}
			if (curtainFlame >= 60) {
				    curtainUp = true;
			}
			if (curtainUp == true) {
				    curtainY -= 5;
			}
			if (curtainY <= -1080) {
				    curtainY = -1080;
				    curtainUp = false;
				    curtainFlame = 0;
			}
				/*if (Novice::IsTriggerButton(0, kPadButton1)) {
				   for (int i = 0; i < 5; i++) {
				    player[i]->Initialize();
				   }
			    }*/
				if (GameScene.scene == 1) {
					backGroundFlame++;
					if (backGroundFlame >= 121) {
						backGroundFlame = 0;
					}
					if (backGroundFlame <= 60) {
						backGroundNum = 0;
					} else {
						backGroundNum = 1;
					}
				    if (playerHP > 0) {
					    if (degreeH < 750) {
						    // 敵戦闘とアイテム選択シーンの切り替え
						    if (GamePhase.phase == 0) {
							    /// 敵と3回戦ったらアイテム選択フェーズに移動する////

							    if (enemyHP <= 0) {
								    degreeH += 150;
								    if (degreeH <= 300) {
									    for (int i = 0; i < Enemys; i++) {
										    enemy[i]->Initialize();
									    }
									    GamePhase.phase = 1;
								    } else if (300 < degreeH < 750) {
									    for (int i = 0; i < Enemys; i++) {
										    enemy[i]->Initialize();
									    }
									    enemyHP = 3;
								    }
							    }

							    ////////////////////////////////////////////////////////////////////
						    }
						    if (GamePhase.phase == 1) {
							    ////////////////アイテムを選択するフェーズの処理////////////////////

							    if (Novice::IsTriggerButton(0, kPadButton12) &&
							        Novice::IsTriggerButton(0, kPadButton13) == 0 &&
							        Novice::IsTriggerButton(0, kPadButton11) == 0) {
								    /// 自機のHPが1回復する処理
								    if (playerHP < 5) {
									    playerHP += 1;
								    }
								    degreeH += 150;
								    enemyHP = 3;
								    GamePhase.phase = 0;
							    }
							    if (Novice::IsTriggerButton(0, kPadButton13) &&
							        Novice::IsTriggerButton(0, kPadButton12) == 0 &&
							        Novice::IsTriggerButton(0, kPadButton11) == 0) {
								    // 次の敵の勝負回数が2回になる処理

								    degreeH += 150;
								    enemyHP = 2;
								    GamePhase.phase = 0;
							    }
							    if (Novice::IsTriggerButton(0, kPadButton11) &&
							        Novice::IsTriggerButton(0, kPadButton13) == 0 &&
							        Novice::IsTriggerButton(0, kPadButton12) == 0) {
								    // 目隠しを消す処理

								    degreeH += 150;
								    enemyHP = 3;
								    GamePhase.phase = 0;
							    }

							    ////////////////////////////////////////////////////////////////////
						    }
							    for (int i = 0; i < Players; i++) {
								    player[i]->Update();
							    }

							    if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
								    GameScene.scene = 0;
								    break;
							    }
#pragma endregion

#pragma region 自機の陣形変更
						    if (GamePhase.phase == 0) {
							    if (Novice::IsTriggerButton(0, kPadButton2)) { // W
								    for (int i = 0; i < 5; i++) {
									    player[i]->MoveUpdate();
									    PlayerFormation = 1;
								    }
							    }
							    if (Novice::IsTriggerButton(0, kPadButton3)) { // ×
								    for (int i = 0; i < 5; i++) {
									    player[i]->SecondMoveUpdate();
									    PlayerFormation = 2;
								    }
							    }
							    if (Novice::IsTriggerButton(0, kPadButton0)) { // 〇
								    for (int i = 0; i < 5; i++) {
									    player[i]->ThirdMoveUpdate();
									    PlayerFormation = 3;
								    }
							    }
							    if (Novice::IsTriggerButton(0, kPadButton1)) {
								    for (int i = 0; i < 5; i++) {
									    player[i]->Initialize();
									    PlayerFormation = 0;
								    }
							    }
						    }

#pragma endregion

#pragma region 敵の更新
						    if (GamePhase.phase == 0) {
							    for (int i = 0; i < Enemys; i++) {
								    enemy[i]->Update();
							    }
						    }
#pragma endregion

#pragma region 勝負
						    if (GamePhase.phase == 0) {
							    if (enemy[0]->GetTimever() <= 0) {
								    if (enemy[0]->Getformation() == 1) { // 敵が逆への字で左ボタン
									    if (PlayerFormation == 1) {
										    enemyHP -= 1;
									    } else {
										    playerHP -= 1;
										    enemyHP -= 1;
											enemy[0]->SharkAttack();
									    }
								    }
								    if (enemy[0]->Getformation() == 2) { // 敵がへの字で上ボタン
									    if (PlayerFormation == 2) {
										    enemyHP -= 1;
									    } else {
										    playerHP -= 1;
										    enemyHP -= 1;
											enemy[0]->SharkAttack();
									    }
								    }
								    if (enemy[0]->Getformation() == 3) { // 敵がギザギザで右ボタン
									    if (PlayerFormation == 3) {
										    enemyHP -= 1;
									    } else {
										    playerHP -= 1;
										    enemyHP -= 1;
											enemy[0]->SharkAttack();
									    }
								    }
							    }

#pragma endregion
							    break;
						    }
					    } else if (degreeH >= 750) {
						    GameScene.scene = 2;
					    }
				    } else {
					    GameScene.scene = 3;
					}
				    
				}
			case 2: // ゲームクリア
				if (GameScene.scene == 2) {
				    /*for (int i = 0; i < 5; i++) {
					    player[i]->MoveUpdate();
					    player[i]->SecondMoveUpdate();
					    player[i]->ThirdMoveUpdate();
					    player[i]->ThirdMoveUpdate();
				    }*/
					if (Novice::IsTriggerButton(0, kPadButton11)) {
						GamePhase.phase = 0;
						degreeH = 0;
					    playerHP = 3;
						GameScene.scene = 0;
					}
				}
		    case 3: //ゲームオーバー
			    if (GameScene.scene == 3) {
					Titleanime->GameoverUpdate();
				    if (Novice::IsTriggerButton(0, kPadButton11)) {
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
			case 0: // タイトル
				Titleanime->Draw();//タイトルアニメーション
				Novice::DrawBox(0, curtainY, 1920, 1080, 0.0f, GREEN, kFillModeSolid);
				break;
			case 1:
				if (backGroundNum == 0) {
					Novice::DrawSprite(0, 0, backGround1, 1, 1, 0.0f, WHITE);
				} else if (backGroundNum == 1) {
					Novice::DrawSprite(0, 0, backGround2, 1, 1, 0.0f, WHITE);
				}
				for (int i = 0; i < Players; i++) {
					player[i]->Draw(); // Player描画
				}
			    if (GamePhase.phase == 0) {
				    enemy[0]->Draw(); // Enemy描画
				}

			///進行度バーの描画
			Novice::DrawBox(100, 915 - degreeH, degreeW, degreeH, 0.0f, RED, kFillModeSolid);
			Novice::DrawBox(100, 165, degreeFrameW, degreeFlameH, 0.0f, BLACK, kFillModeWireFrame);

			Novice::DrawBox(0, curtainY, 1920, 1080, 0.0f, GREEN, kFillModeSolid);

			break;
		case 2:
			if (GameScene.scene == 2) {
				Novice::ScreenPrintf(100, 100, "GAME CLEAR");
			}
			for (int i = 0; i < Players; i++) {
				player[i]->Draw(); // Player描画
			}
			break;
		case 3:
			if (GameScene.scene == 3) {
				Titleanime->GameoverDraw();
				Novice::ScreenPrintf(100, 100, "GAME OVER");
			}
		}

#pragma region デバックコード

			Novice::DrawBox(0, 0, 300, 300, 0.0f, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(0, 20, "%d,%d", player[0]->GetX(), player[0]->GetY());
			Novice::ScreenPrintf(0, 100, "%d,%d", player[1]->GetX(), player[1]->GetY());
			Novice::ScreenPrintf(0, 120, "%d,%d", player[2]->GetX(), player[2]->GetY());
			Novice::ScreenPrintf(0, 140, "PlayerHP%d,PlayerFormation%d",playerHP,PlayerFormation);
			Novice::ScreenPrintf(0, 160, "EnemyHP%d,EnemyFormation%d", enemyHP,enemy[0]->Getformation());

			Novice::ScreenPrintf(0, 40, "%d,%d", GameScene.scene);
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