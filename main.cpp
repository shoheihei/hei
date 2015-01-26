//
// アプリ雛形
// ※ファイル分割対応版
//

#include "lib/appEnv.hpp"

// ↑他の.cppファイルでは、必要なヘッダファイルを
//   適時インクルードする事


// アプリのウインドウサイズ
enum Window {
	WIDTH = 800,
	HEIGHT = 900
};


// 
// メインプログラム
// 
int main() {
	// アプリウインドウの準備
	AppEnv app_env(Window::WIDTH, Window::HEIGHT,
		false, false);

	Texture  aaa("res/aaa.png");
	Texture ga("res/ga.png");
	Texture tyou("res/tyou.png");
	Texture hati("res/hati.png");

	int x = 0;
	bool shot_1 = false, shot_2 = false;
	int shot_x_1 = 0, shot_y_1 = 0, shot_x_2 = 0, shot_y_2 = 0;
	int cnt = 0;

	bool ga_[4] = { true, true, true, true };
	bool tyou_[16] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
	bool hati_[20] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };

	while (1) {
		// アプリウインドウが閉じられたらプログラムを終了
		if (!app_env.isOpen()) return 0;

		// 描画準備
		app_env.setupDraw();

		//
		// 描画処理はここでおこなう
		// 


		// 時機の描画
		drawTextureBox(x, -350, 64, 64, 0, 0, 64, 64,
			aaa,
			Color(1, 1, 1));

		// 移動処理
		if (app_env.isPressKey(GLFW_KEY_RIGHT)){
			if (x < 334)
				x += 4;
		}
		if (app_env.isPressKey(GLFW_KEY_LEFT)){
			if (x > -400)
				x -= 4;
		}

		// 弾の処理
		if (shot_1 == false){
			if (app_env.isPushKey(GLFW_KEY_LEFT_CONTROL)){
				shot_x_1 = x + 32;
				shot_y_1 = -318;
				shot_1 = true;
				cnt = 0;
			}
		}

		if (shot_1 == true && shot_2 == false){
			if (cnt > 10){
				if (app_env.isPushKey(GLFW_KEY_LEFT_CONTROL)){
					shot_x_2 = x + 32;
					shot_y_2 = -318;
					shot_2 = true;
				}
			}
		}

		if (shot_1 == true){
			drawFillBox(shot_x_1, shot_y_1, 4, 6,
				Color(1, 1, 1));
		}

		if (shot_1 == true){
			shot_y_1 += 10;
			cnt++;
		}

		if (shot_y_1 >= 450){
			shot_1 = false;
		}

		if (shot_2 == true){
			drawFillBox(shot_x_2, shot_y_2, 4, 6,
				Color(1, 1, 1));
		}

		if (shot_2 == true)
			shot_y_2 += 10;

		if (shot_y_2 >= 450){
			shot_2 = false;
		}

		// 蛾の描画
		if (ga_[0] == true){
			drawTextureBox(-138, 350, 64, 64, 0, 0, 64, 64,
				ga,
				Color(1, 1, 1));
		}
		if (ga_[1] == true){
			drawTextureBox(-69, 350, 64, 64, 0, 0, 64, 64,
				ga,
				Color(1, 1, 1));
		}
		if (ga_[2] == true){
			drawTextureBox(0, 350, 64, 64, 0, 0, 64, 64,
				ga,
				Color(1, 1, 1));
		}
		if (ga_[3] == true){
			drawTextureBox(69, 350, 64, 64, 0, 0, 64, 64,
				ga,
				Color(1, 1, 1));
		}

		// 蝶の描画
		if (tyou_[0] == true){
			drawTextureBox(-276, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[1] == true){
			drawTextureBox(-207, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[2] == true){
			drawTextureBox(-138, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[3] == true){
			drawTextureBox(-69, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[4] == true){
			drawTextureBox(0, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[5] == true){
			drawTextureBox(69, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[6] == true){
			drawTextureBox(138, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[7] == true){
			drawTextureBox(207, 281, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[8] == true){
			drawTextureBox(-276, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[9] == true){
			drawTextureBox(-207, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[10] == true){
			drawTextureBox(-138, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[11] == true){
			drawTextureBox(-69, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[12] == true){
			drawTextureBox(0, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[13] == true){
			drawTextureBox(69, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[14] == true){
			drawTextureBox(138, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}
		if (tyou_[15] == true){
			drawTextureBox(207, 212, 64, 64, 0, 0, 64, 64,
				tyou,
				Color(1, 1, 1));
		}

		// 蜂の描画
		if (hati_[0] == true){
			drawTextureBox(-345, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[1] == true){
			drawTextureBox(-276, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[2] == true){
			drawTextureBox(-207, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[3] == true){
			drawTextureBox(-138, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[4] == true){
			drawTextureBox(-69, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[5] == true){
			drawTextureBox(0, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[6] == true){
			drawTextureBox(69, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[7] == true){
			drawTextureBox(138, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[8] == true){
			drawTextureBox(207, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[9] == true){
			drawTextureBox(276, 143, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[10] == true){
			drawTextureBox(-345, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[11] == true){
			drawTextureBox(-276, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[12] == true){
			drawTextureBox(-207, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[13] == true){
			drawTextureBox(-138, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[14] == true){
			drawTextureBox(-69, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[15] == true){
			drawTextureBox(0, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[16] == true){
			drawTextureBox(69, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[17] == true){
			drawTextureBox(138, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[18] == true){
			drawTextureBox(207, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}
		if (hati_[19] == true){
			drawTextureBox(276, 74, 64, 64, 0, 0, 64, 64,
				hati,
				Color(1, 1, 1));
		}

		// 画面更新
		app_env.update();
	}

	// アプリ終了
}
