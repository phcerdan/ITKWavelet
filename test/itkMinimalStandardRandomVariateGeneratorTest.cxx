/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkMinimalStandardRandomVariateGenerator.h"

#include "itkTestingMacros.h"
#include "itkMath.h"

#include <iomanip>

int itkMinimalStandardRandomVariateGeneratorTest( int, char * [] )
{
  typedef itk::Statistics::MinimalStandardRandomVariateGenerator GeneratorType;
  GeneratorType::Pointer generator = GeneratorType::New();
  
  EXERCISE_BASIC_OBJECT_METHODS( generator, MinimalStandardRandomVariateGenerator );

  generator->Initialize( 324 );
  TEST_EXPECT_EQUAL( 15639804, generator->GetIntegerVariate() );
  TEST_EXPECT_TRUE( itk::Math::FloatAlmostEqual( generator->GetVariate(), 0.55051352274651965679 ));

  return EXIT_SUCCESS;
}