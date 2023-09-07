#pragma once

#include "Novice.h"
#include "WorldTransform.h"


class Item {
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

    ///ゲッター
	int GetItemPhase() { return isItemPhase_; };

    ///セッター
	void SetItemPhase(int isItemPhase__);

private:
    //アイテムの座標
    float PosX;
    float PosY;

    //アイテム当たり判定のサイズ
    int W;
    int H;

    //アイテムの種類
    int ItemNum_;

    //アイテムの移動スピード
    int ItemSpeed;

    ///アイテムフェーズに入ってるかどうか
	int isItemPhase_;
};
