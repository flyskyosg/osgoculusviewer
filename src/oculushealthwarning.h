/*
 * oculushealthwarning.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Bjorn Blissing
 */
#ifndef _OSG_OCULUSWARNING_H_
#define _OSG_OCULUSWARNING_H_

#include <osg/MatrixTransform>
#include <osgViewer/ViewerEventHandlers>

// Forward declaration
class osg::Image;

class OculusHealthAndSafetyWarning : public osg::Referenced {
public:
	OculusHealthAndSafetyWarning() : m_scale(3.0), m_distance(4.0), m_transform(0) {};
	void updatePosition(osg::Matrix cameraMatrix, osg::Vec3 position, osg::Quat orientation);
	void tryDismissWarning(double time);
	osg::ref_ptr<osg::Group> getGraph();
protected:
	~OculusHealthAndSafetyWarning() {};
	
	osg::Image* buildImageFromByteStream();
	const double m_scale;
	const double m_distance;
	osg::ref_ptr<osg::MatrixTransform> m_transform;
};


class OculusWarningEventHandler : public osgGA::GUIEventHandler
{
public:
	OculusWarningEventHandler(osg::observer_ptr<OculusHealthAndSafetyWarning> warning) : m_warning(warning) {}
	virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&);
protected:
	osg::observer_ptr<OculusHealthAndSafetyWarning> m_warning;

};

#endif /* _OSG_OCULUSWARNING_H_ */