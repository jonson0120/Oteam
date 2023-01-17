#pragma once
#include "flying_object.h"


//   �h��          �E���獶�ɔ��ł����i���j


class Flying_Armor : public Flying_object
{
public:
	//�R���X�g���N�^
	Flying_Armor(int durability = 10, int x = 1200, int y = 360, int speed = 5);

	//�f�X�g���N�^
	~Flying_Armor();

	void Update() override;    //�X�V
	void Draw() override;      //�`��
	
private:
	int image = 0;    //�摜�p�ϐ�

	int durability;   //�ϋv�l
};

