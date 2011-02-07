// SulGeomBarChart.h

#ifndef __SULGEOMBARCHART_H__
#define __SULGEOMBARCHART_H__

#include "SuLGeomQuad.h"
#include <osg/group>

class CSulGeomBarChart : public osg::Group
{
private:
	typedef std::vector< osg::ref_ptr<CSulGeomQuad> > VEC_GEOM_QUAD;

public:
					CSulGeomBarChart();

					sigma::uint32	createBar( const osg::Vec4& color=osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );

	void			setBarSize( sigma::uint32 index, float size );

private:
	VEC_GEOM_QUAD	m_vecBar;
	float			m_h;
};

#endif // __SULGEOMBARCHART_H__