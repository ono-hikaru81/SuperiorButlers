
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

            LoadModel( "Res/Model/motion_monster.mv1" );

            frameDataList.emplace_back( 3, Vector3<>::Zero(), 32.0 );

            MV1AttachAnim( modelHandle, 0 );
        }

        Monster::~Monster() {
        }

        void Monster::Draw() {
            static float t { 0.0f };
            t += 0.5f;
            MV1SetAttachAnimTime( modelHandle, 0, t );
            if ( t >= MV1GetAttachAnimTotalTime( modelHandle, 0 ) ) {
                t = 0.0f;
            }

            MV1SetPosition( modelHandle, status.pos );

            MV1SetRotationXYZ( modelHandle, VGet( 0.0f, status.angle / 180.0f * DX_PI_F, 0.0f ) );

            MV1DrawModel( modelHandle );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( status.pos.X ), static_cast<int32_t>( status.pos.Y ) );
            printfDx( "anim : %f / %f\n", MV1GetAttachAnimTime( modelHandle, 0 ), MV1GetAttachAnimTotalTime( modelHandle, 0 ) );
            for ( auto& frame : frameDataList ) {
                auto drawPos { frame.position };
                DrawSphere3D( drawPos, frame.radius, 16, GetColor( 0, 0, 255 ), GetColor( 255, 255, 255 ), FALSE );
            }
#endif  // _DEBUG
        }

        void Monster::OnCollision() {
            printfDx( "HIT!!" );
        }
    }  // namespace character
}  // namespace spesium
