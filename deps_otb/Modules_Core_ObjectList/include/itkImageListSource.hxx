/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef itkImageListSource_hxx
#define itkImageListSource_hxx

#include "itkImageListSource.h"

namespace itk
{
/**
 *   Constructor
 */
template <class TOutputImage>
ImageListSource<TOutputImage>
::ImageListSource()
{
  this->Superclass::SetNumberOfRequiredOutputs(1);
  this->Superclass::SetNthOutput(0, ImageList<TOutputImage>::New().GetPointer());
}
/**
 * Get the output image list
 * \return The image list produced.
 */
template <class TOutputImage>
typename ImageListSource<TOutputImage>::OutputImageListType *
ImageListSource<TOutputImage>
::GetOutput(void)
{
  if (this->GetNumberOfOutputs() < 1)
    {
    return 0;
    }
  return static_cast<OutputImageListType *> (this->ProcessObject::GetOutput(0));
}
/**
 * PrintSelf Method
 */
template<class TOutputImage>
void
ImageListSource<TOutputImage>
::PrintSelf(std::ostream& os, itk::Indent indent) const
{
  Superclass::PrintSelf(os, indent);
}
} // End namespace itk
#endif
