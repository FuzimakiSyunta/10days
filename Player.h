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


	int GetX();
	int GetY();
	int GetW();
	int GetH();
	int GetHP();

	void SetX(int PosX_);
	void SetY(int PosY_);
	void SetW(int W_);
	void SetH(int H_);
	void SetHP(int HP_);

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
