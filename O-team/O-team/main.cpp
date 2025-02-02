#include"DxLib.h"
#include"information.h"  //使いたい .hファイル をインクルードします

#include"Help.h"
#include"Ranking.h"
#include"Result.h"
#include"Title.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Neko");             //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動

	//ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X, SCREENSIZE_Y, 32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	//画像読み込み
	if (LoadImages() == -1) return -1;

	//最初はタイトル
	GameMode = mode::TITLE;

	//問題なければループ
	while (ProcessMessage() == 0)
	{

		//キー入力取得 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //例のコントローラーの入力も使えます
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //画面を初期化

		switch (GameMode)
		{
		case mode::TITLE:

			//タイトル
			DrawGameTitle(g_KeyFlg, GameMode);

			break;

		case mode::INIT:

			//初期化
			GameInit();

			break;

		case mode::MAIN:

			//ゲームメイン
			GameMain();

			break;

		case mode::RANKING:

			//ランキング表示
			DrawRanking(g_KeyFlg, GameMode);

			break;

		case mode::HELP:

			//ヘルプ表示
			DrawHelp(g_KeyFlg, GameMode);

			break;

		case mode::INPUTNAME:

			//名前入力
			InputRanking(g_KeyFlg, GameMode);

			break;

		case mode::RESULT:

			//リザルト
			DrawResult(g_KeyFlg, GameMode);

			break;

		case mode::END:

			//エンド
			break;

		case mode::CLOSE:

			//くろーず
			break;

		default:
			break;
		}

		DxLib::ScreenFlip();                      //裏画面を表画面に反映
	}

	DxLib_End();				           // ＤＸライブラリ使用の終了処理

	return 0;				               // ソフトの終了 
}

//初期化
void GameInit()
{
	//いろいろ初期化

	//ゲームメインへ
	GameMode = mode::MAIN;
}

//ゲームメイン
void GameMain()
{

}

//画像読み込み
int LoadImages()
{
	if (LoadHelpImage() == -1) return -1;     //ヘルプ画像読み込み
	if (LoadRankingImage() == -1) return -1;  //ランキング画像読み込み
	if (LoadResultImage() == -1) return -1;   //リザルト画像読み込み
	if (LoadTitleImage() == -1) return -1;    //タイトル画像読み込み

	return 0;
}

//音声読み込み
int LoadSounds()
{
	return 0;
}