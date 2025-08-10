#include "MateriaSource.hpp"

MateriaSource::MateriaSource() { for(int i=0;i<4;++i) _mem[i]=0; }
MateriaSource::MateriaSource(const MateriaSource& o) { for(int i=0;i<4;++i) _mem[i] = o._mem[i] ? o._mem[i]->clone() : 0; }
MateriaSource& MateriaSource::operator=(const MateriaSource& o) {
    if (this!=&o) {
        for(int i=0;i<4;++i){ if(_mem[i]) { delete _mem[i]; _mem[i]=0; } _mem[i] = o._mem[i] ? o._mem[i]->clone() : 0; }
    }
    return *this;
}
MateriaSource::~MateriaSource() { for(int i=0;i<4;++i) if(_mem[i]) delete _mem[i]; }

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return; for (int i=0;i<4;++i) if(!_mem[i]) { _mem[i]=m->clone(); delete m; return; }
    // full: discard safely
    delete m;
}
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i=0;i<4;++i) if (_mem[i] && _mem[i]->getType() == type) return _mem[i]->clone();
    return 0;
}