#pragma once

#include "Novice.h"
#include "WorldTransform.h"


class Item {
public:
    /// <summary>
    /// ������
    /// </summary>
    void Initialize();

    /// <summary>
    /// �X�V
    /// </summary>
    void Update();

    /// <summary>
    /// �`��
    /// </summary>
    void Draw();

    ///�Q�b�^�[
	int GetItemNum() { return ItemNum_; };

    ///�Z�b�^�[
	void SetItemNum(int ItemNum__);

private:

    //�擾�����A�C�e���̎�ށi���ʔ������̃A�C�e���̎�ށj
    int ItemNum_;

};
