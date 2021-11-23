
#include <Character/Monster.h>
#include <DxLib.h>

namespace spesium {
    namespace character {
        Monster::Monster() {
            status = {
                { Vector3( 0.0, 0.0, 0.0 ) },  // 座標
                0.0,  // 回転角

                0,  // 体力
                0,  // シールド量
                0,  // 攻撃力
                1.0,  // 速度
                10.0,  // 最大速度
                10.0,  // ジャンプ力
            };
        }

        Monster::~Monster() {
        }

        void Monster::Draw() {
            MV1SetPosition( monsterModel, status.pos );

            MV1SetRotationXYZ( monsterModel, VGet( 0.0f, status.angle / 180.0f * DX_PI_F, 0.0f ) );

            MV1DrawModel( monsterModel );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( status.pos.X ), static_cast<int32_t>( status.pos.Y ) );
#endif  // _DEBUG
        }
    }  // namespace character
}  // namespace spesium
