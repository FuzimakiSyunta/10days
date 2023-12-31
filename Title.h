#include "Novice.h"

class TitleAction
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	void GameoverInitialize();
	void GoalInitialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	void GameoverUpdate();

	void GoalUpdate();


	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void GameoverDraw();

	void GoalDraw();

	//タイトルのアニメーション
	int TitleFrame;
	int TitleAnimation;
	//ボタンのアニメーション
	int ButtonFrame;
	int ButtonAnimation;
	//ゲームオーバーアニメーション
	int GameoverFrame;
	int GameoverAnimation;
	//ゲームオーバーアニメーション
	int GoalFrame;
	int GoalAnimation;
	

private:
	
	//タイトル画像読み込み
	int Titleimage[2] = { Novice::LoadTexture("./Resource./Title.png"), Novice::LoadTexture("./Resource./Title2.png"), };
	//Bボタンで始める
	int Buttonimage[2]= { Novice::LoadTexture("./Resource./BButton.png"), Novice::LoadTexture("./Resource./BButton2.png"), };
	//ゲームオーバー画像読み込み
	int Gameoverimage[8] = { Novice::LoadTexture("./Resource./Gameover1.png"),Novice::LoadTexture("./Resource./Gameover2.png"),Novice::LoadTexture("./Resource./Gameover3.png"),Novice::LoadTexture("./Resource./Gameover4.png"),
		Novice::LoadTexture("./Resource./Gameover5.png"),Novice::LoadTexture("./Resource./Gameover6.png"),Novice::LoadTexture("./Resource./Gameover7.png"),
	Novice::LoadTexture("./Resource./Gameover8.png"), };
	//ゴール画像読み込み
	int Goalimage[5] = { Novice::LoadTexture("./Resource./Goal1.png"), Novice::LoadTexture("./Resource./Goal2.png"), Novice::LoadTexture("./Resource./Goal3.png"),
	Novice::LoadTexture("./Resource./Goal4.png"), Novice::LoadTexture("./Resource./Goal5.png"), };
};

