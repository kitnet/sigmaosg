// SulGuiCheckBox.cpp

#include "stdafx.h"
#include "SulGuiCheckBox.h"
#include "SulGuiText.h"
#include "SulGeomLine.h"

CSulGuiCheckBox::CSulGuiCheckBox( const CSulString& sText, float x, float y, float w, float h ) :
CSulGuiCanvas( x, y, w!=0.0?w:128.0f, h!=0.0f?h:32.0f )
{
	m_bActive = false;

	addEvents( EVENT_MOUSE_RELEASE );

	float padding = 6.0f;

	CSulGeomLine* line0 = new CSulGeomLine( osg::Vec3(padding, padding, 0), osg::Vec3(w-padding, h-padding, 0) );
	line0->setWidth( 4.0f );

	CSulGeomLine* line1 = new CSulGeomLine( osg::Vec3(padding, h-padding, 0), osg::Vec3(w-padding, padding, 0) );
	line1->setWidth( 4.0f );

	m_rGeodeCross = new osg::Geode;
	m_rGeodeCross->addDrawable( line0->getDrawable() );
	m_rGeodeCross->addDrawable( line1->getDrawable() );
	m_rGeodeCross->setNodeMask( 0 );
	addChild( m_rGeodeCross );


	CSulGuiText* pGuiText = new CSulGuiText( sText, w, h/2.0f, h );
	pGuiText->getTextObject()->setAlignment( osgText::TextBase::LEFT_CENTER );
	addChild( pGuiText );
}

void CSulGuiCheckBox::setMouseRelease( bool bInside )
{
	if ( bInside )
	{
		m_bActive = !m_bActive;
		m_rGeodeCross->setNodeMask( bInside?0xFFFFFFFF:0 );
	}
}