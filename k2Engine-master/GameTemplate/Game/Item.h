#pragma once
#include "sound/SoundSource.h" 

class Player;
class Game;
class Item : public IGameObject
{
public:
	Item();
	~Item();
	void Update();
	void Render(RenderContext& renderContext);
	void Rotation();
	void Despawn();

	ModelRender m_modelRender;
	Vector3 m_position;
	Vector3 m_firstPosition;
	Quaternion m_rotation;
	Player* player;
	Game* game;
	SoundSource* ItemGetSE;
	
	int Count, r, i = 0;
};

