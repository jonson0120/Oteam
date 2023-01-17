#include"DxLib.h"
#include "flying_Attack.h"

//テスト用 color
int colors[3] = { 0x00ffff,0x00ff00,0xff00ff };


//コンストラクタ
Flying_Attack::Flying_Attack(Attack_Type type, int x, int y, int speed)
	:my_Type(type), Flying_object(x, y, 30, 30, speed)     //基底クラスのコンストラクタ呼び出し
{
	//コンストラクタで値を渡さないとデフォルト引数で画面右端より飛んできます

	//画像読み込み
	//image = LoadGraph("images/");
}

//デストラクタ
Flying_Attack::~Flying_Attack()
{

}

//更新
void Flying_Attack::Update()
{
	//右から左へ
	x -= speed;
}

//描画
void Flying_Attack::Draw()
{
	//画像変数に何もない場合は　□　を描画
	if (image != 0)
	{
		//画像で描画(中心座標)
		DrawRotaGraph(x, y, 1, 0, image, TRUE);
	}
	else
	{
		// □ を描画   槍：水　　鉄：緑　毒：紫
		DrawBox(x, y, x + w, y + h, colors[static_cast<int>(my_Type)], TRUE);
	}

	//テスト
	DrawFormatString(0, 0, 0xffffff, "イルヨ");
}

// 攻撃によるダメージ取得（ playerのHP(耐久値) ）
int Flying_Attack::GetAttackDamage(int hp)
{
	switch (my_Type)
	{
	case Attack_Type::SPEAR:

		return 10;     //10ダメージ
		break;

	case Attack_Type::IRON:

		return static_cast<int>(hp * 0.5);  //50%の割合ダメージ
		break;

	case Attack_Type::POISON:

		return 50;     //50ダメージ
		break;

	default:
		break;
	}

	return 0;
}