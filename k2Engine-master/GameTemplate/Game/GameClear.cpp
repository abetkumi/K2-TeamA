#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "sound/SoundSource.h" 
#include "Game.h"
#include "GameCamera.h"

GameClear::GameClear()
{
	spriteRender.Init("Assets/modelData/GameClear.dds", 1920.0f, 1080.0f);
	g_soundEngine->ResistWaveFileBank(4, "Assets/BGM_SE/GameClear.wav");

	gameClearBGM = NewGO<SoundSource>(4);
	gameClearBGM->Init(4);
	gameClearBGM->Play(false);
	game = FindGO<Game>("game");
	gameCamera = FindGO<GameCamera>("gameCamera");

}

GameClear::~GameClear()
{
	DeleteGO(gameClearBGM);
}

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0);
		DeleteGO(this);
		DeleteGO(game);
	}
}

void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
