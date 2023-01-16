#pragma once
#include "flying_object.h"


//   �h��          �E���獶�ɔ��ł����i���j


class Flying_Armor : public Flying_object
{
public:
	//�R���X�g���N�^
	Flying_Armor(int durability = 10, float x = 1200.0f, float y = 360.0f, float speed = 5);

	//�f�X�g���N�^
	~Flying_Armor();

	void Update();    //�X�V
	void Draw();      //�`��
	
private:
	int image = 0;    //�摜�p�ϐ�

	int durability;   //�ϋv�l
};

