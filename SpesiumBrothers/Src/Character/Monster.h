#ifndef MONSTER_H
#define MONSTER_H

#include "CharacterBase.h"

namespace character
{
	class Monster : public CharacterBase
	{
	public:
		Monster();
		~Monster() override;

	public:
		void Draw() override;

	public:
		/*
		* @brief アクセサ
		* @param (status.pos) 座標
		*/
		utility::Property<utility::Vector3> Pos{ status.pos };
	};
}

#endif // !MONSTER_H
