#include "Novice.h"

class Player {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 自キャラ
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	//初期化
	void Setup();

private:
	//Player座標
	float PosX_;
	float PosY_;
	//Player半径
	int W_;
	int H_;
	//体力
	int HP_;
};

//Player::Player() {}
//
//Player::~Player() {}
