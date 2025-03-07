#pragma once
//#include "sound/SoundSource.h"

class Player;
class Arrow;
class Assist;
class GameCamera;
class Item;

class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	void Update();
	void Render(RenderContext& rc);
	void Rotation();
	void Attack();
	void PlayAnimation();
	void Collision();
	void Seek();
	void EnemyAttackBar();
	void ItemDrop();
	bool Start();
	void OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName);

	const bool Serch();
	const bool AttackSerch();
	const bool DeleteSerch();
	const bool Desision();
	const bool Dec();

	Vector3 m_position;
	Vector3 m_scale = Vector3::One;
	Vector3 m_moveSpeed;
	Vector3	m_forward = Vector3::AxisZ;
	Vector3 m_toCameraPos;
	Vector3 m_pePos;
	Vector3 m_attackBar = { 0.9f,1.0f,1.0f };
	Vector2 m_spritePosition = Vector2::Zero;
	//Vector3 m_cNPos = { 0.0f,0.0f,0.0f };

	float m_peDis;

	ModelRender m_modelRender;
	SpriteRender m_spriteRender;
	Quaternion m_rotation;
	SoundSource* se;
	SoundSource* se2;


	enum EnEnemyClip
	{
		enEnemyClip_Idle,
		enEnemyClip_Attack,
		enEnemyClip_Down,
		enEnemyClip_Num,
	};
	AnimationClip m_animationClips[enEnemyClip_Num];
	Animation m_animation;

	int m_enemyState = 0;
	int m_enemyDownLag = 0;
	//CharacterController m_charaCon;

	Player* player;
	Arrow* arrow;
	Assist* assist;
	Item* item;
	GameCamera* gameCamera;
	CollisionObject* m_collisionObject;

	bool m_downFlag = false;
	float arrowtimer = 0.01f;
	float arrowtime = 3.0f;
	double m_Dec;
	int HP = 1;
	int i;
	int m_itemGet = 0;
};