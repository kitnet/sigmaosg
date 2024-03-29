// SulRenderCellInstances.h

#ifndef __SULRENDERCELLINSTANCES_H__
#define __SULRENDERCELLINSTANCES_H__

#include "SulTypes.h"
#include "SulExport.h"

class SUL_EXPORT CSulRenderCellInstances : public osg::Group
{
public:
									CSulRenderCellInstances( osg::Vec2 cellXY, osg::Image* pImagePositions, sigma::uint32 numInst, osg::BoundingBox& bb, float min=3.0f, float max=3.0f, bool bSuppressTexture=false, sigma::uint32 texUnit=0, bool bUseZDirectionNormal=false, bool bSuppressShaders=false );

	void							process();

	osg::ref_ptr<osg::Geode>		createCrossQuadCell( sigma::uint32 x, sigma::uint32 y );

	osg::ref_ptr<osg::Geode>		createBillboardCell( sigma::uint32 x, sigma::uint32 y );

private:
	void							setStateSetData( osg::Node* pNode );

	osg::BoundingBox				calcBB( sigma::uint32 x, sigma::uint32 y );

	sigma::uint32					calcTexturedSquared( sigma::uint32 count );

	osg::ref_ptr<osg::Texture2D>	createTextureForPositions( std::vector<osg::Vec3> vecList );

	std::vector<osg::Vec3>			createListOfPositionsForCell( sigma::uint32 x, sigma::uint32 y );

private:
	osg::ref_ptr<osg::Image>		m_rImagePositions;

	sigma::uint32					m_numInstances;
	osg::BoundingBox				m_bb;
	bool							m_bSuppressTexture;
	sigma::uint32					m_texUnit;
	float							m_min;
	float							m_max;
	bool							m_bUseZDirectionNormal;
	bool							m_bSuppressShaders;
	osg::Vec2						m_cellXY;
};

#endif // __SULRENDERCELLINSTANCES_H__