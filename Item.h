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
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    ///ゲッター
	int GetItemNum() { return ItemNum_; };

    ///セッター
	void SetItemNum(int ItemNum__);

private:

    //取得したアイテムの種類（効果発動中のアイテムの種類）
    int ItemNum_;

};
