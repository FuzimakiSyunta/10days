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
	void MoveUpdate();

	void SecondMoveUpdate();

	void ThirdMoveUpdate();


	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	//ゲッター
	int GetX() { return PosX_[5]; };
	int GetY() { return PosY_[5]; };
	int GetW() { return W_; };
	int GetH() { return H_; };
	

	//セッタ－
	void SetX(int PosX_);
	void SetY(int PosY_);
	void SetW(int W_);
	void SetH(int H_);
	

private:
	// Player座標
	float PosX_[5];
	float PosY_[5];
	// Player半径
	int W_;
	int H_;
	
	
};
