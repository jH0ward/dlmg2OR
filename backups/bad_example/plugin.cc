/*
 * @BEGIN LICENSE
 *
 * rhf_dlmg2b by Psi4 Developer, a plugin to:
 *
 * Psi4: an open-source quantum chemistry software package
 *
 * Copyright (c) 2007-2017 The Psi4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This file is part of Psi4.
 *
 * Psi4 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * Psi4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with Psi4; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * @END LICENSE
 */

#include "psi4/psi4-dec.h"
#include <psi4/liboptions/liboptions.h>
#include "psi4/libpsio/psio.hpp"
#include <psi4/libscf_solver/rhf.h>
#include <psi4/libscf_solver/hf.h>
#include <psi4/libciomr/libciomr.h>
#include <psi4/libfunctional/functional.h>
#include "psi4/libpsi4util/PsiOutStream.h"
#include "rhfdlmg2b.h"
#include <iostream>

namespace psi{ namespace scf {

extern "C"
int read_options(std::string name, Options& options)
{
    if (name == "RHF_DLMG2B"|| options.read_globals()) {
        /*- The amount of information printed to the output file -*/
        options.add_int("PRINT", 1);
        options.add_int("nx",161);
        options.add_int("ny",161);
        options.add_int("nz",161);
        options.add_int("block_size",6);
        options.add_double("g_step",0.075);
        options.add_double("sigma",0.5);
        options.add_double("eps",1.0);
        options.add_double("eps_sol",0.0);
        options.add_double("rho0",0.00055);
        options.add_double("beta",1.6);
        options.add_int("dlmg_tol",7);
    }

    return true;
}

extern "C"
SharedWavefunction rhf_dlmg2b(SharedWavefunction ref_wfn, Options& options)
{
    int print = options.get_int("PRINT");

    //* Your code goes here */
    
    //std::shared_ptr<RHF> rhf_shptr(dynamic_cast<RHF*>(ref_wfn.get()));

    //std::shared_ptr<SuperFunctional> func = std::shared_ptr<SuperFunctional>(new SuperFunctional(dynamic_cast<RHF*>(ref_wfn.get())->functional())); 
  
//    std::shared_ptr<Functional> fun(new Functional());

    //auto rhf_shptr = std::make_shared<RHF>(dynamic_cast<RHF*>(ref_wfn.get()));
    //std::shared_ptr<RHF> rhf_shptr=std::shared_ptr<RHF>(new (dynamic_cast<RHF*>(ref_wfn.get()));
    //std::cout << rhf_shptr->ndocc() << "\n";
   // std::cout << "Is it unique? " << rhf_shptr.unique() << "\n";
   // std::cout << "Ref_wfn? " << ref_wfn.unique() << "\n";
    //std::shared_ptr<RHF> rhf_shptr = std::shared_ptr<RHF>(new RHF(dynamic_cast<RHF*>(ref_wfn.get())));
    //std::shared_ptr<SuperFunctional> func = std::shared_ptr<SuperFunctional>(new Functional());
    std::shared_ptr<PSIO>psio(new PSIO);
  //  std::shared_ptr<Wavefunction> scf(new RHFDLMG2B(ref_wfn,func,options,psio));
  //
    std::shared_ptr<Wavefunction> my_wfn(new RHFDLMG2B(ref_wfn,options,psio));
    //SharedWavefunction scf(new RHFDLMG2B(ref_wfn,options,psio));
   
   // below is good, next one is bad 
    //SharedWavefunction ref_copy = std::shared_ptr<Wavefunction>(new Wavefunction(options));
    //SharedWavefunction ref_copy;
    //ref_copy->deep_copy(ref_wfn);
    //
    //SharedWavefunction scf(new RHFDLMG2B(ref_copy,options,psio));
    //double plug_energy=scf->compute_energy();
    //std::cout << "Returned from plugin with energy of " << plug_energy << "\n" << std::flush;

    // Typically you would build a new wavefunction and populate it with data
    //exit(0);
    return my_wfn;
    //ref_wfn=my_wfn;
    //return ref_wfn;
}

}} // End namespaces

