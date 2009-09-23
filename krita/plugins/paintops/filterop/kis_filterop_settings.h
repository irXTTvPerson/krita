/*
 *  Copyright (c) 2002 Patrick Julien <freak@codepimps.org>
 *  Copyright (c) 2004-2008 Boudewijn Rempt <boud@valdyas.org>
 *  Copyright (c) 2004 Clarence Dang <dang@kde.org>
 *  Copyright (c) 2004 Adrian Page <adrian@pagenet.plus.com>
 *  Copyright (c) 2004 Cyrille Berger <cberger@cberger.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KIS_FILTEROP_SETTINGS_H_
#define KIS_FILTEROP_SETTINGS_H_

#include <kis_paintop_settings.h>
#include <kis_types.h>

#include "kis_filterop_settings_widget.h"

class QDomElement;
class KisFilterConfiguration;

class KisFilterOpSettings : public KisPaintOpSettings
{

public:
    using KisPaintOpSettings::fromXML;
    using KisPaintOpSettings::toXML;

    KisFilterOpSettings();

    virtual ~KisFilterOpSettings();
    bool paintIncremental();

    void fromXML(const QDomElement& elt);
    void toXML(QDomDocument& doc, QDomElement& rootElt) const;

    KisPaintOpSettingsSP clone() const;

    void setNode( KisNodeSP node );

    void setImage( KisImageSP image );

    KisFilterSP filter() const;
    KisFilterConfiguration* filterConfig() const;
    bool ignoreAlpha() const;
    
    // XXX: Hack!
    void setOptionsWidget(KisPaintOpSettingsWidget* widget)
    {
        if (m_options != 0 && m_options->property("owned by settings").toBool()) {
            delete m_options;
        }
        if (!widget) {
            m_options = 0;
        }
        else {
            m_options = qobject_cast<KisFilterOpSettingsWidget*>(widget);
            m_options->writeConfiguration( this );
        }
    }
    
public:

    KisFilterOpSettingsWidget *m_options;

};


#endif // KIS_FILTEROP_SETTINGS_H_
