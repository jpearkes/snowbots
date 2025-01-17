//======================================================================
/*! \file ObjectEcuEt.cpp
 *
 * \copydoc Copyright
 * \author Jan Christian Dittmer (jcd)
 * \date Sep 5, 2013
 *///-------------------------------------------------------------------

#include <ibeosdk/ObjectEcuEt.hpp>
#include <ibeosdk/io.hpp>

//======================================================================

namespace ibeo {

//======================================================================

ObjectEcuEt::ObjectEcuEt()
  : m_objectId(0),
    m_flags(0),
    m_objectAge(0),
    m_timestamp(),
    m_objectPredAge(0),
    m_classification(ObjectClass_Unclassified),
    m_classCertainty(0),
    m_classAge(0),
    m_reserved0(),
    m_reserved1(),
    m_objBoxCenter(),
    m_objBoxCenterSigma(),
    m_objBoxSize(),
    m_reserved2(),
    m_objCourseAngle(.0f),
    m_reserved3(.0f),
    m_relVelocity(),
    m_relVelocitySigma(),
    m_absVelocity(),
    m_absVelocitySigma(),
    m_reserved4(0),
    m_reserved5(.0f),
    m_reserved6(.0f),
    m_reserved7(0),
    m_idxOfClosestPoint(0),
    m_refPointLocation(RPL_Unknown),
    m_refPointCoords(),
    m_refPointCoordsSigma(),
    m_refPointPosCorrCoeffs(.0f),
    m_reserved8(.0f),
    m_reserved9(.0f),
    m_objPriority(0),
    m_objExtMeasurement(.0f),
    m_contourPoints()
{}

//======================================================================

std::streamsize ObjectEcuEt::getSerializedSize() const
{
	return 2 * sizeof(uint16_t) // objectId, flags
		+ sizeof(uint32_t)      // objectAge
		+ sizeof(NTPTime)       // timestamp
		+ sizeof(uint16_t)      // objectPredAge
		+ 2*sizeof(uint8_t)     // classification, classCertainty
		+ sizeof(uint32_t)      // classAge
		+ 6* Point2dFloat::getSerializedSize_static() // reserved0,1, objBoxCenter, Sigma, Size, revered2
		+ 2*sizeof(float)       // objCourseAngle, reserved3
		+ 4* Point2dFloat::getSerializedSize_static() // relVelocity, Sigma, absVelocity, Sigma
		+ sizeof(uint64_t)      // reserved4
		+ 2*sizeof(float)       // reserved5, 6
		+ sizeof(uint16_t)      // reserved7
		+ 2*sizeof(uint8_t)     // nbOfPts, idxOfClosestPoint
		+ sizeof(uint16_t)      // refPointLocation
		+ 2* Point2dFloat::getSerializedSize_static() // refPointCoords, Sigma
		+ 3*sizeof(float)       // refPointPosCorrCoeffs, reserved8, 9
		+ sizeof(uint16_t)      // objPriority
		+ sizeof(float)         // objextMeasurement
		+ m_contourPoints.size() * Point2dFloat::getSerializedSize_static();
}
//======================================================================

bool ObjectEcuEt::deserialize(std::istream& is)
{
	const std::istream::pos_type startPos = is.tellg();

	readBE(is, m_objectId);
	readBE(is, m_flags);
	readBE(is, m_objectAge);
	readBE(is, m_timestamp);
	readBE(is, m_objectPredAge);
	uint8_t rd8 = 0;
	readBE(is, rd8);
	m_classification = ObjectClass(rd8);
	readBE(is, m_classCertainty);
	readBE(is, m_classAge);
	m_reserved0.deserialize(is);
	m_reserved1.deserialize(is);
	m_objBoxCenter.deserialize(is);
	m_objBoxCenterSigma.deserialize(is);
	m_objBoxSize.deserialize(is);
	m_reserved2.deserialize(is);
	readBE(is, m_objCourseAngle);
	readBE(is, m_reserved3);
	m_relVelocity.deserialize(is);
	m_relVelocitySigma.deserialize(is);
	m_absVelocity.deserialize(is);
	m_absVelocitySigma.deserialize(is);
	readBE(is, m_reserved4);
	readBE(is, m_reserved5);
	readBE(is, m_reserved6);
	readBE(is, m_reserved7);

	readBE(is, rd8);
	m_contourPoints.resize(rd8);

	readBE(is, m_idxOfClosestPoint);
	uint16_t rd16 = 0;
	readBE(is, rd16);
	m_refPointLocation = RefPointBoxLocation(rd16);
	m_refPointCoords.deserialize(is);
	m_refPointCoordsSigma.deserialize(is);
	readBE(is, m_refPointPosCorrCoeffs);
	readBE(is, m_reserved8);
	readBE(is, m_reserved9);
	readBE(is, m_objPriority);
	readBE(is, m_objExtMeasurement);
	std::vector<Point2dFloat>::iterator cpIter = m_contourPoints.begin();
	for (; cpIter != m_contourPoints.end(); ++cpIter) {
		cpIter->deserialize(is);
	}

	return !is.fail() && ((is.tellg() - startPos) == this->getSerializedSize());
}

//======================================================================

bool ObjectEcuEt::serialize(std::ostream& os) const
{
	const std::istream::pos_type startPos = os.tellp();

	writeBE(os, m_objectId);
	writeBE(os, m_flags);
	writeBE(os, m_objectAge);
	writeBE(os, m_timestamp);
	writeBE(os, m_objectPredAge);
	writeBE(os, uint8_t(m_classification));

	writeBE(os, m_classCertainty);
	writeBE(os, m_classAge);
	m_reserved0.serialize(os);
	m_reserved1.serialize(os);
	m_objBoxCenter.serialize(os);
	m_objBoxCenterSigma.serialize(os);
	m_objBoxSize.serialize(os);
	writeBE(os, m_reserved2);
	writeBE(os, m_objCourseAngle);
	writeBE(os, m_reserved3);
	m_relVelocity.serialize(os);
	m_relVelocitySigma.serialize(os);
	m_absVelocity.serialize(os);
	m_absVelocitySigma.serialize(os);
	writeBE(os, m_reserved4);
	writeBE(os, m_reserved5);
	writeBE(os, m_reserved6);
	writeBE(os, m_reserved7);
	writeBE(os, uint8_t(m_contourPoints.size()));
	writeBE(os, m_idxOfClosestPoint);
	writeBE(os, uint16_t(m_refPointLocation));

	m_refPointCoords.serialize(os);
	m_refPointCoordsSigma.serialize(os);
	writeBE(os, m_refPointPosCorrCoeffs);
	writeBE(os, m_reserved8);
	writeBE(os, m_reserved9);
	writeBE(os, m_objPriority);
	writeBE(os, m_objExtMeasurement);
	std::vector<Point2dFloat>::const_iterator cpIter = m_contourPoints.begin();
	for (; cpIter != m_contourPoints.end(); ++cpIter) {
		cpIter->serialize(os);
	}

	return !os.fail() && ((os.tellp() - startPos) == this->getSerializedSize());
}

//======================================================================

} // namespace ibeo

//======================================================================
