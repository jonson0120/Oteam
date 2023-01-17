#pragma once
#include "flying_object.h"


//   �U��          �E���獶�ɔ��ł����i���j

//�U���̎��
enum class Attack_Type
{
	SPEAR,      //���@�|
	IRON,       //�S�@��
	POISON,     //�Ł@�|�[�V����
};


class Flying_Attack : public Flying_object
{
public:
	//�R���X�g���N�^
	Flying_Attack(Attack_Type type, int x = 1200, int y = 360, int speed = 10);

	//�f�X�g���N�^
	~Flying_Attack();

	void Update() override;    //�X�V
	void Draw() override;      //�`��

	// �U���ɂ��_���[�W�擾�i player��HP(�ϋv�l) �j
	int GetAttackDamage(const int hp);

private:
	int image = 0;          //�摜�p�ϐ�

	Attack_Type my_Type;    //�������ǂ̃^�C�v�̍U����

	int damage = 0;
};

