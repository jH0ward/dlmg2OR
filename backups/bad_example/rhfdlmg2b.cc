#include <typeinfo>
#include "rhfdlmg2b.h"
#include <psi4/psi4-dec.h>
#include <psi4/liboptions/liboptions.h>
#include <fstream>
#include <iostream>
#include <psi4/libpsio/psio.hpp>
#include <psi4/libciomr/libciomr.h>
#include <psi4/libscf_solver/hf.h>
#include <psi4/libscf_solver/rhf.h>
#include <psi4/libmints/oeprop.h>
#include <psi4/psifiles.h>
#include <psi4/libpsi4util/PsiOutStream.h>
#include <psi4/libmints/matrix.h>
#include <psi4/libmints/factory.h>
#include <psi4/libpsi4util/process.h>
#include <psi4/libmints/molecule.h>
#include <psi4/libmints/basisset.h>
#include <psi4/libmints/mintshelper.h>
#include <psi4/libmints/petitelist.h>
#include <psi4/libmints/psimath.h>
#include <psi4/libqt/qt.h>
#include <psi4/libmints/integral.h>
#include <omp.h>
#include <chrono>
#include <stdio.h>
#include <iomanip>
#include "myelst.h"
#include <psi4/libfock/cubature.h>
#include <psi4/libfock/points.h>
#include <mkl.h>
#include <algorithm>
#include <cstring>



namespace psi{ namespace scf {

RHFDLMG2B::RHFDLMG2B(SharedWavefunction ref_wfn, Options
                  &options,std::shared_ptr<PSIO> psio): Wavefunction(options)
{
  // doing nothing
}
RHFDLMG2B::~RHFDLMG2B()
{
  std::cout << "Entering destructor\n" << std::flush;
}


}} // End namespaces

