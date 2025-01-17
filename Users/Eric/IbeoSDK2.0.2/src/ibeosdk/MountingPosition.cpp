//======================================================================
/*! \file MountingPosition.cpp
 *
 * \copydoc Copyright
 * \author Jan Christian Dittmer (jcd)
 * \date Sep 29, 2013
 *///-------------------------------------------------------------------

#include <ibeosdk/misc/WinCompatibility.hpp>

#include <ibeosdk/MountingPosition.hpp>
#include <ibeosdk/Math.hpp>
#include <ibeosdk/io.hpp>

#include <cassert>
#include <cmath>

//======================================================================

namespace ibeo {

//======================================================================

MountingPosition::MountingPosition()
  : m_yawAngle(0), m_pitchAngle(0), m_rollAngle(0),
	m_posX(0), m_posY(0), m_posZ(0)
{}


//======================================================================

MountingPosition::MountingPosition(const float yaw, const float pitch, const float roll,
                                   const float x, const float y, const float z)
  : m_yawAngle(yaw), m_pitchAngle(pitch), m_rollAngle(roll),
	m_posX(x), m_posY(y), m_posZ(z)
{}

//======================================================================

bool MountingPosition::operator==(const MountingPosition& other) const
{
	bool ret =
		ibeo::fuzzyCompare(m_yawAngle, other.m_yawAngle)
		&& ibeo::fuzzyCompare(m_pitchAngle, other.m_pitchAngle)
		&& ibeo::fuzzyCompare(m_rollAngle, other.m_rollAngle)
		&& m_posX == other.m_posX
		&& m_posY == other.m_posY
		&& m_posZ == other.m_posZ
		;

	return ret;
}

//======================================================================

MountingPosition& MountingPosition::set(const float yaw, const float pitch, const float roll,
                                        const float x, const float y, const float z)
{
	m_yawAngle = yaw;
	m_pitchAngle = pitch;
	m_rollAngle = roll;
	m_posX = x;
	m_posY = y;
	m_posZ = z;

	return *this;
}

//======================================================================

bool MountingPosition::deserialize(std::istream &is)
{
	const std::istream::pos_type startPos = is.tellg();

	ibeo::readBE(is, m_yawAngle);
	ibeo::readBE(is, m_pitchAngle);
	ibeo::readBE(is, m_rollAngle);
	ibeo::readBE(is, m_posX);
	ibeo::readBE(is, m_posY);
	ibeo::readBE(is, m_posZ);

	return !is.fail() && ((is.tellg() - startPos) == this->getSerializedSize());
}

//======================================================================

bool MountingPosition::serialize(std::ostream &os) const
{
	const std::istream::pos_type startPos = os.tellp();

	ibeo::writeBE(os, m_yawAngle);
	ibeo::writeBE(os, m_pitchAngle);
	ibeo::writeBE(os, m_rollAngle);
	ibeo::writeBE(os, m_posX);
	ibeo::writeBE(os, m_posY);
	ibeo::writeBE(os, m_posZ);

	return !os.fail() && ((os.tellp() - startPos) == this->getSerializedSize());
}

//======================================================================

void MountingPosition::normalizeAngles()
{
	m_yawAngle = ibeo::normalizeRadians(m_yawAngle);
	m_pitchAngle = ibeo::normalizeRadians(m_pitchAngle);
	m_rollAngle = ibeo::normalizeRadians(m_rollAngle);
}

//======================================================================

} // namespace ibeo

//======================================================================
