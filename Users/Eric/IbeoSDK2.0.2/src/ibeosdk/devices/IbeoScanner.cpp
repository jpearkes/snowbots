//======================================================================
/*! \file IbeoScanner.cpp
 *
 * \copydoc Copyright
 * \author Mario Brumm (mb)
 * \date Apr 24, 2012
 *///-------------------------------------------------------------------

#include <ibeosdk/devices/IbeoScanner.hpp>

//======================================================================

namespace ibeo {

//======================================================================

IbeoScanner::IbeoScanner(const std::string& ip, const unsigned short port)
  : IbeoDevice(ip, port)
{}

//======================================================================

} // namespace ibeo

//======================================================================
