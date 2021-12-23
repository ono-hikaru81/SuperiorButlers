
#include <Character/CharacterBase.h>
#include <Character/Motion/Wait.h>

void spesium::character::Wait::Init( CharacterBase* character_ ) {
}

void spesium::character::Wait::Update( CharacterBase* character_ ) {
    character_->WaitMotion();
}
