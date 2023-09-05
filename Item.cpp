#include "Item.h"
#include <stdio.h>
#include <time.h>

void Item::Initialize() {

    ItemNum_ = rand() % 7;

};

void Item::Update() {

    ///次勝ったときポイントが倍
    if (ItemNum_ == 0 || ItemNum_ == 1) {

    }
    ///失敗時ライフ減少がない代わりにスコアが減る
    else if (ItemNum_ == 2 || ItemNum_ == 3) {

    }
    ///他の効果の中からランダムで一つ発生
    else if (ItemNum_ == 4 || ItemNum_ == 5) {

    }
    ///プレイヤーのHPを１回復
    else if (ItemNum_ == 6) {

    }
};

void Item::Draw() {
    ///aaa


};