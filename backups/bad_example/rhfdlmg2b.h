#ifndef _rhfdlmg2b
#define _rhfdlmg2b

#include <vector>

#include "psi4/libmints/typedefs.h"
#include "psi4/libmints/oeprop.h"
#include "psi4/libscf_solver/rhf.h"
#include "psi4/libscf_solver/hf.h"
#include <psi4/libfock/cubature.h>


namespace psi{

namespace scf{

class RHFDLMG2B: public Wavefunction   {
public:
  RHFDLMG2B(SharedWavefunction ref_wfn,Options &options, std::shared_ptr<PSIO> psio);
  virtual ~RHFDLMG2B();
protected:

};  
}} // Namespaces
#endif
