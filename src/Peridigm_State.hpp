/*! \file Peridigm_State.hpp */

// ***********************************************************************
//
//                             Peridigm
//                 Copyright (2009) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
// 
// Questions? 
// David J. Littlewood   djlittl@sandia.gov 
// John A. Mitchell      jamitch@sandia.gov
// Michael L. Parks      mlparks@sandia.gov
// Stewart A. Silling    sasilli@sandia.gov
//
// ***********************************************************************

#ifndef PERIDIGM_STATE_HPP
#define PERIDIGM_STATE_HPP

#include <Teuchos_RCP.hpp>
#include <Epetra_MultiVector.h>

namespace PeridigmNS {

class State {

public:

  State(){}
  State(const State& state){}
  ~State(){}

  void allocateScalarData(int numVar, Teuchos::RCP<Epetra_BlockMap> map)
  {
    scalarData = Teuchos::rcp(new Epetra_MultiVector(*map, numVar));
  }

  void allocateVector1DData(int numVar, Teuchos::RCP<Epetra_BlockMap> map)
  {
    vector2DData = Teuchos::rcp(new Epetra_MultiVector(*map, numVar));
  }

  void allocateVector2DData(int numVar, Teuchos::RCP<Epetra_BlockMap> map)
  {
    vector3DData = Teuchos::rcp(new Epetra_MultiVector(*map, numVar));
  }

protected:

  Teuchos::RCP<Epetra_MultiVector> scalarData;
  Teuchos::RCP<Epetra_MultiVector> vector2DData;
  Teuchos::RCP<Epetra_MultiVector> vector3DData;
};

}

#endif // PERIDIGM_STATE_HPP
