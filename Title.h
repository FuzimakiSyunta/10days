#include "Novice.h"

class TitleAction
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();


	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	//タイトルのアニメーション
	int TitleFrame;
	int TitleAnimation;
	//ボタンのアニメーション
	int ButtonFrame;
	int ButtonAnimation;

private:
	
	//タイトル画像読み込み
	int Titleimage[3] = { Novice::LoadTexture("./Resource./Title.png"), Novice::LoadTexture("./Resource./Title2.png"), };
	//Bボタンで始める
	int Buttonimage[2]= { Novice::LoadTexture("./Resource./BButton.png"), Novice::LoadTexture("./Resource./BButton2.png"), };

};

