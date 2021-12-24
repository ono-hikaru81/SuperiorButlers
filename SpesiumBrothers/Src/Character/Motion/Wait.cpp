
#include <Character/CharacterBase.h>
#include <Character/Motion/Run.h>
#include <Character/Motion/Wait.h>

void spesium::character::Wait::Init( CharacterBase* character_ ) {
}

void spesium::character::Wait::Update( CharacterBase* character_ ) {
    character_->SwitchMotion( character_->motionList.wait );

    if ( character_->GetMoveVecX() > 0.0 || character_->GetMoveVecX() < 0.0 || !character_->GetIsStanding() ) {
        character_->TransMotion( Run::GetInstance() );
    }
}
