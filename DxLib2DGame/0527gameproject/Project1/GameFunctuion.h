#pragma once
/*
関数の宣言
*/

/// <summary>
/// ゲーム画面
/// </summary>
/// <param name="deltaTime"></param>
/// <param name="startScreenImage">画像ハンドル</param>
void StartScreen(double deltaTime,int startScreenImage);
/// <summary>
/// ゲーム画面
/// </summary>
/// <param name="deltaTime"></param>
void GameProcessing(double deltaTime);

/// <summary>
/// リザルト画面
/// </summary>
void ResultScreen();
