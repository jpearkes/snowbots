//======================================================================
/*! \file Box2dF.hpp
 *
 * \copydoc Copyright
 * \author Jan Christian Dittmer (jcd)
 * \date May 30, 2012
 *///-------------------------------------------------------------------

#ifndef IBEOSDK_BOX2DF_HPP_SEEN
#define IBEOSDK_BOX2DF_HPP_SEEN

//======================================================================

#include <ibeosdk/misc/WinCompatibility.hpp>

#include <ibeosdk/Point2dFloat.hpp>

#include <vector>

//======================================================================

namespace ibeo {

//======================================================================

class Box2dF {
public:
	Box2dF();

	Box2dF(const Point2dFloat& center,
	       const Point2dFloat& size,
	       const float rotation = 0.0);

public:
	//========================================
	/*!\brief Returns the center point of this Box
	 *///-------------------------------------
	const Point2dFloat& getCenter() const { return center; }

	//========================================
	/*!\brief Returns the size of this Box
	 *
	 * The returned size denotes the size of the box in x-direction
	 * point2Dfloat::getX() and y-direction point2Dfloat::getY(), where the
	 * x-direction is rotated against the original x-axis by
	 * getRotation().
	 *///-------------------------------------
	const Point2dFloat& getSize() const { return size; }

	//========================================
	/*!\brief Returns the rotation angle of this Box2D in [radians],
	 *        counter clock wise.
	 *
	 * The rotation of the box' coordinate system around its center
	 * point. Must be in the interval [-pi,pi]
	 *///-------------------------------------
	float getRotation() const { return rotation; }


	void setCenter(const Point2dFloat& newCenter) { this->center = newCenter; }
	void setSize(const Point2dFloat& newSize) { this->size = newSize; }
	void SetRotation(const float newRotation) { this->rotation = newRotation; }


	//========================================
	/*!\brief Returns boundary angles for this box.
	 *
	 * This function calculates a low and a high boundary angle for
	 * all edges of the given (rotated) Box2D. The returned FloatPair
	 * has the component "first" for the lower bounding angle, and
	 * "second" for the upper bounding angle.
	 *
	 * (Note: This ordering is swapped compared to the scan point
	 * ordering!)
	 *///-------------------------------------
	std::pair<float, float> getBoundingAngles() const;

	bool containsPoint(const Point2dFloat& point) const;
	std::vector<Point2dFloat> getCorners() const;


protected:
	Point2dFloat center;
	Point2dFloat size;
	float rotation;
}; // Box2dF

//======================================================================

} // namespace ibeo

//======================================================================

#endif // IBEOSDK_BOX2DF_HPP_SEEN

//======================================================================

