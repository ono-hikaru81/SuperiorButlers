
#include <Character/CharacterBase.h>
#include <Character/Motion/Run.h>
#include <Character/Motion/Wait.h>

void spesium::character::Run::Init( CharacterBase* character_ ) {
}

void spesium::character::Run::Update( CharacterBase* character_ ) {
    character_->SwitchMotion( character_->motionList.run );
}
