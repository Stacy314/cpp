#include "Character.hpp"

Character::Character(const std::string& name) : _name(name), _floorTop(0) {
    for (int i=0;i<4;++i) _inv[i]=0; for (int i=0;i<16;++i) _floor[i]=0;
}

Character::Character(const Character& o) : _name(o._name), _floorTop(0) {
    for (int i=0;i<4;++i) _inv[i] = o._inv[i] ? o._inv[i]->clone() : 0;
    for (int i=0;i<16;++i) _floor[i]=0;
}

Character& Character::operator=(const Character& o) {
    if (this!=&o) {
        _name = o._name;
        for (int i=0;i<4;++i) { if (_inv[i]) { delete _inv[i]; _inv[i]=0; } _inv[i] = o._inv[i] ? o._inv[i]->clone() : 0; }
        // floor cleared
        for (int i=0;i<16;++i) { if (_floor[i]) { delete _floor[i]; _floor[i]=0; } }
        _floorTop = 0;
    }
    return *this;
}

Character::~Character(){ for(int i=0;i<4;++i) if(_inv[i]) delete _inv[i]; for(int i=0;i<16;++i) if(_floor[i]) delete _floor[i]; }
std::string const & Character::getName() const { return _name; }
void Character::equip(AMateria* m) {
    if (!m) return; for (int i=0;i<4;++i) if(!_inv[i]) { _inv[i]=m; return; }
}

void Character::unequip(int idx) {
    if (idx<0 || idx>=4 || !_inv[idx]) return; if (_floorTop<16) _floor[_floorTop++] = _inv[idx]; _inv[idx]=0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx<0 || idx>=4 || !_inv[idx]) return; _inv[idx]->use(target);
}
