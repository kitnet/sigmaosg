// SulGuiRadioButton.h

#ifndef __SULGUIRADIOBUTTON_H__
#define __SULGUIRADIOBUTTON_H__

#include "SulGuiCanvas.h"

class CSulGuiRadioButton : public CSulGuiCanvas
{
public:
								CSulGuiRadioButton( const CSulString& sText, float x, float y, float w, float h );

	virtual void				setupAttr( CSulXmlAttr* pAttr );
	virtual void				setupEventHandler( CSulGuiEventHandler* pEventHandler );

	virtual void				init();

	void						removeSelect();

	virtual class CSulGuiRadioButton*	asRadioButton()	{ return this; }

protected:
	void						setMouseRelease( bool bInside );

private:
	osg::ref_ptr<osg::Geode>	m_rGeodeCross;
	bool						m_bActive;
	osg::ref_ptr<osg::Geode>	m_rGeodeTriangleFan;
	CSulString					m_sText;
	float						m_fontSize;
	float						m_radioSizeInner;
	float						m_radioSizeOuter;
	float						m_paddingText;
};

typedef std::vector< osg::ref_ptr<CSulGuiRadioButton> >	VEC_RADIOBUTTON;

#endif // __SULGUIRADIOBUTTON_H__