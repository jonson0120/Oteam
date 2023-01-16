#include"DxLib.h"
#include"GameMain.h"
#include"flying_Armor.h"
#include"flying_object.h"

//�h��ő�\����
#define ARMOR_MAX 10 

//�h��̔z��
Flying_object** obj_armor;     //���N���X�^�|�C���^


//�Q�[�����C�����������i�R���X�g���N�^����j
void GameMain_Init()
{
	//�h��10���̃��������m��
	obj_armor = new Flying_object * [ARMOR_MAX];

	//������
	for (int i = 0; i < ARMOR_MAX; i++) obj_armor[i] = nullptr;

	//test
	obj_armor[0] = new Flying_Armor();
}

//�Q�[�����C���X�V�E�v�Z
void GameMain_Update()
{
	int armor_count;   //�h��z��́Z�Ԗڂ����Ă��邩

	//�z�������݂�
	for (armor_count = 0; armor_count < ARMOR_MAX; armor_count++)
	{
		//nullptr����ɂ�nullptr�����Ȃ��̂Ń��[�v�𔲂���
		if (obj_armor[armor_count] == nullptr) break;

		//�X�V�@�i�ړ��j
		obj_armor[armor_count]->Update();

		//��ʊO�ɓ��B�ō폜
		if (obj_armor[armor_count]->CheckScreenOut() == true)
		{
			delete obj_armor[armor_count];         //���B�������폜
			obj_armor[armor_count] = nullptr;      //�폜�����z��̗v�f��������

			//�z����l�߂�
			for (int i = armor_count; i < (ARMOR_MAX - 1); i++)
			{
				//���̗v�f�� nullptr �Ȃ�l�߂�K�v���Ȃ��̂Ŕ�����
				if (obj_armor[i + 1] == nullptr) break;

				obj_armor[i] = obj_armor[i + 1];   //�l�߂�
				obj_armor[i + 1] = nullptr;        //�l�߂�ꂽ�v�f�͏�����
			}
			armor_count--;
		}
	}

	//�z��ɋ�v�f������΃I�u�W�F�N�g�𐶐�����
	if (armor_count < ARMOR_MAX && obj_armor[armor_count] == nullptr)
	{
		//�ϋv�l
		int r_dura = 30;   // �Ƃ肠����

		//�����W�i�����j�@�@�����W�� 1300�Œ�i��ʊO�E���j
		int r_y = (GetRand(10) * 60) + 60;

		//�X�s�[�h�i��� 5�ȏ�j
		int r_speed = (GetRand(3) + 1) + 5;

		//��������@�@�@�@�@�@�@                  �ϋv�l   ���@�@���@ ��߰��
		obj_armor[armor_count] = new Flying_Armor(r_dura, 1300, r_y, r_speed);
	}
}

//�Q�[�����C���`��
void GameMain_Draw()
{
	//�h��̕`��
	for (int i = 0; i < ARMOR_MAX; i++)
	{
		if (obj_armor[i] == nullptr) break;   //nullptr����ɂ�nullptr�����Ȃ��̂Ń��[�v�𔲂���
		obj_armor[i]->Draw();                 //�v�f�����鎞�͕`��
	}
}

//�Q�[�����C��
void GameMain()
{
	GameMain_Update();    //�Q�[�����C���X�V�E�v�Z

	GameMain_Draw();      //�Q�[�����C���`��
}